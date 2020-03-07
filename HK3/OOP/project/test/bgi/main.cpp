#include<dos.h>
#include<iostream>
#include"graphics.h"
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include "game.h"
#include "common.h"
#include "board.h"
#include "display.h"

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
	
	Game G;
	G.Processing();

	return 0;
}