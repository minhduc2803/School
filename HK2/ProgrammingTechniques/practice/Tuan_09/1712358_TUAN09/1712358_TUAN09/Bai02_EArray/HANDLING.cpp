#include "HANDLING.h"

//-----Initializing a empty queue
void InitQueue(QUEUE* P)
{
	P->N = 20;
	P->array = (key*)malloc(sizeof(key) * P->N);
	P->use = 0;
	P->in = P->array - 1;
	P->out = P->in + 1;
}
//-----if the queue is empty -> return true, else -> return false
bool IfEmptyQueue(QUEUE* P)
{
	if (P->use == 0)
	{
		return true;
	}
	else
		return false;
}
//-----if the queue is full -> return true, else -> return false
bool IfFullQueue(QUEUE* P)
{
	if (P->use == P->N)
		return true;
	else
		return false;
}
//-----adding an element to the queue, if it is succeed -> return true, else -> return false
bool enqueue(QUEUE* P, key x)
{
	if (!IfFullQueue(P))
	{
		if (P->in != P->array + P->N - 1)
			P->in++;
		else
			P->in = P->array;
		*(P->in) = x;
		P->use++;
		return true;
	}
	else
		return false;
}
//-----assigning the value of the head element of the queue to x, if it is succeed -> return true, else -> return false
bool peek(QUEUE* P, key& x)
{
	if (!IfEmptyQueue(P))
	{
		x = *(P->out);
		return true;
	}
	else
		return false;
}
//-----taking an element from the queue and assigning it to x, if it is succeed -> return true, else -> return false
bool dequeue(QUEUE* P, key& x)
{
	if (!IfEmptyQueue(P))
	{
		x = *(P->out);
		if (P->out != P->array + P->N - 1)
			P->out++;
		else
			P->out = P->array;
		P->use--;
		return true;
	}
	else
		return false;
}
//-----emptying the queue
void EmptyingQueue(QUEUE* P)
{
	P->in = P->array - 1;
	P->out = P->in + 1;
	P->use = 0;
}