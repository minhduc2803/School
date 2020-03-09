#include"FUNC.h"

//tra ve so luong chu so cua so nguyen duong N
int Bai05(int N)
{
	if (N > 9)
		return 1 + Bai05(N / 10);
	else
		return 1;
}

//tra ve tong cac chu so cua so nguyen duong N
int Bai07(int N)
{
	if (N > 9)
		return N % 10 + Bai07(N / 10);
	else
		return N;
}

//in ra so dao nguoc cua so nguyen N
void Bai08(int N)
{
	printf("%d", N % 10);
	if (N > 9)
		Bai08(N / 10);
}

//tra ve chu so lon nhat cua so nguyen duong N
int Bai09(int N)
{
	if (N > 9)
		return N % 10 > Bai09(N / 10) ? N % 10 : Bai09(N / 10);
	else
		return N;
}

//neu N toan chu so le -> tra ve true, nguoc lai -> tra ve false
bool Bai10(int N)
{
	if (N > 9)
		if (N % 2 == 0)
			return false;
		else
			return Bai10(N / 10);
	else
		if (N % 2 == 0)
			return false;
		else
			return true;
}
