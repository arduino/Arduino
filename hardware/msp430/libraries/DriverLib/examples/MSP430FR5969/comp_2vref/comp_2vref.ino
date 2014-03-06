/******************************************************************************
*  COMP_B - Compare input to 2.0V
*
*  Description: This example reads in the analog signal from CB0 and compares
*  it to 2.0V. If the signal is higher than 2.0V it turns on the LED else it
*  turns off the LED.
*
*                                    MSP430
*                              -----------------
*                             |                 |
*                             |             P1.0|-->LED
*                             |                 |
*                    Signal-->|P6.0 (CB0)       |
*                             |                 |
*
* Tested On: MSP430F5529
* Author: Zack Lalanne
******************************************************************************/
#include <driverlib.h>

void setup()
{

    // Setup the LED to display the status
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);

    // Use P6.0 for comparator input
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6,
                                               GPIO_PIN0);

    /* Initialize the COMP_B module
     *
     * Base Address of COMP_B,
     * Pin CB0 to Positive(+) Terminal,
     * Reference Voltage to Negative(-) Terminal,
     * Normal Power Mode,
     * Output Filter On with minimal delay,
     * Non-Inverted Output Polarity
     */
    COMP_B_init(COMP_B_BASE,
                COMP_B_INPUT0,
                COMP_B_VREF,
                COMP_B_POWERMODE_NORMALMODE,
                COMP_B_FILTEROUTPUT_DLYLVL1,
                COMP_B_NORMALOUTPUTPOLARITY);

    /* Set the reference voltage that is being supplied to the (-) terminal
     *
     * Base Address of COMP_B,
     * Reference Voltage of 2.0 V,
     * Lower Limit of 2.0*(32/32) = 2.0V,
     * Upper Limit of 2.0*(32/32) = 2.0V,
     * Static Mode Accuracy
     */
    COMP_B_setReferenceVoltage(COMP_B_BASE,
                               COMP_B_VREFBASE2_0V,
                               32,
                               32,
                               COMP_B_ACCURACY_STATIC
                               );

    // Allow power to COMP_B module
    COMP_B_enable(COMP_B_BASE);
}

void loop()
{
    // Get comparison result and determine state of LED
    if(COMP_B_outputValue(COMP_B_BASE) == COMP_B_HIGH) {
        GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    } else {
        GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }
}
