#include "inc/screens.h"
#include "extapp_api.h"
#include <string.h>

void Header() {
  //The Header is the band at the top of the screen with the logo and the battery indicator
    extapp_pushRectUniform(0, 0, 320, 30, 0x7D19);
    extapp_pushRectUniform(4, 4, 54, 18, 0xFFFF);
    extapp_pushRectUniform(4, 22, 54, 2, 0xDF3E);
    extapp_pushRectUniform(8, 4, 10, 16, 0x7D19);
    extapp_pushRectUniform(16, 20, 2, 4, 0x7D19);
    extapp_pushRectUniform(18, 8, 4, 2, 0x7D19);
    extapp_pushRectUniform(22, 4, 36, 6, 0x7D19);
    extapp_pushRectUniform(22, 10, 2, 14, 0x7D19);
    extapp_pushRectUniform(28, 14, 2, 10, 0x7D19);
    extapp_pushRectUniform(34, 10, 2, 14, 0x7D19);
    extapp_pushRectUniform(28, 14, 2, 10, 0x7D19);
    extapp_pushRectUniform(40, 14, 2, 2, 0x7D19);
    extapp_pushRectUniform(40, 18, 6, 2, 0x7D19);
    extapp_pushRectUniform(46, 10, 2, 14, 0x7D19);
    extapp_pushRectUniform(48, 14, 6, 2, 0x7D19);
    extapp_pushRectUniform(52, 18, 2, 2, 0x7D19);
}

