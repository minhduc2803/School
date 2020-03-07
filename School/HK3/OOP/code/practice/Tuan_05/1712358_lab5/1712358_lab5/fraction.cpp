#include "fraction.h"

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
	x = 0;
	y = 0;
	InstanceCount++;
}
Fraction::Fraction(const float a, const float b)
{
	x = a;
	y = b;
	InstanceCount++;
}
Fraction::Fraction(Fraction* A)
{
	x = A->X();
	y = A->Y();
	InstanceCount++;
}
Fraction::Fraction(const Fraction& A)
{
	x = A.x;
	y = A.y;
	InstanceCount++;
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