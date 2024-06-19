#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON1_PIN 2
#define BUTTON2_PIN 3

#define BTN_LOW HIGH
#define BTN_HIGH LOW

bool last_button1_state = BTN_LOW;
bool last_button2_state = BTN_LOW;
bool button1_state = BTN_LOW;
bool button2_state = BTN_LOW;

void configure_button() {
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
}

void update_buttons() {
  last_button1_state = button1_state;
  last_button2_state = button2_state;
  button1_state = digitalRead(BUTTON1_PIN);
  button2_state = digitalRead(BUTTON2_PIN);
}

bool is_button1_pressed() {
  return button1_state == BTN_HIGH;
}

bool is_button1_released() {
  return button1_state == BTN_LOW && last_button1_state == BTN_HIGH;
}

bool is_button2_pressed() {
    return button2_state == BTN_HIGH;
}

bool is_button2_released() {
  return button2_state == BTN_LOW && last_button2_state == BTN_HIGH;
}

#endif