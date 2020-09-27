int highval = 9;

int count = 0;

void setup()
{
  delay(1000);
  // Ask for firmware version
  Serial.begin(4800);
  Serial.println("C");
  delay(3);
  Serial.print("MKD9NDI-1\r\n");           //SET YOUR CALLSIGN HERE
  delay(10);                       
  Serial.print("PWIDE1-1,WIDE2-1\r\n");    //SET DIGIPATH HERE
  delay(10);
  
  pinMode(highval, OUTPUT);
}

void loop()                     // run over and over again
{
  String data = "";
  count++;

  data = data + "test"+(String)count + ", ";
  Serial.println("transmit data");  
  
  // trasmit
  digitalWrite(highval, HIGH);
  Serial.println("High");
  Serial.print("!");
  Serial.print(data);
  Serial.print("\r\n");
  delay(3000);
  digitalWrite(highval, LOW);
  Serial.println("Low");
  
  Serial.println("C");
  delay(10);
  Serial.print("W");
  Serial.println("data transmitted");
  delay(2000);
}
