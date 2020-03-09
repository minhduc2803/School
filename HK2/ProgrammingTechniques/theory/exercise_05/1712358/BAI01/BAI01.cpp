#include"STANDARDIZED.h"
#include"INOUT.h"
void main()
{
	char S[1001];
	Input(S);
	printf("After standardizing, the string S is:\n");
	Output(Standardized(S));
	printf("\n");
}