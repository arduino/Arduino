/*
  ************************************************************************
  *	wiring.c
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
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
*/
#include "Energia.h"

// the clock source is set so that watch dog timer (WDT) ticks every clock
// cycle (F_CPU), and the watch dog timer ISR is called every 512 ticks.
#define TICKS_PER_WDT_OVERFLOW 512

// the whole number of microseconds per WDT overflow
#define MICROSECONDS_PER_WDT_OVERFLOW (clockCyclesToMicroseconds(TICKS_PER_WDT_OVERFLOW))

// the whole number of milliseconds per WDT overflow
#define MILLIS_INC (MICROSECONDS_PER_WDT_OVERFLOW / 1000)

// the fractional number of milliseconds per WDT overflow. 
#define FRACT_INC (MICROSECONDS_PER_WDT_OVERFLOW % 1000)
#define FRACT_MAX 1000

volatile unsigned long wdt_overflow_count = 0;
volatile unsigned long wdt_millis = 0;
volatile unsigned int wdt_fract = 0;

void initClocks(void);
void enableWatchDogIntervalMode(void);

void init()
{
        disableWatchDog();
	initClocks();
        enableWatchDogIntervalMode();
	/* Clear P2.6 and P2.7 bits to default to GPIO */
#ifdef P2SEL2_
	P2SEL &= ~(BIT6|BIT7);
#endif
        __eint();
}

void disableWatchDog()
{
        /* Diable watchdog timer */
	WDTCTL = WDTPW | WDTHOLD;
}

void enableWatchDog()
{
	enableWatchDogIntervalMode();
}

void enableWatchDogIntervalMode(void)
{
	/* WDT Password + WDT interval mode + Watchdog clock source /512 + source from SMCLK
	 * Note that we WDT is running in interval mode. WDT will not trigger a reset on expire in this mode. */
	WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDT_MDLY_0_5;
 
	/* WDT interrupt enable */
#ifdef __MSP430_HAS_SFR__
	SFRIE1 |= WDTIE;
#else
	IE1 |= WDTIE;
#endif	
}

