#ifndef _ELIP_H_
#define _ELIP_H_

#include "figure.h"

using namespace std;

class Elip : public Figure {
private:
	Point *F1, *F2;
	int a;
public:
	Elip();
	~Elip();
	virtual void Draw();
};

#endif
