/*
  wiring.c - Partial implementation of the Wiring API for the ATmega8.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.c 808 2009-12-18 17:44:08Z dmellis $
*/

#include <stddef.h>
#include <avr/pgmspace.h>
#include "wiring_private.h"

// Some versions of avr-gcc on linux defines XXX_bp instead of _gp.
#if !defined ADC_SWEEP_gp
    #define ADC_SWEEP_gp  ADC_SWEEP0_bp
#endif
#if !defined ADC_EVSEL_gp
    #define ADC_EVSEL_gp  ADC_EVSEL0_bp
#endif
#if !defined ADC_EVACT_gp
    #define ADC_EVACT_gp  ADC_EVACT0_bp
#endif
#if !defined ADC_CH_GAINFAC_gp
    #define ADC_CH_GAINFAC_gp  ADC_CH_GAINFAC0_bp
#endif
#if !defined ADC_DMASEL_gp
    #define ADC_DMASEL_gp  ADC_DMASEL0_bp
#endif

volatile unsigned long millis_count = 0;
volatile unsigned long seconds_count = 0;
#if defined(USE_RTC)
volatile unsigned long rtc_millis = 0;

/*! \brief RTC overflow interrupt service routine.
 *
 *  This ISR keeps track of the milliseconds 
 */
ISR(RTC_OVF_vect)
{
	rtc_millis = rtc_millis+4;
}

unsigned long millis()
{
 	unsigned long m;
 	
 	uint8_t oldSREG = SREG;
 
	// disable interrupts while we read rtc_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to rtc_millis)
	cli();
	m = rtc_millis;
	SREG = oldSREG;

	return m;
}

unsigned long micros(void) {
	// TODO: Get real micros and not just millis*1000
	unsigned long m;

        uint8_t oldSREG = SREG;

        // disable interrupts while we read rtc_millis or we might get an
        // inconsistent value (e.g. in the middle of a write to rtc_millis)
        cli();
        m = rtc_millis;
        SREG = oldSREG;

        return m*1000;
}

/* Delay for the given number of microseconds.  Assumes a 8, 16 or 32 MHz clock. */
void delayMicroseconds(unsigned int us)
{
        // calling avrlib's delay_us() function with low values (e.g. 1 or
        // 2 microseconds) gives delays longer than desired.
        //delay_us(us);

#if F_CPU >= 32000000L
	// for the 32 MHz clock built in all Xmega

        // the following loop takes a eighth of a microsecond (4 cycles)
        // per iteration, so execute it eight times for each microsecond of
        // delay requested.
        us <<= 3;

        // account for the time taken in the preceeding commands.
        us -= 3;
#elif F_CPU >= 16000000L
        // for the 16 MHz clock on most Arduino boards

        // for a one-microsecond delay, simply return.  the overhead
        // of the function call yields a delay of approximately 1 1/8 us.
        if (--us == 0)
                return;

        // the following loop takes a quarter of a microsecond (4 cycles)
        // per iteration, so execute it four times for each microsecond of
        // delay requested.
        us <<= 2;

        // account for the time taken in the preceeding commands.
        us -= 2;
#else
        // for the 8 MHz internal clock on the ATmega168

        // for a one- or two-microsecond delay, simply return.  the overhead of
        // the function calls takes more than two microseconds.  can't just
        // subtract two, since us is unsigned; we'd overflow.
        if (--us == 0)
                return;
        if (--us == 0)
                return;

        // the following loop takes half of a microsecond (4 cycles)
        // per iteration, so execute it twice for each microsecond of
        // delay requested.
        us <<= 1;

        // partially compensate for the time taken by the preceeding commands.
        // we can't subtract any more than this or we'd overflow w/ small delays.
        us--;
#endif

        // busy wait
        __asm__ __volatile__ (
                "1: sbiw %0,1" "\n\t" // 2 cycles
                "brne 1b" : "=w" (us) : "0" (us) // 2 cycles
        );
}


