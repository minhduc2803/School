#include "INOUT.H"
#include "HANDLING.h"
void Input(int& N)
{
	printf("Input a value: ");
	scanf_s("%d", &N);
}
void Output(QUEUE* P)
{
	if (IfEmptyQueue(P))
		printf("empty ");
	else
		for (key* p = P->out; p <= P->in; p++)
		{
			printf("%d ", *p);
		}
}