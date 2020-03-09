#include"FUNC.h"

//tra ve tong cac phan tu cua mang A
int BAI12(int A[], int N, int i)
{
	if ((i + 1) == N)
		return A[i];
	else
		return A[i] + BAI12(A, N, i + 1);
}

//dao nguoc cac phan tu cua mang A
void BAI13(int A[], int N, int i)
{
	if (i < N / 2)
	{
		int temp = A[i];
		A[i] = A[N - 1 - i];
		A[N - 1 - i] = temp;
		BAI13(A, N, i + 1);
	}

}

//tra ve vi tri so lon nhat trong mang A
int BAI14(int A[], int N, int i)
{
	if (i + 1 < N)
	{
		int VTMax = BAI14(A, N, i + 1);
		if (A[i] > A[VTMax])
			return i;
		else
			return VTMax;
	}
	else
		return i;
}

//sap xep man theo thu tu tang dan
void BAI15(int A[], int N)
{
	BAI15(A, N, 0, N - 1);
}
void BAI15(int A[], int N, int head, int tail)
{
	if (head != tail)
	{
		int i = head, j = tail;
		int mid = (tail - head) / 2 + head;
		int ave = A[mid];
		for (i, j; i < j;)
		{
			if (A[i] > ave)
			{
				if (A[j] <= ave)
				{
					swap(A[i], A[j]);
					i++;
					j--;
				}
				else
					j--;
			}
			else
				i++;
		}
		BAI15(A, N, head, i - 1);
		BAI15(A, N, i, tail);
	}
}

//hoan vi 2 so a,b
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}