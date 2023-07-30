#include "display.h"

int WIDTH = 0;
int HEIGHT = 0;
int **screen;

void init_screen()
{
	update_terminal_size();
	screen = (int**)malloc(HEIGHT * sizeof(int*));
	for (int i=0; i<HEIGHT; i++)
	{
		screen[i] = (int*)malloc(WIDTH * sizeof(int));
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

void hideCursor()
{
	printf("\e[?25l");
	fflush(stdout);
}

void showCursor()
{
	printf("\e[?25h");
	fflush(stdout);
}

void draw_scene()
{
	for (int h=0; h<HEIGHT; h++)
	{
		for (int w=0; w<WIDTH; w++)
		{
			// printf("%d", data[h][w]);

			if (screen[h][w] == 0)
			{
				printf("~");
			} else {
				printf("_");
			}

		}
		printf("\n");
	}
	printf("\x1b[J");
	printf("\x1b[H");
}

void frame_rate(long begin, long current)
{
	long cont  = current - begin;
	long frame = 1000/FRAMERATE;
	long delay = frame - cont;
	if (delay>0)
	{
		usleep(delay);
	}
}
