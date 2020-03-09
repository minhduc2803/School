
/*This file is for the stack by linkedlist*/

#ifndef _INFO_H_
#define _INFO_H_
#include <stdio.h>
#include <stdlib.h>
typedef int key;
typedef struct nope {
	key val;
	nope* next;
};

typedef struct list {
	nope* head;
	nope* tail;
}LIST;

typedef struct stack {
	int N;
	LIST* L;
	nope* st;
}STACK;
#endif

