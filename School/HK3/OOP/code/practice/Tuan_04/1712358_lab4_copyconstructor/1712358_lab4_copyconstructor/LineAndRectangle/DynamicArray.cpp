#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	a = new int[8];
	len = 0;
	max = 8;
}
DynamicArray::DynamicArray(const DynamicArray& B)
{
	len = B.len;
	max = B.max;
	a = new int[len];
	for (int i = 0; i < len; i++)
		a[i] = B.a[i];
}
DynamicArray::~DynamicArray()
{
	delete[] a;
}
void DynamicArray::PushBack(int value)
{
	len++;
	if (len > max)
	{
		max *= 2;
		int* b = new int[max];
		for (int i = 0; i < len - 1; i++)
			b[i] = a[i];
		b[len-1] = value;
		delete[] a;
		a = b;
	}
	else
		a[len - 1] = value;
}
int DynamicArray::operator [](int index)
{
	return this->a[index];
}