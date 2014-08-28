/*
Copyright (c) 2014 Texas Instruments Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
/*****************************************************************************
*  @file rekam1.ino
*
*  @brief this file contains all the required functions to send and receive
*  rekam1 RPC(remote procedure calls) using the UART module.
*  @author Leonardo Estevez - Texas Instruments, Inc
*  @date August 2014
*  @version 1.0 Initial version
*  @note Built with Energia version 0101E0013b2 */

/*

  REKAM1 Virtual Machine

  This program interprets REKAM1 get, put, move, ifg/l, endif, sleep, read, and do commands and enables virtual execution of programs with up to 50 instructions. These programs 
  can set appropriate PWM values and retrieve relevant analog values with greater/less than conditions and timers. This version is specific to the Tiva C Launchpad.
  Move (pin number) (microseconds) will return capturesize samples with microsecond specified as sampling period for a given pin. By default, this runs over the USB connection but can operate 
  with any Bluetooth module connected to pins 3 and 4 Tx/Rx.
  Leo Estevez 7/14/2014
  This  code will is in the public domain.

*/

/* In order to communicate with/program the Virtual Machine via your Android Phone, download and install the .apk at github.com/leonardoestevez/Android and connect any Arduino compatbile Bluetooth
Module's Tx and Rx pins to pins 3 and 4 of your Launchpad, Connect VCC and Ground to your Launchpad and ensure the module is configured to operate at 9600 bps. */

//#define G2553 1
//#define FR5969 1
//#define TIVA 1
//#define F5529 1
//#define FR5739 1
#define CCx 1

//Uncomment these lines if using CC3200 Launchpad
#include <WiFi.h>
#include <WiFiClient.h>


#define capturesize 8 // This Determines how many samples are capture by the move command (processors with less SRAM are capable of smaller real-time captures)
#define maxcommands 25 // This determines the maximum number of commands that can be executed in a program (processors with less SRAM are capable of smaller programs)

int inByte = 0; // incoming Serial byte
String inData;
char charBuf[20];
char pinnumber[3];
char valuenumber[5];
int command = 0;
int pin = 0;
int capture[capturesize];
int i;
int value;
int commandnumb=1;
int numbcommands=1;
int commands[maxcommands];
int pins[maxcommands];
int values[maxcommands];
int execute=1;
int condition=1;
int test=512;
int symbol[2];
int pulsetime=20;




#ifdef CCx
char ssid[] = "intercom";     //  your network SSID (name)
char pass[] = "leonardo";  // your network password
uint16_t port = 1080;     // port number of the server
IPAddress server(192, 168, 43, 1);   // IP Address of the server
WiFiClient client;
int status = WL_IDLE_STATUS;     // the Wifi radio's status
#endif

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  // These Pin Modes are specific to each Launchpad and can be reconfigured here. To Use a different Launchpad/Uncomment Relevant Code here and in get/put functions
//    pinMode(2, OUTPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT); 
    pinMode(9, OUTPUT); 
    pinMode(10, OUTPUT); 
    pinMode(11, OUTPUT); 
    pinMode(14, OUTPUT);
    pinMode(PUSH2, INPUT_PULLUP);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);

#ifdef CCx
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int tries = 0;
  while ( status != WL_CONNECTED) {
    status = WiFi.status();
    // wait .1 seconds for connection:
    delay(100);
    Serial.print(".");
    if (tries++ > 100) {
      Serial.println("Couldn't connect to your wifi network");
      Serial.println("check your ssid and password.");
      while(1);
    }
  }

  // you're connected now, so print out the data:
  Serial.println("\nYou're connected to the network");
  IPAddress empty(0,0,0,0);
  while (WiFi.localIP() == empty); //wait for IP assignment
  
  // attempt to connect to the server
  Serial.println("Attempting to connect to server");
  tries = 0;
  while (client.connect(server, port) == false) {
    Serial.print(".");
    if (tries++ > 100) {
      Serial.println("\nThe server isn't responding");
      while(1);
    }
    delay(100);
  } 
#endif
#ifdef FR5739
    pinMode(PUSH1, INPUT_PULLUP);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED5, OUTPUT);
    pinMode(LED6, OUTPUT);
    pinMode(LED7, OUTPUT);
    pinMode(LED8, OUTPUT);
    pinMode(16, INPUT);
    pinMode(17, INPUT);
    pinMode(18, INPUT);
    pinMode(19, INPUT);
    pinMode(21, INPUT);
    pinMode(30, OUTPUT);
    test=1023;
#endif     
#ifdef FR5969    
    pinMode(P4_6, OUTPUT);
    pinMode(P1_0, OUTPUT);
    pinMode(P4_5, INPUT_PULLUP);
    pinMode(P1_1, INPUT_PULLUP);
#endif   
#ifdef TIVA
    pinMode(31, INPUT_PULLUP); 
    pinMode(30, OUTPUT); 
    pinMode(40, OUTPUT);
