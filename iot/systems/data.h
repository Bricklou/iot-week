#ifndef DATA_H
#define DATA_H

#include "proximity.h"
#include "light.h"
#include "air_quality.h"

unsigned long last_sent = 0;

void send_data() {
    if (millis() - last_sent > 30000/20) {
        return;
    }
    last_sent = millis();

    Serial.print(last_light_intensity);
    Serial.print(" ");
    Serial.println(last_air_quality);
}

#endif