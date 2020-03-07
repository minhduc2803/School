#include "handle.h"

void Init(NODE** &hash, int n)
{
	hash = new NODE*[n];
	for (int i = 0; i < n; i++)
	{
		hash[i] = NULL;
	}
}
void insert(NODE** hash, int n, int key, int data)
{
	int k = abs(key) % n;
	if (hash[k] != NULL)
	{
		NODE* p = hash[k];
		while (p->next != NULL)
			p = p->next;
		p->next = new NODE;
		p = p->next;
		p = new NODE;
		p->data = data;
		p->key = key;
		p->next = NULL;
	}
	else
	{
		hash[k] = new NODE;
		hash[k]->data = data;
		hash[k]->key = key;
		hash[k]->next = NULL;
	}
	
}
bool get(NODE** hash, int n, int key, int &result)
{
	int k = abs(key) % n;
	if (hash[k] != NULL)
	{
		NODE* p = hash[k];
		while (p != NULL)
		{
			if (p->key == key)
			{
				result = p->data;
				return true;
			}
			else
				p = p->next;
			return false;
		}
	}
	else
		return false;
}

