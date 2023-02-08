#pragma once
// #include "src/display/display.h"
#include "src/wifi/wifi_code.h"
#include "src/ultrasonic/ultrasonic.h"
#include "src/weight/weight_cell.h"
#include "src/utility/utility.h"
#include "src/servo/servo.h"

#define LDR_PIN 34

// Global Variable 
float Height, Length, Width, Weight; // values to submit
float dHeight = 40, dLength = 65, dWidth = 50, pLength= 0; // default values of sensors
float tHeight = 0, tLength = 0, tWidth = 0, tWeight = 0; // total count
int cHeight = 0, cLength = 0, cWidth = 0, cWeight = 0; // counter varriable
bool trigger = false;
int ldr_threshold = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // screen_setup();
  setup_servo();
  setup_wifi();
  connect_wifi();
  setupUltrasonic();
  setup_weight_cell();
  get_calibration();
}

void loop() {
  // send_data();
  // delay(100000);
  
  float length, width, height, weight;
  weight = get_weight();
  Serial.print("weight :");
  Serial.print(weight);
  Serial.println(" kg");

  length = capturedistance(TRIG_PIN_1, ECHO_PIN_1);
  delayMicroseconds(100);
  logmsg("length :" + to_string(length), "DATA", 1);

  width = capturedistance(TRIG_PIN_2, ECHO_PIN_2);
  delayMicroseconds(100);
  logmsg("width :" + to_string(width), "DATA", 1);

  height = capturedistance(TRIG_PIN_3, ECHO_PIN_3);
  delayMicroseconds(100);
  logmsg("height :" + to_string(height), "DATA", 1);

  // check LDR sensor for 
  unsigned int AnalogValue;
  AnalogValue = analogRead(34);

  ldr_threshold = (AnalogValue > 100) ? ldr_threshold+1 : 0;
  if (ldr_threshold > 17)
    trigger = true;

  pushData(length, width, height, weight);
  delay(300);
}


void pushData(float length, float width, float height, float weight){
  if (trigger){
    Length = tLength/cLength;
    Width = tWidth / cWidth;
    Height= tHeight / cHeight;
    Weight = tWeight / cWeight;

    send_data(Length, Width, Height, Weight);
    Length = -1;
    Width = -1;
    Height = -1;
    Weight = -1;

    tLength = 0;
    tHeight = 0;
    tWidth = 0;
    tWeight = 0;

    cLength = 0;
    cHeight = 0;
    cWidth = 0;
    tWeight = 0;

    servo_release();
    delay(1000);
    servo_block();
    trigger = false;
  }

  if ( dHeight == height || dWidth == width || length <= pLength ){ // Sleep condition
    return;
  }
  weight = (weight > 0) ? weight : 0;
  tLength += length;
  tHeight += height;
  tWidth += width;
  tWeight += weight;

  cLength ++;
  cHeight ++;
  cWidth ++;
  cWeight ++;

  pLength = length;
}