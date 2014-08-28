/****************************************
  Zendesk is a cloud-based customer service platform.
  
  The example demonstrates using Temboo to open a new Zendesk 
  support ticket from your TI LaunchPad.
 
  Learn to auto-generate your own code for the TI LaunchPad
  with Temboo's Getting Started examples and tutorials.
 
  ** http://temboo.com/hardware/ti **
 
*****************************************/
 
/* 
  Instructions:
 
  1. Create a Temboo account: http://www.temboo.com

  2. Retrieve your Temboo application details: http://www.temboo.com/account/applications

  3. Replace the values in the TembooAccount.h tab with your Temboo application details
 
  4. Create a Zendesk account and replace the placeholder values below
     with your own Zendesk account credentials:
     
     https://www.zendesk.com/register
 
  5. Upload the sketch to your LaunchPad and open Energia's serial monitor
  
  This example code is in the public domain.
*/

#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information
                           // as described in the footer comment below

/*** SUBSTITUTE YOUR VALUES BELOW: ***/

// note that for additional security and reusability, you could
// use #define statements to specify these values in a .h file.

// your Zendesk username e.g., customersupport@temboo.com
const String ZENDESK_USER_NAME = "xxxxxxxxxxxxxx";

// the Zendesk password for the account you're using
const String ZENDESK_PASSWORD = "xxxxxxxxxxxxxxx";

// your Zendesk subdomain e.g., temboocare.zendesk.com 
const String SERVER = "xxxxxxxx.zendesk.com";

// the subject of your new ticket
const String SUBJECT = "xxxxxxxxxxxxxxx";

// the body of the Zendesk ticket
const String COMMENT = "xxxxxxxxxxxxxxx";

// a flag to indicate whether we've tried to send the email yet or not
boolean attempted = false; 

WiFiClient client;

void setup() {
  Serial.begin(9600);

  // attempt to connect to Wifi network:
  Serial.print("WiFi");

  int wifiStatus = WL_IDLE_STATUS;

  // determine if the WiFi Shield is present.
  Serial.print("\n\nShield:");
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("FAIL");
    
    // if there's no WiFi shield, stop here.
    while(true);
  }
 
  while(wifiStatus != WL_CONNECTED) {
    Serial.print("WiFi:");
    wifiStatus = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    if (wifiStatus == WL_CONNECTED) {
      Serial.println("OK");
    } else {
      Serial.println("FAIL");
    }
    delay(5000);
  }
}

void loop() {

  // only try to create a ticket if we haven't already tried
  if (!attempted) {

    Serial.println("Running OpenZendeskTicket...");

    TembooChoreo CreateTicketChoreo(client);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked, and repopulated with
    // appropriate arguments, each time its run() method is called.
    CreateTicketChoreo.begin();

    // set Temboo account credentials
    CreateTicketChoreo.setAccountName(TEMBOO_ACCOUNT);
    CreateTicketChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    CreateTicketChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // set Choreo inputs  
    CreateTicketChoreo.addInput("Email", ZENDESK_USER_NAME);
    CreateTicketChoreo.addInput("Subject", SUBJECT);
    CreateTicketChoreo.addInput("Password", ZENDESK_PASSWORD);
    CreateTicketChoreo.addInput("Comment", COMMENT);
    CreateTicketChoreo.addInput("Server", SERVER);

    // identify the Temboo Library Choreo to run (Zendesk > Tickets > CreateTicket)
    CreateTicketChoreo.setChoreo("/Library/Zendesk/Tickets/CreateTicket");

    // tell the Choreo to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = CreateTicketChoreo.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
      Serial.println("Success! Ticket created!");
    } 
    else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (CreateTicketChoreo.available()) {
        char c = CreateTicketChoreo.read();
        Serial.print(c);
      }
    } 
    CreateTicketChoreo.close();

    // set the flag showing we've tried
    attempted = true;
  }
}

/*
  IMPORTANT NOTE: TembooAccount.h:
 
  TembooAccount.h is a file referenced by this sketch that contains your Temboo account information.
  You'll need to edit the placeholder version of TembooAccount.h included with this example sketch,
  by inserting your own Temboo account name and app key information. The contents of the file should
  look like:
 
  #define TEMBOO_ACCOUNT "myTembooAccountName"  // your Temboo account name 
  #define TEMBOO_APP_KEY_NAME "myFirstApp"  // your Temboo app name
  #define TEMBOO_APP_KEY  "xxxxxxxxxxxxxx"  // your Temboo app key
 
  #define WIFI_SSID "myWiFiNetworkName"
  #define WIFI_PASSWORD "myWiFiNetworkPassword"
 
  You can find your Temboo App Key information on the Temboo website under Account > Applications
 
  The same TembooAccount.h file settings can be used for all Temboo sketches.
 
  Keeping your account information in a separate file means you can share the main sketch file without worrying 
  that you forgot to delete your credentials.
*/

