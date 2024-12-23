#include"Gps.h"

void Gps::init(int TxPin, int RxPin, unsigned long baud) {
    this->TxPin = TxPin;
    this->RxPin = RxPin;
    this->baud = baud;
    if(Serial) {
        Serial.println("GPS inicialized.");
    }
};

bool Gps::getData() {
    if(gps.satellites.value() > 4) {
        speed = gps.speed.kmph();
        latitude = (gps.location.lat(), 6);
        longitude = (gps.location.lng(), 6);
        satelites = gps.satellites.value();
        hdop = gps.hdop.value();
        return true;
    } else { return false;}
};
