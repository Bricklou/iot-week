#include "sensors/light_sensor.h"
#include "communication/serial_com.h"
#include "communication/screen.h"
#include "communication/buzzer.h"
#include "sensors/proximity.h"
#include "sensors/air_quality.h"

void setup() {
  // Initialize ESP32 communication
  configure_serial_com();

  configure_buzzer();

  // Initialize OLED screen
  configure_screen();

  configure_proximity_sensor();
}

void loop() {
  reset_screen();
  
  bool is_polluted = air_quality_polluted();

  if (is_polluted) {
    display.println("Polluted air!");
  } else {
    display.println("Air Ok!");
  }
  display.display();

  delay(200);
}