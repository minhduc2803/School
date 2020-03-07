#include "date.h"

Date::Date()
{
	time_t now = time(0);
	tm *t = localtime(&now);
	day = t->tm_mday;
	month = 1 + t->tm_mon;
	year = 1900 + t->tm_year;
	InstanceCount++;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	InstanceCount++;
}
Date::Date(const Date& s)
{
	day = s.day;
	month = s.month;
	year = s.year;
	InstanceCount++;
}
int Date::MaxDayInMonth(int m, int y)
{
	switch (m)
	{
	case 4: case 6: case 9: case 11: 
		return 30;
	case 2: 
		if (IsLeapYear(y))
			return 29;
		else
			return 28;
	default:
		return 31;
	}
}
bool Date::IsValid(int d,int m,int y)
{
	if (y >= 0 && m >= 0 && m <= 12 && d >= 0 && d <= MaxDayInMonth(m, y))
		return true;
	else
		return false;
}
bool Date::IsLeapYear(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return true;
	else
		return false;
}
string Date::ToString() const
{
	stringstream fs;
	fs << day << ":" << month << ":" << year;
	return fs.str();
}
istream& operator >> (istream& in, Date *D)
{
	int d, m, y;
	while (1)
	{
		in >> d >> m >> y;
		if (!(Date::IsValid(d, m, y)))
			cout << "The date is not valid, please try again" << endl;
		else
			break;
	}
	D->day = d;
	D->month = m;
	D->year = y;
	return in;
}
ostream& operator << (ostream& out, const Date *d)
{
	return out << d->ToString();
}