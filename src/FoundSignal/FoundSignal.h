#pragma once
#include<Arduino.h>
#include<Lora\Lora.h>
#include<SPI.h>


class FoundSignal{
    public:
        String response;
        Lora lora;

        FoundSignal(int frequencie, int ss, int reset, int di0) {
            this-> frequencie = frequencie;
            this->ss = ss;
            this->reset = reset;
            this->di0 = di0;
            LoRa.begin(this -> frequencie);
            if(lora.init(ss, reset, scl, di0, frequencie, 14, 12, 27)) {
                lora.setLedRx();
            } else {
                lora.setLedError();
            }
        };

        double getDistanceRssi(double, int);
        void FoundGpsMessage();
        String FoundMessage();

        
    private:
        int frequencie;
        int ss;
        int scl;
        int reset;
        int di0;

};