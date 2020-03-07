#include "handle.h"

int main()
{

	cout << "Merge sort with linked list" << endl;

	int N;
	input(N);
	node* head;
	input(head, N);
	output(head);

	sorting(head, N, NULL);
	cout << endl;
	cout << "The list after sorting" << endl << endl;
	output(head);
	system("pause");
	return 0;
}