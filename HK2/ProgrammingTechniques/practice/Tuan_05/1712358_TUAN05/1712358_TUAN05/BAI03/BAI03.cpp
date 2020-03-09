#include<stdio.h>
#include<stdlib.h>
/******************************************************************************
Ten file duoc dat lai tai #define
******************************************************************************/
#define file1 "file1.cpp"
int main(void)
{
	FILE *fout;
	char a;
	int c = 0;
	if ((fout = fopen(file1, "r+")) == NULL)
	{
		printf("Cannot open output file\n");
		exit(1);
	}
	while (a=getc(fout)!=EOF)
	{
		c++;
	}
	printf("The file has %d characters\n", c);
	fclose(fout);
	exit(0);
}