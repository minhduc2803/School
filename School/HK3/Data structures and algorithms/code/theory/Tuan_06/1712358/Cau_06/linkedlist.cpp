#include "linkedlist.h"

void initialize(linkedlist &L)
{
	L.head = NULL;
	L.tail = NULL;
}
void addtail(linkedlist &L, int value)
{
	node *p = new node;
	p->key = value;
	p->next = NULL;
	if (L.tail == NULL)
	{
		L.head = p;
		L.tail = p;
	}
	else
	{
		L.tail->next = p;
		L.tail = p;
	}
}
void output(linkedlist L)
{
	while (L.head)
	{
		cout << L.head->key << " ";
		L.head = L.head->next;
	}
	cout << endl;
}
void TachThanhHaiDanhSach(linkedlist L, linkedlist &L1, linkedlist &L2)
{
	while (L.head)
	{
		if (L.head->key % 2 == 1)
			addtail(L1, L.head->key);
		else
			addtail(L2, L.head->key);
		L.head = L.head->next;
	}
}