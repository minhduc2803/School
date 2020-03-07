#include "point.h"
#include "Triangle.h"

int main()
{
	cout << "Test triangle class" << endl;
	Triangle * P = new Triangle();
	cout << "We have here the triangle with three points (1;1) (1;2) (4;2)" << endl;
	cout << "The Premeter: " << P->Premeter();
	cout << endl << "The area: " << P->Area();
	cout << endl << "Would you like to test the class with your own triangle ?" << endl;

	
	cout << "Enter your 3 points" << endl;
	int x, y;
	cout << "A:" << endl;
	cin >> x >> y;
	Point* A = new Point(x, y);
	cout << "B:" << endl;
	cin >> x >> y;
	Point* B = new Point(x, y);
	cout << "C:" << endl;
	cin >> x >> y;
	Point* C = new Point(x, y);
	Triangle *F = new Triangle(A, B, C);
	float area = F->Area();
	if (area != 0)
	{
		cout << endl << "The new Premeter: " << F->Premeter();
		cout << endl << "The new area: " << F->Area();
	}
	else
	{
		cout << endl << "Oops... maybe you just entered some points that do not compose a triangle" << endl;
	}
	cout << endl << "Test Succeed! yayyyy" << endl;
	return 0;
}