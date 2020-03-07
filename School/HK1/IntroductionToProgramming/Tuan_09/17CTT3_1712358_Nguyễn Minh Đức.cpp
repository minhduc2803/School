					Bài tập thực hành tuần 09
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
  Nhập chuỗi ký tự s
Ví dụ: Char s[100] = “Hello string in Programming c”
a. Đếm số lượng khoảng trắng của chuỗi s
b. In ra từ đầu tiên của chuỗi
Ví dụ:
Từ thứ nhất của chuỗi s là “Hello”, các từ cách nhau 1 khoảng trắng
c. In ra từ thứ i của chuỗi s
d. Viết hoa các ký tự đầu tiên của một từ nếu nó là chữ thường
Câu 2:
  Nhập ma trận kích thước m x n (m,n là nguyên dương), với m: kích thước dòng, n: kích thước
cột
Viết các hàm sau:
a. Hàm tính tổng dòng: int TongDong(int a[] [maxc], int m, int n, int d); d: dòng
b. Hàm tính tổng cột
c. Hàm tính tổng đường chéo chính: int TongDCChinh(int a[][maxc], int n)
d. Hàm tính tổng trên đường chéo chính
e. Hàm tính tổng dưới đường chéo chính
f. Hàm tính tổng trên đường chéo phụ
g. Tìm điểm yên ngựa trên ma trận
Với: điểm yên ngựa trên ma trận là điểm thoả: vừa nhỏ nhất trên hàng vừa lớn nhất trên cột
6 7 8
5 2 3
3 4 6
6 là yên ngựa
h. * Sắp xếp ma trận với các dòng tăng dần
i. * Sắp xếp ma trận với cột giảm dần
j. ** Sắp xếp ma trận theo thứ tự tăng dần
Câu 3:
 a. Khai báo kiểu dữ liệu phân số
b. Nhập/Xuất phân số
c. Tìm ước số chung lớn nhất hai số nguyên (tử số và mẫu số).
d. Rút gọn phân số
e. Kiểm tra phân số tối giản
f. Tính tổng, hiệu, tích thương hai phân số, kết quả trả về là phân số tối giản. 
Câu 4:
 Điểm trong mặt phẳng Oxy
a. Khai báo kiểu dữ liệu điểm (SDiem)
b. Nhập / Xuất toạ độ điểm
c. Tính khoảng cách giữa điểm
d. Tìm điểm đối xứng qua gốc toạ độ / trục Ox /Oy

