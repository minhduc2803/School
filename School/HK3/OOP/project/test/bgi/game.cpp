#include "game.h"

void Game::Processing()
{
	Common::Screen();
	BeginMenu();
}

void Game::BeginMenu()
{
	Display::DisplayBeginMenu();
	int flow = 0;
	int x, y;

	do
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			flow = GetFlowInBeginMenu(x, y);
			switch (flow)
			{
			case 1:
				NewGameMenu(); break;
			case 2:
				LoadGameMenu(); break;
			}
			clearmouseclick(WM_LBUTTONDOWN);
			Display::DisplayBeginMenu();
		}
	} while (flow != -1);
}

void Game::NewGameMenu()
{
	int flow = 0;
	int x, y;
	Display::DisplayNewGameMenu();
	do
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			flow = GetFlowInBeginMenu(x, y);
			if (flow == 1 || flow == 2)
				B.NewGame(flow);
			clearmouseclick(WM_LBUTTONDOWN);
			Display::DisplayNewGameMenu();
		}
	} while (flow != -1);
}
void Game::LoadGameMenu()
{
	Display::DisplayLoadGameMenu();
	int flow = 0;
	int x, y;
	do
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			flow = GetFlowInBeginMenu(x, y);
			if (flow == 1 || flow == 2)
				B.LoadGame(flow);
			clearmouseclick(WM_LBUTTONDOWN);
		}
	} while (flow != -1);
}
int Game::GetFlowInBeginMenu(int x, int y)
{
	if (Common::GetClick(x, y, 500, 400, 860, 435))
		return 1;
	if (Common::GetClick(x, y, 500, 500, 860, 535))
		return 2;
	if (Common::GetClick(x, y, 500, 600, 860, 635))
		return -1;
	return 0;
}
int Game::GetFlowInNewGameMenu(int x, int y)
{
	return GetFlowInBeginMenu(x, y);
}
int Game::GetFlowInLoadGameMenu(int x, int y)
{
	return GetFlowInBeginMenu(x, y);
}
void Game::SaveGameMenu()
{

}