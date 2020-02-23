#ifdef EMBEDDED

#include <Arduino.h>
#include <graphics.h>
#include <rtc.h>
#include <Fonts/FreeMonoBold18pt7b.h>

#define PIN_EXTCOMIN 30

Graphics display;

SoftwareTimer t, t2, t3;

void extcomin(void* unused) {
  (void) unused;
  digitalToggle(PIN_EXTCOMIN);
}


int x;

void incx(void* unused) {
  x++;
}

void redraw(void* unused) {
  display.clearBuffer();
  display.setCursor(100, 100);
  display.setTextColor(0);
  display.print(x);
  display.refresh();
}


void setup() {
  pinMode(PIN_EXTCOMIN, OUTPUT);
  display.begin();
  display.setFont(&FreeMonoBold18pt7b);
  display.setRotation(2);
  display.clearDisplay();
  display.refresh();
  t.begin(1000, extcomin);
  t.start();
  t2.begin(500, incx);
  t2.start();
  t3.begin(2000, redraw);
  t3.start();


  x = 0;

  //for (int a = 0; a < SCREEN_WIDTH; a++) {
  //  for (int b = 0; b < SCREEN_HEIGHT; b++) {
  //    display.drawPixel(a, b, 0);
  //    display.refresh();
  //    //display.clearDisplay();
  //  }
  //}
  suspendLoop();
}

void loop() {
  Serial.println("hi");
  delay(200);
}

#endif
