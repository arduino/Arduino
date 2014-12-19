/****************************************
  Demonstrates how to update a Google Spreadsheet from your 
  TI LaunchPad using Temboo and the Google Spreadsheets API.  
   
  Learn to auto-generate your own code for the TI LaunchPad
  with Temboo's Getting Started examples and tutorials.
 
  ** http://temboo.com/hardware/ti **
 
*****************************************/
 
/* 
  Instructions:
 
  1. Create a Temboo account: http://www.temboo.com

  2. Retrieve your Temboo application details: http://www.temboo.com/account/applications

  3. Replace the values in the TembooAccount.h tab with your Temboo application details

  4. You should also have a Google Spreadsheet that includes a heading in the first row 
     of each column that data will be written to. This example saves values to three columns:
     company, location, and contact. The spreadsheet should be set up with three column names:
  
       Company | Location | Contact   
     +---------+----------+---------+
               |          |        
 
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

// the full email address associated with your Google account, e.g., cormac@gmail.com
const String GOOGLE_USERNAME = "your-google-username";

// your Google account password
const String GOOGLE_PASSWORD = "your-google-password";

// the name of the spreadsheet in your Google Docs/Drive
// that you you want to send data to
const String SPREADSHEET_TITLE = "your-spreadsheet-title";

// the data you'd like to add to your spreadsheet, each cell value separated by a comma
const String ROW_DATA = "Temboo, New York, hey@temboo.com";

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

    Serial.println("Appending value to spreadsheet...");

    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo AppendRowChoreo(client);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    AppendRowChoreo.begin();

    // set Temboo account credentials
    AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library choreo to run (Google > Spreadsheets > AppendRow)
    AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");

    // your Google username (usually your email address)
    AppendRowChoreo.addInput("Username", GOOGLE_USERNAME);
    // your Google account password
    AppendRowChoreo.addInput("Password", GOOGLE_PASSWORD);
    // the data you want to append to the spreadsheet
    AppendRowChoreo.addInput("RowData", ROW_DATA);
    // the title of the spreadsheet you want to append to
    AppendRowChoreo.addInput("SpreadsheetTitle", SPREADSHEET_TITLE);

    // run the Choreo and wait for the results
    // the return code (returnCode) will indicate success or failure 
    unsigned int returnCode = AppendRowChoreo.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
      Serial.println("Success! Spreadsheet updated!\n");
    } 
    else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (AppendRowChoreo.available()) {
        char c = AppendRowChoreo.read();
        Serial.print(c);
      }
    }

    AppendRowChoreo.close();
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

