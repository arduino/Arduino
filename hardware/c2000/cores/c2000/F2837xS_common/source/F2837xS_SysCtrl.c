//###########################################################################
//
// FILE:   F2837xS_SysCtrl.c
//
// TITLE:  F2837xS Device System Control Initialization & Support Functions.
//
// DESCRIPTION:
//
//         Example initialization of system resources.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // Headerfile Include File
#include "F2837xS_Examples.h"   // Examples Include File

// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped to a load and
// run address using the linker cmd file.
//
//  *IMPORTANT*
//  IF RUNNING FROM FLASH, PLEASE COPY OVER THE SECTION "ramfuncs"  FROM FLASH
//  TO RAM PRIOR TO CALLING InitSysCtrl(). THIS PREVENTS THE MCU FROM THROWING
//  AN EXCEPTION WHEN A CALL TO DELAY_US() IS MADE. 
//
#pragma CODE_SECTION(InitFlash_Bank0, "ramfuncs");
#pragma CODE_SECTION(InitFlash_Bank1, "ramfuncs");

void InitSysCtrl(void)
{
    // Disable the watchdog
    DisableDog();

#ifdef _FLASH
// Copy time critical code and Flash setup code to RAM
// This includes the following functions:  InitFlash();
// The  RamfuncsLoadStart, RamfuncsLoadSize, and RamfuncsRunStart
// symbols are created by the linker. Refer to the device .cmd file.
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

// Call Flash Initialization to setup flash waitstates
// This function must reside in RAM
    InitFlash_Bank0();
#endif

    // *IMPORTANT*
    // The Device_cal function, which copies the ADC & oscillator calibration values
    // from TI reserved OTP into the appropriate trim registers, occurs automatically
    // in the Boot ROM. If the boot ROM code is bypassed during the debug process, the
    // following function MUST be called for the ADC and oscillators to function according
    // to specification. The clocks to the ADC MUST be enabled before calling this
    // function.
    // See the device data manual and/or the ADC Reference
    // Manual for more information.

    EALLOW;

    //enable pull-ups on unbonded IOs as soon as possible to reduce power consumption.
    GPIO_EnableUnbondedIOPullups();

	CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_D = 1;

    //check if device is trimmed
    if(*((Uint16 *)0x5D1B6) == 0x0000){
        //device is not trimmed, apply static calibration values
        AnalogSubsysRegs.ANAREFTRIMA.all = 31709;
        AnalogSubsysRegs.ANAREFTRIMB.all = 31709;
        AnalogSubsysRegs.ANAREFTRIMC.all = 31709;
        AnalogSubsysRegs.ANAREFTRIMD.all = 31709;
    }

	CpuSysRegs.PCLKCR13.bit.ADC_A = 0;
	CpuSysRegs.PCLKCR13.bit.ADC_B = 0;
	CpuSysRegs.PCLKCR13.bit.ADC_C = 0;
	CpuSysRegs.PCLKCR13.bit.ADC_D = 0;
    EDIS;

    // Initialize the PLL control: PLLCR and CLKINDIV
    // F28_PLLCR and F28_CLKINDIV are defined in F2837xS_Examples.h
    // Note: The internal oscillator CANNOT be used as the PLL source if the
    // PLLSYSCLK is configured to frequencies above 194 MHz.
    InitSysPll(XTAL_OSC,IMULT_20,FMULT_0,PLLCLK_BY_2); 		//PLLSYSCLK = 10Mhz(OSCCLK) * 40 (IMULT) * 1 (FMULT) /  2 (PLLCLK_BY_2)

    //Turn on all peripherals
	InitPeripheralClocks();

}

