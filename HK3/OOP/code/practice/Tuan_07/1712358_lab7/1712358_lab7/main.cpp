#include <iostream>
#include <vector>
#include <ctime>
#include "fraction.h"
#include "Random.h"
#include "DynamicArray.h"

using namespace std;

void practice_01();
void practice_02();
void practice_03();

int main()
{
	cout << "Testing vector and exception" << endl;
	cout << "Initialize an integer n <= 10 and then initialize A with n elements" << endl;
	cout << "And then Initialize an integer m and access to A[m]" << endl;
	practice_01();
	practice_02();
	practice_03();

	system("pause");
	return 0;
}

void practice_01()
{
	Random::Reset();
	cout << endl << "1. Vector of integers" << endl;
	int n = Random::Next(10);
	vector<int> A;
	for (int i = 0; i < n; i++)
	{
		A.push_back(Random::Next());
	}
	cout << "n = " << n << endl << "A: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	int m = Random::Next(10);
	cout << endl << "m = " << m << endl;
	try {
		if (m >= A.size())
			throw "Index out of bound";
		else
			cout << "A[" << m << "] = " << A[m] << endl;
	}
	catch (const char* mess)
	{
		cout << mess << endl;
	}
}
void practice_02()
{
	//Random::Reset();
	cout << endl << "2. Vector of fractions" << endl;
	int n = Random::Next(10);
	vector<Fraction> A;
	for (int i = 0; i < n; i++)
	{
		A.push_back(new Fraction());
	}
	cout << "n = " << n << endl << "A: ";
	for (int i = 0; i < n; i++)
		cout << &A[i] << " ";
	int m = Random::Next(10);
	cout << endl << "m = " << m << endl;
	try {
		if (m >= A.size())
			throw "Index out of bound";
		else
		{
			cout << "A[" << m << "] =  " << &A[m] << " simplify " << &(A[m].Simplify()) << endl;
			cout << "inverse " << &(A[m].inverse()) << " simplify " << &((A[m].inverse()).Simplify()) << endl;
		}
	}
	catch (const char* mess)
	{
		cout << mess << endl;
	}
}
void practice_03()
{
	//Random::Reset();
	cout << endl << "3. Dyanmic array" << endl;
	int n = Random::Next(10);
	DynamicArray A;
	for (int i = 0; i < n; i++)
	{
		A.PushBack(Random::Next());
	}
	cout << "n = " << n << endl << "A: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	int m = Random::Next(10);
	cout << endl << "m = " << m << endl;
	A.GetAt(m);
}