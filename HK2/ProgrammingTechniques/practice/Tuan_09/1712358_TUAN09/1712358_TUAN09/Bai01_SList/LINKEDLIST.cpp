#include "LINKEDLIST.h"

//-----initialize a empty list
void InitList(LIST* L)
{
	L->head = NULL;
	L->tail = NULL;
}

//-----if the list is empty -> return true, else -> return false
bool TestEmptyList(LIST* L)
{
	if (L->head == NULL)
		return true;
	else
		return false;
}

//-----add the element which has a value as x to the head of the list
void AddHead(LIST* L, int x)
{
	nope* p = (nope*)malloc(sizeof(nope));
	p->val = x;
	if (TestEmptyList(L))
	{
		L->head = p;
		L->tail = p;
		L->tail->next = NULL;
	}
	else
	{
		p->next = L->head;
		L->head = p;
	}
}

//-----delete the head element in the list
void DeleteHead(LIST* L)
{
	if (!TestEmptyList(L))
		L->head = L->head->next;
}

//-----Delete the list, that means making the list empty
void DeleteList(LIST* L)
{
	L->head = NULL;
}