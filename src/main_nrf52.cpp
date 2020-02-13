#ifdef EMBEDDED

#include <Arduino.h>
#include <graphics.h>

Graphics display();

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("hi");
  delay(200);
}

#endif
