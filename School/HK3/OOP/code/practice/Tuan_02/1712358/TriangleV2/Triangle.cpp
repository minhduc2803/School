#include "Triangle.h"

Triangle::Triangle()
{
	A = new Point(1, 1);
	B = new Point(1, 2);
	C = new Point(4, 2);
}
Triangle::Triangle(Point* A, Point* B,Point* C)
{
	this->A = new Point(A);
	this->B = new Point(B);
	this->C = new Point(C);
}
Triangle::Triangle(Triangle* P)
{
	(*this) = *P;
}
Triangle::~Triangle()
{
	delete A, B, C;
}
void Triangle::set(Point* A, Point* B, Point* C)
{
	this->A = A;
	this->B = B;
	this->C = C;
}

float Triangle::Premeter()
{
	float a = B->CalcDistanceTo(C);
	float b = C->CalcDistanceTo(A);
	float c = A->CalcDistanceTo(B);
	float p = (a + b + c) / 2;
	if (p <= a || p <= b || p <= c)
		return 0;
	return p * 2;
}
float Triangle::Area()
{
	float a = B->CalcDistanceTo(C);
	float b = C->CalcDistanceTo(A);
	float c = A->CalcDistanceTo(B);
	float p = (a + b + c) / 2;
	if (p <= a || p <= b || p <= c)
		return 0;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}