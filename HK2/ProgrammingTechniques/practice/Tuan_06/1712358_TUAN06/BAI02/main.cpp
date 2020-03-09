#include"FUNC.h"

void main()
{
	int N;
	Input(N);
	printf("Bai 2.1: N co %d chu so\n", Bai02_1(N));
	printf("Bai 2.2: Tong cac chu so chan cua N la: %d\n", Bai02_2(N));
	printf("Bai 2.3: Chu so dau tien cua N la: %d\n", Bai02_3(N));
	printf("Bai 2.4: So dao nguoc cua N la: ");
	Bai02_4(N);
	printf("\nBai 2.5: Chu so lon nhat cua N la: %d\n", Bai02_5(N));
	printf("Bai 2.6: ");
	if (Bai02_6(N))
		printf("N chua toan so le\n");
	else
		printf("N khong chua toan so le\n");
}