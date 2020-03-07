#include "linkedlist.h"

int main()
{
	linkedlist L, L1;
	initialize(L);
	initialize(L1);
	addtail(L, 1);
	addtail(L, 5);
	addtail(L, 6);
	addtail(L, 8);
	addtail(L, 4);
	addtail(L, 3);
	addtail(L, 2);

	output(L);
	cout << "a) L co " << DemSoPhanTu(L) << " phan tu" << endl;
	cout << "b) node thu 3 cua L: " << TimNodeThuI(L, 3)->key << endl;
	cout << "c)Them node 9 sau node 5 trong L: " << endl;
	ThemNodeXSauNodeK(L, 9, 5);
	cout << "L: ";
	output(L);
	cout << "d) Xoa node truoc node 3 trong L:" << endl;
	XoaNodeTruocNodeK(L, 3);
	cout << "L: ";
	output(L);
	cout << "Xoa node truoc node 5 trong L:" << endl;
	XoaNodeTruocNodeK(L, 5);
	cout << "L: ";
	output(L);
	cout << "e) Dao nguoc danh sach L" << endl;
	L1 = DaoNguocDanhSach(L);
	cout << "L: ";
	output(L);
	cout << "L1: ";
	output(L1);
	system("pause");
	return 0;
}