#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "extapp_api.h"

#include "inc/peripherals.h"
#include "inc/screens.h"

void extapp_main(void) {
    int y_tutorial = 0;
    blank_page(0x7D19);
    Tutorial(1, 0);
    while (true) {
        while (true) {
            extapp_msleep(100);
            if (extapp_isKeydown(KEY_CTRL_UP)) {
                y_tutorial -= 1;
                if (y_tutorial < 0) y_tutorial = 0;
                Tutorial(y_tutorial, y_tutorial + 1);
            }
            if (extapp_isKeydown(KEY_CTRL_DOWN)) {
                y_tutorial += 1;
                if (y_tutorial > 4) y_tutorial = 4;
                Tutorial(y_tutorial, y_tutorial - 1);
            }
            if (extapp_isKeydown(KEY_CTRL_HOME)) {
                return;
            }
        }
    }
}