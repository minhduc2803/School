#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MenuVaThaoTac.h"

void ThemSach(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short& So_Luong_Sach)
{
	system("cls");
	printf("Them dau sach\n");
	printf("Moi nhap lan luot cac thong tin cua dau sach\n");
	printf("ISBN (Ma sach): ");
	Nhap(ISBN[So_Luong_Sach], 21);
	printf("Ten sach: ");
	Nhap(Ten_Sach[So_Luong_Sach], 41);
	printf("Tac gia: ");
	Nhap(Tac_Gia[So_Luong_Sach], 31);
	printf("Nha xuat ban: ");
	Nhap(Nha_Xuat_Gia[So_Luong_Sach], 31);
	printf("Nam xuat ban: ");
	Nhap(Nam_Xuat_Ban[So_Luong_Sach]);
	printf("The loai: ");
	Nhap(The_Loai[So_Luong_Sach],31);
	printf("Gia 1 quyen sach: ");
	Nhap(Gia_Sach[So_Luong_Sach]);
	printf("So luong quyen sach: ");
	Nhap(So_Quyen_Sach[So_Luong_Sach]);
	printf("\nBan co chac chan muon them dau sach nay\n");
	printf("Nhan phim y roi Enter de hoan tat\n(chuong trinh se tu dong tao moi ma doc gia)\n");
	printf("Nhan phim bat ky (tru phim y) roi Enter de huy\n");
	/* dieu huong menu*/
	char Dieu_Khien_MenuThemSach = 0;
	Nhap(Dieu_Khien_MenuThemSach);
	if (Dieu_Khien_MenuThemSach == 'y')
	{
		So_Luong_Sach++;
	}
}
void SuaSach(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short So_Luong_Sach,
	int So_Thu_Tu_Sach,
	int Dieu_Khien_MenuSuaSach)
{
	switch (Dieu_Khien_MenuSuaSach)
	{
	case 1:
		printf("ISBN sua thanh: ");
		Nhap(ISBN[So_Thu_Tu_Sach - 1], 21);
		break;
	case 2:
		printf("Ten sach sua thanh: ");
		Nhap(Ten_Sach[So_Thu_Tu_Sach - 1], 41);
		break;
	case 3:
		printf("Tac gia sua thanh: ");
		Nhap(Tac_Gia[So_Thu_Tu_Sach - 1], 31);
		break;
	case 4:
		printf("Nha xuat ban sua thanh: ");
		Nhap(Nha_Xuat_Gia[So_Thu_Tu_Sach - 1], 31);
		break;
	case 5:
		printf("Nam xuat ban sua thanh: ");
		Nhap(Nam_Xuat_Ban[So_Thu_Tu_Sach - 1]);
		break;
	case 6:
		printf("The loai sua thanh: ");
		Nhap(The_Loai[So_Thu_Tu_Sach - 1], 31);
		break;
	case 7:
		printf("Gia sach sua thanh: ");
		Nhap(Gia_Sach[So_Thu_Tu_Sach - 1]);
		break;
	case 8:
		printf("So quyen sach sua thanh: ");
		Nhap(So_Quyen_Sach[So_Thu_Tu_Sach - 1]);
	}
}
void XoaSach(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short& So_Luong_Sach,
	int So_Thu_Tu_Sach)
{
	for (int i = So_Thu_Tu_Sach-1; i <= So_Luong_Sach - 2; i++)
	{
		strcpy(ISBN[i], ISBN[i + 1]);
		strcpy(Ten_Sach[i], Ten_Sach[i + 1]);
		strcpy(Tac_Gia[i], Tac_Gia[i + 1]);
		strcpy(Nha_Xuat_Gia[i], Nha_Xuat_Gia[i + 1]);
		Nam_Xuat_Ban[i] = Nam_Xuat_Ban[i + 1];
		strcpy(The_Loai[i], The_Loai[i + 1]);
		Gia_Sach[i] = Gia_Sach[i + 1];
		So_Quyen_Sach[i] = So_Quyen_Sach[i + 1];
	}
	So_Luong_Sach--;
}
void TimSachTheoISBN()
{
	printf("moi nhap ISBN cua dau sach can tim: ");
	/*cac thao tac tim kiem se duoc thuc hien truc tiep trong MenuTimSachTheoISBN*/
}
void TimSachTheoTen()
{
	printf("moi nhap ten sach (co the nhap 1 phan ten sach, chuong trinh se tim nhung ket qua co phan trung lap)\n");
	/*cac thao tac tim kiem se duoc thuc hien truc tiep trong MenuTimSachTheoTen*/
}
void _SelectSach(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short& So_Luong_Sach)
{
	int Dieu_Khien_MenuChonSach = 0;
	char Dieu_Khien_Menu1LoaiSach = 0;
	int Dieu_Khien_MenuSuaSach = 0;
	char Dieu_Khien_MenuXoaSach = 0;
	MenuChonSach();
	Nhap(Dieu_Khien_MenuChonSach);
	do
	{
		Menu1LoaiSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach, Dieu_Khien_MenuChonSach);
		Nhap(Dieu_Khien_Menu1LoaiSach);
		switch (Dieu_Khien_Menu1LoaiSach)
		{
		case 'b':
			break;
		case 'e':
			MenuSuaSach();
			Nhap(Dieu_Khien_MenuSuaSach);
			SuaSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach, Dieu_Khien_MenuChonSach, Dieu_Khien_MenuSuaSach);
			break;
		case 'd':
			MenuXoaSach();
			Nhap(Dieu_Khien_MenuXoaSach);
			if (Dieu_Khien_MenuXoaSach == 'y')
			{
				XoaSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach, Dieu_Khien_MenuChonSach);
				Dieu_Khien_Menu1LoaiSach = 'b';
			}
			break;
		}
	} while (Dieu_Khien_Menu1LoaiSach != 'b');
}
void _FindSachBangISBN(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short& So_Luong_Sach)
{
	char ISBNHienTai[21];
	char Dieu_Khien_MenuTimSachTheoISBN = 0;
	TimSachTheoISBN();
	Nhap(ISBNHienTai, 21);
	do
	{
		MenuTimSachTheoISBN(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach, ISBNHienTai);
		Nhap(Dieu_Khien_MenuTimSachTheoISBN);
		switch (Dieu_Khien_MenuTimSachTheoISBN)
		{
		case 'b':
			break;
		case 's':
			_SelectSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		}
	} while (Dieu_Khien_MenuTimSachTheoISBN != 'b');
}
void _FindSachBangTen(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short& So_Luong_Sach)
{
	char Ten_Sach_Hien_Tai[41];
	char Dieu_Khien_MenuTimSachTheoTen = 0;
	TimSachTheoTen();
	Nhap(Ten_Sach_Hien_Tai, 41);
	do
	{
		MenuTimSachTheoTen(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach, Ten_Sach_Hien_Tai);
		Nhap(Dieu_Khien_MenuTimSachTheoTen);
		switch (Dieu_Khien_MenuTimSachTheoTen)
		{
		case 'b':
			break;
		case 's':
			_SelectSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		}
	} while (Dieu_Khien_MenuTimSachTheoTen != 'b');
}
void _MenuDanhSachCacSach(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short& So_Luong_Sach)
{
	char Dieu_Khien_MenuDanhSachCacSach = 0;
	do
	{
		MenuDanhSachCacSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
		Nhap(Dieu_Khien_MenuDanhSachCacSach);
		switch (Dieu_Khien_MenuDanhSachCacSach)
		{
		case 'b': //back
			break;
		case 'a': //add
			ThemSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		case 's': //select
			_SelectSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		case 'i': //isbn
			_FindSachBangISBN(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		case 't': //ten sach
			_FindSachBangTen(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		}
	} while (Dieu_Khien_MenuDanhSachCacSach != 'b');
}
