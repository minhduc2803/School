#include "time.h"

Time::Time()
{
	time_t t = time(0);
	tm* n = localtime(&t);
	hour = n->tm_hour;
	minute = n->tm_min;
	second = n->tm_sec;
	cout << "Time constructor" << endl;
}
Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
	cout << "Time constructor" << endl;
}
Time::Time(const Time& t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
	cout << "Time constructor" << endl;
}
Time::~Time()
{
	cout << "Time destructor" << endl;
}
bool Time::IsValid(int h, int m, int s)
{
	if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
		return true;
	else
		return false;
}
string Time::ToString() const
{
	stringstream fs;
	fs << hour << ":" << minute << ":" << second;
	return fs.str();
}
istream& operator >> (istream& in, Time *t)
{
	int h, m, s;
	while(1)
	{
		in >> h >> m >> s;
		if (!(Time::IsValid(h, m, s)))
			cout << "The time is not valid, please try again" << endl;
		else
			break;
	}
	t->hour = h;
	t->minute = m;
	t->second = s;
	return in;
}
ostream& operator << (ostream& out, const Time *t)
{
	return out << t->ToString();
}