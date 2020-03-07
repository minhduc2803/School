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
bool HaiDanhSachGiongNhauKhong(linkedlist L, linkedlist L1)
{
	node *p = L.head;
	node *p1 = L1.head;

	//khi p hoac p1 bang NULL thi dung vong lap
	while (p && p1)
	{
		if (p->key != p1->key)
			return false;
		p = p->next;
		p1 = p1->next;
	}

	//bay gio p hoac p1 van co the khac NULL-> 2 danh sach co the van khac nhau
	if (p || p1)
		return false;
	else
		true;
}