#include "inc/peripherals.h"
#include "extapp_api.h"
#include <string.h>


/**
 * init_display: clear the screen
 */
void init_display() {
  // Draw a rectangle to fill all the screen
  extapp_pushRectUniform(0, 0, 320, 240, 0xFFFF);
}

/**
 * draw_pixel: draw a pixel in the screen
 * @param x: x coordinate
 * @param y: y coordinate
 * @param color: color of the pixel
 */
void draw_pixel(int x, int y, int color) {
  extapp_pushRectUniform(x, y, 1, 1, color);
}
/**
 * waitForKeyPressed: wait for a key to be pressed
 */
void waitForKeyPressed() {
  // Scan the keyboard until we get a pressed key
  while (!extapp_scanKeyboard()) {
    // Sleep 10 milliseconds
    extapp_msleep(10);
  }
}
