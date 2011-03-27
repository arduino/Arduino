//************************************************************************
//*	Arduino Test Example Skeleton
//*		(C) 2010 by Rick Anderson
//*		Open source as per standard Arduino code
//*
//************************************************************************
//*	Oct 16,	2010	<ROA> Started on String Test
//************************************************************************

#include	"WProgram.h"
#include	"HardwareSerial.h"
#include	<ArduinoTestSuite.h>

//************************************************************************
void setup()
{
  
  ATS_begin("Arduino", "Issue 392 Test");
  /*
   * Test Run Start
   * Test one passes because result is set to true
   * Test two fails becuase result is set to false
   * You can test memory for any set of tests by using the ATS_ReportMemoryUsage test
   * There is also a way to print current memeory for debugging
   */
  Serial.println("!!!");
  ATS_PrintTestStatus("1. Issue 392 !!! error", true);
  /*
   * Test Run End
   */

  ATS_end();

}


//************************************************************************
void loop()
{


}




