#include "HANDLING.h"

//-----Initializing an empty stack
void InitStack(STACK* P)
{
	P->N = 20;
	P->array = (key*)malloc(sizeof(key)*(P->N));
	P->st = NULL;
}
//-----if the stack is empty -> return true, else -> return false
bool IfEmptyStack(STACK* P)
{
	if (P->st == NULL)
		return true;
	else
		return false;
}
//-----if the stack is full -> return true, else -> return false
bool IfFullStack(STACK* P)
{
	if ((P->st - P->array) == P->N - 1)
		return true;
	else
		return false;
}
//-----adding an element to the stack, if it is succeed -> return true, else -> return false
bool push(STACK* P, key x)
{
	if (!IfFullStack(P))
	{
		if (IfEmptyStack(P))
			P->st = P->array - 1;
		(P->st)++;
		*(P->st) = x;
		return true;
	}
	else
		return false;
}
//-----assigning the value of the head element of the stack to x, if it is succeed -> return true, else -> return false
bool peek(STACK* P, key& x)
{
	if (!IfEmptyStack(P))
	{
		x = *(P->st);
		return true;
	}
	else
		return false;
}
//-----taking an element from the stack and assigning it to x, if it is succeed -> return true, else -> return false
bool pop(STACK* P, key& x)
{
	if (!IfEmptyStack(P))
	{
		x = *(P->st);
		(P->st)--;
		if (P->st < P->array)
			P->st = NULL;
		return true;
	}
	else
		return false;
}
//-----emptying the stack
void EmptyingStack(STACK* P)
{
	P->st = NULL;
	P->N = 0;
}