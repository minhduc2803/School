#ifndef _COW_H_
#define _COW_H_

#include "animal.h"

using namespace std;

class Cow: public Animal {
public:
	static int InstanceCount;
public:
	Cow();
	Cow* Clone();
	~Cow();
	int HaveBaby();
	int GiveMilk();
	void MakeSound();
};


#endif
