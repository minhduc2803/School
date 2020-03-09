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
void Input(char& A)
{
	printf("Please input a character you want to delete: ");
	do
	{
		A = getchar();
	} while (A == '\n' || A == NULL);
}