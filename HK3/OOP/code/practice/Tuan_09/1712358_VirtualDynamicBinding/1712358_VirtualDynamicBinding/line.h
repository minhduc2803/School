#ifndef _LINE_H_
#define _LINE_H_

#include "figure.h"

using namespace std;

class Line: public Figure {
private:
	Point *begin, *end;
public:
	Line();
	~Line();
	virtual void Draw();
};

#endif
