#include "InOut.h"

void input(int A[], int N)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
		A[i] = rand()*rand();
}
void output(int A[], int N)
{
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << endl;
}
void copy(int A[], int B[], int N)
{
	for (int i = 0; i < N; i++)
		B[i] = A[i];
}
void test_time(int B[], int N, void sort(int A[], int N))
{
	int s1 = clock();
	sort(B, N);
	int s2 = clock();
	cout << "Total time: " << setw(7) << right << (int)((float)(s2 - s1)/CLOCKS_PER_SEC*1000) << " ms" << endl << endl;
	//output(B, N);
}
void test_sort(int A[], int N)
{
	int *B = new int[N];
	copy(A, B, N);
	test_time(B, N, SelectionSort);
	copy(A, B, N);
	test_time(B, N, BubbleSort);
	copy(A, B, N);
	test_time(B, N, InsertionSort);
	copy(A, B, N);
	test_time(B, N, MergeSort);
	copy(A, B, N);
	test_time(B, N, QuickSort);
	copy(A, B, N);
	test_time(B, N, HeapSort);
	copy(A, B, N);
	test_time(B, N, RadixSort);
	copy(A, B, N);
	test_time(B, N, ShellSort);
	copy(A, B, N);
	test_time(B, N, BinaryInsertionSort);
	copy(A, B, N);
	test_time(B, N, ShakerSort);
	copy(A, B, N);
	test_time(B, N, InterchangeSort);
}