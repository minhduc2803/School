#include "handle.h"

int main()
{
	int N, k, *A;
	input(N);
	A = new int[N];
	input(A, N);
	output(A, N);
	cout << "The array has ";
	if (!find_same_value(A, N))
		cout << "no equal elements" << endl;
	else
		cout << endl << "are the equal elements" << endl;

}