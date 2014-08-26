/**
 * get host IP by hostname demo
 *
 * Type a hostname into the serial terminal
 * and the corresponding IP address will be printed
 *
 * By Noah Luskey: 2 July 2014
 */
#ifndef __CC3200R1M1RGC__
// Do not include SPI for CC3200 LaunchPad
#include <SPI.h>
#endif
#include <WiFi.h>

// your network name also called SSID
char ssid[] = "energia";
// your network password
char password[] = "launchpad";
// your network key Index number (needed only for WEP)
int keyIndex = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("**Simplelink IP by name demo**");
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid); 
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
  
  // you're connected now, so print out the status  
  printWifiStatus();
}


#define STRLEN 32
char buffer[STRLEN];
int  bufferIndex = 0; 

void loop()
{
  while(Serial.available()) {
      buffer[bufferIndex] = Serial.read();
    // is this the terminating not carriage return
    if( buffer[bufferIndex] != '\r')
    {
      // keep reading
      bufferIndex++;
      continue;
    }
    
    buffer[ bufferIndex ] = 0; // terminate the string with a 0
    bufferIndex = 0;  // reset the index ready for another string

    Serial.print("Getting IP for ");
    Serial.println(buffer);
    
    IPAddress IP(0,0,0,0);
    
    int iRet = WiFi.hostByName(buffer, IP);
    if(iRet < 0) {
      Serial.println("Host name lookup failed");
    } else {
      Serial.println(IP);
      Serial.flush();
    }
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("Network Name: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
