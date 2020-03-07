#include "linkedlist.h"

void initialize(linkedlist &L)
{
	L.head = NULL;
	L.tail = NULL;
}
void addhead(linkedlist &L, int value)
{
	node *p = new node;
	p->key = value;
	p->next = L.head;
	L.head = p;
	if (L.tail == NULL)
		L.tail = p;
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

int DemSoPhanTu(linkedlist L)
{
	int i;
	for (i = 0; L.head != NULL; i++, L.head = L.head->next);

	return i;
}
node* TimNodeThuI(linkedlist L, int i)
{
	int j;
	for (j = 1; L.head != NULL && j < i; j++, L.head = L.head->next);

	return L.head;
}
void ThemNodeXSauNodeK(linkedlist &L, int x, int k)
{
	for (node* p = L.head; p != NULL; p = p->next)
	{
		if (p->key == k)
		{
			node *p1 = new node;
			p1->key = x;
			p1->next = p->next;
			p->next = p1;
			break;
		}
	}
}
void XoaNodeTruocNodeK(linkedlist &L, int k)
{
	node *p1 = NULL;
	node *p2 = NULL;
	for (node* p = L.head; p != NULL; p2 = p1, p1 = p, p = p->next)
	{
		if (p->key == k)
		{
			if (p1)
			{
				if (p2)
					p2->next = p;
				else
					L.head = p;
				delete p1;
			}
			break;
		}
	}
}
linkedlist DaoNguocDanhSach(linkedlist L)
{
	linkedlist L1;
	initialize(L1);
	while (L.head)
	{
		addhead(L1, L.head->key);
		L.head = L.head->next;
	}
	return L1;
}