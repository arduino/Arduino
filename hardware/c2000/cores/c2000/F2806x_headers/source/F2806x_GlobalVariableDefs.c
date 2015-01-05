//###########################################################################
//
// FILE:    F2806x_GlobalVariableDefs.c
//
// TITLE:   F2806x Global Variables and Data Section Pragmas.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File

//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcRegsFile")
#else
#pragma DATA_SECTION(AdcRegs,"AdcRegsFile");
#endif
volatile struct ADC_REGS AdcRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcResultFile")
#else
#pragma DATA_SECTION(AdcResult,"AdcResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcResult;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cla1RegsFile")
#else
#pragma DATA_SECTION(Cla1Regs,"Cla1RegsFile");
#endif
volatile struct CLA_REGS Cla1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Comp1RegsFile")
#else
#pragma DATA_SECTION(Comp1Regs,"Comp1RegsFile");
#endif
volatile struct COMP_REGS Comp1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Comp2RegsFile")
#else
#pragma DATA_SECTION(Comp2Regs,"Comp2RegsFile");
#endif
volatile struct COMP_REGS Comp2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Comp3RegsFile")
#else
#pragma DATA_SECTION(Comp3Regs,"Comp3RegsFile");
#endif
volatile struct COMP_REGS Comp3Regs;

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
#pragma DATA_SECTION("CsmPwlFile")
#else
#pragma DATA_SECTION(CsmPwl,"CsmPwlFile");
#endif
volatile struct CSM_PWL CsmPwl;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CsmRegsFile")
#else
#pragma DATA_SECTION(CsmRegs,"CsmRegsFile");
#endif
volatile struct CSM_REGS CsmRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DevEmuRegsFile")
#else
#pragma DATA_SECTION(DevEmuRegs,"DevEmuRegsFile");
#endif
volatile struct DEV_EMU_REGS DevEmuRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaRegsFile")
#else
#pragma DATA_SECTION(DmaRegs,"DmaRegsFile");
#endif
volatile struct DMA_REGS DmaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaRegsFile")
#else
#pragma DATA_SECTION(ECanaRegs,"ECanaRegsFile");
#endif
volatile struct ECAN_REGS ECanaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaMboxesFile")
#else
#pragma DATA_SECTION(ECanaMboxes,"ECanaMboxesFile");
#endif
volatile struct ECAN_MBOXES ECanaMboxes;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaLAMRegsFile")
#else
#pragma DATA_SECTION(ECanaLAMRegs,"ECanaLAMRegsFile");
#endif
volatile struct LAM_REGS ECanaLAMRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaMOTSRegsFile")
#else
#pragma DATA_SECTION(ECanaMOTSRegs,"ECanaMOTSRegsFile");
#endif
volatile struct MOTS_REGS ECanaMOTSRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaMOTORegsFile")
#else
#pragma DATA_SECTION(ECanaMOTORegs,"ECanaMOTORegsFile");
#endif
volatile struct MOTO_REGS ECanaMOTORegs;

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
#pragma DATA_SECTION("FlashRegsFile")
#else
#pragma DATA_SECTION(FlashRegs,"FlashRegsFile");
#endif
volatile struct FLASH_REGS FlashRegs;

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
#pragma DATA_SECTION("GpioIntRegsFile")
#else
#pragma DATA_SECTION(GpioIntRegs,"GpioIntRegsFile");
#endif
volatile struct GPIO_INT_REGS GpioIntRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("HRCap1RegsFile")
#else
#pragma DATA_SECTION(HRCap1Regs,"HRCap1RegsFile");
#endif
volatile struct HRCAP_REGS HRCap1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("HRCap2RegsFile")
#else
#pragma DATA_SECTION(HRCap2Regs,"HRCap2RegsFile");
#endif
volatile struct HRCAP_REGS HRCap2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("HRCap3RegsFile")
#else
#pragma DATA_SECTION(HRCap3Regs,"HRCap3RegsFile");
#endif
volatile struct HRCAP_REGS HRCap3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("HRCap4RegsFile")
#else
#pragma DATA_SECTION(HRCap4Regs,"HRCap4RegsFile");
#endif
volatile struct HRCAP_REGS HRCap4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2caRegsFile")
#else
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
#endif
volatile struct I2C_REGS I2caRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspaRegsFile")
#else
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
#endif
volatile struct McBSP_REGS McbspaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("NmiIntruptRegsFile")
#else
#pragma DATA_SECTION(NmiIntruptRegs,"NmiIntruptRegsFile");
#endif
volatile struct NMIINTRUPT_REGS NmiIntruptRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PartIdRegsFile")
#else
#pragma DATA_SECTION(PartIdRegs,"PartIdRegsFile");
#endif
volatile struct PARTID_REGS PartIdRegs;

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
#pragma DATA_SECTION("SysCtrlRegsFile")
#else
#pragma DATA_SECTION(SysCtrlRegs,"SysCtrlRegsFile");
#endif
volatile struct SYS_CTRL_REGS SysCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SysPwrCtrlRegsFile")
#else
#pragma DATA_SECTION(SysPwrCtrlRegs,"SysPwrCtrlRegsFile");
#endif
volatile struct SYS_PWR_CTRL_REGS SysPwrCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Usb0RegsFile")
#else
#pragma DATA_SECTION(Usb0Regs,"Usb0RegsFile");
#endif
volatile struct USB_REGS Usb0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XIntruptRegsFile")
#else
#pragma DATA_SECTION(XIntruptRegs,"XIntruptRegsFile");
#endif
volatile struct XINTRUPT_REGS XIntruptRegs;

//----------------------------------------
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
#pragma DATA_SECTION("FlashScalingVar");
#else
#pragma DATA_SECTION(Flash_CPUScaleFactor, "FlashScalingVar");
#endif
Uint32 Flash_CPUScaleFactor;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FlashCallbackVar");
#else
#pragma DATA_SECTION(Flash_CallbackPtr, "FlashCallbackVar");
#endif
void (*Flash_CallbackPtr) (void);


//===========================================================================
// End of file.
//===========================================================================

