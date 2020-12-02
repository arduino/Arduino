#include <Adafruit_CircuitPlayground.h>

float tempC, tempF;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  tempC = CircuitPlayground.temperature();
  tempF = CircuitPlayground.temperatureF();

  Serial.print("tempC: ");
  Serial.print(tempC);
  Serial.print("  tempF: ");
  Serial.println(tempF);

  delay(1000);
}
