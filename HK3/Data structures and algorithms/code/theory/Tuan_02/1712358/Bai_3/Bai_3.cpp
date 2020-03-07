#include "handle.h"

int main()
{
	int N, k, *A;
	input(N);
	A = new int[N];
	input(A, N);
	output(A, N);
	cout << "The most frequent number in the array is" << endl;
	the_most_frequently(A, N);

}