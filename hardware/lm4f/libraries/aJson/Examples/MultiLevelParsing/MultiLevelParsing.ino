/*
 Sample sketch to demonstrate Multi Level JSON parsing in Arduino
 
 This sketch parses the complexly nested JSON
 
 Libraries needed:

 - aJson library for JSON parsing - https://github.com/interactive-matter/aJson
 
 Circuit:

    You don't need any circuit, but need the Arduino board

 Author: 

    Sudar - <http://sudarmuthu.com> <http://hardwarefun.com>
    Refer to http://hardwarefun.com/tutorials/parsing-json-in-arduino

 License:

    BeerWare ;)
 
 */
#include <aJSON.h>

// function definitions
char* parseJson(char *jsonString) ;

// Json string to parse
char jsonString[] = "{\"query\":{\"count\":1,\"created\":\"2012-08-04T14:46:03Z\",\"lang\":\"en-US\",\"results\":{\"item\":{\"title\":\"Handling FTP usernames with @ in them\"}}}}";

void setup() {
    Serial.begin(9600);
    Serial.println(jsonString);
    Serial.println("Starting to parse");

    char* value = parseJson(jsonString);

    if (value) {
        Serial.print(F("Successfully Parsed: "));
        Serial.println(value);
    } else {
        Serial.print(F("There was some problem in parsing the JSON"));
    }
}

/**
 * Parse the JSON String. Uses aJson library
 * 
 * Refer to http://hardwarefun.com/tutorials/parsing-json-in-arduino
 */
char* parseJson(char *jsonString) 
{
    char* value;

    aJsonObject* root = aJson.parse(jsonString);

    if (root != NULL) {
        //Serial.println("Parsed successfully 1 " );
        aJsonObject* query = aJson.getObjectItem(root, "query"); 

        if (query != NULL) {
            //Serial.println("Parsed successfully 2 " );
            aJsonObject* results = aJson.getObjectItem(query, "results"); 

            if (results != NULL) {
                //Serial.println("Parsed successfully 3 " );
                aJsonObject* item = aJson.getObjectItem(results, "item"); 

                if (item != NULL) {
                    //Serial.println("Parsed successfully 4 " );
                    aJsonObject* title = aJson.getObjectItem(item, "title"); 
                    
                    if (title != NULL) {
                        //Serial.println("Parsed successfully 5 " );
                        value = title->valuestring;
                    }
                }
            }
        }
    }

    if (value) {
        return value;
    } else {
        return NULL;
    }
}

void loop() {
   // Nothing to do 
   ;
}
