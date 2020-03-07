#include "common.h"

void Common::BackroundColor(int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(0, 0, 999, 649);
}
void Common::Screen()
{
	HWND   hwndScreen = GetDesktopWindow();
	RECT   rectScreen;
	GetWindowRect(hwndScreen, &rectScreen);

	int pX = (rectScreen.right - rectScreen.left - 1000) / 2;
	int pY = (rectScreen.bottom - rectScreen.top - 650) / 2;

	initwindow(1000, 650, "Super Caro", pX, pY);
}
bool Common::GetClick(int x, int y, int x1, int y1, int x2, int y2)
{
	if (x >= x1 && x <= x2)
		if (y >= y1 && y <= y2)
			return true;

	return false;
}
