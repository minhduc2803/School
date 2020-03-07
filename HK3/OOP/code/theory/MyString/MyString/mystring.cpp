#include "mystring.h"

MyString::MyString()//:n{0}, c{nullptr}
{
	n = 0;
	c = new char;
}
MyString::~MyString()
{
	delete[] c;
}
int MyString::lenght()
{
	return n;
}
char* MyString::subString(int begin, int amount)
{
	char *a = new char[amount+1];
	int i;
	for (i = 0; i < amount && c[i]!=NULL; i++)
	{
		a[i] = c[i + begin];
	}
	a[i] = NULL;
	return a;
}
char MyString::operator [](int j)
{
	return c[j];
}
char* MyString::operator + (MyString& S)
{
	char *a = new char[n + S.lenght()+1];
	int i = 0;
	for (i; c[i] != NULL; i++)
	{
		a[i] = c[i];
	}
	int j = 0;
	for (i; S[j] != NULL; i++, j++)
	{
		a[i] = S[j];
	}
	a[i] = NULL;
	return a;
}
MyString MyString::operator = (char* S)
{
	c = S;
	return *this;
}
bool MyString::insert(int p, char* S)
{
	char *c = new char;
	MyString a = c;//subString(0, p + 1);
}
bool erase(int begin, int amount)
{

}
bool replace(int begin, int amount, char* S)
{

}
bool find(int begin, char* S)
{

}