#endif
#ifdef F5529

#endif
   establishContact(); // send a byte to establish contact until receiver responds 
}

void help(int pin){
    Serial.println("Represents all Launchpads EXCEPT FR5739");
        delay(50);
    Serial.println("PIN0 SYMBOL");
        delay(50);
    Serial.println("PIN1 VCC/SYMBOL"); 
        delay(50);
    Serial.println("PIN2 OUTPUT");
    delay(50);
    Serial.println("PIN3 UART RX/SYMBOL");
        delay(50);
    Serial.println("PIN4 UART TX/SYMBOL");
        delay(50);
    Serial.println("PIN5 INPUT_PULLUP");
        delay(50);
    Serial.println("PIN6 OUTPUT");
        delay(50);
    Serial.println("PIN7 OUTPUT");
        delay(50);
    Serial.println("PIN8 OUTPUT"); 
        delay(50);
    Serial.println("PIN9 OUTPUT"); 
        delay(50);
    Serial.println("PIN10 OUTPUT");
    delay(50); 
    Serial.println("PIN11 OUTPUT"); 
        delay(50);
    Serial.println("PIN12 OUTPUT"); 
        delay(50);
    Serial.println("PIN13 OUTPUT"); 
        delay(50);
    Serial.println("PIN14 OUTPUT");
        delay(50);
    Serial.println("PIN15 OUTPUT");
    delay(50);
    Serial.println("PIN16 RESET"); 
        delay(50);
    Serial.println("PIN17 OUTPUT"); 
        delay(50);
    Serial.println("PIN18 OUTPUT"); 
        delay(50);
    Serial.println("PIN19 OUTPUT");
        delay(50);
    Serial.println("PIN20 GROUND");
    delay(50);
    Serial.println("Supported commands: read,do,get,put(x),move,if(x),sleep,endif where x = +,-,*,/,g,l, or p");
        delay(50);
    Serial.println("Default pulse period is 20ms. Use putp pin period to change.");
        delay(50);
    Serial.println("To change an output pin to an input pin enter: get pin");
}

// Gets an analog value from a pin 
// Any commands using pins 2 and 5 of FR5739 will stop communication with the VM
int get(int pin){ 
    if((pin==0) || (pin==1)){
      return symbol[pin];
    }else{
      int value = analogRead(pin);
      if(value==test){
        return digitalRead(pin);
      }else{
        return value;
      }
    }
}

// Puts an analog or digital value on a pin from 0 100 percent of VCC 
void put(int pin, int value){ 
      if(pin==0 || pin==1){
        symbol[pin]=value; 
      }else{ 
        value=values[commandnumb]*2.5;
        if(value<0){value=0;} 
        digitalWrite(pin,value);
        analogWrite(pin,value); 
      } 
} 

