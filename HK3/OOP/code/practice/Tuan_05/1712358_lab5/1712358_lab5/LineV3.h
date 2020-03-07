#ifndef _LINEV3_H_
#define _LINEV3_H_

#include "Point.h"

using namespace std;

class Line{
public:
	static int InstanceCount;
private:
	Point *start;
	Point *end;
public:
	Line();
	Line(Point *A, Point *B);
	Line(const Line&);
	~Line();

	void declare();
	float Length() const;
	string ToString() const;

	friend istream& operator >> (istream& in, Line *A);
	friend ostream& operator << (ostream& out, const Line *A);
};

#endif