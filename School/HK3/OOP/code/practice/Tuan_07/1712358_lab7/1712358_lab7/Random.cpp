#include "Random.h"

void Random::Reset()
{
	srand(time(0));
}

int Random::Next()
{
	return rand(); 
}
int Random::Next(int max)
{ 
	return rand() % (max+1);
}