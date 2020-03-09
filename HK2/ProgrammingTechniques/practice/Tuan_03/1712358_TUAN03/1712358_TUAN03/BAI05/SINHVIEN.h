#ifndef _SINHVIEN_H_
#define _SINHVIEN_H_

#include <stdio.h>

typedef struct {
	char ten[51];
	float toan, ly, hoa;
}SV;
void Input(char string[]);
void Input(float& A);
void Input(int& N);
void Output(SV* A);
void Input(SV* p, int& N);
void Output(SV* p, int N);
#endif
