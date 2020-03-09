#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/******************************************************************************/
/*thu vien gom cac ham xu ly thuat toan co ban va cac ham bieu dien menu (in ra man hinh)*/

//phan cac ham xu ly
void Nhap(char& S)
{
	do
	{
		S = getchar();
	} while (S == '\n');
}
void Nhap(char S[], int So_Ky_Tu)
{
	do
	{
		gets_s(S, So_Ky_Tu);
	} while (S[0] == 0);
}
void Nhap(int& S)
{
	do
	{
		scanf_s("%d", &S);
	} while (S == '\n');
}
int songaytrongnam(int nam)
{
	if (nam % 400 == 0 || (nam % 4 == 0 && (nam % 100 != 0)))
		return 366;
	else
		return 365;
}
int songaytrongthang(int thang, int nam)
{
	switch (thang)
	{
	case 4: case 6: case 9: case 11: return 30;
	case 2: if (nam % 400 == 0 || (nam % 4 == 0 && (nam % 100 != 0))) return 29; else return 28;
	default: return 31;
	}
}
bool KiemTraNgayHopLe(char Ngay[])
{
	int ngay = (Ngay[0] - '0') * 10 + Ngay[1] - '0';
	int thang = (Ngay[2] - '0') * 10 + Ngay[3] - '0';
	int nam = (Ngay[4] - '0') * 1000 + (Ngay[5] - '0') * 100 + (Ngay[6] - '0') * 10 + Ngay[7] - '0';
	if (nam >= 1 && nam <= 9999)
	{
		if (thang >= 1 && thang <= 12)
		{
			int maxthang = songaytrongthang(thang, nam);
			if (ngay >= 1 && ngay <= maxthang)
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool SoSanhKyTu(char S1, char S2)
{
	char j = 'a' - 'A';
	if (((S1 >= 'A' && S1 <= 'Z') || (S1 >= 'a' && S1 <= 'z')) && ((S2 >= 'A' && S2 <= 'Z') || (S2 >= 'a' && S2 <= 'z')))
	{
		if (S1 == S2 || S1 == S2 + j || S1 == S2 - j)
			return true;
		else
			return false;
	}
	else
	{
		if (S1 == S2)
			return true;
		else
			return false;
	}
}
bool TimKiemChuoi(char S1[], char S2[], int i)
{
	
	for (int j = 0; S1[j] != 0; j++)
	{
		if (!SoSanhKyTu(S1[j],S2[i]))
			return false;
		i++;
	}
	return true;
}
bool TimKiemChuoi(char S1[], char S2[])
{
	for (int i = 0; S2[i] != 0; i++)
	{
		if (TimKiemChuoi(S1, S2, i))
			return true;
	}
	return false;
}

void MenuChinh()
{
	system("cls");
	printf("CHAO MUNG BAN DEN VOI PHAN MEM QUAN LY THU VIEN TRUONG DH KHTN tpHCM\n");
	printf("(phien ban anpha)\n");
	printf("            1: Xem danh sach doc gia\n");
	printf("            2: Xem danh sach cac sach co trong thu vien\n");
	printf("            3: Lap phieu muon va tra sach\n");
	printf("            4: Xem cac thong ke co ban\n");
	printf("            5: Cap nhat ngay hom nay\n");
	printf("            b: thoat\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}

/*****************************************************/
// phan cac menu lien quan den doc gia
void MenuDanhSachDocGia(char Ten_Doc_Gia[1000][31],
char Ma_Doc_Gia[1000][14],
char CMND[1000][13],
char Ngay_Sinh[1000][15],
char Gioi_Tinh[1000],
char Email[1000][30],
char Dia_Chi[1000][31],
char Ngay_Lap_The[1000][15],
unsigned short So_Luong_Doc_Gia)
{
	system("cls");
	printf("			Danh Sach Doc Gia\n");
	printf("SKD  Ma doc gia    Ho va ten                Ngay sinh   Gioi tinh CMND\n");
	if (So_Luong_Doc_Gia == 0)
	{
		printf("			(danh sach trong)\n");
		printf("\nTuy chon\n");
	}
	else
	{
		for (int i = 0; i < So_Luong_Doc_Gia; i++)
		{
			printf("%-5d%-14s%-25s%-12s%-10s%s\n", i + 1, Ma_Doc_Gia[i], Ten_Doc_Gia[i], Ngay_Sinh[i], (Gioi_Tinh[i]=='0') ? "Nam" : "Nu", CMND[i]);
		}
		printf("\nTuy chon\n");
		printf("s (select): Chon 1 doc gia de xem chi tiet va thuc hien 1 so chuc nang\n");
	}
	printf("a (add): Them doc gia\n");
	printf("c (cmnd): Tim kiem doc gia theo CMND\n");
	printf("h (ho ten): Tim kiem doc gia theo ho ten\n");
	printf("b (back): thoat\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void MenuChonDocGia()
{
	printf("Nhap vao STT cua doc gia de chon va tiep tuc\n");
}
void Menu1DocGia(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia,
	int So_Thu_Tu_Doc_Gia)
{
	system("cls");
	printf("1) Ho va ten: %s\n", Ten_Doc_Gia[So_Thu_Tu_Doc_Gia - 1]);
	printf("2) Ma doc gia: %s\n", Ma_Doc_Gia[So_Thu_Tu_Doc_Gia - 1]);
	printf("3) So CMND: %s\n", CMND[So_Thu_Tu_Doc_Gia - 1]);
	printf("4) Ngay thang nam sinh: %c%c/%c%c/%c%c%c%c\n", Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][0], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][1], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][2], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][3], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][4], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][5], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][6], Ngay_Sinh[So_Thu_Tu_Doc_Gia - 1][7]);
	printf("5) Gioi tinh: %s\n", Gioi_Tinh[So_Thu_Tu_Doc_Gia - 1] == '0' ? "Nam" : "Nu");
	printf("6) Email: %s\n", Email[So_Thu_Tu_Doc_Gia - 1]);
	printf("7) Dia chi: %s\n", Dia_Chi[So_Thu_Tu_Doc_Gia - 1]);
	printf("8) Ngay lap the: %c%c/%c%c/%c%c%c%c\n", Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][0], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][1], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][2], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][3], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][4], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][5], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][6], Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1][7]);
	/* tao ngay het han cua the doc gia*/
	char Ngay_Het_Han[9];
	strcpy(Ngay_Het_Han, Ngay_Lap_The[So_Thu_Tu_Doc_Gia - 1]);
	Ngay_Het_Han[7] += 4;
	for (int i = 7; i >4; i--)
	{
		if (Ngay_Het_Han[i] > '9')
		{
			Ngay_Het_Han[i] -= 10;
			Ngay_Het_Han[i - 1]++;
		}
	}
	printf("Ngay het han: %c%c/%c%c/%c%c%c%c\n", Ngay_Het_Han[0], Ngay_Het_Han[1], Ngay_Het_Han[2], Ngay_Het_Han[3], Ngay_Het_Han[4], Ngay_Het_Han[5], Ngay_Het_Han[6], Ngay_Het_Han[7]);
	printf("\nTuy chon:\ne (edit): sua thong tin doc gia\n");
	printf("d (delete): xoa doc gia \n");
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void MenuSuaDocGia()
{
	printf("nhap vao chu so dau dong tuong ung voi phan noi dung ban muon sua\n(muc 1, tu muc 3 den muc 8. rieng muc 2) Ma doc gia duoc tao tu dong, khong the chinh sua)\n");
}
void MenuXoaDocGia()
{
	printf("Ban co chac muon xoa doc gia nay khoi danh sach (khong the hoan tac)\n");
	printf("Nhan phim y (yes) roi Enter de tiep tuc xoa\n");
	printf("Nhan phim bat ky (tru phim y) roi Enter de huy thao tac\n");
}
void MenuTimKiemTheoCMND(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia,
	char CMNDHienTai[13])
{
	bool flag = false;
	system("cls");
	printf("Ket qua tim kiem theo so CMND: %s\n",CMNDHienTai);
	printf("SKD  Ma doc gia    Ho va ten                Ngay sinh   Gioi tinh CMND\n");
	if (So_Luong_Doc_Gia == 0)
		printf("			(danh sach trong)\n");
	else
	{
		for (int i = 0; i < So_Luong_Doc_Gia; i++)
		{
			if (strcmp(CMNDHienTai, CMND[i]) == 0)
			{
				flag = true;
				printf("%-5d%-14s%-25s%-12s%-10s%s\n", i + 1, Ma_Doc_Gia[i], Ten_Doc_Gia[i], Ngay_Sinh[i], (Gioi_Tinh[i] == '0') ? "Nam" : "Nu", CMND[i]);
			}
		}
		if (!flag)
			printf("			(danh sach trong)\n");
		printf("\nTuy chon:\ns (select): Chon 1 doc gia de xem chi tiet va thuc hien 1 so chuc nang\n");
	}
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void MenuTimKiemTheoTen(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia,
	char Ten_Doc_Gia_Hien_Tai[13])
{
	bool flag = false;
	system("cls");
	printf("Ket qua tim kiem theo ten doc gia: %s\n", Ten_Doc_Gia_Hien_Tai);
	printf("SKD  Ma doc gia    Ho va ten                Ngay sinh   Gioi tinh CMND\n");
	if (So_Luong_Doc_Gia == 0)
		printf("			(danh sach trong)\n");
	else
	{
		for (int i = 0; i < So_Luong_Doc_Gia; i++)
		{
			if (TimKiemChuoi(Ten_Doc_Gia_Hien_Tai,Ten_Doc_Gia[i]))
			{
				flag = true;
				printf("%-5d%-14s%-25s%-12s%-10s%s\n", i + 1, Ma_Doc_Gia[i], Ten_Doc_Gia[i], Ngay_Sinh[i], (Gioi_Tinh[i] == '0') ? "Nam" : "Nu", CMND[i]);
			}
		}
		if (!flag)
			printf("			(danh sach trong)\n");
		printf("\nTuy chon:\ns (select): Chon 1 doc gia de xem chi tiet va thuc hien 1 so chuc nang\n");
	}
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}

/*********************************/
// phan cac menu lien quan toi sach
void MenuDanhSachCacSach(char ISBN[1000][21],
char Ten_Sach[1000][41],
char Tac_Gia[1000][31],
char Nha_Xuat_Gia[1000][31],
int Nam_Xuat_Ban[1000],
char The_Loai[1000][31],
int Gia_Sach[1000],
int So_Quyen_Sach[1000],
unsigned short So_Luong_Sach)
{
	system("cls");
	printf("Danh Sach Cac Dau Sach Co Trong Thu Vien\n");
	printf("SKD  ISBN(Ma sach) Ten Sach                            The Loai\n");
	if (So_Luong_Sach == 0)
	{
		printf("                   (danh sach trong)\n");
		printf("\nTuy chon\n");
	}
	else
	{
		for (int i = 0; i < So_Luong_Sach; i++)
		{
			printf("%-5d%-14s%-36s%s\n", i + 1, ISBN[i], Ten_Sach[i], The_Loai[i]);
		}
		printf("\nTuy chon\n");
		printf("s (select): chon 1 dau sach de xem chi tiet va thuc hien 1 so chuc nang\n");
	}
	printf("a (add): them dau sach\n");
	printf("i (isbn): tim sach theo ISBN (ma sach)\n");
	printf("t (ten sach): tim sach theo ten sach\n");
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void MenuChonSach()
{
	printf("moi nhap vao STT cua dau sach tuong ung de chon va tiep tuc\n");
}
void Menu1LoaiSach(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short So_Luong_Sach,
	int So_Thu_Tu_Sach)
{
	system("cls");
	printf("Thong tin chi tiet dau sach\n");
	printf("1) ISBN(ma sach): %s\n", ISBN[So_Thu_Tu_Sach -1]);
	printf("2) Ten sach: %s\n", Ten_Sach[So_Thu_Tu_Sach -1]);
	printf("3) Tac gia: %s\n", Tac_Gia[So_Thu_Tu_Sach -1]);
	printf("4) Nha xuat ban: %s\n", Nha_Xuat_Gia[So_Thu_Tu_Sach -1]);
	printf("5) Nam xuat ban: %d\n", Nam_Xuat_Ban[So_Thu_Tu_Sach -1]);
	printf("6) The loai: %s\n", The_Loai[So_Thu_Tu_Sach -1]);
	printf("7) Gia sach: %d dong\n", Gia_Sach[So_Thu_Tu_Sach -1]);
	printf("8) So luong sach: %d cuon\n", So_Quyen_Sach[So_Thu_Tu_Sach -1]);
	printf("\nTuy chon\n");
	printf("e (edit): sua thong tin sach\n");
	printf("d (delete): xoa sach \n");
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void MenuSuaSach()
{
	printf("moi nhap vao chu so dau dong thong tin ban muon sua: ");
}
void MenuXoaSach()
{
	printf("Ban co chac muon xoa thong tin dau sach nay?\n");
	printf("Nhan phim y (yes) de tiep tuc\n");
	printf("Nhan phim bat ky(tru phim y) de huy\n");
}
void MenuTimSachTheoISBN(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short So_Luong_Sach,
	char ISBNHienTai[21])
{
	bool flag = false;
	system("cls");
	printf("Ket qua tim kiem dau sach theo ISBN: %s\n", ISBNHienTai);
	printf("SKD  ISBN(Ma sach) Ten Sach                            The Loai\n");
	if (So_Luong_Sach == 0)
	{
		printf("                   (danh sach trong)\n");
		printf("\nTuy chon\n");
	}
	else
	{
		for (int i = 0; i < So_Luong_Sach; i++)
		{
			if (strcmp(ISBNHienTai, ISBN[i]) == 0)
			{
				flag = true;
				printf("%-5d%-14s%-36s%s\n", i + 1, ISBN[i], Ten_Sach[i], The_Loai[i]);
			}
		}
		if (flag)
		{
			printf("\nTuy chon\n");
			printf("s (select): chon 1 dau sach de xem chi tiet va thuc hien 1 so chuc nang\n");
		}
		else
		{
			printf("                   (danh sach trong)\n");
			printf("\nTuy chon\n");
		}
	}
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void MenuTimSachTheoTen(char ISBN[1000][21],
	char Ten_Sach[1000][41],
	char Tac_Gia[1000][31],
	char Nha_Xuat_Gia[1000][31],
	int Nam_Xuat_Ban[1000],
	char The_Loai[1000][31],
	int Gia_Sach[1000],
	int So_Quyen_Sach[1000],
	unsigned short So_Luong_Sach,
	char Ten_Sach_Hien_Tai[41])
{
	bool flag = false;
	system("cls");
	printf("Ket qua tim kiem dau sach theo ten: %s\n", Ten_Sach_Hien_Tai);
	printf("SKD  ISBN(Ma sach) Ten Sach                            The Loai\n");
	if (So_Luong_Sach == 0)
	{
		printf("                   (danh sach trong)\n");
		printf("\nTuy chon\n");
	}
	else
	{
		for (int i = 0; i < So_Luong_Sach; i++)
		{
			if (TimKiemChuoi(Ten_Sach_Hien_Tai,Ten_Sach[i]))
			{
				flag = true;
				printf("%-5d%-14s%-36s%s\n", i + 1, ISBN[i], Ten_Sach[i], The_Loai[i]);
			}
		}
		if (flag)
		{
			printf("\nTuy chon\n");
			printf("s (select): chon 1 dau sach de xem chi tiet va thuc hien 1 so chuc nang\n");
		}
		else
		{
			printf("                   (danh sach trong)\n");
			printf("\nTuy chon\n");
		}
	}
	printf("b (back): lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
/******************************************/
// phan cac menu lien quan den lap phieu
void MenuLapPhieuMuonTraSach(char Ten_Doc_Gia[1000][31],
	char Ma_Doc_Gia[1000][14],
	char CMND[1000][13],
	char Ngay_Sinh[1000][15],
	char Gioi_Tinh[1000],
	char Email[1000][30],
	char Dia_Chi[1000][31],
	char Ngay_Lap_The[1000][15],
	unsigned short So_Luong_Doc_Gia)
{
	system("cls");
	printf("\n                   Lap Phieu Muon Sach\n");
	printf("Hay chon 1 doc gia tu danh sach de tiep tuc\n");
	printf("			Danh Sach Doc Gia\n");
	printf("SKD  Ma doc gia    Ho va ten                Ngay sinh   Gioi tinh CMND\n");
	if (So_Luong_Doc_Gia == 0)
	{
		printf("			(danh sach trong)\n");
		printf("\nTuy chon\n");
	}
	else
	{
		for (int i = 0; i < So_Luong_Doc_Gia; i++)
		{
			printf("%-5d%-14s%-25s%-12s%-10s%s\n", i + 1, Ma_Doc_Gia[i], Ten_Doc_Gia[i], Ngay_Sinh[i], (Gioi_Tinh[i] == '0') ? "Nam" : "Nu", CMND[i]);
		}
		printf("\nTuy chon\n");
		printf("s (select): Chon 1 doc gia de tiep tuc lap phieu\n");
		printf("c (cmnd): Tim kiem doc gia theo CMND\n");
		printf("h (ho ten): Tim kiem doc gia theo ho ten\n");
	}
	printf("b (back): thoat\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}
void CapNhatNgay(char Ngay_Hom_Nay[15])
{
	system("cls");
	printf("Dau tien...\n");
	printf("Hom nay la ngay may?\n");
	printf("Ngay hom nay:\n(nhap 1 day so lien tuc xxyyzzzz, xx-ngay, yy-thang, zzzz-nam");
	printf("Luu y: Ngay hoac thang phai la 1 so co 2 chu so, neu chi co 1 so thi them so 0 dang truoc\n");
	printf("VD hom nay la ngay 1 thang 2 nam 1999 thi nhap 01021999)\n");
	do
	{
		Nhap(Ngay_Hom_Nay, 15);
		if (!KiemTraNgayHopLe(Ngay_Hom_Nay))
			printf("Ngay ban vua nhap khong hop le, moi nhap lai: ");
		else
			break;
	} while (1);
}
/*******************************/
//phan menu thong ke
void MenuThongKe()
{
	system("cls");
	printf("Tuy chon\n");
	printf("1: Thong ke so luong sach trong thu vien\n");
	printf("2: Thong ke so luong sach theo the loai\n");
	printf("3: Thong ke so luong doc gia\n");
	printf("4: Thong ke so luong doc gia theo gioi tinh\n");
	printf("5: Thong ke so sach dang duoc muon\n");
	printf("6: Thong ke danh sach doc gia bi tre han\n");
	printf("b: lui lai\n");
	printf("nhap vao ky tu dau dong moi lenh roi Enter de thuc hien lenh tuong ung\n");
}