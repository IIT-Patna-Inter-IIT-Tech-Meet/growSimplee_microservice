#pragma once
#include "src/display/display.h"
#include "src/wifi/wifi_code.h"
#include "src/ultrasonic/ultrasonic.h"
#include "src/weight/weight_cell.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  screen_setup();
  setup_wifi();
  connect_wifi();
  // setupUltrasonic();
  // setup_weight_cell();

}

void loop() {
  send_data();
  delay(100000);
  //   delayMicroseconds(3000000);
  //  float length, width, height, weight;
  //  weight = get_weight();
  //  Serial.print("Weight: ");
  //  Serial.println(weight);
  //length = capturedistance(TRIG_PIN_1, ECHO_PIN_1);
  // delayMicroseconds(3000000);
  // width = capturedistance(TRIG_PIN_2, ECHO_PIN_2);
  // delayMicroseconds(100);
  // height = capturedistance(TRIG_PIN_3, ECHO_PIN_3);
  // delayMicroseconds(100);

  //Print L, B, H
  //Serial.print("Length: ");
  //Serial.println(length);

  // Serial.print("Width: ");
  // Serial.println(width);

  // Serial.print("Height: ");
  // Serial.println(height);

}
