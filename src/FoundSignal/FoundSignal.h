#pragma once
#include<Arduino.h>
#include<Lora\Lora.h>
#include<SPI.h>


class FoundSignal{
    public:
        String response;
        Lora lora;
        FoundSignal() = default;   
        double getDistanceRssi(double, int);
        void FoundGpsMessage();
        void FoundMessage();

        
    private:

};