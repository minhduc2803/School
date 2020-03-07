#ifndef _CARBRIOLET_H_
#define _CARBRIOLET_H_

#include <iostream>
#include "car.h"

using namespace std;

class Carbriolet: public Car{
private:

public:
	Carbriolet();
	~Carbriolet();
	void StartEngine();
};

#endif