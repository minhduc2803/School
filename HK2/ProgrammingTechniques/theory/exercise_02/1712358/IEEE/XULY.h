#ifndef _XULY_H_
#define _XULY_H_
#include<stdio.h>
#include<math.h>
void control(int& flag); //chuyen huong chuong trinh
void Input(float& x); //nhap x
void Sign(float& x, char BiI[]); //xu ly phan dau (bit 0)
void Exponent(float& x, int& Ex, char BiI[]); //xu ly phan so mu (bit 1 -> bit 8)
void Mantissa(float& x, char BiI[]); // xu ly phan dinh tri (bit 9 -> bit 31)
void BiToHex(char BiI[], char HexI[]); // chuyen so nhi phan ve so thap luc phan (so hex)
#endif