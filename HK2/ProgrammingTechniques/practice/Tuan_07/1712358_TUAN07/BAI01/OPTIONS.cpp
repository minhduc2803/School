#include"OPTIONS.h"
#include"MENU.h"
#include"INOUT.h"
//-------------------------------------
//-------Man Hinh Chinh (Home)---------
void MainOptions(CUS LIST[], int& N)
{
	int stick;
	do
	{
		MenuMainOptions();
		Input(stick);
		switch (stick)
		{
		case 1: LapSo(LIST, N); break;
		case 2: TimMotKhachHang(LIST, N); break;
		case 3: TimKiemTheoTen(LIST, N); break;
		case 4: LietKe(LIST, N); break;
		case 5: ThayDoiLaiSuat(LIST, N); break;
		case 6: ThongKe(LIST, N); break;
		case 7: break;
		default: printf("Khong ton tai dich vu, moi nhap lai\n"); break;
		}
	} while (stick != 7);
}

//-------------------------------------
//-----------Xem 1 khach hang----------
void TimMotKhachHang(CUS LIST[], int& N)
{
	char ID[11];
	int i;
	int stick = 0;
	MenuTimMotKhachHang();
	printf("Moi nhap vao ma so so tiet kiem cua khach hang: ");
	do
	{
		Input(ID, 10);
		i = SearchID(ID, LIST, N);
		if (i >= N)
		{
			printf("Khong the tim thay so tiet kiem nao trung khop\n");
			printf("Nhan phim bat ky de nhap ma so moi\n"
				   "Nhan 0 de thoat\n");
			Input(stick);
		}
		else
		{
			XemMotKhachHang(i, LIST, N);
			break;
		}
	} while (stick != 0);
}
void XemMotKhachHang(int i, CUS LIST[], int& N)
{
	
	int stick;
	do
	{
		MenuXemMotKhachHang(LIST[i]);
		Input(stick);
		switch (stick)
		{
		case 1: RutTien(i,LIST,N); break;
		case 2: HuySo(i, LIST, N); stick = 3;  break;
		case 3: break;
		}
	} while (stick != 3);
}
//-----------2.1 Rut Tien---------------
void RutTien(int i, CUS LIST[], int N)
{
	char Day[12];
	int moneyBef = TranMoney(LIST[i].money);
	int moneyAf;
	printf("\nChuc nang: Rut tien\n");
	printf("Hom nay la ngay (nhap vao theo dinh dang dd/mm/yy): ");
	InputDay(Day, LIST, N);
	if (CountMoney(moneyBef, moneyAf, LIST[i].DayIn, Day, LIST[i].RatePerYear, LIST[i].type))
	{
		printf("Tien von: %d vnd\n"
			   "Tien Lai: %d vnd\n"
			   "Tien von + lai: %d vnd\n", moneyBef, moneyAf - moneyBef, moneyAf);
	}
	else
	{
		printf("So tiet kiem nay chua du ky han, so tien von la: %d vnd\n", moneyBef);
	}
	char moneyChar[15];
	itoa(0, moneyChar, 10);
	int stick;
	printf("\nKhach hang co chac muon rut tien\n"
		   "1. Rut tien lai (khi rut, ngay lap so se duoc thiet lap lai thanh ngay hom nay)\n"
		   "2. Rut tien von + lai\n"
	       "3. Thoat\n");
	do
	{
		Input(stick);
		switch (stick)
		{
		case 1: strcpy(LIST[i].DayIn, Day); stick = 3; break;
		case 2: strcpy(LIST[i].money, moneyChar); stick = 3; break;
		case 3: break;
		}
		
	} while (stick != 3);
	system("pause");
}
//------------2.2 Huy So----------------
void HuySo(int i, CUS LIST[], int& N)
{
	int stick;
	printf("Ban co chac muon huy so tiet kiem nay\n");
	printf("1. Yes, chac chan\n"
		   "2. No, Tro ve\n");
	do
	{
		Input(stick);
		if (stick == 1)
		{
			copy(LIST[i], LIST[N - 1]);
			break;
		}
	} while (stick != 2);
	N--;
}

