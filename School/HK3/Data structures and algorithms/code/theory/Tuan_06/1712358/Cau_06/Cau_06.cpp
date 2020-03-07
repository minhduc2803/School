#include "linkedlist.h"


int main()
{
	linkedlist L, L1, L2;
	initialize(L);
	initialize(L1);
	initialize(L2);

	addtail(L, 1);
	addtail(L, 5);
	addtail(L, 6);
	addtail(L, 8);
	addtail(L, 4);
	addtail(L, 3);
	addtail(L, 2);

	TachThanhHaiDanhSach(L, L1, L2);

	cout << "L: ";  output(L);
	cout << "L1: ";  output(L1);
	cout << "L2: ";  output(L2);

	system("pause");
	return 0;
}