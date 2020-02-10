#ifdef NATIVE

#include <iostream>
#include <graphics.h>
#include "logging.h"

Graphics display;

int main() {
  int running = 1;
  /* Calling Arduino like setup() */
  display.setTextColor(1);
  display.print("Display Test");
  display.display();
  LOG_DEBUG("Debug logging");
  LOG_INFO("Info %s", "logging");
  LOG_WARN("Warn logging");
  LOG_ERROR("Error logging");
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
