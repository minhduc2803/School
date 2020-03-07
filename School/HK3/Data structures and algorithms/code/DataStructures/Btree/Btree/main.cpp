#include <iostream>
#include <queue>

using namespace std;

#define MAX 4

struct node {
	int key[MAX];
	int N;
	node *child[MAX + 1];
	node()
	{
		N = 0;
		for (int i = 0; i < N; i++)
		{
			child[i] = NULL;
		}
	}
};

void Traversal(node *root)
{
	queue<node*> q;
	if (root)
	{
		q.push(root);
		node *p;
		while (q.empty())
		{
			p = q.front();
			q.pop();
			q.push(p->child[0]);
			for (int i = 0; i < p->N; i++)
			{
				cout << p->key[i] << " ";
				if (p->child[i])
					q.push(p->child[i]);
			}
		}
	}
}

void Insert(node* &root, int k)
{
	if (root)
	{

	}
	else
	{
		node *p = new node;
		p->key[0] = k;
		p->N++;
		root = p;
	}
}

node* Insert(node* &root, int &k)
{
	if (root)
	{
		for (int i = 0; i < root->N; i++)
		{

		}
	}
	else
		return NULL;
}
int main()
{
	
	return 0;
}