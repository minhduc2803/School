#include "RectangleV3.h"

Rectangle::Rectangle()
{
	topleft = new Point;
	bottomright = new Point(1, 1);
	InstanceCount++;
}
Rectangle::Rectangle(Point *A, Point *B)
{
	topleft = new Point(A);
	bottomright = new Point(B);
	InstanceCount++;
}
Rectangle::~Rectangle()
{

}

float Rectangle::Area() const
{
	return abs(topleft->X() - bottomright->X())*abs(topleft->Y() - bottomright->Y());
}