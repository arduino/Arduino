/* 
 Educational BoosterPack MK II - Konami/Contra Intro
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Play Konami/Contra Intro through the buzzer, demonstrating
 buzzer tune() API and pitch/tone/simple music generation
 
 Dec 2012 - Created for Educational BoosterPack
            buzzer Pin = 19
 Dec 2013 - Modified for Educational BoosterPack MK II
            buzzer Pin = 40
 by Dung Dang
 
 */
#include "pitches.h"


int buzzerPin = 40;

 
// notes in the melody:
int melody[] = {
  NOTE_F2, NOTE_C6, NOTE_B5, NOTE_G5, NOTE_A5, NOTE_E1, NOTE_B1, NOTE_E1, NOTE_B1, NOTE_E1, NOTE_B1, 
   
   
  NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_GS5, 
  NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_F5, NOTE_AS4, NOTE_C5, NOTE_DS5, NOTE_F5,
  
  NOTE_C6, NOTE_NOTONE, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_F5,
  NOTE_C6, NOTE_NOTONE, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_GS5, NOTE_F5,

// Repeat once   
  NOTE_C6, NOTE_NOTONE, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_F5,
  NOTE_C6, NOTE_NOTONE, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_GS5, NOTE_F5,

  NOTE_C6, NOTE_NOTONE, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_NOTONE, NOTE_DS6, NOTE_NOTONE,
  NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_NOTONE, NOTE_D6, NOTE_DS6,
  
  NOTE_C6, NOTE_NOTONE, NOTE_C6, NOTE_NOTONE, NOTE_DS6, NOTE_F6
  
  
};
   
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
2, 2, 2, 2,1, 2, 2, 2, 2, 2, 1,  // 11 start screen  notes



16, 16, 16, 16, 16, 16, 16, 16, 16, 16,  // 20  notes
16, 16, 16, 16, 16, 16, 16, 2,           // for both lines   

16, 16, 16, 8, 16, 2, 2,                  // 7
16, 16, 16, 8, 16, 2, 2,                  // 7

// Repeat once
16, 16, 16, 8, 16, 2, 2,                  // 7
16, 16, 16, 8, 16, 2, 2,                  // 7

16, 16, 4, 4, 16, 16, 16, 8,             // 8
16, 16, 16, 16, 16, 4, 4,                  // 7

16, 16, 16, 16, 16, 4                     // 6 

};

void setup() 
{
pinMode(buzzerPin,OUTPUT);
}
void loop() 
{
  for (int thisNote = 0; thisNote < 80; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    // Had to down tempo to 100/150 
    int noteDuration = 1500/noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration + 50;      //delay between pulse
    delay(pauseBetweenNotes);
    
    noTone(buzzerPin);                // stop the tone playing
  }
}

