#include "io.h"

//hàm xử lý chính, đầu vào là các string từ 1 dòng dữ liệu trong, trả về 1 string kết quả
string execute_data(vector<string> data)
{
	try
	{
		string result;

		int current_base = get_base(data[0]);
		int destination_base = current_base;

		char key = data[data.size() - 2][0];

		if (data.size() == 4)
		{
			Qint A(data[1], current_base);
			Qint B;
			if (key == '<' || key == '>')
			{
				Qint temp(data[3], 10);
				B = temp;
			}
			else
			{
				Qint temp(data[3], current_base);
				B = temp;
			}
			
			Qint C;
			switch (key)
			{
			case '+': C = A + B; break;
			case '-': C = A - B; break;
			case '*': C = A * B; break;
			case '/': C = A / B; break;
			case '&': C = A & B; break;
			case '|': C = A | B; break;
			case '^': C = A ^ B; break;
			case '<': C = A << B; break;
			case '>': C = A >> B; break;
			}
			result = C.bi_to(destination_base);
		}
		else
		{
			Qint C(data[2], current_base);
			switch (key)
			{
			case 'r':
				data[1][2] == 'r' ? C.ror() : C.rol();
				break;
			case '~': C = ~C; break;
			default:
				destination_base = get_base(data[1]);
			}
			result = C.bi_to(destination_base);
		}
		return result;
	}catch (const char* msg)
	{
		string temp;
		return temp;
	}
}

//hàm tách 1 dòng từ file input thành nhiều string ngăn cách nhau bởi dấu cách
void split(string line, vector<string> & data)
{
	stringstream ss;
	ss << line;
	
	while (!ss.eof())
	{
		string temp;
		ss >> temp;
		data.push_back(temp);
	}
}

//dòng dữ liệu từ file có các chỉ thị cơ số p1, p2, hàm này nhận vào các chỉ thị này ở dạng string và trả ra kết quả kiểu int. VD "10" thì trả ra 10
int get_base(string num)
{
	int base = 0;
	for (int i = 0; i<num.size(); i++)
		base = base * 10 + num[i] - '0';
	return base;
}