Bài làm:
Câu 1:
#include<stdio.h>
#include<string.h>
void nhap_lai(char *S, int& L);
bool test_two_space(char *S, int L);
void count_space(char *S, int L);
void print_first_word(char *S);
void print_order_word(char *S, int L);
void capitalization(char *S, int L);
void main()
{
	char S[901];
	printf("Dau va cuoi chuoi khong the la dau cach,khong the co 2 dau cach lien tiep\nmoi nhap vao chuoi S: ");
	int L;
	nhap_lai(S, L);
	count_space(S, L);
	print_first_word(S);
	print_order_word(S, L);
	capitalization(S, L);
}
void nhap_lai(char *S, int& L)
{
	do
	{
		gets_s(S,900);
		L = strlen(S);
		if (S[0] == ' ' || S[L - 1] == ' ' || test_two_space(S, L))
			printf("dau va cuoi chuoi khong the la dau cach, khong the co 2 dau cach lien tiep\nmoi nhap lai chuoi: ");
		else
			break;
	} while (1);
}
bool test_two_space(char *S, int L)
{
	
	for (int i = 1; i <= L - 3; i++)
	{
		if (S[i] == ' '&& S[i + 1] == ' ')
			return true;
	}
	return false;
}
void count_space(char *S, int L)
{
	int space = 0;
	for (int i = 0; i < L; i++)
	{
		if (S[i] == ' ')
			space++;
	}
	printf("a) chuoi co %d khoang trang", space);
}
void print_first_word(char *S)
{
	printf("\nb) tu dau tien cua chuoi la: ");
	int i = 0;
	while (S[i] != ' '&& S[i] != 0)
	{
		printf("%c", S[i]);
		i++;
	}
}
void print_order_word(char *S, int L)
{
	bool flag = false;
	int i;
	int count_space = 0;
	int position;
	printf("\nc) nhap so nguyen duong i: ");
	do
	{
		scanf_s("%d", &i);
		if (i <= 0)
			printf("du lieu nhap khong hop le, i phai la so nguyen duong. moi nhap lai: ");
		else
			break;
	} while (1);
	for (position = 0; position < L; position++)
	{
		if (count_space == i - 1)
		{
			printf("tu thu %d la: ", i);
			flag = true;
			while (S[position] != ' '&& S[position] != 0)
			{
				printf("%c", S[position]);
				position++;
			}

			break;
		}
		if (S[position] == ' ')
			count_space++;
		
	}
	if (!flag)
	{
		printf("i ban vua nhap lon hon so tu trong chuoi, chuong trinh se duoc khoi dong lai");
		print_order_word(S, L);
	}
}
void capitalization(char *S, int L)
{
	bool flag = true;
	printf("\nd) ");
	for (int i = 0; i < L; i++)
	{
		if (flag)
		{
			if (S[i] >= 'a'&&S[i] <= 'z')
				printf("%c", S[i] - ('a' - 'A'));
			else
				printf("%c", S[i]);
		}
		else
			printf("%c", S[i]);
		if (S[i] == ' ')
			flag = true;
		else
			flag = false;
	}
	printf("\n");
}

Câu 2:
// do câu 2 này nhiều ý khác nhau nên em chia những ý liên quan chung code, tổng cộng có 3 source khác nhau nka thầy
a,b)
#include<stdio.h>
void type_array(int A[][50], int& row, int& column);
void print_array(int A[][50], int row, int column);
int TongDong(int A[][50], int m, int n, int d);
int TongCot(int A[][50], int m, int n, int d);
void main()
{
	int row, column, dong, cot;
	int A[50][50];
	type_array(A, row, column);
	print_array(A, row, column);
	//cau a)
	printf("a) moi nhap dong ma ban muon tinh tong: ");
	do
	{
		scanf_s("%d", &dong);
		if (dong <= 0 || dong > row)
			printf("du lieu nhap khong hop le, so dong phai lon hon 0 va nho hon hoac bang %d. moi nhap lai: ", row);
		else
			break;
	} while (1);
	printf("tong dong %d: %d\n", dong, TongDong(A, row, column, dong - 1));
	//cau b)
	printf("b) moi nhap dong ma ban muon tinh tong: ");
	do
	{
		scanf_s("%d", &cot);
		if (cot <= 0 || cot > column)
			printf("du lieu nhap khong hop le, so cot phai lon hon 0 va nho hon hoac bang %d. moi nhap lai: ", column);
		else
			break;
	} while (1);
	printf("tong cot %d: %d\n", cot, TongCot(A, row, column, cot-1));
}
void type_array(int A[][50], int& row, int& column)
{
	printf("moi nhap lan luot so dong, so cot:\n");
	do
	{
		scanf_s("%d%d", &row, &column);
		if (row <= 0 || column <= 0)
			printf("du lieu nhap khong hop le, so dong so cot phai lon hon 0. moi nhap lai:\n");
		else
			break;
	} while (1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("nhap A[%d][%d]: ",i,j);
			scanf_s("%d", &A[i][j]);
		}
	}
}
void print_array(int A[][50], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%5d ", A[i][j]);
		}
		printf("\n");
	}
}
int TongDong(int A[][50], int m, int n, int d)
{
	int tong = 0;
	for (int j = 0; j < n; j++)
	{
		tong += A[d][j];
	}
	return tong;
}
int TongCot(int A[][50], int m, int n, int d)
{
	int tong = 0;
	for (int i = 0; i < m; i++)
	{
		tong += A[i][d];
	}
	return tong;
}

