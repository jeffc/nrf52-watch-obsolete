#ifdef NATIVE

#include <iostream>
#include <cstdio>
#include <rtc.h>
#include <graphics.h>
#include "logging.h"

#include <fonts/SevenSegment36pt.h>

Graphics display;
RTC rtc;

int main() {
  int running = 1;
  /* Calling Arduino like setup() */
  display.setTextColor(1);
  char buf[256] = {'\0'};
  DateTime t = rtc.getTime();
  snprintf(buf, 256, "%02d:%02d:%02d", t.hours, t.minutes, t.seconds);
  display.setFont(&Seven_Segment36pt7b);
  display.setCursor(0, 60);
  display.print(buf);
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
