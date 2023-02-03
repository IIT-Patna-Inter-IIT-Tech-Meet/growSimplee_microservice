#include "wifi_code.h"

void setup_wifi(){
  WiFi.mode(WIFI_STA);
  Serial.println(": LOG : WiFi mode set to WIFI_STA");
}

// Connect to specified wifi network
void connect_wifi(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println(": LOG : Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(": LOG : Connected to WiFi");
  Serial.print(": LOG : IP address: ");
  Serial.println(WiFi.localIP());
}

// Disconnect from wifi
void disconnect_wifi(){
  WiFi.disconnect();
  Serial.println(": LOG : Disconnected from WiFi");
}

// Print wifi status
void print_wifi_status(){
  Serial.print(": LOG : WiFi status: ");
  Serial.println(WiFi.status());
}

// Send data to API endpoint
void send_data(){
  HTTPClient http;
  http.begin(API_ENDPOINT);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST("{\"value\": 1}");
  Serial.print(": LOG : HTTP Response code: ");
  Serial.println(httpResponseCode);
  http.end();
}