#else
ISR(TCF0_OVF_vect)
{
	/// TODO: Do we need to call cli()?
	++millis_count;
        EVSYS.STROBE = 0xF;
}

ISR(TCF1_OVF_vect)
{
	/// TODO: Do we need to call cli()?
	++seconds_count;
}

unsigned long millis(void)
{
	// disable interrupts while we read millis_count or we might get an
	// inconsistent value (e.g. in the middle of a write to millis_count)

	uint8_t oldSREG = SREG; // Save and restore the interrupt enable bit
	cli();
	unsigned long result = seconds_count*1000UL + TCF1.CNT;
	SREG = oldSREG;

	return result + millis_count;
}

uint64_t micros_huge(void) {
	// disable interrupts while we read rtc_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to rtc_millis)

        // TODO: Will micros and millis be consistent?
        // Are events processed even when interrupts are disabled?
        // If so TCF1 count may be updated even when interrupts are off.
	uint8_t oldSREG = SREG; // Save and restore the interrupt enable bit
	cli();
	uint64_t result = ((uint64_t)seconds_count)*1000000UL + TCF1.CNT*1000UL + (TCF0.CNT>>2);
	SREG = oldSREG;

	return result;
}

unsigned long micros(void) {
	// disable interrupts while we read rtc_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to rtc_millis)

        // TODO: Will micros and millis be consistent?
        // Are events processed even when interrupts are disabled?
        // If so TCF1 count may be updated even when interrupts are off.
	uint8_t oldSREG = SREG; // Save and restore the interrupt enable bit
	cli();
	unsigned long result = seconds_count*1000000UL + millis_count*1000 + TCF1.CNT*1000UL + (TCF0.CNT>>2);
	SREG = oldSREG;

	return result;
}

/* Delay for the given number of microseconds.  Assumes a 8 or 16 MHz clock. */
void delayMicroseconds(unsigned int us)
{
        unsigned long start = micros();

        while (micros() - start <= us);
}
#endif // USE_RTC

void delay(unsigned long ms)
{
	unsigned long start = millis();
	
	while (millis() - start <= ms);
}

static void initResetButton();
static void initAdc();
#if defined(ADCACAL0) || defined(ADCBCAL0)
static uint8_t ReadCalibrationByte(uint8_t index);
#endif // ADCACAL0 || ADCBCAL0

