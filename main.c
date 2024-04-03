#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "extapp_api.h"

#include "inc/peripherals.h"
#include "inc/screens.h"
#include "inc/logic.h"

//variable to know the current screen
int current_screen = 0; // "Option" = 0, "Drawing" = 1, "Files" = 2, "Tutorial" = 3, "About" = 4


void extapp_main(void) {
    int Option = 0; // 0 = New Drawing, 1 = Open Files, 2 = Tutorial, 3 = About, 4 = Quit
    blank_page(0x0E88);
    optionScreen(Option, 1, 1);
    extapp_msleep(200);
    while (true) {
        extapp_msleep(200);
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
            Drawing(1);
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

