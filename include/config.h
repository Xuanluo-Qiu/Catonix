#ifndef CONFIG_H
#define CONFIG_H

typedef struct term_conf {
	_Bool cursor;
} TermConf;

extern TermConf win_conf;

#endif