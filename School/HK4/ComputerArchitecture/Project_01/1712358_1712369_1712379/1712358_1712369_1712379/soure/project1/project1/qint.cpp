#include "qint.h"

// hàm chuyển cơ số
Qint::Qint(string p, int base)
{
	switch (base)
	{
	case 2:
	{
		bitset<128> M(p);// khởi tạo biset từ dãy binary
		this->core = M;
		break;
	}
	case 10:
	{
		//this->core.reset();
		bool sign = false;// xử lý dấu
		if (p[0] == '-')
		{
			sign = true;
			p.erase(0, 1);
		}

		for (int i = 0; i < 127; ++i)// hàm chia cho 2
		{
			int L = p.length();

			(p[L - 1] % 2) ? this->core.set(i, 1) : this->core.set(i, 0);// nếu số đầu tiên của dãy số chia hết cho 2 gán 0, nếu ko thì gán 1

			int add = 0;

			for (int j = 0; j < L; ++j)
			{
				int tmp = p[j] - '0';// đổi char sang int
				p[j] = tmp / 2 + add + '0';// giá trị mới của số đầu tiên của dãy số sau khi chia cho 2
				add = tmp % 2 ? 5 : 0;// nếu số đầu tiên của dãy số ko chia hết cho 2 thì cộng thêm 5 vào số tiếp theo của dãy số
			}

			if (p[0] == '0')// xóa số 0 dư
			{
				if (p == "0")
					break;
				else
					p.erase(0, 1);
			}
		}
		if (sign)// xử lý dấu
			this->bu_2();
		break;
	}
	case 16:
		for (int i = 0, j = p.length() - 1; i < 128 && j >= 0; i += 4, --j)
		{
			int n;
			n = (p[j] <= '9') ? p[j] - '0' : p[j] - 'A' + 10;// đổi 1 đơn vị của dãy hex sang dec

			bitset<4> tmp(n);// đổi dec sang bin 4 bit

			this->core.set(i, tmp[0]);
			this->core.set(i + 1, tmp[1]);
			this->core.set(i + 2, tmp[2]);
			this->core.set(i + 3, tmp[3]);
		}
	}
}
Qint::Qint(Qint *temp)
{
	this->core = temp->core;
}
Qint::Qint()
{
	this->core.reset();
}
Qint::~Qint()
{

}

// hàm chuyển số binary dạng bitset sang string để in vào file
string Qint::to_string()
{
	string p = core.to_string();// đổi bitset sang string
	int i = 0;
	while (p[i] == '0')// xóa số 0 dư
	{
		if (i == 127) break;
		i++;
	}
	p.push_back('\n');
	string temp = p.substr(i);
	return temp;// trả về kết quả
}
//hàm chuyển từ cớ số 2 sang cơ số trong biến base, từ hàm này sẽ gọi tới 2 hàm bi_to_dec() và bi_to_hex()
string Qint::bi_to(int base)
{
	if (core == 0)
		return "0\n";

	switch (base)
	{
	case 2: return this->to_string();
	case 10: return this->bi_to_dec();
	case 16: return this->bi_to_hex();
	}
}

