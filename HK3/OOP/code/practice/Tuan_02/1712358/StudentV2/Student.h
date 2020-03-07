#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>

using namespace std;

class Student {
	string firstname, midname, lastname;
public:
	Student();
	Student(string, string, string);
	Student(Student*);
	~Student();
	string name();
};

#endif
