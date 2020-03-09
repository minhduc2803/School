#ifndef _MENU_H_
#define _MENU_H_
#include"INFO.h"
//-------------------------------------
//-------Man Hinh Chinh (Home)---------
void MenuMainOptions();

//-------------------------------------
//-----------Tieu De Co Dinh-----------
void ConstMenu();

//-------------------------------------
//------------Lap So-------------------
void MenuLapSo();

//-------------------------------------
//------Tim kiem theo ma so------------
void MenuTimMotKhachHang();
//------Thong Tin 1 Khach Hang---------
void MenuXemMotKhachHang(CUS A);
//-----------Rut Tien------------------

//-------------------------------------
//-------Tim Kiem Theo Ten-------------
void MenuTimKiemTheoTen();

//-------------------------------------
//-----------Liet Ke-------------------
void MenuLietKe();
void MenuDanhSachKhachHang(CUS LIST[], int N);

//-------------------------------------
//---------Thay Doi Lai Suat-----------
void MenuThayDoiLaiSuat();

//-------------------------------------
//--------Thong Ke Theo Thang----------
void MenuTruocThongKe();
void MenuSauThongKe(char MAndY[], int Sum, int SumOfMoney);

//-------------------------------------
//---------------Thoat-----------------
void MenuThoat(CUS LIST[], int N, FILE* fp);

#endif


