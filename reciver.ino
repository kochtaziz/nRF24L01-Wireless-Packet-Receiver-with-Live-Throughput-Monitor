#include <SPI.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

const byte address[5] = {'J','U','N','K','1'};  // Must match transmitter
int packetCount = 0;
unsigned long lastReport = 0;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(100);            // Must match transmitter
  radio.setPALevel(RF24_PA_LOW);    // Low power (optional)
  radio.setDataRate(RF24_2MBPS);    // Must match transmitter
  radio.openReadingPipe(1, address);
  radio.startListening();
  Serial.println("Listening for packets...");
}

void loop() {
  if (radio.available()) {
    char payload[32] = "";
    radio.read(&payload, sizeof(payload));
    packetCount++;
  }

  // Report packets received every second
  if (millis() - lastReport >= 1000) {
    Serial.print("Packets/sec: ");
    Serial.println(packetCount);
    packetCount = 0;
    lastReport = millis();
  }
}
