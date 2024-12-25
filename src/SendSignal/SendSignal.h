#pragma once
#include"GPS\Gps.h"
#include"Lora\Lora.h"

class SendSignal {
    public:
        bool emergency;
        bool gps;
        String emergencyMessage;
        Gps gpsNeo;
        Lora lora;

        SendSignal(bool gps, int gpsTx, int gpsRx, unsigned long gpsBaud, String emergencyMessage = "SOS") {
            this->emergency = false;
            this->emergencyMessage = emergencyMessage;
            this-> gps = gps;
            this-> gpsRx = gpsRx;
            this-> gpsTx = gpsTx;
            this->gpsBaud = gpsBaud;
            if(gps){gpsNeo.init(gpsTx, gpsRx, gpsBaud);}
            lora.init();
        };

        int getRx();
        int getTx();
        unsigned long getBaud();
        void sendSOS(int, String);
        void sendCoordinates();
        void sendEmergencyContacts();
        void powerSave();

    private:
        unsigned long gpsBaud;
        int gpsTx;
        int gpsRx;

};
