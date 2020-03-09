#include "INOUT.H"

void Input(int& N)
{
	printf("Input a value: ");
	scanf_s("%d", &N);
}
void Output(STACK* P)
{
	if (P->st == NULL)
		printf("empty ");
	else
		for (nope* p = P->st; p != NULL; p = p->next)
		{
			printf("%d ", p->val);
		}
}