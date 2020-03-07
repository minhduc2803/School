#ifndef _GOAT_H_
#define _GOAT_H_

#include "animal.h"

using namespace std;

class Goat: public Animal {
public:
	static int InstanceCount;
public:
	Goat();
	~Goat();
	int HaveBaby();
	int GiveMilk();
	void MakeSound();
};


#endif
