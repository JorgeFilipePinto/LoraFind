#pragma once
#include<Arduino.h>
#include<Lora\Lora.h>
#include<SPI.h>


class FoundSignal{
    public:
        int tempRSSI;
        int count = 0;
        int lastRssi = 0;
        int newRssi = 0;
        bool signal = false;
        bool lostSignal = true;
        unsigned long lastMessage = millis();
        String response;
        String values;
        Lora lora;
        FoundSignal() = default;   
        double getDistanceRssi(double, int);
        void FoundMessage();

        
    private:

};