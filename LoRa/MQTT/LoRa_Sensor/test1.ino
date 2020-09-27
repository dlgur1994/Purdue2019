#include <LoRa.h>

#include <SPI.h>
#include <dht.h>

#define dht_apin A0 // Analog Pin sensor is connected to

dht DHT;
int count = 0;
int counter = 0;

void setup() {
    delay(1000);
  // Ask for firmware version
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");
if (!LoRa.begin(915E6)) { /*LoRa.begin(frequency)*/
    Serial.println("Starting LoRa failed!");
    while (1);
  }else{
   LoRa.setTxPower(13);
    LoRa.setSignalBandwidth(125E3);
    LoRa.setCodingRate4(5);
}
 
}
void loop() {
   DHT.read11(dht_apin);

//  StaticJsonDocument<200> doc;
  String data = "";
  count++;

  data = data + "test"+(String)count + ", ";
  data = data + "temp:"+(String)DHT.temperature + ", ";
  data = data + "hum:"+(String)DHT.humidity + ", ";
  data = data + "soil:"+(String)analogRead(1) + ", ";

  Serial.print("Sending packet: ");
  Serial.println(counter);
  
  Serial.println(analogRead(1));
  Serial.print("!");
  Serial.print(data);
  Serial.print("\r\n");
  
  // send packet
  LoRa.beginPacket();
  LoRa.print(counter);
  LoRa.print("\n");
  LoRa.print(data);
  LoRa.endPacket();                                                 
  counter++;
  delay(5000);
}
