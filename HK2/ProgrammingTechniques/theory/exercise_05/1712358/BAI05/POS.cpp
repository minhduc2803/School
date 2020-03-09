#include"POS.h"

char* StringPos(char S[], int N, int pos)
{
	static char Buf[1001];
	int j = 0;
	for (int i = pos; i < pos + N && S[i] != NULL; i++)
	{
		Buf[j] = S[i];
		j++;
	}
	Buf[j] = NULL;
	return Buf;
}