#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "figure.h"

using namespace std;

class Rectangle : public Figure {
private:
	Point *topleft, *bottomright;
public:
	Rectangle();
	~Rectangle();
	virtual void Draw();
};

#endif
