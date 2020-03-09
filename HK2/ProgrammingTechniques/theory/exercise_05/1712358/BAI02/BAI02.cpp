#include"INOUT.h"
#include"DELETECHAR.h"

void main()
{
	char S[1001];
	char A;
	Input(S);
	Input(A);
	printf("After moving all the character \"%c\", The string S is:\n%s\n",A,DeleteChar(S,A));
}