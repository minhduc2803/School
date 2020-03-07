#include "Dice.h"

Dice::Dice()
{
	RollCount = 0;
}
int Dice::Roll()
{
	RollCount++;
	return A.Next(6) + 1;
}