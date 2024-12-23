#pragma once
#include<Arduino.h>
#include"TinyGPS++.h"

class Gps {
    public:
        int speed;
        double latitude;
        double longitude;
        int satelites;
        int hdop;
        TinyGPSPlus gps;
        
        Gps() {};
        void init(int TxPin, int RxPin, unsigned long baud);
        bool getData();


    private:
        unsigned long baud;
        int TxPin;
        int RxPin;

};