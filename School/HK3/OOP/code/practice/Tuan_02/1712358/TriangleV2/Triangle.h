#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Point.h"

class Triangle {
	Point *A, *B, *C;
public:
	Triangle();
	Triangle(Point*, Point*,Point*);
	Triangle(Triangle*);
	~Triangle();
	void set(Point*, Point*, Point*);
	float Premeter();
	float Area();

};

#endif
