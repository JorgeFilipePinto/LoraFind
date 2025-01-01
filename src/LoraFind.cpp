#include"SendSignal\SendSignal.h"
#include"FoundSignal\FoundSignal.h"
#include"Lcd\lcd.h"
#include "HardwareSerial.h"

#define SELECTOR 34
#define FREQUENCIE 868E6
#define SS 18
#define RESET 23
#define DI0 26
#define SCL 5
#define MISO 19
#define MOSI 27
#define GPSTX 17
#define GPSRX 16
bool gpsEnable = false;

//Cria os objetos transmissor e emissor
FoundSignal foundSignal;
SendSignal sendSignal(gpsEnable, GPSTX, GPSRX, 9600);
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
    lcd.setMessageDisplay("WELCOME", 20, 30, 2);
    delay(2000);
    bool deviceSelected = false;
    //selectorChange(SELECTOR) ? txMode = false : txMode = true;
    txMode ? lcd.setMessageDisplay("TX MODE", 20, 30, 2) : lcd.setMessageDisplay("RX MODE", 20, 30, 2);
    delay(5000);
    while(txMode) {
        lcd.setMessageDisplay(sendSignal.sendEmergencyContacts(), 20, 30, 2);
        delay(500);
        selectorChange(SELECTOR) ? ESP.restart() : void();
    }

    while(!txMode) {
        foundSignal.FoundMessage();
        if(foundSignal.signal && !foundSignal.lostSignal) {
            lcd.setMessageDisplay(foundSignal.response, 0, 0, 2, foundSignal.values, 0, 40, 1);
        }
        if(millis() - foundSignal.lastMessage >= 10000) {
            foundSignal.signal ?  lcd.lostSignal() : lcd.noSignal();
            foundSignal.lostSignal = true;
            foundSignal.count = 0;
            }
        selectorChange(SELECTOR) ? ESP.restart() : void();
    }
}


bool selectorChange(int selector){
    bool change;
    digitalRead(selector) == 1 ? change = true : change = false;
    return change;
}