#include <aJSON.h>

const char RETRIEVING_NAME[] ="Retrieving name\n";
const char ERROR_RETRIEVING_NAME[] ="Error retrieving name\n";
const char SUCCESSFULLY_RETRIEVED_NAME[] ="Successfully retrieved Name:";
const char PARSING_OBJECT[] ="Parsing String\n";
const char ERROR_PARSING_OBJECT[] ="Error parsing Object\n";
const char SUCCESSFULLY_PARSED_OBJECT[] ="Successfully parsed Object\n";
const char DELETING_OBJECT_STRING[] = "Deleting the object\n";
const char FORMAT_FAILED_STRING[] = "Failed to create Format Object\n";
const char OUTPUT_STRING_ERROR[] = "Error creating output String\n";
const char RESULT_PRINTING_STRING[] = "Printing the result:\n";
const char ADDING_FRAMERATE_STRING[] = "Adding frame rate to the format\n";
const char ADDING_INTERLACE_STRING[] = "Adding interlace to the format\n";
const char ADDING_HEIGHT_STRING[] = "Adding height to the format\n";
const char ADDING_WIDTH_STRING[] = "Adding width to the format\n";
const char ADDING_TYPE_STRING[] = "Adding type to the format\n";
const char ADDING_FORMAT_STRING[] = "Adding format to the object\n";
const char ADDING_LENGTH_STRING[] = "Adding length to the object\n";
const char CREATING_FROMAT_STRING[] = "Creating format object\n";
const char ADDING_NAME_STRING[] = "Adding name to the object\n";
const char OBJECT_CREATION_FAILED_STRING[] = "Failed to create the object\n";
const char OBJECT_CREATE_STRING[] = "Created a Object\n";
const char HELLO_STRING[] = "********************\nTesting aJson\n*****************\n";

// The setup() method runs once, when the sketch starts
void setup() {
  Serial.begin(115200);
  Serial.print(HELLO_STRING);
}

void testObjects() {

  aJsonObject* root = aJson.createObject();
  if (root != NULL) {
    Serial.print( OBJECT_CREATE_STRING);
  } 
  else {
    Serial.print( OBJECT_CREATION_FAILED_STRING);
    return;
  }
  Serial.print( ADDING_NAME_STRING);
  aJson.addItemToObject(root, "name", aJson.createItem(
  "Jack (\"Bee\") Nimble"));
  Serial.print( CREATING_FROMAT_STRING);
  aJsonObject* fmt = aJson.createObject();
  if (fmt != NULL) {
    Serial.print( ADDING_FORMAT_STRING);
    aJson.addItemToObject(root, "format", fmt);
    Serial.print( ADDING_TYPE_STRING);
    aJson.addStringToObject(fmt, "type", "rect");
    Serial.print( ADDING_WIDTH_STRING);
    aJson.addNumberToObject(fmt, "width", 1920);
    Serial.print( ADDING_HEIGHT_STRING);
    aJson.addNumberToObject(fmt, "height", 1080);
    Serial.print( ADDING_INTERLACE_STRING);
    aJson.addFalseToObject(fmt, "interlace");
    Serial.print( ADDING_FRAMERATE_STRING);
    aJson.addNumberToObject(fmt, "frame rate", 24);
    Serial.print( ADDING_LENGTH_STRING);
    aJson.addNumberToObject(fmt, "length", 1.29);
  } 
  else {
    Serial.print( FORMAT_FAILED_STRING);
    return;
  }

  Serial.print( RESULT_PRINTING_STRING);
  char* string = aJson.print(root);
  if (string != NULL) {
    Serial.println(string);
  } 
  else {
    Serial.print( OUTPUT_STRING_ERROR);
  }

  Serial.print( DELETING_OBJECT_STRING);
  aJson.deleteItem(root);

  Serial.print(PARSING_OBJECT);
  Serial.println(string);
  root = aJson.parse(string);
  free(string);
  if (root != NULL) {
    Serial.print(SUCCESSFULLY_PARSED_OBJECT);
  } 
  else {
    Serial.print( ERROR_PARSING_OBJECT);
    return;
  }
  Serial.print( RESULT_PRINTING_STRING);
  string = aJson.print(root);
  if (string != NULL) {
    Serial.println(string);
    free(string);
  } 
  else {
    Serial.print( OUTPUT_STRING_ERROR);
  }

  aJsonObject* name = aJson.getObjectItem(root, "name");
  if (name != NULL) {
    Serial.print( SUCCESSFULLY_RETRIEVED_NAME);
    Serial.println(name->valuestring);
  } 
  else {
    Serial.print( ERROR_RETRIEVING_NAME);
  }

  Serial.print( DELETING_OBJECT_STRING);
  aJson.deleteItem(root);
}

void testArrays() {
  aJsonObject* root = aJson.createArray();
  if (root != NULL) {
    Serial.print( OBJECT_CREATE_STRING);
  } 
  else {
    Serial.print( OBJECT_CREATION_FAILED_STRING);
    return;
  }  
  aJsonObject* day;
  day=aJson.createItem("Monday");
  aJson.addItemToArray(root, day);
  day=aJson.createItem("Tuesday");
  aJson.addItemToArray(root, day);
  day=aJson.createItem("Wednesday");
  aJson.addItemToArray(root, day);
  day=aJson.createItem("Thursday");
  aJson.addItemToArray(root, day);
  day=aJson.createItem("Friday");
  aJson.addItemToArray(root, day);
  day=aJson.createItem("Saturday");
  aJson.addItemToArray(root, day);
  day=aJson.createItem("Sunday");
  aJson.addItemToArray(root, day);

  Serial.print( RESULT_PRINTING_STRING);

  char* string = aJson.print(root);
  if (string != NULL) {
    Serial.println(string);
  } 
  else {
    Serial.print( OUTPUT_STRING_ERROR);
  }

  Serial.print( DELETING_OBJECT_STRING);

  aJson.deleteItem(root);
  
  Serial.print(PARSING_OBJECT);
  Serial.println(string);
  root = aJson.parse(string);

  free(string);

  if (root != NULL) {
    Serial.print(SUCCESSFULLY_PARSED_OBJECT);
  } 
  else {
    Serial.print( ERROR_PARSING_OBJECT);
    return;
  }
  Serial.print( RESULT_PRINTING_STRING);

  string = aJson.print(root);
  if (string != NULL) {
    Serial.println(string);
    free(string);
  } 
  else {
    Serial.print( OUTPUT_STRING_ERROR);
  }

  aJson.deleteItem(root);
}


// the loop() method runs over and over again,
// as long as the Arduino has power
void loop() {
  testObjects();
  delay(1000);
  testArrays();
  delay(1000);
}
