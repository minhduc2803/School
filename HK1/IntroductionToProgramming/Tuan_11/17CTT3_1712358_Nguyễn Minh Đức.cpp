					Bài tập thực hành tuần 11
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
  Viết các hàm sau:
a. Thêm 1 phần tử x vào mảng tại vị trí k
b. Viết hàm nhập mảng sao cho khi nhập xong thì giá trị trong mảng sắp xếp giảm dần
c. Thêm x vào trong mảng tăng nhưng vẫn giữ nguyên tính tăng của mảng. 
Câu 2:
Viết các hàm sau:
a. Đảo ngược mảng ban đầu
b. Đảo ngược thứ tự các số chẵn trong mảng
c. Cho biết mảng a có phải là mảng con của mảng b không.
d. Tìm mảng con có tổng lớn nhất (với mảng có số dương và âm).
Câu 3:
Viết các hàm sau:
a. Tính tổng các giá trị nằm trên biên của ma trận
b. Đếm các phần tử cực trị trong ma trận các số thực. Một phần tử cực trị khi nó lớn hơn các
phần tử xung quanh hoặc nhỏ hơn các phần tử xung quanh.
c. Kiểm tra các giá trị trong ma trận có giảm dần theo dòng và cột hay không.
d. Tìm giá trị lớn nhất của ma trận
e. Tìm giá trị lớn thứ 2 của ma trận. 
Câu 4:
Viết các hàm sau
a. Đổi tất cả các ký tự trong chuỗi thành chữ thường (không dùng hàm thư viện)
b. Chuẩn hoá một chuỗi nhập từ bàn phím. Tức loại bỏ hết khoảng trắng thừa ở đầu, cuối và
giữa. ví dụ nhập chuỗi:
“ Nguyễn Mậu Tùng” : Chuẩn hoá thành “Nguyễn Mậu Tùng”
c. Nhập xâu ký tự từ bàn phím, in ra từ dài nhất trong xâu (từ là dãy ký tự không chứa
khoảng trắng).
d. Viết hàm kiểm tra xem trong chuỗi có ký tự số hay không nếu có tách ra thành mảng số
riêng.
Câu 5:
Hay
Bài làm:
Câu 1:
a)
#include<stdio.h>
void nhapmang(int mang[], int N);
void xuatmang(int mang[], int N);
void chen_x(int mang[], int& N, int x, int k);
void main()
{
	int N, x,k;
	int mang[1000];
	printf("a)\nmoi nhap vao so nguyen duong N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N ban vua nhap khong dung (0 < N) moi nhap lai N: ");
		else
			break;
	} while (1);
	printf("moi nhap %d phan tu mang\n", N);
	nhapmang(mang, N);
	printf("mang vua nhap la: ");
	xuatmang(mang, N);
	printf("\na) moi nhap gia tri x can chen: ");
	scanf_s("%d", &x);
	printf("moi nhap vi tri k can chen: ");
	do
	{
		scanf_s("%d", &k);
		if (k < 0 || k >= N)
			printf("k ban vua nhap khong dung (0 <= k < N) moi nhap lai k: ");
		else
			break;
	} while (1);
	chen_x(mang, N, x, k);
	printf("\nmang sau khi chen x vao vi tri k:\n");
	xuatmang(mang, N);
	printf("\n");
}
void nhapmang(int mang[], int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &mang[i]);
	}
}
void xuatmang(int mang[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", mang[i]);
	}
}
void chen_x(int mang[], int& N, int x, int k)
{
	for (int i = N; i >= k + 1; i--)
	{
		mang[i] = mang[i - 1];
	}
	mang[k] = x;
	N++;
}
b)
#include<stdio.h>
void nhapmang(int mang[], int N);
void xuatmang_giamdan(int mang[], int N);
void main()
{
	int N;
	int mang[1000];
	printf("a)\nmoi nhap vao so nguyen duong N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N ban vua nhap khong dung (0 < N) moi nhap lai N: ");
		else
			break;
	} while (1);
	printf("moi nhap %d phan tu mang\n", N);
	nhapmang(mang, N);
	printf("mang vua nhap sau khi sap xep giam dan la:\n");
	xuatmang_giamdan(mang, N);
	printf("\n");
}
void nhapmang(int mang[], int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &mang[i]);
	}
}
void xuatmang_giamdan(int mang[], int N)
{
	int temp;
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (mang[j] < mang[j + 1])
			{
				temp = mang[j];
				mang[j] = mang[j + 1];
				mang[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", mang[i]);
	}
}
c) 
#include<stdio.h>
void nhapmang(int mang[], int N);
void xuatmang_tangdan(int mang[], int N);
void chenx(int mang[], int& N, int x);
void main()
{
	int N, copyN, x;
	int mang[1000];
	printf("a)\nmoi nhap vao so nguyen duong N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N ban vua nhap khong dung (0 < N) moi nhap lai N: ");
		else
			break;
	} while (1);
	printf("moi nhap %d phan tu mang\n", N);
	nhapmang(mang, N);
	printf("mang vua nhap sau khi sap xep giam dan la:\n");
	xuatmang_tangdan(mang, N);
	printf("\n");
	printf("moi nhap x: ");
	scanf_s("%d", &x);
	chenx(mang, N, x);
}
void nhapmang(int mang[],int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &mang[i]);
	}
}
void xuatmang_tangdan(int mang[], int N)
{
	int temp;
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (mang[j] > mang[j + 1])
			{
				temp = mang[j];
				mang[j] = mang[j + 1];
				mang[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", mang[i]);
	}
}
void chenx(int mang[], int& N, int x)
{
	N++;
	mang[N - 1] = x;
	xuatmang_tangdan(mang, N);
}

Câu 2:
ab) 
#include<stdio.h>
void nhapmang(int mang[], int copymang[], int N);
void xuatmang(int mang[], int N);
void daonguoc(int mang[], int N);
void daonguoc_chan(int mang[], int N);
void main()
{
	int N;
	int mang[1000], copymang[1000];
	printf("a)\nmoi nhap vao so nguyen duong N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0)
			printf("N ban vua nhap khong dung (0 < N) moi nhap lai N: ");
		else
			break;
	} while (1);
	printf("moi nhap %d phan tu mang\n", N);
	nhapmang(mang, copymang,N);
	printf("mang vua nhap la:\n");
	xuatmang(mang, N);
	printf("\nmang ban dau sau khi dao nguoc:\n");
	daonguoc(mang, N);
	xuatmang(mang, N);
	printf("\nmang ban dau sau khi dao nguoc thu tu cac so chan:\n");
	daonguoc_chan(copymang, N);
	xuatmang(copymang, N);
	printf("\n");
}
void nhapmang(int mang[], int copymang[], int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &mang[i]);
		copymang[i] = mang[i];
	}
}
void xuatmang(int mang[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", mang[i]);
	}
}
void daonguoc(int mang[], int N)
{
	int temp;
	for (int i = 0; i < N - 1 - i; i++)
	{
		temp = mang[i];
		mang[i] = mang[N - 1 - i];
		mang[N - 1 - i] = temp;
	}
}
void daonguoc_chan(int mang[], int N)
{
	int i, j, temp;
	for (i = 0, j = 0; i < N - 1 - j;)
	{
		if (mang[i] % 2 == 0)
		{
			if (mang[N - 1 - j] % 2 == 0)
			{
				temp = mang[i];
				mang[i] = mang[N - 1 - j];
				mang[N - 1 - j] = temp;
				i++;
				j++;
			}
			else
				j++;
		}
		else
		{
			if (mang[N - 1 - j] % 2 == 0)
				i++;
			else
			{
				i++;
				j++;
			}
		}
	}
}
Câu 3:

