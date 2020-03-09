#include"SINHVIEN.h"

void main()
{
	SV A;
	char S[100];
	printf("Moi nhap thong tin cua sinh vien:\n");
	Input(A);
	HieuChinh(A.Ten);
	Output(A);

	Input(S);
	puts(S);
	if (TimKiemTrongTen(S, A.Ten))
		printf("Day S co trong ten cua sinh vien\n");
	else
		printf("Day S khong co trong ten cua sinh vien (chu y viet hoa)\n");
}