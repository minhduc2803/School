#ifndef _HANDLING_H_
#define _HANDLING_H_
#include<stdio.h>
#include "INFO.h"

//1.
//-----initialize a empty list
void Initialize(LIST* L);

//2.
//-----test the list is empty or not
//-----if the list is empty -> return true, else -> return false
bool TestEmptyList(LIST* L);

//3.
//-----find the first element in the list which has a value as x
//-----return the order of the element in the list which is from number 0, if the function cannot find x -> return -1
int FindFirstX(LIST* L, int x);

//4.
//-----find the last element in the list which has a value as x
//-----return the order of the element in the list which is from number 0, if the function cannot find x -> return -1
int FindLastX(LIST* L, int x);

//5.
//-----find the element in the list which has a value as x 
//-----and (the sum of all elements which are after x) minus (the sum of all elements which are before x) equals x
//-----return the pointer which points to the element, if the function cannot find x -> return NULL
ELE* FindX(LIST* L);
//-----return sum of the list, this function is a supporter function of FindX
int SumOfList(LIST* L);

//6.
//-----find the element number k in the list
//-----return the pointer which points to the element, if the function cannot find the element number k -> return NULL
ELE* FindK(LIST* L, int k);

//7.
//-----add the element which has a value as x to the head of the list
void AddHead(LIST* L, int x);


//8.
//-----add the element which has a value as x to the tail of the list
void AddTail(LIST* L, int x);

//9.
//-----add the element which has a value as x after the element which has a value as y in the list
void Add_x_After_y_(LIST* L, int x, int y);

//10.
//-----if the list is sorted in ascending order, add the element x to the list so that the list is still sorted in ascending order
void AddSortedUp(LIST* L, int x);
//-----sort the list in ascending order
void SortedUp(LIST** L);
//-----if the list is sorted in ascending order -> return true, else -> return false
bool TestSortedUp(LIST* L);

//11.
//-----delete the head element in the list
void DeleteHead(LIST* L);

//12.
//-----delete the tail element in the list
void DeleteTail(LIST* L);

//13.
//-----find the first element which has a value as x in the list and then delete it
void DeleteFirstX(LIST* L, int x);

//14.
//-----Delete the list, that means making the list empty
void DeleteList(LIST* L);
#endif
