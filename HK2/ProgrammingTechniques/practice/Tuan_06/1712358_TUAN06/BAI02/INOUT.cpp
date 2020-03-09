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
