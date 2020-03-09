#ifndef _FUNC_H_
#define _FUNC_H_
#include"INOUT.h"

//nhap mang so nguyen
void Bai03_1(int A[], int& N);

//xuat mang so nguyen ra man hinh
void Bai03_2(int A[], int N);

//xuat mang so nguyen theo thu tu nguoc
void Bai03_3(int A[], int N);

//tra ve so lon nhat tong mang so nguyen
int Bai03_4(int A[], int N);

//tra ve so luong so nguyen to co trong mang so nguyen
int Bai03_5(int A[], int N);

//tra ve so luong cac gia tri phan biet trong mang
int Bai03_6(int A[], int N, int i);
int Bai03_6(int A[], int N, int i = 0);

//neu mang toan cac gia tri chia het cho 7 -> tra ve true, nguoc lai -> tra ve false
bool Bai03_7(int A[], int N);

//sap xep mang theo thu tu tang dan
void Bai03_8(int A[], int N);
void Bai03_8(int A[], int N, int head, int tail);

//neu A la so nguyen to -> tra ve true, nguoc lai -> tre ve false
bool KTNguyenTo(int A);

//hoan vi 2 so a,b
void swap(int& a, int& b);
#endif

