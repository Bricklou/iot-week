#ifndef PROXIMITY_H
#define PROXIMITY_H

#define PROXIMITY_PIN 5

void configure_proximity_sensor() {
    pinMode(PROXIMITY_PIN, INPUT);
}

bool proximity_is_present() {
    return digitalRead(PROXIMITY_PIN);
}

#endif