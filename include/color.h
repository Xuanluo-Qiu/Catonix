#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include "config.h"

#define FONT_MODE_NO 0
#define FONT_MODE_BOLD 1
#define FONT_MODE_UNDERLINE 4
#define FONT_MODE_INVERSE 7

extern enum FONT_FG_COL
{
	FG_BLACK = 30,
	FG_RED,
	FG_GREEN,
	FG_YELLOW,
	FG_BLUE,
	FG_PLUM,
	FG_CYAN,
	FG_WHITE
} FGCol;

extern enum FONT_BG_COL
{
	BG_BLACK = 41,
	BG_RED,
	BG_GREEN,
	BG_YELLOW,
	BG_BLUE,
	BG_PLUM,
	BG_CYAN,
	BG_WHITE
} BGCol;

void colprint(int mode, int fg_color, int bg_color);
void col_end();

#endif