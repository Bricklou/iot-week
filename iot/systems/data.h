#ifndef DATA_H
#define DATA_H

unsigned long last_sent = 0;

void send_data() {
    if (millis() - last_sent > 5000/20) {
        return;
    }
    last_sent = millis();
}

#endif