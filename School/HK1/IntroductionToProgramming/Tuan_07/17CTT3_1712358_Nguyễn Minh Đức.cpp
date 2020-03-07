					Bài tập thực hành tuần 07 
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
Viết chương trình nhập số nguyên dương N (N <= 100) thực hiện:
a. Nhập N số nguyên vào dãy a0, a1,a2,..
b. Xuất dãy vừa nhập ra màn hình.
c. Đếm xem dãy vừa nhập có bao nhiêu số nguyên, in các số nguyên tố đó ra màn hình.
d. Nhập số nguyên X, tìm vị trí xuất hiện của X trên dãy vừa nhập.
e. Nhập số nguyên Y, xóa một số có giá trị Y ra khỏi dãy vừa nhập.
f. Nhập số nguyên Z, tìm vị trí xuất hiện của số trên dãy có giá trị gần với Z nhất.
Câu 2:
Viết chương trình nhập số nguyên dương N (N ≤ 100) thưc̣ hiêṇ :
a. Nhập N số nguyên vào dãy a0, a1, a2, ..
b. Xuất dãy vừa nhập ra màn hình.
c. Kiểm tra xem dãy vừa nhập có phải là dãy tăng dần hay không.
d. Nếu dãy không tăng dần, hãy sắp xếp lại, xuất dãy ra màn hình.
e. Nhập số nguyên X, chèn X vào dãy đang có sao cho dãy vẫn đươc̣ sắp xếp tăng
dần, xuất dãy kết quả ra màn hình.

