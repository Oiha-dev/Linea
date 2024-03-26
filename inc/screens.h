#ifndef LINEA_SCREENS_H
#define LINEA_SCREENS_H

#include <stdint.h>

extern long long unsigned int keymappings[16];
extern int keymappings_await[16];

void Header();
void blank_page(int color);
void optionScreen(int arrow, int last_arrow, int first_time);
void Refresh();
int Tutorial();
int About();


#endif
