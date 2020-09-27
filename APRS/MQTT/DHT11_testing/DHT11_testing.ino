#include "dht.h"

#define dht_apin A0 // Analog Pin sensor is connected to

dht DHT;
int count = 0;

void setup()
{
  delay(1000);
  // Ask for firmware version
  Serial.begin(9600);
  Serial.println("C");
  delay(3);
  Serial.print("MW1AW\r\n");               //SET YOUR CALLSIGN HERE, HERE YOU SEE W1AW
  delay(10);                       
  Serial.print("PWIDE1-1,WIDE2-1\r\n");    //SET DIGIPATH HERE
  delay(10);

}

void loop()                     // run over and over again
{

  
  DHT.read11(dht_apin);

//  StaticJsonDocument<200> doc;
  String data = "";
  count++;

  data = data + "test"+(String)count + ", ";
  data = data + (String)DHT.temperature + ", ";
  data = data + (String)DHT.humidity + ", ";
    
  Serial.print("!");
  Serial.print(data);
  Serial.print("\r\n");
  delay(3000);  

}
