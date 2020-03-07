#include "LineV3.h"

Line::Line()
{
	start = new Point;
	end = new Point(1, 1);
	InstanceCount++;
}
Line::Line(Point *A, Point *B)
{
	start = new Point(A);
	end = new Point(B);
	InstanceCount++;
}
Line::~Line()
{

}

float Line::Length() const
{
	return start->DistanceTo(end);
}