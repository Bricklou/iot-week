#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

#include "../sensors/light_sensor.h"
#include "alert.h"

#define LIGHT_THRESHOLD 40

void check_light() {
    int intensity = read_light_sensor();

    if (intensity < LIGHT_THRESHOLD) {
        alert_t alert{
            .message = "Lumiere trop faible.",
            .type = alert_type_light
        };
        emit_alert(alert);
    }
}

#endif