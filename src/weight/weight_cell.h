#pragma once
#include <Arduino.h>
#include "soc/rtc.h"
#include "HX711.h"

//#define LOADCELL_DOUT_PIN 16
//#define LOADCELL_SCK_PIN 4

const int LOADCELL_DOUT_PIN = 16;
const int LOADCELL_SCK_PIN = 4;

const float CALIBRATION_FACTOR = -69;
void setup_weight_cell();
void set_calibrate_scale();
void get_calibration();
float get_weight();





