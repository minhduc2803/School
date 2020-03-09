#include "HANDLING.h"
#include "INOUT.h"
void main()
{
	QUEUE* P = (QUEUE*)malloc(sizeof(QUEUE));
	InitQueue(P);
	int stick, x;
	bool test = false;
	while (1)
	{
		system("cls");
		printf("Queue with array (20 elements)\n");
		printf("Choose a number to do a function right after\n\n");
		printf("1: enqueue.| 2: peek. |3: dequeue |4. empty out queue |5. exit\n");
		printf("queue: ");
		Output(P);
		if (test)
			printf("\nx: %d", x);
		else
			printf("\nx: none");
		printf("  \(recent value\)\n");
		scanf_s("%d", &stick);
		switch (stick)
		{
		case 1: Input(x); test = enqueue(P, x); break;
		case 2: test = peek(P, x); break;
		case 3: test = dequeue(P, x); break;
		case 4: EmptyingQueue(P); test = false; break;
		}
		if (stick == 5)
			break;
	}
}