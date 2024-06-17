#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#define RXPIN 16
#define TXPIN 17
const char *ssid = "Coworking";          // Change this to your WiFi SSID
const char *password = "C0w0rking!";  // Change this to your WiFi password

void setup() {
  Serial2.begin(115200,SERIAL_8N1,RXPIN,TXPIN);
  while (!Serial2) {
    delay(100);
  }

  // We start by connecting to a WiFi network


  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial2.println("WiFi connected");
  Serial2.println("IP address: ");
  Serial2.println(WiFi.localIP());
}

void loop() {}