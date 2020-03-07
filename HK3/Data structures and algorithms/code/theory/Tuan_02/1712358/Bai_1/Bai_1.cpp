#include "handle.h"

int main()
{
	int N, k, *A;
	input(N);
	A = new int[N];
	input(A, N);
	output(A, N);
	cout << "Enter the number that you want to search ";
	cin >> k;
	int temp = search(A, N, k);
	if (temp == -1)
		cout << "The array does not have the number " << k << endl;
	else
		cout << k << " is at the position number " << temp + 1 << " in the array" << endl;

}