#include <LoRa.h>
#include <SPI.h>

void setup()
{
  Serial.begin(9600);
  LoRa.setPins(5,14,26);
  if (!LoRa.begin(433E6)) { // tần số LoRa (433 MHz)
    Serial.println("LoRa init failed. Check connections.");
    while (1);
  }
  Serial.println("LoRa Sender OK");

}


void loop()
{

  Serial.println("Sending packet...");
  LoRa.beginPacket();
  LoRa.print("Hello LoRa!");
  LoRa.endPacket();

}