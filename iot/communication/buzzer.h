#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_PIN 4


void buzzer_off() {
  noTone(BUZZER_PIN);
}

void buzzer_tone(int frequency) {
    tone(BUZZER_PIN, frequency);
}

void configure_buzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  buzzer_off();
}

void buzzer_tone(int frequency, int duration) {
    tone(BUZZER_PIN, frequency, duration);
}

#endif