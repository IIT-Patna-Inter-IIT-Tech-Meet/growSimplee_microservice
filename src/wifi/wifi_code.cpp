#include "wifi_code.h"
#include <algorithm>

std::string id = "machine:";

void setup_wifi(){
  WiFi.mode(WIFI_STA);
  Serial.println(": LOG : WiFi mode set to WIFI_STA");
  // OLEDdisplay.println("WIFI STA");
}

// Connect to specified wifi network
void connect_wifi(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // flashmsg();
  logmsg("Connecting...", "LOG", 1);
  // OLEDdisplay.println("Connecting ... ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  logmsg("WIFI connected", "LOG", 1);
  logmsg("IP address :", "LOG", 1);
  IPAddress broadcast = WiFi.localIP();
  std::string s = "";
  for (int i = 0; i < 4; ++i) {
    if (i) s += ".";
    s += to_string(broadcast[i]);
  }
  id += s;
  logmsg(s ,"",1);
  delay(3000);

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
void send_data(float l, float b, float h, float w){
  HTTPClient http;
  http.begin(API_ENDPOINT);
  http.addHeader("Content-Type", "application/json");

  // Creating json body

  std::string jsonData = "{\"machineId\": \"";
  jsonData += id;
  jsonData += "\", \"length\":";
  jsonData += to_string(l);
  jsonData += ", \"breadth\":";
  jsonData += to_string(b);
  jsonData += ", \"height\":";
  jsonData += to_string(h);
  jsonData += ", \"weight\":";
  jsonData += to_string(w);
  jsonData += "}";

  // Serial.println(jsonData);

  int httpResponseCode = http.POST( jsonData.c_str() );
  // flashmsg();
  logmsg("HTTP Response code", "LOG", 1);
  std::string r = to_string(httpResponseCode);
  logmsg(r, "LOG", 1);
  http.end();
}
/*
{
  "machineId" : "machine:...",
  "length" : l,
  "breadth": 123,
  "height": 324,
  "weight": 2412i
}

*/