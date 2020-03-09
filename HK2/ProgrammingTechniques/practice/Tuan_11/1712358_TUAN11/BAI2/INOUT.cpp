#include "INOUT.h"
void Input(int& N)
{
	printf("Please input the positive integer N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N must be a positive integer, try again: ");
		else
			break;
	} while (1);
}

void Input(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("A[%d]: ", i);
		scanf_s("%d", &A[i]);
	}
}
void Output(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}