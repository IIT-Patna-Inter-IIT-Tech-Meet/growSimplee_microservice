#pragma once
#include <Arduino.h>
#include "soc/rtc.h"
#include "HX711.h"

// Some timer the load cell don't setup, exchange the DT and SCK pins in that case


const int LOADCELL_DOUT_PIN = 16;//SCK
const int LOADCELL_SCK_PIN = 4; // DT

const float CALIBRATION_FACTOR = -69;
void setup_weight_cell();
// void set_calibrate_scale();
void get_calibration();
float get_weight();