//-------------------------------------
//------------1. Lap So----------------
void LapSo(CUS LIST[], int& N)
{
	MenuLapSo();

	printf("Moi nhap day du cac thong tin sau:\n");

	printf("Ten khach hang: ");
	Input(LIST[N].name, 30);

	printf("Ma so (la 1 chuoi so gom 10 chu so): ");
	InputID(LIST[N].id, LIST, N);

	printf("CMND: ");
	Input(LIST[N].cmnd, 15);

	printf("Hom nay la ngay (nhap vao theo dinh dang dd/mm/yy): ");
	InputDay(LIST[N].DayIn,LIST,N);

	printf("So tien gui: ");
	Input(LIST[N].money, 14);
	
	printf("Ky han gui\n"
		   "Vo thoi han: nhap 0\n"
		   "1 thang: chon 1\n"
		   "3 thang: nhap 3\n"
		   "6 thang: nhap 6\n"
		   "12 thang: nhap 12\n");
	InputType(LIST[N].type);

	printf("Lai suat (%%/nam, VD 3.1%%nam nhap 3.1 roi Enter): ");
	Input(LIST[N].RatePerYear);

	N++;
	XemMotKhachHang(N-1,LIST,N);
}

//-------------------------------------
//-------3. Tim Kiem Theo Ten----------
void TimKiemTheoTen(CUS LIST[], int N)
{
	MenuTimKiemTheoTen();
	char Ten[31];
	printf("Chuong trinh se tim nhung khach hang co ten co 1 phan la chuoi ky tu nhap vao\n"
	       "Chuong trinh se hien thi toan bo danh sach theo thu tu uu tien tim duoc\n"
	       "Moi nhap vao 1 chuoi ky tu: ");
	Input(Ten,30);
	TimKiemTrongTen(LIST, N, Ten);

	DanhSachKhachHang(LIST, N);
}

//-------------------------------------
//-----------4. Liet Ke----------------
void LietKe(CUS LIST[], int& N)
{
	int stick;
	do
	{
		MenuLietKe();
		Input(stick);
		switch (stick)
		{
		case 1: DanhSachKhachHang(LIST, N); break;
		case 2: LietKeTheoTienGui(LIST, N); DanhSachKhachHang(LIST, N); break;
		case 3: break;
		}
	} while (stick != 3);
}
void LietKeTheoTienGui(CUS LIST[], int N)
{
	SortByMoney(LIST, N);
}
void DanhSachKhachHang(CUS LIST[], int& N)
{
	int stick;
	do
	{
		MenuDanhSachKhachHang(LIST, N);
		Input(stick);
		switch (stick)
		{
		case 0: break;
		default: if (stick > 0 && stick <= N) XemMotKhachHang(stick-1, LIST, N); break;
		}
	} while (stick != 0);
}


//-------------------------------------
//---------6. Thay Doi Lai Suat--------
void ThayDoiLaiSuat(CUS LIST[], int N)
{
	MenuThayDoiLaiSuat();
	float rate;
	int type;
	printf("\nMoi nhap vao loai ky han can thay doi lai suat\n"
		   "Vo thoi han: nhap 0\n"
		   "1 thang: chon 1\n"
		   "3 thang: nhap 3\n"
		   "6 thang: nhap 6\n"
		   "12 thang: nhap 12\n");
	InputType(type);
	printf("Moi nhap lai suat moi (%%/nam, VD 3.1%%/nam nhap 3.1 roi Enter)\n");
	Input(rate);
	ChangeRate(LIST, N, type, rate);
	int stick;
	printf("Thay doi thanh cong, nhan phim bat ky roi Enter de tiep tuc\n");
	Input(stick);
}

//-------------------------------------
//--------7. Thong Ke Theo Thang-------
void ThongKe(CUS LIST[], int N)
{
	MenuTruocThongKe();
	char MAndY[11];
	printf("Moi nhap vao thang va nam theo dinh dang mm/yy\n");
	InputMAndY(MAndY);
	int Sum = 0;
	int SumOfMoney = 0;
	ForThongKe(LIST, N, MAndY, Sum, SumOfMoney);
	MenuSauThongKe(MAndY, Sum, SumOfMoney);
	int stick;
	Input(stick);
}

//-------------------------------------
//--------------8. Thoat---------------
void Thoat(CUS LIST[], int N, FILE** fp)
{

}
