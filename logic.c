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
    Refresh();
}

