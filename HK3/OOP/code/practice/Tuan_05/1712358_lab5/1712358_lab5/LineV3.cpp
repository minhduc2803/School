#include "LineV3.h"

Line::Line()
{
	start = new Point(0, 0);
	end = new Point(1, 1);
	InstanceCount++;
}
Line::Line(Point *A, Point *B)
{
	start = new Point(A);
	end = new Point(B);
	InstanceCount++;
} 
Line::Line(const Line& d)
{
	start = new Point(*(d.start));
	end = new Point(*(d.end));
	InstanceCount++;
}
Line::~Line()
{
	delete start, end;
}

void Line::declare()
{
	cout << "start point: (" << start->X() << ";" << start->Y() << "), ";
	cout << "end point: (" << end->X() << ";" << end->Y() << ")" << endl;
}
float Line::Length() const
{
	return start->DistanceTo(end);
}
string Line::ToString() const
{
	stringstream fs;
	fs << "[" << start->ToString() << "," << end->ToString() << "]";
	return fs.str();
}
istream& operator >> (istream& in, Line *A)
{
	Point *P = new Point;
	Point *Q = new Point;
	in >> P >> Q;
	A->start = P;
	A->end = Q;
	return in;
}
ostream& operator << (ostream& out, const Line *A)
{
	return out << A->ToString();
}