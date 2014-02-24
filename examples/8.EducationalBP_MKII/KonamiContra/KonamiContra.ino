/* 
 Educational BoosterPack MK II - Konami/Contra Cheat Code
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Use Joystick & Push buttons to enter the 'secret' Konami/Contra Cheat Code
 Blue LED lights up when correct code is entered.
 Use Serial Monitor window to debug/follow statemachine
 
 Feb 2014 - Initial version created for Edu BP MK II
            
 by Dung Dang
 
 */

//Joystick
const int JOY_X = 2;
const int JOY_Y = 26;
const int JOY_SEL = 5; //Substitute for the Start button

//Push Button/Switch
const int BUTTON_A = 33;
const int BUTTON_B = 32;

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
      pinMode(37, OUTPUT);
      digitalWrite(37, 1);
      while(1);
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
