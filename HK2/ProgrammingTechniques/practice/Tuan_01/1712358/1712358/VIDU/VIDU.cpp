

#include "NhomTrangWeb.h"


void main()
{
	TRANGWEB t1;
	NHOMTRANGWEB nhomWEB;

	//Ban dau chua co trang web nao trong nhom
	nhomWeb.iSoTrangWeb = 0;

	//Trang web dau tien
	nhapMotTrangWeb(t1);
	themTrangWebNhom(nhomWeb, t1);

	//Trang web tiep theo
	nhapMotTrangWeb(t1);
	themTrangWebNhom(nhomWeb, t1);

	//Sap xep trang web trong nhom
	sapxepTrangWebtheoNgay(nhomWeb);
}

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


file TrangWeb.h


#include "stdio.h"
struct _TRANGWEB
{
	char strTenTrangWeb[50];
	//so luong truy cap trong ngay
	unsigned int iSoLuotNgay;
	//so luot truy cap trong thang
	unsigned int iSoLuotThang;
};

typedef struct _TRANGWEB TRANGWEB;
void nhapMotTrangWeb(TRANGWEB &t);
void xuatMotTrangWeb(TRANGWEB t);

//So sanh so luot truy cap trong ngay
//cua 2 trang web
//Input:
// t1,t2: thong tin cua 2 trang web
//Output:
// 0:so luot truy cap trang web thu 1
//		it hon trang web thu 2
// 1: (nguoc lai)
int sosanh2TrangWeb(TRANGWEB t1, TRANGWEB t2);
#endif

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


File TrangWeb.cpp

#include "TrangWeb.h"

void nhapMotTrangWeb(TRANGWEB &t)
{
	printf("Nhap dia chi: ");
	gets(t.strTenTrangWeb);
	printf("Nhap so luot truy cap trong ngay va trong thang: ");
	scanf("%d%d", &t.iSoLuotNgay, &t.iSoLuotThang);
}

void XuatMotTrangWeb(TRANGWEB t)
{
	//sinh vien tu thuc hien
}

//So sanh so luot truy cap trong ngay
//cua 2 trang Web
//Input:
// t1,t2: thong tin cua 2 trang web
//Output:
// 0: so luot truy cap trang web thu 1
//		it hon trang web thu 2
// 1: (nguoc lai)
int sosanh2trangWeb(TRANGWEB t1, TRANGWEB t2)
{
	if (t1.iSoLuotNgay < t2.iSoLuotNgay)
		return 0;
	return 1;
}

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

File NhomTrangWeb.h

#ifndef _nhomtrangweb_
#define _nhomtrangweb_
#include "TrangWeb.h"
#define MAXWEB 50
typedef struct _NHOMTRANGWEB
{
	unsigned int iSoTrangWeb;
	TRANGWEB arrTrangWeb[MAXWEB]; //luu tru toi da 50 trang web
}NHOMTRANGWEB;
//them thong tin 1 trang web t vao nhom trang web
void themTrangWebNhom(NHOMTRANGWEB &nhomTrangWeb, TRANGWEB t);
// xuat trang web co stt iStt trong nhom
void xuatTrangWebNhom(NHOMTRANGWEB nhomTrangWeb, int iStt);
// Sap xep cac trang web giam dan theo so luot
//truy cap trong ngay
void sapxepTrangWebtheoNgay(NHOMTRANGWEB &nhomTrangWeb);
#endif

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

File NhomTrangWeb.cqq


#include "NhomTrangWeb.h"
//Them thong tin 1 trang web t vao nhom trang web
void themTrangWebNhom(NHOMTRANGWEB &nhomTrangWeb, TRANGWEB t)
{
	if (NhomTrangWeb.isoTrangWeb >= MAXWEB)
		printf("Da het cho de them trang web");
	else
	{
		nhomTrangWeb.iSoTrangWeb++;
		nhomTrangWeb.arrTrangWeb[nhomTrangWeb.iSoTrangWeb] = t;

	}
}
// Xuat trang web co so thu tu iStt trong nhom
void xuatTrangWebNhom(NHOMTRANGWEB nhomTrangWeb, int iStt)
{
	if (iStt > nhomTrangWeb.iSoTrangWeb)
		printf("Khong ton tai trang web nay");
	else
		xuatMotTrangWeb(nhomTrangWeb.arrTrangWeb[iStt]);
}
//Sap xep cac trang web giam dan theo so luot truy cap trong ngay
void sapxepTrangWebtheoNgay(NHOMTRANGWEB &nhomTrangWeb)
{
	for (int i = 0; i < nhomTrangWeb.iSoTrangWeb - 1; i++)
		for (int j = 0; j < nhomTrangWeb.iSoTrangWeb; j++)
			if (sosanh2TrangWeb(nhomTrangWeb.arrTrangWeb[i], nhomTrangWeb.arrTrangWeb[j]) == 0)
				//Hoan vi 2 trang web nay trong nhom
				;
}