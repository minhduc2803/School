#include"FUNC.h"

void main()
{
	int N;
	float x;
	Input(N);
	InputFloat(x);
	printf("Bai 1.1: S(N) = 1^2 + 2^2 + ... + n^2 = %d\n", Bai01_1(N));
	printf("Bai 1.2: S(N) = 1 + 1/2 + ... + 1/n = %f\n", Bai01_2(N));
	printf("Bai 1.3: S(N) = 1/2 +1/4 + ... + 1/2n = %f\n", Bai01_3(N));
	printf("Bai 1.4: S(N) = x^2 + x^4 + ... + x^2n = %f\n", Bai01_4(N,x));
	printf("Bai 1.5: So hang thu %d cua day fibonacci la: %d\n",N,Bai01_5(N));
}