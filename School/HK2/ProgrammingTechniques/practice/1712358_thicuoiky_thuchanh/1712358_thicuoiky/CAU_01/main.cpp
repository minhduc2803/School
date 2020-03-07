#include "INFO.h"
#include "INOUT.h"
#include "HANDLING.h"

int main()
{
	mp3* list;
	int n;
	input(n);
	list = (mp3*)malloc(sizeof(mp3)*n);
	input(list, n);
	
	printf("\n2. Tong thoi gian cac ca khuc la: %s\n", ThoiGian(SumTime(list,n)));

	printf("3. Ca khuc co thoi gian dai nhat la: %s\n", list[MaxSong(list, n)].CaKhuc);

	char filename[] = "mp3.txt";
	FILE* fp;
	writefile(&fp, filename, list, n);
	return 0;
}