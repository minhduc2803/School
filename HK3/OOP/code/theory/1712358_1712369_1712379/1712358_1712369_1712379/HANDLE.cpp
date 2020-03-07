#include "HANDLE.h"

void input(ARRAY& P)
{
	printf("Please input the number of elements of the array N: ");
	int N, x;
	while (1)
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N must be greater than 0, please try again\nN: ");
		else
			break;
	}
	P.size = N;
	printf("input %d elements\n", P.size);
	for (int i = 0; i < P.size; i++)
	{
		printf("element number %d: ", i);
		scanf_s("%d", &x);
		P.a[i] = x;
	}
}

void output(ARRAY P)
{
	for (int i = 0; i < P.size; i++)
	{
		printf("%d ", P.a[i]);
	}
}
int get_size(ARRAY P)
{
	return P.size;
}
int get_value(ARRAY P, int position)
{
	return P.a[position];
}
bool find_x(ARRAY P, int x, int& position)
{
	for (int i = 0; i < P.size; i++)
	{
		if (P.a[i] == x)
		{
			position = i;
			return true;
		}
	}
	return false;
}
void sort_up_ascending(ARRAY& P)
{
	for (int i = P.size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (P.a[j] > P.a[j + 1])
			{
				int temp = P.a[j];
				P.a[j] = P.a[j + 1];
				P.a[j + 1] = temp;
			}
		}
	}
}
void sort_descending(ARRAY& P)
{
	for (int i = P.size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (P.a[j] < P.a[j + 1])
			{
				int temp = P.a[j];
				P.a[j] = P.a[j + 1];
				P.a[j + 1] = temp;
			}
		}
	}
}