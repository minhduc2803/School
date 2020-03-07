#include "Student.h"

Student::Student()
{

}
Student::Student(string first, string mid, string last)
{
	firstname = first;
	midname = mid;
	lastname = last;
	
}
Student::Student(Student* P)
{
	(*this) = *P;
}
Student::~Student()
{

}

string Student::name()
{
	return firstname + " " + midname + " " + lastname;
}