#pragma once
#include <stdio.h>
#include <Arduino.h>
#define TRIG_PIN_1 27
#define ECHO_PIN_1 33
#define TRIG_PIN_2 26
#define ECHO_PIN_2 32
#define TRIG_PIN_3 25
#define ECHO_PIN_3 35

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

#define CALIBRATE_HIGHT 40
#define CALIBRATE_WIDTH 50
#define CALIBRATE_LENGTH 60

void setupUltrasonic();
float capturedistance(uint8_t trig_pin, uint8_t echo_pin);
