#include "Point.h"

const float Point::X()
{
	return x;
}
const float Point::Y()
{
	return y;
}
void Point::setX(const float value)
{
	x = value;
}
void Point::setY(const float value)
{
	y = value;
}

Point::Point()
{
	x = 0;
	y = 0;
	InstanceCount++;
}
Point::Point(const float a, const float b)
{
	x = a;
	y = b;
	InstanceCount++;
}
Point::Point(Point* A)
{
	x = A->X();
	y = A->Y();
	InstanceCount++;
}
Point::Point(const Point& A)
{
	x = A.x;
	y = A.y;
	InstanceCount++;
}
Point::~Point()
{

}

float Point::DistanceTo(const Point* other) const
{
	return sqrt((x - other->x)*(x - other->x) + (y - other->y)*(y - other->y));
}

float Point::DistanceTo(const Point* A, const Point* B)
{
	return A->DistanceTo(B);
}
string Point::ToString() const
{
	stringstream fs;
	fs << "(" << x << ";" << y << ")";
	return fs.str();
}
istream& operator >> (istream& in, Point *A)
{
	float x, y;
	in >> x >> y;
	A->x = x;
	A->y = y;
	return in;
}
ostream& operator << (ostream& out, const Point *A)
{
	return out << A->ToString();
}