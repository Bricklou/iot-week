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

void setup()
{
  configure_buzzer();
  configure_screen();
  configure_serial_com();
  configure_led();

  Serial.begin(115200);
  Serial.println("Hello");
}

void loop()
{
  update_buttons();

  if (is_button1_released()) {
    when_button1_pressed();
  }

  check_air_quality();
  check_light();
  /*// Check light intensity
  light_intensity = read_light_sensor();
  if (light_intensity < LIGHT_THRESHOLD)
  {
    // Run the alert process

    return;
  }

  // Check proximity

  bool current_presence = proximity_is_present();
  if (current_presence)
  {
    // Compare to last presence

    return;
  }

  */

  update_alert();

  send_data();
  delay(20);
}