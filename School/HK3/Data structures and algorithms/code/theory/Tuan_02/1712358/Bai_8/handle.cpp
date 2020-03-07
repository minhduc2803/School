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
bool test_sorted(int A[], int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}
int binary_search(int A[], int N, int k)
{
	int left = 0, right = N - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == k)
			return mid;
		else if (k > A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
