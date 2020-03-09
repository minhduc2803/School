#ifndef _POINT_S_H_
#define _POINT_S_H_
#include"POINT.h"
void InputPoint_s(POINT A[], int& N);
void OutputPoint_s(POINT A[], int N);
float Distance(POINT A, POINT B);
int MaxDistance(POINT A, POINT P[], int N);
void PositivePoint_s(POINT P[], int N);
void SwapPoint_s(POINT& A, POINT& B);
void SortPoint_s(POINT P[], int N);
#endif