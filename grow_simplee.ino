#pragma once
#include "wifi_code.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print(SOME_CONST);
  setup_wifi();
}

void loop() {

  // put your main code here, to run repeatedly:

}
