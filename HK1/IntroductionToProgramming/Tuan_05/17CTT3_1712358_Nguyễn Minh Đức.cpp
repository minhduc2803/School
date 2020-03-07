					Bài tập thực hành tuần 05 
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
 Nhập 2 số a, b
a) Viết hàm hoán vị 2 số: swap(int *a, int *b); // Gọi hàm: swap(&a, &b), a,b tham số địa chỉ của số int
b) Viết hàm hoán vị 2 số: swap(int& a, int& b); //Gọi hàm: swap(a,b), a,b tham số tham chiếu, (C++)
c) Viết hàm hoán vị 2 số: void swap(T& a, T& b); (C++), sử dụng template <class T>: tham số kiểu dữ
liệu T trước khi viết hàm.
Câu 2:
a) Viết hàm trả về giá trị nhỏ nhất của 4 số nguyên
b) Viết thủ tục sắp xếp 4 số nguyên giảm dần. 
Câu 3:
Tính tiền điện phải đóng cho một hộ gia đình, số tiền điện tính theo số kwh mà hộ ấy tiêu thụ
trong 1 tháng cộng với tiền thuế 10% VAT.
Biết Biểu giá điện sinh hoạt:
Định mức sử dụng của hộ/tháng 	Giá bán (đồng/kwh)
Cho kwh từ 0-100 				1242
Cho kwh từ 101-150 				1304
Cho kwh từ 151-200 				1651
Cho kwh từ 201-300 				1788
Cho kwh từ 301-400 				1912
Cho kwh từ 401 trở lên 			1962
Viết hàm double tienDien(int kwh); //Tính tiền điện
Câu 4:
 (Đệ qui)
a) Viết hàm tính số fibonanci bằng đệ qui: void Fibo(int n)
b) *Xem dãy {Fn} được định nghĩa như sau:
F0 = 1, F1 = 2, F2 = 5;
Fn+2 = Fn + Fn-1*Fn+1 nếu n>=1.
1. Tính F6
2. Viết hàm đệ qui tính giá trị của Fn với n là số nguyên không âm
3. Viết hàm tính giá trị Fn không dùng đệ qui
Câu 5:
cho phương trình bậc 2 x2 + bx + c = 0 với b và c là các số nguyên. Trường hợp phương trình có
hai nghiệm thực x1 và x2 (x1<=x2), dãy {Fn} được định nghĩa như sau:
F0 = (x1)^0 + (x2)^0 = 2; F1 = (x1)^1 + (x2)^1 = -b; F2 = (x1)^2 + (x2)^2;
Tổng quát: Fn = (x1)^n + (x2)^n
a) Với b = -4 và c = 1, tính F4
b) Thiết lập công thức tính Fn+1 theo Fn và Fn-1
c) Viết hàm đệ qui tính giá trị Fn với n là số nguyên không âm.
d) Viết hàm tính Fn không dùng đệ qui
Câu 6:
/*Năm không chia hết cho 4 không phải là năm nhuận, những năm chia hết cho 4 nhưng không
chia hết cho 100 là năm nhuận*/
a) Viết hàm xét năm có nhuận hay không: int namNhuan(int year)
b) Viết hàm tính số ngày trong tháng: int nDayOfMonth(int month, int year)
c) Viết hàm tìm ngày kế của một ngày: bool nextDay(int &day, int &month, int &year) 

Bài làm:
Câu 1:
a)
#include<stdio.h>
void swap(int *a, int *b);
void main()
{
	int a, b;
	printf("moi nhap lan luot 2 so nguyen a,b. chuong trinh se hoan doi gia tri giua a va b\n");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
b)
#include<stdio.h>
void swap(int& a, int& b);
void main()
{
	int a, b;
	printf("moi nhap lan luot 2 so nguyen a,b. chuong trinh se hoan doi gia tri giua a va b\n");
	scanf("%d %d", &a, &b);
	swap(a, b);
	printf("a=%d b=%d\n", a, b);
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

Câu 2:
#include<stdio.h>
int min(int a, int b, int c, int d);
void swap4(int& a, int& b, int& c, int& d);
void swap2(int& a, int& b);
void main()
{
	int a, b, c, d;
	printf("moi nhap 4 so nguyen a,b,c,d\nchuong trinh se xuat ra gia tri nho nhat va sap xep 4 so theo thu tu giam dan");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	printf("gia tri nho nhat la: %d\n", min(a, b, c, d));
	swap4(a, b, c, d);
	printf("4 so da nhap theo thu tu giam dan la: %d %d %d %d\n", a, b, c, d);
}
int min(int a, int b, int c, int d)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	return min;
}
void swap4(int& a, int& b, int& c, int& d)
{
	if (a < b) swap2(a, b);
	if (b < c) swap2(b, c);
	if (c < d) swap2(c, d);
	if (a < b) swap2(a, b);
	if (b < c) swap2(c, d);
	if (a < b) swap2(a, b);
}
void swap2(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

Câu 3:
#include<stdio.h>
double tienDien(int kwh);
void main()
{
	char kt = 1;
	int kwh;
	printf("moi hop so kwh da su dung trong 1 thang : ");
	do
	{
		scanf_s("%d", &kwh);
		if (kwh < 0)
			printf("du lieu khong hop le (so kwh phai la so nguyen ko am)\nmoinhap lai: ");
		else
			kt = 0;
	}while (kt);
	printf("tien dien su dung trong 1 thang la: %lf\n", tienDien(kwh));
}
double tienDien(int kwh)
{
	double tiendien;
	if		(kwh > 400)	tiendien = 1242 * 100 + 1304 * 50 + 1651 * 50 + 1788 * 100 + 1912 * 100 + 1962 * (kwh - 400);
	else if (kwh > 300) tiendien = 1242 * 100 + 1304 * 50 + 1651 * 50 + 1788 * 100 + 1912 * (kwh - 300);
	else if (kwh > 200) tiendien = 1242 * 100 + 1304 * 50 + 1651 * 50 + 1788 * (kwh - 200);
	else if (kwh > 150) tiendien = 1242 * 100 + 1304 * 50 + 1651 * (kwh - 150);
	else if (kwh > 100) tiendien = 1242 * 100 + 1304 * (kwh - 100);
	else				tiendien = 1242 * kwh;
	tiendien *= 1.1;
	return tiendien;
}

Câu 4:
a)
#include<stdio.h>

