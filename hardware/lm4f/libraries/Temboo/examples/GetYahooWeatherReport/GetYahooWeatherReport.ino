/****************************************                   
  Demonstrates using Temboo to get the weather forecast for a specific 
  location via the Yahoo! Weather API. 
  
  Learn to auto-generate your own code for the TI LaunchPad
  with Temboo's Getting Started examples and tutorials.

  ** http://temboo.com/hardware/ti **
 
 ****************************************/
 
/* 
  Instructions:

  1. Create a Temboo account: http://www.temboo.com

  2. Retrieve your Temboo application details: http://www.temboo.com/account/applications

  3. Replace the values in the TembooAccount.h tab with your Temboo application details
  
  4. Add your wireless network details to TembooAccount.h
  
  5. Upload the sketch to your LaunchPad and open Energia's serial monitor.  

  This example code is in the public domain.      
*/

#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information
                           // as described in the footer comment below

// the address for which a weather forecast will be retrieved
// you can change this to be whatever you like
String ADDRESS_FOR_FORECAST = "104 Franklin St., New York NY 10013";

int numRuns = 1;   // execution count, so that this doesn't run forever
int maxRuns = 10;  // max number of times the Yahoo WeatherByAddress Choreo should be run

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

  // while we haven't reached the max number of runs...
  if (numRuns <= maxRuns) {
      
    // print status
    Serial.println("Running GetWeatherByAddress - Run #" + String(numRuns++) + "...");

    // create a TembooChoreo object to send a Choreo request to Temboo
    TembooChoreo GetWeatherByAddressChoreo(client);
    
    // add your Temboo account info
    GetWeatherByAddressChoreo.setAccountName(TEMBOO_ACCOUNT);
    GetWeatherByAddressChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    GetWeatherByAddressChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // set the name of the Choreo we want to run
    GetWeatherByAddressChoreo.setChoreo("/Library/Yahoo/Weather/GetWeatherByAddress");
    
    // set Choreo inputs; in this case, the address for which to retrieve weather data
    // the Temboo client provides standardized calls to 100+ cloud APIs
    GetWeatherByAddressChoreo.addInput("Address", ADDRESS_FOR_FORECAST);

    // add an output filter to extract the name of the city
    GetWeatherByAddressChoreo.addOutputFilter("city", "/rss/channel/yweather:location/@city", "Response");
    
    // add an output filter to extract the current temperature
    GetWeatherByAddressChoreo.addOutputFilter("temperature", "/rss/channel/item/yweather:condition/@temp", "Response");

    // add an output filter to extract the date and time of the last report
    GetWeatherByAddressChoreo.addOutputFilter("date", "/rss/channel/item/yweather:condition/@date", "Response");

    // run the Choreo 
    GetWeatherByAddressChoreo.run();
        
    // when the Choreo results are available, print them to the serial monitor
    while(GetWeatherByAddressChoreo.available()) {
      char c = GetWeatherByAddressChoreo.read();    
      Serial.print(c);
    }
    GetWeatherByAddressChoreo.close();
  }

  Serial.println("Waiting...");
  Serial.println("");
  delay(30000); // wait 30 seconds between GetWeatherByAddress calls
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
