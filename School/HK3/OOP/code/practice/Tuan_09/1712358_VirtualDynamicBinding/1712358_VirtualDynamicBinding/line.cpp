#include "line.h"

Line::Line()
{
	float x = rand() % 100;
	float y = rand() % 100;
	begin = new Point(x, y);

	x = rand() % 100;
	y = rand() % 100;
	end = new Point(x, y);
}
Line::~Line()
{
	delete begin, end;
}
void Line::Draw()
{
	cout << "- Drawing a line from " << begin->ToString() << " to " << end->ToString() << endl;
}