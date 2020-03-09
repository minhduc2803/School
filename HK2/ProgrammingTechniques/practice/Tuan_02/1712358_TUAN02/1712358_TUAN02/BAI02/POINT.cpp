#include"POINT.h"
#include<math.h>
void InputPoint(POINT& A)
{
	scanf_s("%f %f", &A.x, &A.y);
}

void OutputPoint(POINT A)
{
	printf("(%.3f;%.3f) ", A.x, A.y);
}

float Distance(POINT A, POINT B)
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

void SwapPoint(POINT& A, POINT& B)
{
	float x = A.x;
	float y = A.y;
	A.x = B.x;
	A.y = B.y;
	B.x = x;
	B.y = y;
}