#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Point.h"

using namespace std;

class Circle{
public:
	static int InstanceCount;
private:
	Point *center;
	float radius;
public:
	Circle();
	Circle(Point *A, float r);
	Circle(const Circle&);
	~Circle();

	string ToString() const;

	friend istream& operator >> (istream& in, Circle* &A);
	friend ostream& operator << (ostream& out, const Circle *A);
};

#endif