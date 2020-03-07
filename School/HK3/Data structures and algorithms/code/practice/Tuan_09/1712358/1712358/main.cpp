#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

#define LEVEL 3

struct BTreeNode {
	int *keys;
	int t;
	BTreeNode **Child;
	int n;
	bool leaf;
	BTreeNode(int level) {
		t = level;
		keys = new int[2 * t];
		Child = new BTreeNode*[2 * t + 1];
		for (int i = 0; i < 2 * t + 1; i++)
			Child[i] = NULL;
		n = 0;
		leaf = true;
	}
};

void BTree_Traverse(BTreeNode* root);
BTreeNode* BTree_Search(BTreeNode* root, int k, int &m1, int &m2);
void findleft(BTreeNode *head, int &m1);
void findright(BTreeNode *head, int &m2);
void BTree_Insert(BTreeNode* &root, int k);
bool BTree_Insert(BTreeNode* &root, int &k, BTreeNode* &left, BTreeNode* &right);
void split(BTreeNode* &root, int &k, BTreeNode* &left, BTreeNode* &right);
void subQuickSort(int A[], int index[], int left, int right);
int SI(int m1, int m2);
int main()
{
	ifstream data("data.txt");
	int N;
	int Si = 0;
	data >> N;
	int *a = new int[N];
	int *index = new int[N];
	for (int i = 0; i<N; i++)
	{
		data >> a[i];
		index[i] = i;
	}
	subQuickSort(a, index, 0, N - 1);

	ofstream out("out.txt");
	for (int i = 1; i < N; i++)
	{
		cout << a[index[i]] << " ";
		if (a[index[i - 1]] > a[index[i]])
			cout << "false" << endl;
	}
	data.close();
	out.close();
	BTreeNode* head = NULL;
	int c1, c2;
	for (int i = 0; i<N; i++)
	{
		int m1 = -1, m2 = -1;
		BTree_Insert(head, index[i]);

		cout << endl;
		BTree_Traverse(head);
		cout << endl;

		BTree_Search(head, index[i], m1, m2);
		int temp;
		if (m1 != -1)
		{
			temp = SI(a[m1], a[index[i]]);
			if (Si < temp)
			{
				Si = temp;
				c1 = a[m1];
				c2 = a[index[i]];
				//cout << c1 << " " << c2 << " " << index[i]<< " "<<i << " " << Si << endl;
			}
		}
		if (m2 != -1)
		{
			temp = SI(a[index[i]], a[m2]);
			if (Si < temp)
			{
				Si = temp;
				c1 = a[m2];
				c2 = a[index[i]];
				//cout << c1 << " " << c2 << " " << index[i] << " " << i << " " << Si << endl;
			}
		}
	}
	cout << endl;
	BTree_Traverse(head);
	cout << endl;
	cout << c1 << " " << c2 << " " << Si;
	return 0;
}
int SI(int m1, int m2)
{
	return ((m1&m2) ^ (m1 | m2))&(m1^m2);
}
void BTree_Traverse(BTreeNode* root)
{
	queue<BTreeNode*> q;
	if (root)
		q.push(root);
	BTreeNode *p;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (!(p->leaf))
		{
			for (int i = 0; i <= p->n; i++)
			{
				if(p->Child[i])
					q.push(p->Child[i]);

			}
		}
		for (int i = 0; i < p->n; i++)
			cout << " " << p->keys[i];
		cout << ";";
	}
}
BTreeNode* BTree_Search(BTreeNode* root, int k, int &m1, int &m2)
{
	if (root)
	{
		int position = root->n;
		for (int i = 0; i < root->n; i++)
		{
			if (k == root->keys[i])
			{
				if (i>0)
					m1 = root->keys[i - 1];
				if (i<root->n - 1)
					m2 = root->keys[i + 1];
				findleft(root->Child[i], m1);
				findright(root->Child[i + 1], m2);
				return root;
			}
			else if (k < root->keys[i])
			{
				m2 = root->keys[i];
				position = i;
				break;
			}
			else
			{
				m1 = root->keys[i];
			}
		}
		return BTree_Search(root->Child[position], k, m1, m2);
	}
	else
		return NULL;
}
void findleft(BTreeNode *head, int &m1)
{
	if (head)
	{
		if (head->leaf)
		{
			m1 = head->keys[head->n - 1];
			return;
		}
		else
		{
			findleft(head->Child[head->n], m1);
		}

	}
}
void findright(BTreeNode *head, int &m2)
{
	if (head)
	{
		if (head->leaf)
		{
			m2 = head->keys[0];
			return;
		}
		else
		{
			findleft(head->Child[0], m2);
		}

	}
}
void BTree_Insert(BTreeNode* &root, int k)
{
	if (root)
	{
		BTreeNode *p1, *p2;
		if (BTree_Insert(root, k, p1, p2))
		{
			BTreeNode* p = new BTreeNode(LEVEL);
			p->keys[0] = k;
			p->Child[0] = p1;
			p->Child[1] = p2;
			p->n = 1;
			p->leaf = false;
			root = p;
		}
	}
	else
	{
		BTreeNode* p = new BTreeNode(LEVEL);
		p->keys[0] = k;
		p->n = 1;
		root = p;
	}
}
bool BTree_Insert(BTreeNode* &root, int &k, BTreeNode* &left, BTreeNode* &right)
{
	if (!root)
		return false;
	int position = root->n;
	for (int i = 0; i < root->n; i++)
	{
		if (k == root->keys[i])
			return false;
		else if (k < root->keys[i])
		{
			position = i;
			break;
		}
	}
	BTreeNode *p1, *p2;
	p1 = NULL; p2 = NULL;
	if (root->leaf || BTree_Insert(root->Child[position], k, p1, p2))
	{
		for (int i = root->n; i > position; i--)
		{
			root->keys[i] = root->keys[i - 1];
			root->Child[i + 1] = root->Child[i];
		}
		root->Child[position] = p1;
		root->Child[position + 1] = p2;
		root->keys[position] = k;
		root->n++;
		if (root->n == 2 * root->t - 1)
		{
			split(root, k, left, right);

			return true;
		}
	}
	return false;
}
void split(BTreeNode* &root, int &k, BTreeNode* &left, BTreeNode* &right)
{
	BTreeNode* p1 = new BTreeNode(LEVEL);
	BTreeNode* p2 = new BTreeNode(LEVEL);
	for (int i = 0; i < p1->t - 1; i++)
	{
		p1->keys[i] = root->keys[i];
		p1->Child[i] = root->Child[i];
	}
	p1->Child[p1->t - 1] = root->Child[root->t - 1];
	p1->n = p1->t - 1;
	for (int i = p2->t - 1; i < 2 * p2->t - 1; i++)
	{
		p2->keys[i - p2->t] = root->keys[i];
		p2->Child[i - p2->t] = root->Child[i + 1];
	}
	p2->Child[2 * p2->t - 1] = root->Child[2 * root->t - 1];
	p2->n = p2->t - 1;

	p1->leaf = root->leaf;
	p2->leaf = root->leaf;
	left = p1;
	right = p2;
	k = root->keys[root->t - 1];
	//delete root;
}
void subQuickSort(int A[], int index[], int left, int right)
{
	if (left >= right) return;
	int i = left, j = right;
	int key = (A[index[left]] + A[index[right]]) / 2;
	while (1)
	{
		while (i < j && A[index[i]] <= key)
			i++;
		while (i < j && A[index[j]] > key)
			j--;
		if (i < j)
		{
			swap(index[i], index[j]);
			i++; j--;
		}
		if (i == j)
		{
			if (A[index[i]] > key)
				i--;
			else if (A[index[i]] < key)
				j++;
			else
			{
				i--; j++;
			}
			break;
		}
		if (i > j)
		{
			i--; j++;
			break;
		}
	}
	subQuickSort(A, index, left, i);
	subQuickSort(A, index, j, right);
}
