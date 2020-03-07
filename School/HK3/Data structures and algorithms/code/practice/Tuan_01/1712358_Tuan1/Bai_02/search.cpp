#include "search.h"

int sequentialSearch(int A[], int N, int item)
{
	for (int i = 0; i < N; i++)
		if (A[i] == item)
			return i;
	return -1;
}
int binarySearch(int A[], int N, int item)
{
	int left = 0, right = N - 1;
	int mid;
	for (left, right; left <= right;)
	{
		mid = (left + right) / 2;
		if (A[mid] == item)
			return mid;
		else if (item > A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
void output(int A[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
int compare(const void * a, const void *b)
{
	return *(int*)a - *(int*)b;
}

