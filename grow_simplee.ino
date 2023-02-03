#pragma once
#include "src/wifi/wifi_code.h"
#include "src/ultrasonic/ultrasonic.h"
#include "src/weight/weight_cell.h"
#include "src/display/display.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_wifi();
  connect_wifi();
  setupUltrasonic();
}

void loop() {
  float length, width, height;
  length = capturedistance(TRIG_PIN_1, ECHO_PIN_1);
  delayMicroseconds(100);
  width = capturedistance(TRIG_PIN_2, ECHO_PIN_2);
  delayMicroseconds(100);
  height = capturedistance(TRIG_PIN_3, ECHO_PIN_3);
  delayMicroseconds(100);

  //Print L, B, H
  Serial.print("Length: ");
  Serial.println(length);

  Serial.print("Width: ");
  Serial.println(width);

  Serial.print("Height: ");
  Serial.println(height);

}
