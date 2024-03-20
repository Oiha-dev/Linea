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
    extapp_pushRectUniform(7, 46, 20, 20, color);
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
}