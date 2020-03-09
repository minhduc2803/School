#include"POINT.h"

void InputPoint(POINT& A)
{
	scanf_s("%f %f", &A.x, &A.y);
}

void OutputPoint(POINT A)
{
	printf("(%.3f;%.3f) ", A.x, A.y);
}
