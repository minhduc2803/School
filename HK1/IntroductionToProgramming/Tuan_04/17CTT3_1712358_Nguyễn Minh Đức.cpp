					Bài tập thực hành tuần 04   
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
 Nhập một số không âm N
 a) Viết hàm tính số Fibonaci (dùng vòng lặp, dùng đệ qui)
 b) Viết chương trình in ra dãy Fibonaci với các số hạn F0, F1, .., FN.
Câu 2:
Cho phương trình bậc hai: ax2 + bx +c = 0, với a, b, c là các số thực
a) Viết hàm ptbac2(double a, double b, double c).
Hoặc: ptbac2(double a, doube b, double c, double& x1, double& x2, int& sn)
b) Viết chương trình giải phương trình bậc hai trên
Note: hàm ptbac2(): có nhiệm vụ xác định số nghiệm và giải phương trình bậc 2 với a,b,c là
các số thực đã biết a≠0. x1, x2, sn là dạng tham số tham chiếu, hoặc là giá trị trả về của hàm.

Câu 3:
Nhập 2 số a, b
a) Viết hàm tìm USCLN
b) Viết hàm tìm BSCNN
c) Viết chương trình in ra tổng tối giản của 2 phân số: a/b + c/d
Câu 4:
Nhập một số nguyên dương N (N<=1000)
a) Viết hàm kiểm tra số nguyên tố
b) Viết chương trình in ra N số nguyên tố đầu tiên
Câu 5:
Viết chương trình nhập số nguyên N (kiểu char). In ra cho biết biểu diễn nhị phân của
N. 
Câu 6:
Nhập số nguyên dương n
a) Viết hàm tính gia thừa của n
b) Viết chương trình tính các biệu thức sau:
 a.1+1/(2!)+1/(3!)+...+1/(n!) 
 b.1-1/(2!)+1/(3!)-...+(-1)^(n-1)/(n!)
 c.n!
 d.n!! 
 n!!=1x3x5x...xn nếu n%2!=0 
 n!!=2x4x6x...x(2n-1) nếu n%2==0
Câu 7:
Viết chương trình nhập số nguyên dương N, kiểm tra xem N có phải là số hạnh phúc
hay không. (Số hạnh phúc là số có 2K chữ số và tổng K chữ số đầu tiên bằng tổng K
chữ số cuối cùng).

Bài làm:
Câu 1:
#include<stdio.h>

long long fibo(int n);
void main()
{
	char kt = 1;
	int n;
	printf("moi nhap so nguyen khong am n\n");
	while (kt)
	{ 
		printf("n: ");
		scanf_s("%d", &n);
		if (n < 0)
		{
			printf("n khong hop le, moi nhap lai\n");
		}
		else
			kt = 0;
	}
	for (int i = 0; i <= n; i++)
		printf("%lld\n", fibo(i));
}
long long fibo(int n)
{
		long long fibo, fibo1 = 1, fibo2 = 1;
	if (n == 0 || n == 1)
		return (long long)1;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			fibo = fibo1 + fibo2;
			fibo2 = fibo1;
			fibo1 = fibo;
		}
		return fibo;
	}
}

Câu 2:
#include<stdio.h>
#include<math.h>
void ptbac2(double a, double b, double c, double& x1, double& x2, int& sn);
void main()
{
	double a, b, c, x1, x2;
	int sn;
	printf("chuong trinh giai pt bac 2 ax^2+bx+c=0\n");
	printf("nhap a: "); scanf_s("%lf", &a);
	printf("nhap b: "); scanf_s("%lf", &b);
	printf("nhap c: "); scanf_s("%lf", &c);
	ptbac2(a, b, c, x1, x2, sn);
	if (sn == 0)
		printf("pt vo nghiem\n");
	else if (sn == 1)
		printf("pt co nghiem duy nhat x=%lf\n", x1);
	else
		printf("pt co 2 nghiem x1=%lf x2=%lf\n", x1, x2);
}
void ptbac2(double a, double b, double c, double& x1, double& x2, int& sn)
{
	double delta = b*b - 4 * a*c;
	if (delta < 0)
		sn=0;
	else if (delta == 0)
	{
		sn = 1;
		x1 = -b / (2 * a);
	}
	else
	{
		sn = 2;
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);

	}
}

