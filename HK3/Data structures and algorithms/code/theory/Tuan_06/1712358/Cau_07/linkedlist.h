#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>

using namespace std;

struct node {
	int key;
	node* next;
};

struct linkedlist {
	node *head;
	node *tail;
};
void initialize(linkedlist &L);
void addhead(linkedlist &L, int value);
void addtail(linkedlist &L, int value);
void output(linkedlist L);

int DemSoPhanTu(linkedlist L);
node* TimNodeThuI(linkedlist L, int i);
void ThemNodeXSauNodeK(linkedlist &L, int x, int k);
void XoaNodeTruocNodeK(linkedlist &L, int k);
linkedlist DaoNguocDanhSach(linkedlist L);

#endif