c,d,e,f)
#include<stdio.h>
void type_array(int A[][50], int& n);
void print_array(int A[][50], int n);
int TongDCChinh(int A[][50], int n);
int TongTrenDCChinh(int A[][50], int n);
int TongDuoiDCChinh(int A[][50], int n);
int TongTrenDCPhu(int A[][50], int n);
void main()
{
	int n;
	int A[50][50];
	type_array(A, n);
	print_array(A, n);
	printf("\nc) tong duong cheo chinh la: %d", TongDCChinh(A, n));
	printf("\nd) tong tren duong cheo chinh la: %d", TongTrenDCChinh(A, n));
	printf("\ne) tong duoi duong cheo chinh la: %d", TongDuoiDCChinh(A, n));
	printf("\nf) tong tren duong cheo phu la: %d\n", TongTrenDCPhu(A, n));
}
void type_array(int A[][50], int& n)
{
	printf("o bai nay so hang phai bang so cot thi moi ton tai duong cheo chinh va duong cheo phu\nmoi nhap so nguyen duong N vua la so hang vua la so cot cua mang: ");
	do
	{
		scanf_s("%d", &n);
		if (n<= 0)
			printf("du lieu nhap khong hop le, so dong so cot phai lon hon 0. moi nhap lai:\n");
		else
			break;
	} while (1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("nhap A[%d][%d]: ", i, j);
			scanf_s("%d", &A[i][j]);
		}
	}
}
void print_array(int A[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d ", A[i][j]);
		}
		printf("\n");
	}
}


int TongDCChinh(int A[][50], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		tong += A[i][i];
	return tong;

}
int TongTrenDCChinh(int A[][50], int n)
{
	int tong = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
			tong += A[i][j];
	}
	return tong;
}
int TongDuoiDCChinh(int A[][50], int n)
{
	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			tong += A[i][j];
	}
	return tong;
}
int TongTrenDCPhu(int A[][50], int n)
{
	int tong = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
			tong += A[i][j];
	}
	return tong;
}

