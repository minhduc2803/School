#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "display.h"

using namespace std;

struct SC
{
	char* c;
	int size;
	SC(string s) : c(new char[s.length() + 1]), size(s.length() + 1)
	{
		strcpy_s(c, s.length() + 1, s.c_str());
	}
	~SC() { delete[] c; }
};

class SaveAndLoad
{
	int** a;
	int sz;
public:
	SaveAndLoad(int size = 15) : a(new int*[size]), sz(size)
	{
		for (int i = 0; i < sz; ++i)
			a[i] = new int[sz];
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				a[i][j] = j;
	}
	~SaveAndLoad()
	{
		for (int i = 0; i < sz; ++i)
			delete[] a[i];
	}

	void check(int x, int y, int val);
	int value(int x, int y);

	bool load(int n, bool type);
	bool save(const char* text, bool type);
	bool read(bool type);
};


#endif
