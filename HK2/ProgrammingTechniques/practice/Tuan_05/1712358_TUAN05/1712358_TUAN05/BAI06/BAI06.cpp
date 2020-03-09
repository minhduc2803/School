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
	FILE* fp;

	//mo file
	char filepatch[] = TenFile;
	fp = fopen(filepatch, "rb");
	if (fp == NULL)
	{
		printf("Mo file that bai\n");
		exit(1);
	}

	//doc file
	ReadFile(fp, A, N);

	//sau do ghi ra man hinh
	Output(A, N);

	//dong file
	fclose(fp);
}