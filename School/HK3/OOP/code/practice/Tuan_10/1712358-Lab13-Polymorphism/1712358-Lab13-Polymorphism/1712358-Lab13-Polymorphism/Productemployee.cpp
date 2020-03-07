#include "ProductEmployee.h"

ProductEmployee::ProductEmployee(string fullname, int price, int count) : Employee(fullname){
	ProductPrice = price;
	ProductCount = count;
}

string ProductEmployee::Position()
{
	return "Product";
}
int ProductEmployee::CalcSalary()
{
	return ProductPrice*ProductCount;
}
int ProductEmployee::CalsBonus()
{
	if (ProductCount > 100)
		return (ProductCount - 100) * 500;
	else
		return 0;
}
int ProductEmployee::CalsPenalty()
{
	if (ProductCount < 100)
		return (100 - ProductCount) * 600;
	else
		return 0;
}
int ProductEmployee::TotalSalary()
{
	return CalcSalary() + CalsBonus() - CalsPenalty();
}