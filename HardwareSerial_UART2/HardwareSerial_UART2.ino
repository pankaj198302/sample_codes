 #define RXD2 16
 #define TXD2 17
 // This sample code uses GPIO 16 and GPIO17 for RXD2 and TXD2. ON ESP32 Wroom module the pins are named as RX2 and TX2
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
