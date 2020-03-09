#include "HANDLING.h"
#include "LINKEDLIST.h"
//-----Initializing an empty stack
void InitStack(STACK* P)
{
	P->L = (LIST*)malloc(sizeof(LIST));
	InitList(P->L);
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
	//a stack which is created by linked list is never full 
	return false;
}
//-----adding an element to the stack, if it is succeed -> return true, else -> return false
bool push(STACK* P, key x)
{
	if (!IfFullStack(P))
	{
		AddHead(P->L, x);
		P->st = P->L->head;
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
		x = P->st->val;
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
		x = P->st->val;
		DeleteHead(P->L);
		P->st = P->L->head;
		return true;
	}
	else
		return false;
}
//-----emptying the stack
void EmptyingStack(STACK* P)
{
	P->st = NULL;
	DeleteList(P->L);
}