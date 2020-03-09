#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MenuVaThaoTac.h"
void MuonSach()
{
	printf("\nchuc nang khong kha dung\n");
	system("pause");
}
void TraSach()
{
	printf("\nchuc nang khong kha dung\n");
	system("pause");
}
void MatSach()
{
	printf("\nchuc nang khong kha dung\n");
	system("pause");
}
void _MenuLapPhieuMuonTraSach(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia,
	char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short So_Luong_Sach,
	int SKD_Sach_Duoc_Muon[1000][5],
	int Tong_So_Sach_Muon[1000],
	char Ngay_Hom_Nay[15],
	char Ngay_Muon_Sach[1000][5][15],
	char Han_Tra_Sach[1000][5][15],
	int So_Ngay[1000][5])
{
	char Dieu_Khien_MenuLapPhieuMuonTraSach = 0;
	char Dieu_Khien_Menu1DocGia_Phieu = 0;
	char STT_DocGia = 0;
	do
	{
		MenuLapPhieuMuonTraSach(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
		Nhap(Dieu_Khien_MenuLapPhieuMuonTraSach);
		switch (Dieu_Khien_MenuLapPhieuMuonTraSach)
		{
		case 's':
			printf("\nchuc nang khong kha dung\n");
			system("pause");
			break;
		case 'c':
			printf("\nchuc nang khong kha dung\n");
			system("pause");
			break;
		case 'h':
			printf("\nchuc nang khong kha dung\n");
			system("pause");
			break;
		}
	} while (Dieu_Khien_MenuLapPhieuMuonTraSach != 'b');
}
