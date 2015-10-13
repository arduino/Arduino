//###########################################################################
//
// FILE:    F2837xS_sdfm.h
//
// TITLE:   F2837xS Device SDFM Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_SDFM_H__
#define __F2837xS_SDFM_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// SDFM Individual Register Bit Definitions:

struct SDIFLG_BITS {                    // bits description
    Uint16 IFH1:1;                      // 0 High-level Interrupt flag Filter 1
    Uint16 IFL1:1;                      // 1 Low-Level Interrupt flag Filter 1
    Uint16 IFH2:1;                      // 2 High-level Interrupt flag Filter 2
    Uint16 IFL2:1;                      // 3 Low-Level Interrupt flag Filter 2
    Uint16 IFH3:1;                      // 4 High-level Interrupt flag Filter 3
    Uint16 IFL3:1;                      // 5 Low-Level Interrupt flag Filter 3
    Uint16 IFH4:1;                      // 6 High-level Interrupt flag Filter 4
    Uint16 IFL4:1;                      // 7 Low-Level Interrupt flag Filter 4
    Uint16 MF1:1;                       // 8 Modulator Failure for Filter 1
    Uint16 MF2:1;                       // 9 Modulator Failure for Filter 2
    Uint16 MF3:1;                       // 10 Modulator Failure for Filter 3
    Uint16 MF4:1;                       // 11 Modulator Failure for Filter 4
    Uint16 AF1:1;                       // 12 Acknowledge flag for Filter 1
    Uint16 AF2:1;                       // 13 Acknowledge flag for Filter 2
    Uint16 AF3:1;                       // 14 Acknowledge flag for Filter 3
    Uint16 AF4:1;                       // 15 Acknowledge flag for Filter 4
    Uint16 rsvd1:15;                    // 30:16 Reserved
    Uint16 MIF:1;                       // 31 Master Interrupt Flag
};

union SDIFLG_REG {
    Uint32  all;
    struct  SDIFLG_BITS  bit;
};

struct SDIFLGCLR_BITS {                 // bits description
    Uint16 IFH1:1;                      // 0 High-level Interrupt flag Filter 1
    Uint16 IFL1:1;                      // 1 Low-Level Interrupt flag Filter 1
    Uint16 IFH2:1;                      // 2 High-level Interrupt flag Filter 2
    Uint16 IFL2:1;                      // 3 Low-Level Interrupt flag Filter 2
    Uint16 IFH3:1;                      // 4 High-level Interrupt flag Filter 3
    Uint16 IFL3:1;                      // 5 Low-Level Interrupt flag Filter 3
    Uint16 IFH4:1;                      // 6 High-level Interrupt flag Filter 4
    Uint16 IFL4:1;                      // 7 Low-Level Interrupt flag Filter 4
    Uint16 MF1:1;                       // 8 Modulator Failure for Filter 1
    Uint16 MF2:1;                       // 9 Modulator Failure for Filter 2
    Uint16 MF3:1;                       // 10 Modulator Failure for Filter 3
    Uint16 MF4:1;                       // 11 Modulator Failure for Filter 4
    Uint16 AF1:1;                       // 12 Acknowledge flag for Filter 1
    Uint16 AF2:1;                       // 13 Acknowledge flag for Filter 2
    Uint16 AF3:1;                       // 14 Acknowledge flag for Filter 3
    Uint16 AF4:1;                       // 15 Acknowledge flag for Filter 4
    Uint16 rsvd1:15;                    // 30:16 Reserved
    Uint16 MIF:1;                       // 31 Master Interrupt Flag
};

union SDIFLGCLR_REG {
    Uint32  all;
    struct  SDIFLGCLR_BITS  bit;
};

struct SDCTL_BITS {                     // bits description
    Uint16 rsvd1:13;                    // 12:0 Reserved
    Uint16 MIE:1;                       // 13 Master Interrupt enable
    Uint16 rsvd2:1;                     // 14 Reserved
    Uint16 rsvd3:1;                     // 15 Reserved
};

union SDCTL_REG {
    Uint16  all;
    struct  SDCTL_BITS  bit;
};

struct SDMFILEN_BITS {                  // bits description
    Uint16 rsvd1:4;                     // 3:0 Reserved
    Uint16 rsvd2:3;                     // 6:4 Reserved
    Uint16 rsvd3:2;                     // 8:7 Reserved
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 rsvd5:1;                     // 10 Reserved
    Uint16 MFE:1;                       // 11 Master Filter Enable. 
    Uint16 rsvd6:1;                     // 12 Reserved
    Uint16 rsvd7:3;                     // 15:13 Reserved
};

union SDMFILEN_REG {
    Uint16  all;
    struct  SDMFILEN_BITS  bit;
};

struct SDCTLPARM1_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Delta-Sigma Modulator mode
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:11;                    // 15:5 Reserved
};

union SDCTLPARM1_REG {
    Uint16  all;
    struct  SDCTLPARM1_BITS  bit;
};

