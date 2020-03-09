#include"XULY.h"

void control(int& flag)
{
	printf("Nhap 1 de tiep tuc; nhap 0 de thoat\n");
	scanf_s("%d", &flag);
}
void Input(float& x)
{
	printf("Input x: ");
	scanf_s("%f", &x);
	printf("The computer stored x = %f", x);
}
void Sign(float& x, char BiI[])
{
	if (x < 0)
	{
		BiI[0] = 1;
		x = -x;
	}
}
void Exponent(float& x, int& Ex, char BiI[])
{
	while (x < 1 && Ex != 0)
	{
		x *= 2;
		Ex--;
	}
	while (x >= 2 && Ex != 255)
	{
		x /= 2;
		Ex++;
	}
	for (int i = 1; i <= 8; i++)
	{
		float p = pow(2, 8 - i);
		if (Ex >= p)
		{
			BiI[i] = 1;
			Ex -= p;
		}
	}
}
void Mantissa(float& x, char BiI[])
{
	x -= 1;
	for (int i = 9; i <= 31; i++)
	{
		x *= 2;
		if (x >= 1)
		{
			BiI[i] = 1;
			x -= 1;
		}
	}
}
void BiToHex(char BiI[], char HexI[])
{
	for (int i = 0; i < 8; i++)
	{
		int m = 1;
		HexI[i] = 0;
		for (int j = 4 * i + 3; j >= 4 * i; j--)
		{
			HexI[i] += BiI[j] * m;
			m *= 2;
		}
		if (HexI[i] < 10)
			HexI[i] += '0';
		else
			HexI[i] += 'A' - 10;
		printf("%c", HexI[i]);
		if (i == 3)
			printf(" ");
	}
}