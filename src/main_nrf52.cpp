#ifdef EMBEDDED

#include <Arduino.h>
#include <graphics.h>
#include <rtc.h>
#include <Fonts/FreeMonoBold18pt7b.h>

#include <nrf.h>
#include <nordic/nrfx/hal/nrf_comp.h>
#include <nordic/nrfx/hal/nrf_lpcomp.h>
#include <nordic/nrfx/mdk/nrf52840.h>

#define PIN_EXTCOMIN 30


//#define NRF52_ONRAM1_OFFRAM0    POWER_RAM_POWER_S0POWER_Off      << POWER_RAM_POWER_S0POWER_Pos      \
//  | POWER_RAM_POWER_S1POWER_Off      << POWER_RAM_POWER_S1POWER_Pos      \
//  | POWER_RAM_POWER_S0RETENTION_Off << POWER_RAM_POWER_S0RETENTION_Pos  \
//  | POWER_RAM_POWER_S1RETENTION_Off << POWER_RAM_POWER_S1RETENTION_Pos;

Graphics display;

SoftwareTimer t, t2;

void extcomin(void* unused) {
  (void) unused;
  digitalToggle(PIN_EXTCOMIN);
}


int x;

void incx(void* unused) {
  x++;
}

void redraw(void* unused) {
  display.clearDisplay();
  display.setCursor(100, 100);
  display.setTextColor(0);
  display.print(x);
  display.setTextColor(1);
  display.print(x);
  display.refresh();
}


void setup() {
  //nrf_comp_disable();
  //nrf_lpcomp_disable();
  //NRF_TWI0->ENABLE = 0;
  //NRF_TWI1->ENABLE = 0;
  //NRF_SPI0->ENABLE = 0;
  //NRF_SPI1->ENABLE = 0;

  //NRF_POWER->DCDCEN = 1;

  //NRF_POWER->SYSTEMOFF = 1;

  pinMode(PIN_EXTCOMIN, OUTPUT);
  display.begin();
  display.setFont(&FreeMonoBold18pt7b);
  //display.setRotation(0);
  display.clearDisplay();
  display.refresh();
  //t.begin(1000, extcomin);
  //t.start();
  //t.begin(500, incx);
  //t.start();
  //t2.begin(2000, redraw);
  //t2.start();


  x = 0;

  while(true) {
    display.fillScreen(0);
    display.refresh();
    digitalToggle(PIN_EXTCOMIN);
    delay(1000);
    display.fillScreen(1);
    display.refresh();
    digitalToggle(PIN_EXTCOMIN);
    delay(1000);
  }

  for (int a = 0; a < SCREEN_WIDTH; a++) {
    for (int b = 0; b < SCREEN_HEIGHT; b++) {
      display.drawPixel(a, b, 0);
      delay(1);
      display.refresh();
      //display.clearDisplay();
    }
  }
  suspendLoop();
}

void loop() {
  Serial.println("hi");
  delay(200);
}

#endif
