#include"XuLy.h"
void SearchSV(SV DS[], int N)
{
	char ad[51];
	int flag = 1;
	while (flag)
	{
		printf("Tim kiem theo dia chi SV, moi nhap dia chi: ");
		Input(ad);
		SearchSV(DS, N, ad);
		printf("Nhan phim 1 de tiep tuc tim kiem, nhan phim 0 de thoat\n");
		scanf_s("%d", &flag);
	}
}
void SearchSV(SV DS[], int N, char ad[])
{
	bool flag = false;
	printf("Ket qua:\n");
	for (int i = 0; i < N; i++)
	{
		if (SearchStr(ad, DS[i].ad))
		{
			Output(DS[i]);
			flag = true;
		}
	}
	if (!flag)
		printf("%30s\n", "(Danh sach trong)");
}
bool SearchStr(char S1[], char S2[])
{
	int L1=0, E1=0, E2=0;
	for (int i = 0; S1[i]!=0; i++)
	{
		L1++;
		E1 += S1[i];
		E2 += S2[i];
		if (S2[i] == 0)
			return false;
	}
	for (int i = 0, j = L1 - 1; S2[j] != 0; i++,j++)
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

