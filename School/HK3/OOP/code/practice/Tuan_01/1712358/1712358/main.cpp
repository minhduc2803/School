#include "CDate.h"

int main()
{
	CDate love, hate;
	cout << "Enter a day in year" << endl;
	love.InputDate();
	love.OutputDate();
	cout << " The loving day" << endl;
	cout << endl << "Enter an other day in year" << endl;
	hate.InputDate();
	love.OutputDate();
	cout << " The hating day" << endl;
	cout << endl << "Now, i'm going to do some magic to your days" << endl;
	cout << "Let's see" << endl;
	cout << "The loving day is the day number " << love.DayOrderInYear();
	cout << " and also in the week number " << love.WeekOrderInYear() << " in year" << endl;
	cout << "Hey listen!" << endl;
	if (love > hate)
	{
		cout << "You have to wait " << love.DeductDatetoDate(hate) << " day(s) that your hater becomes your lover" << endl;
	}
	else
	{
		cout << "You have " << love.DeductDatetoDate(hate) << " day(s) before your lover becomes your hater" << endl;
	}
	cout << "^-^";
	cout << endl << "Do you want to see your day with a little bit more nicer, here we go" << endl;
	cout << "The loving day: " << love.ConvertDate() << endl;
	cout << "The hating day: " << hate.ConvertDate() << endl;
	cout << "I can also move your day too" << endl;
	love.IncreaseDay();
	hate.DecreaseDay();
	cout << "if I increase your lover one day, The loving day: " << love.ConvertDate() << endl;
	cout << "if I decrease your hater one day, The hating day: " << hate.ConvertDate() << endl;
	cout << "I can do it to month and year too, but let see if i do it with more days moving" << endl;
	love.IncreaseDay(100);
	hate.DecreaseDay(111);
	cout << "if I increase your lover 100 days, the loving day: " << love.ConvertDate() << endl;
	cout << "if I decrease your hater 111 days, The hating day: " << hate.ConvertDate() << endl;
	system("pause");
	return 0;
}