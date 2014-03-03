/*
 Educational BoosterPack MK II - Random RGB LED patterns
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 This example shows how to mix colors with an RGB LED using the analogWrite() function
 together with random() function to get the random color effect.
 
 The circuit utilizes the LEDs on the Educational BoosterPack MK II:
 * RED LED attached from digital pin 39 to ground.
 * GREEN LED attached from digital pin 38 to ground.
 * BLUE LED attached from digital pin 37 to ground.
 
 Created 3 Dec 2013
 By Dung Dang
 
 http://energia.nu/RandomSeed.html
 http://energia.nu/AnalogWrite.html 
 
 This example code is in the public domain.
 
 */


int ledRed = 39, ledBlue = 37, ledGreen = 38;    // LED connected to digital pin 9

void setup()  { 
  // Initialize the pseudo-random number generator
  randomSeed(1);
} 

void loop()  { 
 
  // sets the value (range from 0 to 255) for 3 RGB channels:
  analogWrite(ledRed, random(255));
  analogWrite(ledBlue, random(255));
  analogWrite(ledGreen, random(255));    
  // wait for 30 milliseconds before changing the color again
  delay(300);                            

}


