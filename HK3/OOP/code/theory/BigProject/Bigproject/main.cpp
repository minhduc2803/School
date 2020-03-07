#include<iostream>
#include <windows.h>
#include<conio.h>
#include <ctime>
using namespace std;

void gotoXY(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void FixConsole()
{
	HWND screen = GetConsoleWindow();
	MoveWindow(screen, 300, 100, 1000, 500, TRUE);
	int style = GetWindowLong(screen, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(screen, GWL_STYLE, style);
}
void Board()
{
	int size = 10;
	int left = 3, top = 1;
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			gotoXY(left + 6 * i, top + 3 * j);
			printf(".");
		}
	}
}
void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
int TestWin(int **a)
{
	for (int k = 0; k < 10; k++)
	{
		int sum1 = 0;
		for (int i = 0; i < 5; i++)
			sum1 += a[0][i];
		if (sum1 == 5)
			return 1;
		else if (sum1 == -5)
			return -1;
		for (int i = 5; i < 10; i++)
		{
			sum1 = sum1 + a[k][i] - a[k][i - 5];
			if (sum1 == 5)
				return 1;
			else if (sum1 == -5)
				return -1;
		}

		int sum2 = 0;
		for (int i = 0; i < 5; i++)
			sum2 += a[i][k];
		if (sum2 == 5)
			return 1;
		else if (sum2 == -5)
			return -1;
		for (int i = 5; i < 10; i++)
		{
			sum2 = sum2 + a[i][k] - a[i - 5][k];
			if (sum2 == 5)
				return 1;
			else if (sum2 == -5)
				return -1;
		}

	}
	return 0;
}
int main()
{
	setFontSize(12);
	FixConsole();
	system("color F0");
	Board();
	char c = 0;
	int x = 6, y = 3;
	gotoXY(x, y);
	bool flag = true;
	int **a = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = new int[10];
		for (int j = 0; j < 10; j++)
			a[i][j] = 0;
	}
	int win = 0;
	while (1)
	{
		win = TestWin(a);
		if (win != 0)
			break;
		c = getch();
		switch (c)
		{
		case 'w':
			if (y > 3)
			{
				y -= 3;
				gotoXY(x, y);
			}
			break;
		case 's':
			if (y < 28)
			{
				y += 3;
				gotoXY(x, y);
			}
			break;
		case 'a':
			if (x > 6)
			{
				x -= 6;
				gotoXY(x, y);
			}
			break;
		case 'd':
			if (x < 57)
			{
				x += 6;
				gotoXY(x, y);
			}
			break;
		case 13:
			gotoXY(x, y);
			if (a[(x-3)/6][(y-1)/3] != 0)
				break;
			if (flag)
			{
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
				cout << "X";
				flag = false;
				a[(x - 3) / 6][(y - 1) / 3] = 1;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 249);
				cout << "O";
				flag = true;
				a[(x - 3) / 6][(y - 1) / 3] = -1;
			}
		}
	}
	gotoXY(63, 3);
	if (win == 1)
		cout << "X win";
	else
		cout << "O win";
	return 0;
}