#ifndef _OPTIONS_H_
#define _OPTIONS_H_
#include"INFO.h"

//-------------------------------------
//-------Man Hinh Chinh (Home)---------
void MainOptions(CUS LIST[], int& N);



//-------------------------------------
//------------1. Lap So----------------
void LapSo(CUS LIST[], int& N);

//-------------------------------------
//--------2. Xem 1 khach hang----------
void TimMotKhachHang(CUS LIST[], int& N); //tim 1 khach hang theo ma so
void XemMotKhachHang(int i, CUS LIST[], int& N); //hien thi khach hang va thuc hien cac chuc nang rut tien, huy so
//-----------2. Rut Tien---------------
void RutTien(int i, CUS LIST[], int N);
//------------2.2 Huy So----------------
void HuySo(int i, CUS LIST[], int& N);


//-------------------------------------
//-------3. Tim Kiem Theo Ten----------
void TimKiemTheoTen(CUS LIST[], int N);

//-------------------------------------
//-----------4. Liet Ke----------------
void LietKe(CUS LIST[], int& N);
void LietKeTheoTienGui(CUS LIST[], int N);
void DanhSachKhachHang(CUS LIST[], int& N);

//-------------------------------------
//---------5. Thay Doi Lai Suat--------
void ThayDoiLaiSuat(CUS LIST[], int N);

//-------------------------------------
//--------6. Thong Ke Theo Thang-------
void ThongKe(CUS LIST[], int N);

//-------------------------------------
//--------------7. Thoat---------------
void Thoat(CUS LIST[], int N, FILE** fp);

#endif 

