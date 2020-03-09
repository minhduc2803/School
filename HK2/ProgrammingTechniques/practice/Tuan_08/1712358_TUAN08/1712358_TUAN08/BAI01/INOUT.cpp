#include "INOUT.h"
#include "INFO.h"
#include "HANDLING.h"
void Input(int& N)
{
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N must be grater than 0, please try again\n");
		else
			break;
	} while (1);
}

//---Input N elements into LIST L by the function AddTail
void Input(LIST* L, int N)
{
	for (int i = 0; i < N; i++)
	{
		int x;
		printf("Please input the element number %d: ", i);
		scanf_s("%d", &x);
		AddTail(L, x);
	}
}

//---Output LIST L
void Output(LIST* L)
{
	if (TestEmptyList(L))
		printf("empty\n");
	else
		for (ELE* p = L->head; p != NULL; p = p->next)
		{
			printf("%d ", p->data);
		}
}