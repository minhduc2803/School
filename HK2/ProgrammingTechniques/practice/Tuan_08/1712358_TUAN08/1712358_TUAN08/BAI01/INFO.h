#ifndef _INFO_H_
#define _INFO_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct ele {
	int data;
	ele* next;
}ELE;
typedef struct list {
	ELE* head;
	ELE* tail;
}LIST;
#endif
