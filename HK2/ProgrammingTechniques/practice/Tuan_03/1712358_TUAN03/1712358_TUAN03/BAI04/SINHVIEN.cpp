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
void Input(SV DS[], int& N)
{
	printf("Moi nhap so luong sinh vien: ");
	Input(N);
	printf("Moi nhap lan luot thong tin tung sinh vien\n");
	for (int i = 0; i < N; i++)
	{
		printf("\nSinh vien %d: ", i + 1);
		printf("\nTen: ");
		Input(DS[i].ten);
		printf("Diem toan: ");
		Input(DS[i].toan);
		printf("Diem ly: ");
		Input(DS[i].ly);
		printf("Diem hoa: ");
		Input(DS[i].hoa);
		DS[i].TB = (DS[i].toan + DS[i].ly + DS[i].hoa) / 3;
		if (DS[i].TB >= 9)
			strcpy(DS[i].xloai, "Xuat Sac");
		else if (DS[i].TB >= 8)
			strcpy(DS[i].xloai, "Gioi");
		else if (DS[i].TB >= 7)
			strcpy(DS[i].xloai, "Kha");
		else if (DS[i].TB >= 5)
			strcpy(DS[i].xloai, "Trung Binh");
		else
			strcpy(DS[i].xloai, "Yeu");
		printf("Dia chi: ");
		Input(DS[i].ad);
	}
	
}
void Output(SV A)
{
	printf("%-23s%-6.2f%-6.2f%-6.2f%-6.2f%-11s%-30s\n", A.ten, A.toan, A.ly, A.hoa, A.TB, A.xloai,A.ad);
}
void Output(SV DS[], int N)
{
	printf("\n%-23s%-6s%-6s%-6s%-6s%-11s%-30s\n", "Ten sinh vien", "Toan", "Ly", "Hoa", "TB", "XL","Dia Chi");
	for (int i = 0; i < N; i++)
	{
		Output(DS[i]);
	}
}