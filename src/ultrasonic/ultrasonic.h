#pragma once
#include <stdio.h>
#include <Arduino.h>
#define TRIG_PIN_1 5
#define ECHO_PIN_1 18
#define TRIG_PIN_2 15
#define ECHO_PIN_2 2
#define TRIG_PIN_3 22
#define ECHO_PIN_3 23
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

#define CALIBRATE_HIGHT 40
#define CALIBRATE_WIDTH 50
#define CALIBRATE_LENGTH 60

void setupUltrasonic();
float capturedistance(int trig_pin, int echo_pin);
