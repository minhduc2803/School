#include "sortfunction.h"

void swap(int& A, int& B)
{
	int temp = A;
	A = B;
	B = temp;
}
int bsearch(int A[], int left, int right, int q)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (q == A[mid])
			return mid;
		else if (q>A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (A[mid]<q)
		return mid;
	else
		return mid - 1;
}
void insertion_h(int A[], int N, int k, int begin)
{
	for (int i = begin+k; i < N; i+=k)
	{
		int temp = A[i];
		int j;
		for (j = i - k; j >= begin; j-=k)
		{
			if (A[j] > temp)
				A[j + k] = A[j];
			else
				break;
		}
		A[j + k] = temp;
	}
}
void Merge(int A[], int s1, int e1, int s2, int e2, int temp[])
{
	int i = s1, j = s2;

	for (int index = s1; index <= e2;)
	{
		temp[index++] = A[i] < A[j] ? A[i++] : A[j++];
		if (i > e1)
		{
			while (index <= e2)
			{
				temp[index++] = A[j++];
			}
			break;
		}
		if (j > e2)
		{
			while (index <= e2)
			{
				temp[index++] = A[i++];
			}
			break;
		}
	}
	for (int i = s1; i <= e2; i++)
		A[i] = temp[i];
}
void Heapify(int A[], int N, int k)
{
	int l1 = 2 * k + 1;
	int l2 = l1 + 1;
	if (l2 < N)
	{
		int max = A[l1] > A[l2] ? l1 : l2;
		if (A[k] < A[max])
		{
			swap(A[k], A[max]);
			Heapify(A, N, max);
		}
	}
	else if (l1 < N)
	{
		if (A[k] < A[l1])
			swap(A[k], A[l1]);
	}
}
void subQuickSort(int A[], int left, int right)
{
	if (left >= right) return;
	int i = left, j = right;
	int key = (A[left] + A[right]) / 2;
	while (1)
	{
		while (i < j && A[i] <= key)
			i++;
		while (i < j && A[j] > key)
			j--;
		if (i < j)
		{
			swap(A[i], A[j]);
			i++; j--;
		}
		if (i == j)
		{
			if (A[i] > key)
				i--;
			else if (A[i] < key)
				j++;
			else
			{
				i--; j++;
			}
			break;
		}
		if (i > j)
		{
			i--; j++;
			break;
		}
	}
	subQuickSort(A, left, i);
	subQuickSort(A, j, right);
}

void SelectionSort(int A[], int N)
{
	cout << setw(40) << left << "Selection sort: sorting...";
	int n = N - 1;
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (A[j] < A[min])
				min = j;
		}
		swap(A[i], A[min]);
	}
}

void BubbleSort(int A[], int N)
{
	cout << setw(40) << left << "Bubble sort: sorting...";
	for (int i = N-1; i>0; i--)
		for (int j = 0; j < i; j++)
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
}

void InsertionSort(int A[], int N)
{
	cout << setw(40) << left << "Insertion sort: sorting...";
	for (int i = 1; i < N; i++)
	{
		int temp = A[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (A[j] > temp)
				A[j + 1] = A[j];
			else
				break;
		}
		A[j + 1] = temp;
	}
}

void MergeSort(int A[], int N)
{
	cout << setw(40) << left << "Merge sort: sorting...";
	int *temp = new int[N];
	for (int k = 1; k < N; k += k)
	{
		int s1 = 0, s2 = k;
		int e1 = s2 - 1, e2 = e1 + k;
		while (e2 < N)
		{
			Merge(A, s1, e1, s2, e2, temp);
			s1 = e2 + 1;
			s2 = s1 + k;
			e1 = s2 - 1;
			e2 = e1 + k;
		}
		if (s2 < N)
			Merge(A, s1, e1, s2, N-1, temp);
	}
}

void QuickSort(int A[], int N)
{
	cout << setw(40) << left << "Quick sort: sorting...";
	subQuickSort(A, 0, N - 1);
}

void HeapSort(int A[], int N)
{
	cout << setw(40) << left << "Heap sort: sorting...";

	//heapify
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		Heapify(A, N, i);
	}
	
	swap(A[0], A[N - 1]);
	for (int i = N - 2; i > 0; i--)
	{
		Heapify(A, i + 1, 0);
		swap(A[0], A[i]);
	}
}

void RadixSort(int A[], int N)
{
	cout << setw(40) << left << "Radix sort: sorting...";
	int *B = new int[N];
	int max = A[0];
	for (int i = 0; i < N; i++)
		if (max < A[i])
			max = A[i];

	for (unsigned int k = 15, tran=0; max > 0; k = k << 4, tran+=4,max = max >> 4)
	{
		int index[16] = { 0 };
		for (int i = 0; i < N; i++)
		{
			int recent = (k&A[i]) >> tran;
			index[recent]++;
		}
		for (int i = 1; i < 16; i++)
			index[i] += index[i - 1];

		for (int i = N-1; i >= 0; i--)
		{
			int recent = (k&A[i]) >> tran;

			B[--index[recent]] = A[i];
		}

		for (int i = 0; i < N; i++)
			A[i] = B[i];
	}
}

void ShellSort(int A[], int N)
{
	cout << setw(40) << left << "Shell sort: sorting...";
	int k = N / 2;
	for (k; k >= 1; k = k / 2)
	{
		for(int i=0;i<k;i++)
			insertion_h(A, N, k, i);
	}
	
}

void BinaryInsertionSort(int A[], int N)
{
	cout << setw(40) << left << "Binary insertion sort: sorting...";
	for (int i = 1; i < N; i++)
	{
		int k = bsearch(A, 0, i - 1, A[i]);
		k++;
		int temp = A[i];
		for (int j = i; j > k; j--)
		{
			A[j] = A[j - 1];
		}
		A[k] = temp;
	}
}

void ShakerSort(int A[], int N)
{
	cout << setw(40) << left << "Shaker sort: sorting...";
	int top = 0, bottom = N - 1;
	while (top < bottom)
	{
		int k = top;
		for (int i = top; i < bottom; i++)
		{
			if (A[i] > A[i + 1])
			{
				k = i;
				swap(A[i], A[i + 1]);
			}
		}
		bottom = k;
		k = bottom;
		for (int i = bottom; i > top; i--)
		{
			if (A[i] < A[i - 1])
			{
				k = i;
				swap(A[i], A[i - 1]);
			}
		}
		top = k;
	}
}

void InterchangeSort(int A[], int N)
{
	cout << setw(40) << left << "Interchange sort: sorting...";
	int n = N - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (A[i] > A[j])
				swap(A[i], A[j]);
		}
	}
}