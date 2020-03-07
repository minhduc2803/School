#include "search.h"
#include<ctime>
int main()
{
	srand(time(NULL));
	int N = 100000000;
	int *A = new int[N];
	cout << "wating..." << endl;
	for (int i = 0; i < N; i++)
	{
		A[i] = rand();
	}
	//output(A, N);

	int value;
	cout << "We have up here the array having 1000000 items" << endl;
	cout << "Enter the value that you want to search in the array" << endl;
	cin >> value;

	cout << "RESULT" << endl;

	int start = clock();
	cout << endl << "-sequentialSearch: " << endl;
	int position = sequentialSearch(A, N, value);
	if (position != -1)
		cout << "The value is in the position number " << position << " in the array" << endl;
	else
		cout << "The value is not in the array" << endl;
	cout << "Total calculating time: " << clock() - start << " miliseconds" << endl << endl;

	start = clock();
	int start1 = start;
	cout << "-binarySearch: ";
	cout << endl << endl << "Sorting... ";
	qsort(A, N, sizeof(int), compare);
	cout << "(calculating time: " << clock() - start << " miliseconds)" << endl;
	start = clock();
	cout << endl << "Searching: " << endl;
	position = binarySearch(A, N, value);
	if (position != -1)
		cout << "The value is in the position number " << position << " in the array" << endl;
	else
		cout << "The value is not in the array" << endl;
	cout << "(calculating time: " << clock() - start << " miliseconds)" << endl << endl;
}