Câu 4:
a) 
#include<stdio.h>
#include<string.h>
void change(char S[]);
void main()
{
	char S[1000];
	printf("a) chuong trinh doi tat ca cac kt ty thanh chu thuong, moi nhap chuoi S:\n");
	gets_s(S);
	change(S);
	puts(S);
}
void change(char S[])
{
	for (int i = 0; S[i] != 0; i++)
	{
		if (S[i] >= 'A' && S[i] <= 'Z')
		{
			S[i] = S[i] + 'a' - 'A';
		}

	}
}
b) 
#include<stdio.h>
#include<string.h>
void chuanhoa(char S[]);
void main()
{
	char S[1000];
	printf("b) chuong trinh chuan hoa chuoi ky tu, moi nhap chuoi S:\n");
	gets_s(S);
	chuanhoa(S);
	printf("chuoi sau khi chuan hoa: \n");
	puts(S);
}
void chuanhoa(char S[])
{
	bool flag = true;
	for (int i = 0; S[i] != 0; i++)
	{
		if (flag)
		{
			if (S[i] == ' ')
			{
				for (int j = i; S[j] != 0; j++)
				{
					S[j] = S[j + 1];
				}
				i--;
			}
			else
				flag = false;
		}
		else
		{
			if (S[i] == ' ')
				flag = true;
		}
	}
}
c) 

