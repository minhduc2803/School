#ifndef _HANDLING_H_
#define _HANDLING_H_
#include "INFO.h"

//-----Initializing a empty queue
void InitQueue(QUEUE* P);
//-----if the queue is empty -> return true, else -> return false
bool IfEmptyQueue(QUEUE* P);
//-----if the queue is full -> return true, else -> return false
bool IfFullQueue(QUEUE* P);
//-----adding an element to the queue, if it is succeed -> return true, else -> return false
bool enqueue(QUEUE* P, key x);
//-----assigning the value of the head element of the queue to x, if it is succeed -> return true, else -> return false
bool peek(QUEUE* P, key& x);
//-----taking an element from the queue and assigning it to x, if it is succeed -> return true, else -> return false
bool dequeue(QUEUE* P, key& x);
//-----emptying the queue
void EmptyingQueue(QUEUE* P);
#endif

