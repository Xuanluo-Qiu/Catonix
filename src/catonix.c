#include "catonix.h"

void initscr()
{
	update_terminal_size();
	init_screen();
}

void noecho(int if_echo)
{
	if (if_echo == 0)
	{
		hideCursor();
	}
}


void endwin()
{
	showCursor();
	free_screen();
}