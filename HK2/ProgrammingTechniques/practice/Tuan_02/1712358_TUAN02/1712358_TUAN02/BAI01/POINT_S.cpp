#include"POINT_S.h"
#include<math.h>

void InputPoint_s(POINT A[], int& N)
{
	printf("moi nhap so luong diem N: ");
	while (1)
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N ko hop le, moi nhap lai: ");
		else
			break;
	}
	printf("moi nhap lan luot hoanh do va tung do cac diem:\n");
	for (int i = 0; i < N; i++)
	{
		InputPoint(A[i]);
		printf("\n");
	}
}
void OutputPoint_s(POINT A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		OutputPoint(A[i]);
	}
}

float Distance(POINT A, POINT B)
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

int MaxDistance(POINT A, POINT P[], int N)
{
	float Max = 0;
	int vtMax = 0;
	for (int i = 0; i < N; i++)
	{
		float Maxht = Distance(A, P[i]);
		if (Maxht > Max)
		{
			Max = Maxht;
			vtMax = i;
		}
	}
	return vtMax;
}

void PositivePoint_s(POINT P[], int N)
{
	POINT Q[100];
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (P[i].x > 0 && P[i].y > 0)
		{
			Q[j].x = P[i].x;
			Q[j].y = P[i].y;
			j++;
		}
	}
	if (j == 0)
		printf("TRONG MANG KHONG CO DIEM NAO CO TOA DO DUONG.");
	else
	OutputPoint_s(Q, j);
} 

void SwapPoint_s(POINT& A, POINT& B)
{
	float x = A.x;
	float y = A.y;
	A.x = B.x;
	A.y = B.y;
	B.x = x;
	B.y = y;
}
void SortPoint_s(POINT P[], int N)
{
	POINT O;
	O.x = 0;
	O.y = 0;
	for (int i = N; i > 1; i--)
	{
		SwapPoint_s(P[i-1], P[MaxDistance(O, P, i)]);
	}
}