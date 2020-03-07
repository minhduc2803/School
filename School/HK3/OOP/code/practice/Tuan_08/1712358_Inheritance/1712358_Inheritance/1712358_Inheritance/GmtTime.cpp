#include "GmtTime.h"

GmtTime::GmtTime()
{
	time_t t = time(0);
	tm* n = localtime(&t);
	hour = n->tm_hour;
	minute = n->tm_min;
	second = n->tm_sec;
	cout << "GmtTime constructor" << endl;
}
GmtTime::GmtTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
	cout << "GmtTime constructor" << endl;
}
GmtTime::GmtTime(const GmtTime& t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
	cout << "GmtTime constructor" << endl;
}
GmtTime::~GmtTime()
{
	cout << "GmtTime destructor" << endl;
}
string GmtTime::ToString(int m)
{
	int temp = hour;
	hour = (hour + m) % 24;
	
	stringstream fs;
	fs << hour << ":" << minute << ":" << second;
	hour = temp;

	return fs.str();
}