/******************************************************************************
*  CRC - Calculate CRC
*
*  Description: This example calculates the CRC of an array of data twice and
*  compares the results. If the results are the same then the LED turns on
*  if the results are different the LED turns off. The results are also printed
*  back to the console.
*
*                                    MSP430
*                              -----------------
*                             |                 |
*                             |             P1.0|-->LED
*                             |                 |
*                             |                 |
*                             |                 |
*
* Tested On: MSP430F5529
* Author: Zack Lalanne
******************************************************************************/
#include <driverlib.h>

const uint16_t CRCSeed = 0xBEEF;
const uint16_t Data[] = { 0x0123,
                          0x4567,
                          0x8910,
                          0x1112,
                          0x1314 };

void setup()
{
    Serial.begin(9600);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void loop()
{
    uint16_t crcResult, crcResult2;
    uint16_t i;

    // Reset the seed
    CRC_setSeed(CRC_BASE, CRCSeed);

    // Add data to the CRC
    for(i = 0; i < 5; i++) {
        CRC_set16BitData(CRC_BASE, Data[i]);
    }

    // Store the result
    crcResult = CRC_getResult(CRC_BASE);
    Serial.print("First Result:  0x");
    Serial.println(crcResult, HEX);

    // Repeat CRC calculation and compare results
    CRC_setSeed(CRC_BASE, CRCSeed);
    for(i = 0; i < 5; i++) {
        CRC_set16BitData(CRC_BASE, Data[i]);
    }

    // Get the second result
    crcResult2 = CRC_getResult(CRC_BASE);
    Serial.print("Second Result: 0x");
    Serial.println(crcResult2, HEX);

    // Compare the results
    if(crcResult == crcResult2) {
        GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    } else {
        GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }

    Serial.println("---------------------");
    delay(1000);
}
