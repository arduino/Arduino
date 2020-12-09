#include <Adafruit_CircuitPlayground.h>

bool slideSwitch;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  slideSwitch = CircuitPlayground.slideSwitch();
  
  Serial.print("Slide Switch: ");
  if (slideSwitch) {
    Serial.print("+");
  } else {
    Serial.print("-");
  }
  Serial.println();
  
  delay(1000);
}