struct SDDFPARM1_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable 
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data Filter Structure (DataFast/1/2/3)
    Uint16 FILRESEN:1;                  // 12 Data FILTER Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM1_REG {
    Uint16  all;
    struct  SDDFPARM1_BITS  bit;
};

struct SDIPARM1_BITS {                  // bits description
    Uint16 rsvd1:7;                     // 6:0 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:1;                     // 8 Reserved
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDIPARM1_REG {
    Uint16  all;
    struct  SDIPARM1_BITS  bit;
};

struct SDCMPH1_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH1_REG {
    Uint16  all;
    struct  SDCMPH1_BITS  bit;
};

struct SDCMPL1_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL1_REG {
    Uint16  all;
    struct  SDCMPL1_BITS  bit;
};

struct SDCPARM1_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio = COSR + 1
    Uint16 IEH:1;                       // 5 High-level interrupt enable
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator filter structure (Sincfast/Sinc1/Sinc2/Sinc3
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union SDCPARM1_REG {
    Uint16  all;
    struct  SDCPARM1_BITS  bit;
};

struct SDDATA1_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 16-bit Data in 16b mode, Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode
};

union SDDATA1_REG {
    Uint32  all;
    struct  SDDATA1_BITS  bit;
};

struct SDCTLPARM2_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Delta-Sigma Modulator mode
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 MS:11;                       // 15:5 Manchester Status
};

union SDCTLPARM2_REG {
    Uint16  all;
    struct  SDCTLPARM2_BITS  bit;
};

struct SDDFPARM2_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable 
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data Filter Structure (SincFast/1/2/3)
    Uint16 FILRESEN:1;                  // 12 Data FILTER Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM2_REG {
    Uint16  all;
    struct  SDDFPARM2_BITS  bit;
};

struct SDIPARM2_BITS {                  // bits description
    Uint16 rsvd1:7;                     // 6:0 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:1;                     // 8 Reserved
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDIPARM2_REG {
    Uint16  all;
    struct  SDIPARM2_BITS  bit;
};

struct SDCMPH2_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH2_REG {
    Uint16  all;
    struct  SDCMPH2_BITS  bit;
};

struct SDCMPL2_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL2_REG {
    Uint16  all;
    struct  SDCMPL2_BITS  bit;
};

struct SDCPARM2_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio = COSR + 1
    Uint16 IEH:1;                       // 5 High-level interrupt enable
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator filter structure (Sincfast/Sinc1/Sinc2/Sinc3
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union SDCPARM2_REG {
    Uint16  all;
    struct  SDCPARM2_BITS  bit;
};

struct SDDATA2_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 16-bit Data in 16b mode, Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode
};

union SDDATA2_REG {
    Uint32  all;
    struct  SDDATA2_BITS  bit;
};

struct SDCTLPARM3_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Delta-Sigma Modulator mode
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 MS:11;                       // 15:5 Manchester Status
};

union SDCTLPARM3_REG {
    Uint16  all;
    struct  SDCTLPARM3_BITS  bit;
};

struct SDDFPARM3_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable 
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data filter structure (SincFast/1/2/3)
    Uint16 FILRESEN:1;                  // 12 Data FILTER Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM3_REG {
    Uint16  all;
    struct  SDDFPARM3_BITS  bit;
};

struct SDIPARM3_BITS {                  // bits description
    Uint16 rsvd1:7;                     // 6:0 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:1;                     // 8 Reserved
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDIPARM3_REG {
    Uint16  all;
    struct  SDIPARM3_BITS  bit;
};

struct SDCMPH3_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH3_REG {
    Uint16  all;
    struct  SDCMPH3_BITS  bit;
};

struct SDCMPL3_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL3_REG {
    Uint16  all;
    struct  SDCMPL3_BITS  bit;
};

struct SDCPARM3_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio = COSR + 1
    Uint16 IEH:1;                       // 5 High-level interrupt enable
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator filter structure (Sincfast/Sinc1/Sinc2/Sinc3
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union SDCPARM3_REG {
    Uint16  all;
    struct  SDCPARM3_BITS  bit;
};

struct SDDATA3_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 16-bit Data in 16b mode, Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode
};

union SDDATA3_REG {
    Uint32  all;
    struct  SDDATA3_BITS  bit;
};

struct SDCTLPARM4_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Delta-Sigma Modulator mode
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 MS:11;                       // 15:5 Manchester Status
};

union SDCTLPARM4_REG {
    Uint16  all;
    struct  SDCTLPARM4_BITS  bit;
};

struct SDDFPARM4_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 SINC Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable 
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data filter structure (SincFast/1/2/3)
    Uint16 FILRESEN:1;                  // 12 SINC FILTER Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM4_REG {
    Uint16  all;
    struct  SDDFPARM4_BITS  bit;
};

