#include"FILE.h"
//ghi 1 bien SV vao file
void WriteFile(FILE* fp, SV A)
{
	fwrite(&A, sizeof(SV), 1, fp);
}
//ghi 1 mang SV vao file
void WriteFile(FILE* fp, SV A[], int N)
{
	WriteFile(fp,A[0]);
	for (int i = 1; i < N; i++)
	{
		WriteFile(fp, A[i]);
	}
}