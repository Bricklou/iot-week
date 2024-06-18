#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#define LIGHT_SENSOR_PIN A0

int read_light_sensor() {
    int value = analogRead(LIGHT_SENSOR_PIN);
    value = map(value, 0, 805, 0, 100);
    value = constrain(value, 0, 100);
    return value;
}

#endif