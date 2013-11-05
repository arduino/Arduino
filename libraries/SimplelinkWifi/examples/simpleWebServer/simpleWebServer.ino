// Enter here the name (=SSID) and password of your WiFi LAN

#define WLAN_SSID       "energia"        // cannot be longer than 32 characters!
#define WLAN_PASS       "supersecret"

 /*
  Web  Server
 
 A simple web server that shows the value of the analog and digital input pins
 using a WiFi BoosterPack.
 
 This example is written for a network using WPA encryption. For 
 WEP or WPA, change the Wifi.begin() call accordingly.
 
 Circuit:
 * WiFi BoosterPack

 Created: October 16, 2013 by Robert Wessels (http://energia.nu)
 Derived from example Sketch by Hans Scharler (http://www.iamshadowlord.com)
 
 */
 
#include "SPI.h"
#include "WiFi.h"

// Prototypes
void printConfig();
void printWifiData();
void printIndex();
void printHelp();

char ssid[] = WLAN_SSID;     //  your network SSID (name) 
char pass[] = WLAN_PASS;     //  your network SSID (name) 

WiFiServer server(80);
WiFiClient client;
int statusConfig = 0;

void setup() {
  Serial.begin(115200);    
  
  // Set communication pins for CC3000
  WiFi.setCSpin(18);  // 18: P2_2 @ F5529, PE_0 @ LM4F/TM4C
  WiFi.setENpin(2);   //  2: P6_5 @ F5529, PB_5 @ LM4F/TM4C
  WiFi.setIRQpin(19); // 19: P2_0 @ F5529, PB_2 @ LM4F/TM4C
 
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PUSH1, INPUT_PULLUP); // released = HIGH, pressed = LOW
  pinMode(PUSH2, INPUT_PULLUP);
  
  delay(10);

  // Connect to an AP with WPA/WPA2 security
  Serial.println("Connecting to WiFi....");  
  WiFi.begin(ssid, pass);
  //WiFi.begin(ssid);
  server.begin();
  Serial.println("Connect success!");
  Serial.println("Waiting for DHCP address");
  // Wait for DHCP address
  delay(5000);
  // Print WiFi status and DHCP address
  // To print the status and DHCP info again, type "i" in the Serial monitor and press send.
  printWifiData();
}

void loop() {
  client = server.available();
  
  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected

      if (client.available()) {             // if there's bytes to read from the client,    
        char c = client.read();             // read a byte, then
                                            // This lockup is because the recv function is blocking.
        Serial.print(c);
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {  
            break;         
          } 
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }     
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        if (currentLine.endsWith("GET / ")) {
          statusConfig = 0;
          printIndex();
        }
        if (currentLine.endsWith("GET /config.html ")) {
          statusConfig = 1;
          printConfig();
        }
        if (currentLine.endsWith("GET /index.html ")) {
          statusConfig = 0;
          printIndex();
        }
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /RED_LED_H")) {digitalWrite(RED_LED, HIGH);printConfig();}         
        if (currentLine.endsWith("GET /RED_LED_L")) {digitalWrite(RED_LED, LOW);printConfig();}     
        if (currentLine.endsWith("GET /GREEN_LED_H")) {digitalWrite(GREEN_LED, HIGH);printConfig();}       
        if (currentLine.endsWith("GET /GREEN_LED_L")) {digitalWrite(GREEN_LED, LOW);printConfig();}
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

void printIndex()
{
  // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  // and a content-type so the client knows what's coming, then a blank line:    
  
  client.println("HTTP/1.1 200 OK");
  
  client.println("Content-type:text/html");
  client.println();
  client.println("<html><head><title>CC3000 Energia Webpage</title></head><body align=center>");
  client.println("<h1 align=center><font color=\"red\">Welcome To CC3000 Web Server</font></h1>");
  client.println("</br><font size=\"4px\"><table border=\"0\" align=center width=1200px height=590px>");
  client.println("<tr><td align=center width=375></td><td width=450px align=left valign=\"top\">");
  
  
  client.println("<p>Using CC3000 WLAN connectivity, Web Server provides ");
  client.println("capability to remotely read and write GPIOs ");
  client.println("on/off.</p></br></br>");
  client.println("<p><a href=\"/config.html\">Click here</a> ");
  client.println("to check status and configure the board</p>");
  client.println("<td align=cneter width=375></td></tr></table></font></body></html>");
  
  client.println();

}

void printConfig()
{
  // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  // and a content-type so the client knows what's coming, then a blank line:    
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println("<html><head><title>CC3000 Energia Webpage</title></head><body align=center>");
  client.println("<h1 align=center><font color=\"red\">Welcome To CC3000 Web Server</font></h1>");
  
  // the content of the HTTP response follows the header:
  // Added: nicer buttons
  client.print("<font color='green'>GREEN_LED</font> <button onclick=\"location.href='/GREEN_LED_H'\">HIGH</button>");
  client.println(" <button onclick=\"location.href='/GREEN_LED_L'\">LOW</button><br>");
  client.print("<font color='red'>RED_LED</font> <button onclick=\"location.href='/RED_LED_H'\">HIGH</button>");
  client.println(" <button onclick=\"location.href='/RED_LED_L'\">LOW</button><br><br>");

  client.println("PUSH1 ");
  if(digitalRead(PUSH1))client.print("is HIGH<br>");
  else client.print("is LOW<br>");
  client.println("PUSH2 ");
  if(digitalRead(PUSH2))client.print("is HIGH<br>");
  else client.print("is LOW<br>");  
  
  client.println("<a href=\"/config.html\" >refresh</a> <br>");
  client.println("<a href=\"/index.html\" >home</a> <br>");
  client.println("</body></html>");
  // The HTTP response ends with another blank line:
  client.println();
  // break out of the while loop:
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    switch(inChar) {
      case 'h':
        printHelp();
        break;
      case 'i':
        printWifiData();
        break;
      default:
        Serial.println();
        Serial.println("Invalid menu option");
    }
  } 
}

void printHelp() {
  Serial.println();
  Serial.println("+++++++++++++++++++++++++++++++++++++");
  Serial.println("Help menu:");
  Serial.println("\th: This help menu");
  Serial.println("\ti: IP address information");
  Serial.println("+++++++++++++++++++++++++++++++++++++");
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

  IPAddress hostIp;
  uint8_t ret = WiFi.hostByName("google.com", hostIp);
  
  Serial.print("ret: ");
  Serial.println(ret);
  
  Serial.print("Google IP: ");
  Serial.println(hostIp);
}
