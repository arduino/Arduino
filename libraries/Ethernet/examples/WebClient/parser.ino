//Author: Martin Chlebovec
//Web: https://arduino.php5.sk
//Support: http://paypal.me/chlebovec
#include <SPI.h>
#include <Ethernet.h>
int led = 6;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char serverName[] = "www.arduino.php5.sk"; // webserver
IPAddress ip(192, 168, 1, 254);
EthernetClient client;
String readString;        //our variable
int x=0; //counter of line
char lf=10; //line feed character
void setup(){
pinMode(led, OUTPUT);
 if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  Serial.begin(9600); 
}

void loop(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET rele/rele1.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //error if i am not connected
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //wait for datas
  while (client.connected() || client.available()) { //check response
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //our variable
   } 
    Serial.print("Variable: ");
    Serial.print(readString); //our variable parsed
                   if(readString=="ZAP"){
                                      digital.Write(led, HIGH);
                   }else if(readString=="VYP"){
                    digital.Write(led, LOW);
                   }else{
                   Serial.println("Unsupported variable");
                   }
  readString = ("");          //delete our variable
  x=0;                         //reset counter
  client.stop(); //end connection
  delay(5000); //wait 5 seconds and start again
} 
