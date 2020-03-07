#ifndef _DAILYEMPLOYEE_H_
#define _DAILYEMPLOYEE_H_

#include "employee.h"

using namespace std;

class DailyEmployee: public Employee{
private:
	int DailyPrice, Daycount;
public:
	DailyEmployee(string fullname, int price, int count);
	string Position();
	int CalcSalary();
	int CalsBonus();
	int CalsPenalty();
	int TotalSalary();
};

#endif