#include"XULY.h"

void main()
{
	float x;
	int flag = 1;
	while (flag)
	{
		char BiI[32] = { 0 }, HexI[8];
		int Ex = 127;
		Input(x);
		printf("\nAccording IEEE x = ");
		Sign(x, BiI);
		Exponent(x, Ex, BiI);
		Mantissa(x, BiI);
		BiToHex(BiI, HexI);
		printf("\n");
		control(flag);
	}
}
