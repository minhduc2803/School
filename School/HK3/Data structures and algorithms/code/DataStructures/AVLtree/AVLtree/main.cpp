#include <iostream>
#include <queue>

using namespace std;

struct node {
	int key;
	int height;
	node* left;
	node* right;
	node()
	{
		left = NULL;
		right = NULL;
		height = 1;
	}
};

enum state {RR,RL,LL,LR,non};

void R_rotate(node* &root);
void RL_rotate(node* &root);
void L_rotate(node* &root);
void LR_rotate(node* &root);
state calculate_height(node* &root);
void insert(node* &root, int k);
void traversal(node* root);

int main()
{
	node *root = NULL;
	insert(root, 0);
	traversal(root);
	insert(root, 1);
	traversal(root);
	insert(root, 2);
	traversal(root);
	insert(root, 5);
	traversal(root);
	insert(root, 6);
	traversal(root);
	insert(root, 4);
	traversal(root);
	insert(root, 7);
	traversal(root);
	insert(root, 9);
	traversal(root);
	return 0;
}
void R_rotate(node* &root)
{
	node *temp = root;
	root = temp->left;
	temp->left = root->right;
	root->right = temp;
}
void RL_rotate(node* &root)
{
	L_rotate(root->left);
	R_rotate(root);
}
void L_rotate(node* &root)
{
	node *temp = root;
	root = temp->right;
	temp->right = root->left;
	root->left = temp;
}
void LR_rotate(node* &root)
{
	R_rotate(root->right);
	L_rotate(root);
}
state calculate_height(node* &root)
{
	state E = non;
	if (root)
	{
		int left_height = 0, right_height = 0;
		if (root->left)
			left_height = root->left->height;

		if (root->right)
			right_height = root->right->height;
		root->height = max(left_height, right_height) + 1;

		int diff = left_height - right_height;
		if (diff < -1)
		{
			E = LL;
			//if E = LR
			int child_left_height = 0, child_right_height = 0;
			if (root->right->left)
				child_left_height = root->right->left->height;
			if (root->right->right)
				child_right_height = root->right->right->height;
			if (child_left_height > child_right_height)
				E = LR;
		}
		else if (diff > 1)
		{
			E = RR;
			//if E = RL
			int child_left_height = 0, child_right_height = 0;
			if (root->left->left)
				child_left_height = root->left->left->height;
			if (root->left->right)
				child_right_height = root->left->right->height;
			if (child_left_height < child_right_height)
				E = RL;
		}
	}
	return E;
}
void insert(node* &root, int k)
{
	if (root)
	{
		if (k == root->key)
			return;
		else if (k < root->key)
			insert(root->left, k);
		else
			insert(root->right, k);

		//calculate the height
		
		state E = calculate_height(root);
		switch (E)
		{
		case non: break;
		case LL:
			L_rotate(root);
			root->left->height -= 2;
			break;
		case LR:
			LR_rotate(root);
			root->right->height--;
			root->left->height -= 2;
			root->height++;
			break;
		case RR:
			R_rotate(root);
			root->right->height -= 2;
			break;
		case RL:
			RL_rotate(root);
			root->left->height--;
			root->right->height -= 2;
			root->height++;
			break;
		}
	}
	else
	{
		node *p = new node;
		p->key = k;
		root = p;
	}
}
void traversal(node* root)
{
	if (root)
	{
		queue<node*> q;
		q.push(root);
		node* p;
		while (!q.empty())
		{
			p = q.front();
			q.pop();

			cout << p->key << " ";
			if (p->left)
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		}
	}
	cout << endl;
}