#ifndef _FUNC_H_
#define _FUNC_H_
#include"HANDING.h"
// Bai 01:
// Kiem tra tep tin cho truoc co ton tai hay khong
// Hamtra ve true neu tep tin ton tai, false neu khong ton tai
bool KiemTra(char filepath[]);

// Bai 02:
// Tra ve kich thuoccua tep tin
int KichThuoc(FILE* fp);

// Bai 03:
//
void Copy(FILE* fp, char filefp[], FILE** copyfp, char newfile[]);

//Bai 04: 
//Chia 1 file thanh cac file nho
void ChiaFile();

//Bai 05:
//Gop cac file nho thanh 1 file lon
void GopFile();

#endif
