#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

// Replace with your network credentials
// const char* ssid     = "RBTRONIKS";     // your network SSID (name of wifi network)
// const char* password = "RBtroniks@2019"; // your network password

const char* ssid     = "STPL-1st Floor";     // your network SSID (name of wifi network)
const char* password = "Sinban@321"; // your network password

void setup() {
  Serial.begin(115200);
  Serial.println();
  // Initialize Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void loop() 
{

  else 
  {
    Serial.printf("[HTTPS] Unable to connect\n");
  }
  Serial.println();
  Serial.println("Waiting 2min before the next round...");
  delay(1000*120);
}