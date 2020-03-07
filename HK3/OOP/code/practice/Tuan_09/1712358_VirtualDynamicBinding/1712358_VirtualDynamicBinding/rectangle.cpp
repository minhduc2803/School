#include "rectangle.h"

Rectangle::Rectangle()
{
	float x = rand() % 100;
	float y = rand() % 100;
	topleft = new Point(x, y);

	x = rand() % 100;
	y = rand() % 100;
	bottomright = new Point(x, y);
}
Rectangle::~Rectangle()
{
	delete topleft, bottomright;
}
void Rectangle::Draw()
{
	cout << "- Drawing a rectangle with a point " << topleft->ToString() << " and a point " << bottomright->ToString() << endl;
}