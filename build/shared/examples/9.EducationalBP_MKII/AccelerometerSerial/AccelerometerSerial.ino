
/*
 ADXL3xx 3-axis accelerometer example for Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Absolute rating/conversion can be determined from the ADXL3xx datasheet.
 As a quick reference, for LaunchPads with 12-bit ADC (MSP430F5529, Tiva C, etc.), 
 the entire analog  range is [0,4096]. For simple tilting calculation 
 [-1g,1g] ~ = [mid-800, mid + 800] = [2048-800,2048+800] = [1248,2848]
 
 Modified from ADXL3xx example by David A. Mellis & Tom Igoe
 
 Reads an Analog Devices ADXL3xx accelerometer and communicates the
 acceleration to the computer.  The pins used are designed to be easily
 compatible with the breakout boards from Sparkfun, available from:
 http://www.sparkfun.com/commerce/categories.php?c=80

 http://www.arduino.cc/en/Tutorial/ADXL3xx

 The circuit:

 * analog 25: z-axis
 * analog 24: y-axis
 * analog 23: x-axis
 
 created 2 Jul 2008
 by David A. Mellis
 modified 30 Aug 2011
 by Tom Igoe 
 modified 03 Dec 2013
 by Dung Dang
 
 This example code is in the public domain.

*/


const int xpin = 23;                  // x-axis of the accelerometer
const int ypin = 24;                  // y-axis
const int zpin = 25;                  // z-axis (only on 3-axis models)

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);
  Serial.print("working \n");

}

void loop()
{
  // print the sensor values:
  Serial.print(((int) analogRead(xpin)) - 2048);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(((int) analogRead(ypin)) - 2048);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(((int) analogRead(zpin)) - 2048);
  Serial.println();
  // delay before next reading:
  delay(100);
}
