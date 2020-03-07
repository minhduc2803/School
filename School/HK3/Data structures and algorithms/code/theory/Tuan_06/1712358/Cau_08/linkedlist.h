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
void addtail(linkedlist &L, int value);
void output(linkedlist L);

bool HaiDanhSachGiongNhauKhong(linkedlist L, linkedlist L1);

#endif