g,h,i,j)
#include<stdio.h>
void type_array(int A[][50], int avatarAh[][50], int avatarAi[][50], int& row, int& column);
void print_array(int A[][50], int row, int column);
bool Diem_Yen_Ngua(int A[][50], int row, int column);
int min_of_row(int A[][50], int current_row, int column);
bool test_max_column(int A[][50], int a, int row, int current_column);
void rise_row(int A[][50], int row, int column);
void rise_row_i(int A[][50], int current_row, int column);
void fall_column(int A[][50], int row, int column);
void fall_column_i(int A[][50], int row, int current_column);
void sort_array(int A[][50], int row, int column);
void sort_i(int giatri, int B[][50], int row, int column, int i, int j);
void main()
{
	int row, column, dong, cot;
	int A[50][50], avatarAh[50][50], avatarAi[50][50];
	type_array(A, avatarAh, avatarAi, row, column);
	print_array(A, row, column);
	if (!Diem_Yen_Ngua(A, row, column))
		printf("trong mang khong ton tai diem yen ngua nao");
	//cau h)
	rise_row(avatarAh, row, column);
	printf("\nh) mang ban dau sau khi sap xep theo hang tang dan la:\n");
	print_array(avatarAh, row, column);
	//cau i)
	fall_column(avatarAi, row, column);
	printf("\ni) mang ban dau sau khi sap xep theo cot giam dan la:\n");
	print_array(avatarAi, row, column);
	//cau j)
	sort_array(A, row, column);
}
void type_array(int A[][50], int avatarAh[][50], int avatarAi[][50], int& row, int& column)
{
	printf("moi nhap lan luot so dong, so cot:\n");
	do
	{
		scanf_s("%d%d", &row, &column);
		if (row <= 0 || column <= 0)
			printf("du lieu nhap khong hop le, so dong so cot phai lon hon 0. moi nhap lai:\n");
		else
			break;
	} while (1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("nhap A[%d][%d]: ", i, j);
			scanf_s("%d", &A[i][j]);
			avatarAh[i][j] = A[i][j];
			avatarAi[i][j] = A[i][j];
		}
	}
}
void print_array(int A[][50], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%5d ", A[i][j]);
		}
		printf("\n");
	}
}
bool Diem_Yen_Ngua(int A[][50], int row, int column)
{
	printf("g) cac diem yen ngua trong mang la: ");
	bool flag = false;
	for (int i = 0; i < row; i++)
	{
		int min_row = min_of_row(A, i, column);
		for (int j = 0; j < column; j++)
		{
			if (A[i][j] == min_row)
			{
				if (test_max_column(A, A[i][j], row, j))
				{
					printf("%d  ", A[i][j]);
					flag = true;
				}
			}
		}
	}
	return flag;
}
int min_of_row(int A[][50], int current_row, int column)
{
	int min = A[current_row][0];
	for (int i = 1; i < column; i++)
	{
		if (min > A[current_row][i])
		{
			min = A[current_row][i];
		}
	}
	return min;
}
bool test_max_column(int A[][50], int a, int row, int current_column)
{
	for (int i = 0; i < row; i++)
	{
		if (a < A[i][current_column])
			return false;
	}
	return true;
}
void rise_row(int A[][50], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		rise_row_i(A, i, column);
	}
}
void rise_row_i(int A[][50], int current_row, int column)
{
	int temp;
	for (int j = column-2; j >= 0; j--)
	{
		for (int k = 0; k <= j; k++)
		{
			if (A[current_row][k] > A[current_row][k + 1])
			{
				temp = A[current_row][k];
				A[current_row][k] = A[current_row][k + 1];
				A[current_row][k + 1] = temp;
			}
		}

	}
}
void fall_column(int A[][50], int row, int column)
{
	for (int j = 0; j < column; j++)
	{
		fall_column_i(A, row, j);
	}
}
void fall_column_i(int A[][50], int row, int current_column)
{
	int temp;
	for (int i = row-2; i >= 0; i--)
	{
		for (int k = 0; k <= i; k++)
		{
			if (A[k][current_column] < A[k+1][current_column])
			{
				temp = A[k][current_column];
				A[k][current_column] = A[k+1][current_column];
				A[k+1][current_column] = temp;
			}
		}

	}
}
void sort_array(int A[][50], int row, int column)
{
	int B[50][50];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			sort_i(A[i][j], B, row, column, i, j);
		}
	}
	printf("\nj) mang ban dau sau khi sap xep tang dan la:\n");
	print_array(B, row, column);
}
void sort_i(int giatri, int B[][50], int row, int column, int i, int j)
{
	int flag = 1;
	int temp;
	for (int i1 = 0; i1 <= i; i1++)
	{
		for (int j1 = 0; j1 <= ((i1==i)?j:(column-1)); j1++)
		{
			if (flag == 1)
			{
				if (B[i1][j1] >= giatri)
				{
					temp = B[i1][j1];
					B[i1][j1] = giatri;
					flag = 2;
					if (i1 == i&&j1 == j)
						flag = 1;
				}
			}
			else
			{
				int temp1 = B[i1][j1];
				B[i1][j1] = temp;
				temp = temp1;
			}
		}
	}
	if (flag == 1)
		B[i][j] = giatri;
}

Câu 3:
#include<stdio.h>
struct phanso {
	int tuso=1;
	int mauso=1;
};
int UCLN(int tuso, int mauso);
bool test_toi_gian(int tuso, int mauso);
void tong(int tu1, int mau1, int tu2, int mau2, struct phanso _tong);
void hieu(int tu1, int mau1, int tu2, int mau2, struct phanso _hieu);
void tich(int tu1, int mau1, int tu2, int mau2, struct phanso _tich);
void thuong(int tu1, int mau1, int tu2, int mau2, struct phanso _thuong);

