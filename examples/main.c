#include "catonix.h"

void event_loop();

int main(void)
{
	init_screen();
	hideCursor();

	win_conf.data[3 * win_conf.width + 1] = 'H';

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
			} else if (buffer[0] == 'c') {
				colprint(
					FONT_MODE_BOLD,
					FGCol=FG_BLUE,
					BGCol=BG_CYAN
				);
			} else if (buffer[0] == 'b') {
				col_end();
			}
		}

		long current = clock();
		frame_rate(60, begin, current);
	}
}
