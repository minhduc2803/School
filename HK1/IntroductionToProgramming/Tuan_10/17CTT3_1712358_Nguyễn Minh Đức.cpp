					Bài tập thực hành tuần 10
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
  Viết hàm tính thuế thu nhập cá nhân, biết: Biểu thuế thu nhập cá nhân luỹ tiến theo thu nhập tháng
Bậc thuế 	Tổng thu nhập năm 			Thuế suất (%)
1 			Đến 4 triệu 				0
2 			Trên 4 triệu đến 6 triệu 	5
3 			Trên 6 triệu đến 9 triệu 	10
4 			Trên 9 triệu đến 14 triệu 	15
5 			Trên 14 triệu đến 24 triệu 	20
6 			Trên 24 triệu đến 44 triệu 	25
7 			Trên 44 triệu đến 84 triệu 	30
8 			Trên 84 triệu 				35

Câu 2:
Viết hàm đệ qui, và không đệ qui, tính T(n) = n! = 1 x 2 x 3 x…x n. trong đó T(0)=1
Câu 3:
Cho mảng 1 chiều các số nguyên. Viết hàm tính tổng các số chẵn và các số lẻ trong mảng bằng
phương pháp đệ qui, và không đệ qui (dùng vòng lặp).
Câu 4:
Viết hàm đệ qui, và không đệ qui tính tổng của biểu thức sau:
S(x,n) = x + x^2/2! + x^3/3! +…+ x^n/n!
Câu 5:
Tìm ước số lẻ lớn nhất của số nguyên dương n. ví dụ n=100 ước số lẻ lớn nhất của 100 là 25
Câu 6:
Hãy khai báo kiểu dữ liệu để biểu diễn thông tin của một mặt hàng (MATHANG). Biết rằng một
mặt hàng gồm những thành phần sau:
- Tên mặt hàng: chuỗi tối đa 20 ký tự
- Đơn giá: kiểu số nguyên 4 byte
- Số lượng tồn: kiểu số nguyên 4 byte
Viết hàm Nhap, hàm Xuất, cho kiểu dữ liệu này
Câu 7:
hãy khai báo kiểu dữ liệu để biểu diễn thông tin của một thí sinh (THISINH). Biết rằng một thí
sinh gồm những thành phần sau:
- Mã thí sinh: chuỗi tối đa 5 kí tự
- Họ tên thí sinh: chuỗi tối đa 30 ký tự
- Điểm toán: kiểu số thực
- Điểm lý: kiểu số thực
- Điểm hoá: kiểu số thực
- Điểm tổng cộng (TongDiem): kiểu số thực
a) Viết hàm Nhập, hàm Xuất cho kiểu dữ liệu này
b) Viết hàm xếp loại thí sinh này biết:
 Nếu TongDiem >= 15 và không có môn nào bị điểm liệt thì Thí sinh đậu Tốt nghiệp
 Nếu TongDiem >= DiemChuan thì Thí sinh đậu vào trường Đại học KHTN, với DiemChuan
> 15. Khi xét vào Đại học TongDiem cộng thêm điểm ưu tiên, với KVI: 1.5 đ, KVII: 1đ,
KVIII: 0đ
Bài làm:
Câu 1:
#include<stdio.h>
float thue(float ThuNhap);
void main()
{
	float ThuNhap,TienThue;
	printf("moi nhap thu nhap 1 thang (trieu dong), chuong trinh se xuat ra tien thue phai dong: ");
	do
	{
		scanf_s("%f", &ThuNhap);
		if (ThuNhap < 0)
			printf("du lieu nhap khong hop le, Thu Nhap phai lon hon 0. moi nhap lai: ");
		else
			break;
	} while (1);
	TienThue = thue(ThuNhap);
	int PhanNguyenTienThue = int(TienThue);
	if (TienThue >= 1)
		printf("tien thue phai dong la %d trieu %.3f nghin dong\n", PhanNguyenTienThue, 1000*(TienThue - PhanNguyenTienThue));
	else
		printf("tien thue phai dong la %.3f nghin dong\n", TienThue*1000);
}
float thue(float ThuNhap)
{
	float TienThue;
	if (ThuNhap > 84)
		TienThue = 20.15 + (ThuNhap - 84)*0.35;
	else if (ThuNhap > 44)
		TienThue = 8.15 + (ThuNhap - 44)*0.30;
	else if (ThuNhap > 24)
		TienThue = 3.15 + (ThuNhap - 24)*0.25;
	else if (ThuNhap > 14)
		TienThue = 1.15 + (ThuNhap - 14)*0.20;
	else if (ThuNhap > 9)
		TienThue = 0.4 + (ThuNhap - 9)*0.15;
	else if (ThuNhap > 6)
		TienThue = 0.1 + (ThuNhap - 6)*0.10;
	else if (ThuNhap > 4)
		TienThue = (ThuNhap - 4)*0.05;
	else
		TienThue = ThuNhap;
	return TienThue;
}

