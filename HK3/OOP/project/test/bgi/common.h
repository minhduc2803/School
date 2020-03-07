#ifndef _COMMON_H_
#define _COMMON_H_

#include "graphics.h"

class Common {
	friend class Display;
public:
	static void BackroundColor(int color);
	static void Screen();
	static bool GetClick(int x, int y, int x1, int y1, int x2, int y2);
};

#endif
