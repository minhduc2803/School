#include"FUNC.h"

void main()
{
	int N;
	int A[100];
	int copy[100];
	printf("Bai 12 - 15:\n\(Bai 13 duoc thuc hien tren 1 mang copy tu mang A, cac bai con lai thuc hien truc tiep tren A\)\n");
	Input(N);
	Input(A, N, copy);

	printf("Bai 12. Tong cac phan cua mang la: %d\n", BAI12(A, N));

	BAI13(copy, N);
	printf("Bai 13. Mang sau khi da dao cac vi tri\n");
	Output(copy, N);

	printf("\nBai 14. Phan tu lon nhat trong mang nam o vi tri so %d\n", BAI14(A, N)+1);

	BAI15(A, N);
	printf("Bai 15. Mang A sau khi sap xep tang dan\n");
	Output(A, N);

	printf("\n");
}