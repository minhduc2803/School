#include "linkedlist.h"

int main()
{
	linkedlist L, L1, L2;
	initialize(L);
	initialize(L1);
	initialize(L2);
	addtail(L, 1); addtail(L1, 1); addtail(L2, 1);
	addtail(L, 5); addtail(L1, 5); addtail(L2, 5);
	addtail(L, 6); addtail(L1, 6); addtail(L2, 6);
	addtail(L, 8); addtail(L1, 8); addtail(L2, 8);
	addtail(L, 4); addtail(L1, 4); addtail(L2, 4);
	addtail(L, 3); addtail(L1, 3); //addtail(L2, 3);
	addtail(L, 2); addtail(L1, 2); addtail(L2, 2);

	cout << "L:  ";
	output(L);
	cout << "L1: ";
	output(L1);
	cout << "L2: ";
	output(L2);

	cout << endl << "L vs L1: ";
	if (HaiDanhSachGiongNhauKhong(L, L1))
		cout << "giong nhau";
	else
		cout << "khac nhau";
	cout << endl << "L vs L2: ";
	if (HaiDanhSachGiongNhauKhong(L, L2))
		cout << "giong nhau";
	else
		cout << "khac nhau";
	cout << endl << "L1 vs L2: ";
	if (HaiDanhSachGiongNhauKhong(L1, L2))
		cout << "giong nhau";
	else
		cout << "khac nhau";

	cout << endl;
	system("pause");
	return 0;
}