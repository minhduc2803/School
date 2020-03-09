#include "SUPPORT.h"

//if x is the prime number then return true, else retun false
bool TestPrime(int x)
{
	if (x < 2)
		return false;

	else if (x >= 2 && x <= 3)
		return true;
	else
	{
		float sr = sqrt(x);
		for (int k = 2; k < sr; k++)
		{
			if (x%k == 0)
				return false;
		}
		return true;
	}
}
//if x is a symmetry number the return true, else return false
bool TestSymmetry(int x)
{
	char a[11];
	int n = 0;
	do
	{
		a[n++] = x % 10;
	} while (x = x / 10);
	for (int i = 0; i < n/2; i++)
	{
		if (a[i] != a[n - i - 1])
			return false;
	}
	return true;
}
//sorting the array
void Sorting(int A[], int N)
{
	for (int i = N - 1; i>0; i--)
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
}