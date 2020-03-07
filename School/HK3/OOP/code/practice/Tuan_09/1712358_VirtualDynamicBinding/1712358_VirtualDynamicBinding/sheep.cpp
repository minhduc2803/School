#include "sheep.h"

Sheep::Sheep()
{
	InstanceCount++;
}
Sheep* Sheep::Clone()
{
	return new Sheep;
}
Sheep::~Sheep()
{
	InstanceCount--;
}
int Sheep::HaveBaby()
{
	return 1 + rand() % 5;
}
int Sheep::GiveMilk()
{
	return rand() % 6;
}
void Sheep::MakeSound()
{
	cout << "Baa..baa.." << endl;
}