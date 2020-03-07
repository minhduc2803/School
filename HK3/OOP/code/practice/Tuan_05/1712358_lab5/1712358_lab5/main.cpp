#include "Point.h"
#include "LineV3.h"
#include "Triangle.h"
#include "RectangleV3.h"
#include "Circle.h"
#include "DynamicArray.h"
#include "fraction.h"
#include "Student.h"
#include "date.h"
#include "time.h"

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Triangle::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int Circle::InstanceCount = 0;
int Fraction::InstanceCount = 0;
int Student::InstanceCount = 0;
int DynamicArray::InstanceCount = 0;
int Time::InstanceCount = 0;
int Date::InstanceCount = 0;

int main()
{
	cout << "Test classes with ToString function and in out operator";

	cout << endl << endl << "Line class" << endl;
	Line *P = new Line;
	cout << "Enter 2 points for the start and end point of the line P" << endl;
	cin >> P;
	cout << "P: " << P;
	delete P;

	cout << endl << endl << "Rectangle class" << endl;
	Rectangle *H = new Rectangle;
	cout << "Enter 2 points for the top left and bottom right point of the rectangle H" << endl;
	cin >> H;
	cout << "H: " << H;
	delete H;

	cout << endl << endl << "Triangle class" << endl;
	Triangle *K = new Triangle;
	cout << "Enter 3 points for the triangle K" << endl;
	cin >> K;
	cout << "K: " << K;
	delete K;

	cout << endl << endl << "Circle class" << endl;
	Circle *C = new Circle;
	cout << "Enter 1 point for the center and 1 real number for the radius of the circle C" << endl;
	cin >> C;
	cout << "C: " << C;
	delete C;

	cout << endl << endl << "Fraction class" << endl;
	Fraction *F = new Fraction;
	cout << "Enter 2 real number for the fraction F" << endl;
	cin >> F;
	cout << "F: " << F;
	delete F;

	cout << endl << endl << "Student class" << endl;
	Student *S = new Student;
	cout << "Enter 3 string for last name, middle name and first name of the student S" << endl;
	cin >> S;
	cout << "S: " << S;
	delete S;

	cout << endl << endl << "DynamicArray class" << endl;
	DynamicArray *A = new DynamicArray;
	cout << "Enter the Dynamic Array A" << endl;
	cin >> A;
	cout << "A: " << A;
	delete A;

	cout << endl << endl << "Time class (The IsValid() function is tested in the >> operator)" << endl;
	Time *T = new Time;
	cout << "Enter natural number for hour, minute and second of the time T" << endl;
	cin >> T;
	cout << "T: " << T;
	delete T;

	cout << endl << endl << "Date class (The IsValid() function is tested in the >> operator)" << endl;
	Date *D = new Date;
	cout << "The current day: " << D << endl;
	cout << "Enter natural number for day, month and year of the date D" << endl;
	cin >> D;
	cout << "D: " << D;
	delete D;

	system("pause");
	return 0;
}