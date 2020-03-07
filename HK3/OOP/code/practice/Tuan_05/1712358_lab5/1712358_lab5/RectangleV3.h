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
	string ToString() const;

	friend istream& operator >> (istream& in, Rectangle *A);
	friend ostream& operator << (ostream& out, const Rectangle *A);
};

#endif