/* theo nhu de bai e phai viet ham tinh so fibocaci bang de quy void Fibo(int n)
nhung e ko hieu s kieu tra ve la kieu void, truyen tham so cung ko phai la dia chi
hay tham chieu thi chang the nao viet de quy duoc, nen e xin sua lai 1 chut 
va e cung xin viet toan bo chuong trinh in FN va day {Fn} de kiem tra dap an a.*/
long long Fibo(int n);
void main()
{
	char kt = 1;
	int n;
	printf("moi nhap so nguyen khong am N: ");
	do
	{
		scanf_s("%d", &n);
		if (n < 0)
			printf("du lieu ko hop le (N phai la so nguyen ko am) moi nhap lai: ");
		else
			kt = 0;
	}while (kt);
	printf("F%d=%lld\n", n, Fibo(n));
	printf("day fibonaci F0 F1 F2...FN: ");
	for (int i = 0; i <= n; i++)
		printf("%lld ", Fibo(i));
}
long long Fibo(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return Fibo(n - 1) + Fibo(n - 2);
}
b)
	1. F2=F1+F0=1+1=2; F3=F2+F1=2+1=3; F4=F3+F2=3+2=5; F5=F4+F3=5+3=8; F6=F5+F4=8+5=13;
	2.
	#include<stdio.h>
long long dayso(int n);
void main()
{
	char kt = 1;
	int n;
	printf("moi nhap so nguyen ko am N: ");
	do
	{
		scanf_s("%d", &n);
		if (n < 0)
			printf("du kien ko hop le (N phai la so nguyen ko am) moi nhap lai N: ");
		else
			kt = 0;
	} while (kt);
	printf("F%d=%lld\n", n, dayso(n));
	printf("day so F0 F1 F2...FN: ");
	for (int i = 0; i <= n; i++)
		printf("%lld ", dayso(i));
}
long long dayso(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	if (n == 2)
		return 5;
	else
		return dayso(n - 2) + dayso(n-3)*dayso(n-1);
}
	3.
	#include<stdio.h>
long long dayso(int n);
void main()
{

	char kt = 1;
	int n;
	printf("moi nhap so nguyen ko am N: ");
	do
	{
		scanf_s("%d", &n);
		if (n < 0)
			printf("du kien ko hop le (N phai la so nguyen ko am) moi nhap lai N: ");
		else
			kt = 0;
	} while (kt);
	printf("F%d=%lld\n", n, dayso(n));
	printf("day so F0 F1 F2...FN: ");
	for (int i = 0; i <= n; i++)
		printf("%lld ", dayso(i));
}
long long dayso(int n)
{
	long long fn,fn1=5,fn2=2,fn3=1;
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	if (n == 2)
		return 5;
	else
		for (int i = 3; i <= n; i++)
		{
			fn = fn2 + fn3*fn1;
			fn3 = fn2;
			fn2 = fn1;
			fn1 = fn;
		}
	return fn;
}
	
Câu 5:
a)
với b=-4 c=1; pt x^2-4x+1=0 co 2 nghiem x1=2-sqrt(3) x2=2+sqrt(3)
=> F4=(x1)^4+(x2)^4=194;
b)
theo pt bac 2: x^2+bx+c=0 <=> x^2=-bx-c (nhan 2 ve cho x^(n-1))
						  <=> x^(n+1)=-bx^n-cx^(n-2) (*)
