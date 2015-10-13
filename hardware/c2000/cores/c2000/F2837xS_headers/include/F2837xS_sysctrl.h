//###########################################################################
//
// FILE:    F2837xS_sysctrl.h
//
// TITLE:   F2837xS Device SYSCTRL Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_SYSCTRL_H__
#define __F2837xS_SYSCTRL_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// SYSCTRL Individual Register Bit Definitions:

struct PARTIDL_BITS {                   // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 rsvd2:2;                     // 4:3 Reserved
    Uint16 rsvd3:1;                     // 5 Reserved
    Uint16 QUAL:2;                      // 7:6 Qualification Status
    Uint16 PIN_COUNT:3;                 // 10:8 Device Pin Count
    Uint16 rsvd4:1;                     // 11 Reserved
    Uint16 rsvd5:1;                     // 12 Reserved
    Uint16 INSTASPIN:2;                 // 14:13 Motorware feature set
    Uint16 rsvd6:1;                     // 15 Reserved
    Uint16 FLASH_SIZE:8;                // 23:16 Flash size in KB
    Uint16 rsvd7:4;                     // 27:24 Reserved
    Uint16 PARTID_FORMAT_REVISION:4;    // 31:28 Revision of the PARTID format
};

union PARTIDL_REG {
    Uint32  all;
    struct  PARTIDL_BITS  bit;
};

struct PARTIDH_BITS {                   // bits description
    Uint16 rsvd1:8;                     // 7:0 Reserved
    Uint16 FAMILY:8;                    // 15:8 Device family
    Uint16 PARTNO:8;                    // 23:16 Device part number
    Uint16 DEVICE_CLASS_ID:8;           // 31:24 Device class ID
};

union PARTIDH_REG {
    Uint32  all;
    struct  PARTIDH_BITS  bit;
};

