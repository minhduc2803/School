#include "handle.h"

void input(int &N)
{
	cout << "Enter the number of the array N: ";
	while (1)
	{
		cin >> N;
		if (N <= 0)
			cout << "N must be greater than 0, please try again" << endl;
		else
			break;
	}
}
void input(int A[], int N)
{
	cout << "Enter " << N << " elements" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}
}
void output(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}
void sorting(int A[], int N, int k)
{
	if (N < k)
		k = N;
	
	for (int i = 0; i < k; i++)
	{
		int min = i;
		for (int j = i + 1; j < k; j++)
		{
			if (A[min] > A[j])
				min = j;
		}
		swap(A[i], A[min]);
	}
	for (int i = k; i < N; i++)
	{
		int max = i;
		for (int j = i + 1; j < N; j++)
		{
			if (A[max] < A[j])
				max = j;
		}
		swap(A[i], A[max]);
	}
	
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
