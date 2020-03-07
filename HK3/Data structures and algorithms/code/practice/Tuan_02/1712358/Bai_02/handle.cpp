#include "handle.h"

void input(int &N)
{
	cout << "Enter the number of elements of the list, N: ";
	while (1)
	{
		cin >> N;
		if (N <= 0)
			cout << "N must be greater than 0, please try again" << endl;
		else
			break;
	}
}
void input(node*& head, int N)
{
	head = new node;
	node *p = head;
	node *p1 = p;
	cout << "Enter " << N << " elements" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "element " << i << ": ";
		int x;
		cin >> x;
		p->data = x;
		p->next = new node;
		p1 = p;
		p = p->next;
	}
	p1->next = NULL;
}
void output(node* head)
{
	node *p = head;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void sorting(node*& head, int N, node* nxt)
{
	if (N > 1)
	{
		node* prehead2 = head;
		for (int i = 1; i < N / 2; i++)
			prehead2 = prehead2->next;
		sorting(head, N / 2, prehead2->next);
		prehead2 = head;
		for (int i = 1; i < N / 2; i++)
			prehead2 = prehead2->next;
		sorting(prehead2->next, N - N / 2, nxt);
		merge(head, prehead2, nxt);
	}
}
void merge(node*& head1, node* prehead2, node* nxt)
{
	node * p1 = head1;
	node * p2 = prehead2->next;
	if (p1 -> data < p2->data)
	{
		head1 = p1;
		p1 = p1->next;
	}
	else
	{
		head1 = p2;
		p2 = p2->next;
	}
	node * p = head1;
	while (1)
	{
		if (p1 == prehead2->next)
		{
			p->next = p2;
			break;
		}
		if (p2 == nxt)
		{
			p->next = p1;
			prehead2->next = nxt;
			break;
		}
		if (p1->data < p2->data)
		{
			p->next = p1;
			p = p->next;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			p = p->next;
			p2 = p2->next;
		}
	}
}
