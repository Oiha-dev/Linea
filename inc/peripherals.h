#ifndef LINEA_PERIPHERALS_H_
#define LINEA_PERIPHERALS_H_

#include <stdint.h>


extern long long unsigned int keymappings[16];
extern int keymappings_await[16];

void init_display();
void waitForKeyPressed();
void draw_pixel(int x, int y, int color);
int exit_app();
void draw_arrow(int x, int y, int color);
void draw_image(int x, int y, const char *filename);
uint16_t invert_color(uint16_t color);
void draw_cursor(int x, int y, int size, int color1);

#endif
