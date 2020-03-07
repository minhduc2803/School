#include "display.h"

void Display::DisplayBeginMenu()
{
	Common::BackroundColor(0);
	
	TextSuperCaro();
	
	settextstyle(2, HORIZ_DIR, 10);
	setcolor(14);

	outtextxy(500, 400, "New Game");
	outtextxy(500, 500, "Load Game");
	outtextxy(500, 600, "Exit");
	
	DrawArrowRight(380, 415, 5);
	DrawArrowRight(380, 515, 5);
	DrawArrowLeft(400, 615, 5);

}
void Display::DisplayNewGameMenu()
{
	Common::BackroundColor(0);

	TextSuperCaro();

	settextstyle(2, HORIZ_DIR, 10);
	setcolor(14);

	outtextxy(150, 400, "New Game");

	outtextxy(650, 400, "1 Player");
	outtextxy(650, 500, "2 Players");
	outtextxy(650, 600, "Back");
	
	DrawArrowRight(530, 415,5);
	DrawArrowRight(530, 515,5);
	DrawArrowLeft(550, 615,5);

}
void Display::DisplayLoadGameMenu()
{
	Common::BackroundColor(0);

	TextSuperCaro();

	settextstyle(2, HORIZ_DIR, 10);
	setcolor(14);

	outtextxy(150, 400, "Load Game");

	outtextxy(650, 400, "1 Player");
	outtextxy(650, 500, "2 Players");
	outtextxy(650, 600, "Back");

	DrawArrowRight(530, 415, 5);
	DrawArrowRight(530, 515, 5);
	DrawArrowLeft(550, 615, 5);
}
void Display::TextSuperCaro()
{
	settextstyle(2, HORIZ_DIR, 20);
	setcolor(14);
	outtextxy(150, 150, "Super Car");

	setcolor(GREEN);
	outtextxy(380, 150, "o");
	outtextxy(410, 105, "o");
	outtextxy(440, 150, "o");
	setcolor(RED);
	outtextxy(412, 150, "x");
	outtextxy(382, 195, "x");
	outtextxy(442, 105, "x");
}
void Display::DrawArrowRight(int x, int y, int color)
{
	setcolor(color);

	line(x - 30, y - 15, x, y);
	line(x - 30, y - 15, x + 20, y);
	line(x - 30, y + 15, x, y);
	line(x - 30, y + 15, x + 20, y);

	line(x + 10, y - 10, x + 33, y);
	line(x + 10, y - 10, x + 50, y);
	line(x + 10, y + 10, x + 33, y);
	line(x + 10, y + 10, x + 50, y);

}
void Display::DrawArrowLeft(int x, int y, int color)
{
	setcolor(color);
	line(x + 30, y - 15, x, y);
	line(x + 30, y - 15, x - 20, y);
	line(x + 30, y + 15, x, y);
	line(x + 30, y + 15, x - 20, y);

	line(x - 10, y - 10, x - 33, y);
	line(x - 10, y - 10, x - 50, y);
	line(x - 10, y + 10, x - 33, y);
	line(x - 10, y + 10, x - 50, y);
}

void Display::DrawBoard(int x, int y, int Column, int Row, int Width, int High, int Color)
{
	setcolor(Color);

	int i = x;
	int maxi = Width*Column + x;
	int maxj = High*Row + y;
	
	for (int NumColumn = 0; NumColumn <= Column; NumColumn++,i+=Width)
		line(i, y, i, maxj);
	int j = y;
	for (int NumRow = 0; NumRow <= Row; NumRow++,j+=High)
		line(x, j, maxi, j);
}
void Display::DisplayInGame(int A[COLUMN][ROW], int kind, int lastx, int lasto, int next, int sumx, int sumo)
{
	Common::BackroundColor(15);

	
	DrawBoard(10, 10, COLUMN, ROW, 40, 40, 5);

	//setfillstyle(SOLID_FILL, 1);
	//floodfill(1, 1, 5);

	settextstyle(1, HORIZ_DIR, 3);
	setcolor(0);

	int optionx = 640;
	int optiony = 130;
	outtextxy(optionx, optiony, "Player 1  vs  Player 2");

	DrawXO(COLUMN + 2, 4, 1);
	DrawXO(COLUMN + 7, 4, -1);

	setcolor(5);

	rectangle(optionx, optiony + 40, optionx + 130, optiony + 80);
	rectangle(optionx + 210, optiony + 40, optionx + 340, optiony + 80);

	settextstyle(1, HORIZ_DIR, 4);
	setcolor(5);

	char c[4];

	itoa(sumx, c, 10);
	outtextxy(optionx, optiony + 90, c);

	itoa(sumo, c, 10);
	outtextxy(optionx + 210, optiony + 90, c);

	setfillstyle(SOLID_FILL, 0);
	bar(optionx + 50, optiony + 280, optionx + 320, optiony + 320);
	bar(optionx + 50, optiony + 360, optionx + 320, optiony + 400);
	bar(optionx + 50, optiony + 440, optionx + 320, optiony + 480);

	settextstyle(2, HORIZ_DIR, 10);
	setcolor(14);

	outtextxy(optionx + 50, optiony + 280, "New Game");
	outtextxy(optionx + 50, optiony + 360, "Save Game");
	outtextxy(optionx + 50, optiony + 440, "Back");
}

