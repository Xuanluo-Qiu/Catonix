#include "catonix.h"

void endwin()
{
	if (win_conf.cursor == 0)
	{
		showCursor();
	}
	if (win_conf.color == 1)
	{
		col_end();
	}

	free_screen();
	printf("\x1b[J");
}