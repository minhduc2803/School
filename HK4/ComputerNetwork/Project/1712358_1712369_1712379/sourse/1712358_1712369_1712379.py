import os
import sys
import _thread
import socket
import time
import json

BLACKLIST = []
ForbiddenMSG = b'\r\n'.join([
    b'HTTP/1.1 403',
    b'Server: proxy',
    b'Content-type: text/html\r\n',
    b'<HTML><HEAD><TITLE>Access Denied</TITLE></HEAD><BODY><H1>403 Access Denied</H1><p>You don\'t have permission to access on this server.</p></BODY></HTML>'])
CACHE = {}

def prepare():
    #bước chuẩn bị đầu tiên trước khi chạy chương trình, chạy mở file blacklis.conf để lấy danh sách các web bị chặn
    global BLACKLIST, CACHE
    try:
        with open("blacklist.conf") as f:
            BLACKLIST = f.readlines()
    except:
        pass
    BLACKLIST = [x.strip() for x in BLACKLIST]


def create_proxy_socket(host, port):
    #đơn giản tạo 1 socket (với vai trò server), và lắng nghe các kết nối trên port 8888
    if len(host) == 0:
        print("Proxy Server localhost:"+str(port))
    else:
        print("Proxy Server "+host+":"+str(port))

    prepare()
    #tạo socket cho proxy server
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((host, port))
        s.listen(100)
    except socket.error:
        if s:
            s.close()
        print("Can not open proxy socket")
        sys.exit(1)
    return s

def my_send(s, msg):
    #hàm send gửi dữ liệu đi, đồng thời đảm bảo dữ liệu được gửi đi toàn (liên tục gửi-check)
    MSGLEN = len(msg)
    totalsent = 0
    while totalsent < MSGLEN:
        sent = s.send(msg[totalsent:])
        if sent == 0:
            raise RuntimeError("socket connection broken")
        totalsent = totalsent + sent

def my_recv(s, timeout = 0.3):
    """hàm recv đặc biệt, để đảm bảo không bị mất gói tin nào và cũng không mất thời gian để đợi tin vô ích.
    ban đầu sẽ đợi client gửi tin,
    sau khi nhận được gói tin đầu tiên sẽ mở block hàm recv và nhận, đợi gói tin liên tục,
    tới khi thời gian đợi từ khi không có gói nào gửi tới nữa > 0.3s thì thoát."""
    total_data = []
    data = b''
    s.setblocking(1)
    try:
        data = s.recv(8192)
    except:
        pass
    if data:
        total_data.append(data)
    else:
        return b''

    s.setblocking(0)
    begin = time.time()
    while 1:
        if (time.time()-begin) > timeout:
            break
        try:
            data = s.recv(8192)
            if data:
                total_data.append(data)
                begin = time.time()
            else:
                time.sleep(0.1)
        except:
            pass
    s.setblocking(1)
    return b''.join(total_data)

def parser_request(server_name, server_port, msg):
    """hàm phân tích cú pháp gói request, cố gắng tìm ra tên server, port
    đồng thời trả về method (dòng đầu tiên trong header và max_age (nếu tìm thấy).
    sở dĩ phải tìm max_age trong gói request là bởi đôi
	khi client theo 1 cách nào đó muốn làm mới gói tin,
    có thể là do yêu cầu nằm trong đoạn scritp của server"""
    max_age = 300
    request = msg.split(b'\r\n\r\n')
    request_header = request[0]
    request_header = request_header.split(b'\r\n')
    method = request_header[0].decode()
    if not server_name:
        
        host = request_header[1].decode()
        #domain name nằm cuối dòng host, sau dấu " "
        server_name = host.split(" ")[-1]
        #nếu dòng này chứa cả port thì port chắc chắn đứng sau dấu ':'
        port_position = server_name.find(":")
        #nếu không chứa port thì hàm find trả về -1
        #khi đó theo mặc định, truy cập vào port 80
        if port_position == -1:
            server_port = 80
        else:
            server_port = int(server_name[port_position+1:])
            server_name = server_name[:port_position]
    for i in range(2,len(request_header)):
        if len(request_header[i]) < 50:
            if b'ache-Control:' in request_header[i]:
                p_age = request_header[i].find(b'max-age')
                if p_age != -1:
                    p_temp = request_header[i][p_age:].split(b' ')[0]
                    max_age = int(p_temp[8:])
                    break

                if b'no-store' in request_header[i] or \
                b'no-cache' in request_header[i] or \
                b'private' in request_header[i]:
                    max_age = 0
                    break
    return server_name, server_port, method, max_age

