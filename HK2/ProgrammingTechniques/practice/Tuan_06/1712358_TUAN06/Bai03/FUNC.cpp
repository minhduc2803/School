#include"FUNC.h"

//nhap mang so nguyen
void Bai03_1(int A[], int& N)
{
	Input(N);
	Input(A, N);
}

//xuat mang so nguyen ra man hinh
void Bai03_2(int A[], int N)
{
	Output(A, N);
}

//xuat mang so nguyen theo thu tu nguoc
void Bai03_3(int A[], int N)
{
	if (N > 0)
	{
		printf("%d ", A[N - 1]);
		Bai03_3(A, N - 1);
	}
}

//tra ve so lon nhat tong mang so nguyen
int Bai03_4(int A[], int N)
{
	if (N > 1)
	{
		int Max = Bai03_4(A, N - 1);
		return A[N - 1] > Max ? A[N - 1] : Max;
	}
	else
		return A[0];
}

//tra ve so luong so nguyen to co trong mang so nguyen
int Bai03_5(int A[], int N)
{
	if (N > 0)
		return Bai03_5(A, N - 1) + (KTNguyenTo(A[N-1]) ? 1 : 0);
	else
		return KTNguyenTo(A[0]) ? 1 : 0;
}

//tra ve so luong cac gia tri phan biet trong mang
int Bai03_6(int A[], int N, int i)
{
	if (i < N)
	{
		int E = 1;
		for (int j = 0; j < i; j++)
			if (A[i] == A[j])
				E = 0;
		return E + Bai03_6(A, N, i + 1);
	}
	else
		return 0;
}

//neu mang toan cac gia tri chia het cho 7 -> tra ve true, nguoc lai -> tra ve false
bool Bai03_7(int A[], int N)
{
	if (N > 1)
		return A[N - 1] % 7 == 0 ? Bai03_7(A, N - 1) : false;
	else
		return A[0] % 7 == 0 ? true : false;
}

//sap xep mang theo thu tu tang dan
void Bai03_8(int A[], int N)
{
	Bai03_8(A, N, 0, N - 1);
}
void Bai03_8(int A[], int N, int head, int tail)
{
	if (head != tail)
	{
		int i = head, j = tail;
		int ave = A[head];
		for (i, j; i <= j;)
		{
			if (A[i] >= ave)
			{
				if (A[j] <= ave)
				{
					if (A[i] != A[j])
						swap(A[i], A[j]);
					i++;
					j--;
				}
				else
					j--;
			}
			else
				i++;
		}
		Bai03_8(A, N, head, i - 1);
		Bai03_8(A, N, i, tail);
	}
}

//hoan vi 2 so a,b
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//neu A la so nguyen to -> tra ve true, nguoc lai -> tra ve false
bool KTNguyenTo(int A)
{
	if (A <= 1)
		return false;
	else if (A <= 3)
		return true;
	else
	{
		for (int i = 2; i <= sqrt(A); i++)
		{
			if (A % i == 0)
				return false;
		}
		return true;
	}
}