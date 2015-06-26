
int sensorPin = 8;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(8, INPUT);
  Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("Value read by task 1: ");
  Serial.println(sensorValue);
  delay(1000);  
}