void blank_page(int color) {
    // The blank page that all the other pages are based on
    Header();
    //Buttons
    //Color
    extapp_pushRectUniform(0, 30, 320, 210, 0xC6FF);
    extapp_pushRectUniform(33, 42, 271, 189, 0xFFFF);
    extapp_pushRectUniform(6, 45, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 46, 19, 19, color);
    //Pen
    extapp_pushRectUniform(6, 72, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 73, 19, 19, 0xFFFF);
    extapp_pushRectUniform(17, 75, 3, 1, 0x7D19);
    extapp_pushRectUniform(16, 76, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 77, 1, 1, 0x7D19);
    extapp_pushRectUniform(14, 78, 1, 1, 0x7D19);
    extapp_pushRectUniform(13, 79, 1, 1, 0x7D19);
    extapp_pushRectUniform(12, 80, 1, 1, 0x7D19);
    extapp_pushRectUniform(11, 81, 1, 1, 0x7D19);
    extapp_pushRectUniform(10, 82, 1, 1, 0x7D19);
    extapp_pushRectUniform(9, 83, 4, 1, 0x7D19);
    extapp_pushRectUniform(9, 83, 1, 7, 0x7D19);
    extapp_pushRectUniform(10, 86, 2, 1, 0x7D19);
    extapp_pushRectUniform(12, 87, 1, 2, 0x7D19);
    extapp_pushRectUniform(9, 89, 7, 1, 0x7D19);
    extapp_pushRectUniform(13, 84, 1, 1, 0x7D19);
    extapp_pushRectUniform(14, 85, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 86, 1, 3, 0x7D19);
    extapp_pushRectUniform(20, 76, 1, 1, 0x7D19);
    extapp_pushRectUniform(21, 77, 1, 1, 0x7D19);
    extapp_pushRectUniform(22, 78, 1, 1, 0x7D19);
    extapp_pushRectUniform(23, 79, 1, 3, 0x7D19);
    extapp_pushRectUniform(20, 78, 1, 1, 0x7D19);
    extapp_pushRectUniform(19, 79, 1, 1, 0x7D19);
    extapp_pushRectUniform(18, 80, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 81, 1, 1, 0x7D19);
    extapp_pushRectUniform(16, 82, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 83, 1, 1, 0x7D19);
    extapp_pushRectUniform(21, 79, 1, 2, 0x7D19);
    extapp_pushRectUniform(20, 80, 1, 2, 0x7D19);
    extapp_pushRectUniform(19, 81, 1, 2, 0x7D19);
    extapp_pushRectUniform(18, 82, 1, 2, 0x7D19);
    extapp_pushRectUniform(17, 83, 1, 2, 0x7D19);
    extapp_pushRectUniform(16, 84, 1, 2, 0x7D19);
    extapp_pushRectUniform(22, 82, 1, 1, 0x7D19);
    extapp_pushRectUniform(21, 83, 1, 1, 0x7D19);
    extapp_pushRectUniform(20, 84, 1, 1, 0x7D19);
    extapp_pushRectUniform(19, 85, 1, 1, 0x7D19);
    extapp_pushRectUniform(18, 86, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 87, 1, 1, 0x7D19);
    extapp_pushRectUniform(16, 88, 1, 1, 0x7D19);

    //Eraser
    extapp_pushRectUniform(6, 99, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 100, 19, 19, 0xFFFF);
    extapp_pushRectUniform(16, 102, 4, 1, 0x7D19);
    extapp_pushRectUniform(15, 103, 1, 1, 0x7D19);
    extapp_pushRectUniform(14, 104, 1, 1, 0x7D19);
    extapp_pushRectUniform(13, 105, 1, 1, 0x7D19);
    extapp_pushRectUniform(12, 106, 1, 1, 0x7D19);
    extapp_pushRectUniform(11, 107, 1, 1, 0x7D19);
    extapp_pushRectUniform(10, 108, 1, 1, 0x7D19);
    extapp_pushRectUniform(9, 109, 1, 5, 0x7D19);
    extapp_pushRectUniform(10, 114, 1, 1, 0x7D19);
    extapp_pushRectUniform(11, 115, 1, 1, 0x7D19);
    extapp_pushRectUniform(12, 116, 5, 1, 0x7D19);
    extapp_pushRectUniform(17, 115, 1, 1, 0x7D19);
    extapp_pushRectUniform(18, 110, 1, 5, 0x7D19);
    extapp_pushRectUniform(19, 113, 1, 1, 0x7D19);
    extapp_pushRectUniform(20, 112, 1, 1, 0x7D19);
    extapp_pushRectUniform(21, 110, 1, 2, 0x7D19);
    extapp_pushRectUniform(22, 110, 1, 1, 0x7D19);
    extapp_pushRectUniform(23, 106, 1, 4, 0x7D19);
    extapp_pushRectUniform(20, 103, 1, 1, 0x7D19);
    extapp_pushRectUniform(21, 104, 1, 1, 0x7D19);
    extapp_pushRectUniform(22, 105, 1, 2, 0x7D19);
    extapp_pushRectUniform(21, 107, 1, 1, 0x7D19);
    extapp_pushRectUniform(20, 108, 1, 2, 0x7D19);
    extapp_pushRectUniform(19, 109, 1, 2, 0x7D19);
    extapp_pushRectUniform(17, 111, 1, 1, 0x7D19);
    extapp_pushRectUniform(16, 112, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 113, 1, 1, 0x7D19);
    extapp_pushRectUniform(14, 114, 1, 2, 0x7D19);
    extapp_pushRectUniform(12, 114, 3, 1, 0x7D19);
    extapp_pushRectUniform(16, 104, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 105, 1, 1, 0x7D19);
    extapp_pushRectUniform(18, 106, 1, 1, 0x7D19);
    extapp_pushRectUniform(19, 107, 1, 1, 0x7D19);
    extapp_pushRectUniform(13, 107, 1, 1, 0x7D19);
    extapp_pushRectUniform(14, 108, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 109, 1, 1, 0x7D19);
    extapp_pushRectUniform(16, 110, 1, 1, 0x7D19);

    //Shapes
    extapp_pushRectUniform(6, 126, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 127, 19, 19, 0xFFFF);
    extapp_pushRectUniform(12, 128, 5, 1, 0x7D19);
    extapp_pushRectUniform(11, 129, 1, 1, 0x7D19);
    extapp_pushRectUniform(10, 130, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 129, 1, 1, 0x7D19);
    extapp_pushRectUniform(18, 130, 1, 1, 0x7D19);
    extapp_pushRectUniform(9, 131, 1, 5, 0x7D19);
    extapp_pushRectUniform(19, 131, 1, 5, 0x7D19);
    extapp_pushRectUniform(10, 136, 1, 1, 0x7D19);
    extapp_pushRectUniform(18, 136, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 137, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 133, 9, 1, 0x7D19);
    extapp_pushRectUniform(15, 134, 1, 7, 0x7D19);
    extapp_pushRectUniform(15, 140, 9, 1, 0x7D19);
    extapp_pushRectUniform(23, 134, 1, 7, 0x7D19);
    extapp_pushRectUniform(11, 133, 1, 11, 0x7D19);
    extapp_pushRectUniform(12, 134, 1, 1, 0x7D19);
    extapp_pushRectUniform(13, 135, 1, 1, 0x7D19);
    extapp_pushRectUniform(14, 136, 1, 1, 0x7D19);
    extapp_pushRectUniform(16, 138, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 139, 1, 1, 0x7D19);
    extapp_pushRectUniform(19, 141, 1, 1, 0x7D19);
    extapp_pushRectUniform(20, 142, 1, 1, 0x7D19);
    extapp_pushRectUniform(12, 138, 3, 1, 0x7D19);
    extapp_pushRectUniform(12, 143, 10, 1, 0x7D19);

    //Select
    extapp_pushRectUniform(6, 153, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 154, 19, 19, 0xFFFF);
    extapp_pushRectUniform(9, 156, 15, 15, 0x7D19);
    extapp_pushRectUniform(12, 159, 9, 9, 0xFFFF);
    extapp_pushRectUniform(10, 157, 1, 2, 0xFFFF);
    extapp_pushRectUniform(10, 157, 2, 1, 0xFFFF);
    extapp_pushRectUniform(13, 157, 1, 1, 0xFFFF);
    extapp_pushRectUniform(15, 157, 1, 1, 0xFFFF);
    extapp_pushRectUniform(17, 157, 1, 1, 0xFFFF);
    extapp_pushRectUniform(19, 157, 1, 1, 0xFFFF);
    extapp_pushRectUniform(21, 157, 2, 1, 0xFFFF);
    extapp_pushRectUniform(22, 158, 1, 1, 0xFFFF);
    extapp_pushRectUniform(22, 160, 1, 1, 0xFFFF);
    extapp_pushRectUniform(22, 162, 1, 1, 0xFFFF);
    extapp_pushRectUniform(22, 164, 1, 1, 0xFFFF);
    extapp_pushRectUniform(22, 166, 1, 1, 0xFFFF);
    extapp_pushRectUniform(22, 168, 1, 2, 0xFFFF);
    extapp_pushRectUniform(21, 169, 1, 1, 0xFFFF);
    extapp_pushRectUniform(19, 169, 1, 1, 0xFFFF);
    extapp_pushRectUniform(17, 169, 1, 1, 0xFFFF);
    extapp_pushRectUniform(15, 169, 1, 1, 0xFFFF);
    extapp_pushRectUniform(13, 169, 1, 1, 0xFFFF);
    extapp_pushRectUniform(10, 169, 2, 1, 0xFFFF);
    extapp_pushRectUniform(10, 168, 1, 1, 0xFFFF);
    extapp_pushRectUniform(10, 166, 1, 1, 0xFFFF);
    extapp_pushRectUniform(10, 164, 1, 1, 0xFFFF);
    extapp_pushRectUniform(10, 162, 1, 1, 0xFFFF);
    extapp_pushRectUniform(10, 160, 1, 1, 0xFFFF);

    //Text
    extapp_pushRectUniform(6, 180, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 181, 19, 19, 0xFFFF);
    extapp_pushRectUniform(14, 184, 7, 1, 0x7D19);
    extapp_pushRectUniform(12, 185, 2, 1, 0x7D19);
    extapp_pushRectUniform(11, 186, 1, 3, 0x7D19);
    extapp_pushRectUniform(12, 189, 2, 1, 0x7D19);
    extapp_pushRectUniform(14, 188, 1, 1, 0x7D19);
    extapp_pushRectUniform(15, 189, 1, 6, 0x7D19);
    extapp_pushRectUniform(16, 195, 1, 1, 0x7D19);
    extapp_pushRectUniform(17, 196, 2, 1, 0x7D19);
    extapp_pushRectUniform(21, 185, 1, 2, 0x7D19);
    extapp_pushRectUniform(19, 187, 2, 1, 0x7D19);
    extapp_pushRectUniform(18, 188, 1, 5, 0x7D19);
    extapp_pushRectUniform(19, 192, 1, 4, 0x7D19);

    //Files
    extapp_pushRectUniform(6, 207, 21, 21, 0x7D19);
    extapp_pushRectUniform(7, 208, 19, 19, 0xFFFF);
    extapp_pushRectUniform(10, 210, 10, 1, 0x7D19);
    extapp_pushRectUniform(9, 211, 1, 11, 0x7D19);
    extapp_pushRectUniform(10, 222, 10, 1, 0x7D19);
    extapp_pushRectUniform(20, 211, 1, 11, 0x7D19);
    extapp_pushRectUniform(12, 213, 6, 1, 0x7D19);
    extapp_pushRectUniform(12, 215, 6, 1, 0x7D19);
    extapp_pushRectUniform(12, 217, 6, 1, 0x7D19);
    extapp_pushRectUniform(12, 213, 6, 1, 0x7D19);
    extapp_pushRectUniform(21, 212, 2, 1, 0x7D19);
    extapp_pushRectUniform(23, 213, 1, 11, 0x7D19);
    extapp_pushRectUniform(12, 224, 11, 1, 0x7D19);
    extapp_pushRectUniform(11, 223, 1, 1, 0x7D19);

}

