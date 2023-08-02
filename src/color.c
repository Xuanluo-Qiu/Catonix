#include "color.h"

enum FONT_FG_COL FGCol;
enum FONT_BG_COL BGCol;

void colprint(int mode, int fg_color, int bg_color)
{
	win_conf.color = 1;
	printf("\x1b[%d;%d;%dm", mode, fg_color, bg_color);
}

void col_end()
{
	printf("\x1b[0m");
}