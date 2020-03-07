#include <random>

#include "cow.h"
#include "goat.h"
#include "sheep.h"
#include "line.h"
#include "rectangle.h"
#include "elip.h"

void problem_1();
void problem_2();

int Animal::InstanceCount = 0;
int Cow::InstanceCount = 0;
int Sheep::InstanceCount = 0;
int Goat::InstanceCount = 0;
int main()
{
	problem_1();
	problem_2();

	system("pause");
	return 0;
}
void problem_1()
{
	cout << "1." << endl;
	srand(time(0));
	int n = rand() % 6 + 5; // 5 <= n <= 10 the total of animal
	vector<Animal*> Farm;
	for (int i = 0; i<n; i++)
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

	cout << "The animal was sounding" << endl;
	for (int i = 0; i < Farm.size(); i++)
	{
		Farm[i]->MakeSound();
	}
	cout << endl << "Total of the animal: " << Animal::InstanceCount << endl;
	cout << "Cow: " << Cow::InstanceCount << endl;
	cout << "Sheep: " << Sheep::InstanceCount << endl;
	cout << "Goat: " << Goat::InstanceCount << endl;

	int total_milk = 0;
	for (int i = 0; i < n; i++)
	{
		total_milk += Farm[i]->GiveMilk();
	}
	cout << "Total milk " << total_milk << endl;

	cout << endl << "The farm after all animal are giving baby:" << endl;
	for (int i = 0; i < n; i++)
	{
		int baby = Farm[i]->HaveBaby();
		for (int j = 0; j < baby; j++)
		{
			Animal *p = Farm[i]->Clone();
			Farm.push_back(p);
		}
	}

	cout << endl << "Total of the animal: " << Animal::InstanceCount << endl;
	cout << "Cow: " << Cow::InstanceCount << endl;
	cout << "Sheep: " << Sheep::InstanceCount << endl;
	cout << "Goat: " << Goat::InstanceCount << endl;
}
void problem_2()
{
	cout << endl << endl << "2." << endl;
	int n = rand() % 6 + 5; // 5 <= n <= 10 the total of figures
	vector<Figure*> List;
	for (int i = 0; i<n; i++)
	{
		int type = rand() % 3;
		//type = 0 add a line to the list, type = 1 add a rectangle, type = 2 add an elip
		switch (type)
		{
		case 0:
		{
			Line *L = new Line;
			List.push_back(L);
			break;
		}
		case 1:
		{
			Rectangle *R = new Rectangle;
			List.push_back(R);
			break;
		}
		case 2:
		{
			Elip *E = new Elip;
			List.push_back(E);
			break;
		}
		}
	}

	cout << "Total of figures: " << n << endl;
	for (int i = 0; i < n; i++)
		List[i]->Draw();
}
