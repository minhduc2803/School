#ifndef _HANDLE_H_
#define _HANDLE_H_

#include <iostream>

using namespace std;

struct NODE {
	int value; 
	NODE* pLeft; 
	NODE* pRight; 
};

NODE* InsertNode(NODE*& root, int x);
int CountEvenNodes(NODE* root);
NODE* FindNode(NODE* root, int x);
int CountNodeLevel_h(NODE* root, int h);
void TraversalByLevel(NODE* root);
int TraversalByLevel(NODE* root, int h);
int Sum(NODE* root);
int BigSum(NODE* root, int x);

#endif
