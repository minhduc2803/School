#include"SUPORT.h"

//--------------------------------------
//-----Ham kiem tra ngay thang----------
bool KTNgay(int day, int month, int year) //Kiem tra 1 ngay co ton tai hay khong
{
	if (year > 0)
		if (month >= 1 && month <= 12)
			if (day >= 1 && day <= MaxMonth(month, year))
				return true;
	return false;
}
int MaxMonth(int month, int year) //Tra ve so ngay toi da cua thang do
{
	switch (month)
	{
	case 4: case 6: case 9 : case 11 : return 30; break;
	case 2: return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28; break;
	default: return 31;
	}
}

//--------------------------------------
//---Ham tim kiem so tiet kiem theo id--
int SearchID(char ID[], CUS LIST[], int N) //ham tra ve so thu tu cua so tiet kiem trong LIST[]
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(ID, LIST[i].id) == 0)
			return i;
	}
	return N;
}

//--------------------------------------
//-Ham chuyen tien kieu char ve kieu int
int TranMoney(char money[])
{
	return atoi(money);
}

//--------------------------------------
//----Ham tinh tien von + lai-----------
bool CountMoney(int moneyBef, int& moneyAf, char DayIn[], char DayOut[], int rate, int type)
{
	int dayCount = DayOut[1] - DayIn[1] + 10 * (DayOut[0] - DayIn[0]);
	int monthCount = DayOut[4] - DayIn[4] + 10 * (DayOut[3] - DayIn[3]);
	int yearConut = DayOut[9] - DayIn[9] + 10 * (DayOut[8] - DayIn[8]) + 100 * (DayOut[7] - DayIn[7]) + 1000 * (DayOut[6] - DayIn[6]);
	monthCount += yearConut * 12 + (dayCount < 0 ? -1 : 0);
	if (monthCount < type)
	{
		moneyAf = moneyBef;
		return false;
	}
	else
	{
		moneyAf = (int)AllMoney(moneyBef, rate, monthCount);
		return true;
	}
}
float AllMoney(int money, float rate, int monthCount) //Ham ho tro tinh tien lai luy tien, ham tra ve tong so tien von + lai
{ 
	return money*pow((1 + (rate / 12) / 100), monthCount);
}

//--------------------------------------
//---------Sap xep so tiet kiem---------
void SortByMoney(CUS LIST[], int N)
{
	int* index = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		index[i] = i;
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (atoi(LIST[index[j]].money) < atoi(LIST[index[j + 1]].money))
			{
				swap(index[j], index[j + 1]);
			}
		}
	}
	CUS* B = (CUS*)malloc(N * sizeof(CUS));
	for (int i = 0; i < N-1; i++)
	{
		copy(B[i], LIST[index[i]]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		copy(LIST[i],B[i]);
	}
}

//--------------------------------------
//----------Hoan vi 2 bien CUS----------
void swap(CUS& A, CUS& B)
{
	CUS C;
	copy(C, A);
	copy(A, B);
	copy(B, C);
}
void copy(CUS& A, CUS C)
{
	strcpy(A.id, C.id);
	strcpy(A.name, C.name);
	strcpy(A.cmnd, C.cmnd);
	strcpy(A.DayIn, C.DayIn);
	strcpy(A.money, C.money);
	A.RatePerYear = C.RatePerYear;
	A.type = C.type;
}
void swap(int& A, int& B)
{
	int C = A;
	A = B;
	B = C;
}

//--------------------------------------
//-------Thay doi lai suat--------------
void ChangeRate(CUS LIST[], int N, int type, float rate)
{
	for (int i = 0; i < N; i++)
	{
		if (LIST[i].type == type)
			LIST[i].RatePerYear = rate;
	}
}

//--------------------------------------
//--------Thong ke trong 1 thang--------
void ForThongKe(CUS LIST[], int N, char MAndY[], int& Sum, int& SumOfMoney)
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(MAndY, &LIST[i].DayIn[3]) == 0)
		{
			Sum++;
			SumOfMoney += atoi(LIST[i].money);
		}
	}
}

//--------------------------------------
//---------Tim kiem theo ten------------
void TimKiemTrongTen(CUS LIST[], int N, char Ten[])
{
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (TimKiemTrongTen(Ten, LIST[i].name))
		{
			swap(LIST[i], LIST[j]);
			j++;
		}
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