void initClocks(void)
{
#ifdef __MSP430_HAS_BC2__
#if defined(CALBC1_16MHZ_) && F_CPU >= 16000000L
	BCSCTL1 = CALBC1_16MHZ;
	DCOCTL = CALDCO_16MHZ;
#elif defined(CALBC1_12MHZ_) && (F_CPU >= 12000000L)
	BCSCTL1 = CALBC1_12MHZ;
	DCOCTL = CALDCO_12MHZ;
#elif defined(CALBC1_8MHZ_) && (F_CPU >= 8000000L)
	BCSCTL1 = CALBC1_8MHZ;
	DCOCTL = CALDCO_8MHZ;
#elif defined(CALBC1_1MHZ_) && (F_CPU >= 1000000L)
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
#else
        #warning No Suitable Frequency found!
#endif
	/* SMCLK = DCO / DIVS = nMHz */
	BCSCTL2 &= ~(DIVS_0);
	/* ACLK = VLO = ~ 12 KHz */
        BCSCTL3 |= LFXT1S_2; 
#endif

#if defined(__MSP430_HAS_CS__) && defined(__MSP430_HAS_FRAM_FR5XX__)
    CSCTL0 = CSKEY;                // Enable Access to CS Registers
  
    CSCTL2 &= ~SELM_7;             // Clear selected Main CLK Source
    CSCTL2 |= SELM__DCOCLK;        // Use DCO as Main Clock Source
    CSCTL3 &= ~(DIVM_3 | DIVS_3);  // clear DIVM Bits
#if F_CPU >= 24000000L
    CSCTL1 = DCOFSEL0 | DCOFSEL1 | DCORSEL;    //Level 2 / Range 1 : 24.0MHz
#elif F_CPU >= 16000000L
    CSCTL1 = DCORSEL;              //Level 0 / Range 1 : 16.0MHz
#elif F_CPU >= 12000000L
    CSCTL1 = DCOFSEL0 | DCOFSEL1 | DCORSEL;    //Level 2 / Range 1 : 24.0MHz
    CSCTL3 |= DIVM_1;              // Div = 2
#elif F_CPU >= 8000000L
    CSCTL1 = DCOFSEL0 | DCOFSEL1;  //Level 2 / Range 0 : 8.0MHz
#elif F_CPU >= 1000000L
    CSCTL1 = DCOFSEL0 | DCOFSEL1;  //Level 2 / Range 0 : 8.0MHz
    CSCTL3 |= DIVM_3;              // Div = 8
#else
        #warning No Suitable Frequency found!
#endif
//    CSCTL0 = 0;                    // Disable Access to CS Registers
#endif // __MSP430_HAS_CS__

#if defined(__MSP430_HAS_CS__) && defined(__MSP430_HAS_FRAM__)
    CSCTL0 = CSKEY;                // Enable Access to CS Registers
  
    CSCTL2 &= ~SELM_7;             // Clear selected Main CLK Source
    CSCTL2 |= SELM__DCOCLK;        // Use DCO as Main Clock Source
    CSCTL3 &= ~(DIVM_3 | DIVS_3);  // clear DIVM Bits
#if F_CPU >= 24000000L
    FRCTL0 = FWPW | NACCESS_2;     // add 2 waitstaite
    CSCTL1 = DCOFSEL_6 | DCORSEL;  //Level 6 / Range 1 : 24.0MHz
#elif F_CPU >= 16000000L
    FRCTL0 = FWPW | NACCESS_1;     // add 1 waitstaite
    CSCTL1 = DCOFSEL_4 | DCORSEL;  //Level 4 / Range 1 : 16.0MHz
#elif F_CPU >= 12000000L
    FRCTL0 = FWPW | NACCESS_1;     // add 1 waitstaite
    CSCTL1 = DCOFSEL_6 | DCORSEL;  //Level 6 / Range 1 : 24.0MHz
    CSCTL3 |= DIVM_1;              // Div = 2
#elif F_CPU >= 8000000L
    CSCTL1 = DCOFSEL_3 | DCORSEL;  //Level 3 / Range 1 : 8.0MHz
#elif F_CPU >= 1000000L
    CSCTL1 = DCOFSEL_3 | DCORSEL;  //Level 3 / Range 1 : 8.0MHz
    CSCTL3 |= DIVM_3;              // Div = 8
#else
        #warning No Suitable Frequency found!
#endif
//    CSCTL0 = 0;                    // Disable Access to CS Registers
#endif // __MSP430_HAS_CS__

#if defined(__MSP430_HAS_UCS__)
     PMMCTL0_H = PMMPW_H;             // open PMM
	 SVSMLCTL &= ~SVSMLRRL_7;         // reset
	 PMMCTL0_L = PMMCOREV_0;          //
	 
	 PMMIFG &= ~(SVSMLDLYIFG|SVMLVLRIFG|SVMLIFG);  // clear flags
	 SVSMLCTL = (SVSMLCTL & ~SVSMLRRL_7) | SVSMLRRL_1;
	 while ((PMMIFG & SVSMLDLYIFG) == 0); // wait till settled
	 while ((PMMIFG & SVMLIFG) == 0); // wait for flag
	 PMMCTL0_L = (PMMCTL0_L & ~PMMCOREV_3) | PMMCOREV_1; // set VCore for lext Speed
	 while ((PMMIFG & SVMLVLRIFG) == 0);  // wait till level reached

	 PMMIFG &= ~(SVSMLDLYIFG|SVMLVLRIFG|SVMLIFG);  // clear flags
	 SVSMLCTL = (SVSMLCTL & ~SVSMLRRL_7) | SVSMLRRL_2;
	 while ((PMMIFG & SVSMLDLYIFG) == 0); // wait till settled
	 while ((PMMIFG & SVMLIFG) == 0); // wait for flag
	 PMMCTL0_L = (PMMCTL0_L & ~PMMCOREV_3) | PMMCOREV_2; // set VCore for lext Speed
	 while ((PMMIFG & SVMLVLRIFG) == 0);  // wait till level reached

	 PMMIFG &= ~(SVSMLDLYIFG|SVMLVLRIFG|SVMLIFG);  // clear flags
	 SVSMLCTL = (SVSMLCTL & ~SVSMLRRL_7) | SVSMLRRL_3;
	 while ((PMMIFG & SVSMLDLYIFG) == 0); // wait till settled
	 while ((PMMIFG & SVMLIFG) == 0); // wait for flag
	 PMMCTL0_L = (PMMCTL0_L & ~PMMCOREV_3) | PMMCOREV_3; // set VCore for lext Speed
	 while ((PMMIFG & SVMLVLRIFG) == 0);  // wait till level reached
	 
     PMMCTL0_H = 0;                   // lock PMM

     UCSCTL0 = 0;                     // set lowest Frequency
#if F_CPU >= 25000000L
     UCSCTL1 = DCORSEL_6;             //Range 6
     UCSCTL2 = 0x1176;                //Loop Control Setting
	 UCSCTL3 = SELREF__REFOCLK;       //REFO for FLL
	 UCSCTL4 = SELA__REFOCLK|SELM__DCOCLK|SELS__DCOCLK;  //Select clock sources
	 UCSCTL7 &= ~(0x07);               //Clear Fault flags
#elif F_CPU >= 24000000L
     UCSCTL1 = DCORSEL_6;             //Range 6
     UCSCTL2 = 0x116D;                //Loop Control Setting
	 UCSCTL3 = SELREF__REFOCLK;       //REFO for FLL
	 UCSCTL4 = SELA__REFOCLK|SELM__DCOCLK|SELS__DCOCLK;  //Select clock sources
	 UCSCTL7 &= ~(0x07);               //Clear Fault flags
#elif F_CPU >= 16000000L
     UCSCTL1 = DCORSEL_6;             //Range 6
     UCSCTL2 = 0x11E7;                //Loop Control Setting
	 UCSCTL3 = SELREF__REFOCLK;       //REFO for FLL
	 UCSCTL4 = SELA__REFOCLK|SELM__DCOCLKDIV|SELS__DCOCLKDIV;  //Select clock sources
	 UCSCTL7 &= ~(0x07);               //Clear Fault flags
#elif F_CPU >= 12000000L
     UCSCTL1 = DCORSEL_6;             //Range 6
     UCSCTL2 = 0x116D;                //Loop Control Setting
	 UCSCTL3 = SELREF__REFOCLK;       //REFO for FLL
	 UCSCTL4 = SELA__REFOCLK|SELM__DCOCLKDIV|SELS__DCOCLKDIV;  //Select clock sources
	 UCSCTL7 &= ~(0x07);               //Clear Fault flags
#elif F_CPU >= 8000000L
     UCSCTL1 = DCORSEL_5;             //Range 6
     UCSCTL2 = 0x10F3;                //Loop Control Setting
	 UCSCTL3 = SELREF__REFOCLK;       //REFO for FLL
	 UCSCTL4 = SELA__REFOCLK|SELM__DCOCLKDIV|SELS__DCOCLKDIV;  //Select clock sources
	 UCSCTL7 &= ~(0x07);               //Clear Fault flags
#elif F_CPU >= 1000000L
     UCSCTL1 = DCORSEL_2;             //Range 6
     UCSCTL2 = 0x101D;                //Loop Control Setting
	 UCSCTL3 = SELREF__REFOCLK;       //REFO for FLL
	 UCSCTL4 = SELA__REFOCLK|SELM__DCOCLKDIV|SELS__DCOCLKDIV;  //Select clock sources
	 UCSCTL7 &= ~(0x07);               //Clear Fault flags
#else
        #warning No Suitable Frequency found!
#endif
#endif // __MSP430_HAS_UCS__

#if defined(LOCKLPM5)
     // This part is required for FR59xx device to unlock the IOs
     PMMCTL0_H = PMMPW_H;           // open PMM
	 PM5CTL0 &= ~LOCKLPM5;          // clear lock bit for ports
     PMMCTL0_H = 0;                 // lock PMM
#endif

}
volatile uint32_t wdtCounter = 0;

