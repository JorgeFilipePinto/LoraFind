#include"Lora\Lora.h"


void Lora::init(){

    SPI.begin(5, 19, 27, 18);
    Serial.println("SPI set pins!");
    LoRa.setPins(18,23,26);
    Serial.println("LoRa set pins!");
    if (!LoRa.begin(868E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
};


void Lora::sendMessage() {
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("Lora send message!!");
};

bool Lora::getMessage() {
  packetSize = LoRa.parsePacket();
  String message = "";
  if (packetSize) {
    while(LoRa.available()) {
      char text = LoRa.read();
      message += text;
    }
    rssi = LoRa.rssi();
    response = message;
    return true;
  } else { return false;}
};



void Lora::setPower() {

};