void Display::DrawXO(int x, int y, int kind ,int out)
{
	settextstyle(4, HORIZ_DIR, 5);
	
	switch (kind)
	{
	case 1:
		x = x * 40 + 14;
		y = y * 40 + 7;
		if (out == 0)
			setcolor(4);
		else
			setcolor(7);
		outtextxy(x, y, "x");
		break;
		
	case -1:
		x = x * 40 + 12;
		y = y * 40 + 7;
		if (out == 0)
			setcolor(2);
		else
			setcolor(7);
		outtextxy(x, y, "o");
		break;
	}
}

void Display::DrawCursor(int x, int y, int color, int kind)
{
	setfillstyle(SOLID_FILL, color);
	floodfill(x * 40 + 11, y * 40 + 11, 5);
	DrawXO(x, y, kind);
}
void Display::DisplayNumberOfX()
{

}
void Display::DisplayNumberOfO()
{

}
void Display::DisplayWin(int kind)
{
	int vx, dx;
	int y = 2 * 40 + 10;
	if (kind == 1)
	{

		setfillstyle(SOLID_FILL, 15);
		floodfill(852, 172, 5);
		DrawXO(COLUMN + 7, 4, -1, 1);

		setfillstyle(SOLID_FILL, 14);
		floodfill(642, 172, 5);
		DrawXO(COLUMN + 2, 4, 1);

		setcolor(RED);
		vx = COLUMN * 40+ 40;
		dx = vx + 210;

	}
	else
	{
		setfillstyle(SOLID_FILL, 15);
		floodfill(642, 172, 5);
		DrawXO(COLUMN + 2, 4, 1, 1);

		setfillstyle(SOLID_FILL, 14);
		floodfill(852, 172, 5);
		DrawXO(COLUMN + 7, 4, -1);

		setcolor(GREEN);
		vx = COLUMN * 40 + 245;
		dx = vx - 200;
	}
	settextstyle(2, HORIZ_DIR, 9);
	
	outtextxy(vx, y, "Victory");

	setcolor(7);
	outtextxy(dx, y, "Defeat");
}
void Display::DisplayDraw()
{
	int drawx = 40 * (COLUMN + 4);
	int drawy = 2 * 40 + 10;

	settextstyle(2, HORIZ_DIR, 2);

	outtextxy(drawx, drawy, "Draw");
}

void Display::DisplayNextStep(int kind, int num)
{
	if (kind == 1)
	{
		setfillstyle(SOLID_FILL, 15);
		floodfill(852, 172, 5);
		DrawXO(COLUMN + 7, 4, -1, 1);

		setfillstyle(SOLID_FILL, 0);
		floodfill(642, 172, 5);
		DrawXO(COLUMN + 2, 4, 1);

		setfillstyle(SOLID_FILL, 15);
		bar(840, 220, 940, 260);

		settextstyle(1, HORIZ_DIR, 4);
		setcolor(5);

		char c[4];

		itoa(num, c, 10);
		outtextxy(850, 220, c);
	}
	else
	{
		setfillstyle(SOLID_FILL, 15);
		floodfill(642, 172, 5);
		DrawXO(COLUMN + 2, 4, 1, 1);
		
		setfillstyle(SOLID_FILL, 0);
		floodfill(852, 172, 5);
		DrawXO(COLUMN + 7, 4, -1);

		setfillstyle(SOLID_FILL, 15);
		bar(640, 220, 740, 260);

		settextstyle(1, HORIZ_DIR, 4);
		setcolor(5);

		char c[4];

		itoa(num, c, 10);
		outtextxy(640, 220, c);
		
	}
}
