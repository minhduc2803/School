#include "Point.h"
#include "LineV3.h"
#include "RectangleV3.h"

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int main()
{ 
	Point *A = new Point(0, 0);
	Point *B = new Point(1, 5);
	cout << "Now we have here 2 points A(0,0) and B(1,5)" << endl << endl;
	cout << "Test copy line function" << endl;
	Line *d = new Line(A, B);
	cout << "The line d is from A(0,0) to b(1,5)" << endl;
	cout << "the line copy of d is d1" << endl;
	Line *d1 = new Line(*d);
	cout << "d1: ";
	d1->declare();


	system("pause");
	return 0;
}