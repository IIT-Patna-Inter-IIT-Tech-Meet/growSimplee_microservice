#pragma once
#include <stdio.h>
#include <WiFi.h>
#include "HTTPClient.h"
#include "../display/display.h"
#include "../utility/utility.h"

#define WIFI_SSID "private"
#define WIFI_PASSWORD "123456789"
#define API_ENDPOINT "http://192.168.215.30:5000/package/record-dimensions"

void setup_wifi();
void connect_wifi();    // Connect to wifi
void disconnect_wifi(); // Disconnect from wifi
void print_wifi_status();
void send_data();