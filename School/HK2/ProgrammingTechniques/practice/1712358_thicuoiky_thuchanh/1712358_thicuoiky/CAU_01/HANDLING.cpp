#include "HANDLING.h"

//chuyen thoi gian tu giay sang dang hh:mm:ss
char* ThoiGian(int t)
{
	char* s = (char*)malloc(sizeof(char) * 9);
	int hour = t / 3600;
	int minute = (t % 3600) / 60;
	int second = t % 60;
	s[1] = hour % 10+'0';
	s[0] = hour / 10 + '0';
	s[4] = minute % 10 + '0';
	s[3] = minute / 10 + '0';
	s[7] = second % 10 + '0';
	s[6] = second / 10 + '0';
	s[2] = ':';
	s[5] = ':';
	s[8] = NULL;
	return s;
}

//Tra ve tong thoi gian cac ca khuc
int SumTime(mp3 list[], int n)
{
	int Sum = 0;
	for (int i = 0; i < n; i++)
		Sum += list[i].time;
	return Sum;
}

//Tra ve so thu tu ca khuc co thoi gia dai nhat
int MaxSong(mp3 list[], int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (list[max].time < list[i].time)
			max = i;
	}
	return max;
}