#include <iostream>

using namespace std;

int main()
{
	int A[] = { 19, 50, 10, 49, 80, 7, 2, 5 };
	int N = 8;
	for (int i = 0; i < N - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (A[min] > A[j])
				min = j;
		}
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
	cout << "The array after sorted" << endl;
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << endl;
	int k;
	cout << "Enter the number you want to search" << endl;
	cin >> k;
	for (int i = 0; i < N; i++)
	{
		if (k == A[i])
		{
			cout << k << " is the element number " << i + 1 << " in the array" << endl;
			return 0;
		}
		else if (k < A[i])
		{
			cout << "The array does not have the number " << k << endl;
			return 0;
		}
	}
	cout << "The array does not have the number " << k << endl;
}