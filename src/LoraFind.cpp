#include"SendSignal\SendSignal.h"
#include"FoundSignal\FoundSignal.h"
#include "HardwareSerial.h"

#define SELECTOR 34
#define FREQUENCIE 433E6
#define SS 18
#define RESET -1
#define DI0 18
#define SCL 22
#define MISO 19
#define MOSI 23
#define GPSTX 17
#define GPSRX 16
bool gpsEnable = true;

//Cria os objetos transmissor e emissor
FoundSignal foundSignal(FREQUENCIE, SS, RESET, DI0);
SendSignal sendSignal(FREQUENCIE, SS, RESET, DI0, gpsEnable, GPSTX, GPSRX, 9600);
//Cria UART
HardwareSerial SerialGps(1); //Ativa a UART 1

//Declaração das funções
bool selectorChange(int);




void setup() {
    pinMode(SELECTOR, INPUT_PULLUP);
    Serial.begin(115200);
    if(sendSignal.gps) {
        SerialGps.begin(sendSignal.getBaud(),SERIAL_8N1, sendSignal.getTx(), sendSignal.getRx());
    }
}

void loop() {
    bool txMode = true;
    delay(5000);
    Serial.print("Decice config: ");
    bool deviceSelected = false;
    selectorChange(SELECTOR) ? txMode = false : txMode = true;

    while(txMode) {
        if(!deviceSelected) {
            Serial.println("Tansmitter");
            deviceSelected = true;
        }



        selectorChange(SELECTOR) ? ESP.restart() : void();
    }

    while(!txMode) {
        if(!deviceSelected) {
            Serial.println("Receiver");
            deviceSelected = true;
        }





        selectorChange(SELECTOR) ? ESP.restart() : void();
    }
}


bool selectorChange(int selector){
    bool change;
    digitalRead(selector) == 0 ? change = true : change = false;
    return change;
}