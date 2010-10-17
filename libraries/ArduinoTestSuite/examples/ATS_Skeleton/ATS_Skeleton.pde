//************************************************************************
//*	Arduino Test Example Skeleton
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
  ATS_PrintTestStart("Arduino", "Skeleton Test");

/*
* Run the tests
*/

  ATS_PrintTestStatus("1. Test of true test status", true);
  
  ATS_PrintTestStatus("2. Test of false test status, this will fail.", false);


/*
* Test complete
*/
  ATS_PrintTestEnd();

}


//************************************************************************
void loop()
{


}



