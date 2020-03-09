#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 4)
		printf("Tham so nhap sai %d ! !",argc);
	else
	{
		int x = atoi(argv[1]);
		int y = atoi(argv[3]);
		printf("%d + %d = ", x, y);
		switch (argv[2][0])
		{
		case '+': printf("%d", x + y); break;
		case '-': printf("%d", x - y); break;
		case '*': printf("%d", x * y); break;
		case '/': printf("%.2f", 1.0*x / y); break;
		default: printf("Tham so nhap sai !");
		}
	}
}