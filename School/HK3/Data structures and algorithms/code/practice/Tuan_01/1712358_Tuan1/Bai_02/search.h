#ifndef _SEARCH_H_
#define _SEARCH_H_H_

#include <iostream>
#include <ctime>

using namespace std;

void output(int A[], int N);
int sequentialSearch(int A[], int N, int item);
int binarySearch(int A[], int N, int item);
int compare(const void * a, const void *b);

#endif
