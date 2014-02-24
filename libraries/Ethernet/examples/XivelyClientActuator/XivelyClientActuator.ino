/*
  xively actuator client
 
 This sketch connects a LED to xively, formerly cosm/pachube.
 
 This example has been updated to use version 2.0 of the xively.com API. 
 To make it work, create a feed with a datastream, and 'actuator1'. 
 Or change the code below to match your feed channel name.
 
 Circuit:
 * D1 shows status of xively.feed.actuator1 value 
    OFF for 0
    ON  for !0
 
 created 15 March 2010
 updated 16 Mar 2012
 by Tom Igoe with input from Usman Haque and Joe Saavedra

 modified 23 Feb 2014
 by Craig Hollabaugh
 
http://arduino.cc/en/Tutorial/PachubeClient
 This code is in the public domain.
 
 */

#include <Ethernet.h>

#define APIKEY         "YOUR API KEY GOES HERE" // replace your xively api key here
#define FEEDID         00000 // replace your feed ID
#define USERAGENT      "EnergiaXivelyClient" // user agent is the project name

// assign a MAC address for the ethernet controller.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// fill in your address here:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// fill in an available IP address on your network here,
// for manual configuration:
IPAddress ip(192,168,1,177);
// initialize the library instance:
EthernetClient client;

// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(216,52,233,120);      // numeric IP for api.xively.com
//char server[] = "api.xively.com";   // name address for xively API

unsigned long lastConnectionTime = 0;          // last time you connected to the server, in milliseconds
boolean lastConnected = false;                 // state of the connection last time through the main loop
const unsigned long postingInterval = 10*1000; //delay between updates to xively.com

char  response[1600]; // something greater than MTU
char* responsePtr;

char  channel[] = "actuator1";

void setup() {
  // start serial port:
  Serial.begin(9600);
  Serial.println("XivelyClientActuator setup");
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // DHCP failed, so use a fixed IP address:
    Ethernet.begin(mac, ip);
  }
  // print your local IP address:
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
  }
  Serial.println();
  pinMode(D1_LED,OUTPUT);
  digitalWrite(D1_LED,LOW);
  sendRequest();
}

void loop() {
  // if there's incoming data from the net connection, process it
  if (client.available()) {
    responseProcess();
  }

  // if there's no net connection, but there was one last time
  // through the loop, then stop the client:
  if (!client.connected() && lastConnected) {
    client.stop();
  }

  // if you're not connected, and ten seconds have passed since
  // your last connection, then connect again and send data:
  if(!client.connected() && (millis() - lastConnectionTime > postingInterval)) {
    sendRequest();
  } 
    
  // store the state of the connection for next time through
  // the loop:
  lastConnected = client.connected();
}

void responseProcess() {
  // the entire HTTP server response is in the client buffer
  char c;

  responsePtr = &response[0];
  while (client.available()) {
    c = client.read();
    *responsePtr++ = c;
  }
  *responsePtr = 0; // terminate the string
  client.stop(); // close the http connection
  //response Serial.println(response);
  responseParse();
}

void responseParse() {
/* response looks like this
requesting from api.xively.com
HTTP/1.1 200 OK
Date: Mon, 24 Feb 2014 00:26:20 GMT
Content-Type: text/plain; charset=utf-8
Content-Length: 79
Connection: keep-alive
X-Request-Id: 3673d93d7435c340b779c0128fc39d44be3f3e21
Cache-Control: max-age=86400
Last-Modified: Sun, 23 Feb 2014 17:31:08 GMT
Age: 20301
Vary: Accept-Encoding

actuator1,2014-02-23T17:31:08.290073Z,1
sensor1,2014-02-21T06:58:34.565599Z,373
*/

  char *token,*field;

  // walking the response lines
  token = strtok(&response[0],"\n");
  while( token != NULL ) {
    if (strstr(token,channel) != 0) { // is token on the csv line with channel desired?
      Serial.println(token);
      // token is now pointing at correct line, need to skip 2 commas
      field = strtok(token,","); // field pointing at channel
      field = strtok(NULL,",");  // field pointing at timestamp
      field = strtok(NULL,",");  // field pointing at channel value as ascii
      if (field[0] == '0') {
        digitalWrite(D1_LED,LOW);
      } else {
        digitalWrite(D1_LED,HIGH);
      }
      return;
    }
    token = strtok(NULL,"\n");
  }
}

// this method makes a HTTP GET feed request to the server:
void sendRequest() {
  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("requesting from api.xively.com");
    // send the HTTP GET request:
    client.print("GET /v2/feeds/");
    client.print(FEEDID);
    client.println(".csv HTTP/1.1");
    client.println("Host: api.xively.com");
    client.print("X-ApiKey: ");
    client.println(APIKEY);
    client.print("User-Agent: ");
    client.println(USERAGENT);
    client.println();
  } else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
  }
   // note the time that the connection was made or attempted:
  lastConnectionTime = millis();
}
