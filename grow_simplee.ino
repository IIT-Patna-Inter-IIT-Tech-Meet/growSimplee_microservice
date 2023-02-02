#pragma once
#include "src/wifi/wifi_code.h"
#include "src/ultrasonic/ultrasonic.h"
#include "src/weight/weight_cell.h"
#include "src/display/display.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print(SOME_CONST);
  setup_wifi();
}

void loop() {

  // put your main code here, to run repeatedly:

}
