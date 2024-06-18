#ifndef AIR_QUALITY_H
#define AIR_QUALITY_H

#include <Air_Quality_Sensor.h>

#define AIR_QUALITY_PIN A1

AirQualitySensor sensor(A1);

int read_air_quality() {
    return sensor.slope();
}

bool air_quality_polluted() {
    return read_air_quality() < AirQualitySensor::HIGH_POLLUTION;
}

#endif