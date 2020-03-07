#include "board.h"

void Board::LoadGame(int kind)
{
	int flow = 0;
	do
	{
		//InitBoard();
		Display::DisplayInGame(A, 2, 0, 0, 1, X, O);
		switch (kind)
		{
		case 1:
			flow = InGameBot(); break;
		case 2:
			flow = InGamePlayers(); break;
		}
	} while (flow != -1);
}
void Board::NewGame(int kind)
{
	int flow = 0;
	do
	{
		InitBoard();
		Display::DisplayInGame(A, 2, 0, 0, 1, X, O);
		switch (kind)
		{
		case 1:
			flow = InGameBot(); break;
		case 2:
			 flow = InGamePlayers(); break;
		}
	} while (flow != -1);
}
int Board::InGameBot(int next)
{
	int flow = 0;
	int x, y;

	int cursorX = 1, cursorY = 1;
	Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);
	Display::DisplayNextStep(next, 0);
	char c = 0;
	bool stopkeyboard = false; // == true when win or full board
	while (1)
	{
		//mouese press
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			flow = GetFlowInGamePlayers(x, y);
			clearmouseclick(WM_LBUTTONDOWN);

			switch (flow)
			{
			case 1:

			case 3:
				//save
				break;
			case 0:
				break;
			default:
				return flow;
			}
		}

		//key press
		if (!stopkeyboard)
		{
			if (GetKeyState('W') < 0)
			{
				while (GetKeyState('W') < 0);
				GoUp(cursorX, cursorY);
			}
			if (GetKeyState('S') < 0)
			{
				while (GetKeyState('S') < 0);
				GoDown(cursorX, cursorY);
			}
			if (GetKeyState('A') < 0)
			{
				while (GetKeyState('A') < 0);
				GoLeft(cursorX, cursorY);
			}
			if (GetKeyState('D') < 0)
			{
				while (GetKeyState('D') < 0);
				GoRight(cursorX, cursorY);
			}
			if (GetKeyState(13) < 0)
			{
				while (GetKeyState(13) < 0);
				Hit(cursorX, cursorY, stopkeyboard);
			}
		}
	}
}
int Board::InGamePlayers(int next)
{

	int flow = 0;
	int x, y;

	int cursorX = 1, cursorY = 1;
	Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);
	Display::DisplayNextStep(next, 0);
	char c = 0;
	bool stopkeyboard = false; // == true when win or full board
	while (1)
	{
		//mouese press
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			flow = GetFlowInGamePlayers(x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			
			switch (flow)
			{
			case 1:
				FindCursor(x, y, cursorX, cursorY, stopkeyboard);
			case 3:
				//save
				break;
			case 0:
				break;
			default:
				return flow;
			}
		}

		//key press
		
			if (GetKeyState('W') < 0)
			{
				while (GetKeyState('W') < 0);
				GoUp(cursorX,cursorY);
			}
			if (GetKeyState('S') < 0)
			{
				while (GetKeyState('S') < 0);
				GoDown(cursorX, cursorY);
			}
			if (GetKeyState('A') < 0)
			{
				while (GetKeyState('A') < 0);
				GoLeft(cursorX, cursorY);
			}
			if (GetKeyState('D') < 0)
			{
				while (GetKeyState('D') < 0);
				GoRight(cursorX, cursorY);
			}
			
			if (GetKeyState(13) < 0)
			{
				while (GetKeyState(13) < 0);
				Hit(cursorX, cursorY, stopkeyboard);
			}
			
	}

}

void Board::InitBoard()
{
	for (int i = 0; i < COLUMN; i++)
		for (int j = 0; j < ROW; j++)
			A[i][j] = 0;
	X = 0;
	O = 0;
	next = 1;
}
void Board::ChangeLevelBot()
{

}

