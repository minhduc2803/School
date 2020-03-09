#include<string.h>
#include"INFO.h"
#include"MENU.h"
#include"OPTIONS.h"
#include"INOUT.h"

void main()
{
	CUS LIST[10000];
	int N = 0;
	char filepatch[] = "BANK.TXT";
	FILE* fp;
	Read(&fp, filepatch, LIST, N);
	MainOptions(LIST, N);
	Write(&fp, filepatch, LIST, N);
}