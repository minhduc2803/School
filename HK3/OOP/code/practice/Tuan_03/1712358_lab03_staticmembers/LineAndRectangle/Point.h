#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <cmath>

using namespace std;

class Point{
public:
	static int InstanceCount;
private:
	float x, y;
public:
	const float X();
	const float Y();
	void setX(const float value);
	void setY(const float value);

	Point();
	Point(const float, const float);
	Point(Point*);
	~Point();

	float DistanceTo(const Point* other) const;

	static float DistanceTo(const Point* A, const Point* B);
};

#endif