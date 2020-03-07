#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Fraction{
public:
	static int InstanceCount;
private:
	float x, y;
public:
	const float X();
	const float Y();
	void setX(const float value);
	void setY(const float value);

	Fraction();
	Fraction(const float, const float);
	Fraction(Fraction*);
	Fraction(const Fraction&);
	~Fraction();

	string ToString() const;

	friend istream& operator >> (istream& in, Fraction *A);
	friend ostream& operator << (ostream& out, const Fraction *A);
};

#endif