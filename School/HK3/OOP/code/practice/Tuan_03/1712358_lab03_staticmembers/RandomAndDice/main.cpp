#include "Random.h"
#include "Dice.h"
#include <iostream>
using namespace std;

int main()
{
	Random A;
	cout << "Test class Random, object A" << endl;
	cout << "After 3 times call the function A.Next(): ";
	cout << A.Next() << " " << A.Next() << " " << A.Next() << endl;
	int max;
	cout << "The function Next(int max) can return the random value from 0 to max-1" << endl;
	cout << "Enter the positive value max ";
	while(1)
	{
		cin >> max;
		if (max <= 0)
			cout << "max must be greater than 0, please try again" << endl;
		else
			break;
	}
	cout << "After 3 times call the function A.Next(max)" << endl;
	cout << A.Next(max) << " " << A.Next(max) << " " << A.Next(max) << endl;

	cout << endl << "Test class Dice, 3 object D1, D2, D3" << endl;
	Dice D1, D2, D3;

	cout << "Rolling..." << endl;
	cout << "D1: " << D1.Roll() << endl;
	cout << "D2: " << D2.Roll() << endl;
	cout << "D3: " << D3.Roll() << endl;
	cout << "D2: " << D2.Roll() << endl;
	cout << "D3: " << D3.Roll() << endl;
	cout << "D3: " << D3.Roll() << endl;
	cout << "D1: " << D1.Roll() << endl;
	cout << "D2: " << D2.Roll() << endl;
	cout << "D3: " << D3.Roll() << endl;

	cout << endl << "Total rolling times" << endl;
	cout << "D1: " << D1.RollCount << endl;
	cout << "D2: " << D2.RollCount << endl;
	cout << "D3: " << D3.RollCount << endl;

	system("pause");
	return 0;
}