#include "HANDLING.h"


//1.
//-----initialize a empty list
void Initialize(LIST* L)
{
	L->head = NULL;
	L->tail = NULL;
}

//2.
//-----test the list is empty or not
//-----if the list is empty -> return true, else -> return false
bool TestEmptyList(LIST* L)
{
	if (L->head == NULL)
		return true;
	else
		return false;
}

//3.
//-----find the first element in the list which has a value as x
//-----return the order of the element in the list which is from number 0, if the function cannot find x -> return -1
int FindFirstX(LIST* L, int x)
{
	ELE* p;
	int i;
	for (p = L->head, i = 0; p != NULL; p = p->next, i++)
	{
		if (p->data == x)
			return i;
	}
	return -1;
}

//4.
//-----find the last element in the list which has a value as x
//-----return the order of the element in the list which is from number 0, if the function cannot find x -> return -1
int FindLastX(LIST* L, int x)
{
	ELE* p;
	int i1 = -1;
	int i;
	for (p = L->head, i = 0; p != NULL; p = p->next, i++)
	{
		if (p->data == x)
			i1 = i;
	}
	return i1;
}

//5.
//-----find the element in the list which has a value as x 
//-----and (the sum of all elements which are after x) minus (the sum of all elements which are before x) equals x
//-----return the pointer which points to the element, if the function cannot find x -> return NULL
ELE* FindX(LIST* L)
{
	if (!TestEmptyList(L) && L->head->next != NULL)
	{
		ELE* p = (L->head)->next;
		int bef = (L->head)->data;
		int aft = SumOfList(L) - (L->head)->data;
		for (p; p->next != NULL; p = p->next) //because p can not be head or tail of the list so that why p began from head->next to the position before tail
		{
			aft -= p->data;
			if (p->data == bef && p->data == aft)
				return p;
			bef += p->data;
		}
	}
	return NULL;
}
//-----return sum of the list, this function is a supporter function of FindX
int SumOfList(LIST* L)
{
	int sum = 0;
	for (ELE* p = L->head; p != NULL; p = p->next)
	{
		sum += p->data;
	}
	return sum;
}

//6.
//-----find the element number k in the list
//-----return the pointer which points to the element, if the function cannot find the element number k -> return NULL
ELE* FindK(LIST* L, int k)
{
	ELE* p;
	int i;
	for (p = L->head, i = 0; p != NULL && i != k; p = p->next, i++);
	if (i == k)
		return p;
	else
		return NULL;
}

//7.
//-----add the element which has a value as x to the head of the list
void AddHead(LIST* L, int x)
{
	ELE* p = (ELE*)malloc(sizeof(ELE));
	p->data = x;
	if(TestEmptyList(L))
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

//8.
//-----add the element which has a value as x to the tail of the list
void AddTail(LIST* L, int x)
{
	ELE* p = (ELE*)malloc(sizeof(ELE));
	p->data = x;
	if (TestEmptyList(L))
	{
		L->head = p;
		L->head->next = NULL;
		L->tail = L->head;
	}
	else
	{
		L->tail->next = p;
		L->tail = L->tail->next;
		L->tail->next = NULL;
	}
}

//9.
//-----add the element which has a value as x after the element which has a value as y in the list
void Add_x_After_y_(LIST* L, int x, int y)
{
	for (ELE* p = L->head; p != NULL; p = p->next)
	{
		if (p->data == y)
		{
			ELE* p1 = (ELE*)malloc(sizeof(ELE));
			p1->data = x;
			p1->next = p->next;
			p->next = p1;
			p = p->next;
		}
	}
}

//10.
//-----if the list is sorted in ascending order, add the element x to the list so that the list is still sorted in ascending order
void AddSortedUp(LIST* L, int x)
{
	ELE* p1 = (ELE*)malloc(sizeof(ELE));
	p1->data = x;
	p1->next = NULL;
	if (!TestEmptyList(L))
	{
		if (L->head->data >= x)
		{
			p1->next = L->head;
			L->head = p1;
		}
		else
		{
			for (ELE* p = L->head; p->next != NULL; p = p->next)
			{
				if (p->next->data >= x)
				{
					p1->next = p->next;
					p->next = p1;
					break;
				}
			}
			if (p1->next == NULL)
			{
				L->tail->next = p1;
				L->tail = L->tail->next;
			}
		}
	}
	else
	{
		L->head = p1;
		L->tail = p1;
	}
}
//-----sort the list in ascending order
void SortedUp(LIST** L)
{
	LIST* T = (LIST*)malloc(sizeof(LIST));
	Initialize(T);
	for (ELE* p = (*L)->head; p != NULL; p = p->next)
	{
		AddSortedUp(T, p->data);
	}
	*L = T;
}
//-----if the list is sorted in ascending order -> return true, else -> return false
bool TestSortedUp(LIST* L)
{
	if (!TestEmptyList(L))
	{
		int before = L->head->data;
		for (ELE* p = L->head->next; p != NULL; p = p->next)
		{
			if (p->data < before)
				return false;
			before = p->data;
		}
	}
	return true;
}

//11.
//-----delete the head element in the list
void DeleteHead(LIST* L)
{
	if (!TestEmptyList(L))
		L->head = L->head->next;
}

//12.
//-----delete the tail element in the list
void DeleteTail(LIST* L)
{
	if (!TestEmptyList(L))
	{
		ELE* p1 = NULL;
		ELE* p = L->head;
		for (p; p->next != NULL; p = p->next)
			p1 = p;
		L->tail = p1;
		if (L->tail)
			L->tail->next = NULL;
		else
			L->head = NULL;
	}
}

//13.
//-----find the first element which has a value as x in the list and then delete it
void DeleteFirstX(LIST* L, int x)
{
	if (!TestEmptyList(L))
	{
		if (L->head->data == x)
			L->head = L->head->next;
		else
		{
			ELE* p;
			for (p = L->head; p->next != NULL; p = p->next)
			{
				if (p->next->data == x)
					p->next = p->next->next;
			}
		}
	}
}

//14.
//-----Delete the list, that means making the list empty
void DeleteList(LIST* L)
{
	L->head = NULL;
}