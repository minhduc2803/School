#include<stdio.h>

struct PHANSO {
	int iTuSo;
	int iMauSo;
};
typedef PHANSO PhanSo;

//cau 1

void nhap(PhanSo A)
{
	printf("moi nhap lan luot tu so va mau so: ");
	while (1)
	{
		scanf_s("%d %d", &A.iTuSo, &A.iMauSo);
		if (A.iMauSo == 0)
			printf("mau so phai khac 0, moi nhap lai tu so va mau so: ");
		else break;
	}
}
void xuat(PhanSo A)
{
	printf("%d/%d", A.iMauSo, A.iMauSo);
}

//cau 2

int UCLN(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (a != 0 && b != 0)
	{
		if (a >= b)
			a = a%b;
		else
			b = b%a;
	}
	return a + b;
}
void tong(PhanSo A, PhanSo B, PhanSo C)
{
	C.iTuSo = A.iTuSo*B.iMauSo + B.iTuSo*A.iMauSo;
	C.iMauSo = A.iMauSo*B.iMauSo;
}
void hieu(PhanSo A, PhanSo B, PhanSo C)
{
	C.iTuSo = A.iTuSo*B.iMauSo - B.iTuSo*A.iMauSo;
	C.iMauSo = A.iMauSo*B.iMauSo;
}
void tich(PhanSo A, PhanSo B, PhanSo C)
{
	C.iTuSo = A.iTuSo*B.iTuSo;
	C.iMauSo = A.iMauSo*B.iMauSo;
}
void thuong(PhanSo A, PhanSo B, PhanSo C)
{
	C.iTuSo = A.iTuSo*B.iMauSo;
	C.iMauSo = A.iMauSo*B.iTuSo;
}

//cau 3

void rutgon(PhanSo A)
{
	int ucln = UCLN(A.iTuSo, A.iMauSo);
	A.iTuSo /= ucln;
	A.iMauSo /= ucln;
}

//cau 4

int sosanh(PhanSo A, PhanSo B)
{
	int Dau;
	PhanSo C;
	hieu(A, B, C);
	Dau = C.iTuSo*C.iMauSo;
	if (Dau < 0)
		return -1;
	else if (Dau == 0)
		return 0;
	else
		return 1;
}