Câu 2:
#include<stdio.h>
int DeQuy(int N);
int KhongDeQuy(int N);
void main()
{
	int N;
	printf("moi nhap so tu nhien N, chuong trinh se xuat ra day T(n)=1*2*3...*N:  ");
	do
	{
		scanf_s("%d", &N);
		if (N < 0)
			printf("du lieu nhap khong hop le, N la so tu nhien (N>=0). moi nhap lai: ");
		else
			break;
	} while (1);
	printf("de quy: T(n)=%d\n", DeQuy(N));
	printf("khong de quy: T(n)=%d\n", KhongDeQuy(N));
}
int DeQuy(int N)
{
	if (N == 0)
		return 1;
	else
		return N*DeQuy(N - 1);
}
int KhongDeQuy(int N)
{
	int KetQua=1;
	if (N == 0);
	else
	{
		for (int i = 1; i <= N; i++)
		{
			KetQua *= i;
		}
	}
	return KetQua;
}

Câu 3:
#include<stdio.h>
int TongChanDeQuy(int *A, int N, int i);
int TongChanDeQuy(int *A, int N);
int TongLeDeQuy(int *A, int N, int i);
int TongLeDeQuy(int *A, int N);
int TongChanKhongDeQuy(int *A, int N);
int TongLeKhongDeQuy(int *A, int N);
void NhapMang(int *A, int N);
void XuatMang(int *A, int N);
void main()
{
	int N;
	int A[100];
	printf("moi nhap so nguyen duong N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("du lieu nhap khong hop le (N>0). moi nhap lai: ");
		else
			break;
	} while (1);
	NhapMang(A, N);
	XuatMang(A, N);
	printf("\nde quy:\ntong cac so chan trong mang la: %d\ntong cac so le trong mang la: %d\n", TongChanDeQuy(A,N),TongLeDeQuy(A,N));
	printf("\nkhong de quy:\ntong cac so chan trong mang la: %d\ntong cac so le trong mang la: %d\n", TongChanKhongDeQuy(A,N), TongLeKhongDeQuy(A,N));
}
void NhapMang(int *A, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("nhap A[i]: ");
		scanf_s("%d", &A[i]);
	}
}
void XuatMang(int *A, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ",A[i]);
	}
}
int TongChanDeQuy(int *A, int N)
{
	return TongChanDeQuy(A, N, 0);
}
int TongLeDeQuy(int *A, int N)
{
	return TongLeDeQuy(A, N, 0);
}
int TongChanDeQuy(int *A, int N, int i)
{
	int TongChan = 0;
	if (A[i]%2==0)
		TongChan = A[i];
	if (i == N - 1)
		return TongChan;
	return TongChan + TongChanDeQuy(A, N, i + 1);
}
int TongLeDeQuy(int *A, int N, int i)
{
	int TongLe = 0;
	if (A[i] % 2 != 0)
		TongLe = A[i];
	if (i == N - 1)
		return TongLe;
	return TongLe + TongLeDeQuy(A, N, i + 1);
}
int TongChanKhongDeQuy(int *A, int N)
{
	int TongChan = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] % 2 == 0)
			TongChan += A[i];
	}
	return TongChan;
}
int TongLeKhongDeQuy(int *A, int N)
{
	int TongLe = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] % 2 != 0)
			TongLe += A[i];
	}
	return TongLe;
}

