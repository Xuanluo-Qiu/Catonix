#include "display.h"

void hideCursor()
{
	win_conf.cursor = 0;
	printf("\e[?25l");
	fflush(stdout);
}

void showCursor()
{
	win_conf.cursor = 1;
	printf("\e[?25h");
	fflush(stdout);
}

void setCursorBlinking(int blinkType)
{
	printf("\033[?%dh", blinkType);
}