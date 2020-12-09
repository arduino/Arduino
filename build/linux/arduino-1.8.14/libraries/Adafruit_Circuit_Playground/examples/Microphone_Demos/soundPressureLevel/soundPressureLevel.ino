/* This example samples the microphone for 50 milliseconds repeatedly
 * and returns the max sound pressure level in dB SPL
 * https://en.wikipedia.org/wiki/Sound_pressure
 *
 * open the serial plotter window in the arduino IDE for a nice graph
 * of sound pressure level over time.
 */

#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  Serial.begin(115200);
}

void loop() {
  Serial.println(CircuitPlayground.mic.soundPressureLevel(50));
}
