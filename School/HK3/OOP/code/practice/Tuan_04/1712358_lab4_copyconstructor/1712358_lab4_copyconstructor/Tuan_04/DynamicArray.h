#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include <iostream>

using namespace std;

class DynamicArray {
	int *a;
	int len, max;
public:
	DynamicArray();
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	int lenght();
	void PushBack(int value);
	int GetAt(int i);
	int operator [](int index);

};

#endif
