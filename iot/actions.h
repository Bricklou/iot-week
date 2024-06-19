#ifndef ACTIONS_H
#define ACTIONS_H

#include "sensors/air_quality.h"
#include "sensors/light_sensor.h"
#include "sensors/proximity.h"
#include "sensors/button.h"
#include "systems/alert.h"

int air_quality = 0;
int light_intensity = 0;
bool is_present = false;

void when_button1_pressed() {
    Serial.println("Button 1 pressed");
    if (_current_alert.type == alert_type_none) {
        return;
    }

    clear_alert();
}

#endif