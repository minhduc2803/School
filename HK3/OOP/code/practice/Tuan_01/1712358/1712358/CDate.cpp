#include "CDate.h"

void CDate::InputDate()
{
	while(1)
	{
		cout << "the day: ";
		cin >> day;
		cout << "the month: ";
		cin >> month;
		cout << "the year: ";
		cin >> year;
		if (!CheckDate())
			cout << "The day is not valid, please try again" << endl;
		else
			break;
	}
}
void CDate::OutputDate()
{
	cout << day << "/" << month << "/" << year;
}
bool CDate::CheckDate()
{
	if (year != 0 && month >= 1 && month <= 12 && day >= 1 && day <= MaxDayInMonth())
		return true;
	else
		return false;
}
bool CDate::InspectLeapYear()
{
	if (year > 0)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return true;
	}
	else
	{
		int y = year + 1;
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			return true;
	}
		return false;
}
CDate CDate::IncreaseYear()
{
	year++;
	if (year == 0)
		year++;
	return *this;
}
CDate CDate::IncreaseMonth()
{
	month++;
	if (month > 12)
	{
		month = 1;
		year++;
	}
	return *this;
}
CDate CDate::IncreaseDay()
{
	day++;
	if (day > MaxDayInMonth())
	{
		day = 1;
		IncreaseMonth();
	}
	return *this;
}
CDate CDate::DecreaseYear()
{
	year--;
	if (year == 0)
		year--;
	return *this;
}
CDate CDate::DecreaseMonth()
{
	month--;
	if (month < 1)
	{
		month = 12;
		DecreaseYear();
	}

	int MaxDay = MaxDayInMonth();
	if (day > MaxDay)
		day = MaxDay;
	return *this;
}
CDate CDate::DecreaseDay()
{
	day--;
	if (day < 1)
	{
		DecreaseMonth();
		day = MaxDayInMonth();
	}
	return *this;
}
CDate CDate::IncreaseYear(int n)
{
	if (year + n >= 0)
		year += n + 1;
	else
		year += n;
	return *this;
}
CDate CDate::IncreaseMonth(int n)
{
	int MaxMonth = (n + month) % 12;
	int MaxYear = (n - 1) / 12;
	month = MaxMonth % 12 == 0 ? 12 : MaxMonth;
	IncreaseYear(MaxYear);
	int MaxDay = MaxDayInMonth();
	if (day > MaxDayInMonth())
		day = MaxDay;
	return *this;
}
CDate CDate::IncreaseDay(int n)
{
	int d = day + n;
	int max = MaxDayInMonth();
	while (d > max)
	{
		IncreaseMonth();
		d -= max;
		max = MaxDayInMonth();
	}
	day = d;
	return *this;
}
CDate CDate::DecreaseYear(int n)
{
	if (year - n <= 0)
		year -= n + 1;
	else
		year -= n;
	return *this;
}
CDate CDate::DecreaseMonth(int n)
{
	int m = month - n;
	if (m > 0)
		month = m;
	else
	{
		m = -m;
		int y = m / 12 + 1;
		month = 12 - m % 12;
		DecreaseYear(y);
		int MaxDay = MaxDayInMonth();
		if (day > MaxDayInMonth())
			day = MaxDay;
	}
	return *this;
}
CDate CDate::DecreaseDay(int n)
{
	int d = day - n;
	if (d > 0)
		day = d;
	else
	{
		d = -d;
		DecreaseMonth();
		int max = MaxDayInMonth();
		while (d >= max)
		{
			d -= max;
			DecreaseMonth();
			max = MaxDayInMonth();
		}
		day = max - d;
	}
	return *this;
}
int CDate::DayOrderInYear()
{
	int number = day;
	int maxday[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	maxday[2 - 1] += InspectLeapYear() ? 1 : 0;
	for (int i = 1; i < month; i++)
		number += maxday[i - 1];
	return number;
}
int CDate::WeekOrderInYear()
{
	int NumberOfDay = DayOrderInYear();
	return NumberOfDay / 7 + 1;
}
string CDate::ConvertDate()
{
	char SD[10], SY[10];
	itoa(day, SD, 10);
	itoa(year, SY, 10);

	string SDay = string(SD);
	string SYear = string(SY);

	string SMonth;
	switch (month)
	{
	case 1:
		 SMonth = "January"; break;
	case 2:
		SMonth = "February"; break;
	case 3:
		SMonth = "March"; break;
	case 4:
		SMonth = "April"; break;
	case 5:
		SMonth = "May"; break;
	case 6:
		SMonth = "June"; break;
	case 7:
		SMonth = "July"; break;
	case 8:
		SMonth = "August"; break;
	case 9:
		SMonth = "September"; break;
	case 10:
		SMonth = "October"; break;
	case 11:
		SMonth = "November"; break;
	case 12:
		SMonth = "December"; break;
	}

	string ss = SMonth + " " + SDay + ", " + SYear;
	return ss;
}
int CDate::DeductDatetoDate(CDate P)
{
	int result = 0;
	CDate Init = *this;

	bool bigger = (year > P.year) || ((year == P.year) && (month > P.month ||( month == P.month && day >= P.day)));

	if (bigger)
	{
		*this = P;
		P = Init;
	}

	int n = P.month - month + 12 * (P.year - year);
	if (n == 0)
		result += P.day - day;
	else
		result += P.day + MaxDayInMonth() - day;
	for (int i = 1; i < n; i++)
	{
		IncreaseMonth();
		result += MaxDayInMonth();
	}
	*this = Init;
	return result;
}
int CDate::MaxDayInMonth()
{
	int maxday[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	maxday[2 - 1] += InspectLeapYear() ? 1 : 0;
	return maxday[month - 1];
}
bool CDate::operator > (CDate P)
{
	return (year > P.year) || ((year == P.year) && (month > P.month || (month == P.month && day >= P.day)));
}