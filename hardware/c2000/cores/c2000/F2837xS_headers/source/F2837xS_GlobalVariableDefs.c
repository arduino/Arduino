//###########################################################################
//
// FILE:    F2837xS_GlobalVariableDefs.c
//
// TITLE:   F2837xS Global Variables and Data Section Pragmas.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // F2837xS Headerfile Include File

//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcaRegsFile")
#else
#pragma DATA_SECTION(AdcaRegs,"AdcaRegsFile");
#endif
volatile struct ADC_REGS AdcaRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("AdcbRegsFile")
#else
#pragma DATA_SECTION(AdcbRegs,"AdcbRegsFile");
#endif
volatile struct ADC_REGS AdcbRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("AdccRegsFile")
#else
#pragma DATA_SECTION(AdccRegs,"AdccRegsFile");
#endif
volatile struct ADC_REGS AdccRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("AdcdRegsFile")
#else
#pragma DATA_SECTION(AdcdRegs,"AdcdRegsFile");
#endif
volatile struct ADC_REGS AdcdRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcaResultFile")
#else
#pragma DATA_SECTION(AdcaResultRegs,"AdcaResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcaResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcbResultFile")
#else
#pragma DATA_SECTION(AdcbResultRegs,"AdcbResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcbResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdccResultFile")
#else
#pragma DATA_SECTION(AdccResultRegs,"AdccResultFile");
#endif
volatile struct ADC_RESULT_REGS AdccResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcdResultFile")
#else
#pragma DATA_SECTION(AdcdResultRegs,"AdcdResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcdResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AnalogSubsysRegsFile")
#else
#pragma DATA_SECTION(AnalogSubsysRegs,"AnalogSubsysRegsFile");
#endif
volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss1RegsFile")
#else
#pragma DATA_SECTION(Cmpss1Regs,"Cmpss1RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss2RegsFile")
#else
#pragma DATA_SECTION(Cmpss2Regs,"Cmpss2RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss3RegsFile")
#else
#pragma DATA_SECTION(Cmpss3Regs,"Cmpss3RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss4RegsFile")
#else
#pragma DATA_SECTION(Cmpss4Regs,"Cmpss4RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss5RegsFile")
#else
#pragma DATA_SECTION(Cmpss5Regs,"Cmpss5RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss6RegsFile")
#else
#pragma DATA_SECTION(Cmpss6Regs,"Cmpss6RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss7RegsFile")
#else
#pragma DATA_SECTION(Cmpss7Regs,"Cmpss7RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss8RegsFile")
#else
#pragma DATA_SECTION(Cmpss8Regs,"Cmpss8RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss8Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DacaRegsFile")
#else
#pragma DATA_SECTION(DacaRegs,"DacaRegsFile");
#endif
volatile struct DAC_REGS DacaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DacbRegsFile")
#else
#pragma DATA_SECTION(DacbRegs,"DacbRegsFile");
#endif
volatile struct DAC_REGS DacbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DaccRegsFile")
#else
#pragma DATA_SECTION(DaccRegs,"DaccRegsFile");
#endif
volatile struct DAC_REGS DaccRegs;
//----------------------------------------