Câu 3:
#include<stdio.h>
int UCLN(int a, int b);
int BCNN(int a, int b);
void toigian(int a, int b, int c, int d, int& tu, int& mau);
void main()
{
	char kt = 1;
	int a, b, c, d, tu, mau;
	printf("moi nhap 2 so nguyen duong a,b\n");
	while (kt)
	{
		printf("a: "); scanf_s("%d", &a);
		printf("b: "); scanf_s("%d", &b);
		if (a <= 0 || b <= 0)
			printf("du lieu khong hop le (a,b phai la 2 so nguyen duong)\nmoi nhap lai\n");
		else
			kt = 0;
	}
	printf("%d va %d co UCLN la %d BCNN la %d\n", a, b, UCLN(a, b), BCNN(a, b));
	kt = 1;
	printf("moi nhap 4 so nguyen a,b,c,d\nchuong trinh se in ra tong a/b+c/d o dang phan so toi gian\n");
	while (kt)
	{
		printf("a: "); scanf_s("%d", &a);
		printf("b: "); scanf_s("%d", &b);
		printf("c: "); scanf_s("%d", &c);
		printf("d: "); scanf_s("%d", &d);
		if (b == 0 || d == 0)
			printf("du lieu ko hop le (a, b, c, d nguyen. b, d khac 0)\nmoi nhap lai\n");
		else
			kt = 0;
	}
	toigian(a, b, c, d, tu, mau);
	printf("%d/%d + %d/%d = %d/%d\n", a,b,c,d,tu, mau);
}
int UCLN(int a, int b)
{
	int ucln=1;
	if (a%b == 0)
		return b;
	else if (b%a == 0)
		return a;
	else if (a < b)
	{
		for (int i = 2; i <= a / 2; i++)
			if (a%i == 0 && b%i == 0)
				ucln = i;
	}
	else
	{
		for (int i = 2; i <= b / 2; i++)
			if (a%i == 0 && b%i == 0)
				ucln = i;
	}
	return ucln;
}
int BCNN(int a, int b)
{
	return a*b / UCLN(a, b);
}
void toigian(int a, int b, int c, int d, int& tu, int& mau)
{
	char dau = 1;
	tu = a*d + c*b;
	mau = b*d;
	if (tu < 0)
	{
		dau = -dau;
		tu = -tu;
	}
	if (mau < 0)
	{
		dau = -dau;
		mau = -mau;
	}
	if (tu != 0)
	{
		int ucln = UCLN(tu, mau);
		tu = dau*tu / ucln;;
		mau /= ucln;
	}
}

Câu 4:
#include<stdio.h>
int kiemtra_songuyento(int n);
void inNsonguyento(int n);
void main()
{
	int n, i;
	char kt = 1, ktnguyento;
	printf("moi nhap so nguyen duong N<=1000 ");
	while (kt)
	{
		printf("N: "); scanf_s("%d", &n);
		if (n<=0 && n>=1000)
			printf("du lieu khong hop le (N la so nguyen duong nho hon hoac bang 1000)\nmoi nhap lai\n");
		else
			kt = 0;
	}
	ktnguyento = kiemtra_songuyento(n);
	if (ktnguyento)
		printf("N la so nguyen to\n");
	else
		printf("N khong phai la so nguyen to\n");
	printf("%d so nguyen to dau tien la: ", n);
	inNsonguyento(n);
}
int kiemtra_songuyento(int n)
{
	int k;
	int n2 = n / 2;
	if (n <= 1)
		return 0;
	else if (n <= 3)
		return 1;
	for (k = 2;; k++)
	{
		if (n%k == 0)
			return 0;
		else if (k > n2)
			return 1;
	}

}
void inNsonguyento(int n)
{
	int j = 2;
	for (int i = 1; i <= n; i++)
	{
		if (kiemtra_songuyento(j) == 1)
			printf("%d ", j);
		else
			i--;
		j++;
	}
}


Câu 5:
#include<stdio.h>

