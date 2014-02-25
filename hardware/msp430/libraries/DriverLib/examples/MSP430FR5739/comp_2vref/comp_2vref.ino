/******************************************************************************
*  COMP_D - Compare input to 2.0V
*
*  Description: This example reads in the analog signal from CD0 and compares
*  it to 2.0V. If the signal is higher than 2.0V it turns on the LED else it
*  turns off the LED.
*
*                                    MSP430
*                              -----------------
*                             |                 |
*                             |             PJ.0|-->LED
*                             |                 |
*                    Signal-->|P6.0 (CD0)       |
*                             |                 |
*
* Tested On: MSP430FR5739
* Author: Zack Lalanne
******************************************************************************/
#include <driverlib.h>

void setup()
{

    // Setup the LED to display the status
    GPIO_setAsOutputPin(GPIO_PORT_PJ, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_PJ, GPIO_PIN0);

    /* Initialize the COMP_D module
     * 
     * Base Address of COMP_D,
     * Pin CD2 to Positive(+) Terminal,
     * Reference Voltage to Negative(-) Terminal,
     * Normal Power Mode,
     * Output Filter On with minimal delay,
     * Non-Inverted Output Polarity
     */
    COMP_D_init(COMP_D_BASE,
                COMP_D_INPUT2,
                COMP_D_VREF,
                COMP_D_FILTEROUTPUT_OFF,
                COMP_D_NORMALOUTPUTPOLARITY);

    /* Set the reference voltage that is being supplied to the (-) terminal
     * 
     * Base Address of COMP_D,
     * Reference Voltage of 2.0 V,
     * Lower Limit of 2.0*(32/32) = 2.0V,
     * Upper Limit of 2.0*(32/32) = 2.0V
     */
    COMP_D_setReferenceVoltage(COMP_D_BASE,
                               COMP_D_VREFBASE2_0V,
                               32,
                               32);

    /* Disable Input Buffer on P3.5/CD2 
     * 
     * Base Address of COMP_D,
     * Input Buffer port
     */
    COMP_D_disableInputBuffer(COMP_D_BASE,
                              COMP_D_INPUT2);

    // Allow power to COMP_D module
    COMP_D_enable(COMP_D_BASE);
}

void loop()
{
    // Get comparison result and determine state of LED
    if(COMP_D_outputValue(COMP_D_BASE) == COMP_D_HIGH) {
        GPIO_setOutputHighOnPin(GPIO_PORT_PJ, GPIO_PIN0);
    } else {
        GPIO_setOutputLowOnPin(GPIO_PORT_PJ, GPIO_PIN0);
    }
}