//hàm chuyển từ cơ số 2 sang cơ số 10
string Qint::bi_to_dec()
{
	bool sign = false;// xử lý dấu
	if (this->core[127] == 1)
	{
		sign = true;
		this->bu_2();
	}
	bitset<300> dd;// khỏi tạo mảng tạm để chứa

	int k = 128;

	while (this->core[k - 1] != 1)// xác định độ dài k của dãy bitset
		--k;

	int dd_size = k + 4 * (k / 3 + 1);// xác định độ dài của mảng chứa 

	for (int i = 0; i < k; ++i)// nạp dãy bitset vào mảng chứa
		dd[i] = this->core[i];

	for (int i = 0; i < k; ++i)// đổi bin sang bcd bằng thuật toán double dabble
	{
		for (int j = k; j < dd_size; j += 4)// kiểm tra từng bộ 4 bit của mảng tạm
		{
			bitset<4> b0;

			b0[0] = dd[j];
			b0[1] = dd[j + 1];
			b0[2] = dd[j + 2];
			b0[3] = dd[j + 3];

			int n = int(b0.to_ulong());// đổi bin sang dec

			if (n >= 5)// nếu có giá trị lớn hơn 5 thì cộng thêm 3 vào
			{
				n += 3;

				bitset<4> b1(n);// đổi dec sang bin

				dd[j] = b1[0];
				dd[j + 1] = b1[1];
				dd[j + 2] = b1[2];
				dd[j + 3] = b1[3];
			}
		}
		dd <<= 1;// left shift
	}

	string tmp;

	for (int i = dd_size - 1; i >= k; i -= 4)// đổi bcd sang dec
	{
		bitset<4> b;

		b[3] = dd[i];
		b[2] = dd[i - 1];
		b[1] = dd[i - 2];
		b[0] = dd[i - 3];

		int n = int(b.to_ulong());// đổi bin sang dec

		char c = n + '0';

		tmp.push_back(c);// thêm số dec vào chuỗi xuất ra
	}

	int i = 0;

	while (tmp[i] == '0')
		++i;

	tmp.erase(0, i);// xóa sô 0 dư

	if (sign)// xử lý dấu
		tmp.insert(0, "-");

	tmp.push_back('\n');

	return tmp;// trả về kết quả
}
//hàm chuyển từ cơ số 2 sang cơ số 16
string Qint::bi_to_hex()
{
	string tmp;

	for (int i = 127; i >= 0; i -= 4)
	{
		bitset<4> b;

		b.set(3, this->core[i]);
		b.set(2, this->core[i - 1]);
		b.set(1, this->core[i - 2]);
		b.set(0, this->core[i - 3]);

		char c = int(b.to_ulong());// đổi tường bộ bin 4 bit sang hex

		c = (c <= 9) ? c + '0' : c - 10 + 'A';

		tmp.push_back(c);// thêm số hex vào chuỗi xuất ra
	}

	int i = 0;

	while (tmp[i] == '0')
		++i;

	tmp.erase(0, i);// xóa số 0 dư

	tmp.push_back('\n');

	return tmp;// trả về kết quả
}
//lấy bù 2 của số hiện tại
void Qint::bu_2()
{
	int i = 0;
	while (i < 128)
		if (core[i++] == 1) break;
	while (i < 128)
	{
		core[i] = ~core[i];
		i++;
	}
}

bool Qint::operator >= (Qint B) //qua tải toán tử lớn hơn bằng
{
	for (int i = 127; i >= 0; i--) //chạy từ đầu bitset
	{
		if (this->core[i] ^ B.core[i]) //nếu 2 phần tử cùng cột khác nhau
		{
			if (this->core[i] == 1) // nếu phần tử bên trái = 1
				return 1; //trả về 1, khi đó phép so sánh đúng
			else
				return 0; //trả về 0, khi đó phép so sánh sai
		}
	}
	return 1; //trả về 1, khi đó 2 số bằng nhau
}

bool Qint::operator < (Qint B) //quá tải toán tử bé hơn
{
	return (!((*this) >= B)); //trả về not của phép so sánh lớn hơn bằng
}

bool Qint::operator <= (Qint B) //quá tải toán tử bé hơn bằng
{
	return ((*this) < B || this->core == B.core); // trả về kết quả phép or giữa so sánh bé hơn và so sánh bằng
}

bool Qint::operator > (Qint B) //quá tải toán tử lớn hơn
{
	return (!((*this) <= B)); //trả về not của phép so sánh bé hơn bằng
}

Qint Qint::operator + (Qint B) // quá tải toán tử cộng
{
	Qint C; // C là đối tượng để trả về kết quả cộng
	C.core.reset(); //reset bitset
	bool temp = 0; //lưu số được cộng dồn từ cột trước
	for (int i = 0; i < 128; i++) //cộng theo từng cột
	{
		if ((this->core[i] ^ B.core[i]) == 0) //nếu 2 phần tử giống nhau
		{
			C.core[i] = temp; //gán cột kết quả bằng với số cộng dồn từ cột trước
			temp = this->core[i]; //gán số cộng dồn bằng với 1 phần tử của số hạng 
		}
		else  //nếu 2 phần tử của số hạng khác nhau
		{
			C.core[i] = !temp;
		}
	}
	return C; //trả về kết quả
}

