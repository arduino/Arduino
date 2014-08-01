// TI File $Revision: /main/4 $
// Checkin $Date: December 16, 2009   16:54:39 $
//###########################################################################
//
// FILE:   DSP2802x_GlobalPrototypes.h
//
// TITLE:  Global prototypes for DSP2802x Examples
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef DSP2802x_GLOBALPROTOTYPES_H
#define DSP2802x_GLOBALPROTOTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*---- shared global function prototypes -----------------------------------*/
extern void InitAdc(void);
extern void InitAdcAio(void);
extern void AdcOffsetSelfCal(void);
extern void AdcChanSelect(Uint16 ch_no);
extern Uint16 AdcConversion (void);
extern void InitPeripherals(void);
extern void InitECap(void);
extern void InitECapGpio(void);
extern void InitECap1Gpio(void);
extern void InitEPwm(void);
extern void InitEPwmGpio(void);
extern void InitEPwm1Gpio(void);
extern void InitEPwm2Gpio(void);
extern void InitEPwm3Gpio(void);
#if DSP28_EPWM4
extern void InitEPwm4Gpio(void);
#endif // endif DSP28_EPWM4
extern void InitCompGpio(void);
extern void InitComp1Gpio(void);
#if DSP28_COMP2
extern void InitComp2Gpio(void);
#endif // endif DSP28_COMP2
extern void InitGpio(void);
extern void InitI2CGpio(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitSci(void);
extern void InitSciGpio(void);
extern void InitSciaGpio(void);
extern void InitSpi(void);
extern void InitSpiGpio(void);
extern void InitSpiaGpio(void);
extern void InitSysCtrl(void);
extern void InitTzGpio(void);
extern void InitXIntrupt(void);
extern void InitPll(Uint16 pllcr, Uint16 clkindiv);
extern void InitPeripheralClocks(void);
extern void EnableInterrupts(void);
extern void DSP28x_usDelay(Uint32 Count);
#define KickDog ServiceDog     // For compatiblity with previous versions
extern void ServiceDog(void);
extern void DisableDog(void);
extern Uint16 CsmUnlock(void);
extern void IntOsc1Sel (void);
extern void IntOsc2Sel (void);
extern void ExtClkSel (void);
extern int16 GetTemperatureC(int16 sensorSample); // returns temp in deg. C
extern int16 GetTemperatureK(int16 sensorSample); // returns temp in deg. K
extern void Osc1Comp(int16 sensorSample);
extern void Osc2Comp(int16 sensorSample);

// DSP28_DBGIER.asm
extern void SetDBGIER(Uint16 dbgier);

//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);

//---------------------------------------------------------------------------
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location
// in Flash to a different RUN location in internal RAM

extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP2802x_GLOBALPROTOTYPES_H

//===========================================================================
// End of file.
//===========================================================================
