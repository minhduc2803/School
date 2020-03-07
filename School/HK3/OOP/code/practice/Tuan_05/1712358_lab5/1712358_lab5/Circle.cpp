 #include "Circle.h"

Circle::Circle()
{
	center = new Point(0, 0);
	radius = 1;
	InstanceCount++;
}
Circle::Circle(Point *A, float r)
{
	center = new Point(A);
	radius = r;
	InstanceCount++;
}
Circle::Circle(const Circle& d)
{
	center = new Point(*(d.center));
	radius = d.radius;
	InstanceCount++;
}
Circle::~Circle()
{
	delete center;
}

string Circle::ToString() const
{
	stringstream fs;
	fs << "(" << center->ToString() << ", " << radius << ")";
	return fs.str();
}
istream& operator >> (istream& in, Circle* &A)
{
	float r;
	Point *O = new Point;
	cout << "The point for center" << endl;
	in >> O;
	cout << "The radius ";
	in >> r;
	A->center = O;
	A->radius = r;
	return in;
}
ostream& operator << (ostream& out, const Circle *A)
{
	return out << A->ToString();
}