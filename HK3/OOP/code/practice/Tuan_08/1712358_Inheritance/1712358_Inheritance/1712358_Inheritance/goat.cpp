#include "goat.h"

Goat::Goat()
{
	InstanceCount++;
}
Goat::~Goat()
{
	InstanceCount--;
}
int Goat::HaveBaby()
{
	return 1 + rand() % 5;
}
int Goat::GiveMilk()
{
	return rand() % 11;
}
void Goat::MakeSound()
{
	cout << "Eee..eee.." << endl;
}