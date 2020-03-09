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
	{
		key* p = P->out;
		key* end = P->array + P->N - 1;
		if (P->out > P->in)
		{
			for (p; p <= end; p++)
				printf("%d ", *p);
			p = P->array;
		}
		for (p; p <= P->in; p++)
			printf("%d ", *p);
	}
}