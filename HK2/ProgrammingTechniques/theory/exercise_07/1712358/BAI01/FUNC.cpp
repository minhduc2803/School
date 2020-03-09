#include"FUNC.h"

float Bai01(int N)
{
	if (N > 1)
		return sqrt(2 + Bai01(N - 1));
	else
		return sqrt(2);
}
float Bai02(int N)
{
	if (N > 1)
		return sqrt(N + Bai02(N - 1));
	else
		return 1;
}
float Bai03(int N, int i)
{
	if (i < N)
		return sqrt(i + Bai03(N, i + 1));
	else
		return sqrt(N);
}
float Bai04(int N, int i)
{
	if (i < N)
		return 1 + 1.0 / Bai04(N, i + 1);
	else
		return 1 + 1.0 / (1 + 1);
}