#include "handle.h"

void input(int& N)
{
	cout << "Enter number of the elements: ";
	while (1)
	{
		cin >> N;
		if (N <= 0)
			cout << "N must be greater than 0, try again" << endl;
		else
			break;
	}
}
void input(int A[], int N)
{
	cout << "Enter " << N << " elements:" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}
}
void output(int A[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
int search(int A[], int N, int k, int i)
{
	if (A[i] == k)
		return i;
	else
	{
		if (i == N - 1)
			return -1;
		else
			return search(A, N, k, i + 1);
	}
}