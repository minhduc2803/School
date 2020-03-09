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
		for (nope* p = P->out; p != NULL; p = p->next)
			printf("%d ", p->val);
	}
}