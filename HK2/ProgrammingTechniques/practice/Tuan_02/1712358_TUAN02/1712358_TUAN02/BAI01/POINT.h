#ifndef _POINT_H_
#define _POINT_H_
#include<stdio.h>

struct	Point {
	float x;
	float y;
};
typedef Point POINT; 

void InputPoint(POINT& A);
void OutputPoint(POINT A);
#endif

