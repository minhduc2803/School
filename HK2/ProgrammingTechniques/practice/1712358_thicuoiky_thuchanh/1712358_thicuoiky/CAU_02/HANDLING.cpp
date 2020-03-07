#include "HANDLING.h"

//khoi tao anh sach lien ket
void Initialize(LIST* L)
{
	L->head = NULL;
	L->tail = NULL;
}
//neu danh sach rong -> return true, else -> return false
bool TestEmptyList(LIST* L)
{
	if (L->head == NULL)
		return true;
	else
		return false;
}
//tra ve tong cua danh sach
int SumOfList(LIST* L)
{
	int sum = 0;
	for (nope* p = L->head; p != NULL; p = p->next)
	{
		sum += p->data;
	}
	return sum;
}
//them 1 phan tu vao duoi danh sach
void AddTail(LIST* L, int x)
{
	nope* p = (nope*)malloc(sizeof(nope));
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

bool TestPrime(int x)
{
	if (x < 2)
		return false;

	else if (x >= 2 && x <= 3)
		return true;
	else
	{
		float sr = sqrt(x);
		for (int k = 2; k <= sr; k++)
		{
			if (x%k == 0)
				return false;
		}
		return true;
	}
}
//tach cac so nguyen to vao l1, cac so con lai vao l2
void TachDanhSach(LIST* L, LIST* l1, LIST* l2)
{
	nope* p = (nope*)malloc(sizeof(nope));
	p = L->head;
	while (p)
	{
		if (TestPrime(p->data))
			AddTail(l1, p->data);
		else
			AddTail(l2, p->data);
		p = p->next;
	}
}
