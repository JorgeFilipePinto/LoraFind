#include"FoundSignal.h"



double FoundSignal::getDistanceRssi(double avgValues, int rssi) {
    double distance;
    //Math.pow(10.0, ((Math.abs(this) - Math.abs(txPower)) / (10 * 2)).toDouble())
    
    return distance;
};


void FoundSignal::FoundMessage() {
    if(lora.getMessage()) {
        tempRSSI += lora.rssi;
        Serial.println(lora.response);
        lastMessage = millis();
        signal = true;
        lostSignal = false;
        count++;
        if(count == 4) {
            count = 0;
            lastRssi = newRssi;
            newRssi = tempRSSI/4;
            tempRSSI = 0;
            values = "last RSSI: " + String(lastRssi);
            values += "\nnew RSSI: " + String(newRssi);
        }
        response = lora.response;
    }
};
