#pragma once
#include<Arduino.h>
#include<Lora\Lora.h>
#include<SPI.h>


class FoundSignal{
    public:
        bool signal = false;
        unsigned long lastMessage = millis();
        String response;
        Lora lora;
        FoundSignal() = default;   
        double getDistanceRssi(double, int);
        void FoundMessage();

        
    private:

};