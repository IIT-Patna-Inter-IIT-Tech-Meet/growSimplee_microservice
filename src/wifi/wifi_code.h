#pragma once
#include <stdio.h>
#include <WiFi.h>
#include "HTTPClient.h"

#define WIFI_SSID "private"
#define WIFI_PASSWORD "123456789"
#define API_ENDPOINT "http://172.16.12.9/api/v1/measurements"

void setup_wifi();
void connect_wifi();    // Connect to wifi
void disconnect_wifi(); // Disconnect from wifi
void print_wifi_status();
void send_data();