#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_PIN 8


void configure_buzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, 0);
}

#endif