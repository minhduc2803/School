#include"INOUT.h"
void Input(int& N)
{
	printf("Please input a positive integer N: ");
	while (1)
	{
			scanf_s("%d", &N);
		if (N <= 0)
			printf("N must be a possitive integer, please try again\n");
		else
			break;
	}
}
void Input(int A[], int N)
{
	printf("Please input the array\n");
	for (int i = 0; i < N; i++)
	{
		printf("A[%d] = ", i);
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