/**
 * get host IP by hostname demo
 *
 * Type a hostname into the serial terminal
 * and the corresponding IP address will be printed
 *
 * By Noah Luskey: 2 July 2014
 */

#include <WiFi.h>

//
//enter your network ssid and passowrd here
//
char yourSSID[] = "your network";
char yourPASS[] = "your password";


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("**Simplelink IP by name demo**");
  Serial.print("Attempting to connect to ");
  Serial.println(yourSSID);
  
  //
  //attempt to connect to the wifi network
  //change this line if your network is not WPA
  //
  WiFi.begin(yourSSID, yourPASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("\nCONNECTED");
}

void loop()
{
  //
  //if a serial command is available, read it
  //!! host name limited to 16 bytes right now
  //
  int bytes = Serial.available();
  if (bytes) {
    Serial.println(bytes);
    char nameBuf[16];
    memset(nameBuf, 0, 16);
    int i = 0;
    Serial.readBytes(nameBuf, bytes);
 
    //
    //get the ip address and print it to the serial terminal
    //
    Serial.print("Getting IP for ");
    Serial.println(nameBuf);
    
    IPAddress IP(0,0,0,0);
    int iRet = WiFi.hostByName(nameBuf, IP);
    Serial.println(IP);
    delay(1000);
    Serial.flush();
  }
}
