					Bài tập thực hành tuần 08 
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
 Viết chương trình nhập số nguyên dương N (N <= 100) thực hiện:
a. Nhâp̣ N số nguyên vào dãy a0, a1, a2, ..
b. Xuất dãy vừa nhâp̣ ra màn hình.
c. Tìm tất cả các vi ̣trí của dãy màsố taị đó bé hơn 2 số kề bên. Các số ở biên chỉ cần xét với 1 số kề bên.
d. Tìm tất cả bộ ba số i, j, k thỏa ai, aj, ak là bô 3 số pitago.
Câu 2:
 Viết chương trình nhập chuỗi ký tự S
a. Đếm và cho biết số lươṇg khoảng trắng, số lươṇg ký số, số lươṇg chữ cái latin, số lươṇg các ký tự khác.
b. Đếm và cho biết số lươṇg từ của chuỗi – các từ cách nhau bởi khoảng trắng.
c. Biến đổi chuỗi sao cho các ký tự đầu mỗi từ là ký tự in hoa, các ký tự khác in thường.
Câu 3:
 Viết chương trình nhập chuỗi ký tự S, tạo chuỗi S1 với các từ của chuỗi S theo trình tự đảo
ngược (Ví dụ: Chuỗi S là “CA AN KIEN”, chuỗi S1 sẽ là “KIEN AN CA”)
Câu 4*:
Viết chương trình nhập chuỗi ký tự S, S1, S2. Hãy tìm trên chuỗi S tất cả những
làn xuất hiện của S1 và thay bằng S2.
Câu 5:
Mảng 2 chiều
a. Viết hàm nhập mảng 2 chiều (Ma trận)
b. Viết hàm xuất Ma trận
c. Tìm vị trí một phần tử có giá trị x
d. Viết hàm tính tổng các dòng của ma trận
e. Viết hàm tính tổng dòng có giá trị lớn nhất.
f. Tìm giá trị nhỏ nhất của ma trận

Bài làm:
Câu 1:
#include<stdio.h>
void nhapmang(int *mang, int *copymang, int N);
void xuatmang(int *mang, int N);
void timvitri(int *mang, int N);
void pytago(int *mang, int N);
bool testpytago(int i, int j, int k);
void main()
{
	int N, copyN;
	bool test = true;
	int mang[100];
	int copymang[100];
	printf("a)\nmoi nhap vao so nguyen duong N<100 N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0 || N > 100)
			printf("N ban vua nhap khong dung (0 < N <= 100\nmoi nhap lai N: ");
		else
			break;
	} while (1);
	copyN = N;
	printf("moi nhap %d phan tu mang\n", N);
	nhapmang(mang, copymang, N);
	printf("b) mang vua nhap la: ");
	xuatmang(mang, N);
	timvitri(mang, N);
	pytago(mang, N);
}
void nhapmang(int *mang, int *copymang, int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &mang[i]);
		copymang[i] = mang[i];
	}
}
void xuatmang(int *mang, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", mang[i]);
	}
}
void timvitri(int *mang, int N)
{
	int i = 0;
	bool truoc, sau, flag=false;
	truoc = false;
	printf("\nc) cac vi tri thoa dieu kien de bai:");
	for (i; i < N - 1; i++)
	{
		sau = mang[i] < mang[i + 1] ? true : false;
		if (!truoc && sau)
		{
			flag = true;
			printf(" thu %d", i + 1);
		}
		truoc = sau;
	}
	if (!truoc)
	{
		flag = true;
		printf(" thu %d", N);
	}
	if (!flag)
		printf(" mang khong co phan tu nao thoa dieu kien de bai");
}
void pytago(int *mang, int N)
{
	bool flag = false;
	printf("\nd) cac bo 3 vi tri ma gia tri trong mang tai do la bo 3 so pytago: ");
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (testpytago(mang[i], mang[j], mang[k]))
				{
					flag = true;
					printf("(%d,%d,%d) ", i, j, k);
				}
			}
		}
	}
	if (!flag)
		printf("trong mang khong co bo 3 nao tao thanh 3 so pytago\n");
	printf("\n");
}
bool testpytago(int i, int j, int k)
{
	if (i <= 0 || j <= 0 || k <= 0)
		return false;
	int i2 = i*i, j2 = j*j, k2 = k*k;
	if (i2 == j2 + k2 || j2 == i2 + k2 || k2 == i2 + j2)
		return true;
	else
		return false;
}

Câu 2:
#include<stdio.h>
#include<string.h>
void cau_a(char *S);
void cau_b(char *S);
void cau_c(char *S);
void main()
{
	int N;
	char S[1001];
	printf("moi nhap vao chuoi ky tu S: ");
	gets_s(S);
	cau_a(S);
	cau_b(S);
	cau_c(S);
}
void cau_a(char *S)
{
	int khoang_trang = 0, kyso = 0, latin = 0, khac = 0;
	int i = 0;
	do
	{
		if (S[i] == ' ')
			khoang_trang++;
		else if (S[i] >= '0'&&S[i] <= '9')
			kyso++;
		else if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
			latin++;
		else
			khac++;
		i++;
	} while (S[i] != 0);
	printf("a) trong chuoi co %d ky tu khoang trang, %d ky so, %d chu cai latin, %d ky tu khac", khoang_trang, kyso, latin, khac);
}
void cau_b(char *S)
{
	int tu = 0, i = 0;
	while (S[i] != 0)
	{
		if (S[i] != ' ')
		{
			tu++;
			do
			{
				i++;
			} while (S[i] != ' ');
		}
		i++;
	}
	printf("\nb) so luong tu trong chuoi la: %d", tu);
}
void cau_c(char *S)
{
	int i = 0;
	int flag = 1;
	do
	{
			if (!flag)
			{
				if (S[i] >= 'A' && S[i] <= 'Z')
					S[i] += 'a' - 'A';
			}	
			else
			{
				if (S[i] >= 'a' && S[i] <= 'z')
				{
					S[i] -= 'a' - 'A';
				}
			}
			if (S[i] == ' ')
				flag = 1;
			else
				flag = 0;
			i++;
	} while (S[i] != 0);
	printf("\nc) ");
	puts(S);
	printf("\n");
}

