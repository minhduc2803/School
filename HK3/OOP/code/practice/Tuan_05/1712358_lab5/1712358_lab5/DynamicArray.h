#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include <iostream>
#include <sstream>

using namespace std;

class DynamicArray {
	int *a;
	int len, max;
public:
	static int InstanceCount;
public:
	DynamicArray();
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	int lenght();
	void PushBack(int value);
	int GetAt(int i);
	int operator [](int index);
	string ToString() const;

	friend istream& operator >> (istream& in, DynamicArray *P);
	friend ostream& operator << (ostream& out, const DynamicArray *P);
};

#endif
