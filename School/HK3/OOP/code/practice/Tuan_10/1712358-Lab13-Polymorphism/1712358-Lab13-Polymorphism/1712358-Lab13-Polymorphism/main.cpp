#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "ProductEmployee.h"
#include"DailyEmployee.h"
#include "Manage.h"

using namespace std;

#define FileNameOfData "data.txt"
void InitialData(vector<Employee*> &a);

int main()
{
	vector<Employee*> a;
	InitialData(a);
	cout << "The salary of all employees: " << endl << endl;
	cout << setw(18) << left << "Name" << setw(10) << left << "Position" << setw(12) << right << "Salary";
	cout << setw(12) << right << "Bonus" << setw(12) << right << "Penalty" << setw(12) << right << "Total" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << endl;
		cout << setw(18) << left << a[i]->FullName();
		cout << setw(10) << left << a[i]->Position();
		cout << setw(12) << right << a[i]->CalcSalary();
		cout << setw(12) << right << a[i]->CalsBonus();
		cout << setw(12) << right << a[i]->CalsPenalty();
		cout << setw(12) << right << a[i]->TotalSalary() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
void InitialData(vector<Employee*> &a)
{
	ifstream file(FileNameOfData);
	int type;
	int N;
	file >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		int price_or_base, count_or_factor;
		file.seekg(2, ios::cur);
		getline(file, name);
		file >> type >> price_or_base >> count_or_factor;
		switch (type)
		{
		case 1:
		{
			ProductEmployee *p = new ProductEmployee(name, price_or_base, count_or_factor);
			a.push_back(p);
			break;
		}
		case 2:
		{
			DailyEmployee *p = new DailyEmployee(name, price_or_base, count_or_factor);
			a.push_back(p);
			break;
		}
		case 3:
		{
			Manage *p = new Manage(name, price_or_base, count_or_factor);
			a.push_back(p);
			break;
		}
		}
	}
	file.close();
}