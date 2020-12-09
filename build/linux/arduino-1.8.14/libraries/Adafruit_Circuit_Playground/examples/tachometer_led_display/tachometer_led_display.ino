// Adafruit Circuit Playground Fidget Spinner Tachometer with LED Display
//
// This sketch uses the light sensor built in to Circuit Playground
// to detect the speed (in revolutions per second) of a fidget spinner
// and display it on a connected 4-digit 7-segment LED backpack display.
// See the tachometer example (without led_display) for a version that
// will output just to the serial monitor with no extra hardware needed.
//
// Load the sketch on a Circuit Playground (either classic or express)
// and notice the first three NeoPixels will turn on bright white.
// Hold a spinning fidget spinner very close to (but not touching) the
// light sensor (look for the eye graphic on the board, it's right
// below the three lit NeoPixels) and the sketch will display the
// revolutions per second of the spinner on the LED display.  Hold
// the spinner perpendicular to the light sensor for the best
// measurement:
//       ||
//       || <- Spinner
//       ||
//    ________  <- Circuit Playground
//
// Author: Tony DiCola
// License: MIT License (https://en.wikipedia.org/wiki/MIT_License)
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>

// Configuration values.  You don't have to change these but they're
// interesting to adjust the logic.  If your spinner has more or less
// than three arms be sure to change the SPINNER_ARMS value below:
#define SPINNER_ARMS       3      // Number of arms on the fidget spinner.
                                  // This is used to calculate the true
                                  // revolutions per second of the spinner
                                  // as one full revolution of the spinner
                                  // will actually see this number of cycles
                                  // pass by the light sensor.  Set this to
                                  // the value 1 to ignore this calculation
                                  // and just see the raw cycles / second.
                                  
#define SAMPLE_DEPTH       512    // How many samples to take when measuring
                                  // the spinner speed.  The larger this value
                                  // the more memory that will be consumed but
                                  // the slower a spinner speed that can be
                                  // detected (larger sample depths mean longer
                                  // period waves can be detected).  You're
                                  // limited by the amount of memory on the
                                  // board for this value.  On a classic
                                  // Circuit Playground with 2kb of memory
                                  // you can only go up to about 512 or so (each
                                  // sample is 2 bytes, so 1kb of space total).
                                  // On an express board you can go much higher,
                                  // like up to 10240 for 20kb of sample data.

#define SAMPLE_PERIOD_US   1500   // Amount of time in microseconds to delay
                                  // between each light sensor sample.  This is
                                  // a balance between how fast and slow of
                                  // a spinner reading that can be measured.
                                  // The higher this value the slower a spinner
                                  // you can measure, but at the tradeoff of
                                  // not accurately measuring fast spinners.
                                  // Low values (even 0) mean very fast speeds
                                  // can be detected but slow speeds (below 10hz)
                                  // are harder to detect.  You can increase the
                                  // sample depth to help improve the range
                                  // of detection speeds, but there's a limit 
                                  // based on the memory available.

#define THRESHOLD          400    // How big the amplitude of a cyclic
                                  // signal has to be before the measurement
                                  // logic kicks in.  This is a value from
                                  // 0 to 1023 and might need to be adjusted
                                  // up or down if the detection is too
                                  // sensitive or not sensitive enough.
                                  // Raising this value will make the detection
                                  // less sensitive and require a very large
                                  // difference in amplitude (i.e. a very close
                                  // or highly reflective spinner), and lowering
                                  // the value will make the detection more
                                  // sensitive and potentially pick up random
                                  // noise from light in the room.

#define MEASURE_PERIOD_MS  1000   // Number of milliseconds to wait
                                  // between measurements.  Default is
                                  // one second (1000 milliseconds).

#define DISPLAY_ADDRESS    0x70   // I2C address of the display.  Use the default
                                  // 0x70 unless you've manually changed the
                                  // devices address by soldering closed a bridge.


// Global state for the LED display:
Adafruit_7segment disp = Adafruit_7segment();

