#include"POS.h"
#include"INOUT.h"
void main()
{
	char S[1001];
	int N, pos;
	Input(S);
	Input(N);
	Inputp(pos);
	printf("%d characters in S from the position number %d is:\n",N,pos);
	printf("%s\n", StringPos(S, N, pos));
}