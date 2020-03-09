#include"COUNT.h"

int CountChar(char S[], int N)
{
	int num = 0;
	for (int i = 0; S[i] != NULL; i++)
	{
		int chars = 0;
		while (S[i] != ' ' && S[i] != NULL)
		{
			chars++;
			i++;
		}
		if (chars > N)
			num++;
		if (S[i] == NULL)
			break;
	}
	return num;
}