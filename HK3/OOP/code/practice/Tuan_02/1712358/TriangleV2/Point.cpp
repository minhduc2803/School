
#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}
Point::Point(Point* A)
{
	this->x = A->x;
	this->y = A->y;
}
Point::~Point()
{
}
float Point::CalcDistanceTo(const Point* other)
{
	float dx = this->x - other->x;
	float dy = this->y - other->y;
	return sqrt(dx * dx + dy * dy);
}

