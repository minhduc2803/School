#ifndef _HANDLING_H_
#define _HANDLING_H_

#include <stdlib.h>
#include "INFO.h"

//chuyen thoi gian tu giay sang dang hh:mm:ss
char* ThoiGian(int t);

//Tra ve tong thoi gian cac ca khuc
int SumTime(mp3 list[], int n);

//Tra ve so thu tu ca khuc co thoi gia dai nhat
int MaxSong(mp3 list[], int n);
#endif

