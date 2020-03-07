#include "DynamicArray.h"

int main()
{
	DynamicArray A;
	int N;
	cout << "Test dynamic array" << endl;
	cout << "Enter N: ";
	cin >> N;
	cout << "Enter N elements: " << endl;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.PushBack(x);
	}
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}