Bài làm:
Câu 1:
#include<stdio.h>
void nhapmang(int *mang, int *copymang, int N);
void xuatmang(int *mang, int N);
void nguyento(int *mang, int N);
bool xetnguyento(int so);
void timx(int *mang, int N);
int deletey(int *mang, int& N);
void timZgannhat(int *mang, int N);
void main()
{
	int N, copyN;
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
	nguyento(mang, N);
	timx(mang, N);
	switch (deletey(mang, N))
	{
	case -1: printf("sau khi xoa Y, mang khong con phan tu nao"); break;
	case 0: printf("mang khong co phan tu nao bang Y"); break;
	default: printf("mang sau khi xoa phan Y dau tien tim duoc tu trai qua phai la:\n");
		xuatmang(mang, N);
	}
	timZgannhat(copymang, copyN);
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
void nguyento(int *mang, int N)
{
	int mangnguyento[100];
	int i,j=-1;
	for (i = 0; i < N; i++)
	{
		if (xetnguyento(mang[i]))
		{
			j++;
			mangnguyento[j] = mang[i];
		}
	}
	if (j == -1)
		printf("\nc) mang khong co so nguyen to nao");
	else
	{
		printf("\nc) mang co %d so nguyen to: ", (j + 1));
		for (int i = 0; i <= j; i++)
		{
			printf("%d ", mangnguyento[i]);
		}
	}
}
bool xetnguyento(int so)
{
	int so2 = so / 2;
	if (so <= 1)
		return false;
	else if (so <= 3)
		return true;
	else
	{
		for (int i = 2;; i++)
		{
			if (so%i == 0)
				return false;
			else if (i > so2)
				return true;
		}
	}
}
void timx(int *mang, int N)
{
	int x;
	printf("\nd) moi nhap vao so nguyen X: ");
	scanf_s("%d", &x);
	int i;
	for (i = 0; i < N; i++)
	{
		if (mang[i] == x)
		{
			printf("X xuat hien o vi tri thu %d", i + 1);
			i++;
			break;
		}
		else if (i == (N - 1))
			printf("mang ban nhap ko co gia tri nao bang X");
	}
	for (i; i < N; i++)
	{
		if (mang[i] == x)
			printf(", thu %d ", i + 1);
	}
}
int deletey(int *mang, int& N)
{
	int y, flag=0;
	printf("\ne) moi nhap vao so nguyen Y: ");
	scanf_s("%d", &y);
	int i,j;
	for (i = 0; i < N; i++)
	{
		if (mang[i] == y)
		{
			flag++;
			for (j = i; j < N - 1; j++)
			{
				mang[j] = mang[j + 1];
			}
			N--;
			i--;
		}
	}
	if (N == 0)
		flag = -1;
	return flag;
}
void timZgannhat(int *mang, int N)
{
	int saiso, hieu, i, giatrigannhat1, giatrigannhat2;
	int z;
	printf("\nf) moi nhap vao so nguyen Z: ");
	scanf_s("%d", &z);
	giatrigannhat1 = mang[0];
	giatrigannhat2 = mang[0];
	hieu = mang[0] - z;
	if (hieu < 0)
		hieu = -hieu;
	saiso = hieu;
	for (i = 1; i < N; i++)
	{
		hieu = mang[i] - z;
		if (hieu < 0)
			hieu = -hieu;
		if (hieu < saiso)
		{
			giatrigannhat1 = mang[i];
			giatrigannhat2 = mang[i];
			saiso = hieu;
		}
		else if (hieu == saiso && giatrigannhat1 != mang[i])
			giatrigannhat2 = mang[i];

	}
	if (giatrigannhat1 == giatrigannhat2)
	{
		printf("gia tri gan nhat voi Z trong mang la %d\nxuat hien o vi tri ", giatrigannhat1);
		for (i = 0; i < N; i++)
		{
			if (mang[i] == giatrigannhat1)
				printf("thu %d ", i + 1);
		}
	}
	else
	{
		printf("gia tri gan nhat voi Z trong mang la %d va %d\nxuat hien o vi tri ", giatrigannhat1, giatrigannhat2);
		for (i = 0; i < N; i++)
		{
			if (mang[i] == giatrigannhat1 || mang[i] == giatrigannhat2)
				printf("thu %d ", i + 1);
		}
	}
	printf("trong mang\n");
}

Câu 2:
#include<stdio.h>
void nhapmang(int *mang, int N);
void xuatmang(int *mang, int N);
bool kiemtra(int *mang, int N);
bool sort(int *mang, int N);
void insertX(int *mang, int N);
void main()
{
	int N;
	int mang[101];
	printf("moi nhap vao so nguyen duong N<100 N: ");
	do
	{
		scanf_s("%d", &N);
		if (N <= 0 || N > 100)
			printf("N ban vua nhap khong dung (0 < N <= 100\nmoi nhap lai N: ");
		else
			break;
	} while (1);
	printf("a) moi nhap %d phan tu mang\n", N);
	nhapmang(mang, N);
	printf("b) mang vua nhap la: ");
	xuatmang(mang, N);
	if (sort(mang, N))
		printf("\nd) mang da duoc sap xep san");
	else
	{
		printf("\nd) mang sau khi sap xep tang dan: ");
		xuatmang(mang, N);
	}
	insertX(mang, N);
	printf("mang sau khi chen X: ");
	xuatmang(mang, N + 1);
}
void nhapmang(int *mang, int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &mang[i]);
	}
}
void xuatmang(int *mang, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", mang[i]);
	}
}
bool kiemtra(int *mang, int N)
{
	int i;
	for (i = 0; i < N-1; i++)
	{
		if (mang[i] > mang[i + 1])
		{
			printf("\nc) day vua nhap khong phai day tang dan ");
			return false;
		}
	}
	printf("\nc) day vua nhap la day tang dan");
	return true;
}
bool sort(int *mang, int N)
{
	int temp;
	if (kiemtra(mang, N))
		return true;
	else
	{
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
	}
	return false;
}
void insertX(int *mang, int N)
{
	int x, i, j;
	printf("\ne) moi nhap so nguyen X: ");
	scanf_s("%d", &x);
	for (i = 0; i < N; i++)
	{
		if (x < mang[i])
			break;
	}
	for (j = N - 1; j >= i; j--)
	{
		mang[j + 1] = mang[j];
	}
	mang[i] = x;
}
