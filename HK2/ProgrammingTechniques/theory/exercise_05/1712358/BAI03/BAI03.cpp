#include"INOUT.h"
#include"COUNT.h"

void main()
{
	char S[1001];
	int N;
	Input(S);
	Input(N);
	printf("The number of words which are longer then %d characters is %d\n",N,CountChar(S,N));
}