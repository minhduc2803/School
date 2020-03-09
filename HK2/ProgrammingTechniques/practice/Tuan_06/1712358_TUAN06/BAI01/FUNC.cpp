#include"FUNC.h"

//tra ve S(n) = 1^2 + 2^2 + … + n^2
int Bai01_1(int N)
{
	if (N == 1)
		return 1;
	else
		return N*N + Bai01_1(N - 1);
}

//S(n) = 1 + 1/2 + … + 1/n
float Bai01_2(int N)
{
	if (N == 1)
		return 1.0;
	else
		return 1.0 / N + Bai01_2(N - 1);
}

//S(n) = 1 / 2 + 1 / 4 + … + 1 / 2n
float Bai01_3(int N)
{
	if (N == 1)
		return 0.5;
	else
		return 1.0 / (2 * N) + Bai01_2(N - 1);
}

//S(x,n) = x^2 + x^4 + … + x^2n
float Bai01_4(int N, float x)
{
	if (N == 1)
		return x*x;
	else
		return pow(x, 2 * N) + Bai01_4(N - 1, x);
}

//tra ve so hang thu n trong day fibonacci
int Bai01_5(int N)
{
	if (N == 1 || N == 2)
		return 1;
	else
		return Bai01_5(N - 1) + Bai01_5(N - 2);
}