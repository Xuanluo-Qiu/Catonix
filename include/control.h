#ifndef CONTROL_H
#define CONTROL_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>

void enableRawMode();
void disableRawMode();

#endif