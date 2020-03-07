#include "Student.h"

Student::Student()
{
	InstanceCount++;
}
Student::Student(string first, string mid, string last)
{
	firstname = first;
	midname = mid;
	lastname = last;
	InstanceCount++;
}
Student::Student(Student* P)
{
	(*this) = *P;
	InstanceCount++;
}
Student::~Student()
{

}
string Student::ToString() const
{
	return lastname + " " + midname + " " + firstname;
}
istream& operator >> (istream& in, Student *A)
{
	return in >> A->lastname >> A->midname >> A->firstname;
}
ostream& operator << (ostream& out, const Student *A)
{
	return out << A->ToString();
}