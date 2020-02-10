#ifdef EMBEDDED

#include <graphics.h>
#include "pindefs.h"

Graphics::Graphics() : Adafruit_SharpMem(
    PIN_DISPLAY_CLK,
    PIN_DISPLAY_MOSI,
    PIN_DISPLAY_SS,
    SCREEN_WIDTH, SCREEN_HEIGHT) {
}

#endif