int Board::GetFlowInGamePlayers(int x, int y)
{
	if (Common::GetClick(x, y, 11, 11, 10 + COLUMN * 40 - 1, 10 + ROW * 40 - 1))
		return 1;
	if (Common::GetClick(x, y, 680, 410, 960, 450))
		return 2;
	if (Common::GetClick(x, y, 680, 490, 960, 530))
		return 3;
	if (Common::GetClick(x, y, 680, 570, 960, 610))
		return -1;
	return 0;
}

bool Board::Full()
{
	if (X + O >= COLUMN*ROW)
		return true;
	else
		return false;
}
int Board::Win(int CursorX, int CursorY)
{
	int kind = A[CursorX][CursorY];

	if (Count(CursorX, CursorY, 1, 0, kind) + Count(CursorX, CursorY, -1, 0, kind) >= 4)
		return true;
	if (Count(CursorX, CursorY, 0, 1, kind) + Count(CursorX, CursorY, 0, -1, kind) >= 4)
		return true;
	if (Count(CursorX, CursorY, 1, 1, kind) + Count(CursorX, CursorY, -1, -1, kind) >= 4)
		return true;
	if (Count(CursorX, CursorY, 1, -1, kind) + Count(CursorX, CursorY, -1, 1, kind) >= 4)
		return true;
	return false;
}
bool Board::InRange(int i, int j)
{
	return (i >= 0 && j >= 0 && i < COLUMN && j < ROW);
}
int Board::Count(int x, int y, int dx, int dy, int kind)
{
	int sum = 0;
	int step = 0;
	do
	{
		x += dx;
		y += dy;
		if (InRange(x, y))
		{
			if (A[x][y] == kind)
				sum++;
			else
				break;
		}
		else
			break;
		step++;
	} while (step < 4);
	return sum;
}
void Board::GoUp(int &cursorX, int &cursorY)
{
	if (cursorY > 0)
	{
		Display::DrawCursor(cursorX, cursorY, 15, A[cursorX][cursorY]);
		cursorY--;
		Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);
	}
}
void Board::GoDown(int &cursorX, int &cursorY)
{
	if (cursorY < ROW - 1)
	{
		Display::DrawCursor(cursorX, cursorY, 15, A[cursorX][cursorY]);
		cursorY++;
		Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);
	}
}
void Board::GoLeft(int &cursorX, int &cursorY)
{
	if (cursorX > 0)
	{
		Display::DrawCursor(cursorX, cursorY, 15, A[cursorX][cursorY]);
		cursorX--;
		Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);
	}
}
void Board::GoRight(int &cursorX, int &cursorY)
{
	if (cursorX < COLUMN - 1)
	{
		Display::DrawCursor(cursorX, cursorY, 15, A[cursorX][cursorY]);
		cursorX++;
		Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);
	}
}
void Board::Hit(int cursorX, int cursorY, bool &stopkeyboard)
{
	if (!stopkeyboard && A[cursorX][cursorY] == 0)
	{
		Display::DrawXO(cursorX, cursorY, next);
		A[cursorX][cursorY] = next;
		next == 1 ? X++, Display::DisplayNumberOfX() : O++, Display::DisplayNumberOfO();
		

		int num = (next == 1) ? X : O;
		next = -next;
		Display::DisplayNextStep(next, num);
		
		if (Win(cursorX, cursorY))
		{
			stopkeyboard = true;
			Display::DisplayWin(A[cursorX][cursorY]);
		}
		else 
		{

			if (Full())
			{
				stopkeyboard = true;
				Display::DisplayDraw();
			}
		}
		
	}
}
void Board::FindCursor(int x, int y, int & cursorX, int &cursorY , bool &stopkeyboard)
{
	x = x - 10;
	y = y - 10;
	if (x % 40 == 0 || y % 40 == 0)
		return;

	Display::DrawCursor(cursorX, cursorY, 15, A[cursorX][cursorY]);
	cursorX = x / 40;
	cursorY = y / 40;
	Display::DrawCursor(cursorX, cursorY, 7, A[cursorX][cursorY]);

	Hit(cursorX, cursorY, stopkeyboard);
}