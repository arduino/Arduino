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

  Serial.begin(9600);
  delay(1000);

  gTestStartTime	=	millis();
  ATS_PrintTestStart("Arduino", "Test of Arduino Constants");

  /*
* Run the tests
   */


  //test true constant

  ATS_PrintTestStatus("1. Test of true constant", true == 1);

  //test false consts
  ATS_PrintTestStatus( "2. Test of false constant", false == 0);

  //Test of HIGH == 1
  ATS_PrintTestStatus( "3. Test of HIGH == 1", HIGH == 1);

  //Test of LOW ==  0
  ATS_PrintTestStatus( "4. Test of LOW ==  0", LOW == 0);

  //Test of INPUT == 1
  ATS_PrintTestStatus( "5. Test of INPUT == 1", HIGH == 1);

  //Test of OUTPUT ==  0
  ATS_PrintTestStatus( "6. Test of OUTPUT ==  0", LOW == 0);

  //test decimal
  ATS_PrintTestStatus( "7. Test of decimal constant", 101 == ((1 * pow(10,2)) + (0 * pow(10,1)) + 1));

  //test binary
  ATS_PrintTestStatus( "8. Test of binary constant", B101 == 5);

  //test octal
  ATS_PrintTestStatus( "9. Test of octal constant", 0101 == 65);

  //test hexadecimal
  ATS_PrintTestStatus( "7. Test of hexadecimal constant", (0x101 == 257));

  /*
  * Test complete
   */
  ATS_PrintTestEnd();

}


//************************************************************************
void loop()
{


}