void setup() {
  // Initialize serial monitor at 115200 baud.
  Serial.begin(115200);

  // Initialize CircuitPlayground library and turn on the first 3 pixels (near the light sensor)
  // to pure white at maximum brightness.
  CircuitPlayground.begin(255);  // 255 means set pixel colors to max brightness.
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 255, 255, 255);  // Set pixel 0, 1, 2 to white.
  CircuitPlayground.setPixelColor(1, 255, 255, 255);
  CircuitPlayground.setPixelColor(2, 255, 255, 255);

  // Initialize and clear the display.
  disp.begin(DISPLAY_ADDRESS);
  disp.clear();
  disp.writeDisplay();
}


void loop() {
  // Pause between measurements.
  delay(MEASURE_PERIOD_MS);

  // Collect samples from the light sensor as quickly as possible.
  // Keep track of the amount of time (in microseconds) between samples
  // so the sampling frequency can later be determined.
  uint16_t samples[SAMPLE_DEPTH] = {0};
  uint32_t start = micros();
  for (int i=0; i<SAMPLE_DEPTH; ++i) {
    samples[i] = CircuitPlayground.lightSensor();
    delayMicroseconds(SAMPLE_PERIOD_US);
  }
  uint32_t elapsed_uS = micros() - start;
  float elapsed = elapsed_uS / 1000000.0;  // Elapsed time in seconds.

  // Find the min and max values in the collected samples.
  uint16_t minval = samples[0];
  uint16_t maxval = samples[0];
  for (int i=1; i<SAMPLE_DEPTH; ++i) {
    minval = min(minval, samples[i]);
    maxval = max(maxval, samples[i]);
  }

  // Check the amplitude of the signal (difference between min and max)
  // is greater than the threshold to continue detecting speed.
  uint16_t amplitude = maxval - minval;
  if (amplitude < THRESHOLD) {
    // Didn't make it past the threshold so start over with another measurement attempt.
    return;
  }

  // Compute midpoint of the signal (halfway between min and max values).
  uint16_t midpoint = minval + (amplitude/2);

  // Count how many midpoint crossings were found in the signal.
  // These are instances where two readings either straddle or land on
  // the midpoint.  The midpoint crossings will happen twice for every
  // complete sine wave cycle (once going up and again coming down).
  int crossings = 0;
  for (int i=1; i<SAMPLE_DEPTH; ++i) {
    uint16_t p0 = samples[i-1];
    uint16_t p1 = samples[i];
    if ((p1 == midpoint) || 
        ((p0 < midpoint) && (p1 > midpoint)) ||
        ((p0 > midpoint) && (p1 < midpoint))) {
      crossings += 1;
    }
  }

  // Compute signal frequency, RPM, and period.
  // The period is the amount of time it takes for a complete
  // sine wave cycle to occur.  You can calculate this by dividing the
  // amount of time that elapsed during the measurement period by the
  // number of midpoint crossings cut in half (because each complete
  // sine wave cycle will have 2 midpoint crossings).  However since
  // fidget spinners have multiple arms you also divide by the number
  // of arms to normalize the period into a value that represents the
  // time taken for a complete revolution of the entire spinner, not
  // just the time between one arm and the next.
  float period = elapsed / (crossings / SPINNER_ARMS / 2.0);

  // Once the period is calculated it can be converted into a frequency
  // value (i.e revolutions per second, how many times the spinner spins
  // around per second) and more common RPM value (revolutions per minute,
  // just multiply frequency by 60 since there are 60 seconds in a minute).
  float frequency = 1.0 / period;
  float rpm = frequency * 60.0;

  // Print out the measured values!
  Serial.print("Frequency: ");
  Serial.print(frequency, 3);
  Serial.print(" (hz)\t\tRPM: ");
  Serial.print(rpm, 3);
  Serial.print("\t\tPeriod: ");
  Serial.print(period, 3);
  Serial.println(" (seconds)");

  // Also print the frequency (revolutions per second) to the LED display.
  disp.print(frequency);
  disp.writeDisplay();
}
