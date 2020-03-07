#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <cmath>
#include <sstream>
#include "Random.h"

using namespace std;

class Fraction{
private:
	float x, y;
private:
	int GreatestCommonDivisor(int a, int b);
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
	Fraction& inverse();
	Fraction& Simplify();

	friend istream& operator >> (istream& in, Fraction *A);
	friend ostream& operator << (ostream& out, const Fraction *A);
};

#endif