#include <iostream>
#include <string>
#include <sstream> 
#include <random>

using namespace std;

int main()
{
	bool flag = false;

	while (!flag)
	{
		random_device rd;
		int id = 0; 
		id = rd() % 9999;		//random id

		for (int i = 1; i <= 10; ++i)
		{
			int numb = 1701725;
			int key = 2 * (id + 984) * (numb + (i - 1) * 2) - 1;		//tính key từ id
			int len = int(to_string(key).length());				

			if (len == i && key > 0)					//Nếu độ dài của key = i thì đúng
			{
				cout << "ID: " << id << '\n';
				cout << "Serial: " << key << '\n';
				flag = true;
				break;
			}
		}
	}
	
	cin.get();
	
	return 0;
}