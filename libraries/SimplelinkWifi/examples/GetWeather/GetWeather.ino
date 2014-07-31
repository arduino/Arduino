/*
 Reading api.openweathermap.org
 
 This sketch connects to api.openweathermap.org using LaunchPad + CC3000 BoosterPack. 
 It parses the XML returned, and looks for temp, humidity & time of last update.
 
 This example uses the DHCP routines in the WiFi CC3000 library. This example was created 
 in Energia version 11
 
 This example uses the String library, which is part of the Energia core.

 This example uses the Serial monitor to display de results of the call to openweathermap.
 
 To see the XML that the LaunchPad is parsing through, go to the URL below with your browser:
 http://api.openweathermap.org/data/2.5/weather?q=Dallas,TX&mode=xml&units=imperial
 
 Circuit:
 * CC3000 WiFi BoosterPack
 * TI LaunchPad (Either MSP-EXP430F5529LP or EK-TM4F123GXL)
  
 This code is in the public domain.
 
 */
#include "SPI.h"
#include "WiFi.h"

char ssid[] = "WIFI_SSID";     //  your network SSID (name) 
char pass[] = "WIFI_PASS";     //  your network password 
String location = "Dallas, TX"; // your desired location


// initialize the library instance:
WiFiServer server(80);
WiFiClient client;

const unsigned long requestInterval = 60000;  // delay between requests (1 min)

IPAddress hostIp;
uint8_t ret;
boolean requested;                   // whether you've made a request since connecting
unsigned long lastAttemptTime = 0;            // last time you connected to the server, in milliseconds
String currentLine = "";        // string to hold the text from server
String tempString = "";         // string to hold temp
String humString = "";          // string to hold humidity
String timeString = "";         // string to hold timestamp
String pressureString = "";
boolean readingTemp = false;    // if you're currently reading the temp
boolean readingHum = false;     // if you're currently reading the humidity
boolean readingTime = false;    // if you're currently reading the timestamp
boolean readingPressure = false; 
int temp = 0;

