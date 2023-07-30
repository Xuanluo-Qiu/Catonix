#include "display.h"
#include "control.h"

void event_loop();

int main(void)
{
	update_terminal_size();
	init_screen();

	screen[3][6] = 1;

	enableRawMode();
	event_loop();
	disableRawMode();

	free_screen();

	return 0;
}


void event_loop()
{
	char buffer[256];
	int bytesRead;

	hideCursor();

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
				showCursor();
				break;
			}
		}

		long current = clock();
		frame_rate(begin, current);
	}
}
