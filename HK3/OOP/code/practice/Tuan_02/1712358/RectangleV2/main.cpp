#include "point.h"
#include "RectangleV2.h"

int main()
{ 
	cout << "Test rectangle class" << endl;
	RectangleV2 * P = new RectangleV2();
	cout << "We have here the rectangle with four points (1;1) (1;10) (10;10) (10,1)" << endl;
	cout << "The Premeter: " << P->Premeter();
	cout << endl << "The area: " << P->Area();

	cout << endl << "Would you like to change the rectangle, please enter 2 points" << endl;
	cout << "A: " << endl;
	int x, y;
	cin >> x >> y;
	Point *A = new Point(x, y);
	cout << "B: " << endl;
	cin >> x >> y;
	Point *C = new Point(x, y);
	P->set(A, C);
	float area = P->Area();
	if (area != 0)
	{
		cout << endl << "The new Premeter: " << P->Premeter();
		cout << endl << "The new area: " << P->Area();
	}
	else
	{
		cout << endl << "Oops... maybe you just entered some points that do not compose a rectangle" << endl;
	}
	cout << endl << "Test Succeed! yayyyy" << endl;
	return 0;
}