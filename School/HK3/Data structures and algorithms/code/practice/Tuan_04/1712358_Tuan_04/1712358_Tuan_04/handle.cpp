#include "handle.h"

NODE* InsertNode(NODE*& root, int x)
{
	if (root)
	{
		if (x == root->value)
			return root;
		else if (x > root->value)
			return InsertNode(root->pRight, x);
		else
			return InsertNode(root->pLeft, x);
	}
	else
	{
		NODE* p = new NODE;
		p->value = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		root = p;
		return root;
	}
}
int CountEvenNodes(NODE* root)
{
	if (root)
	{
		if (root->value % 2 == 0)
			return 1 + CountEvenNodes(root->pLeft) + CountEvenNodes(root->pRight);
		else
			return CountEvenNodes(root->pLeft) + CountEvenNodes(root->pRight);
	}
	else
		return 0;
}
NODE* FindNode(NODE* root, int x)
{
	if (root)
	{
		if (root->value == x)
			return root;
		else if (x > root->value)
		{
			NODE* p = FindNode(root->pRight, x);
			return p ? p : root;
		}
		else
			return FindNode(root->pLeft, x);
	}
	else
		return NULL;
}
int CountNodeLevel_h(NODE* root, int h)
{
	if (root)
	{
		if (h == 1)
				return 1;
		else if (h > 1)
			return CountNodeLevel_h(root->pLeft, h - 1) + CountNodeLevel_h(root->pRight, h - 1);
	}
	else
		return 0;
}
int TraversalByLevel(NODE* root, int h)
{
	if (root)
	{
		if (h == 1)
		{
			cout << root->value << " ";
			return 1;
		}
		else if (h > 1)
			return TraversalByLevel(root->pLeft, h - 1) + TraversalByLevel(root->pRight, h - 1);
	}
	else
		return 0;
}
void TraversalByLevel(NODE* root)
{
	for (int i = 1;; i++)
	{
		cout << endl << "Level " << i << ": ";
		if (TraversalByLevel(root, i) == 0)
		{
			cout << "NULL" << endl;
			break;
		}
		

	}
}
int Sum(NODE* root)
{
	return root ? root->value + Sum(root->pLeft) + Sum(root->pRight) : 0;
}
int BigSum(NODE* root, int x)
{
	if (root)
	{
		if (root->value == x)
			return root->value + Sum(root->pRight);
		else if (root->value > x)
		{
			return root->value + Sum(root->pRight) + BigSum(root->pLeft, x);
		}
		else
		{
			return BigSum(root->pRight, x);
		}
	}
	else
		return 0;
}