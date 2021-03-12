#include <Adafruit_CircuitPlayground.h>

float value;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // Take 10 milliseconds of sound data to calculate
  value = CircuitPlayground.mic.soundPressureLevel(10);
  
  Serial.print("Sound Sensor SPL: ");
  Serial.println(value);

  delay(90);
}