#ifndef SCREEN_H
#define SCREEN_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void configure_screen() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();
}

void reset_screen() {
    display.clearDisplay();
    display.setCursor(0, 0);
}

#endif