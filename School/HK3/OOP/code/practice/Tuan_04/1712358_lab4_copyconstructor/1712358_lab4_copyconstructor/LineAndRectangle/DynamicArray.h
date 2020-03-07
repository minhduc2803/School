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
	void PushBack(int value);
	int operator [](int index);

};

#endif
