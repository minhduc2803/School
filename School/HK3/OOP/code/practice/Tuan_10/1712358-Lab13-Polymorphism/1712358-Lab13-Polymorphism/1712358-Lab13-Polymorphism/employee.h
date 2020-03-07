#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

using namespace std;

class Employee{
private:
	string fullname;
public:
	string FullName(){ return fullname; }
	void SetFullName(string value){ fullname = value; }
public:
	Employee(string value){ fullname = value; }
	virtual string Position() = 0;
	virtual int CalcSalary() = 0;
	virtual int CalsBonus() = 0;
	virtual int CalsPenalty() = 0;
	virtual int TotalSalary() = 0;
};

#endif