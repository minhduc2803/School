#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <ctime>
#include <cstdlib>
class Random {
public:
	Random();
	int Next();
	int Next(int max);
};

#endif