Qint Qint::operator - (Qint B)
{
	B.bu_2();
	Qint C = (*this) + B;
	return C;
}

Qint Qint::operator * (Qint B)
{
	Qint C;
	C.core.reset();
	bool temp[129] = { 0 }; //mảng lưu tạm thời kết quả ở từng cột
	int memory[129] = { 0 }; //mảng để lưu số lượng giá trị cộng dồn

	for (int i = 0; i < 128; i++)
	{
		if (B.core[i] == 0) //nếu phần tử của B có giá trị bằng 0 thì bỏ qua
			continue;
		for (int j = 0; i + j < 128; j++) // nếu chạy quá cột thứ 128 sẽ bị bỏ qua
		{
			bool x = B.core[i] & this->core[j]; // lưu giá trị and giữa 2 phần tử
			if (temp[i + j] == 1) //nếu cột kết quả tạm thời đã có giá trị 1
			{
				if (x == 1)  //nếu x = 1
				{
					temp[i + j] = 0; //cột kết quả tạm thời về giá trị 0
					memory[i + j + 1]++; //tăng giá trị cộng dồn ở cột kế tiếp lên 1 đơn vị
				}
			}
			else // nếu x = 0
			{
				temp[i + j] = x; // gán cột kết quả tạm thời bằng x
			}
		}
	}
	for (int i = 0; i < 128; i++) //chạy từ đầu bitset đến cuối bitset
	{
		if (temp[i] == 0) //nếu cột kết quả tạm thời có giá trị = 0
		{
			if (memory[i] % 2 == 0) //nếu giá trị cộng dồn ở cột đó là số chẵn
			{
				C.core[i] = 0; // gán kết quả ở cột đó = 0
				memory[i + 1] = memory[i + 1] + memory[i] / 2; //giá trị cộng dồn ở cột kế tiếp sẽ được tăng thêm
															   //bằng 1 nửa giá trị cộng dồn ở cột hiện tại	
			}
			else //nếu giá trị cộng dồn ở cột đó là số lẻ
			{
				C.core[i] = 1; //gán kết quả ở cột đó = 1
				memory[i + 1] = memory[i + 1] + (memory[i] - 1) / 2; //giá trị cộng dồn ở cột kế tiếp sẽ được tăng thêm
															   //bằng giá trị cộng dồn ở cột hiện tại trừ 1 rồi chia đôi	
			}
		}
		else //nếu cột kết quả tạm thời có giá trị = 1
		{
			if (memory[i] % 2 == 0) //nếu giá trị cộng dồn ở cột đó là số chẵn
			{
				C.core[i] = 1; //gán kết quả ở cột đó = 1
				memory[i + 1] = memory[i + 1] + memory[i] / 2; //giá trị cộng dồn ở cột kế tiếp sẽ được tăng thêm
															   //bằng 1 nửa giá trị cộng dồn ở cột hiện tại	

			}
			else //nếu giá trị cộng dồn ở cột đó là số lẻ
			{
				C.core[i] = 0; // gán kết quả ở cột đó = 0
				memory[i + 1] = memory[i + 1] + (memory[i] - 1) / 2 + 1; //giá trị cộng dồn ở cột kế tiếp sẽ được tăng thêm
															   //bằng giá trị cộng dồn ở cột hiện tại trừ 1 rồi chia đôi,
																//cuối cùng cộng thêm 1
			}
		}
	}
	return C; //trả về kết quả
}


