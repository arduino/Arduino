/*
  Gator Holes & Buzzer example for Educational BoosterPack MK II
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Turn anything into an input using the Gator Holes. Connect the 
 the two Gator Holes with anything conductive (e.g. your hand, a fruit,
 orange juice, coffee, etc.) to sound the Buzzer.
 
 Dec 2013 - Modified for Educational BoosterPack MK II
            buzzer Pin = 40
 
 The circuit:
 * 1 Gator Hole connected to pin 34
 * 1 Gator Hole connected to GND
 * Buzzer connected to pin 40
 
 
 modified Dec 03 2013 - for Educational BoosterPack MK II
 by Dung Dang
 
 This example code is in the public domain.
 
 
 */

const int gatorHole = 34;     // the number of the gator hole pin
const int buzzerPin = 40;

int gatorHoleState = 0;         // variable for reading the gator hole status


void setup() {

  // initialize the gator hole pin as an input:
  pinMode(gatorHole, INPUT_PULLUP);     
  
}

void loop(){
  // read the state of the pushbutton value:
  gatorHoleState = digitalRead(gatorHole);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (gatorHoleState == LOW) {     
    // turn on Buzzer 
    tone(buzzerPin, 500, 500);
  } 
  else {
    // turn off Buzzer
    noTone(buzzerPin);
  }
  
}
