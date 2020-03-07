#include "Point.h"
#include "LineV3.h"
#include "RectangleV3.h"

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int main()
{ 
	Point *A = new Point(1, 2);
	Point *B = new Point;
	cout << "A(" << A->X() << ";" << A->Y() << "), ";
	cout << "B(" << B->X() << ";" << B->Y() << ")" << endl;
	cout << "The distance from A to B: " << A->DistanceTo(B) << endl;
	cout << "The total points: " << Point::InstanceCount << endl << endl;

	Line *p = new Line(A, B);
	Line *q = new Line;
	cout << "The line p is from A to B" << ", length: " << p->Length() << endl;
	cout << "The line q is from (0;0) to (1;1)" << ", length: " << q->Length() << endl;
	cout << "The total lines: " << Line::InstanceCount << endl << endl;

	Rectangle *m = new Rectangle(A, B);
	Rectangle *n = new Rectangle;
	cout << "The rectangle m with the topleft point A and bottomright point B" << endl << "m's area: " << m->Area() << endl;
	cout << "The rectangle n with the topleft point (0,0) and the bottomright point (1,1)" << endl << "n's area: " << n->Area() << endl;
	cout << "The total rectangles: " << Line::InstanceCount << endl;
	cout << endl;
	cout << "The total points: " << Point::InstanceCount << endl;

	system("pause");
	return 0;
}