#include"SendSignal\SendSignal.h"
#include"FoundSignal\FoundSignal.h"
#include"Lcd\lcd.h"
#include "HardwareSerial.h"

#define SELECTOR 34
#define FREQUENCIE 868E6
#define SS 18
#define RESET -1
#define DI0 18
#define SCL 22
#define MISO 19
#define MOSI 23
#define GPSTX 17
#define GPSRX 16
bool gpsEnable = false;

//Cria os objetos transmissor e emissor
FoundSignal foundSignal(FREQUENCIE, SS, RESET, DI0);
SendSignal sendSignal(FREQUENCIE, SS, RESET, DI0, gpsEnable, GPSTX, GPSRX, 9600);
//Cria UART
HardwareSerial SerialGps(1); //Ativa a UART 1

Lcd lcd;
//Declaração das funções
bool selectorChange(int);



void setup() {
    pinMode(SELECTOR, INPUT_PULLUP);
    Serial.begin(115200);
    if(sendSignal.gps) {
        SerialGps.begin(sendSignal.getBaud(),SERIAL_8N1, sendSignal.getTx(), sendSignal.getRx());
    }
    lcd.init(128, 64, 21, 22);
}


void loop() {
    bool txMode = false;
    lcd.setMessageDisplay("Welcome", 5, 0, 2);
    delay(5000);
    Serial.print("Decice config: ");
    bool deviceSelected = false;
    //selectorChange(SELECTOR) ? txMode = false : txMode = true;

    while(txMode) {
        lcd.checkMessage("TX Mode", 0, 0, 2);
        //sendSignal.sendEmergencyContacts();

        selectorChange(SELECTOR) ? ESP.restart() : void();
    }

    while(!txMode) {
        lcd.checkMessage("Receiver", 0, 0, 2);

        //foundSignal.FoundMessage();



        selectorChange(SELECTOR) ? ESP.restart() : void();
    }
}


bool selectorChange(int selector){
    bool change;
    digitalRead(selector) == 1 ? change = true : change = false;
    return change;
}