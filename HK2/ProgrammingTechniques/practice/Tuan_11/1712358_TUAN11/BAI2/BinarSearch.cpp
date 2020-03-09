#include "BinarySearch.h"

//finding the last x in the array then return the position of x, if couldnot find x, return -1
int FindLast3(int A[], int N, int x)
{
	int pos = FindLast(A, 0, N - 1, x);
	if (pos == -1)
		return -1;
	else
	{
		while (A[++pos] == x);
		return pos - 1;
	}
}
int FindLast(int A[], int begin, int end, int x)
{
	if (end - begin >= 1)
	{
		int ave = (end + begin) / 2;
		if (A[ave] == x)
			return ave;
		else if (A[ave] > x)
			return FindLast(A, ave + 1, end, x);
		else
			return FindLast(A, begin, ave - 1, x);
	}
	else if (end == begin)
	{
		if (A[begin] == x)
			return begin;
	}
	else
		return -1;
}
//finding the first prime number in the array then return the postion of the prime number, if couldnot find any prime number, return -1
int FindFirstPrime3(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		if (TestPrime(A[i]))
			return A[i];
	}
	return -1;
}
//finding the minimum number in the array then return the value of the number
int FindMin3(int A[], int N)
{
	return A[0];
}
//finding the maximum positive integer then return the number, if couldnot find the number, return -1
int FindMaxPositive3(int A[], int N)
{
	if (A[N - 1] > 0)
		return A[N - 1];
	else
		return -1;
}
//finding the maximum prime number then return the value of the number, if couldnot find the number, return -1
int FindMaxPrime3(int A[], int N)
{
	for (int i = N - 1; i >=0; i--)
	{
		if (TestPrime(A[i]))
			return A[i];
	}
	return -1;
}
//findng the minimum symmetry number in the array then return the value of the number, if couldnot find the number, return -1
int FindMinSymmetry3(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		if (TestSymmetry(A[i]))
			return A[i];
	}
	return -1;
}