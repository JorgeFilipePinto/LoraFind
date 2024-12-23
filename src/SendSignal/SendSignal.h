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

        SendSignal(int frequencie, int ss, int reset, int di0, bool gps, int gpsTx, int gpsRx, unsigned long gpsBaud, String emergencyMessage = "SOS") {
            this->emergency = false;
            this->emergencyMessage = emergencyMessage;
            this-> frequencie = frequencie;
            this->ss = ss;
            this->reset = reset;
            this->di0 = di0;
            this-> gps = gps;
            this-> gpsRx = gpsRx;
            this-> gpsTx = gpsTx;
            this->gpsBaud = gpsBaud;
            if(gps){gpsNeo.init(gpsTx, gpsRx, gpsBaud);}
            if(lora.init(ss, reset, scl, di0, frequencie, 14, 12, 27)) {
                lora.setLedTx();
            } else {
                lora.setLedError();
            }
        };

        int getRx();
        int getTx();
        unsigned long getBaud();
        void sendSOS(int, String);
        void sendCoordinates();
        void sendEmergencyContacts();
        void powerSave();

    private:
        int frequencie;
        int ss;
        int scl;
        int reset;
        int di0;
        unsigned long gpsBaud;
        int gpsTx;
        int gpsRx;

};
