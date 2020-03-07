#include "fraction.h"

int Fraction::GreatestCommonDivisor(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	else
	{
		if (a >= b)
			return GreatestCommonDivisor(b, a%b);
		else
			return GreatestCommonDivisor(a, b%a);
	}
}
const float Fraction::X()
{
	return x;
}
const float Fraction::Y()
{
	return y;
}
void Fraction::setX(const float value)
{
	x = value;
}
void Fraction::setY(const float value)
{
	y = value;
}

Fraction::Fraction()
{
	x = Random::Next();
	y = Random::Next();
}
Fraction::Fraction(const float a, const float b)
{
	x = a;
	y = b;
}
Fraction::Fraction(Fraction* A)
{
	x = A->X();
	y = A->Y();
}
Fraction::Fraction(const Fraction& A)
{
	x = A.x;
	y = A.y;
}
Fraction::~Fraction()
{

}

string Fraction::ToString() const
{
	stringstream fs;
	fs << x << "/" << y;
	return fs.str();
}
Fraction& Fraction::inverse()
{
	Fraction *B = new Fraction(this->Y(), this->X());
	return *B;
}
Fraction& Fraction::Simplify()
{
	int CD = this->GreatestCommonDivisor(this->X(), this->Y());
	Fraction *B = new Fraction(this->X() / CD, this->Y() / CD);
	return *B;
}
istream& operator >> (istream& in, Fraction *A)
{
	float x, y;
	in >> x >> y;
	A->x = x;
	A->y = y;
	return in;
}
ostream& operator << (ostream& out, const Fraction *A)
{
	return out << A->ToString();
}