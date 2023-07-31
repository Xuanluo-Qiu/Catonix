#include "catonix.h"

void initscr()
{
	update_terminal_size();
	init_screen();
}

void endwin()
{
	if (win_conf.cursor == 0)
	{
		showCursor();
	}

	free_screen();
}