#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Point{
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
	Point(const Point&);
	~Point();

	float DistanceTo(const Point* other) const;

	static float DistanceTo(const Point* A, const Point* B);
	string ToString() const;

	friend istream& operator >> (istream& in, Point *A);
	friend ostream& operator << (ostream& out, const Point *A);
};

#endif