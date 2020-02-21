#ifdef NATIVE

#include <iostream>
#include <cstdio>
#include <rtc.h>
#include <graphics.h>
#include "logging.h"
#include "fonts/bignum.h"

#include <fonts/SevenSegment36pt.h>

Graphics display;
RTC rtc;

void printnum(int x_, int y_, int n, int scale=1) {
  const uint8_t* ch = BIGNUM[n];

  for (int y=0; y<8; y++) {
      uint8_t b = ch[y];
      for (int x=0; x<8; x++) {
        printf("%1d", b&1);
        for (int yy=scale*y; yy < scale*(y+1); yy++) {
          for (int xx=scale*x; xx < scale*(x+1); xx++) {
            display.drawPixel(x_+xx, y_+yy, !!(b&0x80));
          }
        }
        b <<= 1;
      }
    printf("\n");
  }
  printf("\n");
}

int main() {
  int running = 1;
  /* Calling Arduino like setup() */
  display.setTextColor(1);
  char buf[256] = {'\0'};
  DateTime t = rtc.getTime();
  snprintf(buf, 256, "%02d:%02d:%02d", t.hours, t.minutes, t.seconds);
  display.setFont(&Seven_Segment36pt7b);
  display.setCursor(0, 60);
  //display.print(buf);

  int h1 = t.hours / 10;
  int h2 = t.hours % 10;

  int m1 = t.minutes / 10;
  int m2 = t.minutes % 10;

  printnum(20, 20, h1, 4);
  printnum(20+40, 20, h2, 4);
  printnum(20+80, 20, m1, 4);
  printnum(20+120, 20, m2, 4);


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
    display.display();
  }
  return 0;
}

#endif
