#ifndef _SORTFUNCTION_H_
#define _SORTFUNCTION_H_

#include <iostream>
#include <iomanip>
using namespace std;

void swap(int& A, int& B);
int bsearch(int A[], int left, int right, int q);
void insertion_h(int A[], int N, int k, int begin);
void Merge(int A[], int s1, int e1, int s2, int e2, int temp[]);
void Heapify(int A[], int N, int k);
void subQuickSort(int A[], int left, int right);

void SelectionSort(int A[], int N);
void BubbleSort(int A[], int N);
void InsertionSort(int A[], int N);
void MergeSort(int A[], int N);
void QuickSort(int A[], int N);
void HeapSort(int A[], int N);
void RadixSort(int A[], int N);
void ShellSort(int A[], int N);
void BinaryInsertionSort(int A[], int N);
void ShakerSort(int A[], int N);
void InterchangeSort(int A[], int N);

#endif
