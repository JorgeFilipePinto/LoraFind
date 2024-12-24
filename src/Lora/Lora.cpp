#include"Lora\Lora.h"

void Lora::setLedTx() {
    digitalWrite(ledPinTX, HIGH);
};

void Lora::setLedRx() {
    digitalWrite(ledPinRX, HIGH);
};

void Lora::setLedError() {
    digitalWrite(ledPinError, HIGH);
};


bool Lora::init(int ss, int rst, int scl, int di, int frequencie, int ledPinTX, int ledPinRX, int ledPinError){
    this->ledPinRX = ledPinRX;
    this->ledPinTX = ledPinTX;
    this->ledPinError = ledPinError;
    this->ss = ss;
    this->rst = rst;
    this->scl = scl;
    this->di = di;
    this->frequencie = frequencie;
    pinMode(ledPinTX, OUTPUT);
    pinMode(ledPinRX, OUTPUT);
    pinMode(ledPinError, OUTPUT);
    LoRa.setPins(18,23,26);
    if (!LoRa.begin(frequencie)) {
        Serial.println("Starting LoRa failed!");
        return false;
    } else {return true;}
};


bool Lora::sendMessage() {
    if(message) {
        LoRa.beginPacket();
        LoRa.print(message);
        LoRa.endPacket();
        return true;
    } else {return false;}
    message = "SOS";
};

String Lora::getMessage() {
  packetSize = LoRa.parsePacket();
  if (packetSize) {
    while(LoRa.available()) {
      char text = LoRa.read();
      response += text;
    }
    response = "Emergency Signal: " + response;
  }
  return response;
};

void Lora::setPower() {

};