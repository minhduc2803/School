#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <random>
#include <ctime>
#include <iostream>

using namespace std;

class Animal {
public:
	static int InstanceCount;
public:
	Animal() { InstanceCount++; }
	~Animal() { InstanceCount--; }
	virtual int HaveBaby() = 0;
	virtual int GiveMilk() = 0;
	virtual void MakeSound(){}
};


#endif
