#include"POINT_S.h"
#include"POINT.h"
void main()
{
	POINT P[100];
	int N;
	POINT A;

	//cau 1.1
	InputPoint_s(P,N);

	//cau 1.2
	OutputPoint_s(P,N);

	//cau 1.3
	printf("\nMoi nhap vao lan luot hoanh do va tung do cua diem A:\n");
	InputPoint(A);
	printf("Diem cach xa diem A nhat la: ");
	OutputPoint(P[MaxDistance(A, P, N)]);

	//cau 1.4
	printf("\n\nCac diem co toa do duong trong mang la:\n");
	PositivePoint_s(P, N);

	//cau 1.5
	printf("\n\nThu tu cac diem xa dan tam O(0;0) la:\n");
	SortPoint_s(P, N);
	OutputPoint_s(P, N);
}