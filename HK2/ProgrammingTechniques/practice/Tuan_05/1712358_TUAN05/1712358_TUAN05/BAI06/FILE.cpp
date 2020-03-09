#include"FILE.h"

//doc du lieu tu file vao 1 bien SV
bool ReadFile(FILE* fp, SV& A)
{
	if (fread(&A, sizeof(SV), 1, fp) != 1)
		return false;
	else
		return true;
}

//doc du lieu tu file vao 1 mang SV
void ReadFile(FILE* fp, SV A[], int& N)
{
	N = 0;
	for (int i = 0; ReadFile(fp,A[i]); i++)
		N++;
}