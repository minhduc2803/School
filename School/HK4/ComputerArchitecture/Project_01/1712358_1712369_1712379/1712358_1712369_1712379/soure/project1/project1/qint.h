#ifndef _QINT_H_
#define _QINT_H_

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Qint {
	bitset<128> core;

public:
	Qint(string p, int base);
	Qint(Qint *temp);

	//constructor này khởi tạo toàn bộ các bit bằng 0
	Qint();
	~Qint();
	
	//hàm chuyển số binary dạng bitset sang string để in vào file
	string to_string();

	//hàm chuyển từ cớ số 2 sang cơ số trong biến base, từ hàm này sẽ gọi tới 2 hàm bi_to_dec() và bi_to_hex()
	string bi_to(int base);
	//hàm chuyển từ cơ số 2 sang cơ số 10
	string bi_to_dec();
	//hàm chuyển từ cơ số 2 sang cơ số 16
	string bi_to_hex();

	//lấy bù 2 của số hiện tại
	void bu_2();

	Qint operator + (Qint B);
	Qint operator - (Qint B);
	Qint operator * (Qint B);
	Qint operator / (Qint B);

	Qint operator & (Qint B);
	Qint operator | (Qint B);
	Qint operator ^ (Qint B);
	Qint operator ~ ();
	Qint operator << (Qint B);
	Qint operator >> (Qint B);
	void rol();
	void ror();

	bool operator < (Qint B);
	bool operator > (Qint B);
	bool operator <= (Qint B);
	bool operator >= (Qint B);
	Qint operator % (Qint B);
};

#endif
