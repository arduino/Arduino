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

#define note_cc 261
#define note_dd 294
#define note_ee 329
#define note_ff 349
#define note_g 391
#define note_gS 415
#define note_a 440
#define note_aS 455
#define note_b 466
#define note_cH 523
#define note_cSH 554
#define note_dH 587
#define note_dSH 622
#define note_eH 659
#define note_fH 698
#define note_fSH 740
#define note_gH 784
#define note_gSH 830
#define note_aH 880

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
  beep(note_a, 500);
  beep(note_a, 500);
  beep(note_a, 500);
  beep(note_ff, 350);
  beep(note_cH, 150);  
  beep(note_a, 500);
  beep(note_ff, 350);
  beep(note_cH, 150);
  beep(note_a, 650);

  delay(150);
  //end of first bit   

  beep(note_eH, 500);
  beep(note_eH, 500);
  beep(note_eH, 500);   
  beep(note_fH, 350);
  beep(note_cH, 150);
  beep(note_gS, 500);
  beep(note_ff, 350);
  beep(note_cH, 150);
  beep(note_a, 650);

  delay(150);
  //end of second bit...  

  beep(note_aH, 500);
  beep(note_a, 300);
  beep(note_a, 150);
  beep(note_aH, 400);
  beep(note_gSH, 200);
  beep(note_gH, 200); 
  beep(note_fSH, 125);
  beep(note_fH, 125);    
  beep(note_fSH, 250);

  delay(250);

  beep(note_aS, 250); 
  beep(note_dSH, 400); 
  beep(note_dH, 200);  
  beep(note_cSH, 200);  
  beep(note_cH, 125);  
  beep(note_b, 125);  
  beep(note_cH, 250);  

  delay(250);

  beep(note_ff, 125);  
  beep(note_gS, 500);  
  beep(note_ff, 375);  
  beep(note_a, 125);
  beep(note_cH, 500);
  beep(note_a, 375);  
  beep(note_cH, 125);
  beep(note_eH, 650);


  beep(note_aH, 500);
  beep(note_a, 300);
  beep(note_a, 150);
  beep(note_aH, 400);
  beep(note_gSH, 200);
  beep(note_gH, 200);
  beep(note_fSH, 125);
  beep(note_fH, 125);    
  beep(note_fSH, 250);

  delay(250);

  beep(note_aS, 250);  
  beep(note_dSH, 400);  
  beep(note_dH, 200);  
  beep(note_cSH, 200);  
  beep(note_cH, 125);  
  beep(note_b, 125);  
  beep(note_cH, 250);      

  delay(250);

  beep(note_ff, 250);  
  beep(note_gS, 500);  
  beep(note_ff, 375);  
  beep(note_cH, 125);
  beep(note_a, 500);   
  beep(note_ff, 375);   
  beep(note_cH, 125); 
  beep(note_a, 650);   
  //end of the song
}


