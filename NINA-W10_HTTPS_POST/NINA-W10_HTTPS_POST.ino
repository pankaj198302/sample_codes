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
  WiFiClientSecure *client = new WiFiClientSecure;
  if(client) 
  {
    // set secure client with certificate
    client->setInsecure();
    //create an HTTPClient instance
    HTTPClient https;
    String data = "email=866897055929923&password=Wertyu$567";

    //Initializing an HTTPS communication using the secure client
    Serial.print("[HTTPS] begin...\n");
    https.begin(*client, "https://device.parxsys.com/api/v2/devices/login");
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpsResponsecode = https.POST(data);
    Serial.print("[HTTPS] POST...\n");
    // start connection and send HTTP header
    if (httpsResponsecode > 0) 
      {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] POST... code: %d\n", httpsResponsecode);
        // file found at server
        if (httpsResponsecode == HTTP_CODE_OK || httpsResponsecode == HTTP_CODE_MOVED_PERMANENTLY) 
        {
          // print server response payload
          String payload = https.getString();
          Serial.println(payload);
        }
      }
      else 
      {
        Serial.printf("[HTTPS] POST... failed, error: %s\n", https.errorToString(httpsResponsecode).c_str());
      }
      https.end();
  }
  else 
  {
    Serial.printf("[HTTPS] Unable to connect\n");
  }
  Serial.println();
  Serial.println("Waiting 2min before the next round...");
  delay(1000*120);
}