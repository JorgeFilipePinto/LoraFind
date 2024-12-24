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
    String getMessage();
    void setPower();
    void setLedTx();
    void setLedRx();
    void setLedError();

    private:
        int ledPinRX = -1;
        int ledPinTX = -1;
        int ledPinError = -1;
        int frequencie = -1;
        int ss = -1;
        int rst = -1;
        int scl = -1;
        int di = -1;

};
