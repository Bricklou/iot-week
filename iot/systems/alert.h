#ifndef ALERT_H
#define ALERT_H

#include "../communication/screen.h"
#include "../communication/led.h"
#include "../communication/buzzer.h"

enum alert_type_t {
    alert_type_none,
    alert_type_air_quality,
    alert_type_presence,
    alert_type_light
};

struct alert_t {
    const char* message;
    alert_type_t type;
};

alert_t _current_alert {.message="", .type = alert_type_none };

unsigned int sequence_index = 0;
#define SEQUENCE_SIZE 4
bool led_state = false;

void emit_alert(alert_t alert) {
    if (_current_alert.type == alert.type) {
        return;
    }
    _current_alert = alert;
    sequence_index = 0;
    print_screen(alert.message);

    led_on();
}

void clear_alert() {
    Serial.println("alert cleared");
    _current_alert = alert_t {.message="", .type = alert_type_none };
    reset_screen();
    display.display();
    led_off();
}

unsigned long last_led_update = 0;
void update_alert() {
    if (_current_alert.type == alert_type_none) { return; }
    if (millis() - last_led_update < 150) { return; }

    if (sequence_index < SEQUENCE_SIZE) {
        buzzer_tone(500, 30);
        sequence_index ++;
    }
    
    if (led_state) {
        led_on();
    } else {
        led_off();
    }
    led_state =!led_state;

    last_led_update = millis();
}

#endif