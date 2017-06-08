
/*
PINOUT:
  
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D53
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D9
3.3V            3.3V         3.3V
*/
#include "VirtuinoEsp8266_WebServer.h"
#include <SoftwareSerial.h>
#include <SPI.h>
#include <RFID.h>
#define  SDA_DIO   53 
#define  RESET_DIO 9
#define  delayRead 1000 
#define  delayLed  2000 

VirtuinoEsp8266_WebServer virtuino(Serial3,9600);



const int pirPin       =   38;
const int pir1Pin      =   39;
const int generalPin   =   22;
const int zona1Pin     =   23; 
const int resetPin     =   24;
int sirena             =   12;
int ledVerde           =    4;
int ledGiallo          =    5;
int ledRosso           =    6;
int state              = HIGH;      // the current state of the output pin
int reading;                    // the current reading from the input pin
int previous           =  LOW;
long    time           =    0;         // the last time the output pin was toggled
long debounce          =   20;   // the debounce time, increase if the output flickers
int pirState           =    0;
int pir1State          =    0;
int generalState       =    0;
int zona1State         =    0;
int resetState         =    0;

RFID RC522(SDA_DIO, RESET_DIO); 
// TAG CODE
String codiceAutorizzato1 = "40373A521F";

  
void setup()
{ 
  virtuino.DEBUG=true;
  Serial.begin(9600);
  virtuino.connectESP8266_toInternet("InfostradaWiFi-f5afa0","480a12b96b644",80); 
  virtuino.esp8266_setIP(192,168,1,120);
  virtuino.password="1234";
  SPI.begin(); 
  RC522.init();
  Serial.println("Setup");
   
  
  pinMode(pirPin, INPUT);
  pinMode(pir1Pin, INPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledGiallo,OUTPUT);
  pinMode(ledRosso,OUTPUT);
  pinMode(generalPin,INPUT);
  pinMode(zona1Pin,INPUT);
  pinMode(resetPin,INPUT);
  pinMode(sirena, OUTPUT);
}
  
void loop(){
virtuino.run();
general();
zona1();
rfid();
}
