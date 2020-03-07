#include "elip.h"

Elip::Elip()
{
	float x = rand() % 100;
	float y = rand() % 100;
	F1 = new Point(x, y);

	x = rand() % 100;
	y = rand() % 100;
	F2 = new Point(x, y);

	int c = rand() % 100;
	a = c;
}
Elip::~Elip()
{
	delete F1, F2;
}
void Elip::Draw()
{
	cout << "- Drawing an elip with 2 focal points: " << F1->ToString() << ", " << F2->ToString() << endl;
	cout << "                       And the semi-major axis is " << a << endl;
}