struct SDIPARM4_BITS {                  // bits description
    Uint16 rsvd1:7;                     // 6:0 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:1;                     // 8 Reserved
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDIPARM4_REG {
    Uint16  all;
    struct  SDIPARM4_BITS  bit;
};

struct SDCMPH4_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH4_REG {
    Uint16  all;
    struct  SDCMPH4_BITS  bit;
};

struct SDCMPL4_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output.
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL4_REG {
    Uint16  all;
    struct  SDCMPL4_BITS  bit;
};

struct SDCPARM4_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio = COSR + 1
    Uint16 IEH:1;                       // 5 High-level interrupt enable
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator filter structure (Sincfast/Sinc1/Sinc2/Sinc3
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union SDCPARM4_REG {
    Uint16  all;
    struct  SDCPARM4_BITS  bit;
};

struct SDDATA4_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 16-bit Data in 16b mode, Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode
};

union SDDATA4_REG {
    Uint32  all;
    struct  SDDATA4_BITS  bit;
};

struct SDFM_REGS {
    union   SDIFLG_REG                       SDIFLG;                       // Interrupt Flag Register
    union   SDIFLGCLR_REG                    SDIFLGCLR;                    // Interrupt Flag Clear Register
    union   SDCTL_REG                        SDCTL;                        // SD Control Register
    Uint16                                   rsvd1;                        // Reserved
    union   SDMFILEN_REG                     SDMFILEN;                     // SD Master Filter Enable
    Uint16                                   rsvd2[9];                     // Reserved
    union   SDCTLPARM1_REG                   SDCTLPARM1;                   // Control Parameter Register for Ch1
    union   SDDFPARM1_REG                    SDDFPARM1;                    // Data Filter Parameter Register for Ch1
    union   SDIPARM1_REG                     SDIPARM1;                     // Integer Parameter Register for Ch1
    union   SDCMPH1_REG                      SDCMPH1;                      // High-level Threshold Register for Ch1
    union   SDCMPL1_REG                      SDCMPL1;                      // Low-level Threshold Register for Ch1
    union   SDCPARM1_REG                     SDCPARM1;                     // Comparator Parameter Register for Ch1
    union   SDDATA1_REG                      SDDATA1;                      // Filter Data Register (16 or 32bit) for Ch1
    Uint16                                   rsvd3[8];                     // Reserved
    union   SDCTLPARM2_REG                   SDCTLPARM2;                   // Control Parameter Register for Ch2
    union   SDDFPARM2_REG                    SDDFPARM2;                    // Data Filter Parameter Register for Ch2
    union   SDIPARM2_REG                     SDIPARM2;                     // Integer Parameter Register for Ch2
    union   SDCMPH2_REG                      SDCMPH2;                      // High-level Threshold Register for Ch2
    union   SDCMPL2_REG                      SDCMPL2;                      // Low-level Threshold Register for Ch2
    union   SDCPARM2_REG                     SDCPARM2;                     // Comparator Parameter Register for Ch2
    union   SDDATA2_REG                      SDDATA2;                      // Filter Data Register (16 or 32bit) for Ch2
    Uint16                                   rsvd4[8];                     // Reserved
    union   SDCTLPARM3_REG                   SDCTLPARM3;                   // Control Parameter Register for Ch3
    union   SDDFPARM3_REG                    SDDFPARM3;                    // Data Filter Parameter Register for Ch3
    union   SDIPARM3_REG                     SDIPARM3;                     // Integer Parameter Register for Ch3
    union   SDCMPH3_REG                      SDCMPH3;                      // High-level Threshold Register for Ch3
    union   SDCMPL3_REG                      SDCMPL3;                      // Low-level Threshold Register for Ch3
    union   SDCPARM3_REG                     SDCPARM3;                     // Comparator Parameter Register for Ch3
    union   SDDATA3_REG                      SDDATA3;                      // Filter Data Register (16 or 32bit) for Ch3
    Uint16                                   rsvd5[8];                     // Reserved
    union   SDCTLPARM4_REG                   SDCTLPARM4;                   // Control Parameter Register for Ch4
    union   SDDFPARM4_REG                    SDDFPARM4;                    // Data Filter Parameter Register for Ch4
    union   SDIPARM4_REG                     SDIPARM4;                     // Integer Parameter Register for Ch4
    union   SDCMPH4_REG                      SDCMPH4;                      // High-level Threshold Register for Ch4
    union   SDCMPL4_REG                      SDCMPL4;                      // Low-level Threshold Register for Ch4
    union   SDCPARM4_REG                     SDCPARM4;                     // Comparator Parameter Register for Ch4
    union   SDDATA4_REG                      SDDATA4;                      // Filter Data Register (16 or 32bit) for Ch4
    Uint16                                   rsvd6[56];                    // Reserved
};

//---------------------------------------------------------------------------
// SDFM External References & Function Declarations:
//
extern volatile struct SDFM_REGS Sdfm1Regs;
extern volatile struct SDFM_REGS Sdfm2Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
