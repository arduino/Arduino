void setupAnalog2() {
  Serial.begin(115200);
}

void loopAnalog() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("Value read by task 2: ");
  Serial.println(sensorValue);
  delay(500);  
}
