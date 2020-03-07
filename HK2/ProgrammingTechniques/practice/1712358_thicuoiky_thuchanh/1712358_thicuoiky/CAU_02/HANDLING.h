#ifndef _HANDLING_H_
#define _HANDLING_H_
#include<stdio.h>
#include "INFO.h"

//khoi tao anh sach lien ket
void Initialize(LIST* L);
//neu danh sach rong -> return true, else -> return false
bool TestEmptyList(LIST* L);
//tra ve tong cua danh sach
int SumOfList(LIST* L);
//them 1 phan tu vao duoi danh sach
void AddTail(LIST* L, int x);
//neu x la so nguyen to, -> return true, else -> return false
bool TestPrime(int x);
//tach cac so nguyen to vao l1, cac so con lai vao l2
void TachDanhSach(LIST* L, LIST* l1, LIST* l2);

#endif
