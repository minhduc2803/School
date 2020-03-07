#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	len = 0;
	max = INITIAL_SIZE;
	a = new int[max];
}
DynamicArray::DynamicArray(const DynamicArray& B)
{
	len = B.len;
	max = B.max;
	a = new int[max];
	for (int i = 0; i < len; i++)
		a[i] = B.a[i];
}
DynamicArray::~DynamicArray()
{
	delete[] a;
}
int DynamicArray::lenght()
{
	return len;
}
void DynamicArray::PushBack(int value)
{
	len++;
	if (len > max)
	{
		max += INITIAL_SIZE;
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
int DynamicArray::GetAt(int i)
{
	try {
		if (i < len)
		{
			cout << "element number " << i << " is " << a[i] << endl;
			return a[i];
		}
		else
			throw "Index out of bound";
	}
	catch (const char* mess)
	{
		cout << mess;
	}
}
int DynamicArray::operator [](int index)
{
	return this->a[index];
}
string DynamicArray::ToString() const
{
	stringstream fs;
	for (int i = 0; i < len; i++)
	{
		fs << a[i] << " ";
	}
	return fs.str();
}
istream& operator >> (istream& in, DynamicArray *P)
{
	cout << "Enter the length ";
	in >> P->len;
	while (P->max < P->len)
		P->max *= 2;
	cout << "Enter " << P->len << " elements" << endl;
	for (int i = 0; i < P->len; i++)
		in >> P->a[i];
	return in;
}
ostream& operator << (ostream& out, const DynamicArray *P)
{
	return out << P->ToString();
}