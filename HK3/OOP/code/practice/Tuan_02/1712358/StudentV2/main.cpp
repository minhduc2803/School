#include "Student.h"

int main()
{
	cout << "Test class Student" << endl;
	Student *P = new Student("Nguyen","Minh","Duc");
	cout << "My full name is " << P->name() << endl << endl;

	cout << "Heyyy, welcome to my program" << endl;
	cout << "My program can guess exactly your name with inputting your full name" << endl;
	cout << "What are you waiting for?" << endl;

	string first, mid, last;
	cout << "Now enter your first name ";
	cin >> first;
	cout << "Your middle name: ";
	cin >> mid;
	cout << "And your last name please: ";
	cin >> last;
	Student *A = new Student(first, mid, last);
	cout << "...guessing..." << endl;
	cout << "BOOM" << endl;
	cout << A->name() << endl;
	cout << "See" << endl << "Is that your name? kakakaka ^^ magic" << endl;
	return 0;
}