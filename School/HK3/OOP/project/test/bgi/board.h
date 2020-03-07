#ifndef _BOARD_H_
#define _BOARD_H_

#include "display.h"
#include "saveload.h"

class Board{
	int LevelBot;
	int A[COLUMN][ROW];
	int X, O;
	int next;
public:

	void LoadGame(int kind);
	void NewGame(int kind);
	int InGameBot(int next = 1);
	int InGamePlayers(int next = 1);

	void InitBoard();
	void ChangeLevelBot();

	int GetFlowInGamePlayers(int x, int y);

	//test
	bool Full();
	bool InRange(int i, int j);
	int Count(int x, int y, int dx, int dy, int kind);
	int Win(int CursorX, int CursorY);
	void GoUp(int &cursorX, int &cursorY);
	void GoDown(int &cursorX, int &cursorY);
	void GoLeft(int &cursorX, int &cursorY);
	void GoRight(int &cursorX, int &cursorY);
	void Hit(int cursorX, int cursorY, bool &stopkeyboard);
	void FindCursor(int x, int y, int & cursorX, int &cursorY, bool &stopkeyboard);
};

#endif