Câu 4:
#include<stdio.h>
float DeQuy(float x, float N);
float DeQuy(float x, float N, int i);
float KhongDeQuy(float x, float N);
void main()
{
	float x, N;
	printf("chuong trinh tinh day S(x,N)=x + x^2/2! + x^3/3! +...+ x^n/n!\n");
	printf("moi nhap so nguyen duong N: ");
	do
	{
		scanf_s("%f", &N);
		if (N <= 0)
			printf("du lieu nhap khong hop le (N>0). moi nhap lai: ");
		else
			break;
	} while (1);
	printf("moi nhap x: ");
	scanf_s("%f", &x);
	printf("de quy: S(x,N)=%f\n", DeQuy(x,N));
	printf("khong de quy: S(x,N)=%f\n", KhongDeQuy(x,N));
}
float DeQuy(float x, float N)
{
	return DeQuy(x, N, 1);
}
float DeQuy(float x, float N, int i)
{
	float static tich = 1, giaithua = 1;
	tich *= x;
	giaithua *= i;
	if (i == N)
		return tich / giaithua;
	return tich / giaithua + DeQuy(x, N, i + 1);
}
float KhongDeQuy(float x, float N)
{
	float S = 0, tich = 1, giaithua = 1;
	for (int i = 1; i <= N; i++)
	{
		tich *= x;
		giaithua *= i;
		S = S + tich/giaithua;
	}
	return S;
}

Câu 5:
#include<stdio.h>
#include<math.h>
unsigned int UocLeLonNhat(unsigned int N);
void main()
{
	unsigned int N, UocLe;
	printf("chuong trinh tinh uoc so le lon nhat cua so nguyen duong N\n");
	printf("N cung la uoc cua chinh no, nen neu N le thi uoc so le lon nhat cua N chinh la N\n");
	printf("nhung chuong trinh se xuat ra uoc so le lon nhat nho hon N vi viec xuat ra chinh no khong co y nghia\n");
	printf("(vi ai cung co the tra loi ngay neu N le thi uoc so le lon nhat cua N la N mak khong can dung toi may tinh de tinh toan)\n");
	printf("neu N co uoc so le lon nhat la 1 thi chuong trinh se xuat ra ket qua: \"N khong co uoc so le lon nhat\"\n");
	printf("moi nhap so nguyen duong N: ");
	do
	{
		scanf_s("%u", &N);
		if (N <= 0)
			printf("du lieu nhap khong hop le (N>0). moi nhap lai: ");
		else
			break;
	} while (1);
	UocLe = UocLeLonNhat(N);
	if (UocLe == 1)
		printf("N khong co uoc so le lon nhat\n");
	else
		printf("uoc le lon nhat cua N la: %u\n", UocLe);
}
unsigned int UocLeLonNhat(unsigned int N)
{
	unsigned int UocLe=1;
	unsigned int N2 = sqrt(N); // bien N2 dung de chay chuong trinh tu 1 den N/2
	for (unsigned int i = 2; i <= N2; i++)
		{
			if (N%i == 0)
			{
				unsigned int Uoc = N / i;
				if (Uoc % 2 != 0)
					return Uoc;
			}
			i++;
			if (N%i == 0)
			{
					unsigned int Uoc = N / i;
					if (Uoc % 2 != 0)
						return Uoc;
					else
						UocLe = i;
			}
		}
	return UocLe;
}

Câu 6:
#include<stdio.h>
struct MATHANG {
	char Ten[21];
	int DonGia;
	int SoLuongTon;
}Hang;
void Nhap(char *Ten, int& DonGia, int& SoLuongTon);
void Xuat(char *Ten, int DonGia, int SoLuongTon);
void main()
{
	Nhap(Hang.Ten, Hang.DonGia, Hang.SoLuongTon);
	Xuat(Hang.Ten, Hang.DonGia, Hang.SoLuongTon);
}
void Nhap(char *Ten, int& DonGia, int& SoLuongTon)
{
	printf("moi nhap ten mat hang (toi da 20 ky tu): ");
	gets_s(Ten, 21);
	printf("moi nhap Don Gia: ");
	scanf_s("%d", &DonGia);
	printf("moi nhap so luong hang ton: ");
	scanf_s("%d", &SoLuongTon);
}
void Xuat(char *Ten, int DonGia, int SoLuongTon)
{
	printf("Mat hang: %s\n", Ten);
	printf("Don Gia: %d\n",DonGia);
	printf("So luong hang ton: %d\n", SoLuongTon);
}

Câu 7:
#include<stdio.h>

