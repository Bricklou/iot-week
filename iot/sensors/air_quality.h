#ifndef AIR_QUALITY_H
#define AIR_QUALITY_H

#include <Air_Quality_Sensor.h>

#define AIR_QUALITY_PIN A1

AirQualitySensor sensor(AIR_QUALITY_PIN);

int last_air_quality = AirQualitySensor::FRESH_AIR;

bool configure_air_quality_sensor() {
    return sensor.init();
}

int read_air_quality() {
    last_air_quality = sensor.slope();
    return sensor.slope();
}

int read_air_quality_value() {
    return sensor.getValue();
}

bool air_quality_polluted() {
    return read_air_quality() < AirQualitySensor::HIGH_POLLUTION;
}

#endif