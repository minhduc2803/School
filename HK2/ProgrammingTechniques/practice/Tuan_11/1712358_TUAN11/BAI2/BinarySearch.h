#ifndef _BinarySearch_H_
#define _BinarySearch_H_
#include "SUPPORT.h"

//finding the last x in the array then return the position of x, if couldnot find x, return -1
int FindLast3(int A[], int N, int x);
int FindLast(int A[], int begin, int end, int x);
//finding the first prime number in the array then return the postion of the prime number, if couldnot find any prime number, return -1
int FindFirstPrime3(int A[], int N);
//finding the minimum number in the array then return the value of the number
int FindMin3(int A[], int N);
//finding the maximum positive integer then return the number, if couldnot find the number, return -1
int FindMaxPositive3(int A[], int N);
//finding the maximum prime number then return the value of the number, if couldnot find the number, return -1
int FindMaxPrime3(int A[], int N);
//findng the minimum symmetry number in the array then return the value of the number, if couldnot find the number, return -1
int FindMinSymmetry3(int A[], int N);

#endif
