//************************************************************************
//*	Arduino String Test
//*		(C) 2010 by Rick Anderson
//*		Open source as per standard Arduino code
//*
//************************************************************************
//*	Oct 16,	2010	<ROA> Started on String Test
//************************************************************************



#ifdef __MWERKS__
#include	"codewarrior.h"
#else
#include	<avr/pgmspace.h>
#endif
#include	<avr/io.h>
#include	"WProgram.h"
#include	"HardwareSerial.h"
#include	"pins_arduino.h"
#include	<ArduinoTestSuite.h>
#include	"avr_cpunames.h"

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__)
#define	kBoard_PinCount		20
#define	kBoard_AnalogCount	6
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define	kBoard_PinCount		70
#define	kBoard_AnalogCount	16
#endif

//************************************************************************
void setup()
{
  short	ii;
  uint8_t	timerNumber;
  char testName[64];



  gYotalErrors	=	0;
  gTestCount		=	0;

  /*
* Test Variable Setup
   */

  String stringOne = String("stringThree = ");
  String stringTwo = String("this string");
  String stringThree = String ();
  char charResult[100];

  Serial.begin(9600);
  delay(1000);

  gTestStartTime	=	millis();
  ATS_PrintTestStart("Arduino", "String Test");

  /*
* Run the tests
   */

  // adding a constant integer to a string:
  stringThree =  stringOne + 123;
  strcpy(charResult,  "\0");
  stringThree.toCharArray(charResult, sizeof(charResult));

  strcpy(testName, "Adding a constant integer to a string:");
  if (strcmp(charResult,"stringThree = 123" ) == 0)
  {
    ATS_PrintTestStatus(testName, true);
  }
  else
  {
    ATS_PrintTestStatus(testName, false);
  }



  // adding a constant long interger to a string:
  stringThree = stringOne + 123456789;
  stringThree.toCharArray(charResult, sizeof(charResult));

  strcpy(testName, "Adding a constant long interger to a string");
  if (strcmp(charResult,"stringThree = 123456789" )  == 0)
  {
    ATS_PrintTestStatus(testName, true);
  }
  else
  {
    ATS_PrintTestStatus(testName, false);
  }


  // adding a constant character to a string:
  stringThree =  stringOne + 'A';
  stringThree.toCharArray(charResult, sizeof(charResult));

  strcpy(testName, "Adding a constant character to a string");
  if (strcmp(charResult,"stringThree = A" ) == 0)
  {
    ATS_PrintTestStatus(testName, true);
  }
  else
  {
    ATS_PrintTestStatus(testName, false);
  }



  // adding a constant string to a string:
  stringThree =  stringOne +  "abc";
  stringThree.toCharArray(charResult, sizeof(charResult));

  strcpy(testName, "Adding a constant string variable to a string");
  if (strcmp(charResult,"stringThree = abc" )  == 0)
  {
    ATS_PrintTestStatus(testName, true);
  }
  else
  {
    ATS_PrintTestStatus(testName, false);
  }

  stringThree = stringOne + stringTwo;
  stringThree.toCharArray(charResult, sizeof(charResult));

  strcpy(testName, "Adding a constant long interger to a string");
  if (strcmp(charResult,"stringThree = this string" )  == 0)
  {
    ATS_PrintTestStatus(testName, true);
  }
  else
  {
    ATS_PrintTestStatus(testName, false);
  }



  /*
* Test complete
   */
  ATS_PrintTestEnd();

}


//************************************************************************
void loop()
{


}




