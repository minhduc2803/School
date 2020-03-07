#include "handle.h"

int main()
{
	int N, *A;
	input(N);
	A = new int[N];
	input(A, N);
	output(A, N);
	int k;
	cout << endl << "Enter k: ";
	cin >> k;
	sorting(A, N, k);
	output(A, N);
	system("pause");
	return 0;
}