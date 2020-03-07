#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <string>

using namespace std;

class MyString {

	char *c;
	int n;
public:
	MyString();
	~MyString();
	int lenght();
	char* subString(int, int);
	char* operator + (MyString&);
	bool insert(int, char*);
	bool erase(int, int);
	bool replace(int, int, char*);
	bool find(int, char*);
	char operator [](int j);
	MyString operator = (char*);
	istream& operator >> (istream& goin)
	{

	}
};

#endif
