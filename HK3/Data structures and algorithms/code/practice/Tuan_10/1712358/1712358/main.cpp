#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 9

struct node {
	int val;
	struct node * next;
};

bool is_on_list(int *a, int n, int val)
{
	for (int i = 0; i < n; i++)
	{
		if (val == a[i])
			return true;
	}
	return false;
}
void BFS(vector<node*> A, int start = 0)
{
	int n = A.size();
	int *list = new int[n];
	for (int j = 0; j < n; j++)
		list[j] = -1;
	int top_of_list = 0;

	queue<node*> q;
	
	while (start != -1)
	{
		q.push(A[start]);
		list[top_of_list] = A[start]->val;
		top_of_list++;
		node *p;
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			cout << p->val << " ";
			p = p->next;
			while (p)
			{
				if (!is_on_list(list, n, p->val))
				{
					q.push(A[p->val]);
					list[top_of_list] = p->val;
					top_of_list++;
				}
				p = p->next;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (!is_on_list(list, n, A[i]->val))
			{
				start = i;
				break;
			}
			else
				start = -1;
		}

		cout << endl;
	} 
}
void tran(vector<node*> &A, int s[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		node *p = new node;
		p->val = i;
		p->next = NULL;
		node *p1 = p;
		for (int j = 0; j < MAX; j++)
		{
			if (s[i][j] == 1)
			{
				node *p2 = new node;
				p2->val = j;
				p2->next = NULL;
				p1->next = p2;

				p1 = p2;
			}
		}
		
		A.push_back(p);
	}
}
void out(vector<node*> A)
{
	for (int i = 0; i < A.size(); i++)
	{
		node *p = A[i];
		cout << "[" << p->val << "]" << " -> ";
		p = p->next;
		if (!p)
			cout << "NULL";
		while (p)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
}

int main()
{
	vector<node*> A;
	int n = MAX;
	int s[MAX][MAX] = { 0, 1, 0, 1, 0, 0, 0, 0, 1,
						1, 0, 0, 0, 0, 0, 0, 1, 0,
						0, 0, 0, 1, 0, 1, 0, 1, 0,
						1, 0, 1, 0, 1, 0, 0, 0, 0,
						0, 0, 0, 1, 0, 0, 0, 0, 1,
						0, 0, 1, 0, 0, 0, 1, 0, 0,
						0, 0, 0, 0, 0, 1, 0, 0, 0,
						0, 1, 1, 0, 0, 0, 0, 0, 0,
						1, 0, 0, 0, 1, 0, 0, 0, 0};
	
	tran(A, s);
	cout << "2. Given a graph as an adjacency list below" << endl;
	out(A);
	cout << "The order of elements following the BFS is (breadth first search)" << endl;
	BFS(A);
	cout << endl;
	system("pause");
	return 0;
}