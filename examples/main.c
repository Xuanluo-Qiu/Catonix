#include "catonix.h"

void event_loop();

int main(void)
{
	initscr();
	noecho(0);

	screen[3][6] = 1;

	enableRawMode();
	event_loop();
	disableRawMode();

	endwin();

	return 0;
}


void event_loop()
{
	char buffer[256];
	int bytesRead;

	while (1)
	{
		long begin = clock();

		draw_scene();

		bytesRead = read(0, buffer, sizeof(buffer)-1);
		if (bytesRead > 0)
		{
			buffer[bytesRead] = '\0';
			if (buffer[0] == 'q')
			{
				break;
			}
		}

		long current = clock();
		frame_rate(60, begin, current);
	}
}
