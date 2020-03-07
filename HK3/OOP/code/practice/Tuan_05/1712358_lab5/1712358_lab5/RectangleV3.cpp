#include "RectangleV3.h"

Rectangle::Rectangle()
{
	topleft = new Point(0, 0);
	bottomright = new Point(1, 1);
	InstanceCount++;
}
Rectangle::Rectangle(Point *A, Point *B)
{
	topleft = new Point(A);
	bottomright = new Point(B);
	InstanceCount++;
}
Rectangle::Rectangle(const Rectangle& H)
{
	topleft = new Point(*(H.topleft));
	bottomright = new Point(*(H.bottomright));
	InstanceCount++;
}
Rectangle::~Rectangle()
{
	delete topleft, bottomright;
}

void Rectangle::declare()
{
	cout << "top left point: (" << topleft->X() << ";" << topleft->Y() << "), ";
	cout << "bottom right point: (" << bottomright->X() << ";" << bottomright->Y() << ")" << endl;
}
float Rectangle::Area() const
{
	return abs(topleft->X() - bottomright->X())*abs(topleft->Y() - bottomright->Y());
}
string Rectangle::ToString() const
{
	stringstream fs;
	fs << "[" << topleft->ToString() << ", " << bottomright->ToString() << "]";
	return fs.str();
}
istream& operator >> (istream& in, Rectangle *A)
{
	Point *a = new Point;
	Point *b = new Point;
	in >> a >> b;
	A->topleft = a;
	A->bottomright = b;
	return in;
}
ostream& operator << (ostream& out, const Rectangle *A)
{
	return out << A->ToString();
}
