#include"SINHVIEN.h"
int MSSVhople()
{
	int MaSo;
	while (1)
	{
		scanf_s("%d", &MaSo);
		if (MaSo > 9999999 || MaSo < 1000000)
			printf("Ma so hop le phai co 7 chu so, moi nhap lai: ");
		else
			break;
	}
	return MaSo;
}
void Input(SV& A)
{
	
	printf("Nhap ten: ");
	gets_s(A.Ten, 31);
	printf("Ma so sinh vien: ");
	
	A.MSSV = MSSVhople();
	printf("Diem trung binh: ");
	scanf_s("%f", &A.TB);
}
void Output(SV A)
{
	printf("Ten: %s\n", A.Ten);
	printf("Ma so sinh vien: %d\n",A.MSSV);
	printf("Diem trung binh: %.2f\n", A.TB);
}
void HieuChinh(char S[])
{
	bool flag = true;
	for (int i = 0; S[i]; i++)
	{
		if(flag)
			if (S[i] >= 'a' && S[i] <= 'z')
			{
				S[i] = S[i] - ('a' - 'A');
			}
		if (S[i] == ' ')
			flag = true;
		else
			flag = false;
	}
}
bool TimKiemTrongTen(char S1[], char S2[])
{
	int L1 = 0, E1 = 0, E2 = 0;
	for (int i = 0; S1[i] != 0; i++)
	{
		L1++;
		E1 += S1[i];
		E2 += S2[i];
		if (S2[i] == 0)
			return false;
	}
	for (int i = 0, j = L1 - 1; S2[j] != 0; i++, j++)
	{
		if (E1 == E2)
			if (equal(S1, &S2[i]))
				return true;
		E2 = E2 - S2[i] + S2[j + 1];
	}
	return false;
}
bool equal(char S1[], char S2[])
{
	for (int i = 0; S1[i] != 0; i++)
	{
		if (S1[i] != S2[i])
			return false;
	}
	return true;
}

void Input(char S[])
{
	printf("\nMoi nhap vao 1 day ky tu S: ");
	do
	{
		gets_s(S, 51);
	} while (S[0] == '\n' || S[0] == 0);
}