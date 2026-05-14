void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  float voltage = reading * 5.0 / 1024.0;
  float temperature = (voltage - 0.5) * 100;
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  if (temperature > 30) {
    digitalWrite(13, HIGH);
    tone(8, 1000);
  } else {
    digitalWrite(13, LOW);
    noTone(8);
  }
  
  delay(900);
}
