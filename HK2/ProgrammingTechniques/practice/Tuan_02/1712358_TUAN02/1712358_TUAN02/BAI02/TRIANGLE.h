#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include"POINT.h"
struct Triangle {
	POINT A, B, C;
};
typedef Triangle TRIANGLE;
void InputTriangle(TRIANGLE& M);
void OutputTriangle(TRIANGLE M);
#endif