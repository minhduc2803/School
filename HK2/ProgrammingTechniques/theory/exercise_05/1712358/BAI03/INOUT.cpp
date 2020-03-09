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
	printf("Please input a number: ");
	do
	{
		scanf_s("%d", &N);
	} while (N == '\n' || N == NULL);
}