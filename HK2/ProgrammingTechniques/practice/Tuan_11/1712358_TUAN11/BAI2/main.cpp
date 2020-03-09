#include "ExhaustedSearch.h"
#include "FlagSearch.h"
#include "BinarySearch.h"
#include "INOUT.h"

int main()
{
	int *A, N;
	Input(N);
	A = (int*)malloc(sizeof(int)*N);
	Input(A, N);
	Output(A, N);
	
	printf("\n\nProblems\n"
		"1. Finding the last x in the array then return the position of x\n"
		"2. Finding the first prime number in the array then return the postion of the prime number\n"
		"3. Finding the minimum number in the array then return the value of the number\n"
		"4. Finding the maximum positive integer then return the number\n"
		"5. Finding the maximum prime number then return the value of the number\n"
		"6. Findng the minimum symmetry number in the array then return the value of the number\n"
		"Note: if the function cannot find any result, return -1");
	int stick;
	printf("\n\nPlease input a number to do the specific system functions\n");
	printf("1. Exhausted searching\n"
		"2. Exhausted searching with flags\n"
		"3. Binary searching\n");
	do
	{
		scanf_s("%d", &stick);
		if (stick != 1 && stick != 2 && stick != 3)
			printf("The number is not valid, try again: ");
		else
			break;
	} while (1);
	int x;
	printf("\nPlease input the value x for function number 1: ");
	scanf("%d", &x);
	printf("Result\n");
	switch (stick)
	{
	case 1:
		printf("1. %d\n", FindLast1(A, N, x));
		printf("2. %d\n", FindFirstPrime1(A,N));
		printf("3. %d\n", FindMin1(A, N));
		printf("4. %d\n", FindMaxPositive1(A, N));
		printf("5. %d\n", FindMaxPrime1(A, N));
		printf("6. %d\n", FindMinSymmetry1(A, N));
		break;
	case 2:
		printf("1. %d\n", FindLast2(A, N, x));
		printf("2. %d\n", FindFirstPrime2(A, N));
		printf("3. %d\n", FindMin2(A, N));
		printf("4. %d\n", FindMaxPositive2(A, N));
		printf("5. %d\n", FindMaxPrime2(A, N));
		printf("6. %d\n", FindMinSymmetry2(A, N));
		break;
	case 3:
		printf("The array has to be sorted before using the functions\n");
		Sorting(A, N);
		Output(A, N);
		printf("\n\n");
		printf("1. %d\n", FindLast3(A, N, x));
		printf("2. %d\n", FindFirstPrime3(A, N));
		printf("3. %d\n", FindMin3(A, N));
		printf("4. %d\n", FindMaxPositive3(A, N));
		printf("5. %d\n", FindMaxPrime3(A, N));
		printf("6. %d\n", FindMinSymmetry3(A, N));
		break;
	}
	return 0;
}