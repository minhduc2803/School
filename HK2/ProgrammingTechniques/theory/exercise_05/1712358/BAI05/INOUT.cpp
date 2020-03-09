#include"INOUT.h"
void Input(char S[])
{
	printf("Please input the string S:\n");
	gets_s(S, 1001);
}
void Output(char S[])
{
	printf("%s", S);
}
void Input(int& N)
{
	printf("Please input a positive number of characters you want to print, N: ");
	while (1)
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N must be positive, try again N: ");
		else
			break;
	}
}
void Inputp(int& pos)
{
	printf("Please input a position in S you want to start printing: ");
	while (1)
	{
		scanf_s("%d", &pos);
		if (pos < 0)
			printf("pos must be a natural number, try again pos: ");
		else
			break;
	}
}