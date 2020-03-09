#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"quanlydocgia.h"
#include"quanlysach.h"
#include"lapphieu.h"
#include"thongke.h"
#include"MenuVaThaoTac.h"
void main()
{
	// cac bien thuoc ve quan ly doc gia
	char Ten_Doc_Gia[1000][31];
	char Ma_Doc_Gia[1000][14];
	char CMND[1000][13];
	char Ngay_Sinh[1000][15];
	char Gioi_Tinh[1000];
	char Email[1000][30];
	char Dia_Chi[1000][31];
	char Ngay_Lap_The[1000][15];
	unsigned short So_Luong_Doc_Gia=0;
	//cac bien thuoc ve quan ly sach
	char ISBN[1000][21];
	char Ten_Sach[1000][41];
	char Tac_Gia[1000][31];
	char Nha_Xuat_Gia[1000][31];
	int Nam_Xuat_Ban[1000];
	char The_Loai[1000][31];
	int Gia_Sach[1000];
	int So_Quyen_Sach[1000];
	unsigned short So_Luong_Sach = 0;
	//cac bien thuoc ve lap phieu
	bool Tre_Han[1000]; //moi phieu chua so thu tu cua sach, so thu tu cua phieu chinh la key ket noi giua cac bien
	int Tong_So_Sach_Muon[1000] = { 0 };
	char Ngay_Muon[1000][9];
	int SKD_Sach_Duoc_Muon[1000][5];//moi bien chua 1 thu tu cua sach duoc muon, khong duoc muon qua 1 cuon cho 1 dau sach nen khong co thu tu trung nhau
	char Ngay_Hom_Nay[15];
	char Ngay_Muon_Sach[1000][5][15];
	char Han_Tra_Sach[1000][5][15];
	int So_Ngay[1000][5];
									 //cac bien khac
	char Dieu_Khien_MenuChinh=0;
	/************/
	float A[2] = { 1,2 };
	CapNhatNgay(Ngay_Hom_Nay);
	do
	{
		MenuChinh();
		Nhap(Dieu_Khien_MenuChinh);
		switch (Dieu_Khien_MenuChinh)
		{
		case 'b': //back
			break;
		case '1': 
			_MenuDanhSachDocGia(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia);
			break;
		case '2':
			_MenuDanhSachCacSach(ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach);
			break;
		case '3':
			_MenuLapPhieuMuonTraSach(Ten_Doc_Gia, Ma_Doc_Gia, CMND, Ngay_Sinh, Gioi_Tinh, Email, Dia_Chi, Ngay_Lap_The, So_Luong_Doc_Gia, ISBN, Ten_Sach, Tac_Gia, Nha_Xuat_Gia, Nam_Xuat_Ban, The_Loai, Gia_Sach, So_Quyen_Sach, So_Luong_Sach, SKD_Sach_Duoc_Muon, Tong_So_Sach_Muon, Ngay_Hom_Nay, Ngay_Muon_Sach, Han_Tra_Sach, So_Ngay);
			break;
		case '4':
			_MenuThongKe();
			break;
		case '5':
			CapNhatNgay(Ngay_Hom_Nay);
			break;
		}
	} while (Dieu_Khien_MenuChinh != 'b');
}

