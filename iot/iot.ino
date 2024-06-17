#include <SoftwareSerial.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define rxPin 10
#define txPin 11
#define BUZZER_PIN 8

SoftwareSerial mySerial(rxPin, txPin);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

int counter = 0;

void setup()
{
    // Initialize ESP32 communication
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, 0);

    // Initialize OLED screen
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Hello world!");
    display.display();

    // Initialize USB serial
    Serial.begin(115200);
    // Initialize ESP32 serial
    mySerial.begin(115200);
}

void loop()
{
    while (mySerial.available() > 0) {
        String buffer = mySerial.readStringUntil('\n');
        Serial.print("I received ");
        Serial.println(buffer);
    }

    display.clearDisplay();
    display.setCursor(0, 0);

    display.print("Hello world! ");
    display.println(counter);
    display.display();

    counter++;
    if (counter >= 200)
    {
        counter = 0;
    }
    delay(100);
}