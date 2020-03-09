#include"HANDING.h"

//Ham mo file, tra ve true neu mo thanh cong, false neu that bai
bool OpenFile(FILE** fp, char filepatch[], char mode[])
{
	*fp = fopen(filepatch, mode);
	if (fp == NULL)
	{
		printf("Mo file %s that bai\n", filepatch);
		return false;
	}
	return true;
}

//Ham dong file
void CloseFile(FILE* fp)
{
	fclose(fp);
}

void Input(char S[], int N)
{
	do
	{
		gets_s(S, N);
	} while (S[0] == '\n' || S[0] == NULL);
}

void Input(char& S)
{
	do
	{
		S = getchar();
	} while (S == '\n' || S == NULL);
}
//Cac ham phu cua ham void Copy(FILE* fp, char filefp[], FILE** copyfp, char newfile[]);
bool TestFileName(char S[])
{
	for (int i = 0; S[i] != NULL; i++)
	{
		if (S[i] == '\\' || S[i] == '//' || S[i] == ':' || S[i] == '*' || S[i] == '?' || S[i] == '\"' || S[i] == '<' || S[i] == '>' || S[i] == '|')
			return false;
	}
	return true;
}
void InputFileName(char newname[], char filefp[])
{
	printf("Ban co muon doi ten file copy ? nhan 1 de doi ten, 0 de giu nguyen ten\n");
	char flag;
	Input(flag);
	if (flag == 1)
	{
		while (1)
		{
			printf("Ten file copy moi: ");
			Input(newname, 30);
			if (!TestFileName(newname))
				printf("Ten file khong duoc chua cac ky tu: \/:*?\"<>|, thu lai\n");
			else
				break;
		}
	}
	else
		strcpy(newname, filefp);
}
void InputLink(char link[])
{
	printf("Moi nhap link toi vi tri can copy");
	Input(link, 100);
	for (int i = 0;; i++)
		if (link[i] == NULL)
			if (link[i - 1] != '\\')
			{
				link[i] = '\\';
				link[i + 1] = NULL;
				break;
			}
}