Câu 3:
#include<stdio.h>
#include<string.h>

void main()
{
	int L, j = 0;
	char S[1001], S1[1001];
	printf("moi nhap vao chuoi S: ");
	gets_s(S);
	L=strlen(S);
	for (int i = L - 1; i >=0; i--)
	{
		if (S[i] == ' '|| i==0)
		{
			int i1 = i ? (i + 1) : 0;
			while (S[i1] != ' ' && S[i1] != 0)
			{
				S1[j] = S[i1];
				i1++;
				j++;
			}
			S1[j] = ' ';
			j++;
		}
	}
	j--;
	S1[j] = 0;
	puts(S1);
}

Câu 4:
#include<stdio.h>
#include<string.h>
bool find_and_replace(char *S, char *S1, char *S2, char *newS);
bool find(char *S, char *S1, int& vitriS, int L1);
void replace(char *newS, char *S2, int& vitr_newS, int L2);
void main()
{
	char S[901], S1[901], S2[901],newS[901];
	printf("moi nhap chuoi S: "); gets_s(S);
	printf("moi nhap chuoi S1: "); gets_s(S1);
	printf("moi nhap chuoi S2: "); gets_s(S2);
	if (find_and_replace(S, S1, S2, newS))
		printf("chuoi S sau khi thay the cac chuoi S1 thanh S2:\n%s\n", newS);
	else
		printf("trong chuoi S khong ton tai chuoi S1\n");
}
bool find_and_replace(char *S, char *S1, char *S2, char *newS)
{
	bool flag = false;
	int L = strlen(S), L1=strlen(S1), L2=strlen(S2);
	int vitriS=0, vitri_newS = 0;
	for (vitriS; vitriS < L; vitriS++)
	{
		if (find(S, S1, vitriS, L1))
		{
			flag = true;
			replace(newS, S2, vitri_newS, L2);
		}
		else
		{
			newS[vitri_newS] = S[vitriS];
			vitri_newS++;
		}
	}
	newS[vitri_newS] = 0;
	return flag;
}
bool find(char *S, char *S1, int& vitriS, int L1)
{
	int i=vitriS, j = 0;
	for (j; j < L1; j++)
	{
		if (S[i] != S1[j])
			return false;
		i++;
	}
	vitriS = i - 1;
	return true;
}
void replace(char *newS, char *S2, int& vitri_newS, int L2)
{
	int i = 0;
	for (i; i <L2; i++)
	{
		newS[vitri_newS] = S2[i];
		vitri_newS++;
	}
}

Câu 5:
#include<stdio.h>
void nhap_mang(int& m, int& n, int S[][100]);
void xuat_mang(int m, int n, int S[][100]);
bool find_x(int m, int n, int S[][100]);
void tong_dong(int m, int n, int S[][100], int tongdong[]);
void tong_dong_max(int m, int n, int S[][100], int tongdong[]);
void min_mang(int m, int n, int S[][100]);
void main()
{
	int m, n;
	int S[50][100];
	int tongdong[50];
	nhap_mang(m, n, S);
	xuat_mang(m, n, S);
	if (!(find_x(m, n, S)))
		printf("trong mang khong co gia tri nao bang x");
	tong_dong(m, n, S, tongdong);
	printf("\nd)\n");
	for (int i = 0; i < m; i++)
		printf("tong dong thu %d la: %d\n", i + 1,tongdong[i]);
	tong_dong_max(m, n, S, tongdong);
	min_mang(m, n, S);
}
void nhap_mang(int& m, int& n, int S[][100])
{
	printf("a) moi nhap lan luot so hang va so cot:\n");
	scanf_s("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("nhap S[%d][%d] ", i, j);
			scanf_s("%d", &S[i][j]);
		}
	}
}
void xuat_mang(int m, int n, int S[][100])
{
	printf("\nb)\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d ", S[i][j]);
		}
		printf("\n");
	}
}
bool find_x(int m, int n, int S[][100])
{
	int x;
	bool flag = false;
	printf("\nc) moi nhap x: ");
	scanf_s("%d", &x);
	printf("cac vi tri xuat hien cua x trong mang: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (S[i][j] == x)
			{
				flag = true;
				printf(" (hang %d cot %d)", i + 1, j + 1);
			}
		}
	}
	return flag;
}
void tong_dong(int m, int n, int S[][100], int tongdong[])
{
	for (int i = 0; i < m; i++)
	{
		tongdong[i] = 0;
		int max1;
		for (int j = 0; j < n; j++)
		{
			tongdong[i] += S[i][j];
		}
	}
}
void tong_dong_max(int m, int n, int S[][100], int tongdong[])
{
	tong_dong(m, n, S, tongdong);
	int max = tongdong[0];
	for (int i = 1; i < n; i++)
	{
		if (max < tongdong[i])
			max = tongdong[i];
	}
	printf("e) tong dong lon nhat la: %d",max);
}
void min_mang(int m, int n, int S[][100])
{
	int min = S[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (min > S[i][j])
				min = S[i][j];
		}
	}
	printf("\nf) gia tri nho nhat trong mang la: %d\n", min);
}