#include"FILE.h"
#include"INOUT.h"

/***************************************
Ten file thay doi o duoi day
***************************************/
#define TenFile "sinhvien.bin"
void main()
{
	SV A[100];
	int N;
	FILE* fp=0;

	//doc file
	char filepatch[] = TenFile;
	fp = fopen(filepatch, "wb");
	if (fp == NULL)
	{
		printf("Mo file that bai\n");
		exit(1);
	}

	//khoi tao du lieu bang cach nhap tu ban phim
	Input(A, N);

	//ghi du lieu vao file
	WriteFile(fp, A, N);

	//dong file
	fclose(fp);
}