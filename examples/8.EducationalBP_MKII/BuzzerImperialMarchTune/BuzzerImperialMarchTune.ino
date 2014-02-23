/*
 Educational BoosterPack MK II - Imperial March Tune
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 

 Based on the Imperial March implementation on MSP430 LaunchPad
 posted here http://processors.wiki.ti.com/index.php/Playing_The_Imperial_March
 Originally created for Educational BoosterPack 
 Buzzer Pin was 19
 Modified for Educational BoosterPack MK II - Dec 03 2013
 Buzzer Pin = 40

by Dung Dang
*/ 

#include "pitches.h"
#define cc 261
#define dd 294
#define ee 329
#define ff 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

int buzzerPin = 40;

void beep(int note, int duration)
{
  tone(buzzerPin, note, duration/2);
  delay(duration/2);
  noTone(buzzerPin);
  delay(duration/2 + 20);  
}
void setup() 
{
pinMode(buzzerPin,OUTPUT);
}
void loop() 
{
   beep(a, 500);
beep(a, 500);
beep(a, 500);
beep(ff, 350);
beep(cH, 150);  
beep(a, 500);
beep(ff, 350);
beep(cH, 150);
beep(a, 650);
 
    delay(150);
    //end of first bit   
 
beep(eH, 500);
beep(eH, 500);
beep(eH, 500);   
beep(fH, 350);
beep(cH, 150);
beep(gS, 500);
beep(ff, 350);
beep(cH, 150);
beep(a, 650);
 
    delay(150);
    //end of second bit...  
 
beep(aH, 500);
beep(a, 300);
beep(a, 150);
beep(aH, 400);
beep(gSH, 200);
beep(gH, 200); 
beep(fSH, 125);
beep(fH, 125);    
beep(fSH, 250);
 
    delay(250);
 
beep(aS, 250); 
beep(dSH, 400); 
beep(dH, 200);  
beep(cSH, 200);  
beep(cH, 125);  
beep(b, 125);  
beep(cH, 250);  
 
    delay(250);
 
beep(ff, 125);  
beep(gS, 500);  
beep(ff, 375);  
beep(a, 125);
beep(cH, 500);
beep(a, 375);  
beep(cH, 125);
beep(eH, 650);

 
beep(aH, 500);
beep(a, 300);
beep(a, 150);
beep(aH, 400);
beep(gSH, 200);
beep(gH, 200);
beep(fSH, 125);
beep(fH, 125);    
beep(fSH, 250);
 
    delay(250);
 
beep(aS, 250);  
beep(dSH, 400);  
beep(dH, 200);  
beep(cSH, 200);  
beep(cH, 125);  
beep(b, 125);  
beep(cH, 250);      
 
    delay(250);
 
beep(ff, 250);  
beep(gS, 500);  
beep(ff, 375);  
beep(cH, 125);
beep(a, 500);   
beep(ff, 375);   
beep(cH, 125); 
beep(a, 650);   
    //end of the song
    //end of the song
}

