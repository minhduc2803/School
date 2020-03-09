#include"MENU.h"

//-------------------------------------
//-------Man Hinh Chinh (Home)---------
void MenuMainOptions()
{
	ConstMenu();
	printf("Nhap vao chu so tuong ung dau cac dich vu roi Enter de thuc hien\n\n");
	printf("1. Lap so tiet kiem\n"
		   "2. Xem thong tin 1 so tiet kiem va thuc hien cac nang rut tien, huy so\n"
		   "3. Tim kiem khach hang theo ten\n"
		   "4. Liet ke tat ca cac so tiet kiem (xem danh sach khach hang)\n"
		   "5. Thay doi lai suat\n"
		   "6. Thong ke cac so tiet kiem theo thang\n"
		   "7. Thoat\n");
}

//-------------------------------------
//-----------Tieu De Co Dinh-----------
void ConstMenu()
{
	system("cls");
	printf("\nUniversity of Science"
		   "\nNguyen Minh Duc"
		   "\n1712358 17CTT3 Ky Thuat Lap Trinh\n\n"
		   "\n------------------------------NGAN HANG GLM---------------------------------\n"
	       "\nWelcome\n\n");
}

//-------------------------------------
//------Tim kiem theo ma so------------
void MenuTimMotKhachHang()
{
	ConstMenu();
	printf("Tim kiem khach hang theo ma so\n");
}
//------Thong Tin 1 Khach Hang---------
void MenuXemMotKhachHang(CUS A)
{
	ConstMenu();
	printf("Thong tin so tiet kiem\n");
	printf("Ho va ten: %s\n"
		   "Ma so: %s\n"
		   "CMND: %s\n"
		   "Ngay lap so: %s\n"
		   "So tien: %s\n"
		   "Lai suat (%%/nam): %.2f\%%\n"
		   "Ky han: ",A.name,A.id,A.cmnd,A.DayIn,A.money,A.RatePerYear);
	if (A.type == 0)
		printf("khong thoi han\n");
	else
		printf("%d thang\n", A.type);
	printf("\n");
	printf("Nhap vao chu so tuong ung dau cac dich vu roi Enter de thuc hien\n\n");
	printf("1. Rut tien\n"
	       "2. Huy so\n"
	       "3. Tro ve\n");
}

//-------------------------------------
//------------Lap So-------------------
void MenuLapSo()
{
	ConstMenu();
	printf("Lap so tiet kiem moi\n");
}

//-------------------------------------
//-------Tim Kiem Theo Ten-------------
void MenuTimKiemTheoTen()
{
	ConstMenu();
	printf("Tim kiem theo ten khach hang\n");
}

//-------------------------------------
//-----------Liet Ke-------------------
void MenuLietKe()
{
	ConstMenu();
	printf("\n\nNhap vao chu so tuong ung dau cac dich vu roi Enter de thuc hien\n\n"
		   "1. Xem danh sach khach hang\n"
		   "2. Liet ke danh sach theo muc do giam dan cua so tien gui\n"
	       "3. Thoat\n");
	
}
void MenuDanhSachKhachHang(CUS LIST[], int N)
{
	ConstMenu();
	printf("Danh Sach Khach hang\n\n");
	printf("STT   Ho va Ten            ID      Ngay Gui     So Tien(vnd)  Lai Suat Ky Han\n");
	if (N == 0)
		printf("                          (Danh sach trong)\n");
	else
	{
		for (int i = 0; i < N; i++)
		{
			printf("%-6d%-21s%-8s%c%c/%c%c/%-7s%-14s%-9.2f", i + 1, LIST[i].name, LIST[i].id, LIST[i].DayIn[0], LIST[i].DayIn[1], LIST[i].DayIn[3], LIST[i].DayIn[4], &LIST[i].DayIn[5], LIST[i].money, LIST[i].RatePerYear);
			if (LIST[i].type == 0)
				printf("%s\n", "none");
			else
				printf("%d thang\n", LIST[i].type);
		}
	}
	printf("\n\nNhap vao chu so tuong ung dau cac dich vu roi Enter de thuc hien\n\n");
	printf("     0. Thoat\n"
		   "Others. Nhap vao so thu tu cua khach hang roi Enter de xem chi tiet\n");
}


//-------------------------------------
//---------Thay Doi Lai Suat-----------
void MenuThayDoiLaiSuat()
{
	ConstMenu();
	printf("Thay doi lai suat\n");
}

//-------------------------------------
//--------Thong Ke Theo Thang----------
void MenuTruocThongKe()
{
	ConstMenu();
	printf("Thong ke kinh doanh trong mot thang\n");
}
void MenuSauThongKe(char MAndY[], int Sum, int SumOfMoney)
{
	ConstMenu();
	printf("Thong ke kinh doanh trong mot thang\n");
	printf("\nTrong thang %s co %d so tiet kiem duoc lap"
		   "\nvoi tong so tien tien gui la: %d\n", MAndY, Sum, SumOfMoney);
	printf("\nNhan phim Bat ky roi Enter de tro lai");
}

//-------------------------------------
//---------------Thoat-----------------
void MenuThoat(CUS LIST[], int N, FILE* fp)
{
	ConstMenu();
	printf("                                 Thank you\n");
}



