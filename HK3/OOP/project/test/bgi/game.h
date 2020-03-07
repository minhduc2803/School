#ifndef _GAME_H_
#define _GAME_H_

#include "board.h"
#include "common.h"
#include "display.h"
#include "graphics.h"

class Game {
	Board B;

public:

	void Processing();
	void BeginMenu();
	void NewGameMenu();
	void LoadGameMenu();
	void SaveGameMenu();
	int GetFlowInBeginMenu(int, int);
	int GetFlowInNewGameMenu(int, int);
	int GetFlowInLoadGameMenu(int, int);
};

#endif
