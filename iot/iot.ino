#include "sensors/light_sensor.h"
#include "communication/serial_com.h"
#include "communication/screen.h"
#include "communication/buzzer.h"
#include "sensors/proximity.h"
#include "sensors/air_quality.h"
#include "communication/led.h"
#include "sensors/button.h"

#include "actions.h"
#include "systems/data.h"
#include "systems/air_quality.h"
#include "systems/light.h"
#include "systems/proximity.h"

void setup()
{
  configure_buzzer();
  configure_screen();
  configure_serial_com();
  configure_led();

  Serial.begin(115200);
}

void loop()
{
  update_buttons();

  if (is_button1_released()) {
    when_button1_pressed();
  }

  check_air_quality();
  check_light();
  check_presence();

  if (_current_alert.type == alert_type_none) {

    reset_screen();
    if (presence_state)
    {
      display.print("Present");
    } else {
      display.print("Absent");
    }
    if (!previous_presence_state) {
      display.print(" (!) ");
      display.println((millis() - presence_start) / 1000);
    }
    display.display();
  }

  update_alert();

  send_data();
  delay(20);
}