//---------------------------------------------------------------------------
// InitPeripheralClocks
//---------------------------------------------------------------------------
// This function initializes the clocks for the peripherals. 
//
// Note: In order to reduce power consumption, turn off the clocks to any 
// peripheral that is not specified for your part-number or is not used in the 
// application
void InitPeripheralClocks()
{
	EALLOW;

	CpuSysRegs.PCLKCR0.bit.CLA1 = 1;
	CpuSysRegs.PCLKCR0.bit.DMA = 1;
	CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
	CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1;
	CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1;
	CpuSysRegs.PCLKCR0.bit.HRPWM = 1;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;

	CpuSysRegs.PCLKCR1.bit.EMIF1 = 1;
	CpuSysRegs.PCLKCR1.bit.EMIF2 = 1;

	CpuSysRegs.PCLKCR2.bit.EPWM1 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM2 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM3 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM4 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM5 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM6 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM7 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM8 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM9 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM10 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM11 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM12 = 1;

	CpuSysRegs.PCLKCR3.bit.ECAP1 = 1;
	CpuSysRegs.PCLKCR3.bit.ECAP2 = 1;
	CpuSysRegs.PCLKCR3.bit.ECAP3 = 1;
	CpuSysRegs.PCLKCR3.bit.ECAP4 = 1;
	CpuSysRegs.PCLKCR3.bit.ECAP5 = 1;
	CpuSysRegs.PCLKCR3.bit.ECAP6 = 1;

	CpuSysRegs.PCLKCR4.bit.EQEP1 = 1;
	CpuSysRegs.PCLKCR4.bit.EQEP2 = 1;
	CpuSysRegs.PCLKCR4.bit.EQEP3 = 1;

	CpuSysRegs.PCLKCR6.bit.SD1 = 1;
	CpuSysRegs.PCLKCR6.bit.SD2 = 1;

	CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
	CpuSysRegs.PCLKCR7.bit.SCI_B = 1;
	CpuSysRegs.PCLKCR7.bit.SCI_C = 1;
	CpuSysRegs.PCLKCR7.bit.SCI_D = 1;

	CpuSysRegs.PCLKCR8.bit.SPI_A = 1;
	CpuSysRegs.PCLKCR8.bit.SPI_B = 1;
	CpuSysRegs.PCLKCR8.bit.SPI_C = 1;

	CpuSysRegs.PCLKCR9.bit.I2C_A = 1;
	CpuSysRegs.PCLKCR9.bit.I2C_B = 1;

	CpuSysRegs.PCLKCR10.bit.CAN_A = 1;
	CpuSysRegs.PCLKCR10.bit.CAN_B = 1;

	CpuSysRegs.PCLKCR11.bit.McBSP_A = 1;
	CpuSysRegs.PCLKCR11.bit.McBSP_B = 1;
	CpuSysRegs.PCLKCR11.bit.USB_A = 1;

	CpuSysRegs.PCLKCR12.bit.uPP_A = 1;

	CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_D = 1;

	CpuSysRegs.PCLKCR14.bit.CMPSS1 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS2 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS3 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS4 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS5 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS6 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS7 = 1;
	CpuSysRegs.PCLKCR14.bit.CMPSS8 = 1;

	CpuSysRegs.PCLKCR16.bit.DAC_A = 1;
	CpuSysRegs.PCLKCR16.bit.DAC_B = 1;
	CpuSysRegs.PCLKCR16.bit.DAC_C = 1;
	
	EDIS;
}

void DisablePeripheralClocks()
{
	EALLOW;

	CpuSysRegs.PCLKCR0.all = 0;
	CpuSysRegs.PCLKCR1.all = 0;
	CpuSysRegs.PCLKCR2.all = 0;
	CpuSysRegs.PCLKCR3.all = 0;
	CpuSysRegs.PCLKCR4.all = 0;
	CpuSysRegs.PCLKCR6.all = 0;
	CpuSysRegs.PCLKCR7.all = 0;
	CpuSysRegs.PCLKCR8.all = 0;
	CpuSysRegs.PCLKCR9.all = 0;
	CpuSysRegs.PCLKCR10.all = 0;
	CpuSysRegs.PCLKCR11.all = 0;
	CpuSysRegs.PCLKCR12.all = 0;
	CpuSysRegs.PCLKCR13.all = 0;
	CpuSysRegs.PCLKCR14.all = 0;
	CpuSysRegs.PCLKCR16.all = 0;
	
	EDIS;
}

//---------------------------------------------------------------------------
// Example: InitFlash_Bank0
//---------------------------------------------------------------------------
// This function initializes the Flash Control registers for Bank0

