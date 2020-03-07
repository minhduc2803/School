#ifndef _TIME_H_
#define _TIME_H_

#include <iostream>
#include <sstream>
using namespace std;

class Time
{
	int hour, minute, second;
public:
	static int InstanceCount;
public:
	Time();
	Time(int, int, int);
	Time(const Time&);
	static bool IsValid(int, int, int);
	string ToString() const;

	friend istream& operator >> (istream& in, Time *t);
	friend ostream& operator << (ostream& out, const Time *t);
};

#endif