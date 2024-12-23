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

    Lora(){};

    bool init(int ss, int rst, int scl, int di, int frequencie, int ledPinTX, int ledPinRX, int ledPinError);
    bool sendMessage();
    bool getMessage();
    void setPower();
    void setLedTx();
    void setLedRx();
    void setLedError();

    private:
        int ledPinRX;
        int ledPinTX;
        int ledPinError;
        int frequencie; 
        int ss;
        int rst;
        int scl;
        int di;

};
