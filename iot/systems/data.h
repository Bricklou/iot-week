#ifndef DATA_H
#define DATA_H

#include "proximity.h"
#include "light.h"
#include "air_quality.h"
#include "../communication/serial_com.h"

unsigned long last_sent = 0;

void send_data() {
    if (millis() - last_sent < 30000/20) {
        return;
    }
    last_sent = millis();

    char buffer[20];
    sprintf(buffer, "%d %d %d %lu %lu", last_light_intensity, last_air_quality, presence_state, presence_accumulated_time/1000, (millis() - absence_start) / 1000);
    Serial.println(buffer);
    mySerial.println(buffer);
    Serial.println("Data sent");
}

#endif