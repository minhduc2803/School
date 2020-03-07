#include "HANDLING.h"
#include "INOUT.h"
void main()
{
	LIST* L = (LIST*)malloc(sizeof(LIST));
	LIST* l1 = (LIST*)malloc(sizeof(LIST));
	LIST* l2 = (LIST*)malloc(sizeof(LIST));
	int N;
	printf("1. Nhap so phan tu N: ");
	Input(N);

	Initialize(L);
	Initialize(l1);
	Initialize(l2);
	Input(L, N);
	printf("Danh sach: ");
	Output(L);
	printf("\n2. Tong cac phan tu trong danh sach la: %d\n", SumOfList(L));
	TachDanhSach(L, l1, l2);
	printf("3.\nDanh sach l1: ");
	Output(l1);
	printf("\nDanh sach l2: ");
	Output(l2);
	printf("\n");
}