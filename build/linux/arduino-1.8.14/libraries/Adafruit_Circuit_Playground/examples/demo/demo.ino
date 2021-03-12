// Demo program for testing library and board - flip the switch to turn on/off buzzer

#include <Adafruit_CircuitPlayground.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
}


void loop() {
  // turn off speaker when not in use
  CircuitPlayground.speaker.enable(false);

  // test Red #13 LED
  CircuitPlayground.redLED(HIGH);
  delay(100);
  CircuitPlayground.redLED(LOW);

  /************* TEST CAPTOUCH */
  Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3));
  Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2));
  Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0));
  Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));
  delay(10);

  /************* TEST SLIDE SWITCH */
  if (CircuitPlayground.slideSwitch()) {
    Serial.println("Slide to the left");
  } else {
    Serial.println("Slide to the right");
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(500 + pixeln * 500, 100);
  }
  delay(10);

  /************* TEST 10 NEOPIXELS */
  CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
  if (pixeln == 11) {
    pixeln = 0;
    CircuitPlayground.clearPixels();
  }
  delay(10);

  /************* TEST BOTH BUTTONS */
  if (CircuitPlayground.leftButton()) {
    Serial.println("Left button pressed!");
  }
  if (CircuitPlayground.rightButton()) {
    Serial.println("Right button pressed!");
  }
  delay(10);

  /************* TEST LIGHT SENSOR */
  Serial.print("Light sensor: ");
  Serial.println(CircuitPlayground.lightSensor());
  delay(10);

  /************* TEST SOUND SENSOR */
  Serial.print("Sound sensor: ");
  Serial.println(CircuitPlayground.mic.soundPressureLevel(10));
  delay(10);

  /************* TEST ACCEL */
  // Display the results (acceleration is measured in m/s*s)
  Serial.print("X: "); Serial.print(CircuitPlayground.motionX());
  Serial.print(" \tY: "); Serial.print(CircuitPlayground.motionY());
  Serial.print(" \tZ: "); Serial.print(CircuitPlayground.motionZ());
  Serial.println(" m/s^2");
  delay(10);

  /************* TEST THERMISTOR */
  Serial.print("Temperature ");
  Serial.print(CircuitPlayground.temperature());
  Serial.println(" *C");
}