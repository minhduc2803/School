#include"INOUT.h"
void Input(SV& A)
{

	printf("Nhap ten: ");
	do
	{
		gets_s(A.name, 10);
	} while (A.name[0] == '\n' || A.name[0] == NULL);
	printf("Ma so sinh vien: ");

	gets_s(A.mssv, 10);
	printf("Diem toan: ");
	scanf_s("%d", &A.diemSo[0]);
	printf("Diem ly: ");
	scanf_s("%d", &A.diemSo[1]);
	printf("Diem hoa: ");
	scanf_s("%d", &A.diemSo[2]);
}
void Output(SV A)
{
	printf("Ten: %s\n", A.name);
	printf("Ma so sinh vien: %s\n", A.mssv);
	printf("Diem toan, ly, hoa: %d, %d, %d\n", A.diemSo[0], A.diemSo[1], A.diemSo[2]);
}
void Input(SV A[], int& N)
{
	printf("Moi nhap so luong sinh vien: ");
	while (1)
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("So luong sinh vien phai lon hon 0, moi nhap lai: ");
		else
			break;
	}
	for (int i = 0; i < N; i++)
	{
		printf("SV %d\n", i + 1);
		Input(A[i]);
	}
}
void Output(SV A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("\n");
		Output(A[i]);
	}
}