void nhap(char *Ma_Thi_Sinh, char *Ho_Ten, float& diem_toan, float& diem_ly, float& diem_hoa, float& TongDiem);
void xuat(char *Ma_Thi_Sinh, char *Ho_Ten, float& diem_toan, float& diem_ly, float& diem_hoa, float& TongDiem);
bool xet_dau_tot_nghiep(float diem_toan, float diem_ly, float diem_hoa, float TongDiem);
bool xet_dau_dai_hoc(float diem_toan, float diem_ly, float diem_hoa, float TongDiem);
void main()
{
	struct THISINH {
		char Ma_Thi_Sinh[6];
		char Ho_Ten[31];
		float diem_toan;
		float diem_ly;
		float diem_hoa;
		float TongDiem;
	}duc;
	nhap(duc.Ma_Thi_Sinh, duc.Ho_Ten, duc.diem_toan, duc.diem_ly, duc.diem_hoa, duc.TongDiem);
	xuat(duc.Ma_Thi_Sinh, duc.Ho_Ten, duc.diem_toan, duc.diem_ly, duc.diem_hoa, duc.TongDiem);
	bool KQtotnghiep = xet_dau_tot_nghiep(duc.diem_toan,duc.diem_ly,duc.diem_hoa,duc.TongDiem);
	printf("ket qua tot nghiep cua thi sinh: ");
	if (KQtotnghiep)
		printf("dau\n");
	else
		printf("rot\n");
	bool KQdaihoc = xet_dau_dai_hoc(duc.diem_toan, duc.diem_ly, duc.diem_hoa, duc.TongDiem);
	printf("ket qua tuyen sinh vao truong KHTN cua thi sinh: ");
	if (KQdaihoc)
		printf("dau\n");
	else
		printf("rot\n");
}
void nhap(char *Ma_Thi_Sinh, char *Ho_Ten, float& diem_toan, float& diem_ly, float& diem_hoa, float& TongDiem)
{
	printf("moi nhap ma thi sinh (ma thi sinh chi gom duy nhat 5 chu so): ");
	gets_s(Ma_Thi_Sinh, 6);
	printf("moi nhap ho ten thi sinh: ");
	gets_s(Ho_Ten, 31);
	printf("moi nhap lan luot diem toan, diem ly va diem hoa cua thi sinh ");
	scanf_s("%f%f%f", &diem_toan, &diem_ly, &diem_hoa);
	TongDiem = diem_toan + diem_hoa + diem_ly;
}
void xuat(char *Ma_Thi_Sinh, char *Ho_Ten, float& diem_toan, float& diem_ly, float& diem_hoa, float& TongDiem)
{
	printf("Ho va Ten: %s\nMa so thi sinh: %s\ndiem toan: %.2f\ndiem hoa: %.2f\ndiem ly: %.2f\nTong diem: %.2f\n", Ho_Ten, Ma_Thi_Sinh, diem_toan, diem_ly, diem_hoa, TongDiem);
}
bool xet_dau_tot_nghiep(float diem_toan, float diem_ly, float diem_hoa, float TongDiem)
{
	int DiemLiet;
	printf("moi nhap diem liet: ");
	scanf_s("%d", &DiemLiet);
	printf("thi sinh dau tot nghiep neu tong diem lon hon hoac bang 15 diem va tat ca diem cac mon phai lon hon diem liet\n");
	if (diem_toan > DiemLiet && diem_ly > DiemLiet && diem_hoa > DiemLiet && TongDiem >= 15)
		return true;
	else
		return false;
}
bool xet_dau_dai_hoc(float diem_toan, float diem_ly, float diem_hoa, float TongDiem)
{
	int KVucUutien;
	float DiemUuTien;
	float DiemTrungTuyen;
	printf("moi nhap khu vuc uu tien tuyen sinh cua thi sinh (KV1 nhap so 1, KV2 nhap 2, KV3 nhap 3): ");
	do
	{
		scanf_s("%d", &KVucUutien);
		if (KVucUutien != 1 && KVucUutien != 2 && KVucUutien != 3)
			printf("du lieu nhap khong hop le, khu vuc uu tien chi nam trong 3 khu vuc 1 2 hoac 3. moi nhap lai: ");
		else
			break;
	} while (1);
	switch (KVucUutien)
	{
	case 1: DiemUuTien = 1.5; break;
	case 2: DiemUuTien = 1; break;
	case 3: DiemUuTien = 0; break;
	}
	printf("moi nhap diem trung tuyen vao truong KHTN (diem trung tuyen lon hon 15 diem): ");
	do
	{
		scanf_s("%f", &DiemTrungTuyen);
		if (DiemTrungTuyen<=15)
			printf("du lieu nhap khong hop le, diem trung tuyen phai lon hon 15 diem. moi nhap lai: ");
		else
			break;
	} while (1);
	printf("thi sinh duoc dau vao truong KHTN neu tong diem + diem uu tien >= diem chuan\n");
	if (TongDiem + DiemUuTien >= DiemTrungTuyen)
		return true;
	else
		return false;
}