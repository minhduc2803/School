#include"FUNC.h"

// Bai 01:
// Kiem tra tep tin cho truoc co ton tai hay khong
// Hamtra ve true neu tep tin ton tai, false neu khong ton tai
bool KiemTra(char filepath[])
{
	if (access(filepath, 0) == -1)
		return false;
	else
		return true;
}

// Bai 02:
// Tra ve kich thuoccua tep tin
int KichThuoc(FILE* fp)
{
	fseek(fp, 0L, SEEK_END);
	return ftell(fp);
}

// Bai 03:
//
void Copy(FILE* fp, char filefp[], FILE** copyfp, char newfile[])
{
	
	char link[100];
	char newname[30];
	printf("Chuong trinh se copy file \"%s\" toi 1 vi tri khac\n");
	while (1)
	{
		InputFileName(newname, filefp);
		InputLink(link);
		strcat(link, newname);
		if (KiemTra(link))
			printf("Ten file da duoc dung, thu lai\n");
		else if (*copyfp = fopen(link, "w"))
			printf("Link khong hop le, khong the tao file copy, thu lai\n");
		else
			break;
	}
	do
	{
		char a = fgetc(fp);
		fputc(a, *copyfp);
	} while (a != EOF);
}

//Bai 04: 
//Chia 1 file thanh cac file nho
void ChiaFile();

//Bai 05:
//Gop cac file nho thanh 1 file lon
void GopFile();