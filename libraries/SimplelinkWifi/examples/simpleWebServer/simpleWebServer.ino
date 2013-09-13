

#include "SPI.h"
#include "SimplelinkWifi.h"
#include "wifi.h"

#include "Energia.h"


char ssid[] = "energia";     //  your network SSID (name) 


WiFiServer server(80);
IPAddress serverIP(192,168,1,101);
WiFiClient client;
int statusConfig = 0;
//int checkSocket = 1;
void setup() {
  Serial.begin(9600);  
  // initialize the digital pin as an output.
  // Pin 14 has an LED connected on most Arduino boards:
  
  
  WiFi.setCSpin(P2_2);
  WiFi.setENpin(P6_5);
  WiFi.setIRQpin(P2_0);
  

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PUSH1, INPUT);
  pinMode(PUSH2, INPUT);
  
  Serial.println("connecting....");
  
  //connect to an open AP
  
  WiFi.begin(ssid);
  server.begin();

  Serial.println("connect success!");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(serverIP);

}

void loop() {
  client = server.available();
  
  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
    //delay(10);
      if (client.available()) {             // if there's bytes to read from the client,      
      //client.println();
      
        char c= client.read();             // read a byte, then
        

        //client.println();
        Serial.write(c);                    // print it out the serial monitor
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
          //printPage();              
        }
        if (currentLine.endsWith("GET /config.html ")) {
          statusConfig = 1;
          printConfig();
          //printPage();          
        }
        if (currentLine.endsWith("GET /index.html ")) {
          statusConfig = 0;
          printIndex();
          //printPage();              
        }
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /RED_LED_H")) {digitalWrite(RED_LED, HIGH);printConfig();}         
        if (currentLine.endsWith("GET /RED_LED_L")) {digitalWrite(RED_LED, LOW);printConfig();}     
        if (currentLine.endsWith("GET /GREEN_LED_H")) {digitalWrite(GREEN_LED, HIGH);printConfig();}       
        if (currentLine.endsWith("GET /GREEN_LED_L")) {digitalWrite(GREEN_LED, LOW);printConfig();}

        //int checkSocket = WiFi.countSocket;
        //if (checkSocket ==0)
        //  Serial.print("There are more than 4 sockets.");
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
  
}
void printPage()
{
  if(statusConfig == 0)
    printIndex();
  if(statusConfig == 1)
    printConfig();
}
void printIndex()
{
  //statusConfig = 0;
              // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:    

client.println();
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
            //client.println("<a target=\"_blank\" href=\"http://processors.wiki.ti.com/index.php/CC3000\">");
            //client.println("CC3000 wiki</a></br>");
            //client.println("<a target=\"_blank\" href=\"http://energia.nu/\">Energia Project</a></br>");
            client.println("<td align=cneter width=375></td></tr></table></font></body></html>");

            client.println();

}

void printConfig()
{
  //statusConfig = 1;
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:    
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<html><head><title>CC3000 Energia Webpage</title></head><body align=center>");
            client.println("<h1 align=center><font color=\"red\">Welcome To CC3000 Web Server</font></h1>");
                        //client.println("<font color=\"red\" face=\"arial\" size=\"40\">");

            // the content of the HTTP response follows the header:
            client.println("GREEN_LED <a href=\"/GREEN_LED_H\">HIGH</a> <a href=\"/GREEN_LED_L\">LOW</a><br>");
            client.println("RED_LED <a href=\"/RED_LED_H\">HIGH</a> <a href=\"/RED_LED_L\">LOW</a><br><br>");
            client.println("PUSH1 ");
            if(digitalRead(PUSH1))client.print("is HIGH<br>");
            else client.print("is LOW<br>");
            client.println("PUSH2 ");
            if(digitalRead(PUSH2))client.print("is HIGH<br>");
            else client.print("is LOW<br>");
            //client.println("<a href=\"/T\">Get the temperature.</a><br>");
            //client.println("<p>Temperature = <b id=\"");
            //client.print(analogRead(A0));

            
            client.println("<a href=\"/config.html\" >refresh</a> <br>");
            client.println("<a href=\"/index.html\" >home</a> <br>");
            //client.println("</font>");
            client.println("</body></html>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            
            
}