void init()
{
	// this needs to be called before setup() or some functions won't
	// work there
	sei();
	
        // TODO: micros/millis timer init.

        // TODO: pwm init

	// set a2d prescale factor to 128
	// 16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
	// XXX: this will not work properly for other clock speeds, and
	// this code should use F_CPU to determine the prescale factor.
	// TODO: Init a2d

	// the bootloader connects pins 0 and 1 to the USART; disconnect them
	// here so they can be used as normal digital i/o; they will be
	// reconnected in Serial.begin()
	// TODO: Disconnect bootloader USARTS
	
        /**************************************/
        /* Init system clock: run it at 32Mhz */

        // Enable 32M internal crystal
        OSC.CTRL |= OSC_RC32MEN_bm;
        // Wait for it to stablize
        while ( !(OSC.STATUS & OSC_RC32MEN_bm) ) ;

        // Set main system clock to 32Mhz internal clock
        CCP = CCP_IOREG_gc; // Secret handshake so we can change clock
        CLK.CTRL = (CLK.CTRL & ~CLK_SCLKSEL_gm ) | CLK_SCLKSEL_RC32M_gc;

        // TODO: gc: ClkPer2 should really be 2x ClkSys for EBI to work (Xmega A doc, 4.10.1)
        // TODO: gc: ClkPer4 should really be 4x ClkSys for Hi-Res extensions (16.2)

#ifdef USE_RTC
	/* Turn on internal 32kHz. */
	OSC.CTRL |= OSC_RC32KEN_bm;

	do {
		/* Wait for the 32kHz oscillator to stabilize. */
	} while ( ( OSC.STATUS & OSC_RC32KRDY_bm ) == 0);
		

	/* Set internal 32kHz oscillator as clock source for RTC. */
	CLK.RTCCTRL = CLK_RTCSRC_RCOSC_gc | CLK_RTCEN_bm;//1kHz
#else
        /*************************************/
        /* Init real time clock for millis() */

        /* Timer 1 uses the system clock as its source. 32Mhz with a prescalar of 8 is 4Mhz.
         * 4 ticks per microsecond. 4000 ticks per milli. On overflow generate an event.
         *
         * Timer 2 uses timer 1's overlow event as its source. Each tick is a ms.
         * 1000 ticks per second. On overflow generates an interrupt.
         *
         * interrupt handler increments seconds counter.
        */
        TCF0.CTRLA    = TC_CLKSEL_DIV8_gc;
        TCF0.PERBUF   = 4000;
        TCF0.CTRLB    = ( TCF0.CTRLB & ~TC0_WGMODE_gm ) | TC_WGMODE_NORMAL_gc;
//      EVSYS.CH0MUX  = EVSYS_CHMUX_TCF0_OVF_gc;
        TCF0.INTCTRLA = TC_OVFINTLVL_HI_gc;

        TCF1.CTRLA    = TC_CLKSEL_EVCH0_gc;
        TCF1.PERBUF   = 1000;
        TCF1.CTRLB    = ( TCF1.CTRLB & ~TC1_WGMODE_gm ) | TC_WGMODE_NORMAL_gc;
        TCF1.CTRLD    = TC_EVACT_UPDOWN_gc | TC1_EVDLY_bm;
        TCF1.INTCTRLA = TC_OVFINTLVL_HI_gc;
#endif
        /*************************************/
        /* Init I/O ports */
	
#define TOTEMPOLE      0x00  // Totempole
#define PULLDOWN       0x10  // Pull down
#define PULLUP         0x18  // Pull up
#define BUSKEEPER      0x08  // Buskeeper
#define WIRED_AND_PULL 0x38  // Wired-AND-PullUp
#define OUT_PULL_CONFIG TOTEMPOLE
//#define OUT_PULL_CONFIG BUSKEEPER
//#define OUT_PULL_CONFIG WIRED_AND_PULL
	
	//configure pins of xmega

	PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
	PORTA.PIN0CTRL  = PULLDOWN;
	PORTA.DIR       = 0;
#if defined(ADCACAL0)
// TODO: Linux avr-gcc doesn't seem to declare CAL[LH]
        ADCA.CALL       = ReadCalibrationByte( offsetof(NVM_PROD_SIGNATURES_t, ADCACAL0) );
        ADCA.CALH       = ReadCalibrationByte( offsetof(NVM_PROD_SIGNATURES_t, ADCACAL1) );
#endif // ADCACAL0
        initAdc(&ADCA);

	PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
	PORTB.PIN0CTRL  = PULLDOWN;
	PORTB.DIR       = 0;
#if defined(ADCB) 
#if defined(ADCBCAL0) 
// TODO: Linux avr-gcc doesn't seem to declare CAL[LH]
        ADCB.CALL       = ReadCalibrationByte( offsetof(NVM_PROD_SIGNATURES_t, ADCBCAL0) );
        ADCB.CALH       = ReadCalibrationByte( offsetof(NVM_PROD_SIGNATURES_t, ADCBCAL1) );
#endif // ADCBCAL0
        initAdc(&ADCB);
#endif // ADCB
	
	PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
	PORTC.PIN0CTRL  = OUT_PULL_CONFIG;

	PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
	PORTD.PIN0CTRL  = OUT_PULL_CONFIG;

	PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
	PORTE.PIN0CTRL  = OUT_PULL_CONFIG;

#if defined(PORTF) 
	PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
	PORTF.PIN0CTRL  = PULLUP;
#endif

#if defined(USE_RTC)
	do {
		/* Wait until RTC is not busy. */
	} while (  RTC.STATUS & RTC_SYNCBUSY_bm );
	
	/* Configure RTC period to 1 millisecond. */
	RTC.PER = 0;//1ms
	RTC.CNT = 0;
	RTC.COMP = 0;
	RTC.CTRL = ( RTC.CTRL & ~RTC_PRESCALER_gm ) | RTC_PRESCALER_DIV1_gc;

	/* Enable overflow interrupt. */	
	RTC.INTCTRL = ( RTC.INTCTRL & ~( RTC_COMPINTLVL_gm | RTC_OVFINTLVL_gm ) ) |
	              RTC_OVFINTLVL_LO_gc |
	              RTC_COMPINTLVL_OFF_gc;
#endif

        /*************************************/
        /* Enable reset button               */
        initResetButton();

        /*************************************/
	/* Enable interrupts.                */
	PMIC.CTRL |= PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
	sei();
}

