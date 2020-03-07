#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "graphics.h"
#include "common.h"
#include "winbgitypes.h"
#include <dos.h>
#include <Windows.h>
#include <iostream>

using namespace std;

#define COLUMN 15
#define ROW 15

class Display {
	friend class Board;
	friend class Game;
	friend class SaveAndLoad;
public:
	static void DisplayBeginMenu();
	static void DisplayNewGameMenu();
	static void DisplayLoadGameMenu();
	static void TextSuperCaro();
	static void DrawArrowRight(int, int, int);
	static void DrawArrowLeft(int, int, int);

	static void DisplayInGame(int A[COLUMN][ROW], int kind, int lastx, int lasty, int next, int sumx, int sumo);
	static void DrawBoard(int x, int y, int Column, int Row, int Width, int High, int Color);
	static void DrawXO(int x, int y, int kind, int out = 0);
	static void DrawCursor(int x, int y, int color, int kind);
	static void DisplayNumberOfX();
	static void DisplayNumberOfO();
	static void DisplayNextStep(int kind, int num);

	static void DisplayWin(int kind);
	static void DisplayDraw();
};

#endif
