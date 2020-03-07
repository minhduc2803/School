

function login(){
    let p = document.getElementsByClassName('username')[0].value;
    if(p==''){
        document.getElementsByClassName('username-e')[0].innerHTML = "";
        return;
    }
    //let reg = /^[\p{L}\s'.-]+$/;
    let reg = /^[A-Za-z_]\w*$/;
    if(reg.test(p)){

        document.location.href = 'sucess.html';

    }
    else
        document.getElementsByClassName('username-e')[0].innerHTML = 'User name không được có khoảng trắng, chỉ gồm chữ, số và dấu _, không được bắt đầu bởi ký số';
}

function register(){
    let hoten = document.getElementsByClassName('hoten')[0].value;
    let username = document.getElementsByClassName('username')[1].value;
    let email = document.getElementsByClassName('email')[0].value;
    let phone = document.getElementsByClassName('phone')[0].value;
    let ngaysinh = document.getElementsByClassName('ngaysinh')[0].value;
    if(hoten=='') document.getElementsByClassName('hoten-e')[0].innerHTML = '';
    if(username=='') document.getElementsByClassName('username-e')[1].innerHTML = '';
    if(email=='') document.getElementsByClassName('username-e')[1].innerHTML = '';
    if(phone=='') document.getElementsByClassName('phone-e')[0].innerHTML = '';
    if(ngaysinh=='') document.getElementsByClassName('ngaysinh-e')[0].innerHTML = '';
    if(hoten==''||username==''||email==''||phone==''||ngaysinh=='') return;

    let reg = /^(\b[A-Z]\w*\s*)+$/;
    let v_hoten = reg.test(hoten);
    if(!v_hoten)
    document.getElementsByClassName('hoten-e')[0].innerHTML = 'Họ tên không dấu và yêu cầu phải viết hoa các chữ cái đầu';
    else
    document.getElementsByClassName('hoten-e')[0].innerHTML = '';


    reg = /^[A-Za-z_]\w*$/;
    let v_username = reg.test(username);
    if(!v_username)
    document.getElementsByClassName('username-e')[1].innerHTML = 'User name không được có khoảng trắng, chỉ gồm chữ, số và dấu _, không được bắt đầu bởi ký số';
    else
    document.getElementsByClassName('username-e')[1].innerHTML = '';

    reg = /^[a-z][a-z0-9_\.]{5,32}@[a-z0-9]{2,}(\.[a-z0-9]{2,}){1,3}$/;
    let v_email = reg.test(email);
    if(!v_email)
    document.getElementsByClassName('email-e')[0].innerHTML = 'Email không hợp lệ';
    else
    document.getElementsByClassName('email-e')[0].innerHTML = '';

    reg = /(0)+([0-9]{9})\b/;
    let v_phone = reg.test(phone);
    if(!v_phone)
    document.getElementsByClassName('phone-e')[0].innerHTML = 'Số điện thoại không hợp lệ';
    else
    document.getElementsByClassName('phone-e')[0].innerHTML = '';

    reg = /^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[13-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$/;
    let v_ngaysinh = reg.test(ngaysinh);
    if(!v_ngaysinh)
    document.getElementsByClassName('ngaysinh-e')[0].innerHTML = 'Ngày sinh không hợp lệ hoặc không đúng định dạng';
    else
    document.getElementsByClassName('ngaysinh-e')[0].innerHTML = '';

    if(v_ngaysinh)
    {
        year = parseInt(ngaysinh.substring(6,10));
        let current_year = new Date().getFullYear();
        if(current_year-year<=55 && current_year-year>=5)
            v_ngaysinh = true;
        else
        {
            v_ngaysinh = false;
            document.getElementsByClassName('ngaysinh-e')[0].innerHTML = 'Độ tuổi hợp lệ [15-55] tuổi';
        }
    }

    if(v_hoten & v_username & v_email & v_phone & v_ngaysinh)
        document.location.href = 'sucess.html';
}
