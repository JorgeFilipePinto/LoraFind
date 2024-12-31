#include"lcd.h"

void Lcd::init(int width, int height, int sdaPin, int sclPin) {
    this->width = width;
    this->height = height;
    this->sdaPin = sdaPin;
    this->sclPin = sclPin;
    this->lcd = new Adafruit_SSD1306(width, height, &Wire, resetPin);
    if(!lcd-> begin(SSD1306_SWITCHCAPVCC, address)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    lcd-> clearDisplay();
    lcd-> display();
    delay(2000);
};


void Lcd::checkMessage(String message, int posX, int posY, int size) {
    if(displayMessage != message || displayPosX != posX || displayPosY != posY) {
        this-> message = message;
        setMessageDisplay(message, posX, posY, size);
    }
}

void Lcd::noSignal() {
    lcd-> clearDisplay();
    lcd-> setCursor(50, 20);
    lcd-> print("NO");
    lcd-> setCursor(45, 40);
    lcd-> print("SIGNAL");
    lcd-> display();
}

void Lcd::lostSignal() {
    lcd-> clearDisplay();
    lcd-> setCursor(50, 20);
    lcd-> print("LOST");
    lcd-> setCursor(45, 40);
    lcd-> print("SIGNAL");
    lcd-> display();
}


void Lcd::setMessageDisplay(String message, int posX, int posY, int size) {
    lcd-> clearDisplay();
    lcd-> setTextColor(SSD1306_WHITE);
    lcd-> setCursor(posX, posY);
    lcd-> setTextSize(size);
    lcd-> print(message);
    displayMessage = message;
    displayPosX = posX;
    displayPosY = posY;
    lcd-> display();
}


