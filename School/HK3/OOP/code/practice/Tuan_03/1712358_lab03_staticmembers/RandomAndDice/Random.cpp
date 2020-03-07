#include "Random.h"

Random::Random() 
{ 
	srand(time(0));
}
int Random::Next()
{
	return rand(); 
}
int Random::Next(int max)
{ 
	return rand() % max;
}