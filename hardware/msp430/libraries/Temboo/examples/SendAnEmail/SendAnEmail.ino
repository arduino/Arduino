/****************************************
  Demonstrates how to use Temboo to send an email from your 
  TI LaunchPad via Google's Gmail API.  
  
  Learn to auto-generate your own code for the TI LaunchPad
  with Temboo's Getting Started examples and tutorials.
 
  ** http://temboo.com/hardware/ti **
 
 ****************************************/

/* 
  Instructions:
 
  1. Create a Temboo account: http://www.temboo.com

  2. Retrieve your Temboo application details: http://www.temboo.com/account/applications

  3. Replace the values in the TembooAccount.h tab with your Temboo application details
 
  4. You'll also need a Gmail account. Replace the placeholder Gmail account 
     information below with your own details. 
     
     https://www.gmail.com
 
  5. Upload the sketch to your LaunchPad and open Energia's serial monitor

  NOTE: the first time you run this sketch, you may receive a warning from
  Google, prompting you to authorize access from a third-party system.
  
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

// your Gmail username, formatted as a complete email address, e.g., "john.bonham@gmail.com"
const String GMAIL_USER_NAME = "xxxxxxxxxx";

// your Gmail password
const String GMAIL_PASSWORD = "xxxxxxxxxx";

// the email address you want to send the email to, e.g., "johnpauljones@temboo.com"
const String TO_EMAIL_ADDRESS = "xxxxxxxxxx";

// a flag to indicate whether we've tried to send the email yet or not
boolean attempted = false; 

WiFiClient client;

void setup() {
  Serial.begin(9600);

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

  // only try to send the email if we haven't already tried
  if (!attempted) {

    Serial.println("Running SendAnEmail...");
  
    TembooChoreo SendEmailChoreo(client);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked, and repopulated with
    // appropriate arguments, each time its run() method is called.
    SendEmailChoreo.begin();
    
    // set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library Choreo to run (Google > Gmail > SendEmail)
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
 
    // set the required Choreo inputs
    // see https://www.temboo.com/library/Library/Google/Gmail/SendEmail/ 
    // for complete details about the inputs for this Choreo

    // the first input is your Gmail email address    
    SendEmailChoreo.addInput("Username", GMAIL_USER_NAME);
    // next is your Gmail password
    SendEmailChoreo.addInput("Password", GMAIL_PASSWORD);
    // next is who to send the email to
    SendEmailChoreo.addInput("ToAddress", TO_EMAIL_ADDRESS);
    // then a subject line
    SendEmailChoreo.addInput("Subject", "ALERT: Greenhouse Temperature");

    // next comes the message body, the main content of the email   
    SendEmailChoreo.addInput("MessageBody", "Hey! The greenhouse is too cold!");

    // tell the Choreo to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendEmailChoreo.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! Email sent!");
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendEmailChoreo.available()) {
        char c = SendEmailChoreo.read();
        Serial.print(c);
      }
    } 
    SendEmailChoreo.close();
    
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
