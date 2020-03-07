					Bài tập thực hành tuần 01   
Họ tên: Nguyễn Minh Đức 
MSSV: 1712358 
Lớp: 17CTT3 
Ca thực hành: Chiều Thứ 2, Ca 2, PM. NĐH_4.1
Đề bài:
Câu 1:
Viết chương trình nhập số thực  R, tính diện tích hình tròn có bán kính R, biết Pi = 3.14159.         
Câu 2:
Viết chương trình nhập số nguyên N, in ra cho biết góc có số đo N0 thuộc cung phần tư số mấy của đường tròn lượng giác.
Biết: góc có số đo [0..90): cung phần tư số 1, [90..180): cung phần tư số 2, [180.. 270): cung phần tư số 3,
[270..360): cung phần tư số 4.
Câu 3:
Viết chương trình nhập 2 số nguyên a, b. In ra cho biết chu vi, diện tích của hình chữ nhật có độ dài 2 cạnh là a, b.
Câu 4:
Viết chương trình nhập vào 1 ký tự, in ra ký tự in hoa tương ứng.
Câu 5:
Viết chương trình nhập vào 1 số nguyên, in ra ký tự tương ứng và ngược lại, nhập một ký tự, in ra mã ASCII của ký tự đó.
Câu 6:
Viết chương trình thực hiện các phép tính sau:
a)
A.2n, với A, n là các số nguyên
b)
B/2m, với B, m là các số nguyên

Bài làm:
Câu 1:

#include<stdio.h>
#include<stdlib.h>
#define pi 3.14159

void main()
{
	float r;
	printf("moi nhap ban kinh r:");
	scanf_s("%f", &r);
	printf("\ndien tich hinh tron la: %f\n", pi*r*r);
	system("pause");
}

Câu 2:

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n1,n,a;
	printf("moi nhap so do goc N:");
	scanf_s("%d", &n1);
	n = n1 % 360;
	a = n / 90;
	printf("\nso do goc N thuoc cung phan tu so %d\n", a+1);
	system("pause");
}

Câu 3:

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a, b;
	printf("moi nhap do dai 2 kich thuoc hinh chu nhat\na=");
	scanf_s("%d", &a);
	printf("\nb=");
	scanf_s("%d", &b);
	printf("chu vi hinh chu nhat la: %d, dien tich hinh chu nhat la: %d\n", 2 * (a + b), a*b);
	system("pause");
}

Câu 4:

#include<stdio.h>
#include<stdlib.h>
void main()
{
	char a;
	printf("moi nhap 1 ky tu thuong: ");
	a = getchar();
	printf("\nky tu hoa tuong ung la: %c\n", a-32);
	system("pause");
}

Câu 5:

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a;
	char b;
	printf("moi nhap 1 so: ");
	scanf_s("%d", &a);
	printf("\nky tu tuong ung vs ma ASCII tren la: %c\n", a);
	printf("moi nhap 1 ku tu: ");
	getchar();
	b = getchar();
	printf("ma ASCII tuong ung vs ky tu tren la: %d\n", b);
	system("pause");
}

Câu 6a:

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a, n;
	printf("moi nhap lan luot so nguyen A:  ");
	scanf_s("%d", &a);
	printf("va so nguyen n: ");
	scanf_s("%d", &n);
	a = a << n;
	printf("\nA.2^n=%d\n", a);
	system("pause");
}

Câu 6b:

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int b, n;
	printf("moi nhap lan luot so nguyen B:  ");
	scanf_s("%d", &b);
	printf("va so nguyen n: ");
	scanf_s("%d", &n);
	b = b >> n;
	printf("\nB/(2^n)=%d\n", b);
	system("pause");
}
