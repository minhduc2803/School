#ifndef _INOUT_H_
#define _INOUT_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct SV
{
	char name[10];
	char mssv[10];
	int diemSo[3];
} SinhVien;

void Input(SV& A);
void Output(SV A);
void Input(SV A[], int& N);
void Output(SV A[], int N);
#endif