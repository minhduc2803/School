#include "car.h"
#include "carbriolet.h"
#include "time.h"
#include "GmtTime.h"
#include "cow.h"
#include "goat.h"
#include "sheep.h"

void problem_1();
void problem_2();
void problem_3();

int Animal::InstanceCount = 0;
int Cow::InstanceCount = 0;
int Sheep::InstanceCount = 0;
int Goat::InstanceCount = 0;
int main()
{
	problem_1();
	problem_2();
	problem_3();
	
	system("pause");
	return 0;
}

void problem_1()
{
	cout << "1." << endl;
	Carbriolet A;
	cout << endl;
	A.StartEngine();
	cout << endl;
	//A.~Carbriolet();
}
void problem_2()
{
	cout << endl << "2. " << endl;
	GmtTime t;
	cout << endl << "GMT+5: " << t.ToString(5) << endl;
	cout << "GMT+7: " << t.ToString(7) << endl << endl;
	//t.~GmtTime();
}

void problem_3()
{
	cout << endl << endl << "3." << endl;
	srand(time(0));
	int n = rand() % 6 + 5; // 5 <= n <= 10 the total of animal
	vector<Animal*> Farm;
	for(int i=0;i<n;i++)
	{
		int type = rand() % 3; 
		//type = 0 add a cow to a farm, type = 1 add a sheep, type = 2 add a goat
		switch (type)
		{
		case 0:
		{
			Cow *C = new Cow;
			Farm.push_back(C);
			break;
			break;
		}
		case 1:
		{
			Sheep *S = new Sheep;
			Farm.push_back(S);
			break;
		}
		case 2:
		{
			Goat *G = new Goat;
			Farm.push_back(G);
			break;
		}
		}
	}

	cout << "Animal was sounding" << endl;
	for (int i = 0; i < Farm.size(); i++)
	{
		Farm[i]->MakeSound();
	}
	cout << endl << "Total of animal: " << n << endl;
	cout << "Cow: " << Cow::InstanceCount << endl;
	cout << "Sheep: " << Sheep::InstanceCount << endl;
	cout << "Goat: " << Goat::InstanceCount << endl;
	
}
