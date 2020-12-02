#include <Adafruit_CircuitPlayground.h>

int value;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  value = CircuitPlayground.lightSensor();
  
  Serial.print("Light Sensor: ");
  Serial.println(value);
  
  delay(1000);
}
