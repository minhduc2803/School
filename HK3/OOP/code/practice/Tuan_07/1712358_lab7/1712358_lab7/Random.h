#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <ctime>
#include <cstdlib>
class Random {
public:
	static void Reset();
	static int Next();
	static int Next(int max);
};

#endif
