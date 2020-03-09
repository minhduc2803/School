#ifndef _INFO_H_
#define _INFO_H_
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*----------------------------------------
----------infomation of customers---------*/
typedef struct cus {
	char id[8];
	char name[31];
	char cmnd[16];
	char DayIn[12];
	char money[15];
	float RatePerYear;
	int type;
}CUS;

//----------------------------------------

#endif