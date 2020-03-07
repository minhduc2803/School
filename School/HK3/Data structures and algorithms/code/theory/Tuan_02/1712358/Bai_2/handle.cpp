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
bool find_same_value(int A[], int N)
{
	bool flag = false;
	bool *B = new bool[N];
	memset(B, true, sizeof(bool));
	for (int i = 0; i < N - 1; ++i)
	{
		if (B[i])
		{
			bool first_same = false;
			for (int j = i + 1; j < N; ++j)
			{
				if (A[i] == A[j])
				{
					if (!first_same)
						cout << endl << A[i] << " ";
					cout << A[i] << " ";
					B[j] = false;
					flag = true;
					first_same = true;
				}
			}
		}
	}
	return flag;
}
