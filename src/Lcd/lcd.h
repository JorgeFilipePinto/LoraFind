#pragma once

#include<Arduino.h>
#include <memory.h>
#include <Wire.h>
#include<Adafruit_SSD1306.h>

#include <FS.h>
#include "SPIFFS.h"


class Lcd {
    public:
        String displayMessage = "";
        String message = "";
        int displayPosX = 0;
        int displayPosY = 0;
        void init(int width, int height, int sdaPin, int sclPin);
        void setMessageDisplay(String message, int posX, int posY, int size);
        void checkMessage(String message, int posX, int posY, int size);
        void noSignal();
        void lostSignal();
        
    private:
        int width = -1;
        int height = -1;
        int sdaPin = -1;
        int sclPin = -1;
        int resetPin = -1;
        int address = 0x3C;
        Adafruit_SSD1306* lcd;
};