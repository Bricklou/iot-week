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
    bool current_presence = proximity_is_present();
    if (current_presence)
    {
      print_screen("Present");
    } else {
      print_screen("Absent");
    }
  }

  update_alert();

  send_data();
  delay(20);
}