#include"TRIANGLE.h"
#include"POINT.h"
void InputTriangle(TRIANGLE& M)
{
	printf("Nhap toa do dinh A:\n");
	InputPoint(M.A);
	printf("Nhap toa do dinh B:\n");
	InputPoint(M.B);
	printf("Nhap toa do dinh C:\n");
	InputPoint(M.C);
}
void OutputTriangle(TRIANGLE M)
{
	OutputPoint(M.A);
	OutputPoint(M.B);
	OutputPoint(M.C);
}
