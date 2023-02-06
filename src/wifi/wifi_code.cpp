#include "wifi_code.h"
#include <algorithm>

void setup_wifi(){
  WiFi.mode(WIFI_STA);
  Serial.println(": LOG : WiFi mode set to WIFI_STA");
  logmsg("Wifi > mode STA", "LOG", 0);
  // OLEDdisplay.println("WIFI STA");
}

std::string to_string(int x) {
    std::string y;
    do {
        y += (x % 10) + '0';
        x /= 10;
    } while (x);
    std::reverse(y.begin(), y.end());
    return y;
}


// Connect to specified wifi network
void connect_wifi(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  flashmsg();
  logmsg("Connecting...", "LOG", 0);
  // OLEDdisplay.println("Connecting ... ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  logmsg("WIFI connected", "LOG", 0);
  logmsg("IP address :", "LOG", 0);
  IPAddress broadcast = WiFi.localIP();
  std::string s = "";
  for (int i = 0; i < 4; ++i) {
    if (i) s += ".";
    s += to_string(broadcast[i]);
  }
  logmsg(s ,"",0);
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
void send_data(){
  HTTPClient http;
  http.begin(API_ENDPOINT);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST("{\"machineId\" : \"machine:6\", \"length\": 123, \"breadth\": 123, \"height\": 324, \"weight\": 2412}");
  flashmsg();
  logmsg("HTTP Response code", "LOG", 0);
  std::string r = to_string(httpResponseCode);
  logmsg(r, "LOG", 0);
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