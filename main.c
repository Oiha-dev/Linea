#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "extapp_api.h"

#include "inc/peripherals.h"
#include "inc/screens.h"

void extapp_main(void) {
    blank_page(0x001F);
    while (true) {
        if (extapp_isKeydown(KEY_CTRL_HOME)) {
            return;
        }
    }
}