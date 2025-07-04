#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  LoRa.setPins(5, 14, 26); // NSS, RST, DIO0

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check connections.");
    while (1);
  }

  Serial.println("LoRa Receiver OK");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println();
  }
}
