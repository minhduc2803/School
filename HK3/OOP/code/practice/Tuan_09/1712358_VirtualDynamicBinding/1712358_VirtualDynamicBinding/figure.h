#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "Point.h"
#include <random>
using namespace std;

class Figure {
public:
	Figure(){}
	virtual ~Figure(){}
	virtual void Draw() = 0;
};

#endif