unsigned long micros()
{
	unsigned long m;

	// disable interrupts to ensure consistent readings
	// safe SREG to avoid issues if interrupts were already disabled
	uint16_t oldSREG = READ_SR;
	__dint();

	m = wdt_overflow_count;

	WRITE_SR(oldSREG);	// safe to enable interrupts again

	// MSP430 does not give read access to current WDT, so we
	// have to approximate microseconds from overflows and
	// fractional milliseconds.
	// With an WDT interval of SMCLK/512, precision is +/- 256/SMCLK,
	// for example +/-256us @1MHz and +/-16us @16MHz

	return (m * MICROSECONDS_PER_WDT_OVERFLOW);
}

unsigned long millis()
{
	unsigned long m;

	// disable interrupts to ensure consistent readings
	// safe SREG to avoid issues if interrupts were already disabled
	uint16_t oldSREG = READ_SR;
	__dint();

	m = wdt_millis;

	WRITE_SR(oldSREG);	// safe to enable interrupts again

 	return m;
}

/* Delay for the given number of microseconds.  Assumes a 1, 8 or 16 MHz clock. */
void delayMicroseconds(unsigned int us)
{
#if F_CPU >= 20000000L
	/* For a one-microsecond delay, simply wait 2 cycle and return. The overhead
	 * of the function call yields a delay of exactly one microsecond. */
	__asm__ __volatile__ (
		"nop" "\n\t"
		"nop");
	if (--us == 0)
		return;

	/* The following loop takes a 1/5 of a microsecond (4 cycles)
	 * per iteration, so execute it five times for each microsecond of
	 * delay requested. */
	us = (us<<2) + us; // x5 us

	/* Account for the time taken in the preceeding commands. */
	us -= 2;

#elif F_CPU >= 16000000L
	/* For the 16 MHz clock on most boards */

	/* For a one-microsecond delay, simply return.  the overhead
	 * of the function call yields a delay of approximately 1 1/8 us. */
	if (--us == 0)
		return;

	/* The following loop takes a quarter of a microsecond (4 cycles)
	 * per iteration, so execute it four times for each microsecond of
	 * delay requested. */
	us <<= 2;

	/* Account for the time taken in the preceeding commands. */
	us -= 2;
#else
	/* For the 1 MHz */

	/* For a one- or two-microsecond delay, simply return.  the overhead of
	 * the function calls takes more than two microseconds.  can't just
	 * subtract two, since us is unsigned; we'd overflow. */
	if (--us == 0)
		return;
	if (--us == 0)
		return;

	/* The following loop takes 4 microsecond (4 cycles)
	 * per iteration, so execute it ones for each 4 microsecond of
	 * delay requested. */
	us >>= 2;

	/* Partially compensate for the time taken by the preceeding commands.
	 * we can't subtract any more than this or we'd overflow w/ small delays. */
	us--;
#endif

	/* Busy wait */
        __asm__ __volatile__ (
                /* even steven */
                "L1: nop \n\t"   
                /* 1 instruction */
                "dec.w %[us] \n\t"
                /* 2 instructions */
                "jnz L1 \n\t"
                : [us] "=r" (us) : "[us]" (us)
        );
}

/* (ab)use the WDT */
void delay(uint32_t milliseconds)
{
	uint32_t start = millis();
        while(millis() - start < milliseconds)
                /* Wait for WDT interrupt in LMP0 */
                __bis_status_register(LPM0_bits+GIE);
}

__attribute__((interrupt(WDT_VECTOR)))
void watchdog_isr (void)
{
	// copy these to local variables so they can be stored in registers
	// (volatile variables must be read from memory on every access)
	unsigned long m = wdt_millis;
	unsigned int f = wdt_fract;

	m += MILLIS_INC;
	f += FRACT_INC;
	if (f >= FRACT_MAX) {
		f -= FRACT_MAX;
		m += 1;
	}

	wdt_fract = f;
	wdt_millis = m;
	wdt_overflow_count++;

        /* Exit from LMP3 on reti (this includes LMP0) */
        __bic_status_register_on_exit(LPM3_bits);
}