Qint Qint::operator / (Qint B)
{
	Qint C; //lưu thương của phép chia
	C.core.reset();
	bool sign = core[127] ^ B.core[127]; // gán dấu của kết quả bằng phép xor 2 dấu của số bị chia và số chia
	
	if (core[127] == 1)
		this->bu_2();
	if (B.core[127] == 1)
		B.bu_2();

	Qint sobichia = (*this);
	Qint sochia = B;
	if (sobichia < sochia)
		return C;

	Qint temp;
	temp.core.reset(); // bây giờ temp có vai trò lưu số dư của phép chia

	int index_sobichia = 128, index_sochia = 128; //lưu chỉ số của số 1 đầu tiên trong bitset
	while (sobichia.core[--index_sobichia] == 0);
	while (sochia.core[--index_sochia] == 0);
	
	sochia.core <<= (index_sobichia - index_sochia); // dịch trái số chia sang (index_sobichia - index_sochia) vị trí
	int i = index_sobichia;
	for (i; i > index_sobichia - index_sochia; i--)
		temp.core[i] = sobichia.core[i];
	for (i; i >= 0; i--) //chạy từ cột mà số 1 xuất hiện đầu tiên ở số bị chia 
	{
		temp.core[i] = sobichia.core[i];

		if (temp >= sochia)
		{
			C.core[i] = 1;
			temp = temp - sochia;
		}
		
		sochia.core >>= 1; // dịch phải số chia 1 vị trí
	}
	if (sign) C.bu_2();

	return C; //trả về thương
}

Qint Qint::operator % (Qint B)
{
	Qint C; //lưu thương của phép chia
	C.core.reset();
	bool sign = core[127] ^ B.core[127]; // gán dấu của kết quả bằng phép xor 2 dấu của số bị chia và số chia

	if (core[127] == 1)
		this->bu_2();
	if (B.core[127] == 1)
		B.bu_2();

	Qint sobichia = (*this);
	Qint sochia = B;
	if (sobichia < sochia)
		return C;

	Qint temp;
	temp.core.reset(); // bây giờ temp có vai trò lưu số dư của phép chia

	int index_sobichia = 128, index_sochia = 128; //lưu chỉ số của số 1 đầu tiên trong bitset
	while (sobichia.core[--index_sobichia] == 0);
	while (sochia.core[--index_sochia] == 0);

	sochia.core <<= (index_sobichia - index_sochia); // dịch trái số chia sang (index_sobichia - index_sochia) vị trí
	int i = index_sobichia;
	for (i; i > index_sobichia - index_sochia; i--)
		temp.core[i] = sobichia.core[i];
	for (i; i >= 0; i--) //chạy từ cột mà số 1 xuất hiện đầu tiên ở số bị chia 
	{
		temp.core[i] = sobichia.core[i];

		if (temp >= sochia)
		{
			C.core[i] = 1;
			temp = temp - sochia;
		}

		sochia.core >>= 1; // dịch phải số chia 1 vị trí
	}
	if (sign) C.bu_2();

	return temp; //trả về phần dư
}
	
Qint Qint::operator & (Qint B)
{
	Qint C;
	C.core = this->core & B.core;
	return C;
}
Qint Qint::operator | (Qint B)
{
	Qint C;
	C.core = this->core | B.core;
	return C;
}
Qint Qint::operator ^ (Qint B)
{
	Qint C;
	C.core = this->core ^ B.core;
	return C;
}
Qint Qint::operator ~ ()
{
	Qint C;
	C.core = ~this->core;
	return C;
}
Qint Qint::operator << (Qint B)
{
	Qint C;
	C.core = this->core << B.core.to_ulong();
	return C;
}
Qint Qint::operator >> (Qint B)
{
	Qint C;

	//Nếu số ban đầu là số âm ta dịch phải k bit, mỗi lần dịch qua 1 bit trái nhất thì phải gán bit đầu tiên bằng 1
	if (this->core[127] == 1)
	{
		int number = B.core.to_ulong();
		for (int i = 0; i < number; i++)
		{
			this->core >>= 1;
			this->core.set(127, 1);
		}
		C = (*this);
	}
	else
		C.core = this->core >> B.core.to_ulong();
	return C;
}
void Qint::rol()
{
	int first_bit = this->core[127];
	this->core <<= 1;
	this->core.set(0, first_bit);
}
void Qint::ror()
{
	int last_bit = this->core[0];
	this->core >>= 1;
	this->core.set(127, last_bit);
}