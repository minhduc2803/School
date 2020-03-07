#include "Manage.h"

Manage::Manage(string fullname, int base, int factor) : Employee(fullname){
	BaseSalary = base;
	SalaryFactor = factor;
}

string Manage::Position()
{
	return "Manage";
}
int Manage::CalcSalary()
{
	return BaseSalary*SalaryFactor;
}
int Manage::CalsBonus()
{
	return 0;
}
int Manage::CalsPenalty()
{
	return 0;
}
int Manage::TotalSalary()
{
	return CalcSalary() + CalsBonus() - CalsPenalty();
}