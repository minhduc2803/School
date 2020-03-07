#ifndef _PRODUCTEMPLOYEE_H_
#define _PRODUCTEMPLOYEE_H_

#include "employee.h"

using namespace std;

class ProductEmployee: public Employee{
private:
	int ProductPrice, ProductCount;
public:
	ProductEmployee(string fullname, int price, int count);
	string Position();
	int CalcSalary();
	int CalsBonus();
	int CalsPenalty();
	int TotalSalary();
};

#endif