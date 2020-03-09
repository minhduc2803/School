#include "HANDLING.h"
#include "INOUT.h"
void main()
{
	LIST* L = (LIST*)malloc(sizeof(LIST));
	int N;
	printf("Please input the positive integer N: ");
	Input(N);

	Initialize(L);
	Input(L, N);
	printf("The list: ");
	Output(L);
//3.4.
	int x;
	//3.
	printf("\nPlease input the value x: ");
	scanf_s("%d", &x);
	int order = FindFirstX(L, x);
	if (order != -1)
		printf("3. The first x is the element number %d in the list\n", order);
	else
		printf("3. There is no x in the list\n");
	//4.
	printf("\nPlease input the value x: ");
	scanf_s("%d", &x);
	order = FindLastX(L, x);
	if (order != -1)
		printf("4. The last x is the element number %d in the list\n", order);
	else
		printf("4. There is no x in the list\n");
//5.
	ELE* p = FindX(L);
	if (p)
		printf("\n\n5. x = %d\n", p->data);
	else
		printf("\n\n5. The element x does not exist\n");
//6.
	int k;
	printf("\nPlease input the k value: ");
	scanf_s("%d", &k);
	p = FindK(L, k);
	if (p)
		printf("6. The element number k is %d\n", p->data);
	else
		printf("6. The element number k does not exist\n");
//7.8.9.
	int y;
	printf("\nPlease input the value x: ");
	scanf_s("%d", &x);
	printf("Please input the value y: ");
	scanf_s("%d", &y);
	//7.
	AddHead(L, x);
	printf("\n7. The list after adding %d to the head:\n", x);
	Output(L);
	//8.
	AddTail(L, x);
	printf("\n\n8. The list after adding %d to the tail:\n", x);
	Output(L);
	//9.
	Add_x_After_y_(L, x, y);
	printf("\n\n9. The list after adding %d after %d:\n", x, y);
	Output(L);
//10.
	printf("\n\nPlease input the value x: ");
	scanf_s("%d", &x);
	if (!TestSortedUp(L))
	{
		printf("The list is not sorted in ascending order\nThe list after sorting in ascending order\n");
		SortedUp(&L);
		Output(L);
	}
	AddSortedUp(L, x);
	printf("\n10. The list after adding %d in ascending order:\n", x);
	Output(L);
//11.
	DeleteHead(L);
	printf("\n\n11. The list after deleting the head:\n");
	Output(L);
//12.
	DeleteTail(L);
	printf("\n\n12. The list after deleting the tail:\n");
	Output(L);
//13.
	printf("\n\nPlease input the value x: ");
	scanf_s("%d", &x);
	DeleteFirstX(L, x);
	printf("13. The list after deleting the first x:\n");
	Output(L);
//14.
	DeleteList(L);
	printf("\n\nThe list after deleting all elements:\n");
	Output(L);

	printf("\n");
}