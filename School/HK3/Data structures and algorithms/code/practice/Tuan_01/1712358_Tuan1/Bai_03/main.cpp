#include "handle.h"

#define max 1000000

int main()
{
	NODE ** hash;
	Init(hash, max);
	int key, data;
	
	cout << "Welcome, I have created a hash table. Do you want to test something? Here we go" << endl;
	cout << endl << "Testing insert function" << endl;
	cout << "Enter some key and data, enter 0 for key to finish inserting" << endl;

	while(1)
	{
		cout << endl << "key: ";
		cin >> key;
		cout << "data: ";
		cin >> data;
		insert(hash, max, key, data);
	}

	cout << endl << "Testing get function" << endl;
	cout << "Enter some key to get the data, enter 0 for key to finish getting" << endl;

	while(1)
	{
		cout << endl << endl << "key: ";
		cin >> key;
		if (get(hash, max, key, data))
			cout << "data: " << data;
		else
			cout << "data: not in hash table";
	}
	return 0;
}