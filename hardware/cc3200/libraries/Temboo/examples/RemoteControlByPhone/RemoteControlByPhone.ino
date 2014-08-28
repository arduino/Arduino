/****************************************
  Nexmo is a cloud-based voice and SMS service. 
  
  This example demonstrates using Temboo to make a phone call 
  via Nexmo when changes to a sensor value are detected. 
 
  Learn to auto-generate your own code for the TI LaunchPad
  with Temboo's Getting Started examples and tutorials.
 
  ** http://temboo.com/hardware/ti **
 
*****************************************/
 
/* 
  Instructions:
 
  1. Create a Temboo account: http://www.temboo.com

  2. Retrieve your Temboo application details: http://www.temboo.com/account/applications

  3. Replace the values in the TembooAccount.h tab with your Temboo application details. 
  
  4. Create a Nexmo account and get your Nexmo API key and API secret. Update the 
     placeholder values in the code below:
     
     http://nexmo.com
  
  5. Add your wireless network details to TembooAccount.h
  
  5. Upload the sketch to your LaunchPad and open Energia's serial monitor 
 
  NOTE: This example assumes an analog sensor attached to pin 2 but it does not require this to run. 
  You'll need to adjust the threshold that triggers the Choreo to values appropriate for your sensor. 
  The threshold is now set at < 100 as a default, but you may want to replace that with a higher or lower 
  number, depending on your sensor. 

  View the full tutorial at: https://www.temboo.com/hardware/ti/control-by-phone

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

// your NEXMO API key & secret
const String NEXMO_API_KEY = "xxxxxxxx";
const String NEXMO_API_SECRET = "xxxxxxxx";

// the phone number you want your LaunchPad to call
// make sure to include the international access code,
// for example, a US number would be: 12062954698
const String NUMBER_TO_CALL = "xxxxxxxxx";

int sensor = 2; // the sensor pin to read

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

  // read the sensor value
  int sensorReading = analogRead(sensor); 
  
  // slow down the output and make it easier to read 
  delay(250); 
  
  // print the sensor value to the serial monitor
  Serial.println(sensorReading); 

  // when the sensor value is less than 100
  if (sensorReading < 100) {
    Serial.println("\nSensor change detected! Making phone call...\n");

    // if the user chooses option 1 when they receive the phone call
    if (makeNexmoCall() == "1") {
      Serial.println("The user pressed 1.\n");
      // you can add code here to make your LaunchPad take 
      // an action based on the user's choice, e.g., start a motor, turn on a light, etc.
    } 
    else {
      Serial.println("The user did not press 1.");
    }
  }
}

/*
  Trigger a voice call via a Temboo Nexmo Choreo. Call the user, give them a menu of options
 and return an integer based on the selection they make on their phone keypad. 
 */
String makeNexmoCall() {
  // a string to represent the choice made by the user who receives the phone call
  String choice = "";

  // create the Choreo
  TembooChoreo CaptureTextToSpeechPromptChoreo(client);

  // invoke the Temboo client
  CaptureTextToSpeechPromptChoreo.begin();

  // set Temboo account credentials
  CaptureTextToSpeechPromptChoreo.setAccountName(TEMBOO_ACCOUNT);
  CaptureTextToSpeechPromptChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  CaptureTextToSpeechPromptChoreo.setAppKey(TEMBOO_APP_KEY);

  // set Choreo inputs
  CaptureTextToSpeechPromptChoreo.addInput("Text", "Hey there, a sensor change was detected. Press one to take an action on your Launch Pad, or press zero to ignore me.");
  CaptureTextToSpeechPromptChoreo.addInput("APIKey", NEXMO_API_KEY);
  CaptureTextToSpeechPromptChoreo.addInput("To", NUMBER_TO_CALL);
  CaptureTextToSpeechPromptChoreo.addInput("MaxDigits", "1");
  CaptureTextToSpeechPromptChoreo.addInput("APISecret", NEXMO_API_SECRET);
  CaptureTextToSpeechPromptChoreo.addInput("ByeText", "Ok, your wish is my command. Goodbye!");

  // identify Choreo to run
  CaptureTextToSpeechPromptChoreo.setChoreo("/Library/Nexmo/Voice/CaptureTextToSpeechPrompt");

  // create an output filter to return only the digit that the user pressed when they made their choice
  CaptureTextToSpeechPromptChoreo.addOutputFilter("choice", "/digits", "CallbackData");

  // run Choreo
  CaptureTextToSpeechPromptChoreo.run();

  // parse the results
  while(CaptureTextToSpeechPromptChoreo.available()) {
    // read the name of the next output item
    String name = CaptureTextToSpeechPromptChoreo.readStringUntil('\x1F');
    name.trim(); // use “trim” to get rid of newlines

    // read the value of the next output item
    String data = CaptureTextToSpeechPromptChoreo.readStringUntil('\x1E');
    data.trim(); // use “trim” to get rid of newlines

    // parse the user's choice out of the response data
    if (name == "choice") {
      choice = data;
    } 
  }
  // close the Choreo 
  CaptureTextToSpeechPromptChoreo.close();

  // return the choice that the user made 
  return choice;
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
