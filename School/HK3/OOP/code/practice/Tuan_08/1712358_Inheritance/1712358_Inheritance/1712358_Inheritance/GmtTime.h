#ifndef _GMTTTME_H_
#define _GMTTIME_H_

#include "time.h"

class GmtTime : public Time {
public:
	GmtTime();
	GmtTime(int h, int m, int s);
	GmtTime(const GmtTime& t);
	~GmtTime();
	string ToString(int m);
};

#endif