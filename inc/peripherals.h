#ifndef LINEA_PERIPHERALS_H_
#define LINEA_PERIPHERALS_H_

#include <stdint.h>


extern long long unsigned int keymappings[16];
extern int keymappings_await[16];

void init_display();
void waitForKeyPressed();
void draw_pixel(int x, int y, int color);

#endif
