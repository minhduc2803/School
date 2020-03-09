#include"TRIANGLE_S.h"
#include"TRIANGLE.h"
#include"POINT.h"
#include<math.h>
void InputTriangle_s(TRIANGLE T[], int& N)
{
	printf("moi nhap so luong tam giac N: ");
	while (1)
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N ko hop le, moi nhap lai: ");
		else
			break;
	}
	printf("moi nhap lan luot hoanh do va tung do cac diem cua tung tam giac\n");
	for (int i = 0; i < N; i++)
	{
		InputTriangle(T[i]);
		printf("\n");
	}
}
void OutputTriangle_s(TRIANGLE T[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("Tam giac %d ", i+1);
		OutputTriangle(T[i]);
		printf(";\n");
	}
}

float Perimeter(TRIANGLE E)
{
	float AB = Distance(E.A, E.B);
	float BC = Distance(E.B, E.C);
	float CA = Distance(E.C, E.A);
	return AB + BC + CA;
}

float Area(TRIANGLE E)
{
	float AB = Distance(E.A, E.B);
	float BC = Distance(E.B, E.C);
	float CA = Distance(E.C, E.A);
	float p = Perimeter(E) / 2;
	return sqrt(p*(p - AB)*(p - BC)*(p - CA));
}
int MaxPerimeter(TRIANGLE T[], int N)
{
	float Max = 0;
	int vtMax = 0;
	for (int i = 0; i < N; i++)
	{
		float Maxht = Perimeter(T[i]);
		if (Maxht > Max)
		{
			Max = Maxht;
			vtMax = i;
		}
	}
	return vtMax;
}
int MinPerimeter(TRIANGLE T[], int N)
{
	float Min = Perimeter(T[0]);
	int vtMin = 0;
	for (int i = 0; i < N; i++)
	{
		float Minht = Perimeter(T[i]);
		if (Minht < Min)
		{
			Min = Minht;
			vtMin = i;
		}
	}
	return vtMin;
}
float SumOfArea(TRIANGLE T[], int N)
{
	float Sum = 0;
	for (int i = 0; i < N; i++)
		Sum += Area(T[i]);
	return Sum;
}
void CountLargeArea(TRIANGLE T[], int N)
{
	bool flag = false;
	float Avarage = SumOfArea(T, N) / N;
	for (int i = 0; i < N; i++)
	{
		if (Area(T[i]) > Avarage)
		{
			printf("\n");
			OutputTriangle(T[i]);
			flag = true;
		}
	}
	if (!flag)
		printf("\nKhong co tam giac nao co dien tich lon hon dien tich trung binh");
}
void SwapTriangle(TRIANGLE& A, TRIANGLE& B)
{
	SwapPoint(A.A, B.A);
	SwapPoint(A.B, B.B);
	SwapPoint(A.C, B.C);
}
void SortDePerimeter(TRIANGLE T[], int N)
{
	int h[100];
	for (int i = 0; i < 100; i++)
		h[i] = i;
	for (int i = N; i > 1; i--)
	{
		SwapTriangle(T[i-1], T[MinPerimeter(T, i)]);
	}
	OutputTriangle_s(T, N);
}