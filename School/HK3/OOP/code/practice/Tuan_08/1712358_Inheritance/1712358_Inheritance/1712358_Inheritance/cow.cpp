#include "cow.h"

Cow::Cow()
{
	InstanceCount++;
}
Cow::~Cow()
{
	InstanceCount--;
}
int Cow::HaveBaby() 
{
	return 1 + rand() % 5;
}
int Cow::GiveMilk() 
{
	return rand() % 21;
}
void Cow::MakeSound() 
{
	cout << "Moo.." << endl;
}