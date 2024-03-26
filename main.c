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
int current_screen = 0; // "Option" = 0, "Drawing" = 1, "Files" = 2, , "Tutorial" = 3 "About" = 4

int exit_app() {
    if (extapp_isKeydown(KEY_CTRL_HOME)) {
        return 1;
    }
    return 0;
}

void extapp_main(void) {
    int Option = 0; // 0 = New Drawing, 1 = Open Files, 2 = Tutorial, 3 = About, 4 = Quit
    blank_page(color_1);
    optionScreen(Option, 1, 1);
    extapp_msleep(500);
    while (true) {
        if (exit_app() == 1) {
            return;
        }
        while (true) {
            if (exit_app() == 1) {
                return;
            }

            if (extapp_isKeydown(KEY_CTRL_OK) || extapp_isKeydown(52)){
                break;
            }

            extapp_msleep(200);
            if (extapp_isKeydown(KEY_CTRL_UP)) {
                Option -= 1;
                if (Option < 0) Option = 0;
                optionScreen(Option, Option + 1, 0);
            }

            else if (extapp_isKeydown(KEY_CTRL_DOWN)) {
                Option += 1;
                if (Option > 4) Option = 4;
                optionScreen(Option, Option - 1, 0);
            }
        }
        if (Option == 0){
            // New Drawing
            Drawing();
        }

        if (Option == 1){
            // Open Files
            Files();
        }

        if (Option == 2) {
            // Tutorial
            current_screen = Tutorial();
            extapp_msleep(500);
            while (current_screen == 3) {
                if (exit_app() == 1) {
                    break;
                }
                if (extapp_isKeydown(KEY_CTRL_OK) ||
                    extapp_isKeydown(52)) {
                    current_screen = 0;
                }
            }
            if (current_screen == 0) {
                // Display option menu again

                optionScreen(Option, Option + 1, 1);
            }
            extapp_msleep(500);
        }

        if (Option == 3){
            // Tutorial
            current_screen = About();
            extapp_msleep(500);
            while (current_screen == 4) {
                if (exit_app() == 1) {
                    break;
                }
                if (extapp_isKeydown(KEY_CTRL_OK) ||
                    extapp_isKeydown(52)) {
                    current_screen = 0;
                }
            }
            if (current_screen == 0) {
                // Display option menu again

                optionScreen(Option, Option + 1, 1);
            }
            extapp_msleep(500);
        }

        if (Option == 4){
            // Quit
            return;
        }

    }
}

