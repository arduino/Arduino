/*OPT3001_Backlight Example
In this example, we will read LUX readings from the OPT3001 and will use that to
modulate a PWM that controls an LED backlight to an LCD. LUX readings are also sent
to the serial monitor.

Created by Adrian Fernandez & Dung Dang, Dec 2013
Released to public domain.
*/

#include <Wire.h>			// Needed by Energia for Tiva C LaunchPad 
#include "OPT3001.h"
#define USE_USCI_B1 
opt3001 opt3001;

const uint8_t backlightPin = 39; //PWM-capable pin tied to backlight
const uint16_t darkestLUX = 0; 
const uint16_t brightestLUX = 4000;

const uint8_t dimmestBacklight = 55;
const uint8_t brightestBacklight = 254;
uint16_t SerialPrintInterval = 50;
void setup()
{
 
  Serial.begin(115200);
  delay(1000); 
  opt3001.begin(); 
  Serial.println("OPT3001 Initialized!");
  
}

void loop()
{
  uint8_t backlight = 0;
  // Variables
  unsigned long readings;
     
  // Read OPT3001
  readings = opt3001.readResult();  //min = 0, max = 131040
  
  backlight = map(readings,darkestLUX, brightestLUX, dimmestBacklight, brightestBacklight);  //simple linear backlight
  backlight = constrain(backlight, dimmestBacklight, brightestBacklight);  // keep value between the acceptable value of analogWrite()
  analogWrite(backlightPin, backlight);
  
  
  if (--SerialPrintInterval == 0)
  {
	SerialPrintInterval = 50;
	Serial.print("LUX Readings = ");
	Serial.print(readings, DEC); 
	Serial.print("  //  Backlight = ");
	Serial.println(backlight, DEC);
  }
  delay(100);
}