#ifndef _DICE_H_
#define _DICE_H_

#include "Random.h"
class Dice {
	Random A;
public:
	int RollCount;
	Dice();
	int Roll();

};
#endif
