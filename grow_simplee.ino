#pragma once
#include "src/display/display.h"
#include "src/wifi/wifi_code.h"
#include "src/ultrasonic/ultrasonic.h"
#include "src/weight/weight_cell.h"
#include "src/utility/utility.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // screen_setup();
  // setup_wifi();
  // connect_wifi();
  // setupUltrasonic();
  setup_weight_cell();

}

void loop() {
  // send_data();
  // delay(100000);

   float length, width, height, weight;
   weight = get_weight();
   Serial.print("weight :");
   Serial.print(weight);
   Serial.println(" kg");

  // length = capturedistance(TRIG_PIN_1, ECHO_PIN_1);
  // delayMicroseconds(100);
  // logmsg("length :" + to_string(length), "DATA", 1);

  // width = capturedistance(TRIG_PIN_2, ECHO_PIN_2);
  // delayMicroseconds(100);
  // logmsg("width :" + to_string(width), "DATA", 1);

  // height = capturedistance(TRIG_PIN_3, ECHO_PIN_3);
  // delayMicroseconds(100);
  // logmsg("height :" + to_string(height), "DATA", 1);

  delay(300);

}
