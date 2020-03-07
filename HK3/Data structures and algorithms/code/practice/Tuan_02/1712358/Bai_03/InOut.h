#ifndef _INOUT_H_
#define _INOUT_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "sortfunction.h"

using namespace std;

void input(int A[], int N);
void output(int A[], int N);
void copy(int A[], int B[], int N);
void test_time(int B[], int N, void sort(int A[], int N));
void test_sort(int A[], int N);

#endif
