/*
  GetYahooWeatherReport
  
  Demonstrates making a request to the Yahoo! Weather API using Temboo. 
  
  A Temboo account and application key are necessary to run all Temboo examples. 
  If you don't already have one, you can register for a free Temboo account at 
  http://www.temboo.com
  
  This example assumes basic familiarity with Launchpad sketches, and that your board is connected
  to the Internet.

  Looking for another API to use with your Launchpad? We've got over 100 in our Library!
  
  This example code is in the public domain.
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information
                           // as described in the footer comment below


// the address for which a weather forecast will be retrieved
String ADDRESS_FOR_FORECAST = "104 Franklin St., New York NY 10013";

int numRuns = 1;   // execution count, so that this doesn't run forever
int maxRuns = 10;  // max number of times the Yahoo WeatherByAddress Choreo should be run

WiFiClient client;

void setup() {
  Serial.begin(115200);

  // attempt to connect to Wifi network:
  Serial.print("WiFi");

  // Connect to WPA/WPA2 network. 
  // Change this line if using open or WEP network:    
  int status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (status != WL_CONNECTED) {
    status = WiFi.status();
    Serial.print(".");
    delay(100);
  }
  Serial.println(" OK!");

  // wait for 5 seconds for connection:
  while(WiFi.localIP() == INADDR_NONE);
  
  Serial.print("Connected to: ");
  Serial.println(WiFi.SSID());

}

void loop()
{
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

    // add an output filter to extract the name of the city.
    GetWeatherByAddressChoreo.addOutputFilter("city", "/rss/channel/yweather:location/@city", "Response");
    
    // add an output filter to extract the current temperature
    GetWeatherByAddressChoreo.addOutputFilter("temperature", "/rss/channel/item/yweather:condition/@temp", "Response");

    // add an output filter to extract the date and time of the last report.
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
  #define TEMBOO_APP_KEY_NAME "myFirstApp"  // your Temboo app key name
  #define TEMBOO_APP_KEY  "xxx-xxx-xxx-xx-xxx"  // your Temboo app key

  You can find your Temboo App Key information on the Temboo website, 
  under Account > Applications

  The same TembooAccount.h file settings can be used for all Temboo SDK sketches.

  Keeping your account information in a separate file means you can share the main sketch file without worrying 
  that you forgot to delete your credentials.
*/
