#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>
#include <iostream>

using namespace std;

class Point {
	float x, y;
public:
	Point();
	Point(Point*);
	Point(float, float);
	~Point();

	float X() { return x; }
	float Y() { return y; }
	void setX(float value) { x = value; }
	void setY(float value) { y = value; }

	float CalcDistanceTo(const Point* other);
};

#endif