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
void Input(int& r)
{
	printf("Please input a integer radix which is bigger than 1, r: ");
	while (1)
	{
		scanf_s("%d", &r);
		if (r < 2)
			printf("r must be bigger than 2, please try again\n");
		else
			break;
	}
}