#include "display.h"

int WIDTH = 0;
int HEIGHT = 0;
char **screen;

void init_screen()
{
	update_terminal_size();
	screen = (char**)malloc(HEIGHT * sizeof(char*));
	for (int i=0; i<HEIGHT; i++)
	{
		screen[i] = (char*)malloc(WIDTH * sizeof(char));
	}
}

void free_screen()
{
	for (int i=0; i<HEIGHT; i++)
	{
		free(screen[i]);
	}
	free(screen);
}

void update_terminal_size() {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	WIDTH = size.ws_col;
	HEIGHT = size.ws_row - 1;
}

void draw_scene()
{
	for (int h=0; h<HEIGHT; h++)
	{
		for (int w=0; w<WIDTH; w++)
		{
			printf("%c", screen[h][w]);
		}
		printf("\n");
	}
	printf("\x1b[J");
	printf("\x1b[H");
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