void optionScreen(int Option, int last_option, int first_time) {

    if (first_time == 1) {
        Refresh();
        extapp_drawTextLarge("New Drawing", 107, 72, 0x0000, 0xFFFF, false);
        extapp_drawTextLarge("Open Files", 112, 100, 0x0000, 0xFFFF, false);
        extapp_drawTextLarge("Tutorial", 123, 128, 0x0000, 0xFFFF, false);
        extapp_drawTextLarge("About", 137, 156, 0x0000, 0xFFFF, false);
        extapp_drawTextLarge("Quit", 142, 184, 0x0000, 0xFFFF, false);
    }
    int y;

    //Arrow
    if (Option == 0) {
        y = 74;
    } else if (Option == 1) {
        y = 102;
    } else if (Option == 2) {
        y = 130;
    } else if (Option == 3) {
        y = 158;
    } else if (Option == 4) {
        y = 186;
    }
    extapp_pushRectUniform(0 + 96, 0 + y, 1, 9, 0xC6FF);
    extapp_pushRectUniform(1 + 96, 1 + y, 1, 7, 0xC6FF);
    extapp_pushRectUniform(2 + 96, 2 + y, 1, 5, 0xC6FF);
    extapp_pushRectUniform(3 + 96, 3 + y, 1, 3, 0xC6FF);
    extapp_pushRectUniform(4 + 96, 4 + y, 1, 1, 0xC6FF);

    //Last Arrow
if (last_option == 0) {
        y = 74;
    } else if (last_option == 1) {
        y = 102;
    } else if (last_option == 2) {
        y = 130;
    } else if (last_option == 3) {
        y = 158;
    } else if (last_option == 4) {
        y = 186;
    }
    extapp_pushRectUniform(0 + 96, 0 + y, 1, 9, 0xFFFF);
    extapp_pushRectUniform(1 + 96, 1 + y, 1, 7, 0xFFFF);
    extapp_pushRectUniform(2 + 96, 2 + y, 1, 5, 0xFFFF);
    extapp_pushRectUniform(3 + 96, 3 + y, 1, 3, 0xFFFF);
    extapp_pushRectUniform(4 + 96, 4 + y, 1, 1, 0xFFFF);




}

void Refresh() {
    extapp_pushRectUniform(33, 42, 271, 189, 0xFFFF);
}

int Tutorial() {
    Refresh();
    extapp_drawTextLarge("shift", 40, 46, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("e(x)", 40, 73, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("sin", 40, 100, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("7", 40, 126, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("4", 40, 154, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("1", 40, 182, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("0", 40, 208, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("Tutorial", 130, 46, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("Linea use the keys \nof the left column \nto select tools", 100, 80, 0x0000, 0xFFFF, false);
    return 3;
}

int About() {
    Refresh();
    extapp_drawTextLarge("About", 130, 46, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("Linea is a simple \ndrawing program \nfor the Numworks", 50, 70, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("By Gauthier Cenes (Oiha)", 50, 140, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("A big thank to \nthe Omega/Upsilon\ncommunity", 50, 170, 0x0000, 0xFFFF, false);
    extapp_drawTextLarge("v-dev", 234, 208, 0x0000, 0xFFFF, false);
    return 4;
}