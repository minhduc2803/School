#ifndef _RECTANGLEV2_H_
#define _RECTANGLEV2_H_

#include "Point.h"

class RectangleV2{
	Point *topLeft, *bottomRight;
public:
	RectangleV2();
	RectangleV2(Point*, Point*);
	RectangleV2(RectangleV2*);
	~RectangleV2();

	void set(Point*, Point*);

	float Premeter();
	float Area();

};

#endif