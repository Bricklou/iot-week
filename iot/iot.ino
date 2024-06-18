#include "sensors/light_sensor.h"
#include "communication/serial_com.h"
#include "communication/screen.h"
#include "communication/buzzer.h"
#include "sensors/proximity.h"
#include "sensors/air_quality.h"
#include "communication/led.h"
#include "sensors/button.h"

bool toggle = false;

void setup() {
  // Initialize ESP32 communication
  configure_serial_com();

  configure_buzzer();
  configure_button();

  // Initialize OLED screen
  configure_screen();

  configure_proximity_sensor();
  configure_led();
  if (!configure_air_quality_sensor()) {
    reset_screen();
    display.println("Air sensor ERROR!");
    display.display();

    while(true) {}
  }
}

void loop() {
  reset_screen();
  
  int quality = read_air_quality();
  bool state = air_quality_polluted();
  int value = read_air_quality_value();

  if (state) {
    display.print("Polluted! ");
  } else {
    display.print("Ok! ");
  }
  display.print(value);
  display.print(" ");
  display.println(quality);

  if (is_button1_pressed()) {
    display.println("pressed");
  } else {
    display.println("not pressed");
  }
  display.display();

  if (toggle) {
    led_on();
  } else {
    led_off();
  }
  toggle = !toggle;
}