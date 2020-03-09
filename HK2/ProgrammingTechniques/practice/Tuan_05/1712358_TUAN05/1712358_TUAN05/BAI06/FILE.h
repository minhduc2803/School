#ifndef _FILE_H_
#define _FILE_H_
#include"INOUT.h"

//doc du lieu tu file vao 1 bien SV
bool ReadFile(FILE* fp, SV& A);

//doc du lieu tu file vao 1 mang SV
void ReadFile(FILE* fp, SV A[], int& N);
#endif
