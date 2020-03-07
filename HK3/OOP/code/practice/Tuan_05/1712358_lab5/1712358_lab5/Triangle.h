#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Point.h"

using namespace std;

class Triangle{
public:
	static int InstanceCount;
private:
	Point *a, *b, *c;
public:
	Triangle();
	Triangle(Point *A, Point *B, Point *C);
	Triangle(const Triangle&);
	~Triangle();

	string ToString() const;

	friend istream& operator >> (istream& in, Triangle *A);
	friend ostream& operator << (ostream& out, const Triangle *A);
};

#endif