def parser_respond(msg, max_age):
    #hàm phần tích cú pháp gói respond, lấy ra giá trị connection trong term Connection: keep-alive hoặc Connection: close
    #đồng thời tìm max-age trong term Cache-control:, nếu tồn tại các giá trị như no-store, no-cache, private hay max-age=0
    #thì ta gán max_age=0, còn lại ta sẽ gán max_age bằng với trường max-age (nếu tìm thấy)
    #max_age mặc định là 300s
    connection = False
    respond = msg.split(b'\r\n\r\n')
    respond_header = respond[0]
    respond_header = respond_header.split(b'\r\n')

    for i in range(1,len(respond_header)):
        if len(respond_header[i]) < 25:
            if b'onnection:' in respond_header[i]:
                if b'keep-alive' in respond_header[i]:
                    connection = True
                break
        
    for i in range(1,len(respond_header)):
        if len(respond_header[i]) < 50:
            if b'ache-Control:' in respond_header[i]:
                p_age = respond_header[i].find(b'max-age')
                if p_age != -1:
                    p_temp = respond_header[i][p_age:].split(b' ')[0]
                    max_age = int(p_temp[8:])
                    break

                if b'no-store' in respond_header[i] or \
                b'no-cache' in respond_header[i] or \
                b'private' in respond_header[i]:
                    max_age = 0
                    break
    return connection, max_age

def blacklist(client_socket, client_address, server_name, method):
    #hàm kiểm trả các tên miền trong BLACKLIST có trùng với tên miền của webserver hay không
    #nếu có, trả về gói 403, return False -> đồng nghĩa với đóng kết nối
    for i in range(len(BLACKLIST)):
        if BLACKLIST[i] in server_name:
            print("BLOCK",client_address,method)
            client_socket.send(ForbiddenMSG)
            return False
    return True

def cache(file_name, respond, max_age ,connection):
    #lưu file_name vào CACHE, dùng dictionary
    #dictionary của python sử dụng cơ chế hashing để lưu dữ liệu nên việc truy suất 1 phần tử với key cho trước rất nhanh chóng
    global CACHE
    CACHE[file_name] = [respond,time.time()+max_age, connection]

def fetch(file_name):
    """hàm fetch tìm gói respond với key là file_name, value là 1 list [respond,time,connection]"""
    global CACHE
    respond = b''
    connection = False
    cache_status = -1
    if file_name[0:3] == 'GET':
        full_respond = CACHE.get(file_name)
        
        if full_respond:
            age = full_respond[1]
            #chỉ gửi lại respond khi tìm thấy file_name trong CACHE và thời gian sống lớn hơn thời gian hiện tại
            if age > time.time():
                respond = full_respond[0]
                connection = full_respond[2]
                cache_status = 1
            else:
                cache_status = 0
        else:
            cache_status = 0
    return respond, cache_status, connection


def proxy(client_socket, client_address):
    """"proxy sẽ đợi và nhận 1 reuqest của client, gửi cho server, nhận lại respond của server và gửi cho client.
    hàm proxy sử dụng cơ chế pipeline, cố gắng duy trì kết nối TCP giữa proxy với client và proxy với server.
    sau mỗi đợt request-respond, hàm lại kiểm tra kết nối với server qua thông số Connection: keep-alive của respond header,
    và với client qua tín hiệu chuỗi b'' rỗng trả về từ hàm recv()"""
    first_step = True 
    server_socket = None
    connection = True
    server_name = ''
    server_port = 80
    while connection:
        request = my_recv(client_socket)
        if not request:
            break
        #phần tích cú pháp request, max_age phục vụ cho caching
        server_name, server_port, method, max_age = parser_request(server_name, server_port, request)
        #tạo file name, mục đích để tìm file này trong cache của proxy
        file_name = ','.join([method, server_name, str(server_port)])
        print(client_address, method)
        #tìm kiếm file trong cache proxy, trả về cache_status = (1-cache hit, 0-cache miss, -1-no cache), proxy chỉ cache gói GET
        respond, cache_status, connection = fetch(file_name)
        #cache hit, trả respond lại cho client
        if cache_status == 1:
            my_send(client_socket, respond)
            print("RESPOND",'[proxy_cache]',client_address)
            connection, max_age = parser_respond(respond, max_age)
            continue
        #nếu là lặp đầu tiên của kết nối, proxy cần kết nối với docket server, các lần sau thì không cần
        if first_step:
            if blacklist(client_socket, client_address, server_name, method):
                try:
                    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    server_socket.connect((server_name, server_port))
                except:
                    break
            else:
                break
            first_step = False
        #cache miss or no-cache, tới server để yêu cầu gói tin
        my_send(server_socket, request)
        respond = my_recv(server_socket)
        my_send(client_socket, respond)
        print("RESPOND",'[',server_name,':',server_port,']',client_address)
        #phân tích gói tin respond
        connection, max_age = parser_respond(respond, max_age)
        #nếu là cache-miss chứ ko phải no-cache, ta lưu lại 1 bản sao của gói respond
        if cache_status == 0:
            cache(file_name, respond, max_age, connection)
    if server_socket:
        server_socket.close()
    if client_socket:
        client_socket.close()

def main():
    s = create_proxy_socket(socket.gethostbyname(socket.gethostname()),8888)
    #chấp nhận các kết nối từ client, với mỗi kết nối -> tạo 1 thread xử lý riêng
    while 1:
        try:
            client_socket, client_address = s.accept()
            _thread.start_new_thread(proxy, (client_socket, client_address))
        #ctrl + C để kết thúc chương trình
        except KeyboardInterrupt:
            s.close()
            sys.exit(0)
    s.close()

if __name__ == '__main__':
    main()