#include "INOUT.h"
#include "INFO.h"
#include "HANDLING.h"
void Input(int& N)
{
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N phai lon hon 0, thu lai\n");
		else
			break;
	} while (1);
}

void Input(LIST* L, int N)
{
	for (int i = 0; i < N; i++)
	{
		int x;
		printf("Nhap phan tu so %d: ", i);
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
		for (nope* p = L->head; p != NULL; p = p->next)
		{
			printf("%d ", p->data);
		}
}