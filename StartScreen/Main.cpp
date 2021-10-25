#include "StartScreen.h"
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700



int main()
{
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	fixConsoleWindow();
	noCursorType();

	Sleep(1000);

	khtn(45, 6, 30, 3000, 1);
	khtn(45, 6, 30, 2000, 0);

	team5(45, 6, 30, 3000, 3);
	team5(45, 6, 30, 2000, 0);

	startScreen(17, 4);

	goToXY(0, 37);
	return 0;
}