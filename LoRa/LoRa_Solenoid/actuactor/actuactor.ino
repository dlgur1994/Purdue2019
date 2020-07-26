int solenoidPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
  pinMode(solenoidPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("HIGH");
  digitalWrite(solenoidPin, HIGH);
  delay(1000);
  Serial.print("LOW");
  digitalWrite(solenoidPin, LOW);
  delay(1000);
}
