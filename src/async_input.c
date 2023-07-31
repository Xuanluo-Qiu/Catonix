#include "async_input.h"

struct termios orig_term;

void enableRawMode()
{
	struct termios term;
	tcgetattr(0, &term);
	orig_term = term;
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
}

void disableRawMode()
{
	tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
}