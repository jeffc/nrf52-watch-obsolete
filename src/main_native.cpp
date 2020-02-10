#ifdef NATIVE

#include <iostream>
#include <Adafruit_GFX_dummy_display.h>
#include "logging.h"

#define DISP_WIDTH 128
#define DISP_HEIGHT 128
#define ZOOM 10

Adafruit_GFX_dummy_display display(DISP_WIDTH, DISP_HEIGHT, ZOOM);

int main() {
  int running = 1;
  /* Calling Arduino like setup() */
  display.setTextColor(1);
  display.print("Display Test");
  display.display();
  LOG_INFO("Test logging");
  while(running)
  {
    SDL_Event event;
    if ( SDL_PollEvent(&event) == 1 )
    {
      switch (event.type)
      {
        case SDL_QUIT:
          running = 0;
          break;
        default:
          /* running */
          break;
      }
    }
  }
  return 0;
}

#endif
