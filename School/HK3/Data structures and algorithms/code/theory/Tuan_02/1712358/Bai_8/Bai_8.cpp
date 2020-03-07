#include "handle.h"

int main()
{
	int N, k, *A;
	input(N);
	A = new int[N];
	input(A, N);
	output(A, N);
	if (!test_sorted(A, N))
		cout << "The array is not arranged ascending so we cannot use binary search algorithm" << endl;
	else
	{
		cout << "Enter the number you want to search" << endl;
		cin >> k;
		int pos = binary_search(A, N, k);
		if (pos < 0)
			cout << "The array does not have the number " << k << endl;
		else
			cout << "The number " << k << " is the element number " << pos+1 << " in the array" << endl;
	}


}