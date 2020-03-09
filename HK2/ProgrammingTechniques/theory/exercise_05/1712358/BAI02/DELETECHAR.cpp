#include"DELETECHAR.h"

char* DeleteChar(char S[], char A)
{
	static char Buf[101];
	int j = 0;
	bool flag = false;
	if (A >= 'A'&&A <= 'Z')
		A = A + ('a' - 'A');
	for (int i = 0; S[i] != NULL; i++)
	{
		if (S[i] != A && S[i] != A - ('a' - 'A'))
		{
			Buf[j] = S[i];
			j++;
		}
	}
	Buf[j] = NULL;
	return Buf;
}