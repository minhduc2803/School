#include "Triangle.h"

Triangle::Triangle()
{
	a = new Point(0, 0);
	b = new Point(1, 1);
	c = new Point(1, 0);
	InstanceCount++;
}
Triangle::Triangle(Point *A, Point *B, Point *C)
{
	a = new Point(A);
	b = new Point(B);
	c = new Point(C);
	InstanceCount++;
}
Triangle::Triangle(const Triangle& H)
{
	a = new Point(*(H.a));
	b = new Point(*(H.b));
	c = new Point(*(H.c));
	InstanceCount++;
}
Triangle::~Triangle()
{
	delete a, b, c;
}

string Triangle::ToString() const
{
	stringstream fs;
	fs << "[" << a->ToString() << ", " << b->ToString() << ", " << c->ToString() << "]";
	return fs.str();
}
istream& operator >> (istream& in, Triangle *A)
{
	Point *a = new Point;
	Point *b = new Point;
	Point *c = new Point;
	in >> a >> b >> c;
	A->a = a;
	A->b = b;
	A->c = c;
	return in;
}
ostream& operator << (ostream& out, const Triangle *A)
{
	return out << A->ToString();
}
