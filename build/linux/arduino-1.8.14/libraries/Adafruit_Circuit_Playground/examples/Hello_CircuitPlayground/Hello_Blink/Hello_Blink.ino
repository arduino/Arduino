#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  CircuitPlayground.redLED(HIGH);
  delay(500);
  CircuitPlayground.redLED(LOW);
  delay(500);
}
