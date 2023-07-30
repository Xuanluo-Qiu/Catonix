#ifndef DISPLAY_H
#define DISPLAY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>
#include "config.h"

extern int WIDTH;
extern int HEIGHT;
extern int **screen;

void init_screen();
void free_screen();
void update_terminal_size();
void hideCursor();
void showCursor();
void draw_scene();
void frame_rate(long bengin, long current);

#endif