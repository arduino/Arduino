/******************************************************************************
*  GPIO - Blink LED
*
*  Description: This example demonstrates how to set a GPIO pin as an output
*  pin and toggle the output of the pin
*
*                                    MSP430
*                              -----------------
*                             |                 |
*                             |             P1.0|-->LED
*                             |                 |
*                             |                 |
*                             |                 |
*
* Tested On: MSP430FR5969
* Author: Zack Lalanne
******************************************************************************/
#include <driverlib.h>

void setup()
{
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void loop()
{
    // Wait for a second
    delay(1000);
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
}
