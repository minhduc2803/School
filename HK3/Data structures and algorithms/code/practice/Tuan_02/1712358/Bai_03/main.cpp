#include "InOut.h"
#include "sortfunction.h"

int main()
{
	int const N = 300000;
	int *A = new int[N];
	input(A, N);

	cout << "Initializing an array with " << N << "  elements..." << endl << endl;

	test_sort(A, N);

	system("pause");
	return 0;
}