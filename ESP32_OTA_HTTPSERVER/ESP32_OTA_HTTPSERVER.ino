#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsync_WiFiManager.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <Update.h>

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
const char* firmwareUrl = "http://yourserver.com/firmware.bin";  // URL of the firmware binary

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup OTA update endpoint
  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request){
    t_httpUpdate_return ret = HTTP_UPDATE_FAILED;

    WiFiClient client;
    HTTPClient http;

    Serial.print("Downloading firmware from ");
    Serial.println(firmwareUrl);

    // Download the firmware binary
    http.begin(client, firmwareUrl);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
      Serial.println("Firmware download successful");

      // Start the update process
      ret = Update.begin(UPDATE_SIZE_UNKNOWN);
      if (ret == HTTP_UPDATE_OK) {
        WiFiClient stream = http.getStream();
        while (stream.connected() && !Update.isFinished()) {
          ret = Update.writeStream(stream);
          if (ret != HTTP_UPDATE_OK)
            break;
        }
      }
    }

    // Clean up resources
    http.end();
    client.stop();
  int ret = -1;
    // Send response to the client
    if (ret == HTTP_UPDATE_OK) {
      request->send(200, "text/plain", "Update successful; rebooting...");
      ESP.restart();
    } else {
      request->send(200, "text/plain", "Update failed");
    }
  });

  // Start server
  server.begin();
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
