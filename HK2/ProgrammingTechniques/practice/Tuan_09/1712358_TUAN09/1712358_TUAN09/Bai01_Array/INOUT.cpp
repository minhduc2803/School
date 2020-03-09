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
		for (key* p = P->st; p >= P->array; p--)
		{
			printf("%d ", *p);
		}
}