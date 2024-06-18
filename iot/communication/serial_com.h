#ifndef SERIAL_COM_H
#define SERIAL_COM_H

#include <SoftwareSerial.h>

#define RX_PIN 10
#define TX_PIN 11

SoftwareSerial mySerial(RX_PIN, TX_PIN);

void configure_serial_com() {
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);
  mySerial.begin(115200);
}

#endif