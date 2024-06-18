#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON1_PIN 6
#define BUTTON2_PIN 7


void configure_buzzer() {
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
}

bool is_button1_pressed() {
    return digitalRead(BUTTON1_PIN);
}

bool is_button2_pressed() {
    return digitalRead(BUTTON2_PIN);
}

#endif