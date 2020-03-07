#ifndef _LINEV3_H_
#define _LINEV3_H_

#include "Point.h"

using namespace std;

class Line{
public:
	static int InstanceCount;
private:
	Point *start, *end;
public:
	Line();
	Line(Point *A, Point *B);
	~Line();

	float Length() const;

};

#endif