void InitFlash_Bank0(void)
{
    EALLOW;

    //At reset bank and pump are in sleep
    //A Flash access will power up the bank and pump automatically
    //After a Flash access, bank and pump go to low power mode (configurable in FBFALLBACK/FPAC1 registers)-
    //if there is no further access to flash
    //Power up Flash bank and pump and this also sets the fall back mode of flash and pump as active
    Flash0CtrlRegs.FPAC1.bit.PMPPWR = 0x1;
    Flash0CtrlRegs.FBFALLBACK.bit.BNKPWR0 = 0x3;

    //Disable Cache and prefetch mechanism before changing wait states
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN = 0;
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN = 0;

    //Set waitstates according to frequency
    //                CAUTION
    //Minimum waitstates required for the flash operating
    //at a given CPU rate must be characterized by TI.
    //Refer to the datasheet for the latest information.
    #if CPU_FRQ_200MHZ
    Flash0CtrlRegs.FRDCNTL.bit.RWAIT = 0x3;
    #endif

    #if CPU_FRQ_150MHZ
    Flash0CtrlRegs.FRDCNTL.bit.RWAIT = 0x2;
    #endif

    #if CPU_FRQ_120MHZ
    Flash0CtrlRegs.FRDCNTL.bit.RWAIT = 0x2;
    #endif

    //Enable Cache and prefetch mechanism to improve performance
    //of code executed from Flash.
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN = 1;
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN = 1;

    //At reset, ECC is enabled
    //If it is disabled by application software and if application again wants to enable ECC
    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;

    EDIS;

    //Force a pipeline flush to ensure that the write to
    //the last register configured occurs before returning.

    __asm(" RPT #7 || NOP");

}

//---------------------------------------------------------------------------
// Example: InitFlash_Bank1
//---------------------------------------------------------------------------
// This function initializes the Flash Control registers for Bank1

void InitFlash_Bank1(void)
{
    EALLOW;

    //At reset bank and pump are in sleep
    //A Flash access will power up the bank and pump automatically
    //After a Flash access, bank and pump go to low power mode (configurable in FBFALLBACK/FPAC1 registers)-
    //if there is no further access to flash
    //Power up Flash bank and pump and this also sets the fall back mode of flash and pump as active
    Flash1CtrlRegs.FPAC1.bit.PMPPWR = 0x1;
    Flash1CtrlRegs.FBFALLBACK.bit.BNKPWR0 = 0x3;

    //Disable Cache and prefetch mechanism before changing wait states
    Flash1CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN = 0;
    Flash1CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN = 0;

    //Set waitstates according to frequency
    //                CAUTION
    //Minimum waitstates required for the flash operating
    //at a given CPU rate must be characterized by TI.
    //Refer to the datasheet for the latest information.
    #if CPU_FRQ_200MHZ
    Flash1CtrlRegs.FRDCNTL.bit.RWAIT = 0x3;
    #endif

    #if CPU_FRQ_150MHZ
    Flash1CtrlRegs.FRDCNTL.bit.RWAIT = 0x2;
    #endif

    #if CPU_FRQ_120MHZ
    Flash1CtrlRegs.FRDCNTL.bit.RWAIT = 0x2;
    #endif

    //Enable Cache and prefetch mechanism to improve performance
    //of code executed from Flash.
    Flash1CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN = 1;
    Flash1CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN = 1;

    //At reset, ECC is enabled
    //If it is disabled by application software and if application again wants to enable ECC
    Flash1EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;

    EDIS;

    //Force a pipeline flush to ensure that the write to
    //the last register configured occurs before returning.

    __asm(" RPT #7 || NOP");

}

//---------------------------------------------------------------------------
// Example: ServiceDog:
//---------------------------------------------------------------------------
// This function resets the watchdog timer.
// Enable this function for using ServiceDog in the application

void ServiceDog(void)
{
    EALLOW;
    WdRegs.WDKEY.bit.WDKEY = 0x0055;
    WdRegs.WDKEY.bit.WDKEY = 0x00AA;
    EDIS;
}

//---------------------------------------------------------------------------
// Example: DisableDog:
//---------------------------------------------------------------------------
// This function disables the watchdog timer.

void DisableDog(void)
{
	volatile Uint16 temp;
    EALLOW;
    //Grab the clock config so we don't clobber it
    temp = WdRegs.WDCR.all & 0x0007;
    WdRegs.WDCR.all = 0x0068 | temp;
    EDIS;
}

//---------------------------------------------------------------------------
// Example: InitPll:
//---------------------------------------------------------------------------
// This function initializes the PLL registers.
//
// Note: The internal oscillator CANNOT be used as the PLL source if the
// PLLSYSCLK is configured to frequencies above 194 MHz.

