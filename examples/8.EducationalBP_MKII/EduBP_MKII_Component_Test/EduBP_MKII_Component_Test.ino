
#include "pitches.h"
#include <Wire.h>
#include <tmp006.h>
#include "OPT3001.h"
#define USE_USCI_B1 
#define USING_MSP430F5529_LAUNCHPAD
//#define USING_TIVA_C_LAUNCHPAD

//-----For now, analog pin definitions are different
//----between MSP430 & Tiva LaunchPads




const int JOY_X = 2;
const int JOY_Y = 26;
const int SEL = 5;

//MIC
const int MIC = 6;

//ACCELEROMETER
const int ACC_X = 23;
const int ACC_Y = 24;
const int ACC_Z = 25;


//SWITCHES
const int SW1 = 33;
const int SW2 = 32;

//BUZZER
const int BUZZ = 40;



//RGB LED
const int RGB_RED = 39;
const int RGB_GRN = 38;
const int RGB_BLU = 37;

//TMP006
float tempReading = 0;

// notes in the melody:
#define NOTE_C4_1 260

// OPT3001
opt3001 opt3001;
tmp006 tmp006;
unsigned long readings = 0;

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
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(300);
  pinMode(SEL, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.println("Welcome to the Educational BoosterPack MKII Production Test:");

  tmp006.begin(EIGHT_SAMPLES);  // Takes 8 averaged samples for measurement
  opt3001.begin(); 
}

void loop()
{
  int16_t i;
  // put your main code here, to run repeatedly:
  
  //Test out the joystick
  Serial.print("Push joystick all the way to the right.");
  while(analogRead(JOY_X)<4094);
  Serial.println(" > Passed!");
  Serial.print("Push joystick all the way to the left.");
  while(analogRead(JOY_X)>0);
  Serial.println(" > Passed!");
  Serial.print("Push joystick all the way to the top.");
  while(analogRead(JOY_Y)<4094);
  Serial.println(" > Passed!");
  Serial.print("Push joystick all the way to the bottom.");
  while(analogRead(JOY_Y)>0);
  Serial.println(" > Passed!");
  Serial.print("Click down on the joystick.");
  while(digitalRead(SEL) == 1);
  Serial.println(" > Passed!");

  
  //Test out the microphone
  Serial.print("Rub on the microphone.");
  while(analogRead(MIC) > 100);
  Serial.println(" > Passed!");

  //Test out button 1
  Serial.print("Press button S1.");
  while(digitalRead(SW1) == 1);
  Serial.println(" > Passed!");

  //Test out button 2
  Serial.print("Press button S2.");
  while(digitalRead(SW2) == 1);
  Serial.println(" > Passed!");
  
  //Test out buzzer
  Serial.println("Press button S1 & S2 at the same time to run the buzzer test.");
  while(digitalRead(SW2) == 1 || digitalRead(SW1) == 1);
  Serial.println("Playing melody.");
  for (int thisNote = 0; thisNote < 26; thisNote++) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(BUZZ, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration + 50;      //delay between pulse
    delay(pauseBetweenNotes>>2);
    noTone(BUZZ);                // stop the tone playing
  }
  Serial.print("Press SW1 if you heard the melody.");
  while(digitalRead(SW1) == 1);
  Serial.println(" > Passed!");
  
  
  //Test out 3-axis analog accelerometer
  // 1200 ~ -1G / 2000 ~ 0G / 2800 ~ +1G
  Serial.print("Lay LaunchPad flat on table.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) < 2700);
  Serial.println(" > Passed!");
  
  Serial.print("Tilt LaunchPad all the way to the left.");
  while(analogRead(ACC_X) > 1350 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) > 2100 || analogRead(ACC_Z) < 1900);
  Serial.println(" > Passed!");

  Serial.print("Lay LaunchPad flat on table.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) < 2700);
  Serial.println(" > Passed!");

  Serial.print("Tilt LaunchPad all the way to the right.");
  while(analogRead(ACC_X) < 2650 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) > 2100 || analogRead(ACC_Z) < 1900);
  Serial.println(" > Passed!");

  Serial.print("Lay LaunchPad flat on table.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) < 2700);
  Serial.println(" > Passed!");

  Serial.print("Tilt LaunchPad away from you.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2000 || analogRead(ACC_Y) < 2600 || analogRead(ACC_Z) < 1900 || analogRead(ACC_Z) > 2100);
  Serial.println(" > Passed!");
  
  Serial.print("Lay LaunchPad flat on table.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) < 2700);
  Serial.println(" > Passed!");

  Serial.print("Tilt LaunchPad towards you.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 1450 || analogRead(ACC_Z) < 1900 || analogRead(ACC_Z) > 2100);
  Serial.println(" > Passed!");
  
  Serial.print("Lay LaunchPad flat on table.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) < 2700);
  Serial.println(" > Passed!");
  
  Serial.print("Flip LaunchPad upside down so display is facing the surface of table.");
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) > 1300);
  Serial.println(" > Passed!");
  
  //TEST TMP006 TEMP SENSOR
  Serial.println("Press SW1 to test the TMP006.");
  while(digitalRead(SW1) == 1);
  float temp = tmp006.getTemp();
  Serial.print("Temp Reading = ");
  Serial.print(temp);
  Serial.println("*C    ");    


  
  //TEST OPT3001 LIGHT SENSOR
  //To be enabled once OPT3001 is added to future Edu BP MK II Rev.
  // Serial.println("Cover the light sensor to test the OPT3001.");
  // while(opt3001.readResult() > 30);
  // Serial.println("Shine flashlight onto the light sensor ");
  // while(opt3001.readResult() < 1000);
  
  // Serial.println("OPT3001 testing successful!");
  
  //TEST RGB LED
  Serial.println("Press SW1 to test the RGB LED.");
  while(digitalRead(SW1) == 1);
  i = 0;
  int brightness = 0;
  int fadeAmount = 5;
  
  for(brightness = 0; brightness<255; brightness+=fadeAmount){
    analogWrite(RGB_RED, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  for(brightness = 255; brightness>=0; brightness-=fadeAmount){
    analogWrite(RGB_RED, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }  
  for(brightness = 0; brightness<255; brightness+=fadeAmount){
    analogWrite(RGB_GRN, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  for(brightness = 255; brightness>=0; brightness-=fadeAmount){
    analogWrite(RGB_GRN, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }  
  for(brightness = 0; brightness<255; brightness+=fadeAmount){
    analogWrite(RGB_BLU, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  for(brightness = 255; brightness>=0; brightness-=fadeAmount){
    analogWrite(RGB_BLU, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  

  Serial.println("ALL TEST SUCCESSFUL!");
  while(1);
}


