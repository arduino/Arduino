#include <Adafruit_CircuitPlayground.h>

bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  
  Serial.print("Left Button: ");
  if (leftButtonPressed) {
    Serial.print("DOWN");
  } else {
    Serial.print("  UP");
  }
  Serial.print("   Right Button: ");
  if (rightButtonPressed) {
    Serial.print("DOWN");
  } else {
    Serial.print("  UP");    
  }
  Serial.println();
  
  delay(1000);
}
