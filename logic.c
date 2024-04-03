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
void Drawing(int refresh){
    extapp_msleep(200);
    if (refresh == 1){
        Refresh();
    }
    int CursorX = 33;
    int CursorY = 42;
    int CursorColor = color_1;
    int CursorSize = 1;
    int isDrawing = 0;
    // This is the cursor part where I store the value of the current pixel to be able to restore it later
    uint16_t CursorColor1;
    extapp_pullRect(CursorX, CursorY, 1, 1, &CursorColor1);
    extapp_pushRectUniform(CursorX, CursorY, 1, 1, CursorColor);


    while (true){
        isDrawing = 0;

        if (exit_app() == 1) {
            return;
        }


        // Change the size of the cursor
        if (extapp_isKeydown(45) && CursorSize < 10){
            CursorSize += 1;
            extapp_msleep(200);
        }
        if (extapp_isKeydown(46) && CursorSize > 1){
            CursorSize -= 1;
            extapp_msleep(200);
        }

        if (extapp_isKeydown(KEY_CTRL_OK)){
            for (int i = 0; i < CursorSize; i++){
                for (int j = 0; j < CursorSize; j++){
                    extapp_pushRectUniform(CursorX + i, CursorY + j, 1, 1, CursorColor);
                    isDrawing = 1; // isDrawing = 1 means that the cursor is drawing
                }
            }
        }


        // Make the cursor move
        if (extapp_isKeydown(KEY_CTRL_UP) && CursorY > HEIGHT_OFFSET){
            if (isDrawing == 0){
                extapp_pushRectUniform(CursorX, CursorY, 1, 1, CursorColor1);
            }
            CursorY -= 1;
            extapp_pullRect(CursorX, CursorY, 1, 1, &CursorColor1);
            extapp_pushRectUniform(CursorX, CursorY, 1, 1, isDrawing ? CursorColor : 0x0000);
        }
        if (extapp_isKeydown(KEY_CTRL_DOWN) && CursorY < HEIGHT + HEIGHT_OFFSET - CursorSize){
            if (isDrawing == 0){
                extapp_pushRectUniform(CursorX, CursorY, 1, 1, CursorColor1);
            }
            CursorY += 1;
            extapp_pullRect(CursorX, CursorY, 1, 1, &CursorColor1);
            extapp_pushRectUniform(CursorX, CursorY, 1, 1, isDrawing ? CursorColor : 0x0000);
        }
        if (extapp_isKeydown(KEY_CTRL_LEFT) && CursorX > WIDTH_OFFSET){
            if (isDrawing == 0){
                extapp_pushRectUniform(CursorX, CursorY, 1, 1, CursorColor1);
            }
            CursorX -= 1;
            extapp_pullRect(CursorX, CursorY, 1, 1, &CursorColor1);
            extapp_pushRectUniform(CursorX, CursorY, 1, 1, isDrawing ? CursorColor : 0x0000);
        }
        if (extapp_isKeydown(KEY_CTRL_RIGHT) && CursorX < WIDTH + WIDTH_OFFSET - CursorSize){
            if (isDrawing == 0){
                extapp_pushRectUniform(CursorX, CursorY, 1, 1, CursorColor1);
            }
            CursorX += 1;
            extapp_pullRect(CursorX, CursorY, 1, 1, &CursorColor1);
            extapp_pushRectUniform(CursorX, CursorY, 1, 1, isDrawing ? CursorColor : 0x0000);
        }
    }
}

void Files(){
    Refresh();
    int isInLoop = 0;
    int MAX_FILENAMES = 8;
    const char *filenames[MAX_FILENAMES];
    int num_files = extapp_fileListWithExtension(filenames, MAX_FILENAMES, ".ppm", EXTAPP_FLASH_FILE_SYSTEM);
    int selected_file = 0;
    for (int i = 0; i < num_files; i++) {
        // Display the file name
        char filenameWidth[50];
        sprintf(filenameWidth, "%d", extapp_drawTextLarge(filenames[i], WIDTH_OFFSET, HEIGHT_OFFSET, 0xFFFF, 0xFFFF, false) - WIDTH_OFFSET); // This is relly messy, but it works
        extapp_drawTextLarge(filenames[i], WIDTH_OFFSET + 135 - (extapp_drawTextLarge(filenames[i], WIDTH_OFFSET, HEIGHT_OFFSET, 0xFFFF, 0xFFFF, false) / 2), HEIGHT_OFFSET + 14 + i * 18, 0x0000, 0xFFFF, false);
    }

    draw_arrow(68, HEIGHT_OFFSET + 14, 0x0000);

    while (isInLoop == 0){
        if (extapp_isKeydown(KEY_CTRL_EXIT)) {
            isInLoop = 1;
        }

        if (exit_app() == 1) {
            return;
        }
        extapp_msleep(200);

        // Navigate through the menu
        if (extapp_isKeydown(KEY_CTRL_UP) && selected_file > 0){
            draw_arrow(68, HEIGHT_OFFSET + 14 + selected_file * 18, 0xFFFF);
            selected_file -= 1;
            draw_arrow(68, HEIGHT_OFFSET + 14 + selected_file * 18, 0x0000);
        }
        if (extapp_isKeydown(KEY_CTRL_DOWN) && selected_file < num_files - 1){
            draw_arrow(68, HEIGHT_OFFSET + 14 + selected_file * 18, 0xFFFF);
            selected_file += 1;
            draw_arrow(68, HEIGHT_OFFSET + 14 + selected_file * 18, 0x0000);
        }

        // Open the selected file
        if (extapp_isKeydown(KEY_CTRL_OK)) {
            draw_image(WIDTH_OFFSET, HEIGHT_OFFSET, filenames[selected_file]);
            isInLoop = 1;
            Drawing(0);
        }
    }
}
