#include "INOUT.h"
#include "HANDLING.h"

void input(char s[], int n)
{
	do
	{
		gets_s(s, n);
	} while (s[0] == NULL || s[0] == '\n');
}
void input(int &n)
{
	printf("1. Nhap so ca khuc: ");
	do
	{
		scanf_s("%d", &n);
		if (n <= 0)
			printf("So ca khuc phai lon hon 0, nhap lai: ");
		else
			break;
	} while (1);
}
void input(mp3 list[], int n)
{

	for (int i = 0; i < n; i++)
		input(list[i]);
}
void input(mp3& song)
{
	char s[52];
	printf("\nMoi nhap ten ca khuc: ");
	input(s, 50);
	strcpy(song.CaKhuc, s);
	printf("Moi nhap ten nhac sy: ");
	input(s, 30);
	strcpy(song.NhacSy, s);
	printf("Moi nhap ten ca sy: ");
	input(s, 30);
	strcpy(song.CaSy, s);
	printf("Moi nhap thoi gian ca khuc (tinh bang giay): ");
	scanf_s("%d", &song.time);
}
void writefile(FILE** fp, char filename[], mp3 list[], int n)
{
	*fp = fopen(filename, "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(*fp, "%s %s %s %s\n", list[i].CaKhuc, list[i].CaSy, list[i].NhacSy, ThoiGian(list[i].time));
	}
	fclose(*fp);
}
