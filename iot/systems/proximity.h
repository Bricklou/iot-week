#ifndef PRESENCE_H
#define PRESENCE_H

#include "../sensors/proximity.h"
#include "alert.h"

bool previous_presence_state = false;
unsigned long absence_start = 0;
unsigned long presence_start = 0;
unsigned long presence_accumulated_time = 0;

#define DEBOUNCE_TIME 10000 //5*60*1000
#define TRIGGER_TIME 20000 //2*60*60*1000

void check_presence() {
    bool current_presence = proximity_is_present();
    unsigned long current_time = millis();
  
    // If the person is present
    if (current_presence) {
        // They weren't present before
        if (!previous_presence_state) {
            // Have they went away more than "DEBOUNCE_TIME" milliseconds?
            unsigned long duration = current_time - absence_start;
            if (absence_start != 0 && duration < DEBOUNCE_TIME) {
                // Add the difference
                presence_accumulated_time += duration;
            } else {
                presence_accumulated_time = 0;
            }
        } else {
            // Otherwise, if they were present before, accumulate the time
            presence_accumulated_time += current_time - presence_start;
        }

        presence_start = current_time;
        previous_presence_state = true;
    } else {
        if (previous_presence_state) {
            presence_accumulated_time += current_time - presence_start;
        }
        absence_start = current_time;
        previous_presence_state = false;
    }


    if (presence_accumulated_time > TRIGGER_TIME) {
        // Run the alert process
        alert_t alert{
            .message = "Take a break!",
            .type = alert_type_presence
        };
        emit_alert(alert);
    }
}

void reset_accumulated_presence() {
    presence_accumulated_time = 0;
}

#endif