#include "FlagSearch.h"

//finding the last x in the array then return the position of x, if couldnot find x, return -1
int FindLast2(int A[], int N, int x)
{
	for (int i = N-1; i >=0; i--)
	{
		if (A[i] == x)
			return i;
	}
	return -1;
}
//finding the first prime number in the array then return the postion of the prime number, if couldnot find any prime number, return -1
int FindFirstPrime2(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		if (TestPrime(A[i]))
			return A[i];
	}
	return -1;
}
//finding the minimum number in the array then return the value of the number
int FindMin2(int A[], int N)
{
	int min = A[0];
	for (int i = 1; i < N; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}
//finding the maximum positive integer then return the number, if couldnot find the number, return -1
int FindMaxPositive2(int A[], int N)
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max ? max : -1;
}
//finding the maximum prime number then return the value of the number, if couldnot find the number, return -1
int FindMaxPrime2(int A[], int N)
{
	int maxPrime = -1;
	for (int i = 0; i < N; i++)
	{
		if (TestPrime(A[i]))
			if (A[i] > maxPrime)
				maxPrime = A[i];
	}
	return maxPrime;
}
//findng the minimum symmetry number in the array then return the value of the number, if couldnot find the number, return -1
int FindMinSymmetry2(int A[], int N)
{
	int min = -1;
	int i = 0;
	while (!TestSymmetry(A[i++]));
	min = A[i - 1];
	for (int j = i + 1; j < N; j++)
	{
		if (TestSymmetry(A[j]))
		{
			if (min > A[j])
			{
				min = A[j];
			}
		}
	}
	return min;
}