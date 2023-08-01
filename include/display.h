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
extern char **screen;

void init_screen();
void free_screen();
void update_terminal_size();
void draw_scene();
void frame_rate(int frame_number, long bengin, long current);

void hideCursor();
void showCursor();
void setCursorBlinking(int blinkType);

#endif