#ifdef __cplusplus
#pragma DATA_SECTION("Cla1RegsFile")
#else
#pragma DATA_SECTION(Cla1Regs,"Cla1RegsFile");
#endif
volatile struct CLA_REGS Cla1Regs;
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cla1SoftIntRegsFile")
#else
#pragma DATA_SECTION(Cla1SoftIntRegs,"Cla1SoftIntRegsFile");
#endif
volatile struct CLA_SOFTINT_REGS Cla1SoftIntRegs;
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ClkCfgRegsFile")
#else
#pragma DATA_SECTION(ClkCfgRegs,"ClkCfgRegsFile");
#endif
volatile struct CLK_CFG_REGS ClkCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuSysRegsFile")
#else
#pragma DATA_SECTION(CpuSysRegs,"CpuSysRegsFile");
#endif
volatile struct CPU_SYS_REGS CpuSysRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer0RegsFile")
#else
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer1RegsFile")
#else
#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer2RegsFile")
#else
#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ1RegsFile")
#else
#pragma DATA_SECTION(DcsmZ1Regs,"DcsmZ1RegsFile");
#endif
volatile struct DCSM_Z1_REGS DcsmZ1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ2RegsFile")
#else
#pragma DATA_SECTION(DcsmZ2Regs,"DcsmZ2RegsFile");
#endif
volatile struct DCSM_Z2_REGS DcsmZ2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmCommonRegsFile")
#else
#pragma DATA_SECTION(DcsmCommonRegs,"DcsmCommonRegsFile");
#endif
volatile struct DCSM_COMMON_REGS DcsmCommonRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ1OtpFile")
#else
#pragma DATA_SECTION(DcsmZ1Otp,"DcsmZ1OtpFile");
#endif
volatile struct DCSM_Z1_OTP DcsmZ1Otp;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ2OtpFile")
#else
#pragma DATA_SECTION(DcsmZ2Otp,"DcsmZ2OtpFile");
#endif
volatile struct DCSM_Z2_OTP DcsmZ2Otp;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaRegsFile")
#else
#pragma DATA_SECTION(DmaRegs,"DmaRegsFile");
#endif
volatile struct DMA_REGS DmaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaClaSrcSelRegsFile")
#else
#pragma DATA_SECTION(DmaClaSrcSelRegs,"DmaClaSrcSelRegsFile");
#endif
volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DevCfgRegsFile")
#else
#pragma DATA_SECTION(DevCfgRegs,"DevCfgRegsFile");
#endif
volatile struct DEV_CFG_REGS DevCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap1RegsFile")
#else
#pragma DATA_SECTION(ECap1Regs,"ECap1RegsFile");
#endif
volatile struct ECAP_REGS ECap1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap2RegsFile")
#else
#pragma DATA_SECTION(ECap2Regs,"ECap2RegsFile");
#endif
volatile struct ECAP_REGS ECap2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap3RegsFile")
#else
#pragma DATA_SECTION(ECap3Regs,"ECap3RegsFile");
#endif
volatile struct ECAP_REGS ECap3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap4RegsFile")
#else
#pragma DATA_SECTION(ECap4Regs,"ECap4RegsFile");
#endif
volatile struct ECAP_REGS ECap4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap5RegsFile")
#else
#pragma DATA_SECTION(ECap5Regs,"ECap5RegsFile");
#endif
volatile struct ECAP_REGS ECap5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap6RegsFile")
#else
#pragma DATA_SECTION(ECap6Regs,"ECap6RegsFile");
#endif
volatile struct ECAP_REGS ECap6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif1RegsFile")
#else
#pragma DATA_SECTION(Emif1Regs,"Emif1RegsFile");
#endif
volatile struct EMIF_REGS  Emif1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif2RegsFile")
#else
#pragma DATA_SECTION(Emif2Regs,"Emif2RegsFile");
#endif
volatile struct EMIF_REGS  Emif2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep1RegsFile")
#else
#pragma DATA_SECTION(EQep1Regs,"EQep1RegsFile");
#endif
volatile struct EQEP_REGS EQep1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep2RegsFile")
#else
#pragma DATA_SECTION(EQep2Regs,"EQep2RegsFile");
#endif
volatile struct EQEP_REGS EQep2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep3RegsFile")
#else
#pragma DATA_SECTION(EQep3Regs,"EQep3RegsFile");
#endif
volatile struct EQEP_REGS EQep3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm1RegsFile")
#else
#pragma DATA_SECTION(EPwm1Regs,"EPwm1RegsFile");
#endif
volatile struct EPWM_REGS EPwm1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm2RegsFile")
#else
#pragma DATA_SECTION(EPwm2Regs,"EPwm2RegsFile");
#endif
volatile struct EPWM_REGS EPwm2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm3RegsFile")
#else
#pragma DATA_SECTION(EPwm3Regs,"EPwm3RegsFile");
#endif
volatile struct EPWM_REGS EPwm3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm4RegsFile")
#else
#pragma DATA_SECTION(EPwm4Regs,"EPwm4RegsFile");
#endif
volatile struct EPWM_REGS EPwm4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm5RegsFile")
#else
#pragma DATA_SECTION(EPwm5Regs,"EPwm5RegsFile");
#endif
volatile struct EPWM_REGS EPwm5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm6RegsFile")
#else
#pragma DATA_SECTION(EPwm6Regs,"EPwm6RegsFile");
#endif
volatile struct EPWM_REGS EPwm6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm7RegsFile")
#else
#pragma DATA_SECTION(EPwm7Regs,"EPwm7RegsFile");
#endif
volatile struct EPWM_REGS EPwm7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm8RegsFile")
#else
#pragma DATA_SECTION(EPwm8Regs,"EPwm8RegsFile");
#endif
volatile struct EPWM_REGS EPwm8Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm9RegsFile")
#else
#pragma DATA_SECTION(EPwm9Regs,"EPwm9RegsFile");
#endif
volatile struct EPWM_REGS EPwm9Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm10RegsFile")
#else
#pragma DATA_SECTION(EPwm10Regs,"EPwm10RegsFile");
#endif
volatile struct EPWM_REGS EPwm10Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm11RegsFile")
#else
#pragma DATA_SECTION(EPwm11Regs,"EPwm11RegsFile");
#endif
volatile struct EPWM_REGS EPwm11Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm12RegsFile")
#else
#pragma DATA_SECTION(EPwm12Regs,"EPwm12RegsFile");
#endif
volatile struct EPWM_REGS EPwm12Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwmXbarRegsFile")
#else
#pragma DATA_SECTION(EPwmXbarRegs,"EPwmXbarRegsFile");
#endif
volatile struct EPWM_XBAR_REGS EPwmXbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioCtrlRegsFile")
#else
#pragma DATA_SECTION(GpioCtrlRegs,"GpioCtrlRegsFile");
#endif
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioDataRegsFile")
#else
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("InputXbarRegsFile")
#else
#pragma DATA_SECTION(InputXbarRegs,"InputXbarRegsFile");
#endif
volatile struct INPUT_XBAR_REGS InputXbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XbarRegsFile")
#else
#pragma DATA_SECTION(XbarRegs,"XbarRegsFile");
#endif
volatile struct XBAR_REGS XbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("OutputXbarRegsFile")
#else
#pragma DATA_SECTION(OutputXbarRegs,"OutputXbarRegsFile");
#endif
volatile struct OUTPUT_XBAR_REGS OutputXbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2caRegsFile")
#else
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
#endif
volatile struct I2C_REGS I2caRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2cbRegsFile")
#else
#pragma DATA_SECTION(I2cbRegs,"I2cbRegsFile");
#endif
volatile struct I2C_REGS I2cbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FlashPumpSemaphoreRegsFile")
#else
#pragma DATA_SECTION(FlashPumpSemaphoreRegs,"FlashPumpSemaphoreRegsFile");
#endif
volatile struct FLASH_PUMP_SEMAPHORE_REGS FlashPumpSemaphoreRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspaRegsFile")
#else
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
#endif
volatile struct McBSP_REGS McbspaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("RomPrefetchRegsFile")
#else
#pragma DATA_SECTION(RomPrefetchRegs,"RomPrefetchRegsFile");
#endif
volatile struct ROM_PREFETCH_REGS RomPrefetchRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("MemCfgRegsFile")
#else
#pragma DATA_SECTION(MemCfgRegs,"MemCfgRegsFile");
#endif
volatile struct MEM_CFG_REGS MemCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif1ConfigRegsFile")
#else
#pragma DATA_SECTION(Emif1ConfigRegs,"Emif1ConfigRegsFile");
#endif
volatile struct EMIF1_CONFIG_REGS Emif1ConfigRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif2ConfigRegsFile")
#else
#pragma DATA_SECTION(Emif2ConfigRegs,"Emif2ConfigRegsFile");
#endif
volatile struct EMIF2_CONFIG_REGS Emif2ConfigRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("RomWaitStateRegsFile")
#else
#pragma DATA_SECTION(RomWaitStateRegs,"RomWaitStateRegsFile");
#endif
volatile struct ROM_WAIT_STATE_REGS RomWaitStateRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AccessProtectionRegsFile")
#else
#pragma DATA_SECTION(AccessProtectionRegs,"AccessProtectionRegsFile");
#endif
volatile struct ACCESS_PROTECTION_REGS AccessProtectionRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("MemoryErrorRegsFile")
#else
#pragma DATA_SECTION(MemoryErrorRegs,"MemoryErrorRegsFile");
#endif
volatile struct MEMORY_ERROR_REGS MemoryErrorRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspbRegsFile")
#else
#pragma DATA_SECTION(McbspbRegs,"McbspbRegsFile");
#endif
volatile struct McBSP_REGS McbspbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("NmiIntruptRegsFile")
#else
#pragma DATA_SECTION(NmiIntruptRegs,"NmiIntruptRegsFile");
#endif
volatile struct NMI_INTRUPT_REGS NmiIntruptRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieCtrlRegsFile")
#else
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
#endif
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieVectTableFile")
#else
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
#endif
volatile struct PIE_VECT_TABLE PieVectTable;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SciaRegsFile")
#else
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
#endif
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScibRegsFile")
#else
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
#endif
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScicRegsFile")
#else
#pragma DATA_SECTION(ScicRegs,"ScicRegsFile");
#endif
volatile struct SCI_REGS ScicRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScidRegsFile")
#else
#pragma DATA_SECTION(ScidRegs,"ScidRegsFile");
#endif
volatile struct SCI_REGS ScidRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpiaRegsFile")
#else
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
#endif
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpibRegsFile")
#else
#pragma DATA_SECTION(SpibRegs,"SpibRegsFile");
#endif
volatile struct SPI_REGS SpibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpicRegsFile")
#else
#pragma DATA_SECTION(SpicRegs,"SpicRegsFile");
#endif
volatile struct SPI_REGS SpicRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Sdfm1RegsFile")
#else
#pragma DATA_SECTION(Sdfm1Regs,"Sdfm1RegsFile");
#endif
volatile struct SDFM_REGS Sdfm1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Sdfm2RegsFile")
#else
#pragma DATA_SECTION(Sdfm2Regs,"Sdfm2RegsFile");
#endif
volatile struct SDFM_REGS Sdfm2Regs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SyncSocRegsFile")
#else
#pragma DATA_SECTION(SyncSocRegs,"SyncSocRegsFile");
#endif
volatile struct SYNC_SOC_REGS SyncSocRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("UppRegsFile")
#else
#pragma DATA_SECTION(UppRegs,"UppRegsFile");
#endif
volatile struct UPP_REGS UppRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("WdRegsFile")
#else
#pragma DATA_SECTION(WdRegs,"WdRegsFile");
#endif
volatile struct WD_REGS WdRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XintRegsFile")
#else
#pragma DATA_SECTION(XintRegs,"XintRegsFile");
#endif
volatile struct XINT_REGS XintRegs;


//--------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EmuKeyVar");
#else
#pragma DATA_SECTION(EmuKey,"EmuKeyVar");
#endif
Uint16 EmuKey;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EmuBModeVar");
#else
#pragma DATA_SECTION(EmuBMode,"EmuBModeVar");
#endif
Uint16 EmuBMode;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash0EccRegsFile")
#else
#pragma DATA_SECTION(Flash0EccRegs,"Flash0EccRegsFile");
#endif
volatile struct FLASH_ECC_REGS Flash0EccRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash0CtrlRegsFile")
#else
#pragma DATA_SECTION(Flash0CtrlRegs,"Flash0CtrlRegsFile");
#endif
volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash1EccRegsFile")
#else
#pragma DATA_SECTION(Flash1EccRegs,"Flash1EccRegsFile");
#endif
volatile struct FLASH_ECC_REGS Flash1EccRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash1CtrlRegsFile")
#else
#pragma DATA_SECTION(Flash1CtrlRegs,"Flash1CtrlRegsFile");
#endif
volatile struct FLASH_CTRL_REGS Flash1CtrlRegs;

//===========================================================================
// End of file.
//===========================================================================

