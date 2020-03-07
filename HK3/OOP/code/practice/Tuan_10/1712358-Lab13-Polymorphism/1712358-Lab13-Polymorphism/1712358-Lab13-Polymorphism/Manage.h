#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "employee.h"

using namespace std;

class Manage: public Employee{
private:
	int BaseSalary, SalaryFactor;
public:
	Manage(string fullname, int base, int factor);
	string Position();
	int CalcSalary();
	int CalsBonus();
	int CalsPenalty();
	int TotalSalary();
};

#endif