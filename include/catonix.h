#ifndef CATONIX_H
#define CATONIX_H

#include "config.h"
#include "color.h"
#include "display.h"
#include "async_input.h"

void initscr();
void noecho();
// TODO
// void curs_set();
// void refresh();
void endwin();

#endif