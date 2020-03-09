#include"LONGEST.h"

void LongestWords(char S[])
{
	int Buf[100];
	int num[100];
	int Max = 0;
	int j = 0;
	bool flag = false;
	for (int i = 0; S[i] != NULL; i++)
	{
		while (S[i] == ' ')
			i++;
		num[j] = 0;
		Buf[j] = i;
		while (S[i] != ' ' && S[i] != NULL)
		{
			num[j]++;
			i++;
		}
		if (S[i] == NULL)
			break;
		j++;
	}
	for (int i = 0; i <= j; i++)
	{
		if (num[i] > Max)
			Max = num[i];
	}
	for (int i = 0; i <= j; i++)
		if (num[i] == Max)
		{
			if(flag)
				printf("\t");
			PrintWord(S, Buf[i], num[i]);
			flag = true;
		}
}
void PrintWord(char S[], int Buf, int N)
{
	for (int i = Buf; i < Buf + N; i++)
	{
		printf("%c", S[i]);
	}
}