void InitSysPll(Uint16 clock_source, Uint16 imult, Uint16 fmult, Uint16 divsel)
{
    if((clock_source == ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL)    &&
      (imult         == ClkCfgRegs.SYSPLLMULT.bit.IMULT)           &&
      (fmult         == ClkCfgRegs.SYSPLLMULT.bit.FMULT)           &&
      (divsel        == ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV))
    {
        //everything is set as required, so just return
        return;
    }

    if(clock_source != ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL)
    {
        switch (clock_source)
        {
            case INT_OSC1:
                SysIntOsc1Sel();
                break;

            case INT_OSC2:
                SysIntOsc2Sel();
                break;

            case XTAL_OSC:
                SysXtalOscSel();
                break;
        }
    }

    EALLOW;
     // first modify the PLL multipliers
    if(imult != ClkCfgRegs.SYSPLLMULT.bit.IMULT || fmult != ClkCfgRegs.SYSPLLMULT.bit.FMULT)
    {
        // Bypass PLL and set dividers to /1
        ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 0;
        ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 0;

        // Program PLL multipliers
        Uint32 temp_syspllmult = ClkCfgRegs.SYSPLLMULT.all;
        ClkCfgRegs.SYSPLLMULT.all = ((temp_syspllmult & ~(0x37FU)) | 
                                     ((fmult << 8U) | imult));
                                     
        ClkCfgRegs.SYSPLLCTL1.bit.PLLEN = 1;            // Enable SYSPLL

        // Wait for the SYSPLL lock
        while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1)
        {
            // Uncomment to service the watchdog
            // ServiceDog();
        }

        // Write a multiplier again to ensure proper PLL initialization
        // This will force the PLL to lock a second time
        ClkCfgRegs.SYSPLLMULT.bit.IMULT = imult;        // Setting integer multiplier

        // Wait for the SYSPLL re-lock
        while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1)
        {
            // Uncomment to service the watchdog
            // ServiceDog();
        }
    }

    // Set divider to produce slower output frequency to limit current increase
    if(divsel != PLLCLK_BY_126)
    {
         ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = divsel + 1;
    }else
    {
         ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = divsel;
    }

    // Enable PLLSYSCLK is fed from system PLL clock
    ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 1;

    // Small 100 cycle delay
    asm(" RPT #100 || NOP");

    // Set the divider to user value
    ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = divsel;
    EDIS;
}


//---------------------------------------------------------------------------
// Example: InitPll2:
//---------------------------------------------------------------------------
// This function initializes the PLL2 registers.
//
// Note: The internal oscillator CANNOT be used as the PLL source if the
// PLLSYSCLK is configured to frequencies above 194 MHz.

void InitAuxPll(Uint16 clock_source, Uint16 imult, Uint16 fmult, Uint16 divsel)
{
	Uint16 temp_divsel;

	if((clock_source == ClkCfgRegs.CLKSRCCTL2.bit.AUXOSCCLKSRCSEL)   &&
	  (imult		 == ClkCfgRegs.AUXPLLMULT.bit.IMULT) 	      &&
	  (fmult 	     == ClkCfgRegs.AUXPLLMULT.bit.FMULT)          &&
	  (divsel        == ClkCfgRegs.AUXCLKDIVSEL.bit.AUXPLLDIV))
    {
	    //everything is set as required, so just return
	    return;
	}

	switch (clock_source)
	{

		case INT_OSC2:
			AuxIntOsc2Sel();
			break;

		case XTAL_OSC:
			AuxXtalOscSel();
			break;

		case AUXCLKIN:
			AuxAuxClkSel();
			break;

	}

   // Change the SYSPLL Integer Multiplier (or) SYSPLL Fractional Multiplier
   if(ClkCfgRegs.AUXPLLMULT.bit.IMULT != imult || ClkCfgRegs.AUXPLLMULT.bit.FMULT !=fmult)
   {
	   EALLOW;
	   ClkCfgRegs.AUXCLKDIVSEL.bit.AUXPLLDIV = AUXPLLRAWCLK_BY_8;
       
       //Set integer and fractional multiplier     
       Uint32 temp_auxpllmult = ClkCfgRegs.AUXPLLMULT.all;
       ClkCfgRegs.AUXPLLMULT.all = ((temp_auxpllmult & ~(0x37FU)) | 
                                    ((fmult << 8U) | imult));
                                    
	   ClkCfgRegs.AUXPLLCTL1.bit.PLLEN = 1;			//Enable AUXPLL
	   EDIS;

	   //Wait for the AUXPLL lock
	   while(ClkCfgRegs.AUXPLLSTS.bit.LOCKS != 1)
	   {
	        // Uncomment to service the watchdog
	        // ServiceDog();
	   }
       
       // Write a multiplier again to ensure proper PLL initialization
       // This will force the PLL to lock a second time
       EALLOW;
       ClkCfgRegs.AUXPLLMULT.bit.IMULT = imult;        // Setting integer multiplier       
       EDIS;
       
       //Wait for the AUXPLL lock
	   while(ClkCfgRegs.AUXPLLSTS.bit.LOCKS != 1)
	   {
	        // Uncomment to service the watchdog
	        // ServiceDog();
	   }
   }

	 //increase the freq. of operation in steps to avoid any VDD fluctuations
	 temp_divsel = AUXPLLRAWCLK_BY_8;
	 while(ClkCfgRegs.AUXCLKDIVSEL.bit.AUXPLLDIV != divsel)
	 {
		 EALLOW;
		 ClkCfgRegs.AUXCLKDIVSEL.bit.AUXPLLDIV = temp_divsel - 1;
		 EDIS;

		 temp_divsel = temp_divsel - 1;
		 if(ClkCfgRegs.AUXCLKDIVSEL.bit.AUXPLLDIV != divsel)
		 {
			 DELAY_US(15L);
		 }
	 }

   EALLOW;
   ClkCfgRegs.AUXPLLCTL1.bit.PLLCLKEN = 1;			//Enable AUXPLLCLK is fed from AUX PLL
   EDIS;
}

