#ifndef _HANDLE_H_
#define _HANDLE_H_

#include <iostream>
#include <cmath>

using namespace std;

typedef struct node {
	int key;
	int data;
	node *next;
}NODE;

void Init(NODE** &hash, int n);
void insert(NODE** hash, int n, int key, int data);
bool get(NODE** hash, int n, int key, int &result);

#endif
