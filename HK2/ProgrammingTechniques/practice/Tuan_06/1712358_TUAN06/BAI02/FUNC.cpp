#include"FUNC.h"

//tra ve so luong chu so cua so nguyen duong N
int Bai02_1(int N)
{
	if (N > 9)
		return 1 + Bai02_1(N / 10);
	else
		return 1;
}

//tra ve tong cac chu so chan cua so nguyen duong N
int Bai02_2(int N)
{
	if (N > 9)
	{
		int SoChan = (N % 10);
		return (SoChan % 2 == 0 ? SoChan : 0) + Bai02_2(N / 10);
	}
	else
	{
		return N % 2 == 0 ? N : 0;
	}
}

//tra ve chu so dau tien cua so nguyen duong N
int Bai02_3(int N)
{
	if (N > 9)
		return Bai02_3(N / 10);
	else
		return N;
}

//in ra so dao nguoc cua so nguyen N
void Bai02_4(int N)
{
	printf("%d", N % 10);
	if (N > 9)
		Bai02_4(N / 10);
}

//tra ve chu so lon nhat cua so nguyen duong N
int Bai02_5(int N)
{
	if (N > 9)
	{
		int FindMax = Bai02_5(N / 10);
		return N % 10 > FindMax ? N % 10 : FindMax;
	}
	else
		return N;
}

//neu N toan chu so le -> tra ve true, nguoc lai -> tra ve false
bool Bai02_6(int N)
{
	if (N > 9)
		return N % 2 == 0 ? false : Bai02_6(N / 10);
	else
		return N % 2 == 0 ? false : true;
}