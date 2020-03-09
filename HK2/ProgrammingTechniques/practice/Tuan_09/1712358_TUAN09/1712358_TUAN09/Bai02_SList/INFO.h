
/*This file is for the stack by array*/

#ifndef _INFO_H_
#define _INFO_H_
#include <stdio.h>
#include <stdlib.h>

typedef int key;
typedef struct nope {
	key val;
	nope* next;
};

typedef struct queue {
	int N;
	nope* in;
	nope* out;
}QUEUE;
#endif




