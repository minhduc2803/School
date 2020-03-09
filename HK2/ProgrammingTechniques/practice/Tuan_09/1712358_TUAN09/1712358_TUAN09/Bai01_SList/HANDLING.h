#ifndef _HANDLING_H_
#define _HANDLING_H_
#include "INFO.h"

//-----Initializing an empty stack
void InitStack(STACK* P);
//-----if the stack is empty -> return true, else -> return false
bool IfEmptyStack(STACK* P);
//-----if the stack is full -> return true, else -> return false
bool IfFullStack(STACK* P);
//-----adding an element to the stack, if it is succeed -> return true, else -> return false
bool push(STACK* P, key x);
//-----assigning the value of the head element of the stack to x, if it is succeed -> return true, else -> return false
bool peek(STACK* P, key& x);
//-----taking an element from the stack and assigning it to x, if it is succeed -> return true, else -> return false
bool pop(STACK* P, key& x);
//-----emptying the stack
void EmptyingStack(STACK* P);
#endif

