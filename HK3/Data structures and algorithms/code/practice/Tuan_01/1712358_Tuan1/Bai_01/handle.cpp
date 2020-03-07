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
int find_second(int A[], int N)
{
	if (N < 2)
		return -1;
	else
	{
		int first = 0;
		int second = 0;
		for (int i = 1; i < N; i++)
		{
			if (A[i] > A[first])
			{
				second = first;
				first = i;
			}
		}
		return second;
	}
}
