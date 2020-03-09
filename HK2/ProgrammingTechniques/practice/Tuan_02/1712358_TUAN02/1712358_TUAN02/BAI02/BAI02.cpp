#include"POINT.h"
#include"TRIANGLE.h"
#include"TRIANGLE_S.h"
void main()
{
	TRIANGLE T[100];
	int N;
	
	//2.1
	InputTriangle_s(T, N);

	//2.2
	printf("Mang cac tam giac:\n");
	OutputTriangle_s(T, N);

	//2.3
	printf("Tam giac co chu vi lon nhat: ");
	OutputTriangle(T[MaxPerimeter(T, N)]);

	//2.4
	printf("\nTong dien tich cac tam giac: %f", SumOfArea(T, N));

	//2.5
	printf("\nCac tam giac co dien tich lon hon dien tich trung binh: ");
	CountLargeArea(T, N);

	//2.6
	printf("\nMang cac tam giac giam dan theo chu vi:\n");
	SortDePerimeter(T, N);
}