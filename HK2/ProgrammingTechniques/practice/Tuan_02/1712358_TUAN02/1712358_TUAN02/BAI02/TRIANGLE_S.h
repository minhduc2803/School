#ifndef _TRIANGLE_S_H_
#define _TRIANGLE_S_H_
#include"TRIANGLE.h"
void InputTriangle_s(TRIANGLE T[], int& N);
void OutputTriangle_s(TRIANGLE T[], int N);
float Perimeter(TRIANGLE E);
float Area(TRIANGLE E);
int MaxPerimeter(TRIANGLE T[], int N);
int MinPerimeter(TRIANGLE T[], int N);
float SumOfArea(TRIANGLE T[], int N);
void CountLargeArea(TRIANGLE T[], int N);
void SwapTriangle(TRIANGLE& A, TRIANGLE& B);
void SortDePerimeter(TRIANGLE T[], int N);
#endif