/* 
 Educational BoosterPack MK II - Birthday Tune
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Play birthday tune through the buzzer, demonstrating
 buzzer tune() API and pitch/tone (hence music) generation
 
 Dec 2012 - Created for Educational BoosterPack
            buzzer Pin = 19
 Dec 2013 - Modified for Educational BoosterPack MK II
            buzzer Pin = 40
 by Dung Dang
 
 */
#include "pitches.h"
#define NOTE_C4_1 260

int buzzerPin = 40;

// notes in the melody:
int melody[] = {
   NOTE_C4_1,NOTE_C4, NOTE_D4, NOTE_C4,NOTE_F4,NOTE_E4,
   NOTE_C4_1,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_F4,
   NOTE_C4_1,NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_F4, NOTE_E4,NOTE_D4,
   NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_F4};
   
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 2,2,1,
  4, 4, 2, 2,2,1,
  4, 4, 2, 2,4,4,2,1, 
  4, 4, 2, 2,2,1};

void setup() 
{
pinMode(buzzerPin,OUTPUT);
}
void loop() 
{
  for (int thisNote = 0; thisNote < 26; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration + 50;      //delay between pulse
    delay(pauseBetweenNotes);
    
    noTone(buzzerPin);                // stop the tone playing
  }
}

