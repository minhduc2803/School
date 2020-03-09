#include"STANDARDIZED.h"

char* Standardized(char S[])
{
	static char Buf[101];
	int j = 0;
	bool flag = false;
	for (int i = 0; S[i] != NULL; i++)
	{
		if (S[i] != ' ')
		{
			while (S[i] != ' ' && S[i] != NULL)
			{
				Buf[j] = S[i];
				j++;
				i++;
			}
			Buf[j] = ' ';
			j++;
			if (S[i] == NULL)
				break;
		}
	}
	Buf[--j] = NULL;
	return Buf;
}