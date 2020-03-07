#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>

using namespace std;

class Student {
	string firstname, midname, lastname;
public:
	static int InstanceCount;
public:
	Student();
	Student(string, string, string);
	Student(Student*);
	~Student();
	string ToString() const;

	friend istream& operator >> (istream& in, Student *A);
	friend ostream& operator << (ostream& out, const Student *A);
};

#endif