void main()
{
	int fakeN; // o day e dung kieu int, boi vi trong Visual cua e, %d khong tuong thich voi kieu char trong ham scanf_s
	char realN, kt = 1, batdau = 0;// nhung o day e co char N, coi nhu dung yeu cau nka thay hihi
	printf("moi nhap so nguyen N thuoc doan [-128;127]\nchuong trinh se chuyen N sang dang nhi phan\nN: ");
	while (kt)
	{
		scanf_s("%d", &fakeN);
		if (fakeN >= -128 && fakeN <= 127)
		{
			realN = fakeN;
			kt = 0;
		}
		else
			printf("N khong hop le, N thuoc doan [-128;127], moi nhap lai  N: ");
	}
	if (realN < 0)
	{
		realN = ~realN + 1;
		printf("-");
	}
	if (realN == 0)
		printf("0");
	for (int dem = 1; dem <= 8; dem++)
	{
		if (realN < 0)
		{
			printf("1");
			batdau = 1;
		}
		else if (batdau)
		{
			printf("0");
		}
		realN = realN << 1;
	}
	printf("\n");
}

Câu 6:
#include<stdio.h>

int _6a(int n);
float _6b1(float n);
float _6b2(float n);
int _6b3(int n);
int _6b4(int n);
void main()
{
	int n;
	char kt = 1;
	printf("moi nhap so nguyen duong N\n");
	while (kt)
	{
		printf("N: "); scanf_s("%d", &n);
		if (n <= 0)
			printf("du lieu khong hop le (N la so nguyen duong)\nmoi nhap lai\n");
		else
			kt = 0;
	}
	printf("6a) N giai thua bang %d\n",_6a(n));
	printf("6b.1) 1+1/(2!)+1/(3!)+...+1/(n!)=%f\n",_6b1(n));
	printf("6b.2) 1-1/(2!)+1/(3!)-...+(-1)^(n-1)/(n!)=%f\n",_6b2(n));
	printf("6b.3) N!=%d\n", _6a(n));
	printf("6b.4) N!!=%d\n", _6b4(n));
}
int _6a(int n)
{
	int gt = 1;
	for (int i = 1; i <= n; i++)
	{
		gt *= i;
	}
	return gt;
}
float _6b1(float n)
{
	float gt = 1.0, tong = 0.0;
	for (int i = 1; i <= n; i++)
	{
		gt *= (float)i;
		tong += 1 / gt;
	}
	return tong;
}
float _6b2(float n)
{
	float dau = 1.0, gt = 1.0, tong = 0.0;
	for (int i = 1; i <= n; i++)
	{
		gt *= (float)i;
		tong += dau / gt;
		dau *= -1.0;
	}
	return tong;
}
int _6b3(int n)
{
	int gt = 1;
	for (int i = 1; i <= n; i++)
	{
		gt *= i;
	}
	return gt;
}
int _6b4(int n)
{
	int gt = 1;
	int i;
	if (n % 2 == 0)
		i = 2;
	else
		i = 1;
	for (i; i <= n; i = i + 2)
	{
		gt *= i;
	}
	return gt;
}

Câu 7:
#include<stdio.h>
void main()
{
	int n, tong1 = 0, tong2 = 0;
	char kt = 1, chuso[10], i;
	printf("chuong trinh kiem tra N co phai so hanh phuc hay khong\nmoi nhap so nguyen duong N: ");
	while (kt)
	{
		scanf_s("%d", &n);
		if (n > 0)
			kt = 0;
		else
			printf("N khong hop le (N phai la so nguyen duong)\nmoi nhap lai N: ");
	}
	for (i = 0; n != 0; i++)
	{
		chuso[i] = n % 10;
		n /= 10;
	}
	if (n % 2 == 0)
	{
		for (int j = 0; j <= (i / 2 - 1); j++)
			tong1 += chuso[j];
		for (int j = i / 2; j <= i - 1; j++)
			tong2 += chuso[j];
		if (tong1 == tong2)
			printf("N la so hanh phuc\n");
		else
			printf("N khong phai so hanh phuc\n");
	}
	else
		printf("N khong phai so hanh phuc\n");
}