#include"FUNC.h"

void main()
{
	int N;
	int A[100];
	printf("Bai 3.1: Nhap mang A\n");
	Bai03_1(A, N);
	printf("Bai 3.2: Xuat mang A\n");
	Bai03_2(A, N);
	printf("\nBai 3.3: Xuat mang A theo thu tu nguoc\n");
	Bai03_3(A, N);
	printf("\nBai 3.4: So lon nhat trong mang la: %d\n", Bai03_4(A, N));
	printf("Bai 3.5: So luong so nguyen to trong mang la: %d\n", Bai03_5(A, N));
	printf("Bai 3.6: So luong cac gia tri khac nhau trong mang la: %d\n", Bai03_6(A, N));
	printf("Bai 3.7: ");
	if (Bai03_7(A, N))
		printf("Mang toan so chia het cho 7\n");
	else
		printf("Mang khong chua toan so chia het cho 7\n");
	printf("Bai 3.8: Mang sau khi da sap xep theo thu tu tang dan\n");
	Bai03_8(A, N);
	Output(A, N);
	printf("\n");
}