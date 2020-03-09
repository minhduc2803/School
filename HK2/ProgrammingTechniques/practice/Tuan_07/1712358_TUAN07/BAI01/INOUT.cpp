#include"INOUT.h"

//------------------------------------
//--------in out from file------------
bool OpenFile(FILE** fp, char filepatch[], char mode[])
{
	*fp = fopen(filepatch, mode);
	if (!(*fp))
		return false;
	else
		return true;
}
//------------------------------------
void CloseFile(FILE* fp)
{
	fclose(fp);
}
//------------------------------------
void Read(FILE** fp, char filepatch[], CUS LIST[], int& N)
{
	N = 0;
	if (OpenFile(fp, filepatch, "rb"))
	{
		for (int i = 0; i == N; i++)
		{
			N += fread(LIST[i].id, sizeof(CUS), 1, *fp);
		}
		CloseFile(*fp);
	}
}
//------------------------------------
void Write(FILE** fp, char filepatch[], CUS LIST[], int N)
{
	OpenFile(fp, filepatch, "wb");
	fwrite(LIST, N, sizeof(CUS), *fp);
	CloseFile(*fp);
}

//------------------------------------
//--------in out from the screen------
void Input(int& A)
{
	flushall();
	scanf_s("%d", &A);
}
//------------------------------------
void Input(char A[], int N)
{
	do
	{
		gets_s(A, N + 1);
	} while(A[0] == '\n' || A[0] == NULL);
}
//------------------------------------
void Input(float& A)
{
	flushall();
	scanf_s("%f", &A);
}
//------------------------------------
void InputID(char ID[], CUS LIST[], int N)
{
	do
	{
		Input(ID, 7);
		if (!TestID(ID))
			printf("Ma so la chuoi so gom 7 chu so, moi thu lai\n");
		else if (!CompareID(ID, LIST, N))
			printf("Ma so da duoc su dung, moi nhap ma so khac\n");
		else
			break;
	} while (1);
}
bool CompareID(char ID[], CUS LIST[], int N) //ham ho tro cho InputID
{
	if (N == 0)
		return true;
	else
		if (strcmp(ID, LIST[N - 1].id) == 0)
			return false;
		else
			return CompareID(ID, LIST, N - 1);
}
bool TestID(char ID[]) //ham ho tro cho InputID
{
	int i;
	for (i = 0; ID[i] != NULL; i++)
	{
		if (ID[i]<'0' || ID[i]>'9')
			return false;
	}
	if (i != 7)
		return false;
	else
		return true;
}
//------------------------------------
void InputDay(char Day[], CUS LIST[], int N)
{
	
	do
	{
		Input(Day, 11);
		if (!TestDay(Day))
			printf("Ngay nhap vao khong ton tai hoac khong dung dinh dang, moi nhap lai\n");
		else if (!CompareDay(Day, LIST, N))
			printf("Ngay hom nay khong the nam truoc cac ngay lap so trong danh sach, moi nhap lai\n");
		else
			break;
	} while (1);
}
bool CompareDay(char Day[], CUS LIST[], int N) //ham so tro cho InputDay
{
	char DayYearFirst[] = { Day[6],Day[7],Day[8],Day[9],Day[3],Day[4],Day[0],Day[1],NULL };
	for (int i = 0; i < N; i++)
	{
		char DayYearFirst_of_List[]= { LIST[i].DayIn[6],LIST[i].DayIn[7],LIST[i].DayIn[8],LIST[i].DayIn[9],LIST[i].DayIn[3],LIST[i].DayIn[4],LIST[i].DayIn[0],LIST[i].DayIn[1],NULL };
		if (strcmp(DayYearFirst, DayYearFirst_of_List) < 0)
			return false;
	}
	return true;
}
bool TestDay(char Day[]) //ham so tro cho InputDay
{
	if (Day[2] != '/' || Day[5] != '/' || Day[10] != NULL)
		return false;
	int i;
	for (i = 0; Day[i] != 0; i++)
	{
		if (i != 2 && i != 5)
			if (Day[i]<'0' || Day[i]>'9')
				return false;
	}
	int _day = (Day[0] - '0') * 10 + Day[1] - '0';
	int _month= (Day[3] - '0') * 10 + Day[4] - '0';
	int _year = atoi(&Day[6]);
	if (KTNgay(_day, _month, _year))
		return true;
	else
		return false;
}
//------------------------------------
void InputMAndY(char MAndY[])
{
	do
	{
		Input(MAndY, 7);
		if (!TestMAndY(MAndY))
			printf("Thang va nam nhap vao khong ton tai hoac khong dung dinh dang, thu lai\n");
		else
			break;
	} while (1);
}
bool TestMAndY(char MAndY[])//Ham ho tro cho InputMAndy
{
	if (MAndY[2] != '/' || MAndY[7] != NULL)
		return false;
	int i;
	for (i = 0; MAndY[i] != 0; i++)
	{
		if (i != 2)
			if (MAndY[i]<'0' || MAndY[i]>'9')
				return false;
	}
	int _month = (MAndY[0] - '0') * 10 + MAndY[1] - '0';
	int _year = atoi(&MAndY[3]);
	if (_year > 0 && (_month >= 1 && _month <= 12))
		return true;
	else
		return false;
}
//------------------------------------
void InputType(int& type)
{
	do
	{
		Input(type);
		if (type != 0 && type != 1 && type != 3 && type != 6 && type != 12)
			printf("Chi co 5 loai ky han da ghi o tren, moi nhap lai\n");
		else
			break;
	} while (1);
}