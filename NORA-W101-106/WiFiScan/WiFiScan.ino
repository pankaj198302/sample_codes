/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 */
#include "WiFi.h"
// 44 and 43 are GPIO Pin numbers Module Pin numbers are 37-->43 -->TXD; 36-->44-->RXD.
 #define RXD1 44
 #define TXD1 43
 // 17 and 18 are GPIO Pin numbers Module Pin numbers are 10-->17 -->TXD; 11-->18-->RXD.
 #define RXD2 18
 #define TXD2 17

void setup()
{
    Serial.begin(115200); 
    Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1);
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done"); // Print statement is going to USB Port of the module
    Serial1.println("UART0 -- Setup done"); // Print statement is going to UART0 Port of the module
    Serial2.println("UART1 -- Setup done"); // Print statement is going to UART1 Port of the module
}

void loop()
{
    Serial.println("Scan start");
    Serial1.println("Scan start");
    Serial2.println("Scan start");

    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    Serial1.println("Scan done");
    Serial2.println("Scan done");
    if (n == 0) {
        Serial.println("no networks found");
        Serial1.println("no networks found");
        Serial2.println("no networks found");
    } else {
        Serial.print(n);
        Serial1.print(n);
        Serial2.print(n);
        Serial.println(" networks found");
        Serial1.println(" networks found");
        Serial2.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
        Serial1.println("Nr | SSID                             | RSSI | CH | Encryption");
        Serial2.println("Nr | SSID                             | RSSI | CH | Encryption");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.printf("%2d",i + 1);
            Serial1.printf("%2d",i + 1);
            Serial1.printf("%2d",i + 1);
            Serial2.printf("%2d",i + 1);
            Serial.print(" | ");
            Serial1.print(" | ");
            Serial2.print(" | ");
            Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial1.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial2.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial.print(" | ");
            Serial1.print(" | ");
            Serial2.print(" | ");
            Serial.printf("%4d", WiFi.RSSI(i));
            Serial1.printf("%4d", WiFi.RSSI(i));
            Serial2.printf("%4d", WiFi.RSSI(i));
            Serial.print(" | ");
            Serial1.print(" | ");
            Serial2.print(" | ");
            Serial.printf("%2d", WiFi.channel(i));
            Serial1.printf("%2d", WiFi.channel(i));
            Serial2.printf("%2d", WiFi.channel(i));
            Serial.print(" | ");
            Serial1.print(" | ");
            Serial2.print(" | ");
            switch (WiFi.encryptionType(i))
            {
            case WIFI_AUTH_OPEN:
                Serial.print("open");
                Serial1.print("open");
                Serial2.print("open");
                break;
            case WIFI_AUTH_WEP:
                Serial.print("WEP");
                Serial1.print("WEP");
                Serial2.print("WEP");
                break;
            case WIFI_AUTH_WPA_PSK:
                Serial.print("WPA");
                Serial1.print("WPA");
                Serial2.print("WPA");
                break;
            case WIFI_AUTH_WPA2_PSK:
                Serial.print("WPA2");
                Serial1.print("WPA2");
                Serial2.print("WPA2");
                break;
            case WIFI_AUTH_WPA_WPA2_PSK:
                Serial.print("WPA+WPA2");
                Serial1.print("WPA+WPA2");
                Serial2.print("WPA+WPA2");
                break;
            case WIFI_AUTH_WPA2_ENTERPRISE:
                Serial.print("WPA2-EAP");
                Serial1.print("WPA2-EAP");
                Serial2.print("WPA2-EAP");
                break;
            case WIFI_AUTH_WPA3_PSK:
                Serial.print("WPA3");
                Serial1.print("WPA3");
                Serial2.print("WPA3");
                break;
            case WIFI_AUTH_WPA2_WPA3_PSK:
                Serial.print("WPA2+WPA3");
                Serial1.print("WPA2+WPA3");
                Serial2.print("WPA2+WPA3");
                break;
            case WIFI_AUTH_WAPI_PSK:
                Serial.print("WAPI");
                Serial1.print("WAPI");
                Serial2.print("WAPI");
                break;
            default:
                Serial.print("unknown");
                Serial1.print("unknown");
                Serial2.print("unknown");
            }
            Serial.println();
            Serial1.println();
            Serial2.println();
            delay(10);
        }
    }
    Serial.println("");
    Serial1.println("");
    Serial2.println("");

    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();

    // Wait a bit before scanning again.
    delay(5000);
}