static void initAdc( ADC_t* adc ) {
        /* ADC INIT */

        adc->CTRLB   = 0 << ADC_CONMODE_bp      // unsigned conversion
                     | 0 << ADC_FREERUN_bp      // no freerun
                     | ADC_RESOLUTION_12BIT_gc  // 12bit resolution
                     ;

        // TODO: What should we use as analog ref?
        adc->REFCTRL = ADC_REFSEL_VCC_gc   // VCC/1.6 analog ref
                     | 0 << ADC_BANDGAP_bp // bandgap not enabled
                     | 0 << ADC_TEMPREF_bp // temerature reference not enabled
                     ;

        adc->EVCTRL = 0 << ADC_SWEEP_gp // Have to set it to something, so sweep only channel 0.
                    | 0 << ADC_EVSEL_gp // Have to set it to something, so event channels 0123.
                    | 0 << ADC_EVACT_gp // No event action
                    ;

        // TODO: What should we use as prescalar?
        // 128K times per second with 32Mhz sys clock. That's what the mega based
        // arduinos use. No idea if that is appropriate for xmegas.
        adc->PRESCALER = ADC_PRESCALER_DIV256_gc;

        adc->INTFLAGS = 0; // No interrupt on conversion complete

        /* CHANNEL INIT */

        // TODO: Perhaps we should create API so we can use all ADC channels, events, free run, etc.
        // TODO: Perhaps we should use ADC channel 3 rather than 0 ...

        adc->CH0.CTRL = 0 << ADC_CH_START_bp            // Don't start conversion yet
                      | 0 << ADC_CH_GAINFAC_gp          // 1x gain (2^0 is 1)
                      | ADC_CH_INPUTMODE_SINGLEENDED_gc // single ended
                      ;

        adc->CH0.INTCTRL = ADC_CH_INTMODE_COMPLETE_gc // Not really, below value turns interrupts off ...
                         | ADC_CH_INTLVL_OFF_gc       // Interrupt off
                         ;

        adc->CH0.INTFLAGS = 1; // Strangely enough, clears IF
	
        // Do CTRLA last so everything is initialized before we enable.
        adc->CTRLA   = 0 << ADC_DMASEL_gp   // DMA off
                     | 0 << ADC_CH0START_bp // don't start ADC
                     | 0 << ADC_FLUSH_bp    // don't flush
                     | 1 << ADC_ENABLE_bp   // enable
                     ;
}

#if defined(ADCACAL0) || defined(ADCBCAL0)
static uint8_t ReadCalibrationByte(uint8_t index)
{
    NVM_CMD = NVM_CMD_READ_CALIB_ROW_gc;
    uint8_t result = pgm_read_byte(index);
    NVM_CMD = NVM_CMD_NO_OPERATION_gc;

    return result;
}
#endif // ADCACAL0 || ADCBCAL0

// TODO: Do this only for xplain board.

static const byte resetPin = 31;

static void resetRupt() {
    if ( 1 == digitalRead(resetPin) ) {
        CCP = CCP_IOREG_gc;
        WDT.CTRL = WDT_PER_8CLK_gc
                 | WDT_ENABLE_bm
                 | WDT_CEN_bm;
    }
}

static void initResetButton() {
    attachInterrupt( resetPin, resetRupt, FALLING );
}