//---------------------------------------------------------------------------
// Example: CsmUnlock:
//---------------------------------------------------------------------------
// This function unlocks the CSM. User must replace 0xFFFF's with current
// password for the DSP. Returns 1 if unlock is successful.

#define STATUS_FAIL          0
#define STATUS_SUCCESS       1

Uint16 CsmUnlock()
{
    volatile Uint16 temp;

    // Load the key registers with the current password. The 0xFFFF's are dummy
    // passwords.  User should replace them with the correct password for the DSP.

    EALLOW;
//    CsmRegs.KEY0 = 0xFFFF;
//    CsmRegs.KEY1 = 0xFFFF;
//    CsmRegs.KEY2 = 0xFFFF;
//    CsmRegs.KEY3 = 0xFFFF;
//    CsmRegs.KEY4 = 0xFFFF;
//    CsmRegs.KEY5 = 0xFFFF;
//    CsmRegs.KEY6 = 0xFFFF;
//    CsmRegs.KEY7 = 0xFFFF;

    DcsmZ1Regs.Z1_CSMKEY0 = 0xFFFFFFFF;
    DcsmZ1Regs.Z1_CSMKEY1 = 0xFFFFFFFF;
    DcsmZ1Regs.Z1_CSMKEY2 = 0xFFFFFFFF;
    DcsmZ1Regs.Z1_CSMKEY3  = 0xFFFFFFFF;

    DcsmZ2Regs.Z2_CSMKEY0 = 0xFFFFFFFF;
    DcsmZ2Regs.Z2_CSMKEY1 = 0xFFFFFFFF;
    DcsmZ2Regs.Z2_CSMKEY2 = 0xFFFFFFFF;
    DcsmZ2Regs.Z2_CSMKEY3  = 0xFFFFFFFF;
    EDIS;

    // Perform a dummy read of the password locations
    // if they match the key values, the CSM will unlock

//    temp = CsmPwl.PSWD0;
//    temp = CsmPwl.PSWD1;
//    temp = CsmPwl.PSWD2;
//    temp = CsmPwl.PSWD3;
//    temp = CsmPwl.PSWD4;
//    temp = CsmPwl.PSWD5;
//    temp = CsmPwl.PSWD6;
//    temp = CsmPwl.PSWD7;

    // If the CSM unlocked, return success, otherwise return
    // failure.
//    if (CsmRegs.CSMSCR.bit.SECURE == 0) return STATUS_SUCCESS;
//    else return STATUS_FAIL;

    return 0;

}

//---------------------------------------------------------------------------
// Example: SysIntOsc1Sel:
//---------------------------------------------------------------------------
// This function switches to Internal Oscillator 1 and turns off all other clock
// sources to minimize power consumption

