 #define RXD2 13
 #define TXD2 12
 // This sample code uses GPIO 13 and GPIO12 for RXD2 and TXD2. ON ESP32 Wroom module the pins are named as D13 and D12
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(1000);
  Serial.println("Loopback program started");

}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available()){
    Serial.write("-");
    Serial2.write(Serial.read());  
   }
   if(Serial2.available()){
     Serial.write(".");
     Serial.write(Serial2.read());  
   }

}
