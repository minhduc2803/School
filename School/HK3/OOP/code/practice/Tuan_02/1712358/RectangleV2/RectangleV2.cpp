#include "RectangleV2.h"

RectangleV2::RectangleV2()
{
	topLeft = new Point(1, 1);
	bottomRight = new Point(10, 10);
}
RectangleV2::RectangleV2(Point *A, Point *B)
{ 
	topLeft = A;
	bottomRight = B;
}
RectangleV2::RectangleV2(RectangleV2* P)
{
	topLeft = new Point(P->topLeft);
	bottomRight = new Point(P->bottomRight);
}
RectangleV2::~RectangleV2()
{ 
	delete topLeft, bottomRight;
}
void RectangleV2::set(Point* A, Point* B)
{
	topLeft = A;
	bottomRight = B;
}
float RectangleV2::Premeter()
{ 
	float p = abs(topLeft->X() - bottomRight->X()) * abs(topLeft->Y() - bottomRight->Y());
	if (p != 0)
		return 2 * (abs(topLeft->X() - bottomRight->X()) + abs(topLeft->Y() - bottomRight->Y()));
	else
		return 0;
}
float RectangleV2::Area()
{
	float p = abs(topLeft->X() - bottomRight->X()) * abs(topLeft->Y() - bottomRight->Y());
	return p;
}