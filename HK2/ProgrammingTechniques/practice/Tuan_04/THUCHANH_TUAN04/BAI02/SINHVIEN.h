#ifndef _SINHVIEN_H_
#define _SINHVIEN_H_

#include <stdio.h>
#include<string.h>
typedef struct {
	int MSSV;
	char Ten[51];
	float TB;
}SV;
int MSSVhople();
void Input(SV& A);
void Output(SV A);
void HieuChinh(char S[]);
bool TimKiemTrongTen(char S1[], char S[]);
bool equal(char S1[], char S2[]);
void Input(char S[]);
#endif

