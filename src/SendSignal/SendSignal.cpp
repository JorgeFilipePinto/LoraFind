#include"SendSignal.h"


int SendSignal::getRx(){
    return gpsRx;
}

int SendSignal::getTx(){
    return gpsTx;
}

unsigned long SendSignal::getBaud(){
    return gpsBaud;
}

void SendSignal::sendSOS(int timePerMessage, String message){
    unsigned long lastTime = millis();
    while(true) {
        unsigned long newTime = millis();
        if((newTime -lastTime) >= timePerMessage) {
            sendCoordinates();
            sendEmergencyContacts();
        }
    }
};

void SendSignal::sendCoordinates() {
    
    if(gpsNeo.getData()) {
        Serial.println("I am lost please search me in these coordinates:");
        Serial.print("Latitude: "); Serial.println(gpsNeo.latitude);
        Serial.print("Longitude: "); Serial.println(gpsNeo.longitude);
        Serial.print("My speed is Kmp/h: "); Serial.println(gpsNeo.speed);
        Serial.print("This message has HDOP value: "); Serial.println(gpsNeo.hdop);
    }
};

void SendSignal::sendEmergencyContacts() {
    Serial.println("Emergency contacts: 91xxxxxxx");
}

void SendSignal::powerSave() {

};