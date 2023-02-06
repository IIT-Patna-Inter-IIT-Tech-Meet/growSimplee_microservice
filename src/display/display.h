#pragma once 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string>
#include <stdio.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3D

void screen_setup();
void logmsg(std::string msg, std::string level, int mode); // 0 -> serial and screen, 1 -> serial, 2 -> screen
void flashmsg();
// PIN SETUP [ i2c protocol ]
// Vin -> 3.3v, GND -> ground, SCL->GPIO 22, SDA -> GPIO 21
