//************************************************************************
//************************************************************************
//*	Aug 31,	2010	<MLS> Started on TestArduino
//************************************************************************

#ifndef _AVR_IO_H_
	#include	<avr/io.h>
#endif

#ifndef WProgram_h
	#include	"WProgram.h"
#endif
#ifndef HardwareSerial_h
	#include	"HardwareSerial.h"
#endif


#if defined(USART3_RX_vect)
	#define	SERIAL_PORT_COUNT		4
#elif  defined(USART1_RX_vect)
	#define	SERIAL_PORT_COUNT		2
#else
	#define	SERIAL_PORT_COUNT		1
#endif


void	ATS_PrintTestStart(char *manufName, char *testSuiteName);
void	ATS_PrintTestEnd();
void	ATS_PrintTestStatus(char *testString, boolean passed);
boolean	ATS_Test_DigitalPin(uint8_t digitalPinToTest);
boolean	ATS_Test_PWM_Pin(uint8_t digitalPinToTest);
boolean	ATS_Test_AnalogInput(uint8_t analogPintoTest);
boolean	ATS_Test_EEPROM(void);

static void	ATS_PrintProperty(	int		propertyTagNum,
							char	*propertyName,
							char	*propertyValue);

short	ATS_TestSerialLoopback(HardwareSerial *theSerialPort, char *serialPortName);




extern	unsigned long	gTestStartTime;
extern	int				gYotalErrors;
extern	int				gTestCount;


#define	PASSED	true
#define	FAILED	false

