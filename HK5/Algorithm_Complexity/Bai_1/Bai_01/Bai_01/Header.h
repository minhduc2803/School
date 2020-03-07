#pragma once

#include <iostream>
#include <string>
#include <fstream> 
#include <ctime>
using namespace std;

class hash_table
{
public:
	virtual bool put(const string& word) = 0;
	virtual bool check(const string& word) = 0;
};

class chaining : public hash_table
{
	class node
	{
	public:
		string word;
		node* next = nullptr;
	};

	node** e;
	int sz;

public:
	chaining(int size) : e(new node* [size]), sz(size)
	{
		for (int i = 0; i < sz; ++i)
			e[i] = nullptr;
	}
	chaining(const chaining& other) : e(new node* [other.sz]), sz(other.sz)
	{
		for (int i = 0; i < sz; ++i)
			e[i] = other.e[i];
	}
	~chaining()
	{
		for (int i = 0; i < sz; ++i)
		{
			while (e[i])
			{
				node* tmp = e[i];
				e[i] = e[i]->next;
				delete tmp;
			}
		}
		delete[] e;
	}

	bool put(const string& word)
	{
		int x = word[0];
		int h = x % 26;
		
		if (!e[h])
		{
			e[h] = new node;
			e[h]->word = word;

			return true;
		}

		if (e[h]->word == word)
			return false;

		node* tmp = e[h];
		while (tmp->next)
		{
			if (tmp->next->word == word)
				return false;

			tmp = tmp->next;
		}	

		tmp->next = new node;
		tmp->next->word = word;

		return true;
	}
	bool check(const string& word)
	{
		int x = word[0];
		int h = x % 26;

		node* tmp = e[h];
		while (tmp)
		{
			if (tmp->word == word)
				return true;

			tmp = tmp->next;
		}

		return false;
	}
};

class linear : public hash_table
{
	string* w;
	int sz;

public:
	linear(int size) : w(new string[size]), sz(size) {}
	linear(const linear& other) : w(new string[other.sz]), sz(other.sz)
	{
		for (int i = 0; i < sz; ++i)
			w[i] = other.w[i];
	}
	~linear()
	{
		delete[] w;
	}

	bool put(const string& word)
	{
		int x = 0;
		for (int i = 0; i < word.length(); ++i)
			x += word[i];

		int h = x % sz;

		for (int i = 0; i < sz; ++i)
		{
			if (w[(h + i) % sz].empty())
			{
				w[(h + i) % sz] = word;
				return true;
			}
			else if (w[(h + i) % sz] == word)
				return false;
		}

		return false;
	}
	bool check(const string& word)
	{
		int x = 0;
		for (int i = 0; i < word.length(); ++i)
			x += word[i];

		int h = x % sz;

		for (int i = 0; i < sz; ++i)
		{
			if (w[(h + i) % sz] == word)
				return true;
		}

		return false;
	}
};

class quadratic : public hash_table
{
	string* w;
	int sz;

public:
	quadratic(int size) : w(new string[size]), sz(size) {}
	quadratic(const quadratic& other) : w(new string[other.sz]), sz(other.sz)
	{
		for (int i = 0; i < sz; ++i)
			w[i] = other.w[i];
	}
	~quadratic()
	{
		delete[] w;
	}

	bool put(const string& word)
	{
		int x = 0;
		for (int i = 0; i < word.length(); ++i)
			x += word[i];

		int h = x % sz;

		for (long long i = 0; i < sz; ++i)
		{
			long long t = (h + i * i) % sz;
			
			if (w[t].empty())
			{
				w[(h + i * i) % sz] = word;
				return true;
			}
			else if (w[(h + i * i) % sz] == word)
				return false;
		}

		return false;
	}
	bool check(const string& word)
	{
		int x = 0;
		for (int i = 0; i < word.length(); ++i)
			x += word[i];

		int h = x % sz;

		for (int i = 0; i < sz; ++i)
		{
			double t = (h + i * i) % sz;

			if (w[int(t)] == word)
				return true;
		}

		return false;
	}
};

class doublehash : public hash_table
{
	string* w;
	int sz;

public:
	doublehash(int size) : w(new string[size]), sz(size) {}
	doublehash(const doublehash& other) : w(new string[other.sz]), sz(other.sz)
	{
		for (int i = 0; i < sz; ++i)
			w[i] = other.w[i];
	}
	~doublehash()
	{
		delete[] w;
	}

	bool put(const string& word)
	{
		int x = 0;
		for (int i = 0; i < word.length(); ++i)
			x += word[i];

		int h = x % sz;

		for (int i = 0; i < sz; ++i)
		{
			if (w[(h + i * h) % sz].empty())
			{
				w[(h + i * h) % sz] = word;
				return true;
			}
			else if (w[(h + i * h) % sz] == word)
				return false;			
		}

		return false;
	}
	bool check(const string& word)
	{
		int x = 0;
		for (int i = 0; i < word.length(); ++i)
			x += word[i];

		int h = x % sz;

		for (int i = 0; i < sz; ++i)
		{
			if (w[(h + i * h) % sz] == word)
				return true;
		}

		return false;
	}
};