#include "handle.h"

int main()
{
	int N;
	input(N);
	int *A = new int[N];
	input(A, N);
	output(A, N);
	int index_of_second = find_second(A, N);
	if (index_of_second < 0)
		cout << "The array having just 1 element cannot have the second largest element" << endl;
	else
		cout << "The index of the second largest element is " << index_of_second << endl;
}