struct DC0_BITS {                       // bits description
    Uint16 SINGLE_CORE:1;               // 0 Single Core vs Dual Core 
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC0_REG {
    Uint32  all;
    struct  DC0_BITS  bit;
};

struct DC1_BITS {                       // bits description
    Uint16 CPU1_FPU_TMU:1;              // 0 CPU1's FPU1+TMU1 
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 CPU1_VCU:1;                  // 2 CPU1's VCU 
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:2;                     // 5:4 Reserved
    Uint16 CPU1_CLA1:1;                 // 6 CPU1.CLA1 
    Uint16 rsvd4:1;                     // 7 Reserved
    Uint16 rsvd5:1;                     // 8 Reserved
    Uint16 rsvd6:1;                     // 9 Reserved
    Uint16 rsvd7:6;                     // 15:10 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union DC1_REG {
    Uint32  all;
    struct  DC1_BITS  bit;
};

struct DC2_BITS {                       // bits description
    Uint16 EMIF1:1;                     // 0 EMIF1 
    Uint16 EMIF2:1;                     // 1 EMIF2 
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC2_REG {
    Uint32  all;
    struct  DC2_BITS  bit;
};

struct DC3_BITS {                       // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 
    Uint16 EPWM2:1;                     // 1 EPWM2 
    Uint16 EPWM3:1;                     // 2 EPWM3 
    Uint16 EPWM4:1;                     // 3 EPWM4 
    Uint16 EPWM5:1;                     // 4 EPWM5 
    Uint16 EPWM6:1;                     // 5 EPWM6 
    Uint16 EPWM7:1;                     // 6 EPWM7 
    Uint16 EPWM8:1;                     // 7 EPWM8 
    Uint16 EPWM9:1;                     // 8 EPWM9 
    Uint16 EPWM10:1;                    // 9 EPWM10 
    Uint16 EPWM11:1;                    // 10 EPWM11 
    Uint16 EPWM12:1;                    // 11 EPWM12 
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union DC3_REG {
    Uint32  all;
    struct  DC3_BITS  bit;
};

struct DC4_BITS {                       // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 
    Uint16 ECAP2:1;                     // 1 ECAP2 
    Uint16 ECAP3:1;                     // 2 ECAP3 
    Uint16 ECAP4:1;                     // 3 ECAP4 
    Uint16 ECAP5:1;                     // 4 ECAP5 
    Uint16 ECAP6:1;                     // 5 ECAP6 
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union DC4_REG {
    Uint32  all;
    struct  DC4_BITS  bit;
};

struct DC5_BITS {                       // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 
    Uint16 EQEP2:1;                     // 1 EQEP2 
    Uint16 EQEP3:1;                     // 2 EQEP3 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union DC5_REG {
    Uint32  all;
    struct  DC5_BITS  bit;
};

struct DC6_BITS {                       // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:1;                     // 4 Reserved
    Uint16 rsvd6:1;                     // 5 Reserved
    Uint16 rsvd7:1;                     // 6 Reserved
    Uint16 rsvd8:1;                     // 7 Reserved
    Uint16 rsvd9:8;                     // 15:8 Reserved
    Uint16 rsvd10:16;                   // 31:16 Reserved
};

union DC6_REG {
    Uint32  all;
    struct  DC6_BITS  bit;
};

struct DC7_BITS {                       // bits description
    Uint16 SD1:1;                       // 0 SD1 
    Uint16 SD2:1;                       // 1 SD2 
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union DC7_REG {
    Uint32  all;
    struct  DC7_BITS  bit;
};

struct DC8_BITS {                       // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A 
    Uint16 SCI_B:1;                     // 1 SCI_B 
    Uint16 SCI_C:1;                     // 2 SCI_C 
    Uint16 SCI_D:1;                     // 3 SCI_D 
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC8_REG {
    Uint32  all;
    struct  DC8_BITS  bit;
};

struct DC9_BITS {                       // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A 
    Uint16 SPI_B:1;                     // 1 SPI_B 
    Uint16 SPI_C:1;                     // 2 SPI_C 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union DC9_REG {
    Uint32  all;
    struct  DC9_BITS  bit;
};

struct DC10_BITS {                      // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A 
    Uint16 I2C_B:1;                     // 1 I2C_B 
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union DC10_REG {
    Uint32  all;
    struct  DC10_BITS  bit;
};

struct DC11_BITS {                      // bits description
    Uint16 CAN_A:1;                     // 0 CAN_A 
    Uint16 CAN_B:1;                     // 1 CAN_B 
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:12;                    // 15:4 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union DC11_REG {
    Uint32  all;
    struct  DC11_BITS  bit;
};

struct DC12_BITS {                      // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A 
    Uint16 McBSP_B:1;                   // 1 McBSP_B 
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 USB_A:2;                     // 17:16 Decides the capability of the USB_A Module
    Uint16 rsvd2:2;                     // 19:18 Reserved
    Uint16 rsvd3:12;                    // 31:20 Reserved
};

union DC12_REG {
    Uint32  all;
    struct  DC12_BITS  bit;
};

struct DC13_BITS {                      // bits description
    Uint16 uPP_A:1;                     // 0 uPP_A 
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 rsvd2:14;                    // 15:2 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union DC13_REG {
    Uint32  all;
    struct  DC13_BITS  bit;
};

struct DC14_BITS {                      // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A
    Uint16 ADC_B:1;                     // 1 ADC_B
    Uint16 ADC_C:1;                     // 2 ADC_C
    Uint16 ADC_D:1;                     // 3 ADC_D
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC14_REG {
    Uint32  all;
    struct  DC14_BITS  bit;
};

struct DC15_BITS {                      // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 
    Uint16 CMPSS2:1;                    // 1 CMPSS2 
    Uint16 CMPSS3:1;                    // 2 CMPSS3 
    Uint16 CMPSS4:1;                    // 3 CMPSS4 
    Uint16 CMPSS5:1;                    // 4 CMPSS5 
    Uint16 CMPSS6:1;                    // 5 CMPSS6 
    Uint16 CMPSS7:1;                    // 6 CMPSS7 
    Uint16 CMPSS8:1;                    // 7 CMPSS8 
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC15_REG {
    Uint32  all;
    struct  DC15_BITS  bit;
};

struct DC17_BITS {                      // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered-DAC_A
    Uint16 DAC_B:1;                     // 17 Buffered-DAC_B
    Uint16 DAC_C:1;                     // 18 Buffered-DAC_C
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union DC17_REG {
    Uint32  all;
    struct  DC17_BITS  bit;
};

struct DC18_BITS {                      // bits description
    Uint16 LS0_1:1;                     // 0 LS0_1 
    Uint16 LS1_1:1;                     // 1 LS1_1 
    Uint16 LS2_1:1;                     // 2 LS2_1 
    Uint16 LS3_1:1;                     // 3 LS3_1 
    Uint16 LS4_1:1;                     // 4 LS4_1 
    Uint16 LS5_1:1;                     // 5 LS5_1 
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC18_REG {
    Uint32  all;
    struct  DC18_BITS  bit;
};

struct DC20_BITS {                      // bits description
    Uint16 GS0:1;                       // 0 GS0 
    Uint16 GS1:1;                       // 1 GS1 
    Uint16 GS2:1;                       // 2 GS2 
    Uint16 GS3:1;                       // 3 GS3 
    Uint16 GS4:1;                       // 4 GS4 
    Uint16 GS5:1;                       // 5 GS5 
    Uint16 GS6:1;                       // 6 GS6 
    Uint16 GS7:1;                       // 7 GS7 
    Uint16 GS8:1;                       // 8 GS8 
    Uint16 GS9:1;                       // 9 GS9 
    Uint16 GS10:1;                      // 10 GS10 
    Uint16 GS11:1;                      // 11 GS11 
    Uint16 GS12:1;                      // 12 GS12 
    Uint16 GS13:1;                      // 13 GS13 
    Uint16 GS14:1;                      // 14 GS14 
    Uint16 GS15:1;                      // 15 GS15 
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union DC20_REG {
    Uint32  all;
    struct  DC20_BITS  bit;
};

struct PERCNF1_BITS {                   // bits description
    Uint16 ADC_A_MODE:1;                // 0 ADC_A mode setting bit
    Uint16 ADC_B_MODE:1;                // 1 ADC_B mode setting bit
    Uint16 ADC_C_MODE:1;                // 2 ADC_C mode setting bit
    Uint16 ADC_D_MODE:1;                // 3 ADC_D mode setting bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 USB_A_PHY:1;                 // 16 USB_A_PHY 
    Uint16 rsvd2:1;                     // 17 Reserved
    Uint16 rsvd3:14;                    // 31:18 Reserved
};

union PERCNF1_REG {
    Uint32  all;
    struct  PERCNF1_BITS  bit;
};

struct FUSEERR_BITS {                   // bits description
    Uint16 ALERR:5;                     // 4:0 Efuse Autoload Error Status
    Uint16 ERR:1;                       // 5 Efuse Self Test Error Status
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FUSEERR_REG {
    Uint32  all;
    struct  FUSEERR_BITS  bit;
};

struct SOFTPRES0_BITS {                 // bits description
    Uint16 CPU1_CLA1:1;                 // 0 CPU1_CLA1 software reset bit
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 rsvd2:1;                     // 2 Reserved
    Uint16 rsvd3:1;                     // 3 Reserved
    Uint16 rsvd4:12;                    // 15:4 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union SOFTPRES0_REG {
    Uint32  all;
    struct  SOFTPRES0_BITS  bit;
};

struct SOFTPRES1_BITS {                 // bits description
    Uint16 EMIF1:1;                     // 0 EMIF1 software reset bit
    Uint16 EMIF2:1;                     // 1 EMIF2 software reset bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES1_REG {
    Uint32  all;
    struct  SOFTPRES1_BITS  bit;
};

struct SOFTPRES2_BITS {                 // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 software reset bit
    Uint16 EPWM2:1;                     // 1 EPWM2 software reset bit
    Uint16 EPWM3:1;                     // 2 EPWM3 software reset bit
    Uint16 EPWM4:1;                     // 3 EPWM4 software reset bit
    Uint16 EPWM5:1;                     // 4 EPWM5 software reset bit
    Uint16 EPWM6:1;                     // 5 EPWM6 software reset bit
    Uint16 EPWM7:1;                     // 6 EPWM7 software reset bit
    Uint16 EPWM8:1;                     // 7 EPWM8 software reset bit
    Uint16 EPWM9:1;                     // 8 EPWM9 software reset bit
    Uint16 EPWM10:1;                    // 9 EPWM10 software reset bit
    Uint16 EPWM11:1;                    // 10 EPWM11 software reset bit
    Uint16 EPWM12:1;                    // 11 EPWM12 software reset bit
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union SOFTPRES2_REG {
    Uint32  all;
    struct  SOFTPRES2_BITS  bit;
};

struct SOFTPRES3_BITS {                 // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 software reset bit
    Uint16 ECAP2:1;                     // 1 ECAP2 software reset bit
    Uint16 ECAP3:1;                     // 2 ECAP3 software reset bit
    Uint16 ECAP4:1;                     // 3 ECAP4 software reset bit
    Uint16 ECAP5:1;                     // 4 ECAP5 software reset bit
    Uint16 ECAP6:1;                     // 5 ECAP6 software reset bit
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union SOFTPRES3_REG {
    Uint32  all;
    struct  SOFTPRES3_BITS  bit;
};

struct SOFTPRES4_BITS {                 // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 software reset bit
    Uint16 EQEP2:1;                     // 1 EQEP2 software reset bit
    Uint16 EQEP3:1;                     // 2 EQEP3 software reset bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union SOFTPRES4_REG {
    Uint32  all;
    struct  SOFTPRES4_BITS  bit;
};

struct SOFTPRES6_BITS {                 // bits description
    Uint16 SD1:1;                       // 0 SD1 software reset bit
    Uint16 SD2:1;                       // 1 SD2 software reset bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union SOFTPRES6_REG {
    Uint32  all;
    struct  SOFTPRES6_BITS  bit;
};

struct SOFTPRES7_BITS {                 // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A software reset bit
    Uint16 SCI_B:1;                     // 1 SCI_B software reset bit
    Uint16 SCI_C:1;                     // 2 SCI_C software reset bit
    Uint16 SCI_D:1;                     // 3 SCI_D software reset bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES7_REG {
    Uint32  all;
    struct  SOFTPRES7_BITS  bit;
};

struct SOFTPRES8_BITS {                 // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A software reset bit
    Uint16 SPI_B:1;                     // 1 SPI_B software reset bit
    Uint16 SPI_C:1;                     // 2 SPI_C software reset bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union SOFTPRES8_REG {
    Uint32  all;
    struct  SOFTPRES8_BITS  bit;
};

struct SOFTPRES9_BITS {                 // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A software reset bit
    Uint16 I2C_B:1;                     // 1 I2C_B software reset bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union SOFTPRES9_REG {
    Uint32  all;
    struct  SOFTPRES9_BITS  bit;
};

struct SOFTPRES11_BITS {                // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A software reset bit
    Uint16 McBSP_B:1;                   // 1 McBSP_B software reset bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 USB_A:1;                     // 16 USB_A software reset bit
    Uint16 rsvd2:1;                     // 17 Reserved
    Uint16 rsvd3:14;                    // 31:18 Reserved
};

union SOFTPRES11_REG {
    Uint32  all;
    struct  SOFTPRES11_BITS  bit;
};

struct SOFTPRES13_BITS {                // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A software reset bit
    Uint16 ADC_B:1;                     // 1 ADC_B software reset bit
    Uint16 ADC_C:1;                     // 2 ADC_C software reset bit
    Uint16 ADC_D:1;                     // 3 ADC_D software reset bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES13_REG {
    Uint32  all;
    struct  SOFTPRES13_BITS  bit;
};

struct SOFTPRES14_BITS {                // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 software reset bit
    Uint16 CMPSS2:1;                    // 1 CMPSS2 software reset bit
    Uint16 CMPSS3:1;                    // 2 CMPSS3 software reset bit
    Uint16 CMPSS4:1;                    // 3 CMPSS4 software reset bit
    Uint16 CMPSS5:1;                    // 4 CMPSS5 software reset bit
    Uint16 CMPSS6:1;                    // 5 CMPSS6 software reset bit
    Uint16 CMPSS7:1;                    // 6 CMPSS7 software reset bit
    Uint16 CMPSS8:1;                    // 7 CMPSS8 software reset bit
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES14_REG {
    Uint32  all;
    struct  SOFTPRES14_BITS  bit;
};

struct SOFTPRES16_BITS {                // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered_DAC_A software reset bit
    Uint16 DAC_B:1;                     // 17 Buffered_DAC_B software reset bit
    Uint16 DAC_C:1;                     // 18 Buffered_DAC_C software reset bit
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union SOFTPRES16_REG {
    Uint32  all;
    struct  SOFTPRES16_BITS  bit;
};

struct DEV_CFG_REGS {
    Uint16                                   rsvd1[8];                     // Reserved
    union   PARTIDL_REG                      PARTIDL;                      // Lower 32-bit of Device PART Identification Number
    union   PARTIDH_REG                      PARTIDH;                      // Upper 32-bit of Device PART Identification Number
    Uint32                                   REVID;                        // Device Revision Number
    Uint16                                   rsvd2[2];                     // Reserved
    union   DC0_REG                          DC0;                          // Device Capability: Device Information
    union   DC1_REG                          DC1;                          // Device Capability: Processing Block Customization
    union   DC2_REG                          DC2;                          // Device Capability: EMIF Customization
    union   DC3_REG                          DC3;                          // Device Capability: Peripheral Customization
    union   DC4_REG                          DC4;                          // Device Capability: Peripheral Customization
    union   DC5_REG                          DC5;                          // Device Capability: Peripheral Customization
    union   DC6_REG                          DC6;                          // Device Capability: Peripheral Customization
    union   DC7_REG                          DC7;                          // Device Capability: Peripheral Customization
    union   DC8_REG                          DC8;                          // Device Capability: Peripheral Customization
    union   DC9_REG                          DC9;                          // Device Capability: Peripheral Customization
    union   DC10_REG                         DC10;                         // Device Capability: Peripheral Customization
    union   DC11_REG                         DC11;                         // Device Capability: Peripheral Customization
    union   DC12_REG                         DC12;                         // Device Capability: Peripheral Customization
    union   DC13_REG                         DC13;                         // Device Capability: Peripheral Customization
    union   DC14_REG                         DC14;                         // Device Capability: Analog Modules Customization
    union   DC15_REG                         DC15;                         // Device Capability: Analog Modules Customization
    Uint16                                   rsvd3[2];                     // Reserved
    union   DC17_REG                         DC17;                         // Device Capability: Analog Modules Customization
    union   DC18_REG                         DC18;                         // Device Capability: CPU1 Lx SRAM Customization
    Uint16                                   rsvd4[2];                     // Reserved
    union   DC20_REG                         DC20;                         // Device Capability: GSx SRAM Customization
    Uint16                                   rsvd5[38];                    // Reserved
    union   PERCNF1_REG                      PERCNF1;                      // Peripheral Configuration register
    Uint16                                   rsvd6[18];                    // Reserved
    union   FUSEERR_REG                      FUSEERR;                      // e-Fuse error Status register
    Uint16                                   rsvd7[12];                    // Reserved
    union   SOFTPRES0_REG                    SOFTPRES0;                    // Processing Block Software Reset register
    union   SOFTPRES1_REG                    SOFTPRES1;                    // EMIF Software Reset register
    union   SOFTPRES2_REG                    SOFTPRES2;                    // Peripheral Software Reset register
    union   SOFTPRES3_REG                    SOFTPRES3;                    // Peripheral Software Reset register
    union   SOFTPRES4_REG                    SOFTPRES4;                    // Peripheral Software Reset register
    Uint16                                   rsvd8[2];                     // Reserved
    union   SOFTPRES6_REG                    SOFTPRES6;                    // Peripheral Software Reset register
    union   SOFTPRES7_REG                    SOFTPRES7;                    // Peripheral Software Reset register
    union   SOFTPRES8_REG                    SOFTPRES8;                    // Peripheral Software Reset register
    union   SOFTPRES9_REG                    SOFTPRES9;                    // Peripheral Software Reset register
    Uint16                                   rsvd9[2];                     // Reserved
    union   SOFTPRES11_REG                   SOFTPRES11;                   // Peripheral Software Reset register
    Uint16                                   rsvd10[2];                    // Reserved
    union   SOFTPRES13_REG                   SOFTPRES13;                   // Peripheral Software Reset register
    union   SOFTPRES14_REG                   SOFTPRES14;                   // Peripheral Software Reset register
    Uint16                                   rsvd11[2];                    // Reserved
    union   SOFTPRES16_REG                   SOFTPRES16;                   // Peripheral Software Reset register
    Uint16                                   rsvd12[138];                  // Reserved
};

struct CLKCFGLOCK1_BITS {               // bits description
    Uint16 CLKSRCCTL1:1;                // 0 Lock bit for CLKSRCCTL1 register
    Uint16 CLKSRCCTL2:1;                // 1 Lock bit for CLKSRCCTL2 register
    Uint16 CLKSRCCTL3:1;                // 2 Lock bit for CLKSRCCTL3 register
    Uint16 SYSPLLCTL1:1;                // 3 Lock bit for SYSPLLCTL1 register
    Uint16 SYSPLLCTL2:1;                // 4 Lock bit for SYSPLLCTL2 register
    Uint16 SYSPLLCTL3:1;                // 5 Lock bit for SYSPLLCTL3 register
    Uint16 SYSPLLMULT:1;                // 6 Lock bit for SYSPLLMULT register
    Uint16 AUXPLLCTL1:1;                // 7 Lock bit for AUXPLLCTL1 register
    Uint16 rsvd1:1;                     // 8 Reserved
    Uint16 rsvd2:1;                     // 9 Reserved
    Uint16 AUXPLLMULT:1;                // 10 Lock bit for AUXPLLMULT register
    Uint16 SYSCLKDIVSEL:1;              // 11 Lock bit for SYSCLKDIVSEL register
    Uint16 AUXCLKDIVSEL:1;              // 12 Lock bit for AUXCLKDIVSEL register
    Uint16 PERCLKDIVSEL:1;              // 13 Lock bit for PERCLKDIVSEL register
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 LOSPCP:1;                    // 15 Lock bit for LOSPCP register
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union CLKCFGLOCK1_REG {
    Uint32  all;
    struct  CLKCFGLOCK1_BITS  bit;
};

struct CLKSRCCTL1_BITS {                // bits description
    Uint16 OSCCLKSRCSEL:2;              // 1:0 OSCCLK Source Select Bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 INTOSC2OFF:1;                // 3 Internal Oscillator 2 Off Bit
    Uint16 XTALOFF:1;                   // 4 Crystal (External) Oscillator Off Bit
    Uint16 WDHALTI:1;                   // 5 Watchdog HALT Mode Ignore Bit
    Uint16 rsvd2:10;                    // 15:6 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CLKSRCCTL1_REG {
    Uint32  all;
    struct  CLKSRCCTL1_BITS  bit;
};

struct CLKSRCCTL2_BITS {                // bits description
    Uint16 AUXOSCCLKSRCSEL:2;           // 1:0 AUXOSCCLK Source Select Bit
    Uint16 CANABCLKSEL:2;               // 3:2 CANA Bit Clock Source Select Bit
    Uint16 CANBBCLKSEL:2;               // 5:4 CANB Bit Clock Source Select Bit
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 rsvd2:2;                     // 9:8 Reserved
    Uint16 rsvd3:6;                     // 15:10 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union CLKSRCCTL2_REG {
    Uint32  all;
    struct  CLKSRCCTL2_BITS  bit;
};

struct CLKSRCCTL3_BITS {                // bits description
    Uint16 XCLKOUTSEL:3;                // 2:0 XCLKOUT Source Select Bit
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLKSRCCTL3_REG {
    Uint32  all;
    struct  CLKSRCCTL3_BITS  bit;
};

struct SYSPLLCTL1_BITS {                // bits description
    Uint16 PLLEN:1;                     // 0 SYSPLL enable/disable bit
    Uint16 PLLCLKEN:1;                  // 1 SYSPLL bypassed or included in the PLLSYSCLK path
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSPLLCTL1_REG {
    Uint32  all;
    struct  SYSPLLCTL1_BITS  bit;
};

struct SYSPLLMULT_BITS {                // bits description
    Uint16 IMULT:7;                     // 6:0 SYSPLL Integer Multiplier
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 FMULT:2;                     // 9:8 SYSPLL Fractional Multiplier
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union SYSPLLMULT_REG {
    Uint32  all;
    struct  SYSPLLMULT_BITS  bit;
};

struct SYSPLLSTS_BITS {                 // bits description
    Uint16 LOCKS:1;                     // 0 SYSPLL Lock Status Bit
    Uint16 SLIPS:1;                     // 1 SYSPLL Slip Status Bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSPLLSTS_REG {
    Uint32  all;
    struct  SYSPLLSTS_BITS  bit;
};

struct AUXPLLCTL1_BITS {                // bits description
    Uint16 PLLEN:1;                     // 0 AUXPLL enable/disable bit
    Uint16 PLLCLKEN:1;                  // 1 AUXPLL bypassed or included in the AUXPLLCLK path
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union AUXPLLCTL1_REG {
    Uint32  all;
    struct  AUXPLLCTL1_BITS  bit;
};

struct AUXPLLMULT_BITS {                // bits description
    Uint16 IMULT:7;                     // 6:0 AUXPLL Integer Multiplier
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 FMULT:2;                     // 9:8 AUXPLL Fractional Multiplier
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union AUXPLLMULT_REG {
    Uint32  all;
    struct  AUXPLLMULT_BITS  bit;
};

struct AUXPLLSTS_BITS {                 // bits description
    Uint16 LOCKS:1;                     // 0 AUXPLL Lock Status Bit
    Uint16 SLIPS:1;                     // 1 AUXPLL Slip Status Bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union AUXPLLSTS_REG {
    Uint32  all;
    struct  AUXPLLSTS_BITS  bit;
};

struct SYSCLKDIVSEL_BITS {              // bits description
    Uint16 PLLSYSCLKDIV:6;              // 5:0 PLLSYSCLK Divide Select
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSCLKDIVSEL_REG {
    Uint32  all;
    struct  SYSCLKDIVSEL_BITS  bit;
};

struct AUXCLKDIVSEL_BITS {              // bits description
    Uint16 AUXPLLDIV:2;                 // 1:0 AUXPLLCLK Divide Select
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union AUXCLKDIVSEL_REG {
    Uint32  all;
    struct  AUXCLKDIVSEL_BITS  bit;
};

struct PERCLKDIVSEL_BITS {              // bits description
    Uint16 EPWMCLKDIV:2;                // 1:0 EPWM Clock Divide Select
    Uint16 rsvd1:2;                     // 3:2 Reserved
    Uint16 EMIF1CLKDIV:1;               // 4 EMIF1  Clock Divide Select
    Uint16 rsvd2:1;                     // 5 Reserved
    Uint16 EMIF2CLKDIV:1;               // 6 EMIF2 Clock Divide Select
    Uint16 rsvd3:9;                     // 15:7 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union PERCLKDIVSEL_REG {
    Uint32  all;
    struct  PERCLKDIVSEL_BITS  bit;
};

struct XCLKOUTDIVSEL_BITS {             // bits description
    Uint16 XCLKOUTDIV:2;                // 1:0 XCLKOUT Divide Select
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union XCLKOUTDIVSEL_REG {
    Uint32  all;
    struct  XCLKOUTDIVSEL_BITS  bit;
};

struct LOSPCP_BITS {                    // bits description
    Uint16 LSPCLKDIV:3;                 // 2:0 LSPCLK Divide Select
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LOSPCP_REG {
    Uint32  all;
    struct  LOSPCP_BITS  bit;
};

struct MCDCR_BITS {                     // bits description
    Uint16 MCLKSTS:1;                   // 0 Missing Clock Status Bit
    Uint16 MCLKCLR:1;                   // 1 Missing Clock Clear Bit
    Uint16 MCLKOFF:1;                   // 2 Missing Clock Detect Off Bit
    Uint16 OSCOFF:1;                    // 3 Oscillator Clock Off Bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union MCDCR_REG {
    Uint32  all;
    struct  MCDCR_BITS  bit;
};

struct X1CNT_BITS {                     // bits description
    Uint16 X1CNT:10;                    // 9:0 X1 Counter
    Uint16 rsvd1:6;                     // 15:10 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union X1CNT_REG {
    Uint32  all;
    struct  X1CNT_BITS  bit;
};

struct CLK_CFG_REGS {
    Uint16                                   rsvd1[2];                     // Reserved
    union   CLKCFGLOCK1_REG                  CLKCFGLOCK1;                  // Lock bit for CLKCFG registers
    Uint16                                   rsvd2[4];                     // Reserved
    union   CLKSRCCTL1_REG                   CLKSRCCTL1;                   // Clock Source Control register-1
    union   CLKSRCCTL2_REG                   CLKSRCCTL2;                   // Clock Source Control register-2
    union   CLKSRCCTL3_REG                   CLKSRCCTL3;                   // Clock Source Control register-3
    union   SYSPLLCTL1_REG                   SYSPLLCTL1;                   // SYSPLL Control register-1
    Uint16                                   rsvd3[4];                     // Reserved
    union   SYSPLLMULT_REG                   SYSPLLMULT;                   // SYSPLL Multiplier register
    union   SYSPLLSTS_REG                    SYSPLLSTS;                    // SYSPLL Status register
    union   AUXPLLCTL1_REG                   AUXPLLCTL1;                   // AUXPLL Control register-1
    Uint16                                   rsvd4[4];                     // Reserved
    union   AUXPLLMULT_REG                   AUXPLLMULT;                   // AUXPLL Multiplier register
    union   AUXPLLSTS_REG                    AUXPLLSTS;                    // AUXPLL Status register
    union   SYSCLKDIVSEL_REG                 SYSCLKDIVSEL;                 // System Clock Divider Select register
    union   AUXCLKDIVSEL_REG                 AUXCLKDIVSEL;                 // Auxillary Clock Divider Select register
    union   PERCLKDIVSEL_REG                 PERCLKDIVSEL;                 // Peripheral Clock Divider Selet register
    union   XCLKOUTDIVSEL_REG                XCLKOUTDIVSEL;                // XCLKOUT Divider Select register
    Uint16                                   rsvd5[2];                     // Reserved
    union   LOSPCP_REG                       LOSPCP;                       // Low Speed Clock Source Prescalar
    union   MCDCR_REG                        MCDCR;                        // Missing Clock Detect Control Register
    union   X1CNT_REG                        X1CNT;                        // 10-bit Counter on X1 Clock
};

struct CPUSYSLOCK1_BITS {               // bits description
    Uint16 HIBBOOTMODE:1;               // 0 Lock bit for HIBBOOTMODE register
    Uint16 IORESTOREADDR:1;             // 1 Lock bit for IORESTOREADDR Register
    Uint16 PIEVERRADDR:1;               // 2 Lock bit for PIEVERRADDR Register
    Uint16 PCLKCR0:1;                   // 3 Lock bit for PCLKCR0 Register
    Uint16 PCLKCR1:1;                   // 4 Lock bit for PCLKCR1 Register
    Uint16 PCLKCR2:1;                   // 5 Lock bit for PCLKCR2 Register
    Uint16 PCLKCR3:1;                   // 6 Lock bit for PCLKCR3 Register
    Uint16 PCLKCR4:1;                   // 7 Lock bit for PCLKCR4 Register
    Uint16 PCLKCR5:1;                   // 8 Lock bit for PCLKCR5 Register
    Uint16 PCLKCR6:1;                   // 9 Lock bit for PCLKCR6 Register
    Uint16 PCLKCR7:1;                   // 10 Lock bit for PCLKCR7 Register
    Uint16 PCLKCR8:1;                   // 11 Lock bit for PCLKCR8 Register
    Uint16 PCLKCR9:1;                   // 12 Lock bit for PCLKCR9 Register
    Uint16 PCLKCR10:1;                  // 13 Lock bit for PCLKCR10 Register
    Uint16 PCLKCR11:1;                  // 14 Lock bit for PCLKCR11 Register
    Uint16 PCLKCR12:1;                  // 15 Lock bit for PCLKCR12 Register
    Uint16 PCLKCR13:1;                  // 16 Lock bit for PCLKCR13 Register
    Uint16 PCLKCR14:1;                  // 17 Lock bit for PCLKCR14 Register
    Uint16 PCLKCR15:1;                  // 18 Lock bit for PCLKCR15 Register
    Uint16 PCLKCR16:1;                  // 19 Lock bit for PCLKCR16 Register
    Uint16 SECMSEL:1;                   // 20 Lock bit for SECMSEL Register
    Uint16 LPMCR:1;                     // 21 Lock bit for LPMCR Register
    Uint16 GPIOLPMSEL0:1;               // 22 Lock bit for GPIOLPMSEL0 Register
    Uint16 GPIOLPMSEL1:1;               // 23 Lock bit for GPIOLPMSEL1 Register
    Uint16 rsvd1:8;                     // 31:24 Reserved
};

union CPUSYSLOCK1_REG {
    Uint32  all;
    struct  CPUSYSLOCK1_BITS  bit;
};

struct IORESTOREADDR_BITS {             // bits description
    Uint32 ADDR:22;                     // 21:0 restoreIO() routine address
    Uint16 rsvd1:10;                    // 31:22 Reserved
};

union IORESTOREADDR_REG {
    Uint32  all;
    struct  IORESTOREADDR_BITS  bit;
};

struct PIEVERRADDR_BITS {               // bits description
    Uint32 ADDR:22;                     // 21:0 PIE Vector Fetch Error Handler Routine Address
    Uint16 rsvd1:10;                    // 31:22 Reserved
};

union PIEVERRADDR_REG {
    Uint32  all;
    struct  PIEVERRADDR_BITS  bit;
};

struct PCLKCR0_BITS {                   // bits description
    Uint16 CLA1:1;                      // 0 CLA1 Clock Enable Bit
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 DMA:1;                       // 2 DMA Clock Enable bit
    Uint16 CPUTIMER0:1;                 // 3 CPUTIMER0 Clock Enable bit
    Uint16 CPUTIMER1:1;                 // 4 CPUTIMER1 Clock Enable bit
    Uint16 CPUTIMER2:1;                 // 5 CPUTIMER2 Clock Enable bit
    Uint16 rsvd2:10;                    // 15:6 Reserved
    Uint16 HRPWM:1;                     // 16 HRPWM Clock Enable Bit
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 TBCLKSYNC:1;                 // 18 EPWM Time Base Clock sync
    Uint16 rsvd4:1;                     // 19 Reserved
    Uint16 rsvd5:12;                    // 31:20 Reserved
};

union PCLKCR0_REG {
    Uint32  all;
    struct  PCLKCR0_BITS  bit;
};

struct PCLKCR1_BITS {                   // bits description
    Uint16 EMIF1:1;                     // 0 EMIF1 Clock Enable bit
    Uint16 EMIF2:1;                     // 1 EMIF2 Clock Enable bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR1_REG {
    Uint32  all;
    struct  PCLKCR1_BITS  bit;
};

struct PCLKCR2_BITS {                   // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 Clock Enable bit
    Uint16 EPWM2:1;                     // 1 EPWM2 Clock Enable bit
    Uint16 EPWM3:1;                     // 2 EPWM3 Clock Enable bit
    Uint16 EPWM4:1;                     // 3 EPWM4 Clock Enable bit
    Uint16 EPWM5:1;                     // 4 EPWM5 Clock Enable bit
    Uint16 EPWM6:1;                     // 5 EPWM6 Clock Enable bit
    Uint16 EPWM7:1;                     // 6 EPWM7 Clock Enable bit
    Uint16 EPWM8:1;                     // 7 EPWM8 Clock Enable bit
    Uint16 EPWM9:1;                     // 8 EPWM9 Clock Enable bit
    Uint16 EPWM10:1;                    // 9 EPWM10 Clock Enable bit
    Uint16 EPWM11:1;                    // 10 EPWM11 Clock Enable bit
    Uint16 EPWM12:1;                    // 11 EPWM12 Clock Enable bit
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union PCLKCR2_REG {
    Uint32  all;
    struct  PCLKCR2_BITS  bit;
};

struct PCLKCR3_BITS {                   // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 Clock Enable bit
    Uint16 ECAP2:1;                     // 1 ECAP2 Clock Enable bit
    Uint16 ECAP3:1;                     // 2 ECAP3 Clock Enable bit
    Uint16 ECAP4:1;                     // 3 ECAP4 Clock Enable bit
    Uint16 ECAP5:1;                     // 4 ECAP5 Clock Enable bit
    Uint16 ECAP6:1;                     // 5 ECAP6 Clock Enable bit
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union PCLKCR3_REG {
    Uint32  all;
    struct  PCLKCR3_BITS  bit;
};

struct PCLKCR4_BITS {                   // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 Clock Enable bit
    Uint16 EQEP2:1;                     // 1 EQEP2 Clock Enable bit
    Uint16 EQEP3:1;                     // 2 EQEP3 Clock Enable bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union PCLKCR4_REG {
    Uint32  all;
    struct  PCLKCR4_BITS  bit;
};

struct PCLKCR6_BITS {                   // bits description
    Uint16 SD1:1;                       // 0 SD1 Clock Enable bit
    Uint16 SD2:1;                       // 1 SD2 Clock Enable bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union PCLKCR6_REG {
    Uint32  all;
    struct  PCLKCR6_BITS  bit;
};

struct PCLKCR7_BITS {                   // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A Clock Enable bit
    Uint16 SCI_B:1;                     // 1 SCI_B Clock Enable bit
    Uint16 SCI_C:1;                     // 2 SCI_C Clock Enable bit
    Uint16 SCI_D:1;                     // 3 SCI_D Clock Enable bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR7_REG {
    Uint32  all;
    struct  PCLKCR7_BITS  bit;
};

struct PCLKCR8_BITS {                   // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A Clock Enable bit
    Uint16 SPI_B:1;                     // 1 SPI_B Clock Enable bit
    Uint16 SPI_C:1;                     // 2 SPI_C Clock Enable bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union PCLKCR8_REG {
    Uint32  all;
    struct  PCLKCR8_BITS  bit;
};

struct PCLKCR9_BITS {                   // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A Clock Enable bit
    Uint16 I2C_B:1;                     // 1 I2C_B Clock Enable bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union PCLKCR9_REG {
    Uint32  all;
    struct  PCLKCR9_BITS  bit;
};

struct PCLKCR10_BITS {                  // bits description
    Uint16 CAN_A:1;                     // 0 CAN_A Clock Enable bit
    Uint16 CAN_B:1;                     // 1 CAN_B Clock Enable bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:12;                    // 15:4 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union PCLKCR10_REG {
    Uint32  all;
    struct  PCLKCR10_BITS  bit;
};

struct PCLKCR11_BITS {                  // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A Clock Enable bit
    Uint16 McBSP_B:1;                   // 1 McBSP_B Clock Enable bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 USB_A:1;                     // 16 USB_A Clock Enable bit
    Uint16 rsvd2:1;                     // 17 Reserved
    Uint16 rsvd3:14;                    // 31:18 Reserved
};

union PCLKCR11_REG {
    Uint32  all;
    struct  PCLKCR11_BITS  bit;
};

struct PCLKCR12_BITS {                  // bits description
    Uint16 uPP_A:1;                     // 0 uPP_A Clock Enable bit
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 rsvd2:14;                    // 15:2 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union PCLKCR12_REG {
    Uint32  all;
    struct  PCLKCR12_BITS  bit;
};

struct PCLKCR13_BITS {                  // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A Clock Enable bit
    Uint16 ADC_B:1;                     // 1 ADC_B Clock Enable bit
    Uint16 ADC_C:1;                     // 2 ADC_C Clock Enable bit
    Uint16 ADC_D:1;                     // 3 ADC_D Clock Enable bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR13_REG {
    Uint32  all;
    struct  PCLKCR13_BITS  bit;
};

struct PCLKCR14_BITS {                  // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 Clock Enable bit
    Uint16 CMPSS2:1;                    // 1 CMPSS2 Clock Enable bit
    Uint16 CMPSS3:1;                    // 2 CMPSS3 Clock Enable bit
    Uint16 CMPSS4:1;                    // 3 CMPSS4 Clock Enable bit
    Uint16 CMPSS5:1;                    // 4 CMPSS5 Clock Enable bit
    Uint16 CMPSS6:1;                    // 5 CMPSS6 Clock Enable bit
    Uint16 CMPSS7:1;                    // 6 CMPSS7 Clock Enable bit
    Uint16 CMPSS8:1;                    // 7 CMPSS8 Clock Enable bit
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR14_REG {
    Uint32  all;
    struct  PCLKCR14_BITS  bit;
};

struct PCLKCR16_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered_DAC_A Clock Enable Bit
    Uint16 DAC_B:1;                     // 17 Buffered_DAC_B Clock Enable Bit
    Uint16 DAC_C:1;                     // 18 Buffered_DAC_C Clock Enable Bit
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union PCLKCR16_REG {
    Uint32  all;
    struct  PCLKCR16_BITS  bit;
};

struct SECMSEL_BITS {                   // bits description
    Uint16 PF1SEL:2;                    // 1:0 Secondary Master Select for VBUS32_1 Bridge
    Uint16 PF2SEL:2;                    // 3:2 Secondary Master Select for VBUS32_2 Bridge
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 rsvd2:2;                     // 7:6 Reserved
    Uint16 rsvd3:2;                     // 9:8 Reserved
    Uint16 rsvd4:2;                     // 11:10 Reserved
    Uint16 rsvd5:2;                     // 13:12 Reserved
    Uint16 rsvd6:2;                     // 15:14 Reserved
    Uint16 rsvd7:16;                    // 31:16 Reserved
};

union SECMSEL_REG {
    Uint32  all;
    struct  SECMSEL_BITS  bit;
};

struct LPMCR_BITS {                     // bits description
    Uint16 LPM:2;                       // 1:0 Low Power Mode setting
    Uint16 QUALSTDBY:6;                 // 7:2 STANDBY Wakeup Pin Qualification Setting
    Uint16 rsvd1:7;                     // 14:8 Reserved
    Uint16 WDINTE:1;                    // 15 Enable for WDINT wakeup from STANDBY
    Uint16 M0M1MODE:2;                  // 17:16 Configuration for M0 and M1 mode during HIB
    Uint16 rsvd2:13;                    // 30:18 Reserved
    Uint16 IOISODIS:1;                  // 31 IO Isolation Disable
};

union LPMCR_REG {
    Uint32  all;
    struct  LPMCR_BITS  bit;
};

struct GPIOLPMSEL0_BITS {               // bits description
    Uint16 GPIO0:1;                     // 0 GPIO0 Enable for LPM Wakeup
    Uint16 GPIO1:1;                     // 1 GPIO1 Enable for LPM Wakeup
    Uint16 GPIO2:1;                     // 2 GPIO2 Enable for LPM Wakeup
    Uint16 GPIO3:1;                     // 3 GPIO3 Enable for LPM Wakeup
    Uint16 GPIO4:1;                     // 4 GPIO4 Enable for LPM Wakeup
    Uint16 GPIO5:1;                     // 5 GPIO5 Enable for LPM Wakeup
    Uint16 GPIO6:1;                     // 6 GPIO6 Enable for LPM Wakeup
    Uint16 GPIO7:1;                     // 7 GPIO7 Enable for LPM Wakeup
    Uint16 GPIO8:1;                     // 8 GPIO8 Enable for LPM Wakeup
    Uint16 GPIO9:1;                     // 9 GPIO9 Enable for LPM Wakeup
    Uint16 GPIO10:1;                    // 10 GPIO10 Enable for LPM Wakeup
    Uint16 GPIO11:1;                    // 11 GPIO11 Enable for LPM Wakeup
    Uint16 GPIO12:1;                    // 12 GPIO12 Enable for LPM Wakeup
    Uint16 GPIO13:1;                    // 13 GPIO13 Enable for LPM Wakeup
    Uint16 GPIO14:1;                    // 14 GPIO14 Enable for LPM Wakeup
    Uint16 GPIO15:1;                    // 15 GPIO15 Enable for LPM Wakeup
    Uint16 GPIO16:1;                    // 16 GPIO16 Enable for LPM Wakeup
    Uint16 GPIO17:1;                    // 17 GPIO17 Enable for LPM Wakeup
    Uint16 GPIO18:1;                    // 18 GPIO18 Enable for LPM Wakeup
    Uint16 GPIO19:1;                    // 19 GPIO19 Enable for LPM Wakeup
    Uint16 GPIO20:1;                    // 20 GPIO20 Enable for LPM Wakeup
    Uint16 GPIO21:1;                    // 21 GPIO21 Enable for LPM Wakeup
    Uint16 GPIO22:1;                    // 22 GPIO22 Enable for LPM Wakeup
    Uint16 GPIO23:1;                    // 23 GPIO23 Enable for LPM Wakeup
    Uint16 GPIO24:1;                    // 24 GPIO24 Enable for LPM Wakeup
    Uint16 GPIO25:1;                    // 25 GPIO25 Enable for LPM Wakeup
    Uint16 GPIO26:1;                    // 26 GPIO26 Enable for LPM Wakeup
    Uint16 GPIO27:1;                    // 27 GPIO27 Enable for LPM Wakeup
    Uint16 GPIO28:1;                    // 28 GPIO28 Enable for LPM Wakeup
    Uint16 GPIO29:1;                    // 29 GPIO29 Enable for LPM Wakeup
    Uint16 GPIO30:1;                    // 30 GPIO30 Enable for LPM Wakeup
    Uint16 GPIO31:1;                    // 31 GPIO31 Enable for LPM Wakeup
};

union GPIOLPMSEL0_REG {
    Uint32  all;
    struct  GPIOLPMSEL0_BITS  bit;
};

struct GPIOLPMSEL1_BITS {               // bits description
    Uint16 GPIO32:1;                    // 0 GPIO32 Enable for LPM Wakeup
    Uint16 GPIO33:1;                    // 1 GPIO33 Enable for LPM Wakeup
    Uint16 GPIO34:1;                    // 2 GPIO34 Enable for LPM Wakeup
    Uint16 GPIO35:1;                    // 3 GPIO35 Enable for LPM Wakeup
    Uint16 GPIO36:1;                    // 4 GPIO36 Enable for LPM Wakeup
    Uint16 GPIO37:1;                    // 5 GPIO37 Enable for LPM Wakeup
    Uint16 GPIO38:1;                    // 6 GPIO38 Enable for LPM Wakeup
    Uint16 GPIO39:1;                    // 7 GPIO39 Enable for LPM Wakeup
    Uint16 GPIO40:1;                    // 8 GPIO40 Enable for LPM Wakeup
    Uint16 GPIO41:1;                    // 9 GPIO41 Enable for LPM Wakeup
    Uint16 GPIO42:1;                    // 10 GPIO42 Enable for LPM Wakeup
    Uint16 GPIO43:1;                    // 11 GPIO43 Enable for LPM Wakeup
    Uint16 GPIO44:1;                    // 12 GPIO44 Enable for LPM Wakeup
    Uint16 GPIO45:1;                    // 13 GPIO45 Enable for LPM Wakeup
    Uint16 GPIO46:1;                    // 14 GPIO46 Enable for LPM Wakeup
    Uint16 GPIO47:1;                    // 15 GPIO47 Enable for LPM Wakeup
    Uint16 GPIO48:1;                    // 16 GPIO48 Enable for LPM Wakeup
    Uint16 GPIO49:1;                    // 17 GPIO49 Enable for LPM Wakeup
    Uint16 GPIO50:1;                    // 18 GPIO50 Enable for LPM Wakeup
    Uint16 GPIO51:1;                    // 19 GPIO51 Enable for LPM Wakeup
    Uint16 GPIO52:1;                    // 20 GPIO52 Enable for LPM Wakeup
    Uint16 GPIO53:1;                    // 21 GPIO53 Enable for LPM Wakeup
    Uint16 GPIO54:1;                    // 22 GPIO54 Enable for LPM Wakeup
    Uint16 GPIO55:1;                    // 23 GPIO55 Enable for LPM Wakeup
    Uint16 GPIO56:1;                    // 24 GPIO56 Enable for LPM Wakeup
    Uint16 GPIO57:1;                    // 25 GPIO57 Enable for LPM Wakeup
    Uint16 GPIO58:1;                    // 26 GPIO58 Enable for LPM Wakeup
    Uint16 GPIO59:1;                    // 27 GPIO59 Enable for LPM Wakeup
    Uint16 GPIO60:1;                    // 28 GPIO60 Enable for LPM Wakeup
    Uint16 GPIO61:1;                    // 29 GPIO61 Enable for LPM Wakeup
    Uint16 GPIO62:1;                    // 30 GPIO62 Enable for LPM Wakeup
    Uint16 GPIO63:1;                    // 31 GPIO63 Enable for LPM Wakeup
};

union GPIOLPMSEL1_REG {
    Uint32  all;
    struct  GPIOLPMSEL1_BITS  bit;
};

struct TMR2CLKCTL_BITS {                // bits description
    Uint16 TMR2CLKSRCSEL:3;             // 2:0 CPU Timer 2 Clock Source Select Bit
    Uint16 TMR2CLKPRESCALE:3;           // 5:3 CPU Timer 2 Clock Pre-Scale Value
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union TMR2CLKCTL_REG {
    Uint32  all;
    struct  TMR2CLKCTL_BITS  bit;
};

struct RESC_BITS {                      // bits description
    Uint16 POR:1;                       // 0 POR Reset Cause Indication Bit
    Uint16 XRSn:1;                      // 1 XRSn Reset Cause Indication Bit
    Uint16 WDRSn:1;                     // 2 WDRSn Reset Cause Indication Bit
    Uint16 NMIWDRSn:1;                  // 3 NMIWDRSn Reset Cause Indication Bit
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 HWBISTn:1;                   // 5 HWBISTn Reset Cause Indication Bit
    Uint16 HIBRESETn:1;                 // 6 HIBRESETn Reset Cause Indication Bit
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 SCCRESETn:1;                 // 8 SCCRESETn Reset Cause Indication Bit
    Uint16 rsvd3:7;                     // 15:9 Reserved
    Uint16 rsvd4:14;                    // 29:16 Reserved
    Uint16 XRSn_pin_status:1;           // 30 XRSN Pin Status
    Uint16 TRSTn_pin_status:1;          // 31 TRSTn Status
};

union RESC_REG {
    Uint32  all;
    struct  RESC_BITS  bit;
};

struct CPU_SYS_REGS {
    union   CPUSYSLOCK1_REG                  CPUSYSLOCK1;                  // Lock bit for CPUSYS registers
    Uint16                                   rsvd1[4];                     // Reserved
    Uint32                                   HIBBOOTMODE;                  // HIB Boot Mode Register
    union   IORESTOREADDR_REG                IORESTOREADDR;                // IORestore() routine Address Register
    union   PIEVERRADDR_REG                  PIEVERRADDR;                  // PIE Vector Fetch Error Address register
    Uint16                                   rsvd2[22];                    // Reserved
    union   PCLKCR0_REG                      PCLKCR0;                      // Peripheral Clock Gating Registers
    union   PCLKCR1_REG                      PCLKCR1;                      // Peripheral Clock Gating Registers
    union   PCLKCR2_REG                      PCLKCR2;                      // Peripheral Clock Gating Registers
    union   PCLKCR3_REG                      PCLKCR3;                      // Peripheral Clock Gating Registers
    union   PCLKCR4_REG                      PCLKCR4;                      // Peripheral Clock Gating Registers
    Uint16                                   rsvd3[2];                     // Reserved
    union   PCLKCR6_REG                      PCLKCR6;                      // Peripheral Clock Gating Registers
    union   PCLKCR7_REG                      PCLKCR7;                      // Peripheral Clock Gating Registers
    union   PCLKCR8_REG                      PCLKCR8;                      // Peripheral Clock Gating Registers
    union   PCLKCR9_REG                      PCLKCR9;                      // Peripheral Clock Gating Registers
    union   PCLKCR10_REG                     PCLKCR10;                     // Peripheral Clock Gating Registers
    union   PCLKCR11_REG                     PCLKCR11;                     // Peripheral Clock Gating Registers
    union   PCLKCR12_REG                     PCLKCR12;                     // Peripheral Clock Gating Registers
    union   PCLKCR13_REG                     PCLKCR13;                     // Peripheral Clock Gating Registers
    union   PCLKCR14_REG                     PCLKCR14;                     // Peripheral Clock Gating Registers
    Uint16                                   rsvd4[2];                     // Reserved
    union   PCLKCR16_REG                     PCLKCR16;                     // Peripheral Clock Gating Registers
    Uint16                                   rsvd5[48];                    // Reserved
    union   SECMSEL_REG                      SECMSEL;                      // Secondary Master Select register for common peripherals: Selects between CLA & DMA
    union   LPMCR_REG                        LPMCR;                        // LPM Control Register
    union   GPIOLPMSEL0_REG                  GPIOLPMSEL0;                  // GPIO LPM Wakeup select registers
    union   GPIOLPMSEL1_REG                  GPIOLPMSEL1;                  // GPIO LPM Wakeup select registers
    union   TMR2CLKCTL_REG                   TMR2CLKCTL;                   // Timer2 Clock Measurement functionality control register
    Uint16                                   rsvd6[2];                     // Reserved
    union   RESC_REG                         RESC;                         // Reset Cause register
};

struct SCSR_BITS {                      // bits description
    Uint16 WDOVERRIDE:1;                // 0 WD Override for WDDIS bit
    Uint16 WDENINT:1;                   // 1 WD Interrupt Enable
    Uint16 WDINTS:1;                    // 2 WD Interrupt Status
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union SCSR_REG {
    Uint16  all;
    struct  SCSR_BITS  bit;
};

struct WDCNTR_BITS {                    // bits description
    Uint16 WDCNTR:8;                    // 7:0 WD Counter
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union WDCNTR_REG {
    Uint16  all;
    struct  WDCNTR_BITS  bit;
};

struct WDKEY_BITS {                     // bits description
    Uint16 WDKEY:8;                     // 7:0 WD KEY
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union WDKEY_REG {
    Uint16  all;
    struct  WDKEY_BITS  bit;
};

struct WDCR_BITS {                      // bits description
    Uint16 WDPS:3;                      // 2:0 WD Clock Prescalar
    Uint16 WDCHK:3;                     // 5:3 WD Check Bits
    Uint16 WDDIS:1;                     // 6 WD Disable
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 rsvd2:8;                     // 15:8 Reserved
};

union WDCR_REG {
    Uint16  all;
    struct  WDCR_BITS  bit;
};

struct WDWCR_BITS {                     // bits description
    Uint16 MIN:8;                       // 7:0 WD Min Threshold setting for Windowed Watchdog functionality
    Uint16 FIRSTKEY:1;                  // 8 First Key Detect Flag
    Uint16 rsvd1:7;                     // 15:9 Reserved
};

union WDWCR_REG {
    Uint16  all;
    struct  WDWCR_BITS  bit;
};

struct WD_REGS {
    Uint16                                   rsvd1[34];                    // Reserved
    union   SCSR_REG                         SCSR;                         // System Control & Status Register
    union   WDCNTR_REG                       WDCNTR;                       // Watchdog Counter Register
    Uint16                                   rsvd2;                        // Reserved
    union   WDKEY_REG                        WDKEY;                        // Watchdog Reset Key Register
    Uint16                                   rsvd3[3];                     // Reserved
    union   WDCR_REG                         WDCR;                         // Watchdog Control Register
    union   WDWCR_REG                        WDWCR;                        // Watchdog Windowed Control Register
};

struct CLA1TASKSRCSELLOCK_BITS {        // bits description
    Uint16 CLA1TASKSRCSEL1:1;           // 0 CLA1TASKSRCSEL1 Register Lock bit
    Uint16 CLA1TASKSRCSEL2:1;           // 1 CLA1TASKSRCSEL2 Register Lock bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLA1TASKSRCSELLOCK_REG {
    Uint32  all;
    struct  CLA1TASKSRCSELLOCK_BITS  bit;
};

struct DMACHSRCSELLOCK_BITS {           // bits description
    Uint16 DMACHSRCSEL1:1;              // 0 DMACHSRCSEL1 Register Lock bit
    Uint16 DMACHSRCSEL2:1;              // 1 DMACHSRCSEL2 Register Lock bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DMACHSRCSELLOCK_REG {
    Uint32  all;
    struct  DMACHSRCSELLOCK_BITS  bit;
};

struct CLA1TASKSRCSEL1_BITS {           // bits description
    Uint16 TASK1:8;                     // 7:0 Selects the Trigger Source for TASK1 of CLA1
    Uint16 TASK2:8;                     // 15:8 Selects the Trigger Source for TASK2 of CLA1
    Uint16 TASK3:8;                     // 23:16 Selects the Trigger Source for TASK3 of CLA1
    Uint16 TASK4:8;                     // 31:24 Selects the Trigger Source for TASK4 of CLA1
};

union CLA1TASKSRCSEL1_REG {
    Uint32  all;
    struct  CLA1TASKSRCSEL1_BITS  bit;
};

struct CLA1TASKSRCSEL2_BITS {           // bits description
    Uint16 TASK5:8;                     // 7:0 Selects the Trigger Source for TASK5 of CLA1
    Uint16 TASK6:8;                     // 15:8 Selects the Trigger Source for TASK6 of CLA1
    Uint16 TASK7:8;                     // 23:16 Selects the Trigger Source for TASK7 of CLA1
    Uint16 TASK8:8;                     // 31:24 Selects the Trigger Source for TASK8 of CLA1
};

union CLA1TASKSRCSEL2_REG {
    Uint32  all;
    struct  CLA1TASKSRCSEL2_BITS  bit;
};

struct DMACHSRCSEL1_BITS {              // bits description
    Uint16 CH1:8;                       // 7:0 Selects the Trigger and Sync Source CH1 of DMA
    Uint16 CH2:8;                       // 15:8 Selects the Trigger and Sync Source CH2 of DMA
    Uint16 CH3:8;                       // 23:16 Selects the Trigger and Sync Source CH3 of DMA
    Uint16 CH4:8;                       // 31:24 Selects the Trigger and Sync Source CH4 of DMA
};

union DMACHSRCSEL1_REG {
    Uint32  all;
    struct  DMACHSRCSEL1_BITS  bit;
};

struct DMACHSRCSEL2_BITS {              // bits description
    Uint16 CH5:8;                       // 7:0 Selects the Trigger and Sync Source CH5 of DMA
    Uint16 CH6:8;                       // 15:8 Selects the Trigger and Sync Source CH6 of DMA
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union DMACHSRCSEL2_REG {
    Uint32  all;
    struct  DMACHSRCSEL2_BITS  bit;
};

struct DMA_CLA_SRC_SEL_REGS {
    union   CLA1TASKSRCSELLOCK_REG           CLA1TASKSRCSELLOCK;           // CLA1 Task Trigger Source Select Lock Register
    Uint16                                   rsvd1[2];                     // Reserved
    union   DMACHSRCSELLOCK_REG              DMACHSRCSELLOCK;              // DMA Channel Triger Source Select Lock Register
    union   CLA1TASKSRCSEL1_REG              CLA1TASKSRCSEL1;              // CLA1 Task Trigger Source Select Register-1
    union   CLA1TASKSRCSEL2_REG              CLA1TASKSRCSEL2;              // CLA1 Task Trigger Source Select Register-2
    Uint16                                   rsvd2[12];                    // Reserved
    union   DMACHSRCSEL1_REG                 DMACHSRCSEL1;                 // DMA Channel Trigger Source Select Register-1
    union   DMACHSRCSEL2_REG                 DMACHSRCSEL2;                 // DMA Channel Trigger Source Select Register-2
};

struct SYNCSELECT_BITS {                // bits description
    Uint16 EPWM4SYNCIN:3;               // 2:0 Selects Sync Input Source for EPWM4
    Uint16 EPWM7SYNCIN:3;               // 5:3 Selects Sync Input Source for EPWM7
    Uint16 EPWM10SYNCIN:3;              // 8:6 Selects Sync Input Source for EPWM10
    Uint16 ECAP1SYNCIN:3;               // 11:9 Selects Sync Input Source for ECAP1
    Uint16 ECAP4SYNCIN:3;               // 14:12 Selects Sync Input Source for ECAP4
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:11;                    // 26:16 Reserved
    Uint16 SYNCOUT:2;                   // 28:27 Select Syncout Source
    Uint16 rsvd3:3;                     // 31:29 Reserved
};

union SYNCSELECT_REG {
    Uint32  all;
    struct  SYNCSELECT_BITS  bit;
};

struct ADCSOCOUTSELECT_BITS {           // bits description
    Uint16 PWM1SOCAEN:1;                // 0 PWM1SOCAEN Enable for ADCSOCAO 
    Uint16 PWM2SOCAEN:1;                // 1 PWM2SOCAEN Enable for ADCSOCAO 
    Uint16 PWM3SOCAEN:1;                // 2 PWM3SOCAEN Enable for ADCSOCAO 
    Uint16 PWM4SOCAEN:1;                // 3 PWM4SOCAEN Enable for ADCSOCAO 
    Uint16 PWM5SOCAEN:1;                // 4 PWM5SOCAEN Enable for ADCSOCAO 
    Uint16 PWM6SOCAEN:1;                // 5 PWM6SOCAEN Enable for ADCSOCAO 
    Uint16 PWM7SOCAEN:1;                // 6 PWM7SOCAEN Enable for ADCSOCAO 
    Uint16 PWM8SOCAEN:1;                // 7 PWM8SOCAEN Enable for ADCSOCAO 
    Uint16 PWM9SOCAEN:1;                // 8 PWM9SOCAEN Enable for ADCSOCAO 
    Uint16 PWM10SOCAEN:1;               // 9 PWM10SOCAEN Enable for ADCSOCAO 
    Uint16 PWM11SOCAEN:1;               // 10 PWM11SOCAEN Enable for ADCSOCAO 
    Uint16 PWM12SOCAEN:1;               // 11 PWM12SOCAEN Enable for ADCSOCAO 
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 PWM1SOCBEN:1;                // 16 PWM1SOCBEN Enable for ADCSOCBO 
    Uint16 PWM2SOCBEN:1;                // 17 PWM2SOCBEN Enable for ADCSOCBO 
    Uint16 PWM3SOCBEN:1;                // 18 PWM3SOCBEN Enable for ADCSOCBO 
    Uint16 PWM4SOCBEN:1;                // 19 PWM4SOCBEN Enable for ADCSOCBO 
    Uint16 PWM5SOCBEN:1;                // 20 PWM5SOCBEN Enable for ADCSOCBO 
    Uint16 PWM6SOCBEN:1;                // 21 PWM6SOCBEN Enable for ADCSOCBO 
    Uint16 PWM7SOCBEN:1;                // 22 PWM7SOCBEN Enable for ADCSOCBO 
    Uint16 PWM8SOCBEN:1;                // 23 PWM8SOCBEN Enable for ADCSOCBO 
    Uint16 PWM9SOCBEN:1;                // 24 PWM9SOCBEN Enable for ADCSOCBO 
    Uint16 PWM10SOCBEN:1;               // 25 PWM10SOCBEN Enable for ADCSOCBO 
    Uint16 PWM11SOCBEN:1;               // 26 PWM11SOCBEN Enable for ADCSOCBO 
    Uint16 PWM12SOCBEN:1;               // 27 PWM12SOCBEN Enable for ADCSOCBO 
    Uint16 rsvd2:4;                     // 31:28 Reserved
};

union ADCSOCOUTSELECT_REG {
    Uint32  all;
    struct  ADCSOCOUTSELECT_BITS  bit;
};

struct SYNCSOCLOCK_BITS {               // bits description
    Uint16 SYNCSELECT:1;                // 0 SYNCSEL Register Lock bit
    Uint16 ADCSOCOUTSELECT:1;           // 1 ADCSOCOUTSELECT Register Lock bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYNCSOCLOCK_REG {
    Uint32  all;
    struct  SYNCSOCLOCK_BITS  bit;
};

struct SYNC_SOC_REGS {
    union   SYNCSELECT_REG                   SYNCSELECT;                   // Sync Input and Output Select Register
    union   ADCSOCOUTSELECT_REG              ADCSOCOUTSELECT;              // External ADC (Off Chip) SOC Select Register
    union   SYNCSOCLOCK_REG                  SYNCSOCLOCK;                  // SYNCSEL and EXTADCSOC Select Lock register
};

//---------------------------------------------------------------------------
// SYSCTRL External References & Function Declarations:
//
extern volatile struct WD_REGS WdRegs;
extern volatile struct SYNC_SOC_REGS SyncSocRegs;
extern volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;
extern volatile struct DEV_CFG_REGS DevCfgRegs;
extern volatile struct CLK_CFG_REGS ClkCfgRegs;
extern volatile struct CPU_SYS_REGS CpuSysRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
