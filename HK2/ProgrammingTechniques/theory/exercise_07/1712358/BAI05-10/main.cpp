#include"FUNC.h"

void main()
{
	int N;
	Input(N);
	printf("Bai 05: N co %d chu so\n", Bai05(N));
	printf("Bai 07: Tong cac chu so cua N la: %d\n", Bai07(N));
	printf("Bai 08: So dao nguoc cua N la: ");
	Bai08(N);
	printf("\nBai 09: Chu so lon nhat cua N la: %d\n", Bai09(N));
	printf("Bai 10: ");
	if (Bai10(N))
		printf("N chua toan so le\n");
	else
		printf("N khong chua toan so le\n");
}