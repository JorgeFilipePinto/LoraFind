#include"FoundSignal.h"



double FoundSignal::getDistanceRssi(double avgValues, int rssi) {
    double distance;
    //Math.pow(10.0, ((Math.abs(this) - Math.abs(txPower)) / (10 * 2)).toDouble())
    
    return distance;
};


void FoundSignal::FoundMessage() {
    if(lora.getMessage()) {
        Serial.println(lora.response);
        response = lora.response;
        lastMessage = millis();
        signal = true;
    }
};
