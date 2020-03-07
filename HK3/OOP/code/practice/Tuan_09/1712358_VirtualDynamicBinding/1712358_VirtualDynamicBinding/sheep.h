#ifndef _SHEEP_H_
#define _SHEEP_H_

#include "animal.h"

using namespace std;

class Sheep: public Animal {
public:
	static int InstanceCount;
public:
	Sheep();
	Sheep* Clone();
	~Sheep();
	int HaveBaby();
	int GiveMilk();
	void MakeSound();
};


#endif
