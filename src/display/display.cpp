#include "display.h"


Adafruit_SSD1306 OLEDdisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void screen_setup(){
    if(!OLEDdisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F(": ERROR :SSD1306 allocation failed"));
        for(;;);
    }
    Serial.println(": LOG : Screen Setup Complete.");
    delay(2000);
    OLEDdisplay.clearDisplay();
    OLEDdisplay.setTextSize(1);
    OLEDdisplay.setTextColor(WHITE);
    OLEDdisplay.setCursor(0,10);
    OLEDdisplay.println("__init__");
    OLEDdisplay.display();
    delay(2000);
    OLEDdisplay.clearDisplay();
    OLEDdisplay.display();
    Serial.println(": DEBUG : Screen working.");
}

void logmsg(std::string msg, std::string level, int mode){
    if ( mode == 0 || mode == 1 ){
        if (level != ""){
            Serial.print(": ");
            Serial.print(level.c_str());
            Serial.print(" :");
        }
        Serial.println(msg.c_str());
    }

    if (mode == 0 || mode == 2){
        // Screen print
        OLEDdisplay.println(msg.c_str());
        OLEDdisplay.display();
    }

}

// void bulkmsg(std::vector<std::string> msgs){
//     OLEDdisplay.clearDisplay();
//     OLEDdisplay.setCursor(0,10);
//     for ( auto msg: msgs){
//         OLEDdisplay.println(msg);
//     }

// }

void flashmsg(){
    OLEDdisplay.clearDisplay();
    OLEDdisplay.setCursor(0,10);
    OLEDdisplay.display();
}


