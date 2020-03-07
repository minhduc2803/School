#include "HANDLE.h"

int main()
{
	ARRAY P;
	input(P);
	output(P);
	printf("\nThe size of the array is %d", get_size(P));
	printf("\nPlease input the position you want to get the value: ");
	int position, x;
	while (1)
	{
		scanf_s("%d", &position);
		if (position <= 0 || position >= P.size)
			printf("The position must be greater than 0 and smaller than the size\nPlease try again ");
		else
			break;
	}
	printf("The value at the position number %d is %d", position, get_value(P, position));
	printf("\nPlease input the number x that you want to find in the array\n");
	scanf_s("%d", &x);
	if (find_x(P, x, position))
	{
		printf("We found x in the position number %d\n", position);
	}
	else
		printf("The array does not have %d\n", x);
	printf("The array after sorting up ascending\n");
	sort_up_ascending(P);
	output(P);
	printf("\nThe array after sorting descending\n");
	sort_descending(P);
	output(P);
	return 0;
}