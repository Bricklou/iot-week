#include <SoftwareSerial.h>

#include "sensors/light_sensor.h"
#include "communication/serial_com.h"
#include "communication/screen.h"
#include "communication/buzzer.h"


void setup() {
  // Initialize ESP32 communication
  configure_serial_com();

  configure_buzzer();

  // Initialize OLED screen
  configure_screen();
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("Hello world! ");
  int light = read_light_sensor();
  display.println(light);
  display.display();

  delay(100);
}