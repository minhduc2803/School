#include "handle.h"

void input(int& N)
{
	cout << "Enter number of the elements: ";
	while (1)
	{
		cin >> N;
		if (N <= 0)
			cout << "N must be greater than 0, try again" << endl;
		else
			break;
	}
}
void input(int A[], int N)
{
	cout << "Enter " << N << " elements:" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}
}
void output(int A[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void the_most_frequently(int A[], int N)
{
	bool *B = new bool[N];
	memset(B, true, sizeof(bool));
	int repeat = 1, key = A[0];
	for (int i = 0; i < N - 1; ++i)
	{
		if (B[i])
		{
			int cur_repeat = 1;
			for (int j = i + 1; j < N; ++j)
			{
				if (A[j] == A[i])
				{
					cur_repeat++;
					B[j] = false;
				}
			}
			if (cur_repeat > repeat)
			{
				repeat = cur_repeat;
				key = A[i];
			}
		}
	}
	cout << key << " : " << repeat << " time(s)" << endl;
}
