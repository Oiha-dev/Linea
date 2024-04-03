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

/**
 * exit_app: check if the exit key is pressed
 * @return 1 if the exit key is pressed, 0 otherwise
 */
int exit_app() {
    if (extapp_isKeydown(6)) {
        return 1;
    }
    return 0;
}

void draw_arrow(int x, int y, int color) {
    extapp_pushRectUniform(0 + x, 0 + y, 1, 9, color);
    extapp_pushRectUniform(1 + x, 1 + y, 1, 7, color);
    extapp_pushRectUniform(2 + x, 2 + y, 1, 5, color);
    extapp_pushRectUniform(3 + x, 3 + y, 1, 3, color);
    extapp_pushRectUniform(4 + x, 4 + y, 1, 1, color);
}

void draw_image(int x, int y, const char *filename) {
    // Read the file
    size_t len;
    const char *content = extapp_fileRead(filename, &len, EXTAPP_FLASH_FILE_SYSTEM);
    // Read the header
    char magic[3];
    int width, height, maxval;
    sscanf(content, "%s %d %d %d", magic, &width, &height, &maxval);

    // Skip the header
    const char *pixelData = content + strlen(magic) + 3 * sizeof(int);

    // Read the pixel data and draw the image in chunks
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the pixel color
            int r, g, b;
            if (strcmp(magic, "P3") == 0) {
                sscanf(pixelData, "%d %d %d", &r, &g, &b);
                pixelData += 3 * sizeof(int);
            } else if (strcmp(magic, "P6") == 0) {
                r = *pixelData++;
                g = *pixelData++;
                b = *pixelData++;
            }

            // Convert the color to a 16-bit color
            uint16_t color = ((g >> 3) << 11) | ((b >> 2) << 5) | (r >> 3);

            extapp_pushRectUniform(33 + x, 42 + y, 1, 1, color);
        }
    }
}