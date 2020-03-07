#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <random>

using namespace std;

string to_hex(int i)				//đổi int thành hex
{
	ostringstream oss;
	oss << hex << ((i >> 0) & 0xFF);
	return oss.str();
}

int main()
{
	string s;
	random_device rd;
	
	int l = 0;		
	l = rd() % 9;				//random length l				

	for (int i = 0; i < l; ++i)							
	{
		int j = 0;

		do
		{
			j = rd() % 127;		//random string với length = l, string là đoạn key từ ký tự thứ 3 trở đi
		} while (j < 32);		//trong khoảng ascii hợp lệ
		
		s += char(j);
	}
	
	while (s.length() <= 4)			
		s += char(0);			

	int edi[4];				//call 1

	edi[0] = s[0] + 14;			//gán char từ string vào edi 
	edi[1] = s[1] + 13;	
	edi[2] = s[2] + 12;
	edi[3] = s[3] + 11;

	for (int i = 0; i < 4; ++i)
	{
		if (edi[i] < 33)		//nếu char < 33 thì += 33
			edi[i] += 33;
		
		if (edi[i] > 123)		//nếu char > 123 thì >>= 1
		{
			bitset <8> bs(edi[i]);
			bs >>= 1; 
			edi[i] = int(bs.to_ulong());
		}
	}
	
	string xae;				//call 2

	xae = to_hex(edi[3]);			//gán covert edi thành hex rồi gán vào xae
	xae += to_hex(edi[2]);
	xae += to_hex(edi[1]);
	xae += to_hex(edi[0]);
	int tmp = 0;

	for (int i = 0; i < 8; ++i)		//chuyển chuỗi hex xae thành int
	{
		if (xae[i] <= '9')
			tmp += (xae[i] - '0') * int(pow(16.0, (7.0 - i * 1.0)));
		else
			tmp += (xae[i] - 'a' + 10) * int(pow(16.0, (7.0 - i * 1.0)));
		
	}
	
	int c[2];				//main
	c[0] = tmp % 10 + '0';			//chuyển 2 số cuối trong tmp thành ký tự và gán vào c
	c[1] = (tmp / 10) % 10 + '0';

	bitset <8> bst1(c[0]), bst2(c[1]);	//bst1 = c[0], bst2 = c[1]
	bitset <16> ebx, eax(6684);		//eax = 6684
	
	for (int i = 0; i < 8; ++i)		//gán c vào ebx
	{
		ebx[i] = bst2[i];		
		ebx[i + 8] = bst1[i];
	}
	
	bool du = 0;
	for (int i = 0; i < 16; ++i)		//eax += ebx
	{
		int j = eax[i] + ebx[i] + du;

		if (j <= 1)
		{
			eax[i] = j;
			du = 0;
		}
		else 
		{
			eax[i] = j % 2;
			du = 1;
		}
	}
	
	for (int i = 0; i < 8; ++i)		
	{
		bst1[i] = eax[i];		//bst1 = eax
		bst2[i] = eax[i + 8];		//bst2 = [eax + 8]
	}

	c[0] = int(bst1.to_ulong());		//c[0] = bst1
	c[1] = int(bst2.to_ulong());		//c[1] = bst2

	for (int i = 0; i < 1; ++i)		//random 2 ký tự đầu
	{
		if (c[i] < 33 || c[i] > 126)	
			return -1;

		int j = rd() % 3;		
		if (j == 1 && c[i] == 65)		
			c[i] -= 33;
		if (j == 2)
		{
			bitset <8> bs(c[i]);
			bs <<= 1;
			if (int(bs.to_ulong()) <= 126 && int(bs.to_ulong()) >= 124)
				c[i] = int(bs.to_ulong());
		}
	}
	
	string key;							
	key = char(c[0] - 16);			//thêm ký tự đầu vào key
	key += char(c[1] - 15);

	for (int i = 0; i < int(s.length()); ++i)	//loại bỏ ký từ null khỏi string
		if (s[i] == 0)
			s = s.substr(0, i);

	key += s;				//thêm string vào key

	cout << "Key: " << key << '\n';		

	cin.get();
	
	return 0;
}