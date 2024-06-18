#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON1_PIN 3
#define BUTTON2_PIN 4


void configure_button() {
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
}

bool is_button1_pressed() {
    return digitalRead(BUTTON1_PIN) == LOW;
}

bool is_button2_pressed() {
    return digitalRead(BUTTON2_PIN) == LOW;
}

#endif