Câu 5:
#include<stdio.h>
struct NGAY {
	int ngay;
	int thang;
	int nam;
};
struct SOTIETKIEM {
	char MaSo[6];
	char LoaiTietKiem[11];
	char HoTenKhachHang[31];
	int CMND;
	struct NGAY ngay;
	float SoTienGui;
}; 
void Nhap(char& S);
void Nhap(char S[], int So_Ky_Tu);
void Nhap(int& S);
void Nhap(float& S);
void nhap(char MaSo[], char LoaiTietKiem[], char HoTenKhachHang[], int& CMND, int& ngay, int& thang, int& nam, float& SoTienGui);
void xuat(char MaSo[], char LoaiTietKiem[], char HoTenKhachHang[], int CMND, int ngay, int thang, int nam, float SoTienGui);
void main()
{
	struct SOTIETKIEM duc;
	nhap(duc.MaSo, duc.LoaiTietKiem, duc.HoTenKhachHang, duc.CMND, duc.ngay.ngay, duc.ngay.thang, duc.ngay.nam, duc.SoTienGui);
	xuat(duc.MaSo, duc.LoaiTietKiem, duc.HoTenKhachHang, duc.CMND, duc.ngay.ngay, duc.ngay.thang, duc.ngay.nam, duc.SoTienGui);

}
void nhap(char MaSo[], char LoaiTietKiem[], char HoTenKhachHang[], int& CMND, int& ngay, int& thang, int& nam, float& SoTienGui)
{
	printf("moi nhap cac thong tin sau:\n");
	printf("MaSo: ");
	Nhap(MaSo, 6);
	printf("Loai tiet kiem: ");
	Nhap(LoaiTietKiem, 11);
	printf("Ho va ten khach hang: ");
	Nhap(HoTenKhachHang, 31);
	printf("So CMND: ");
	Nhap(CMND);
	printf("Ngay mo so: (nhap lien tuc ngay thang nam, Enter sau moi lan nhap) ");
	Nhap(ngay);
	Nhap(thang);
	Nhap(nam);
	printf("So tien gui (Nghin dong): ");
	Nhap(SoTienGui);
}
void xuat(char MaSo[], char LoaiTietKiem[], char HoTenKhachHang[], int CMND, int ngay, int thang, int nam, float SoTienGui)
{
	printf("\nThong tin so tiet kiem\n");
	printf("Ma so: %s\n", MaSo);
	printf("Loai tiet kiem: %s\n", LoaiTietKiem);
	printf("Ho va ten khach hang: %s\n", HoTenKhachHang);
	printf("So CMND: %d\n", CMND);
	printf("Ngay mo so: %d/%d/%d\n", ngay, thang, nam);
	printf("So tien gui: %.3f nghin dong\n", SoTienGui);
}
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
void Nhap(float& S)
{
	do
	{
		scanf_s("%f", &S);
	} while (S == '\n');
}
