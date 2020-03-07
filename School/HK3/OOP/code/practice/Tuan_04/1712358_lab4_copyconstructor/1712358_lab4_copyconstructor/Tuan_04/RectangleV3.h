#ifndef _RECTANGLEV3_H_
#define _RECTANGLEV3_H_

#include "Point.h"

using namespace std;

class Rectangle{
public:
	static int InstanceCount;
private:
	Point *topleft, *bottomright;
public:
	Rectangle();
	Rectangle(Point *A, Point *B);
	Rectangle(const Rectangle&);
	~Rectangle();

	void declare();
	float Area() const;
};

#endif