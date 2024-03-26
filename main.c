#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "extapp_api.h"

#include "inc/peripherals.h"
#include "inc/screens.h"
#include "inc/logic.h"

// TODO: Make a file with all the colors and parameters
int color_1 = 0x0E88;
int color_2 = 0xC7E1;
int color_3 = 0xFBE4;
int color_4 = 0x055E;
int color_5 = 0x0000;
int color_6 = 0xE8E4;
int color_7 = 0x001F;

//variable to know the current screen
char* current_screen = "Option";

int exit_app() {
    if (extapp_isKeydown(KEY_CTRL_HOME)) {
        return 1;
    }
    return 0;
}

void extapp_main(void) {
    int Option = 0; // 0 = New Drawing, 1 = Open Files, 2 = Tutorial, 3 = About, 4 = Quit
    blank_page(color_1);
    optionScreen(Option, 1);
    while (true) {
        if (exit_app() == 1) {
            return;
        }
        while (true) {
            if (exit_app() == 1) {
                return;
            }

            if (extapp_isKeydown(KEY_CTRL_OK) || extapp_isKeydown(KEY_CTRL_EXE)){   //For some reason the EXE key is not working
                break;
            }

            extapp_msleep(200);
            if (extapp_isKeydown(KEY_CTRL_UP)) {
                Option -= 1;
                if (Option < 0) Option = 0;
                optionScreen(Option, Option + 1);
            }

            else if (extapp_isKeydown(KEY_CTRL_DOWN)) {
                Option += 1;
                if (Option > 4) Option = 4;
                optionScreen(Option, Option - 1);
            }
        }
        if (Option == 0){
            // New Drawing
            Drawing();
        }

        else if (Option == 1){
            // Open Files
            Files();
        }

        else if (Option == 2){
            // Tutorial
            strcpy(current_screen, Tutorial());
            while (strcmp(current_screen, "Option") == 0){
                if(exit_app() == 1){
                    break;
                }
                if(extapp_isKeydown(KEY_CTRL_OK) || extapp_isKeydown(KEY_CTRL_EXE || extapp_isKeydown(KEY_CTRL_EXIT))){
                    strcpy(current_screen, "Option");                }
            }
        }

        else if (Option == 3){
            // About
            About();
        }

        else if (Option == 4){
            // Quit
            return;
        }

    }
}

