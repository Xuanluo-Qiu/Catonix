#ifndef CONFIG_H
#define CONFIG_H

typedef struct term_conf {
	int width;
	int height;
	char *data;
	_Bool cursor;
	_Bool color;
} TermConf;

extern TermConf win_conf;

#endif