void SysIntOsc1Sel (void) {
    EALLOW;
    ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 2; // Clk Src = INTOSC1
    EDIS;
}

//---------------------------------------------------------------------------
// Example: SysIntOsc2Sel:
//---------------------------------------------------------------------------
// This function switches to Internal oscillator 2 from External Oscillator
// and turns off all other clock sources to minimize power consumption
// NOTE: If there is no external clock connection, when switching from
//       INTOSC1 to INTOSC2, EXTOSC and XLCKIN must be turned OFF prior
//       to switching to internal oscillator 1

void SysIntOsc2Sel (void) {

    EALLOW;
    ClkCfgRegs.CLKSRCCTL1.bit.INTOSC2OFF=0;     // Turn on INTOSC2
    ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 0; // Clk Src = INTOSC2
    EDIS;

}

//---------------------------------------------------------------------------
// Example: SysXtalOscSel:
//---------------------------------------------------------------------------
// This function switches to External CRYSTAL oscillator and turns off all other clock
// sources to minimize power consumption. This option may not be available on all
// device packages

void SysXtalOscSel (void)  {

    EALLOW;
    ClkCfgRegs.CLKSRCCTL1.bit.XTALOFF=0;        // Turn on XTALOSC
    ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 1; // Clk Src = XTAL
    EDIS;

}

//---------------------------------------------------------------------------
// Example: AuxIntOsc2Sel:
//---------------------------------------------------------------------------
// This function switches to Internal oscillator 2 from External Oscillator
// and turns off all other clock sources to minimize power consumption
// NOTE: If there is no external clock connection, when switching from
//       INTOSC1 to INTOSC2, EXTOSC and XLCKIN must be turned OFF prior
//       to switching to internal oscillator 1

void AuxIntOsc2Sel (void) {

    EALLOW;
    ClkCfgRegs.CLKSRCCTL1.bit.INTOSC2OFF=0;     // Turn on INTOSC2
    ClkCfgRegs.CLKSRCCTL2.bit.AUXOSCCLKSRCSEL = 0; // Clk Src = INTOSC2
    EDIS;

}

//---------------------------------------------------------------------------
// Example: AuxXtalOscSel:
//---------------------------------------------------------------------------
// This function switches to External CRYSTAL oscillator and turns off all other clock
// sources to minimize power consumption. This option may not be available on all
// device packages

void AuxXtalOscSel (void)  {

    EALLOW;
    ClkCfgRegs.CLKSRCCTL1.bit.XTALOFF=0;        // Turn on XTALOSC
    ClkCfgRegs.CLKSRCCTL2.bit.AUXOSCCLKSRCSEL = 1; // Clk Src = XTAL
    EDIS;

}

//---------------------------------------------------------------------------
// Example: AuxAUXCLKOscSel:
//---------------------------------------------------------------------------
// This function switches to External CRYSTAL oscillator and turns off all other clock
// sources to minimize power consumption. This option may not be available on all
// device packages

void AuxAuxClkSel (void)  {

    EALLOW;
    ClkCfgRegs.CLKSRCCTL2.bit.AUXOSCCLKSRCSEL = 2; // Clk Src = XTAL
    EDIS;

}


//Enter IDLE mode
void IDLE()
{
	EALLOW;
	CpuSysRegs.LPMCR.bit.LPM = LPM_IDLE;
	EDIS;
	asm(" IDLE");
}

//Enter STANDBY mode
void STANDBY()
{
	EALLOW;
	CpuSysRegs.LPMCR.bit.LPM = LPM_STANDBY;
	EDIS;
	asm(" IDLE");
}

//Enter HALT mode
void HALT()
{
    EALLOW;
    CpuSysRegs.LPMCR.bit.LPM = LPM_HALT;
    ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 0;
    ClkCfgRegs.SYSPLLCTL1.bit.PLLEN = 0;
    EDIS;
    asm(" IDLE");
}

//Enter HIB mode
void HIB()
{
    EALLOW;
    CpuSysRegs.LPMCR.bit.LPM = LPM_HIB;
    EDIS;
    DisablePeripheralClocks();
    EALLOW;
    ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 0;
    ClkCfgRegs.SYSPLLCTL1.bit.PLLEN = 0;
    EDIS;
    asm(" IDLE");   
}
