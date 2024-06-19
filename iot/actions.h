#ifndef ACTIONS_H
#define ACTIONS_H

#include "sensors/air_quality.h"
#include "sensors/light_sensor.h"
#include "sensors/proximity.h"
#include "sensors/button.h"
#include "systems/alert.h"
#include "systems/proximity.h"

int air_quality = 0;
int light_intensity = 0;
bool is_present = false;

void when_button1_pressed() {
    if (_current_alert.type == alert_type_none) {
        return;
    }

    if (_current_alert.type == alert_type_presence) {
        reset_accumulated_presence();
    }

    clear_alert();
}

#endif