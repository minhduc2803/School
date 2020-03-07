#ifndef _HANDLE_H_
#define _HANDLE_H_

#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

void input(int &N);
void input(node*& head, int N);
void output(node* head);
void sorting(node*& head, int N, node* nxt);
void merge(node*& head1, node* prehead2, node* nxt);

#endif