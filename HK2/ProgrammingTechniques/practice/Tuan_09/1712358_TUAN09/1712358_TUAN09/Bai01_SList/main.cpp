#include "HANDLING.h"
#include "INOUT.h"
void main()
{
	STACK* P = (STACK*)malloc(sizeof(STACK));
	InitStack(P);
	int stick, x;
	bool test = false;
	while (1)
	{
		system("cls");
		printf("Stack with linked list\n");
		printf("Choose a number to do a function right after\n\n");
		printf("1: push.| 2: peek. |3: pop |4. empty out stack |5. exit\n");
		printf("stack: ");
		Output(P);
		if (test)
			printf("\nx: %d", x);
		else
			printf("\nx: none");
		printf("  \(recent value\)\n");
		scanf_s("%d", &stick);
		switch (stick)
		{
		case 1: Input(x); test = push(P, x); break;
		case 2: test = peek(P, x); break;
		case 3: test = pop(P, x); break;
		case 4: EmptyingStack(P); test = false; break;
		}
		if (stick == 5)
			break;
	}
}