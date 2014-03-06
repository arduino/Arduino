/* 
 Educational BoosterPack MK II - Konami/Contra Intro
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 
 Use Joystick & Push buttons to enter the 'secret' Konami/Contra Cheat Code
 When correct code is entered:
 - Play Konami/Contra Intro through the buzzer, demonstrating
   buzzer tune() API and pitch/tone/simple music generation
 - Blue LED lights up  
 
 Use Serial Monitor window to debug/follow statemachine
 
 Feb 2014 - Initial version created for Edu BP MK II
            
            
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


//Joystick
const int JOY_X = 2;
const int JOY_Y = 26;
const int JOY_SEL = 5; //Substitute for the Start button

//Push Button/Switch
const int BUTTON_A = 33;
const int BUTTON_B = 32;
const int RGB_BLUE_LED = 37;

int statemachine = 0;

int pressedLeft(void);
int pressedRight(void);
int pressedUp(void);
int pressedDown(void);
int pressedA(void);
int pressedB(void);
int pressedStart(void);

void setup()
{
  // put your setup code here, to run once:
  statemachine =0;
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_A, INPUT);
  pinMode(JOY_SEL, INPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(RGB_BLUE_LED, OUTPUT);
  digitalWrite(RGB_BLUE_LED, 0);
  Serial.begin(115200);
}


void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print("State Machine = ");
  Serial.println(statemachine);
  switch (statemachine)
  {
      
    //---UP---
    case 0:        
      if (pressedUp())       //JoyStick Up
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;
      
    //---UP---      
    case 1:      
      if (pressedUp())       //JoyStick Up
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;
      
    //---DOWN---
    case 2:        
      if (pressedDown())       //JoyStick Down
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;
    //---DOWN---      
    case 3:         
      if (pressedDown())       //JoyStick Down
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;  
      
    //---LEFT---           
    case 4:        
      if (pressedLeft())       //JoyStick left
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;
    //---RIGHT---             
    case 5: // Waiting for Right       
      if (pressedRight())       //JoyStick right
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;
    //---LEFT---           
    case 6:        
      if (pressedLeft())       //JoyStick left
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break;
    //---RIGHT---             
    case 7: // Waiting for Right       
      if (pressedRight())       //JoyStick right
        if (backToCenter())    // Then back to center
          statemachine++;  
        else
          statemachine = 0;
      else
        statemachine = 0;  
      break; 

    //---BUTTON_B---             
    case 8: // Waiting for Right       
      delay(300);
      if (pressedB())       //Button B
          statemachine++;  
      else
          statemachine = 0;
      break; 

    //---BUTTON_A---             
    case 9: // Waiting for Right       
      if (pressedA())       //Button A
          statemachine++;  
      else
          statemachine = 0;
      break; 
      
    //---START---             
    
    case 10: // Waiting for Start       
      if (pressedStart())       //JoyStick Start
          statemachine++;  
      else
          statemachine = 0;
      break; 
    case 11:      
      digitalWrite(RGB_BLUE_LED, 1);
	  for (int thisNote = 0; thisNote < 80; thisNote++) 
	  {

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
	  digitalWrite(RGB_BLUE_LED, 0);
	  statemachine = 0;				      // Reset statemachine
      break;
  }
  
}


int pressedLeft(void)
{
  uint8_t pass  = 1;
  while ( (analogRead(JOY_X)>0) && (pass==1) )
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_A) == 0) || 
         (digitalRead(BUTTON_B) == 0) ||
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;
      
    if ( (analogRead(JOY_Y)<10) || (analogRead(JOY_Y) >  4050) )
      pass = 0;    
    
  }  
  return pass;  
}
int pressedRight(void)
{
  uint8_t pass  = 1;
  while ( (analogRead(JOY_X)<4094) && (pass==1))
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_A) == 0) || 
         (digitalRead(BUTTON_B) == 0) ||
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;
      
    if ( (analogRead(JOY_Y)<10) || (analogRead(JOY_Y) >  4050) )
      pass = 0;    
    
  }  
  return pass;  
}


int pressedDown(void)
{
  uint8_t pass  = 1;
  while ( (analogRead(JOY_Y)>0) && (pass==1))
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_A) == 0) || 
         (digitalRead(BUTTON_B) == 0) ||
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;
      
    if ( (analogRead(JOY_X)<10) || (analogRead(JOY_X) >  4050) )
      pass = 0;    
    
  }  
  return pass;  
}
int pressedUp(void)
{
  uint8_t pass  = 1;
  while ( (analogRead(JOY_Y)<4094) && (pass==1))
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_A) == 0) || 
         (digitalRead(BUTTON_B) == 0) ||
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;
      
    if ( (analogRead(JOY_X)<10) || (analogRead(JOY_X) >  4050) )
      pass = 0;    
    
  }  
  return pass;  
}

int backToCenter(void)
{
  uint8_t pass  = 1;
  while ( ( (analogRead(JOY_X)>2200) || 
            (analogRead(JOY_X)<1800) || 
            (analogRead(JOY_Y)>2200) || 
            (analogRead(JOY_Y)<1800)    ) 
          && (pass==1) )
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_A) == 0) || 
         (digitalRead(BUTTON_B) == 0) ||
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;    
  }  
  return pass;  
}

int pressedA(void)
{
  uint8_t pass  = 1;
  while (  (digitalRead(BUTTON_A)==1) &&
           (pass==1) )
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_B) == 0) ||          
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;    
    if ( (analogRead(JOY_X)>4050) || 
            (analogRead(JOY_X)<10) || 
            (analogRead(JOY_Y)>4050) || 
            (analogRead(JOY_Y)<10)    ) 
      pass = 0;  
  }  
  if (pass)
    while (digitalRead(BUTTON_A)==0); //Wait until button is released
    
  return pass;    
}

int pressedB(void)
{
  uint8_t pass  = 1;
  while (  (digitalRead(BUTTON_B)==1) &&
           (pass==1) )
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_A) == 0) ||          
         (digitalRead(JOY_SEL) == 0) )         
      pass = 0;    
    if ( (analogRead(JOY_X)>4050) || 
            (analogRead(JOY_X)<10) || 
            (analogRead(JOY_Y)>4050) || 
            (analogRead(JOY_Y)<10)    ) 
      pass = 0;  
  }  
  if (pass)
    while (digitalRead(BUTTON_B)==0); //Wait until button is released
  
  return pass;    
}

int pressedStart(void)
{
  uint8_t pass  = 1;
  while (  (digitalRead(JOY_SEL)==1) &&
           (pass==1) )
  {
    // Ensure no other buttons/joystick directions are pressed
    if ( (digitalRead(BUTTON_B) == 0) ||          
         (digitalRead(BUTTON_A) == 0) )         
      pass = 0;    
    if ( (analogRead(JOY_X)>4050) || 
            (analogRead(JOY_X)<10) || 
            (analogRead(JOY_Y)>4050) || 
            (analogRead(JOY_Y)<10)    ) 
      pass = 0;   
  }  
  if (pass)
    while (digitalRead(JOY_SEL)==0); //Wait until button is released

  return pass;    
}
