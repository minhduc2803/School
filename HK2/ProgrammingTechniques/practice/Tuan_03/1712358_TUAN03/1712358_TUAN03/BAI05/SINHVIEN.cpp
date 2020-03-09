#include"SINHVIEN.h"
void Input(char string[])
{
	do {
		gets_s(string, 51);
	} while (string[0] == '\n' || string[0] == 0);
}
void Input(float& A)
{
	while (1)
	{
		scanf_s("%f", &A);
		if (A < 0 || A>10)
			printf("Diem so phai >= 0 va <= 10, moi nhap lai: ");
		else break;
	}
}
void Input(int& N)
{
	while (1)
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("So luong sinh vien phai lon hon 0, moi nhap lai: ");
		else
			break;
	}
}
void Input(SV* p, int& N)
{
	printf("Moi nhap so luong sinh vien: ");
	Input(N);
	printf("Moi nhap lan luot thong tin tung sinh vien\n");
	for (int i = 0; i < N; i++)
	{
		printf("\nSinh vien %d: ", i + 1);
		printf("\nTen: ");
		Input(p->ten);
		printf("Diem toan: ");
		Input(p->toan);
		printf("Diem ly: ");
		Input(p->ly);
		printf("Diem hoa: ");
		Input(p->hoa);
		p++;
	}
}
void Output(SV* A)
{
	printf("%-30s%-10.2f%-10.2f%-10.2f\n", A->ten, A->toan, A->ly, A->hoa);
}
void Output(SV* p, int N)
{
	printf("\n%-30s%-10s%-10s%-10s\n", "Ten sinh vien", "Toan", "Ly", "Hoa");
	for (int i = 0; i < N; i++)
	{
		Output(p);
		p++;
	}
}