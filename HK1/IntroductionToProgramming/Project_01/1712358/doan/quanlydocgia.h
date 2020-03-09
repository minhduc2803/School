#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"MenuVaThaoTac.h"

bool TestMaDocGia(char Ma_Hien_Tai[], char Ma_Doc_Gia[][14], unsigned short So_Luong_Doc_Gia)
{
	for (int i = 0; i < So_Luong_Doc_Gia; i++)
	{
		if (!strcmp(Ma_Hien_Tai, Ma_Doc_Gia[i]))
			return false;
	}
	return true;
}
void TaoMaDocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia)
{
	if (Gioi_Tinh[So_Luong_Doc_Gia] == '0')
		Ma_Doc_Gia[So_Luong_Doc_Gia][0] = 'B';
	else
		Ma_Doc_Gia[So_Luong_Doc_Gia][0] = 'G';
	Ma_Doc_Gia[So_Luong_Doc_Gia][1] = Ngay_Sinh[So_Luong_Doc_Gia][6];
	Ma_Doc_Gia[So_Luong_Doc_Gia][2] = Ngay_Sinh[So_Luong_Doc_Gia][7];
	Ma_Doc_Gia[So_Luong_Doc_Gia][3] = Ngay_Lap_The[So_Luong_Doc_Gia][0];
	Ma_Doc_Gia[So_Luong_Doc_Gia][4] = Ngay_Lap_The[So_Luong_Doc_Gia][1];
	Ma_Doc_Gia[So_Luong_Doc_Gia][5] = Ngay_Lap_The[So_Luong_Doc_Gia][2];
	Ma_Doc_Gia[So_Luong_Doc_Gia][6] = Ngay_Lap_The[So_Luong_Doc_Gia][3];
	Ma_Doc_Gia[So_Luong_Doc_Gia][7] = Ngay_Lap_The[So_Luong_Doc_Gia][6];
	Ma_Doc_Gia[So_Luong_Doc_Gia][8] = Ngay_Lap_The[So_Luong_Doc_Gia][7];
	unsigned short BaSoCuoi = So_Luong_Doc_Gia+1;
	do
	{
		Ma_Doc_Gia[So_Luong_Doc_Gia][9] = BaSoCuoi / 1000 + '0';
		Ma_Doc_Gia[So_Luong_Doc_Gia][10] = (BaSoCuoi % 1000) / 100 + '0';
		Ma_Doc_Gia[So_Luong_Doc_Gia][11] = ((BaSoCuoi % 1000) % 100) / 10 + '0';
		Ma_Doc_Gia[So_Luong_Doc_Gia][12] = ((BaSoCuoi % 1000) % 100) % 10 + '0';
		Ma_Doc_Gia[So_Luong_Doc_Gia][13] = 0;
		BaSoCuoi++;
	} while (!TestMaDocGia(Ma_Doc_Gia[So_Luong_Doc_Gia], Ma_Doc_Gia, So_Luong_Doc_Gia));

}
void ThemDocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short& So_Luong_Doc_Gia)
{
	system("cls");
	printf("Them doc gia\n");
	printf("Moi nhap lan luot cac thong tin cua doc gia\n");
	printf("Ho va ten: ");
	Nhap(Ten_Doc_Gia[So_Luong_Doc_Gia], 31);
	printf("So CMND: ");
	Nhap(CMND[So_Luong_Doc_Gia], 13);
	printf("Ngay sinh:\n(nhap 1 day so lien tuc xxyyzzzz, xx-ngay, yy-thang, zzzz-nam");
	printf("Luu y: Ngay hoac thang phai la 1 so co 2 chu so, neu chi co 1 so thi them so 0 dang truoc\n");
	printf("VD doc gia sinh ngay 1 thang 2 nam 1999 thi nhap 01021999)\n");
	do
	{
		Nhap(Ngay_Sinh[So_Luong_Doc_Gia], 15);
		if (!KiemTraNgayHopLe(Ngay_Sinh[So_Luong_Doc_Gia]))
			printf("Ngay ban vua nhap khong hop le, moi nhap lai: ");
		else
			break;
	} while (1);
	printf("Gioi tinh:\n");
	printf("Nam: chon phim 0 roi Enter\n");
	printf("Nu: chon phim bat ky (tru phim 0) roi Enter\n");
	Nhap(Gioi_Tinh[So_Luong_Doc_Gia]);
	printf("Email: ");
	Nhap(Email[So_Luong_Doc_Gia], 30);
	printf("Dia chi: ");
	Nhap(Dia_Chi[So_Luong_Doc_Gia], 31);
	printf("Ngay lap the:\n(nhap 1 day so lien tuc xxyyzzzz, xx-ngay, yy-thang, zzzz-nam");
	printf("Luu y: Ngay hoac thang phai la 1 so co 2 chu so, neu chi co 1 so thi them so 0 dang truoc\n");
	printf("VD ngay lap the la ngay 1 thang 2 nam 2017 thi nhap 01022017)\n");
	do
	{
		Nhap(Ngay_Lap_The[So_Luong_Doc_Gia], 15);
	if (!KiemTraNgayHopLe(Ngay_Lap_The[So_Luong_Doc_Gia]))
		printf("Ngay ban vua nhap khong hop le, moi nhap lai: ");
	else
		break;
	} while (1);
	printf("\nBan co chac chan muon them doc gia nay\n");
	printf("Nhan phim y roi Enter de hoan tat\n(chuong trinh se tu dong tao moi ma doc gia)\n");
	printf("Nhan phim bat ky (tru phim y) roi Enter de huy\n");
	/* dieu huong menu*/
	char Dieu_Khien_MenuThemDocGia = 0;
		Nhap(Dieu_Khien_MenuThemDocGia);
		if (Dieu_Khien_MenuThemDocGia == 'y')
		{
			TaoMaDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			So_Luong_Doc_Gia++;
		}
}
void SuaDocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia,
	int So_Thu_Tu_Doc_Gia,
	char Muc_Can_Sua_Doc_Gia)
{
	switch (Muc_Can_Sua_Doc_Gia)
	{
	case '1':
		printf("Ho va ten sua thanh: ");
		do
		{
			Nhap(Ten_Doc_Gia[So_Thu_Tu_Doc_Gia - 1], 31);
		} while (Ten_Doc_Gia[So_Thu_Tu_Doc_Gia-1][0] == 0);
		break;
	case '2':
		printf("khong the sua Ma doc gia\n");
		system("pause");
		break;
	case '3':
		printf("So CMND sua thanh: ");
		Nhap(CMND[So_Thu_Tu_Doc_Gia - 1], 13);
		break;
	case '4':
		printf("Ngay sinh sua thanh:\n(nhap 1 day so lien tuc xxyyzzzz, xx-ngay, yy-thang, zzzz-nam)");
		do
		{
			Nhap(Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1], 15);
			if (!KiemTraNgayHopLe(Ngay_Sinh[So_Thu_Tu_Doc_Gia-1]))
				printf("Ngay ban vua nhap khong hop le, moi nhap lai: ");
			else
				break;
		} while (1);
		break;
	case '5':
		printf("Gioi tinh sua thanh: \n");
		printf("Nam: chon phim 0 roi Enter\n");
		printf("Nu: chon phim bat ky (tru phim 0) roi Enter\n");
		Nhap(Gioi_Tinh[So_Thu_Tu_Doc_Gia - 1]);
		break;
	case '6':
		printf("Email sua thanh: ");
		Nhap(Email[So_Thu_Tu_Doc_Gia - 1], 30);
		break;
	case '7':
		printf("Dia chi sua thanh: ");
		Nhap(Dia_Chi[So_Thu_Tu_Doc_Gia - 1], 31);
		break;
	case '8':
		printf("Ngay lap the sua thanh:\n(nhap 1 day so lien tuc xxyyzzzz, xx-ngay, yy-thang, zzzz-nam)");
		do
		{
			Nhap(Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1], 15);
			if (!KiemTraNgayHopLe(Ngay_Lap_The[So_Thu_Tu_Doc_Gia-1]))
				printf("Ngay ban vua nhap khong hop le, moi nhap lai: ");
			else
				break;
		} while (1);
		break;
	}
}
void XoaDocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short& So_Luong_Doc_Gia,
	int So_Thu_Tu_Doc_Gia)
{
	for (int i = So_Thu_Tu_Doc_Gia - 1; i <= So_Luong_Doc_Gia - 2; i++)
	{
		strcpy(Ten_Doc_Gia[i], Ten_Doc_Gia[i + 1]);
		strcpy(Ma_Doc_Gia[i], Ma_Doc_Gia[i + 1]);
		strcpy(CMND[i], CMND[i + 1]);
		strcpy(Ngay_Sinh[i], Ngay_Sinh[i + 1]);
		Gioi_Tinh[i]= Gioi_Tinh[i + 1];
		strcpy(Email[i], Email[i + 1]);
		strcpy(Dia_Chi[i], Dia_Chi[i + 1]);
		strcpy(Ngay_Lap_The[i], Ngay_Lap_The[i + 1]);
	}
	So_Luong_Doc_Gia--;
}
void TimKiemTheoTen()
{
	printf("moi nhap ten doc gia:\n(co the nhap 1 phan cua ho va ten doc gia, chuong trinh se tim nhung ket qua co phan trung lap)\n");
	/*cac thao tim kiem duoc thuc hien truc tiep trong MenuTimKiemTheoTen*/
}
void TimkiemTheoCMND()
{
	printf("moi nhap so CMND: ");
	/***cac thao tac tim kiem duoc thuc hien truc tiep trong MenuTimKiemTheoCMND****/
}
void _SelectDocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short& So_Luong_Doc_Gia)
{
	int Dieu_Khien_MenuChonDocGia = 0;
	char Dieu_Khien_Menu1DocGia = 0;
	char Muc_Can_Sua_Doc_Gia = 0;
	char Dieu_Khien_MenuXoaDocGia = 0;
	MenuChonDocGia();
	Nhap(Dieu_Khien_MenuChonDocGia);
	if (Dieu_Khien_MenuChonDocGia > So_Luong_Doc_Gia || Dieu_Khien_MenuChonDocGia <= 0);
	else
	{
		do
		{
			Menu1DocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia, Dieu_Khien_MenuChonDocGia);
			Nhap(Dieu_Khien_Menu1DocGia);
			switch (Dieu_Khien_Menu1DocGia)
			{
			case 'b':
				break;
			case 'e':
				MenuSuaDocGia();
				Nhap(Muc_Can_Sua_Doc_Gia);
				SuaDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia, Dieu_Khien_MenuChonDocGia, Muc_Can_Sua_Doc_Gia);
				break;
			case 'd':
				MenuXoaDocGia();
				Nhap(Dieu_Khien_MenuXoaDocGia);
				if (Dieu_Khien_MenuXoaDocGia == 'y')
				{
					XoaDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia, Dieu_Khien_MenuChonDocGia);
					Dieu_Khien_Menu1DocGia = 'b';
				}
				break;
			}
		} while (Dieu_Khien_Menu1DocGia != 'b');
	}
}
void _FindDocGiaBangCMND(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short& So_Luong_Doc_Gia)
{
	char CMNDHienTai[13];
	char Dieu_Khien_MenuTimKiemTheoCMND = 0;

	TimkiemTheoCMND();
	Nhap(CMNDHienTai, 13);
	do
	{
		MenuTimKiemTheoCMND(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia, CMNDHienTai);
		Nhap(Dieu_Khien_MenuTimKiemTheoCMND);
		switch (Dieu_Khien_MenuTimKiemTheoCMND)
		{
		case 'b':
			break;
		case 's':
			_SelectDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		}
	} while (Dieu_Khien_MenuTimKiemTheoCMND != 'b');
}
void _FindDocGiaBangTen(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short& So_Luong_Doc_Gia)
{
	char Ten_Doc_Gia_Hien_Tai[31];
	char Dieu_Khien_MenuTimKiemTheoTen = 0;
	TimKiemTheoTen();
	Nhap(Ten_Doc_Gia_Hien_Tai, 31);
	do
	{
		MenuTimKiemTheoTen(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia, Ten_Doc_Gia_Hien_Tai);
		Nhap(Dieu_Khien_MenuTimKiemTheoTen);
		switch (Dieu_Khien_MenuTimKiemTheoTen)
		{
		case 'b':
			break;
		case 's':
			_SelectDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		}
	} while (Dieu_Khien_MenuTimKiemTheoTen != 'b');
}
void _MenuDanhSachDocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short& So_Luong_Doc_Gia)
{
	char Dieu_Khien_MenuDanhSachDocGia = 0;
	do
	{
		MenuDanhSachDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
		Nhap(Dieu_Khien_MenuDanhSachDocGia);
		switch (Dieu_Khien_MenuDanhSachDocGia)
		{
		case 'b': //back;
			break;
		case 'a': //add 
			ThemDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		case 's': //select
			_SelectDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		case 'c': //cmnd
			_FindDocGiaBangCMND(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		case 'h': //ho va ten
			_FindDocGiaBangTen(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		}
	} while (Dieu_Khien_MenuDanhSachDocGia != 'b');
}