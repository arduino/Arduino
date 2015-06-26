/* 
 Educational BoosterPack MK II - LED_Blink_Counter
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Blink BLUE_LED on the Edu BP MK II exactly 10 times.
 
 Dec 2012 - Created for Educational BoosterPack
            Use MSP430G2 LaunchPad on-board LED
 Dec 2013 - Modified for Educational BoosterPack MK II
            Use Edu BP MK II RGB LED channels
 by Dung Dang
 
 */

#define RGB_BLUE_LED 37 
#define RGB_GREEN_LED 38
#define RGB_RED_LED 39

void setup() 
{ 
  // initialize the digital pin as an output. 
  pinMode(RGB_BLUE_LED, OUTPUT);
}

void loop()
{ 
  for (int i = 0; i < 10; i++)
  {
    // blink the BLUE LED 10x with the help of the for-loop! 
    digitalWrite(RGB_BLUE_LED, HIGH); 
    delay(300); 
    digitalWrite(RGB_BLUE_LED, LOW); 
    delay(300);
  }// when we’re done with the for-loop, exit the loop and continue the sketch
  while(1);// once we blinked the LED the desired amount of times, we get stuck in this empty while loop
}
