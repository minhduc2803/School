#include "DailyEmployee.h"

DailyEmployee::DailyEmployee(string fullname, int price, int count) : Employee(fullname){
	DailyPrice = price;
	Daycount = count;
}

string DailyEmployee::Position()
{
	return "Daily";
}
int DailyEmployee::CalcSalary()
{
	return DailyPrice*Daycount;
}
int DailyEmployee::CalsBonus()
{
	if (Daycount > 20)
		return (Daycount - 20) * 100000;
	else
		return 0;
}
int DailyEmployee::CalsPenalty()
{
	if (Daycount < 15)
		return (15 - Daycount) * 150000;
	else
		return 0;
}
int DailyEmployee::TotalSalary()
{
	return CalcSalary() + CalsBonus() - CalsPenalty();
}