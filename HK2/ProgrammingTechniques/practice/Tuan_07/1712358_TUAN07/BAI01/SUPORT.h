#ifndef _SUPORT_H_
#define _SUPORT_H_
#include"INFO.h"
//--------------------------------------
//-----Ham kiem tra ngay thang----------
bool KTNgay(int day, int month, int year); //Kiem tra 1 ngay co ton tai hay khong
int MaxMonth(int month, int year); //Tra ve so ngay toi da cua thang do

//--------------------------------------
//---Ham tim kiem so tiet kiem theo id--
int SearchID(char ID[], CUS LIST[], int N); //ham tra ve so thu tu cua so tiet kiem trong LIST[]

//--------------------------------------
//-Ham chuyen tien kieu char ve kieu int
int TranMoney(char money[]);

//--------------------------------------
//----Ham tinh tien von + lai-----------
bool CountMoney(int moneyBef, int& moneyAf, char DayIn[], char DayOut[], int rate, int type);
float AllMoney(int money, float rate, int monthCount); //Ham ho tro tinh tien lai luy tien, ham tra ve tong so tien von + lai

//--------------------------------------
//---------Sap xep so tiet kiem---------
void SortByMoney(CUS LIST[], int N);

//--------------------------------------
//------------Hoan vi 2 bien------------
void swap(CUS& A, CUS& B);
void copy(CUS& A, CUS C);
void swap(int& A, int& B);

//--------------------------------------
//-------Thay doi lai suat--------------
void ChangeRate(CUS LIST[], int N, int type, float rate);

//--------------------------------------
//--------Thong ke trong 1 thang--------
void ForThongKe(CUS LIST[], int N, char MAndY[], int& Sum, int& SumOfMoney);

//--------------------------------------
//---------Tim kiem theo ten------------
void TimKiemTrongTen(CUS LIST[], int N, char Ten[]);
bool TimKiemTrongTen(char S1[], char S2[]);
bool equal(char S1[], char S2[]);//Ham so tro cho ham TimKiemTrongTen

#endif