do x1, x2 đều la nghiem cua (*) nen:
					  x1^(n+1)=-bx1^n-cx1^(n-2)
				  và  x2^(n+1)=-bx2^n-cx2^(n-2)
					  cong ve voi ve 2 pt tren ta dc:
					  x1^(n+1)+x2^(n+1)=-bx1^n-cx1^(n-2)-bx2^n-cx2^(n-2)
									   =(-bx1^n-bx2^n)+(-cx1^(n-2)-cx2^(n-2))
				<=>	  F(n+1)=-bF(n)-cF(n-1)			   
c)
#include<stdio.h>

long long dayso(int n, int b, int c);
bool kiemtra(int a, int b, int c);
void main()
{
	char kt = 1;
	int b, c, n;
	long long Fn;
	printf("moi nhap lan luot 2 he so nguyen b,c\n ");
	printf("b: "); scanf_s("%d", &b);
	printf("c: "); scanf_s("%d", &c);
	printf("moi nhap so nguyen ko am N: ");
	do
	{
		scanf_s("%d", &n);
		if (n < 0)
			printf("du kien ko hop le (N phai la so nguyen ko am) moi nhap lai N: ");
		else
			kt = 0;
	} while (kt);
	if (kiemtra(1, b, c))
	{
		Fn = dayso(n, b, c);
		printf("phan tu Fn=%lld\n", Fn);
	}
	else
		printf("pt bac 2 x^2+%dx+%d=0 vo nghiem nen ko ton tai day {Fn}\n",b,c);
}
long long dayso(int n, int b, int c)
{
	if (n == 0)
		return 2;
	else if (n == 1)
		return -b;
	else return -b*dayso(n - 1, b, c) - c*dayso(n - 2, b, c);
}
bool kiemtra(int a, int b, int c)
{
	int delta = b*b - 4 * a*c;
	if (delta < 0)
		return false;
	else
		return true;
}
d)
#include<stdio.h>

long long dayso(int n, int b, int c);
bool kiemtra(int a, int b, int c);
void main()
{
	char kt = 1;
	int b, c, n;
	long long Fn;
	printf("moi nhap lan luot 2 he so nguyen b,c\n ");
	printf("b: "); scanf_s("%d", &b);
	printf("c: "); scanf_s("%d", &c);
	printf("moi nhap so nguyen ko am N: ");
	do
	{
		scanf_s("%d", &n);
		if (n < 0)
			printf("du kien ko hop le (N phai la so nguyen ko am) moi nhap lai N: ");
		else
			kt = 0;
	} while (kt);
	if (kiemtra(1, b, c))
	{
		Fn = dayso(n, b, c);
		printf("phan tu Fn=%lld\n", Fn);
	}
	else
		printf("pt bac 2 x^2+%dx+%d=0 vo nghiem nen ko ton tai day {Fn}\n", b, c);
}
long long dayso(int n, int b, int c)
{
	int f0 = 2, f1 = -b, f;
	if (n == 0)
		return f0;
	else if (n == 1)
		return f1;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			f = -b*f1 - c*f0;
			f0 = f1;
			f1 = f;
		}
		return f;
	}
}
bool kiemtra(int a, int b, int c)
{
	int delta = b*b - 4 * a*c;
	if (delta < 0)
		return false;
	else
		return true;
}

Câu 6:
#include<stdio.h>

/*  ca 3 cau deu la viet ham ma ko phai viet chuong trinh nen e gop chung 3 ham vao 1 chuong trinh 
"in ra ngay ke cua 1 ngay" de kiem tra a*/
int namNhuan(int year);
int nDayOfMonth(int month, int year);
bool nextDay(int &day, int &month, int &year);
void main()
{
	char kt = 0;
	int day, month, year;
	printf("moi nhap vao 1 ngay, chuong trinh se xuat ra ngay ke cua ngay do\n");
	while (kt==0)
	{
		printf("ngay: "); scanf_s("%d", &day);
		printf("thang: "); scanf_s("%d", &month);
		printf("nam: "); scanf_s("%d", &year);
		kt = nextDay(day, month, year);
		if (kt)
			printf("ngay ke: %d/%d/%d\n", day, month, year);

		else
			printf("ngay nhap vao ko hop le, moi nhap lai\n");
	}

}
int namNhuan(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && (year % 100 != 0)))
		return 366;
	else
		return 365;
}
int nDayOfMonth(int month, int year)
{
	switch (month)
	{
	case 4: case 6: case 9: case 11: return 30;
	case 2: return (namNhuan(year) == 366 ? 29 : 28);
	default: return 31;
	}
}
bool nextDay(int &day, int &month, int &year)
{
	if (day<1 || day>nDayOfMonth(month, year) || month < 1 || month>12)
		return false;
	if (day == nDayOfMonth(month, year))
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
		}
		else
			month++;
	}
	else
		day++;
	return true;
}