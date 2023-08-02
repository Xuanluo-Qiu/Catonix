#include "display.h"

void init_screen()
{
	update_terminal_size();
	win_conf.data = (char *)malloc(win_conf.height * win_conf.width * sizeof(char));
	for (int i = 0; i < win_conf.height * win_conf.width; i++) {
		win_conf.data[i] = ' ';
	}
}

void free_screen()
{
	free(win_conf.data);
}

void update_terminal_size() {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	win_conf.width = size.ws_col;
	win_conf.height = size.ws_row-1;
}

void draw_scene()
{
	for (int h=0; h<win_conf.height; h++)
	{
		int index = h * win_conf.width;
		printf("%.*s\n", win_conf.width, win_conf.data + index);
	}
	printf("\x1b[J\x1b[H");
}

void frame_rate(int frame_number, long begin, long current)
{
	long cont  = current - begin;
	long frame = 1000/frame_number;
	long delay = frame - cont;
	if (delay>0)
	{
		usleep(delay);
	}
}
