#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "INFO.h"

//-----initialize a empty list
void InitList(LIST* L);

//-----if the list is empty -> return true, else -> return false
bool TestEmptyList(LIST* L);

//-----add the element which has a value as x to the head of the list
void AddHead(LIST* L, int x);

//-----delete the head element in the list
void DeleteHead(LIST* L);

//-----Delete the list, that means making the list empty
void DeleteList(LIST* L);

#endif



