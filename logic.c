#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "extapp_api.h"

#include "inc/logic.h"
#include "inc/peripherals.h"
#include "inc/screens.h"

// TODO: Make a file with all the colors and parameters
int color_1 = 0x0E88;
int color_2 = 0xC7E1;
int color_3 = 0xFBE4;
int color_4 = 0x055E;
int color_5 = 0x0000;
int color_6 = 0xE8E4;
int color_7 = 0x001F;

#define WIDTH  271   // Width of the image
#define HEIGHT 189   // Height of the image
#define WIDTH_OFFSET  33   // Width offset of the image
#define HEIGHT_OFFSET  42   // Height offset of the image
int image[HEIGHT][WIDTH]; // Image to be drawn

//Drawing is the function that will make the user able to draw on the screen
void Drawing(){
    Refresh();
    int CursorX = 0;
    int CursorY = 0;
    int CursorColor = color_1;
    int CursorSize = 1;

    while (true){
        if (exit_app() == 1) {
            return;
        }
        //Draw the cursor
        for (int i = 0; i < CursorSize; i++){
            for (int j = 0; j < CursorSize; j++){
                extapp_pushRectUniform(CursorX + i, CursorY + j, 1, 1, CursorColor);
            }
        }
        //Make the cursor move
        if (extapp_isKeydown(KEY_CTRL_UP)){
            CursorY -= 1;
        }
        if (extapp_isKeydown(KEY_CTRL_DOWN)){
            CursorY += 1;
        }
        if (extapp_isKeydown(KEY_CTRL_LEFT)){
            CursorX -= 1;
        }
        if (extapp_isKeydown(KEY_CTRL_RIGHT)){
            CursorX += 1;
        }
    }

}

void Files(){
    int MAX_FILENAMES = 4;
    const char *filenames[MAX_FILENAMES];
    int num_files = extapp_fileListWithExtension(filenames, MAX_FILENAMES, ".ppm", EXTAPP_FLASH_FILE_SYSTEM);

    if (num_files > 0) {
        for (int i = 0; i < num_files; i++) {
            // Read the file
            size_t len;
            const char *content = extapp_fileRead(filenames[i], &len, EXTAPP_FLASH_FILE_SYSTEM);
            if (content != NULL) {
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

                        // Here i convert the color to a 16-bit color but it's very strange and i don't know why it works like this lmfao
                        uint16_t color = ((g >> 3) << 11) | ((b >> 2) << 5) | (r >> 3);

                        extapp_pushRectUniform(WIDTH_OFFSET + x, HEIGHT_OFFSET + y, 1, 1, color);
                    }
                }
            }
        }
    }
}