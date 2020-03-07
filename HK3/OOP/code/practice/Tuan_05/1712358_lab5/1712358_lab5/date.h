#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

class Date {
	int day, month, year;
public:
	static int InstanceCount;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	static int MaxDayInMonth(int, int);
	static bool IsValid(int,int,int);
	static bool IsLeapYear(int);

	string ToString() const;

	friend istream& operator >> (istream& in, Date *D);
	friend ostream& operator << (ostream& out, const Date *d);
};
#endif
