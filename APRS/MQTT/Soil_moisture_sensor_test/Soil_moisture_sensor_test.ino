
void setup()
{
// Setup serial
Serial.begin(9600);
}void loop()
{
Serial.println(analogRead(0));
delay(200);  // wait 200 milliseconds
}
