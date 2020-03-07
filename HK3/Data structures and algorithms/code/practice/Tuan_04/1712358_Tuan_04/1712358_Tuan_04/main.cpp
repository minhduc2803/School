#include "handle.h"

int main()
{
	NODE* root = NULL;
	InsertNode(root, 70);
	InsertNode(root, 31);
	InsertNode(root, 93);
	InsertNode(root, 14);
	InsertNode(root, 73);
	InsertNode(root, 94);
	InsertNode(root, 23);
	
	TraversalByLevel(root);

	cout << endl << "2." << endl;
	cout << "a) The tree after inserting 35";
	InsertNode(root, 35);
	TraversalByLevel(root);

	cout << "b) The tree has " << CountEvenNodes(root) << " even node(s)" << endl;
	cout << "c) The maximum node with its value which is not bigger than 32 is ";
	NODE* p = FindNode(root, 32);
	if (p)
		cout << p->value << endl;
	else
		cout << "not exist" << endl;
	cout << endl << "3." << endl;
	cout << "a) The number of nodes in level 3 is " << CountNodeLevel_h(root, 3) << endl;
	cout << "b) The tree traversal by level";
	TraversalByLevel(root);
	cout << "c) The sum of nodes which are bigger than or equal to 33 is " << BigSum(root, 33) << endl;
	system("pause");
	return 0;
}