void main()
{
	struct phanso phanso1, phanso2, _tong, _hieu, _tich, _thuong;
	int uc1;
	printf("b) moi nhap lan luot tu so va mau so cua phan so thu nhat: ");
	do
	{
		scanf_s("%d %d", &phanso1.tuso, &phanso1.mauso);
		if (phanso1.mauso == 0)
			printf("du lieu nhap sai, mau so phai khac khong. moi nhap lai phan so 1: ");
		else
			break;
	} while (1);
	printf("moi nhap lan luot tu so va mau so cua phan so thu hai: ");
	do
	{
		scanf_s("%d %d", &phanso2.tuso, &phanso2.mauso);
		if (phanso2.mauso == 0)
			printf("du lieu nhap sai, mau so phai khac khong. moi nhap lai phan so 2: ");
		else
			break;
	} while (1);
	printf("phan so 1: %d/%d\n", phanso1.tuso, phanso1.mauso);
	printf("phan so 1: %d/%d\n", phanso2.tuso, phanso2.mauso);
	uc1 = UCLN(phanso1.tuso, phanso1.mauso);
	printf("c) uoc chung lon nhat cua tu so va mau so phan so 1: %d\n", uc1);
	if (phanso1.tuso%phanso1.mauso == 0)
		printf("d) phan so 1 sau khi rut gon: %d\n", phanso1.tuso / phanso1.mauso);
	else
		printf("d) phan so 1 sau khi rut gon: %d/%d\n", phanso1.tuso / uc1, phanso1.mauso / uc1);
	if (test_toi_gian(phanso1.tuso, phanso1.mauso))
		printf("e) phan so thu nhat %d/%d la phan so toi gian\n",phanso1.tuso,phanso1.mauso);
	else
		printf("e) phan so thu nhat %d/%d khong phai la phan so toi gian\n",phanso1.tuso, phanso1.mauso);
	printf("f)\n");
	tong(phanso1.tuso, phanso1.mauso, phanso2.tuso, phanso2.mauso,_tong);
	hieu(phanso1.tuso, phanso1.mauso, phanso2.tuso, phanso2.mauso,_hieu);
	tich(phanso1.tuso, phanso1.mauso, phanso2.tuso, phanso2.mauso,_tich);
	thuong(phanso1.tuso, phanso1.mauso, phanso2.tuso, phanso2.mauso,_thuong);
}
int UCLN(int tuso, int mauso)
{
	int uc = 1;
	int dau;
	if (tuso*mauso<0)
		dau = -1;
	if (tuso<0)
		tuso = -tuso;
	if (mauso<0)
		mauso = -mauso;
	if (tuso % mauso == 0)
		return tuso;
	else if (mauso%tuso == 0)
		return tuso;
	else if (tuso > mauso)
	{

		int mauso2 = mauso / 2;
		for (int i = 1; i <= mauso2; i++)
		{
			if (tuso%i == 0 && mauso%i == 0)
				uc = i;
		}
	}
	return uc;
}
bool test_toi_gian(int tuso, int mauso)
{
	if (UCLN(tuso, mauso) == 1)
		return true;
	else
		return false;
}
void tong(int tu1, int mau1, int tu2, int mau2, struct phanso _tong)
{
	
	_tong.tuso = tu1*mau2 + tu2*mau1;
	_tong.mauso = mau1*mau2;
	int uc = UCLN(_tong.tuso, _tong.mauso);
	if (_tong.tuso%_tong.mauso == 0)
		printf("tong %d/%d + %d/%d=%d\n", tu1,mau1,tu2,mau2,_tong.tuso/_tong.mauso);
	else
		printf("tong %d/%d + %d/%d=%d/%d\n", tu1,mau1,tu2,mau2,_tong.tuso/uc,_tong.mauso/uc);
}
void hieu(int tu1, int mau1, int tu2, int mau2, struct phanso _hieu)
{
	
	_hieu.tuso = tu1*mau2 - tu2*mau1;
	_hieu.mauso = mau1*mau2;
	int uc = UCLN(_hieu.tuso, _hieu.mauso);
	if (_hieu.tuso%_hieu.mauso == 0)
		printf("hieu %d/%d - %d/%d=%d\n", tu1, mau1, tu2, mau2, _hieu.tuso / _hieu.mauso);
	else
		printf("hieu %d/%d - %d/%d=%d/%d\n", tu1, mau1, tu2, mau2, _hieu.tuso / uc, _hieu.mauso / uc);
}
void tich(int tu1, int mau1, int tu2, int mau2, struct phanso _tich)
{
	_tich.tuso = tu1*tu2;
	_tich.mauso = mau1*mau2;
	int uc = UCLN(_tich.tuso, _tich.mauso);
	if (_tich.tuso%_tich.mauso == 0)
		printf("tich %d/%d x %d/%d=%d\n", tu1, mau1, tu2, mau2, _tich.tuso / _tich.mauso);
	else
		printf("tich %d/%d x %d/%d=%d/%d\n", tu1, mau1, tu2, mau2, _tich.tuso / uc, _tich.mauso / uc);
}
void thuong(int tu1, int mau1, int tu2, int mau2, struct phanso _thuong)
{

	_thuong.tuso = tu1*mau2;
	_thuong.mauso = mau1*tu2;
	if (_thuong.mauso == 0)
		printf("thuong %d/%d : %d/%d khong ton tai vi phan so thu 2 bang 0\n", tu1, mau1, tu2, mau2);
	else
	{

		int uc = UCLN(_thuong.tuso, _thuong.mauso);
		if (_thuong.tuso%_thuong.mauso == 0)
			printf("thuong %d/%d : %d/%d=%d\n", tu1, mau1, tu2, mau2, _thuong.tuso / _thuong.mauso);
		else
			printf("thuong %d/%d : %d/%d=%d/%d\n", tu1, mau1, tu2, mau2, _thuong.tuso / uc, _thuong.mauso / uc);
	}
}

