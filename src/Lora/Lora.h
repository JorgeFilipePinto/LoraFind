#pragma once
#include<Arduino.h>
#include<LoRa.h>
#include <SPI.h>

class Lora {
    public:
    String message;
    String response;
    int packetSize;
    int rssi;

    void init();
    void sendMessage();
    bool getMessage();
    void setPower();

    private:

};
