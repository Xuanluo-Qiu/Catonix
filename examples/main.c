#include "catonix.h"

void event_loop();

int main(void)
{
	init_screen();
	hideCursor();

	win_conf.data[3 * win_conf.width + 1] = 'H';
	win_conf.data[win_conf.height-10 * win_conf.width + 1] = 'Y';

	// printf("%d\n", win_conf.height);
	// printf("\n%c\n", win_conf.data[win_conf.height-3 * win_conf.width + 1]);
	// getchar();

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
					FGCol=FG_BLACK,
					BGCol=BG_CYAN
				);
			} else if (buffer[0] == 'b') {
				col_end();
			}
		}

		long current = clock();
		frame_rate(120, begin, current);
	}
}