void setup() {
  // reserve space for the strings:
  currentLine.reserve(100);
  tempString.reserve(10);
  humString.reserve(10);
  timeString.reserve(20);
  Serial.begin(115200);    
  
  // Setup pins of CC3000 BoosterPack
  WiFi.setCSpin(18);  // 18: P2_2 @ F5529, PE_0 @ LM4F/TM4C
  WiFi.setENpin(2);   //  2: P6_5 @ F5529, PB_5 @ LM4F/TM4C
  WiFi.setIRQpin(19); // 19: P2_0 @ F5529, PB_2 @ LM4F/TM4C
  
  delay(10);
  // Connect to an AP with WPA/WPA2 security
  Serial.println("Connecting to WiFi....");  
  WiFi.begin(ssid, pass);  // Use this if your wifi network requires a password
  //WiFi.begin(ssid);    // Use this if your wifi network is unprotected.
  
  server.begin();
  Serial.println("Connect success!");
  Serial.println("Waiting for DHCP address");
  // Wait for DHCP address
  while(WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\n");
  // Print WiFi status and DHCP address
  // To print the status and DHCP info again, type "i" in the Serial monitor and press send.
  printWifiData();

  // connect to api.openweathermap.org:
  connectToServer();

}

void loop()
{
  if (client.connected()) {
    while (client.available()) {
      // read incoming bytes:
      char inChar = client.read();
      // add incoming byte to end of line:
      currentLine += inChar; 
      // if you get a newline, clear the line:
      //Serial.println("trying to parse...");

      if (inChar == '\n') {
        //Serial.print("clientReadLine = ");
        //Serial.println(currentLine);
        currentLine = "";
      } 
      
      // LOOKING FOR TEMPERATURE DATA
      // if the current line ends with <temperature value=, it will
      // be followed by the temp:
      if ( currentLine.endsWith("<temperature value=")) {
        // temperatue data is beginning. Clear the temp string:
        readingTemp = true; 
        tempString = "";
      }      
      
      // PULLING TEMPERATURE DATA
      // if you're currently reading the bytes for temperature,
      // add them to the temperature string:
      if (readingTemp) {
        if (inChar != 'm') { // if you see 'm', you're done reading temp
          tempString += inChar;
        } 
        else {
          // if you got a termination character,
          // you've reached the end of the temperature data:
          readingTemp = false;

          Serial.print("-  Temperature: ");
          Serial.print(getInt(tempString));
          Serial.println((char)176);    //degree symbol
        }
      }

      // LOOKING FOR HUMIDITY DATA
      // if the current line ends with <humidity value=, it will
      // be followed by the humidity:
      if ( currentLine.endsWith("<humidity value=")) {
        // Humidity reading is beginning. Clear the humidity string:
        readingHum = true; 
        humString = "";
      }
      
      // PULLING HUMIDITY DATA
      // if you're currently reading the bytes of humidity data,
      // add them to the humidity String:
      if (readingHum) {
        if (inChar != 'u') {// if you see 'u', you're done reading humidity
          humString += inChar;
        } 
        else {
          // if you got a termination character,
          // you've reached the end of humidity data
          readingHum = false;

          Serial.print("-  Humidity: ");
          Serial.print(getInt(humString));
          Serial.println((char)37);    //percent sign
        }
      }
      
      // LOOKING FOR TIMESTAMP
      // if the current line ends with <lastupdate value=, it will
      // be followed by the timestamp:
      if ( currentLine.endsWith("<lastupdate value=")) {
        // timestamp is beginning. Clear the timestamp string:
        readingTime = true; 
        timeString = "";
      }
      
      // PULLING TIMESTAMP DATA
      // if you're currently reading the bytes of timestamp,
      // add them to the timestamp String:
      if (readingTime) {
        if (inChar != '/') { // if you see '/', you're done reading timestamp
          timeString += inChar;
        } 
        else {
          // if you got a termination character,
          // you've reached the end of the timestamp:
          readingTime = false;

          Serial.print("-  Last update: ");
          Serial.println(timeString.substring(2,timeString.length()-1));
        }
      }

      // LOOKING FOR PRESSURE DATA
      // if the current line ends with <pressure value=, it will
      // be followed by the temp:
      if ( currentLine.endsWith("<pressure value=")) {
        // Pressure data is beginning. Clear the pressure string:
        readingPressure = true; 
        pressureString = "";
      }      
      
      // PULLING TEMPERATURE DATA
      // if you're currently reading the bytes for temperature,
      // add them to the temperature string:
      if (readingPressure) {
        if (inChar != 'u') { // if you see 'm', you're done reading temp
          pressureString += inChar;
        } 
        else {
          // if you got a termination character,
          // you've reached the end of the temperature data:
          readingPressure = false;

          Serial.print("-  Pressure: ");
          Serial.print(getInt(pressureString));
          Serial.println("hPa");    //Pressure unit
        }
      }

      
      // if the current line ends with </current>, 
      // we have reached the end of the client data:
      if ( currentLine.endsWith("</current>")) {
          // close the connection to the server:
          client.stop(); 
          Serial.println("Disconnected from Server.\n");
      }
      
    }   
    
  }
  else if (millis() - lastAttemptTime > requestInterval) {
    // if you're not connected, and request interval time have passed since
    // your last connection, then attempt to connect again to get new data:
    connectToServer();
  }
}

void connectToServer() {
  // attempt to connect, and wait a millisecond:
  Serial.println("connecting to server...");
  String content = "";
  if (client.connect(hostIp, 80)) {
    Serial.println("Connected! Making HTTP request to api.openweathermap.org for "+location+"...");
    Serial.println("GET /data/2.5/weather?q="+location+"&mode=xml&units=imperial");

    // make HTTP GET request to Facebook:
    client.println("GET /data/2.5/weather?q="+location+"&mode=xml&units=imperial HTTP/1.1"); 

    // declare correct server
    client.print("HOST: api.openweathermap.org\n");
    client.println("User-Agent: launchpad-wifi");
    client.println("Connection: close");

    client.println();
    Serial.println("Weather information for "+location);
  }
  // note the time of this connect attempt:
  lastAttemptTime = millis();
}


void printHex(int num, int precision) {
      char tmp[16];
      char format[128];

      sprintf(format, "%%.%dX", precision);

      sprintf(tmp, format, num);
      Serial.print(tmp);
}

void printWifiData() {
  // print your WiFi shield's IP address:
  Serial.println();
  Serial.println("IP Address Information:");  
  IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
  Serial.println(ip);
  
  // print your MAC address:
  byte mac[6];  
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printHex(mac[5], 2);
  Serial.print(":");
  printHex(mac[4], 2);
  Serial.print(":");
  printHex(mac[3], 2);
  Serial.print(":");
  printHex(mac[2], 2);
  Serial.print(":");
  printHex(mac[1], 2);
  Serial.print(":");
  printHex(mac[0], 2);
  Serial.println();
  
  uint8_t *ver = WiFi.firmwareVersion();
  Serial.print("Version: ");
  Serial.print(ver[0]);
  Serial.print(".");
  Serial.println(ver[1]);  
  // print your subnet mask:
  IPAddress subnet = WiFi.subnetMask();
  Serial.print("NetMask: ");
  Serial.println(subnet);

  // print your gateway address:
  IPAddress gateway = WiFi.gatewayIP();
  Serial.print("Gateway: ");
  Serial.println(gateway);
  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  
  ret = WiFi.hostByName("api.openweathermap.org", hostIp);
    
  Serial.print("ret: ");
  Serial.println(ret);
  
  Serial.print("Host IP: ");
  Serial.println(hostIp);
  Serial.println("");
}

int getInt(String input){  // This function converts String to Integer.
// This allows you to perform math on the string data we extracted from XML.
  int i = 2;
  
  while(input[i] != '"'){
    //Serial.print(i); Serial.print("=");
    //Serial.println(input[i]);
    i++;
  }
  input = input.substring(2,i);
  char carray[20];
  //Serial.println(input);
  input.toCharArray(carray, sizeof(carray));
  //Serial.println(carray);
  temp = atoi(carray);
  //Serial.println(temp);
  return temp;
}
