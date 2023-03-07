 // This sample code uses GPIO 16 and GPIO17 for RXD2 and TXD2. ON ESP32 Wroom module the pins are named as RX2 and TX2
 //#define RXD2 16
 //#define TXD2 17
// Here We are testing with NINA-W106 -- Doesn't work
 //#define RXD2 13
// #define TXD2 12

 // Here We are testing with NINA-W106  -- Refer NINA-EVK USer Guide Working NINA-W106 MOP 16 and MOP 17 Working
 //#define RXD2 26
 //#define TXD2 25
  // Here We are testing with NINA-W106  -- Refer NINA-EVK USer Guide Working NINA-W106 MOP 20 and MOP 21 Working
 //#define RXD2 22
 //#define TXD2 19
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(1000*5);
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