Câu 4:
#include<stdio.h>
#include<math.h>
float KhoangCach(float x1, float y1, float x2, float y2);
void DoiXungGocToaDo(float x, float y, float& x1, float& y1);
void DoiXungTrucOx(float x, float y, float& x1, float& y1);
void DoiXungTrucOy(float x, float y, float& x1, float& y1);
struct SDiem {
	float x;
	float y;
}A,B, DoiGocToaDo,DoiTrucOx,DoiTrucOy;
void main()
{
	printf("b) moi nhap lan luot hoanh do va tung do diem A: ");
	scanf_s("%f %f", &A.x, &A.y);
	printf("b) moi nhap lan luot hoanh do va tung do diem B ");
	scanf_s("%f %f", &B.x, &B.y);
	printf("toa do A(%.3f;%.3f)\ntoa do B(%.3f;%.3f)\n", A.x, A.y, B.x, B.y);
	printf("khoang cach giua 2 diem A,B la: %f\n", KhoangCach(A.x, A.y, B.x, B.y));
	DoiXungGocToaDo(A.x,A.y,DoiGocToaDo.x,DoiGocToaDo.y);
	DoiXungTrucOx(A.x, A.y, DoiTrucOx.x,DoiTrucOx.y);
	DoiXungTrucOy(A.x, A.y, DoiTrucOy.x, DoiTrucOy.y);
	printf("Diem doi xung cua A qua goc toa do la (%.3f;%.3f)\n", DoiGocToaDo.x, DoiGocToaDo.y);
	printf("Diem doi xung cua A qua truc Ox la (%.3f;%.3f)\n", DoiTrucOx.x, DoiTrucOx.y);
	printf("Diem doi xung cua A qua truc Oy la (%.3f;%.3f)\n", DoiTrucOy.x, DoiTrucOy.y);
}
float KhoangCach(float x1, float y1, float x2, float y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	
}
void DoiXungGocToaDo(float x, float y, float& x1, float& y1)
{
	x1 = -x;
	y1 = -y;
}
void DoiXungTrucOx(float x, float y, float& x1, float& y1)
{
	x1 = x;
	y1 = -y;
}
void DoiXungTrucOy(float x, float y, float& x1, float& y1)
{
	x1 = -x;
	y1 = y;
}
