#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

// Replace with your network credentials
const char* ssid = "SANT 2.4GZ";//"RBTRONIKS"; //"SRNN";
const char* pass = "sant1234";//"RBtroniks@2019"; //"Shwe9481ta"; //

void setup() {
  Serial.begin(115200);
  Serial.println();
  // Initialize Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
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
    String data = "data=562&Data=CT:0.000Amps&DeviceID=1&Time=11:43:23"; //"status=10.X,X,X,12,22&power=10.33,3.96,54.34,13,43,23&alert=34,76,12,0,0,0,0"; "Time=11:21:22&CT_Amps=CT1:12.212Amps&Device_ID=b2b5f256-983b-4dab-a9c6-033aa305778c" ; //"email=866897055929923&password=Wertyu$567";

    //Initializing an HTTPS communication using the secure client
    Serial.print("[HTTPS] begin...\n");
   // https.begin(*client, "https://captura.parxsys.com/api/media_assets/7559ca18-a079-4b12-bdab-a77486f6e08d/iot_logs");          //https://device.parxsys.com/api/v2/devices/login           https://moblit.parxsys.com/api/v1/vehicles/ILC201700999  https://captura.parxsys.com/api/media_assets/753e6d09-5fda-4fc1-94ad-c7f48ae4dfbf/iot_logs
   https.begin(*client, "https://captura.parxsys.com/api/media_assets/7559ca18-a079-4b12-bdab-a77486f6e08d/iot_logs"); 
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
  Serial.println("Waiting 1min before the next round...");
  delay(1000);
}