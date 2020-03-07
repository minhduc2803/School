#ifndef _CDATE_H_
#define _CDATE_H_

#include <iostream>
#include <string>

using namespace std;

class CDate {
	int year, month, day;
public:
	void InputDate();
	void OutputDate();
	bool CheckDate();
	bool InspectLeapYear();
	CDate IncreaseYear();
	CDate IncreaseMonth();
	CDate IncreaseDay();
	CDate DecreaseYear();
	CDate DecreaseMonth();
	CDate DecreaseDay();
	CDate IncreaseYear(int);
	CDate IncreaseMonth(int);
	CDate IncreaseDay(int);
	CDate DecreaseYear(int);
	CDate DecreaseMonth(int);
	CDate DecreaseDay(int);
	int DayOrderInYear();
	int WeekOrderInYear();
	string ConvertDate();
	int DeductDatetoDate(CDate P);
	int MaxDayInMonth();
	bool operator > (CDate P);
};

#endif