// This is generic rekam1 VM code and should be the same across all Launchpads              
void loop()
{
      while (Serial.available() > 0)
    {
        char received = Serial.read();
        inData += received;  
        // Process message when new line or carriage return character is recieved
        if(received == '\n' || received == '\r'){
          inData.toCharArray(charBuf, 20);
          if(execute){
            commandnumb=0;
          }
          if(!strncmp(charBuf,"get ",4)){
            command=1;
          }else if(!strncmp(charBuf,"put ",4)){
            command=2;
          }else if(!strncmp(charBuf,"move",4)){
            command=3;
          }else if(!strncmp(charBuf,"sleep",4)){
            command=4;
          }else if(!strncmp(charBuf,"ifg",3)){
            command=5;
          }else if(!strncmp(charBuf,"ifl",3)){
            command=6;
          }else if(!strncmp(charBuf,"endif",5)){
            command=7;
          }else if(!strncmp(charBuf,"read",4)){
            execute=0;
            numbcommands=1;
            commandnumb=1;
            command=8;
          }else if(!strncmp(charBuf,"do",2)){
            execute=1;
            commandnumb=1;
            command=8;
          }else if(!strncmp(charBuf,"?",1)){
            command=9;
          }else if(!strncmp(charBuf,"put+",4)){
            command=10;
          }else if(!strncmp(charBuf,"put-",4)){
            command=11;
          }else if(!strncmp(charBuf,"put*",4)){
            command=12;
          }else if(!strncmp(charBuf,"put/",4)){
            command=13;
          }else if(!strncmp(charBuf,"putp",4)){
            command=14;
          }
          
          Serial.print("OK\n");
          
          for(i=0;i<3;i++){
            pinnumber[i]=charBuf[i+4];
          }
           
          pin = atoi(pinnumber);
            
          for(i=0;i<5;i++){
            if(pin<10){
              valuenumber[i]=charBuf[i+6];
            }else{
              valuenumber[i]=charBuf[i+7];
            }
          }
          value=atoi(valuenumber);
          inData = ""; // Clear recieved buffer
             
          if(command!=8){

            commands[commandnumb]=command;
            pins[commandnumb]=pin;
            values[commandnumb]=value;
            numbcommands=numbcommands+1;
            if(!execute){
              commandnumb=commandnumb+1;
            }
          }
        }  
    }
    
#ifdef CCx    
  if (client.available()) {
    client.read((uint8_t*)charBuf, client.available());
    Serial.print("Received: ");
    Serial.println(charBuf);
          if(execute){
            commandnumb=0;
          }
          if(!strncmp(charBuf,"get ",4)){
            command=1;
          }else if(!strncmp(charBuf,"put ",4)){
            command=2;
          }else if(!strncmp(charBuf,"move",4)){
            command=3;
          }else if(!strncmp(charBuf,"sleep",4)){
            command=4;
          }else if(!strncmp(charBuf,"ifg",3)){
            command=5;
          }else if(!strncmp(charBuf,"ifl",3)){
            command=6;
          }else if(!strncmp(charBuf,"endif",5)){
            command=7;
          }else if(!strncmp(charBuf,"read",4)){
            execute=0;
            numbcommands=1;
            commandnumb=1;
            command=8;
          }else if(!strncmp(charBuf,"do",2)){
            execute=1;
            commandnumb=1;
            command=8;
          }else if(!strncmp(charBuf,"?",1)){
            command=9;
          }else if(!strncmp(charBuf,"put+",4)){
            command=10;
          }else if(!strncmp(charBuf,"put-",4)){
            command=11;
          }else if(!strncmp(charBuf,"put*",4)){
            command=12;
          }else if(!strncmp(charBuf,"put/",4)){
            command=13;
          }else if(!strncmp(charBuf,"putp",4)){
            command=14;
          }
          if(command!=1){
            Serial.println("OK");
            client.println("OK");
          }
          
          for(i=0;i<3;i++){
            pinnumber[i]=charBuf[i+4];
          }
           
          pin = atoi(pinnumber);
            
          for(i=0;i<5;i++){
            if(pin<10){
              valuenumber[i]=charBuf[i+6];
            }else{
              valuenumber[i]=charBuf[i+7];
            }
          }
          value=atoi(valuenumber);
          inData = ""; // Clear recieved buffer
             
          if(command!=8){

            commands[commandnumb]=command;
            pins[commandnumb]=pin;
            values[commandnumb]=value;
            numbcommands=numbcommands+1;
            if(!execute){
              commandnumb=commandnumb+1;
            }
          }
  }
  #endif
  
   if(execute && condition){  
          if(commands[commandnumb]==1){
            Serial.println(get(pins[commandnumb]));
            #ifdef CCx
            client.println(get(pins[commandnumb]));
            #endif
          }else if(commands[commandnumb]==2){
            put(pins[commandnumb],values[commandnumb]);
          }else if(commands[commandnumb]==10){
            value=get(pins[commandnumb])+values[commandnumb];
            put(pins[commandnumb],value);
          }else if(commands[commandnumb]==11){
            value=get(pins[commandnumb])-values[commandnumb];
            put(pins[commandnumb],value);
          }else if(commands[commandnumb]==12){
            value=get(pins[commandnumb])*values[commandnumb];
            put(pins[commandnumb],value);
          }else if(commands[commandnumb]==13){
            value=get(pins[commandnumb])/values[commandnumb];
            put(pins[commandnumb],value);
          }else if(commands[commandnumb]==14){
            pulsetime=values[commandnumb];
          }else if(commands[commandnumb]==3){
              if(values[commandnumb]<49){
                put(values[commandnumb],get(pins[commandnumb]));
              }else{
                 for(i=0;i<capturesize;i++){
                      delayMicroseconds(values[commandnumb]);
                      capture[i]=get(pins[commandnumb]);             
                  }
                 for(i=0;i<capturesize;i++){
                    Serial.print(capture[i]);
                    Serial.print("\n");
                }
              }

          }else if(commands[commandnumb]==4){
            delay(values[commandnumb]*pulsetime);
          }else if(commands[commandnumb]==5){
            if(get(pins[commandnumb])>values[commandnumb]){
              condition=1;
            }else{
              condition=0;
            }
          }else if(commands[commandnumb]==6){
            if(get(pins[commandnumb])<values[commandnumb]){
              condition=1;
            }else{
              condition=0;
            }
          }else if(commands[commandnumb]==9){
            help(pins[commandnumb]);
          }
            commandnumb=commandnumb+1;
            if(commandnumb>=numbcommands){
              commandnumb=1;
              condition=1;
            } 
   }else if(execute && !condition){
          if(commands[commandnumb]==7){
            condition=1;
          }
          commandnumb=commandnumb+1;
          if(commandnumb>=numbcommands){
            commandnumb=1;
            condition=1;
          } 
   }
}

void establishContact() {
  Serial.println("ENTER A COMMAND");
  while (Serial.available() <= 0) {
    Serial.println("ENTER A COMMAND"); // send an initial string
    delay(1000);
  }
}
