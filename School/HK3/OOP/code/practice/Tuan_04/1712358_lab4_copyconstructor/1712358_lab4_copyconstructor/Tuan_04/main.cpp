#include "Point.h"
#include "LineV3.h"
#include "RectangleV3.h"
#include "DynamicArray.h"

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int main()
{ 
	Point *A = new Point(0, 0);
	Point *B = new Point(1, 5);
	cout << "Now we have here 2 points A(0,0) and B(1,5)";
	cout << endl << endl << "Test copy Line function" << endl;
	Line *d = new Line(A, B);
	cout << "The line d is from A(0,0) to B(1,5)" << endl;
	cout << "The length of d: " << d->Length() << endl;
	cout << "the line copy of d is d1" << endl;
	Line *d1 = new Line(*d);
	cout << "d1: ";
	d1->declare();
	cout << "Total lines have been created: " << Line::InstanceCount;

	cout << endl << endl << "Test copy Rectangle function" << endl;
	Rectangle *H = new Rectangle(A, B);
	cout << "The Rectangle H has the top left point A(0,0), the bottom right point B(1,5)" << endl;
	cout << "The area of H: " << H->Area() << endl;
	cout << "The rectangle copy of H is H1" << endl;
	Rectangle *H1 = new Rectangle(*H);
	cout << "H1 has: ";
	H1->declare();
	cout << "Total rectangles have been created: " << Rectangle::InstanceCount << endl;

	cout << endl << "Test dynamic array copy funtion" << endl;
	DynamicArray* D = new DynamicArray;
	cout << "The DArray (dynamic array) D after adding 5,12,7,4,5,10" << endl;
	D->PushBack(5);
	D->PushBack(12);
	D->PushBack(7);
	D->PushBack(4);
	D->PushBack(5);
	D->PushBack(10);
	cout << "D: ";
	for (int i = 0; i < D->lenght(); i++)
	{
		cout << D->GetAt(i) << " ";
	}
	cout << endl << "The DArray E is a copy of D" << endl;
	cout << "E: ";
	DynamicArray* E = new DynamicArray(*D);
	for (int i = 0; i < E->lenght(); i++)
	{
		cout << E->GetAt(i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}