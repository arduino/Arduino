// TI File $Revision: /main/3 $
// Checkin $Date: November 10, 2008   10:44:09 $
//###########################################################################
//
// FILE:    DSP2802x_SWPrioritizedIsrLevels.h
//
// TITLE:   DSP28 Devices Software Prioritized Interrupt Service Routine
//          Level definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef DSP2802x_SW_PRIORITZIED_ISR_H
#define DSP2802x_SW_PRIORITZIED_ISR_H

#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------
// Interrupt Enable Register Allocation For 2802x Devices:
//-------------------------------------------------------------------------------
// Interrupts can be enabled/disabled using the CPU interrupt enable register
// (IER) and the PIE interrupt enable registers (PIEIER1 to PIEIER12).
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
// Set "Global" Interrupt Priority Level (IER register):
//-------------------------------------------------------------------------------
// The user must set the appropriate priority level for each of the CPU
// interrupts. This is termed as the "global" priority. The priority level
// must be a number between 1 (highest) to 16 (lowest). A value of 0 must
// be entered for reserved interrupts or interrupts that are not used. This
// will also reduce code size by not including ISR's that are not used.
//
// Note: The priority levels below are used to calculate the IER register
//       interrupt masks MINT1 to MINT16.
//
//
// Note: The priority levels shown here may not make sense in a
//       real application.  This is for demonstration purposes only!!!
//
//       The user should change these to values that make sense for
//       their application.
//
// 0  = not used
// 1  = highest priority
// ...
// 16 = lowest priority
#define    INT1PL      2        // Group1 Interrupts (PIEIER1)
#define    INT2PL      1        // Group2 Interrupts (PIEIER2)
#define    INT3PL      4        // Group3 Interrupts (PIEIER3)
#define    INT4PL      2        // Group4 Interrupts (PIEIER4)
#define    INT5PL      2        // Group5 Interrupts (PIEIER5)
#define    INT6PL      3        // Group6 Interrupts (PIEIER6)
#define    INT7PL      0        // reserved
#define    INT8PL      0        // reserved
#define    INT9PL      3        // Group9 Interrupts (PIEIER9)
#define    INT10PL     0        // reserved
#define    INT11PL     0        // reserved
#define    INT12PL     0        // reserved
#define    INT13PL     4        // TINT1
#define    INT14PL     4        // INT14 (TINT2)
#define    INT15PL     4        // DATALOG
#define    INT16PL     4        // RTOSINT

//-------------------------------------------------------------------------------
// Set "Group" Interrupt Priority Level (PIEIER1 to PIEIER12 registers):
//-------------------------------------------------------------------------------
// The user must set the appropriate priority level for each of the PIE
// interrupts. This is termed as the "group" priority. The priority level
// must be a number between 1 (highest) to 8 (lowest). A value of 0 must
// be entered for reserved interrupts or interrupts that are not used. This
// will also reduce code size by not including ISR's that are not used:
//
// Note: The priority levels below are used to calculate the following
//       PIEIER register interrupt masks:
//                           MG11 to MG18
//                           MG21 to MG28
//                           MG31 to MG38
//                           MG41 to MG48
//                           MG51 to MG58
//                           MG61 to MG68
//                           MG71 to MG78
//                           MG81 to MG88
//                           MG91 to MG98
//                           MG101 to MG108
//                           MG111 to MG118
//                           MG121 to MG128
//
// Note: The priority levels shown here may not make sense in a
//       real application.  This is for demonstration purposes only!!!
//
//       The user should change these to values that make sense for
//       their application.
//
// 0  = not used
// 1  = highest priority
// ...
// 8  = lowest priority
//

#define    G11PL       7        // ADCINT1     (ADC)  or reserved if 10.1 is ADCINT1
#define    G12PL       6        // ADCINT2     (ADC)  or reserved if 10.2 is ADCINT2
#define    G13PL       0        // reserved
#define    G14PL       1        // XINT1       (External)
#define    G15PL       3        // XINT2       (External)
#define    G16PL       2        // ADCINT9     (ADC)
#define    G17PL       1        // TINT0       (CPU Timer 0)
#define    G18PL       5        // WAKEINT     (WD/LPM)

#define    G21PL       4        // EPWM1_TZINT (EPwm1 Trip)
#define    G22PL       3        // EPWM2_TZINT (EPwm2 Trip)
#define    G23PL       2        // EPWM3_TZINT (EPwm3 Trip)
#define    G24PL       1        // EPWM4_TZINT (EPwm4 Trip)
#define    G25PL       0        // reserved
#define    G26PL       0        // reserved
#define    G27PL       0        // reserved
#define    G28PL       0        // reserved

#define    G31PL       4        // EPWM1_INT   (EPwm1 Int)
#define    G32PL       1        // EPWM2_INT   (EPwm2 Int)
#define    G33PL       1        // EPWM3_INT   (EPwm3 Int)
#define    G34PL       2        // EPWM4_INT   (EPwm4 Int)
#define    G35PL       0        // reserved
#define    G36PL       0        // reserved
#define    G37PL       0        // reserved
#define    G38PL       0        // reserved

#define    G41PL       1        // ECAP1_INT   (eCAP1 Int)
#define    G42PL       0        // reserved
#define    G43PL       0        // reserved
#define    G44PL       0        // reserved
#define    G45PL       0        // reserved
#define    G46PL       0        // reserved
#define    G47PL       0        // reserved
#define    G48PL       0        // reserved

#define    G51PL       0        // reserved
#define    G52PL       0        // reserved
#define    G53PL       0        // reserved
#define    G54PL       0        // reserved
#define    G55PL       0        // reserved
#define    G56PL       0        // reserved
#define    G57PL       0        // reserved
#define    G58PL       0        // reserved

#define    G61PL       2        // SPIRXINTA (SPI-A)
#define    G62PL       1        // SPITXINTA (SPI-A)
#define    G63PL       0        // reserved
#define    G64PL       0        // reserved
#define    G65PL       0        // reserved
#define    G66PL       0        // reserved
#define    G67PL       0        // reserved
#define    G68PL       0        // reserved


#define    G71PL      0        // reserved
#define    G72PL      0        // reserved
#define    G73PL      0        // reserved
#define    G74PL      0        // reserved
#define    G75PL      0        // reserved
#define    G76PL      0        // reserved
#define    G77PL      0        // reserved
#define    G78PL      0        // reserved


#define    G81PL       1        // I2CINT1A  (I2C-A)
#define    G82PL       2        // I2CINT2A  (I2C-A)
#define    G83PL       0        // reserved
#define    G84PL       0        // reserved
#define    G85PL       0        // reserved
#define    G86PL       0        // reserved
#define    G87PL       0        // reserved
#define    G88PL       0        // reserved

#define    G91PL       1        // SCIRXINTA (SCI-A)
#define    G92PL       5        // SCITXINTA (SCI-A)
#define    G93PL       0        // reserved
#define    G94PL       0        // reserved
#define    G95PL       0        // reserved
#define    G96PL       0        // reserved
#define    G97PL       0        // reserved
#define    G98PL       0        // reserved


#define    G101PL      0        // reserved  or ADCINT1 (define G11PL as 0 / reserved)
#define    G102PL      0        // reserved  or ADCINT2 (define G12PL as 0 / reserved)
#define    G103PL      1        // ADCINT3   (ADC)
#define    G104PL      4        // ADCINT4   (ADC)
#define    G105PL      5        // ADCINT5   (ADC)
#define    G106PL      7        // ADCINT6   (ADC)
#define    G107PL      7        // ADCINT7   (ADC)
#define    G108PL      3        // ADCINT8   (ADC)


#define    G111PL      0        // reserved
#define    G112PL      0        // reserved
#define    G113PL      0        // reserved
#define    G114PL      0        // reserved
#define    G115PL      0        // reserved
#define    G116PL      0        // reserved
#define    G117PL      0        // reserved
#define    G118PL      0        // reserved

#define    G121PL      1        // XINT3     (External)
#define    G122PL      0        // reserved
#define    G123PL      0        // reserved
#define    G124PL      0        // reserved
#define    G125PL      0        // reserved
#define    G126PL      0        // reserved
#define    G127PL      0        // reserved
#define    G128PL      0        // reserved

// There should be no need to modify code below this line
//-------------------------------------------------------------------------------
// Automatically generate IER interrupt masks MINT1 to MINT16:
//

// Beginning of MINT1:
#if (INT1PL == 0)
#define  MINT1_1PL    ~(1 << 0)
#else
#define  MINT1_1PL    0xFFFF
#endif

#if (INT2PL >= INT1PL) || (INT2PL == 0)
#define  MINT1_2PL   ~(1 << 1)
#else
#define  MINT1_2PL   0xFFFF
#endif

#if (INT3PL >= INT1PL) || (INT3PL == 0)
#define  MINT1_3PL   ~(1 << 2)
#else
#define  MINT1_3PL   0xFFFF
#endif

#if (INT4PL >= INT1PL) || (INT4PL == 0)
#define  MINT1_4PL   ~(1 << 3)
#else
#define  MINT1_4PL   0xFFFF
#endif

#if (INT5PL >= INT1PL) || (INT5PL == 0)
#define  MINT1_5PL   ~(1 << 4)
#else
#define  MINT1_5PL   0xFFFF
#endif

#if (INT6PL >= INT1PL) || (INT6PL == 0)
#define  MINT1_6PL   ~(1 << 5)
#else
#define  MINT1_6PL   0xFFFF
#endif

#if (INT7PL >= INT1PL) || (INT7PL == 0)
#define  MINT1_7PL   ~(1 << 6)
#else
#define  MINT1_7PL   0xFFFF
#endif

#if (INT8PL >= INT1PL) || (INT8PL == 0)
#define  MINT1_8PL   ~(1 << 7)
#else
#define  MINT1_8PL   0xFFFF
#endif

#if (INT9PL >= INT1PL) || (INT9PL == 0)
#define  MINT1_9PL   ~(1 << 8)
#else
#define  MINT1_9PL   0xFFFF
#endif

#if (INT10PL >= INT1PL) || (INT10PL == 0)
#define  MINT1_10PL   ~(1 << 9)
#else
#define  MINT1_10PL   0xFFFF
#endif

#if (INT11PL >= INT1PL) || (INT11PL == 0)
#define  MINT1_11PL   ~(1 << 10)
#else
#define  MINT1_11PL   0xFFFF
#endif

#if (INT12PL >= INT1PL) || (INT12PL == 0)
#define  MINT1_12PL   ~(1 << 11)
#else
#define  MINT1_12PL   0xFFFF
#endif

#if (INT13PL >= INT1PL) || (INT13PL == 0)
#define  MINT1_13PL   ~(1 << 12)
#else
#define  MINT1_13PL   0xFFFF
#endif

#if (INT14PL >= INT1PL) || (INT14PL == 0)
#define  MINT1_14PL   ~(1 << 13)
#else
#define  MINT1_14PL   0xFFFF
#endif

#if (INT15PL >= INT1PL) || (INT15PL == 0)
#define  MINT1_15PL   ~(1 << 14)
#else
#define  MINT1_15PL   0xFFFF
#endif

#if (INT16PL >= INT1PL) || (INT16PL == 0)
#define  MINT1_16PL   ~(1 << 15)
#else
#define  MINT1_16PL   0xFFFF
#endif

#define  MINT1    (MINT1_1PL  & MINT1_2PL  & MINT1_3PL  & MINT1_4PL  & \
                   MINT1_5PL  & MINT1_6PL  & MINT1_7PL  & MINT1_8PL  & \
                   MINT1_9PL  & MINT1_10PL & MINT1_11PL & MINT1_12PL & \
                   MINT1_13PL & MINT1_14PL & MINT1_15PL & MINT1_16PL)
// End Of MINT1.

// Beginning of MINT2:
#if (INT1PL >= INT2PL) || (INT1PL == 0)
#define  MINT2_1PL    ~(1 << 0)
#else
#define  MINT2_1PL    0xFFFF
#endif

#if (INT2PL == 0)
#define  MINT2_2PL   ~(1 << 1)
#else
#define  MINT2_2PL   0xFFFF
#endif

#if (INT3PL >= INT2PL) || (INT3PL == 0)
#define  MINT2_3PL   ~(1 << 2)
#else
#define  MINT2_3PL   0xFFFF
#endif

#if (INT4PL >= INT2PL) || (INT4PL == 0)
#define  MINT2_4PL   ~(1 << 3)
#else
#define  MINT2_4PL   0xFFFF
#endif

#if (INT5PL >= INT2PL) || (INT5PL == 0)
#define  MINT2_5PL   ~(1 << 4)
#else
#define  MINT2_5PL   0xFFFF
#endif

#if (INT6PL >= INT2PL) || (INT6PL == 0)
#define  MINT2_6PL   ~(1 << 5)
#else
#define  MINT2_6PL   0xFFFF
#endif

#if (INT7PL >= INT2PL) || (INT7PL == 0)
#define  MINT2_7PL   ~(1 << 6)
#else
#define  MINT2_7PL   0xFFFF
#endif

#if (INT8PL >= INT2PL) || (INT8PL == 0)
#define  MINT2_8PL   ~(1 << 7)
#else
#define  MINT2_8PL   0xFFFF
#endif

#if (INT9PL >= INT2PL) || (INT9PL == 0)
#define  MINT2_9PL   ~(1 << 8)
#else
#define  MINT2_9PL   0xFFFF
#endif

#if (INT10PL >= INT2PL) || (INT10PL == 0)
#define  MINT2_10PL   ~(1 << 9)
#else
#define  MINT2_10PL   0xFFFF
#endif

#if (INT11PL >= INT2PL) || (INT11PL == 0)
#define  MINT2_11PL   ~(1 << 10)
#else
#define  MINT2_11PL   0xFFFF
#endif

#if (INT12PL >= INT2PL) || (INT12PL == 0)
#define  MINT2_12PL   ~(1 << 11)
#else
#define  MINT2_12PL   0xFFFF
#endif

#if (INT13PL >= INT2PL) || (INT13PL == 0)
#define  MINT2_13PL   ~(1 << 12)
#else
#define  MINT2_13PL   0xFFFF
#endif

#if (INT14PL >= INT2PL) || (INT14PL == 0)
#define  MINT2_14PL   ~(1 << 13)
#else
#define  MINT2_14PL   0xFFFF
#endif

#if (INT15PL >= INT2PL) || (INT15PL == 0)
#define  MINT2_15PL   ~(1 << 14)
#else
#define  MINT2_15PL   0xFFFF
#endif

#if (INT16PL >= INT2PL) || (INT16PL == 0)
#define  MINT2_16PL   ~(1 << 15)
#else
#define  MINT2_16PL   0xFFFF
#endif

#define  MINT2    (MINT2_1PL  & MINT2_2PL  & MINT2_3PL  & MINT2_4PL  & \
                   MINT2_5PL  & MINT2_6PL  & MINT2_7PL  & MINT2_8PL  & \
                   MINT2_9PL  & MINT2_10PL & MINT2_11PL & MINT2_12PL & \
                   MINT2_13PL & MINT2_14PL & MINT2_15PL & MINT2_16PL)
// End Of MINT2.

// Beginning of MINT3:
#if (INT1PL >= INT3PL) || (INT1PL == 0)
#define  MINT3_1PL    ~(1 << 0)
#else
#define  MINT3_1PL    0xFFFF
#endif

#if (INT2PL >= INT3PL) || (INT2PL == 0)
#define  MINT3_2PL   ~(1 << 1)
#else
#define  MINT3_2PL   0xFFFF
#endif

#if (INT3PL == 0)
#define  MINT3_3PL   ~(1 << 2)
#else
#define  MINT3_3PL   0xFFFF
#endif

#if (INT4PL >= INT3PL) || (INT4PL == 0)
#define  MINT3_4PL   ~(1 << 3)
#else
#define  MINT3_4PL   0xFFFF
#endif

#if (INT5PL >= INT3PL) || (INT5PL == 0)
#define  MINT3_5PL   ~(1 << 4)
#else
#define  MINT3_5PL   0xFFFF
#endif

#if (INT6PL >= INT3PL) || (INT6PL == 0)
#define  MINT3_6PL   ~(1 << 5)
#else
#define  MINT3_6PL   0xFFFF
#endif

#if (INT7PL >= INT3PL) || (INT7PL == 0)
#define  MINT3_7PL   ~(1 << 6)
#else
#define  MINT3_7PL   0xFFFF
#endif

#if (INT8PL >= INT3PL) || (INT8PL == 0)
#define  MINT3_8PL   ~(1 << 7)
#else
#define  MINT3_8PL   0xFFFF
#endif

#if (INT9PL >= INT3PL) || (INT9PL == 0)
#define  MINT3_9PL   ~(1 << 8)
#else
#define  MINT3_9PL   0xFFFF
#endif

#if (INT10PL >= INT3PL) || (INT10PL == 0)
#define  MINT3_10PL   ~(1 << 9)
#else
#define  MINT3_10PL   0xFFFF
#endif

#if (INT11PL >= INT3PL) || (INT11PL == 0)
#define  MINT3_11PL   ~(1 << 10)
#else
#define  MINT3_11PL   0xFFFF
#endif

#if (INT12PL >= INT3PL) || (INT12PL == 0)
#define  MINT3_12PL   ~(1 << 11)
#else
#define  MINT3_12PL   0xFFFF
#endif

#if (INT13PL >= INT3PL) || (INT13PL == 0)
#define  MINT3_13PL   ~(1 << 12)
#else
#define  MINT3_13PL   0xFFFF
#endif

#if (INT14PL >= INT3PL) || (INT14PL == 0)
#define  MINT3_14PL   ~(1 << 13)
#else
#define  MINT3_14PL   0xFFFF
#endif

#if (INT15PL >= INT3PL) || (INT15PL == 0)
#define  MINT3_15PL   ~(1 << 14)
#else
#define  MINT3_15PL   0xFFFF
#endif

#if (INT16PL >= INT3PL) || (INT16PL == 0)
#define  MINT3_16PL   ~(1 << 15)
#else
#define  MINT3_16PL   0xFFFF
#endif

#define  MINT3    (MINT3_1PL  & MINT3_2PL  & MINT3_3PL  & MINT3_4PL  & \
                   MINT3_5PL  & MINT3_6PL  & MINT3_7PL  & MINT3_8PL  & \
                   MINT3_9PL  & MINT3_10PL & MINT3_11PL & MINT3_12PL & \
                   MINT3_13PL & MINT3_14PL & MINT3_15PL & MINT3_16PL)
// End Of MINT3.

// Beginning of MINT4:
#if (INT1PL >= INT4PL) || (INT1PL == 0)
#define  MINT4_1PL    ~(1 << 0)
#else
#define  MINT4_1PL    0xFFFF
#endif

#if (INT2PL >= INT4PL) || (INT2PL == 0)
#define  MINT4_2PL   ~(1 << 1)
#else
#define  MINT4_2PL   0xFFFF
#endif

#if (INT3PL >= INT4PL) || (INT3PL == 0)
#define  MINT4_3PL   ~(1 << 2)
#else
#define  MINT4_3PL   0xFFFF
#endif

#if (INT4PL == 0)
#define  MINT4_4PL   ~(1 << 3)
#else
#define  MINT4_4PL   0xFFFF
#endif

#if (INT5PL >= INT4PL) || (INT5PL == 0)
#define  MINT4_5PL   ~(1 << 4)
#else
#define  MINT4_5PL   0xFFFF
#endif

#if (INT6PL >= INT4PL) || (INT6PL == 0)
#define  MINT4_6PL   ~(1 << 5)
#else
#define  MINT4_6PL   0xFFFF
#endif

#if (INT7PL >= INT4PL) || (INT7PL == 0)
#define  MINT4_7PL   ~(1 << 6)
#else
#define  MINT4_7PL   0xFFFF
#endif

#if (INT8PL >= INT4PL) || (INT8PL == 0)
#define  MINT4_8PL   ~(1 << 7)
#else
#define  MINT4_8PL   0xFFFF
#endif

#if (INT9PL >= INT4PL) || (INT9PL == 0)
#define  MINT4_9PL   ~(1 << 8)
#else
#define  MINT4_9PL   0xFFFF
#endif

#if (INT10PL >= INT4PL) || (INT10PL == 0)
#define  MINT4_10PL   ~(1 << 9)
#else
#define  MINT4_10PL   0xFFFF
#endif

#if (INT11PL >= INT4PL) || (INT11PL == 0)
#define  MINT4_11PL   ~(1 << 10)
#else
#define  MINT4_11PL   0xFFFF
#endif

#if (INT12PL >= INT4PL) || (INT12PL == 0)
#define  MINT4_12PL   ~(1 << 11)
#else
#define  MINT4_12PL   0xFFFF
#endif

#if (INT13PL >= INT4PL) || (INT13PL == 0)
#define  MINT4_13PL   ~(1 << 12)
#else
#define  MINT4_13PL   0xFFFF
#endif

#if (INT14PL >= INT4PL) || (INT14PL == 0)
#define  MINT4_14PL   ~(1 << 13)
#else
#define  MINT4_14PL   0xFFFF
#endif

#if (INT15PL >= INT4PL) || (INT15PL == 0)
#define  MINT4_15PL   ~(1 << 14)
#else
#define  MINT4_15PL   0xFFFF
#endif

#if (INT16PL >= INT4PL) || (INT16PL == 0)
#define  MINT4_16PL   ~(1 << 15)
#else
#define  MINT4_16PL   0xFFFF
#endif

#define  MINT4    (MINT4_1PL  & MINT4_2PL  & MINT4_3PL  & MINT4_4PL  & \
                   MINT4_5PL  & MINT4_6PL  & MINT4_7PL  & MINT4_8PL  & \
                   MINT4_9PL  & MINT4_10PL & MINT4_11PL & MINT4_12PL & \
                   MINT4_13PL & MINT4_14PL & MINT4_15PL & MINT4_16PL)
// End Of MINT4.

// Beginning of MINT5:
#if (INT1PL >= INT5PL) || (INT1PL == 0)
#define  MINT5_1PL    ~(1 << 0)
#else
#define  MINT5_1PL    0xFFFF
#endif

#if (INT2PL >= INT5PL) || (INT2PL == 0)
#define  MINT5_2PL   ~(1 << 1)
#else
#define  MINT5_2PL   0xFFFF
#endif

#if (INT3PL >= INT5PL) || (INT3PL == 0)
#define  MINT5_3PL   ~(1 << 2)
#else
#define  MINT5_3PL   0xFFFF
#endif

#if (INT4PL >= INT5PL) || (INT4PL == 0)
#define  MINT5_4PL   ~(1 << 3)
#else
#define  MINT5_4PL   0xFFFF
#endif

#if (INT5PL == 0)
#define  MINT5_5PL   ~(1 << 4)
#else
#define  MINT5_5PL   0xFFFF
#endif

#if (INT6PL >= INT5PL) || (INT6PL == 0)
#define  MINT5_6PL   ~(1 << 5)
#else
#define  MINT5_6PL   0xFFFF
#endif

#if (INT7PL >= INT5PL) || (INT7PL == 0)
#define  MINT5_7PL   ~(1 << 6)
#else
#define  MINT5_7PL   0xFFFF
#endif

#if (INT8PL >= INT5PL) || (INT8PL == 0)
#define  MINT5_8PL   ~(1 << 7)
#else
#define  MINT5_8PL   0xFFFF
#endif

#if (INT9PL >= INT5PL) || (INT9PL == 0)
#define  MINT5_9PL   ~(1 << 8)
#else
#define  MINT5_9PL   0xFFFF
#endif

#if (INT10PL >= INT5PL) || (INT10PL == 0)
#define  MINT5_10PL   ~(1 << 9)
#else
#define  MINT5_10PL   0xFFFF
#endif

#if (INT11PL >= INT5PL) || (INT11PL == 0)
#define  MINT5_11PL   ~(1 << 10)
#else
#define  MINT5_11PL   0xFFFF
#endif

#if (INT12PL >= INT5PL) || (INT12PL == 0)
#define  MINT5_12PL   ~(1 << 11)
#else
#define  MINT5_12PL   0xFFFF
#endif

#if (INT13PL >= INT5PL) || (INT13PL == 0)
#define  MINT5_13PL   ~(1 << 12)
#else
#define  MINT5_13PL   0xFFFF
#endif

#if (INT14PL >= INT5PL) || (INT14PL == 0)
#define  MINT5_14PL   ~(1 << 13)
#else
#define  MINT5_14PL   0xFFFF
#endif

#if (INT15PL >= INT5PL) || (INT15PL == 0)
#define  MINT5_15PL   ~(1 << 14)
#else
#define  MINT5_15PL   0xFFFF
#endif

#if (INT16PL >= INT5PL) || (INT16PL == 0)
#define  MINT5_16PL   ~(1 << 15)
#else
#define  MINT5_16PL   0xFFFF
#endif

#define  MINT5    (MINT5_1PL  & MINT5_2PL  & MINT5_3PL  & MINT5_4PL  & \
                   MINT5_5PL  & MINT5_6PL  & MINT5_7PL  & MINT5_8PL  & \
                   MINT5_9PL  & MINT5_10PL & MINT5_11PL & MINT5_12PL & \
                   MINT5_13PL & MINT5_14PL & MINT5_15PL & MINT5_16PL)
// End Of MINT5.

// Beginning of MINT6:
#if (INT1PL >= INT6PL) || (INT1PL == 0)
#define  MINT6_1PL    ~(1 << 0)
#else
#define  MINT6_1PL    0xFFFF
#endif

#if (INT2PL >= INT6PL) || (INT2PL == 0)
#define  MINT6_2PL   ~(1 << 1)
#else
#define  MINT6_2PL   0xFFFF
#endif

#if (INT3PL >= INT6PL) || (INT3PL == 0)
#define  MINT6_3PL   ~(1 << 2)
#else
#define  MINT6_3PL   0xFFFF
#endif

#if (INT4PL >= INT6PL) || (INT4PL == 0)
#define  MINT6_4PL   ~(1 << 3)
#else
#define  MINT6_4PL   0xFFFF
#endif

#if (INT5PL >= INT6PL) || (INT5PL == 0)
#define  MINT6_5PL   ~(1 << 4)
#else
#define  MINT6_5PL   0xFFFF
#endif

#if (INT6PL == 0)
#define  MINT6_6PL   ~(1 << 5)
#else
#define  MINT6_6PL   0xFFFF
#endif

#if (INT7PL >= INT6PL) || (INT7PL == 0)
#define  MINT6_7PL   ~(1 << 6)
#else
#define  MINT6_7PL   0xFFFF
#endif

#if (INT8PL >= INT6PL) || (INT8PL == 0)
#define  MINT6_8PL   ~(1 << 7)
#else
#define  MINT6_8PL   0xFFFF
#endif

#if (INT9PL >= INT6PL) || (INT9PL == 0)
#define  MINT6_9PL   ~(1 << 8)
#else
#define  MINT6_9PL   0xFFFF
#endif

#if (INT10PL >= INT6PL) || (INT10PL == 0)
#define  MINT6_10PL   ~(1 << 9)
#else
#define  MINT6_10PL   0xFFFF
#endif

#if (INT11PL >= INT6PL) || (INT11PL == 0)
#define  MINT6_11PL   ~(1 << 10)
#else
#define  MINT6_11PL   0xFFFF
#endif

#if (INT12PL >= INT6PL) || (INT12PL == 0)
#define  MINT6_12PL   ~(1 << 11)
#else
#define  MINT6_12PL   0xFFFF
#endif

#if (INT13PL >= INT6PL) || (INT13PL == 0)
#define  MINT6_13PL   ~(1 << 12)
#else
#define  MINT6_13PL   0xFFFF
#endif

#if (INT14PL >= INT6PL) || (INT14PL == 0)
#define  MINT6_14PL   ~(1 << 13)
#else
#define  MINT6_14PL   0xFFFF
#endif

#if (INT15PL >= INT6PL) || (INT15PL == 0)
#define  MINT6_15PL   ~(1 << 14)
#else
#define  MINT6_15PL   0xFFFF
#endif

#if (INT16PL >= INT6PL) || (INT16PL == 0)
#define  MINT6_16PL   ~(1 << 15)
#else
#define  MINT6_16PL   0xFFFF
#endif

#define  MINT6    (MINT6_1PL  & MINT6_2PL  & MINT6_3PL  & MINT6_4PL  & \
                   MINT6_5PL  & MINT6_6PL  & MINT6_7PL  & MINT6_8PL  & \
                   MINT6_9PL  & MINT6_10PL & MINT6_11PL & MINT6_12PL & \
                   MINT6_13PL & MINT6_14PL & MINT6_15PL & MINT6_16PL)
// End Of MINT6.

// Beginning of MINT7:
#if (INT1PL >= INT7PL) || (INT1PL == 0)
#define  MINT7_1PL    ~(1 << 0)
#else
#define  MINT7_1PL    0xFFFF
#endif

#if (INT2PL >= INT7PL) || (INT2PL == 0)
#define  MINT7_2PL   ~(1 << 1)
#else
#define  MINT7_2PL   0xFFFF
#endif

#if (INT3PL >= INT7PL) || (INT3PL == 0)
#define  MINT7_3PL   ~(1 << 2)
#else
#define  MINT7_3PL   0xFFFF
#endif

#if (INT4PL >= INT7PL) || (INT4PL == 0)
#define  MINT7_4PL   ~(1 << 3)
#else
#define  MINT7_4PL   0xFFFF
#endif

#if (INT5PL >= INT7PL) || (INT5PL == 0)
#define  MINT7_5PL   ~(1 << 4)
#else
#define  MINT7_5PL   0xFFFF
#endif

#if (INT6PL >= INT7PL) || (INT6PL == 0)
#define  MINT7_6PL   ~(1 << 5)
#else
#define  MINT7_6PL   0xFFFF
#endif

#if (INT7PL == 0)
#define  MINT7_7PL   ~(1 << 6)
#else
#define  MINT7_7PL   0xFFFF
#endif

#if (INT8PL >= INT7PL) || (INT8PL == 0)
#define  MINT7_8PL   ~(1 << 7)
#else
#define  MINT7_8PL   0xFFFF
#endif

#if (INT9PL >= INT7PL) || (INT9PL == 0)
#define  MINT7_9PL   ~(1 << 8)
#else
#define  MINT7_9PL   0xFFFF
#endif

#if (INT10PL >= INT7PL) || (INT10PL == 0)
#define  MINT7_10PL   ~(1 << 9)
#else
#define  MINT7_10PL   0xFFFF
#endif

#if (INT11PL >= INT7PL) || (INT11PL == 0)
#define  MINT7_11PL   ~(1 << 10)
#else
#define  MINT7_11PL   0xFFFF
#endif

#if (INT12PL >= INT7PL) || (INT12PL == 0)
#define  MINT7_12PL   ~(1 << 11)
#else
#define  MINT7_12PL   0xFFFF
#endif

#if (INT13PL >= INT7PL) || (INT13PL == 0)
#define  MINT7_13PL   ~(1 << 12)
#else
#define  MINT7_13PL   0xFFFF
#endif

#if (INT14PL >= INT7PL) || (INT14PL == 0)
#define  MINT7_14PL   ~(1 << 13)
#else
#define  MINT7_14PL   0xFFFF
#endif

#if (INT15PL >= INT7PL) || (INT15PL == 0)
#define  MINT7_15PL   ~(1 << 14)
#else
#define  MINT7_15PL   0xFFFF
#endif

#if (INT16PL >= INT7PL) || (INT16PL == 0)
#define  MINT7_16PL   ~(1 << 15)
#else
#define  MINT7_16PL   0xFFFF
#endif

#define  MINT7    (MINT7_1PL  & MINT7_2PL  & MINT7_3PL  & MINT7_4PL  & \
                   MINT7_5PL  & MINT7_6PL  & MINT7_7PL  & MINT7_8PL  & \
                   MINT7_9PL  & MINT7_10PL & MINT7_11PL & MINT7_12PL & \
                   MINT7_13PL & MINT7_14PL & MINT7_15PL & MINT7_16PL)
// End Of MINT7.

// Beginning of MINT8:
#if (INT1PL >= INT8PL) || (INT1PL == 0)
#define  MINT8_1PL    ~(1 << 0)
#else
#define  MINT8_1PL    0xFFFF
#endif

#if (INT2PL >= INT8PL) || (INT2PL == 0)
#define  MINT8_2PL   ~(1 << 1)
#else
#define  MINT8_2PL   0xFFFF
#endif

#if (INT3PL >= INT8PL) || (INT3PL == 0)
#define  MINT8_3PL   ~(1 << 2)
#else
#define  MINT8_3PL   0xFFFF
#endif

#if (INT4PL >= INT8PL) || (INT4PL == 0)
#define  MINT8_4PL   ~(1 << 3)
#else
#define  MINT8_4PL   0xFFFF
#endif

#if (INT5PL >= INT8PL) || (INT5PL == 0)
#define  MINT8_5PL   ~(1 << 4)
#else
#define  MINT8_5PL   0xFFFF
#endif

#if (INT6PL >= INT8PL) || (INT6PL == 0)
#define  MINT8_6PL   ~(1 << 5)
#else
#define  MINT8_6PL   0xFFFF
#endif

#if (INT7PL >= INT8PL) || (INT7PL == 0)
#define  MINT8_7PL   ~(1 << 6)
#else
#define  MINT8_7PL   0xFFFF
#endif

#if (INT8PL == 0)
#define  MINT8_8PL   ~(1 << 7)
#else
#define  MINT8_8PL   0xFFFF
#endif

#if (INT9PL >= INT8PL) || (INT9PL == 0)
#define  MINT8_9PL   ~(1 << 8)
#else
#define  MINT8_9PL   0xFFFF
#endif

#if (INT10PL >= INT8PL) || (INT10PL == 0)
#define  MINT8_10PL   ~(1 << 9)
#else
#define  MINT8_10PL   0xFFFF
#endif

#if (INT11PL >= INT8PL) || (INT11PL == 0)
#define  MINT8_11PL   ~(1 << 10)
#else
#define  MINT8_11PL   0xFFFF
#endif

#if (INT12PL >= INT8PL) || (INT12PL == 0)
#define  MINT8_12PL   ~(1 << 11)
#else
#define  MINT8_12PL   0xFFFF
#endif

#if (INT13PL >= INT8PL) || (INT13PL == 0)
#define  MINT8_13PL   ~(1 << 12)
#else
#define  MINT8_13PL   0xFFFF
#endif

#if (INT14PL >= INT8PL) || (INT14PL == 0)
#define  MINT8_14PL   ~(1 << 13)
#else
#define  MINT8_14PL   0xFFFF
#endif

#if (INT15PL >= INT8PL) || (INT15PL == 0)
#define  MINT8_15PL   ~(1 << 14)
#else
#define  MINT8_15PL   0xFFFF
#endif

#if (INT16PL >= INT8PL) || (INT16PL == 0)
#define  MINT8_16PL   ~(1 << 15)
#else
#define  MINT8_16PL   0xFFFF
#endif

#define  MINT8    (MINT8_1PL  & MINT8_2PL  & MINT8_3PL  & MINT8_4PL  & \
                   MINT8_5PL  & MINT8_6PL  & MINT8_7PL  & MINT8_8PL  & \
                   MINT8_9PL  & MINT8_10PL & MINT8_11PL & MINT8_12PL & \
                   MINT8_13PL & MINT8_14PL & MINT8_15PL & MINT8_16PL)
// End Of MINT8.

// Beginning of MINT9:
#if (INT1PL >= INT9PL) || (INT1PL == 0)
#define  MINT9_1PL    ~(1 << 0)
#else
#define  MINT9_1PL    0xFFFF
#endif

#if (INT2PL >= INT9PL) || (INT2PL == 0)
#define  MINT9_2PL   ~(1 << 1)
#else
#define  MINT9_2PL   0xFFFF
#endif

#if (INT3PL >= INT9PL) || (INT3PL == 0)
#define  MINT9_3PL   ~(1 << 2)
#else
#define  MINT9_3PL   0xFFFF
#endif

#if (INT4PL >= INT9PL) || (INT4PL == 0)
#define  MINT9_4PL   ~(1 << 3)
#else
#define  MINT9_4PL   0xFFFF
#endif

#if (INT5PL >= INT9PL) || (INT5PL == 0)
#define  MINT9_5PL   ~(1 << 4)
#else
#define  MINT9_5PL   0xFFFF
#endif

#if (INT6PL >= INT9PL) || (INT6PL == 0)
#define  MINT9_6PL   ~(1 << 5)
#else
#define  MINT9_6PL   0xFFFF
#endif

#if (INT7PL >= INT9PL) || (INT7PL == 0)
#define  MINT9_7PL   ~(1 << 6)
#else
#define  MINT9_7PL   0xFFFF
#endif

#if (INT8PL >= INT9PL) || (INT8PL == 0)
#define  MINT9_8PL   ~(1 << 7)
#else
#define  MINT9_8PL   0xFFFF
#endif

#if (INT9PL == 0)
#define  MINT9_9PL   ~(1 << 8)
#else
#define  MINT9_9PL   0xFFFF
#endif

#if (INT10PL >= INT9PL) || (INT10PL == 0)
#define  MINT9_10PL   ~(1 << 9)
#else
#define  MINT9_10PL   0xFFFF
#endif

#if (INT11PL >= INT9PL) || (INT11PL == 0)
#define  MINT9_11PL   ~(1 << 10)
#else
#define  MINT9_11PL   0xFFFF
#endif

#if (INT12PL >= INT9PL) || (INT12PL == 0)
#define  MINT9_12PL   ~(1 << 11)
#else
#define  MINT9_12PL   0xFFFF
#endif

#if (INT13PL >= INT9PL) || (INT13PL == 0)
#define  MINT9_13PL   ~(1 << 12)
#else
#define  MINT9_13PL   0xFFFF
#endif

#if (INT14PL >= INT9PL) || (INT14PL == 0)
#define  MINT9_14PL   ~(1 << 13)
#else
#define  MINT9_14PL   0xFFFF
#endif

#if (INT15PL >= INT9PL) || (INT15PL == 0)
#define  MINT9_15PL   ~(1 << 14)
#else
#define  MINT9_15PL   0xFFFF
#endif

#if (INT16PL >= INT9PL) || (INT16PL == 0)
#define  MINT9_16PL   ~(1 << 15)
#else
#define  MINT9_16PL   0xFFFF
#endif

#define  MINT9    (MINT9_1PL  & MINT9_2PL  & MINT9_3PL  & MINT9_4PL  & \
                   MINT9_5PL  & MINT9_6PL  & MINT9_7PL  & MINT9_8PL  & \
                   MINT9_9PL  & MINT9_10PL & MINT9_11PL & MINT9_12PL & \
                   MINT9_13PL & MINT9_14PL & MINT9_15PL & MINT9_16PL)
// End Of MINT9.

// Beginning of MINT10:
#if (INT1PL >= INT10PL) || (INT1PL == 0)
#define  MINT10_1PL    ~(1 << 0)
#else
#define  MINT10_1PL    0xFFFF
#endif

#if (INT2PL >= INT10PL) || (INT2PL == 0)
#define  MINT10_2PL   ~(1 << 1)
#else
#define  MINT10_2PL   0xFFFF
#endif

#if (INT3PL >= INT10PL) || (INT3PL == 0)
#define  MINT10_3PL   ~(1 << 2)
#else
#define  MINT10_3PL   0xFFFF
#endif

#if (INT4PL >= INT10PL) || (INT4PL == 0)
#define  MINT10_4PL   ~(1 << 3)
#else
#define  MINT10_4PL   0xFFFF
#endif

#if (INT5PL >= INT10PL) || (INT5PL == 0)
#define  MINT10_5PL   ~(1 << 4)
#else
#define  MINT10_5PL   0xFFFF
#endif

#if (INT6PL >= INT10PL) || (INT6PL == 0)
#define  MINT10_6PL   ~(1 << 5)
#else
#define  MINT10_6PL   0xFFFF
#endif

#if (INT7PL >= INT10PL) || (INT7PL == 0)
#define  MINT10_7PL   ~(1 << 6)
#else
#define  MINT10_7PL   0xFFFF
#endif

#if (INT8PL >= INT10PL) || (INT8PL == 0)
#define  MINT10_8PL   ~(1 << 7)
#else
#define  MINT10_8PL   0xFFFF
#endif

#if (INT9PL >= INT10PL) || (INT9PL == 0)
#define  MINT10_9PL   ~(1 << 8)
#else
#define  MINT10_9PL   0xFFFF
#endif

#if (INT10PL == 0)
#define  MINT10_10PL   ~(1 << 9)
#else
#define  MINT10_10PL   0xFFFF
#endif

#if (INT11PL >= INT10PL) || (INT11PL == 0)
#define  MINT10_11PL   ~(1 << 10)
#else
#define  MINT10_11PL   0xFFFF
#endif

#if (INT12PL >= INT10PL) || (INT12PL == 0)
#define  MINT10_12PL   ~(1 << 11)
#else
#define  MINT10_12PL   0xFFFF
#endif

#if (INT13PL >= INT10PL) || (INT13PL == 0)
#define  MINT10_13PL   ~(1 << 12)
#else
#define  MINT10_13PL   0xFFFF
#endif

#if (INT14PL >= INT10PL) || (INT14PL == 0)
#define  MINT10_14PL   ~(1 << 13)
#else
#define  MINT10_14PL   0xFFFF
#endif

#if (INT15PL >= INT10PL) || (INT15PL == 0)
#define  MINT10_15PL   ~(1 << 14)
#else
#define  MINT10_15PL   0xFFFF
#endif

#if (INT16PL >= INT10PL) || (INT16PL == 0)
#define  MINT10_16PL   ~(1 << 15)
#else
#define  MINT10_16PL   0xFFFF
#endif

#define  MINT10   (MINT10_1PL  & MINT10_2PL  & MINT10_3PL  & MINT10_4PL  & \
                   MINT10_5PL  & MINT10_6PL  & MINT10_7PL  & MINT10_8PL  & \
                   MINT10_9PL  & MINT10_10PL & MINT10_11PL & MINT10_12PL & \
                   MINT10_13PL & MINT10_14PL & MINT10_15PL & MINT10_16PL)
// End Of MINT10.

// Beginning of MINT11:
#if (INT1PL >= INT11PL) || (INT1PL == 0)
#define  MINT11_1PL    ~(1 << 0)
#else
#define  MINT11_1PL    0xFFFF
#endif

#if (INT2PL >= INT11PL) || (INT2PL == 0)
#define  MINT11_2PL   ~(1 << 1)
#else
#define  MINT11_2PL   0xFFFF
#endif

#if (INT3PL >= INT11PL) || (INT3PL == 0)
#define  MINT11_3PL   ~(1 << 2)
#else
#define  MINT11_3PL   0xFFFF
#endif

#if (INT4PL >= INT11PL) || (INT4PL == 0)
#define  MINT11_4PL   ~(1 << 3)
#else
#define  MINT11_4PL   0xFFFF
#endif

#if (INT5PL >= INT11PL) || (INT5PL == 0)
#define  MINT11_5PL   ~(1 << 4)
#else
#define  MINT11_5PL   0xFFFF
#endif

#if (INT6PL >= INT11PL) || (INT6PL == 0)
#define  MINT11_6PL   ~(1 << 5)
#else
#define  MINT11_6PL   0xFFFF
#endif

#if (INT7PL >= INT11PL) || (INT7PL == 0)
#define  MINT11_7PL   ~(1 << 6)
#else
#define  MINT11_7PL   0xFFFF
#endif

#if (INT8PL >= INT11PL) || (INT8PL == 0)
#define  MINT11_8PL   ~(1 << 7)
#else
#define  MINT11_8PL   0xFFFF
#endif

#if (INT9PL >= INT11PL) || (INT9PL == 0)
#define  MINT11_9PL   ~(1 << 8)
#else
#define  MINT11_9PL   0xFFFF
#endif

#if (INT10PL >= INT11PL) || (INT10PL == 0)
#define  MINT11_10PL   ~(1 << 9)
#else
#define  MINT11_10PL   0xFFFF
#endif

#if (INT11PL == 0)
#define  MINT11_11PL   ~(1 << 10)
#else
#define  MINT11_11PL   0xFFFF
#endif

#if (INT12PL >= INT11PL) || (INT12PL == 0)
#define  MINT11_12PL   ~(1 << 11)
#else
#define  MINT11_12PL   0xFFFF
#endif

#if (INT13PL >= INT11PL) || (INT13PL == 0)
#define  MINT11_13PL   ~(1 << 12)
#else
#define  MINT11_13PL   0xFFFF
#endif

#if (INT14PL >= INT11PL) || (INT14PL == 0)
#define  MINT11_14PL   ~(1 << 13)
#else
#define  MINT11_14PL   0xFFFF
#endif

#if (INT15PL >= INT11PL) || (INT15PL == 0)
#define  MINT11_15PL   ~(1 << 14)
#else
#define  MINT11_15PL   0xFFFF
#endif

#if (INT16PL >= INT11PL) || (INT16PL == 0)
#define  MINT11_16PL   ~(1 << 15)
#else
#define  MINT11_16PL   0xFFFF
#endif

#define  MINT11   (MINT11_1PL  & MINT11_2PL  & MINT11_3PL  & MINT11_4PL  & \
                   MINT11_5PL  & MINT11_6PL  & MINT11_7PL  & MINT11_8PL  & \
                   MINT11_9PL  & MINT11_10PL & MINT11_11PL & MINT11_12PL & \
                   MINT11_13PL & MINT11_14PL & MINT11_15PL & MINT11_16PL)
// End Of MINT11.

// Beginning of MINT12:
#if (INT1PL >= INT12PL) || (INT1PL == 0)
#define  MINT12_1PL    ~(1 << 0)
#else
#define  MINT12_1PL    0xFFFF
#endif

#if (INT2PL >= INT12PL) || (INT2PL == 0)
#define  MINT12_2PL   ~(1 << 1)
#else
#define  MINT12_2PL   0xFFFF
#endif

#if (INT3PL >= INT12PL) || (INT3PL == 0)
#define  MINT12_3PL   ~(1 << 2)
#else
#define  MINT12_3PL   0xFFFF
#endif

#if (INT4PL >= INT12PL) || (INT4PL == 0)
#define  MINT12_4PL   ~(1 << 3)
#else
#define  MINT12_4PL   0xFFFF
#endif

#if (INT5PL >= INT12PL) || (INT5PL == 0)
#define  MINT12_5PL   ~(1 << 4)
#else
#define  MINT12_5PL   0xFFFF
#endif

#if (INT6PL >= INT12PL) || (INT6PL == 0)
#define  MINT12_6PL   ~(1 << 5)
#else
#define  MINT12_6PL   0xFFFF
#endif

#if (INT7PL >= INT12PL) || (INT7PL == 0)
#define  MINT12_7PL   ~(1 << 6)
#else
#define  MINT12_7PL   0xFFFF
#endif

#if (INT8PL >= INT12PL) || (INT8PL == 0)
#define  MINT12_8PL   ~(1 << 7)
#else
#define  MINT12_8PL   0xFFFF
#endif

#if (INT9PL >= INT12PL) || (INT9PL == 0)
#define  MINT12_9PL   ~(1 << 8)
#else
#define  MINT12_9PL   0xFFFF
#endif

#if (INT10PL >= INT12PL) || (INT10PL == 0)
#define  MINT12_10PL   ~(1 << 9)
#else
#define  MINT12_10PL   0xFFFF
#endif

#if (INT11PL >= INT12PL) || (INT11PL == 0)
#define  MINT12_11PL   ~(1 << 10)
#else
#define  MINT12_11PL   0xFFFF
#endif

#if (INT12PL == 0)
#define  MINT12_12PL   ~(1 << 11)
#else
#define  MINT12_12PL   0xFFFF
#endif

#if (INT13PL >= INT12PL) || (INT13PL == 0)
#define  MINT12_13PL   ~(1 << 12)
#else
#define  MINT12_13PL   0xFFFF
#endif

#if (INT14PL >= INT12PL) || (INT14PL == 0)
#define  MINT12_14PL   ~(1 << 13)
#else
#define  MINT12_14PL   0xFFFF
#endif

#if (INT15PL >= INT12PL) || (INT15PL == 0)
#define  MINT12_15PL   ~(1 << 14)
#else
#define  MINT12_15PL   0xFFFF
#endif

#if (INT16PL >= INT12PL) || (INT16PL == 0)
#define  MINT12_16PL   ~(1 << 15)
#else
#define  MINT12_16PL   0xFFFF
#endif

#define  MINT12   (MINT12_1PL  & MINT12_2PL  & MINT12_3PL  & MINT12_4PL  & \
                   MINT12_5PL  & MINT12_6PL  & MINT12_7PL  & MINT12_8PL  & \
                   MINT12_9PL  & MINT12_10PL & MINT12_11PL & MINT12_12PL & \
                   MINT12_13PL & MINT12_14PL & MINT12_15PL & MINT12_16PL)
// End Of MINT12.

// Beginning of MINT13:
#if (INT1PL >= INT13PL) || (INT1PL == 0)
#define  MINT13_1PL    ~(1 << 0)
#else
#define  MINT13_1PL    0xFFFF
#endif

#if (INT2PL >= INT13PL) || (INT2PL == 0)
#define  MINT13_2PL   ~(1 << 1)
#else
#define  MINT13_2PL   0xFFFF
#endif

#if (INT3PL >= INT13PL) || (INT3PL == 0)
#define  MINT13_3PL   ~(1 << 2)
#else
#define  MINT13_3PL   0xFFFF
#endif

#if (INT4PL >= INT13PL) || (INT4PL == 0)
#define  MINT13_4PL   ~(1 << 3)
#else
#define  MINT13_4PL   0xFFFF
#endif

#if (INT5PL >= INT13PL) || (INT5PL == 0)
#define  MINT13_5PL   ~(1 << 4)
#else
#define  MINT13_5PL   0xFFFF
#endif

#if (INT6PL >= INT13PL) || (INT6PL == 0)
#define  MINT13_6PL   ~(1 << 5)
#else
#define  MINT13_6PL   0xFFFF
#endif

#if (INT7PL >= INT13PL) || (INT7PL == 0)
#define  MINT13_7PL   ~(1 << 6)
#else
#define  MINT13_7PL   0xFFFF
#endif

#if (INT8PL >= INT13PL) || (INT8PL == 0)
#define  MINT13_8PL   ~(1 << 7)
#else
#define  MINT13_8PL   0xFFFF
#endif

#if (INT9PL >= INT13PL) || (INT9PL == 0)
#define  MINT13_9PL   ~(1 << 8)
#else
#define  MINT13_9PL   0xFFFF
#endif

#if (INT10PL >= INT13PL) || (INT10PL == 0)
#define  MINT13_10PL   ~(1 << 9)
#else
#define  MINT13_10PL   0xFFFF
#endif

#if (INT11PL >= INT13PL) || (INT11PL == 0)
#define  MINT13_11PL   ~(1 << 10)
#else
#define  MINT13_11PL   0xFFFF
#endif

#define  MINT13_12PL   ~(1 << 11)

#if (INT13PL == 0)
#define  MINT13_13PL   ~(1 << 12)
#else
#define  MINT13_13PL   0xFFFF
#endif

#if (INT14PL >= INT13PL) || (INT14PL == 0)
#define  MINT13_14PL   ~(1 << 13)
#else
#define  MINT13_14PL   0xFFFF
#endif

#if (INT15PL >= INT13PL) || (INT15PL == 0)
#define  MINT13_15PL   ~(1 << 14)
#else
#define  MINT13_15PL   0xFFFF
#endif

#if (INT16PL >= INT13PL) || (INT16PL == 0)
#define  MINT13_16PL   ~(1 << 15)
#else
#define  MINT13_16PL   0xFFFF
#endif

#define  MINT13   (MINT13_1PL  & MINT13_2PL  & MINT13_3PL  & MINT13_4PL  & \
                   MINT13_5PL  & MINT13_6PL  & MINT13_7PL  & MINT13_8PL  & \
                   MINT13_9PL  & MINT13_10PL & MINT13_11PL & MINT13_12PL & \
                   MINT13_13PL & MINT13_14PL & MINT13_15PL & MINT13_16PL)
// End Of MINT13.

// Beginning of MINT14:
#if (INT1PL >= INT14PL) || (INT1PL == 0)
#define  MINT14_1PL    ~(1 << 0)
#else
#define  MINT14_1PL    0xFFFF
#endif

#if (INT2PL >= INT14PL) || (INT2PL == 0)
#define  MINT14_2PL   ~(1 << 1)
#else
#define  MINT14_2PL   0xFFFF
#endif

#if (INT3PL >= INT14PL) || (INT3PL == 0)
#define  MINT14_3PL   ~(1 << 2)
#else
#define  MINT14_3PL   0xFFFF
#endif

#if (INT4PL >= INT14PL) || (INT4PL == 0)
#define  MINT14_4PL   ~(1 << 3)
#else
#define  MINT14_4PL   0xFFFF
#endif

#if (INT5PL >= INT14PL) || (INT5PL == 0)
#define  MINT14_5PL   ~(1 << 4)
#else
#define  MINT14_5PL   0xFFFF
#endif

#if (INT6PL >= INT14PL) || (INT6PL == 0)
#define  MINT14_6PL   ~(1 << 5)
#else
#define  MINT14_6PL   0xFFFF
#endif

#if (INT7PL >= INT14PL) || (INT7PL == 0)
#define  MINT14_7PL   ~(1 << 6)
#else
#define  MINT14_7PL   0xFFFF
#endif

#if (INT8PL >= INT14PL) || (INT8PL == 0)
#define  MINT14_8PL   ~(1 << 7)
#else
#define  MINT14_8PL   0xFFFF
#endif

#if (INT9PL >= INT14PL) || (INT9PL == 0)
#define  MINT14_9PL   ~(1 << 8)
#else
#define  MINT14_9PL   0xFFFF
#endif

#if (INT10PL >= INT14PL) || (INT10PL == 0)
#define  MINT14_10PL   ~(1 << 9)
#else
#define  MINT14_10PL   0xFFFF
#endif

#if (INT11PL >= INT14PL) || (INT11PL == 0)
#define  MINT14_11PL   ~(1 << 10)
#else
#define  MINT14_11PL   0xFFFF
#endif

#if (INT12PL >= INT14PL) || (INT12PL == 0)
#define  MINT14_12PL   ~(1 << 11)
#else
#define  MINT14_12PL   0xFFFF
#endif

#if (INT13PL >= INT14PL) || (INT13PL == 0)
#define  MINT14_13PL   ~(1 << 12)
#else
#define  MINT14_13PL   0xFFFF
#endif

#define  MINT14_14PL   ~(1 << 13)

#if (INT15PL >= INT14PL) || (INT15PL == 0)
#define  MINT14_15PL   ~(1 << 14)
#else
#define  MINT14_15PL   0xFFFF
#endif

#if (INT16PL >= INT14PL) || (INT16PL == 0)
#define  MINT14_16PL   ~(1 << 15)
#else
#define  MINT14_16PL   0xFFFF
#endif

#define  MINT14   (MINT14_1PL  & MINT14_2PL  & MINT14_3PL  & MINT14_4PL  & \
                   MINT14_5PL  & MINT14_6PL  & MINT14_7PL  & MINT14_8PL  & \
                   MINT14_9PL  & MINT14_10PL & MINT14_11PL & MINT14_12PL & \
                   MINT14_13PL & MINT14_14PL & MINT14_15PL & MINT14_16PL)
// End Of MINT14.

// Beginning of MINT15:
#if (INT1PL >= INT15PL) || (INT1PL == 0)
#define  MINT15_1PL    ~(1 << 0)
#else
#define  MINT15_1PL    0xFFFF
#endif

#if (INT2PL >= INT15PL) || (INT2PL == 0)
#define  MINT15_2PL   ~(1 << 1)
#else
#define  MINT15_2PL   0xFFFF
#endif

#if (INT3PL >= INT15PL) || (INT3PL == 0)
#define  MINT15_3PL   ~(1 << 2)
#else
#define  MINT15_3PL   0xFFFF
#endif

#if (INT4PL >= INT15PL) || (INT4PL == 0)
#define  MINT15_4PL   ~(1 << 3)
#else
#define  MINT15_4PL   0xFFFF
#endif

#if (INT5PL >= INT15PL) || (INT5PL == 0)
#define  MINT15_5PL   ~(1 << 4)
#else
#define  MINT15_5PL   0xFFFF
#endif

#if (INT6PL >= INT15PL) || (INT6PL == 0)
#define  MINT15_6PL   ~(1 << 5)
#else
#define  MINT15_6PL   0xFFFF
#endif

#if (INT7PL >= INT15PL) || (INT7PL == 0)
#define  MINT15_7PL   ~(1 << 6)
#else
#define  MINT15_7PL   0xFFFF
#endif

#if (INT8PL >= INT15PL) || (INT8PL == 0)
#define  MINT15_8PL   ~(1 << 7)
#else
#define  MINT15_8PL   0xFFFF
#endif

#if (INT9PL >= INT15PL) || (INT9PL == 0)
#define  MINT15_9PL   ~(1 << 8)
#else
#define  MINT15_9PL   0xFFFF
#endif

#if (INT10PL >= INT15PL) || (INT10PL == 0)
#define  MINT15_10PL   ~(1 << 9)
#else
#define  MINT15_10PL   0xFFFF
#endif

#if (INT11PL >= INT15PL) || (INT11PL == 0)
#define  MINT15_11PL   ~(1 << 10)
#else
#define  MINT15_11PL   0xFFFF
#endif

#if (INT12PL >= INT15PL) || (INT12PL == 0)
#define  MINT15_12PL   ~(1 << 11)
#else
#define  MINT15_12PL   0xFFFF
#endif

#if (INT13PL >= INT15PL) || (INT13PL == 0)
#define  MINT15_13PL   ~(1 << 12)
#else
#define  MINT15_13PL   0xFFFF
#endif

#if (INT14PL >= INT15PL) || (INT14PL == 0)
#define  MINT15_14PL   ~(1 << 13)
#else
#define  MINT15_14PL   0xFFFF
#endif

#define  MINT15_15PL   ~(1 << 14)

#if (INT16PL >= INT15PL) || (INT16PL == 0)
#define  MINT15_16PL   ~(1 << 15)
#else
#define  MINT15_16PL   0xFFFF
#endif

#define  MINT15   (MINT15_1PL  & MINT15_2PL  & MINT15_3PL  & MINT15_4PL  & \
                   MINT15_5PL  & MINT15_6PL  & MINT15_7PL  & MINT15_8PL  & \
                   MINT15_9PL  & MINT15_10PL & MINT15_11PL & MINT15_12PL & \
                   MINT15_13PL & MINT15_14PL & MINT15_15PL & MINT15_16PL)
// End Of MINT15.

// Beginning of MINT16:
#if (INT1PL >= INT16PL) || (INT1PL == 0)
#define  MINT16_1PL    ~(1 << 0)
#else
#define  MINT16_1PL    0xFFFF
#endif

#if (INT2PL >= INT16PL) || (INT2PL == 0)
#define  MINT16_2PL   ~(1 << 1)
#else
#define  MINT16_2PL   0xFFFF
#endif

#if (INT3PL >= INT16PL) || (INT3PL == 0)
#define  MINT16_3PL   ~(1 << 2)
#else
#define  MINT16_3PL   0xFFFF
#endif

#if (INT4PL >= INT16PL) || (INT4PL == 0)
#define  MINT16_4PL   ~(1 << 3)
#else
#define  MINT16_4PL   0xFFFF
#endif

#if (INT5PL >= INT16PL) || (INT5PL == 0)
#define  MINT16_5PL   ~(1 << 4)
#else
#define  MINT16_5PL   0xFFFF
#endif

#if (INT6PL >= INT16PL) || (INT6PL == 0)
#define  MINT16_6PL   ~(1 << 5)
#else
#define  MINT16_6PL   0xFFFF
#endif

#if (INT7PL >= INT16PL) || (INT7PL == 0)
#define  MINT16_7PL   ~(1 << 6)
#else
#define  MINT16_7PL   0xFFFF
#endif

#if (INT8PL >= INT16PL) || (INT8PL == 0)
#define  MINT16_8PL   ~(1 << 7)
#else
#define  MINT16_8PL   0xFFFF
#endif

#if (INT9PL >= INT16PL) || (INT9PL == 0)
#define  MINT16_9PL   ~(1 << 8)
#else
#define  MINT16_9PL   0xFFFF
#endif

#if (INT10PL >= INT16PL) || (INT10PL == 0)
#define  MINT16_10PL   ~(1 << 9)
#else
#define  MINT16_10PL   0xFFFF
#endif

#if (INT11PL >= INT16PL) || (INT11PL == 0)
#define  MINT16_11PL   ~(1 << 10)
#else
#define  MINT16_11PL   0xFFFF
#endif

#if (INT12PL >= INT16PL) || (INT12PL == 0)
#define  MINT16_12PL   ~(1 << 11)
#else
#define  MINT16_12PL   0xFFFF
#endif

#if (INT13PL >= INT16PL) || (INT13PL == 0)
#define  MINT16_13PL   ~(1 << 12)
#else
#define  MINT16_13PL   0xFFFF
#endif

#if (INT14PL >= INT16PL) || (INT14PL == 0)
#define  MINT16_14PL   ~(1 << 13)
#else
#define  MINT16_14PL   0xFFFF
#endif

#if (INT15PL >= INT16PL) || (INT15PL == 0)
#define  MINT16_15PL   ~(1 << 14)
#else
#define  MINT16_15PL   0xFFFF
#endif

#define  MINT16_16PL   ~(1 << 15)

#define  MINT16   (MINT16_1PL  & MINT16_2PL  & MINT16_3PL  & MINT16_4PL  & \
                   MINT16_5PL  & MINT16_6PL  & MINT16_7PL  & MINT16_8PL  & \
                   MINT16_9PL  & MINT16_10PL & MINT16_11PL & MINT16_12PL & \
                   MINT16_13PL & MINT16_14PL & MINT16_15PL & MINT16_16PL)
// End Of MINT16.

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG11 to MG18:

// Beginning of MG11:
#if (G12PL >= G11PL) || (G12PL == 0)
#define  MG11_12PL   ~(1 << 1)
#else
#define  MG11_12PL   0xFFFF
#endif

#if (G13PL >= G11PL) || (G13PL == 0)
#define  MG11_13PL   ~(1 << 2)
#else
#define  MG11_13PL   0xFFFF
#endif

#if (G14PL >= G11PL) || (G14PL == 0)
#define  MG11_14PL   ~(1 << 3)
#else
#define  MG11_14PL   0xFFFF
#endif

#if (G15PL >= G11PL) || (G15PL == 0)
#define  MG11_15PL   ~(1 << 4)
#else
#define  MG11_15PL   0xFFFF
#endif

#if (G16PL >= G11PL) || (G16PL == 0)
#define  MG11_16PL   ~(1 << 5)
#else
#define  MG11_16PL   0xFFFF
#endif

#if (G17PL >= G11PL) || (G17PL == 0)
#define  MG11_17PL   ~(1 << 6)
#else
#define  MG11_17PL   0xFFFF
#endif

#if (G18PL >= G11PL) || (G18PL == 0)
#define  MG11_18PL   ~(1 << 7)
#else
#define  MG11_18PL   0xFFFF
#endif

#define  MG11_11PL   0x00FE
#define  MG11    (MG11_11PL & MG11_12PL & MG11_13PL & MG11_14PL & \
                  MG11_15PL & MG11_16PL & MG11_17PL & MG11_18PL)
// End of MG11:

// Beginning of MG12:
#if (G11PL >= G12PL) || (G11PL == 0)
#define  MG12_11PL   ~(1)
#else
#define  MG12_11PL   0xFFFF
#endif
#if (G13PL >= G12PL) || (G13PL == 0)
#define  MG12_13PL   ~(1 << 2)
#else
#define  MG12_13PL   0xFFFF
#endif
#if (G14PL >= G12PL) || (G14PL == 0)
#define  MG12_14PL   ~(1 << 3)
#else
#define  MG12_14PL   0xFFFF
#endif
#if (G15PL >= G12PL) || (G15PL == 0)
#define  MG12_15PL   ~(1 << 4)
#else
#define  MG12_15PL   0xFFFF
#endif
#if (G16PL >= G12PL) || (G16PL == 0)
#define  MG12_16PL   ~(1 << 5)
#else
#define  MG12_16PL   0xFFFF
#endif
#if (G17PL >= G12PL) || (G17PL == 0)
#define  MG12_17PL   ~(1 << 6)
#else
#define  MG12_17PL   0xFFFF
#endif
#if (G18PL >= G12PL) || (G18PL == 0)
#define  MG12_18PL   ~(1 << 7)
#else
#define  MG12_18PL   0xFFFF
#endif
#define  MG12_12PL   0x00FD
#define  MG12    (MG12_11PL & MG12_12PL & MG12_13PL & MG12_14PL & \
                  MG12_15PL & MG12_16PL & MG12_17PL & MG12_18PL)
// End of MG12:

// Beginning of MG13:
#if (G11PL >= G13PL) || (G11PL == 0)
#define  MG13_11PL   ~(1)
#else
#define  MG13_11PL   0xFFFF
#endif
#if (G12PL >= G13PL) || (G12PL == 0)
#define  MG13_12PL   ~(1 << 1)
#else
#define  MG13_12PL   0xFFFF
#endif
#if (G14PL >= G13PL) || (G14PL == 0)
#define  MG13_14PL   ~(1 << 3)
#else
#define  MG13_14PL   0xFFFF
#endif
#if (G15PL >= G13PL) || (G15PL == 0)
#define  MG13_15PL   ~(1 << 4)
#else
#define  MG13_15PL   0xFFFF
#endif
#if (G16PL >= G13PL) || (G16PL == 0)
#define  MG13_16PL   ~(1 << 5)
#else
#define  MG13_16PL   0xFFFF
#endif
#if (G17PL >= G13PL) || (G17PL == 0)
#define  MG13_17PL   ~(1 << 6)
#else
#define  MG13_17PL   0xFFFF
#endif
#if (G18PL >= G13PL) || (G18PL == 0)
#define  MG13_18PL   ~(1 << 7)
#else
#define  MG13_18PL   0xFFFF
#endif
#define  MG13_13PL   0x00FB
#define  MG13    (MG13_11PL & MG13_12PL & MG13_13PL & MG13_14PL & \
                  MG13_15PL & MG13_16PL & MG13_17PL & MG13_18PL)
// End of MG13:

// Beginning of MG14:
#if (G11PL >= G14PL) || (G11PL == 0)
#define  MG14_11PL   ~(1)
#else
#define  MG14_11PL   0xFFFF
#endif
#if (G12PL >= G14PL) || (G12PL == 0)
#define  MG14_12PL   ~(1 << 1)
#else
#define  MG14_12PL   0xFFFF
#endif
#if (G13PL >= G14PL) || (G13PL == 0)
#define  MG14_13PL   ~(1 << 2)
#else
#define  MG14_13PL   0xFFFF
#endif
#if (G15PL >= G14PL) || (G15PL == 0)
#define  MG14_15PL   ~(1 << 4)
#else
#define  MG14_15PL   0xFFFF
#endif
#if (G16PL >= G14PL) || (G16PL == 0)
#define  MG14_16PL   ~(1 << 5)
#else
#define  MG14_16PL   0xFFFF
#endif
#if (G17PL >= G14PL) || (G17PL == 0)
#define  MG14_17PL   ~(1 << 6)
#else
#define  MG14_17PL   0xFFFF
#endif
#if (G18PL >= G14PL) || (G18PL == 0)
#define  MG14_18PL   ~(1 << 7)
#else
#define  MG14_18PL   0xFFFF
#endif
#define  MG14_14PL   0x00F7
#define  MG14    (MG14_11PL & MG14_12PL & MG14_13PL & MG14_14PL & \
                  MG14_15PL & MG14_16PL & MG14_17PL & MG14_18PL)
// End of MG14:

// Beginning of MG15:
#if (G11PL >= G15PL) || (G11PL == 0)
#define  MG15_11PL   ~(1)
#else
#define  MG15_11PL   0xFFFF
#endif
#if (G12PL >= G15PL) || (G12PL == 0)
#define  MG15_12PL   ~(1 << 1)
#else
#define  MG15_12PL   0xFFFF
#endif
#if (G13PL >= G15PL) || (G13PL == 0)
#define  MG15_13PL   ~(1 << 2)
#else
#define  MG15_13PL   0xFFFF
#endif
#if (G14PL >= G15PL) || (G14PL == 0)
#define  MG15_14PL   ~(1 << 3)
#else
#define  MG15_14PL   0xFFFF
#endif
#if (G16PL >= G15PL) || (G16PL == 0)
#define  MG15_16PL   ~(1 << 5)
#else
#define  MG15_16PL   0xFFFF
#endif
#if (G17PL >= G15PL) || (G17PL == 0)
#define  MG15_17PL   ~(1 << 6)
#else
#define  MG15_17PL   0xFFFF
#endif
#if (G18PL >= G15PL) || (G18PL == 0)
#define  MG15_18PL   ~(1 << 7)
#else
#define  MG15_18PL   0xFFFF
#endif
#define  MG15_15PL   0x00EF
#define  MG15    (MG15_11PL & MG15_12PL & MG15_13PL & MG15_14PL & \
                  MG15_15PL & MG15_16PL & MG15_17PL & MG15_18PL)
// End of MG15:

// Beginning of MG16:
#if (G11PL >= G16PL) || (G11PL == 0)
#define  MG16_11PL   ~(1)
#else
#define  MG16_11PL   0xFFFF
#endif
#if (G12PL >= G16PL) || (G12PL == 0)
#define  MG16_12PL   ~(1 << 1)
#else
#define  MG16_12PL   0xFFFF
#endif
#if (G13PL >= G16PL) || (G13PL == 0)
#define  MG16_13PL   ~(1 << 2)
#else
#define  MG16_13PL   0xFFFF
#endif
#if (G14PL >= G16PL) || (G14PL == 0)
#define  MG16_14PL   ~(1 << 3)
#else
#define  MG16_14PL   0xFFFF
#endif
#if (G15PL >= G16PL) || (G15PL == 0)
#define  MG16_15PL   ~(1 << 4)
#else
#define  MG16_15PL   0xFFFF
#endif
#if (G17PL >= G16PL) || (G17PL == 0)
#define  MG16_17PL   ~(1 << 6)
#else
#define  MG16_17PL   0xFFFF
#endif
#if (G18PL >= G16PL) || (G18PL == 0)
#define  MG16_18PL   ~(1 << 7)
#else
#define  MG16_18PL   0xFFFF
#endif
#define  MG16_16PL   0x00DF
#define  MG16    (MG16_11PL & MG16_12PL & MG16_13PL & MG16_14PL & \
                  MG16_15PL & MG16_16PL & MG16_17PL & MG16_18PL)
// End of MG16:

// Beginning of MG17:
#if (G11PL >= G17PL) || (G11PL == 0)
#define  MG17_11PL   ~(1)
#else
#define  MG17_11PL   0xFFFF
#endif
#if (G12PL >= G17PL) || (G12PL == 0)
#define  MG17_12PL   ~(1 << 1)
#else
#define  MG17_12PL   0xFFFF
#endif
#if (G13PL >= G17PL) || (G13PL == 0)
#define  MG17_13PL   ~(1 << 2)
#else
#define  MG17_13PL   0xFFFF
#endif
#if (G14PL >= G17PL) || (G14PL == 0)
#define  MG17_14PL   ~(1 << 3)
#else
#define  MG17_14PL   0xFFFF
#endif
#if (G15PL >= G17PL) || (G15PL == 0)
#define  MG17_15PL   ~(1 << 4)
#else
#define  MG17_15PL   0xFFFF
#endif
#if (G16PL >= G17PL) || (G16PL == 0)
#define  MG17_16PL   ~(1 << 5)
#else
#define  MG17_16PL   0xFFFF
#endif
#if (G18PL >= G17PL) || (G18PL == 0)
#define  MG17_18PL   ~(1 << 7)
#else
#define  MG17_18PL   0xFFFF
#endif
#define  MG17_17PL   0x00BF
#define  MG17    (MG17_11PL & MG17_12PL & MG17_13PL & MG17_14PL & \
                  MG17_15PL & MG17_16PL & MG17_17PL & MG17_18PL)
// End of MG17:

// Beginning of MG18:
#if (G11PL >= G18PL) || (G11PL == 0)
#define  MG18_11PL   ~(1)
#else
#define  MG18_11PL   0xFFFF
#endif
#if (G12PL >= G18PL) || (G12PL == 0)
#define  MG18_12PL   ~(1 << 1)
#else
#define  MG18_12PL   0xFFFF
#endif
#if (G13PL >= G18PL) || (G13PL == 0)
#define  MG18_13PL   ~(1 << 2)
#else
#define  MG18_13PL   0xFFFF
#endif
#if (G14PL >= G18PL) || (G14PL == 0)
#define  MG18_14PL   ~(1 << 3)
#else
#define  MG18_14PL   0xFFFF
#endif
#if (G15PL >= G18PL) || (G15PL == 0)
#define  MG18_15PL   ~(1 << 4)
#else
#define  MG18_15PL   0xFFFF
#endif
#if (G16PL >= G18PL) || (G16PL == 0)
#define  MG18_16PL   ~(1 << 5)
#else
#define  MG18_16PL   0xFFFF
#endif
#if (G17PL >= G18PL) || (G17PL == 0)
#define  MG18_17PL   ~(1 << 6)
#else
#define  MG18_17PL   0xFFFF
#endif
#define  MG18_18PL   0x007F
#define  MG18    (MG18_11PL & MG18_12PL & MG18_13PL & MG18_14PL & \
                  MG18_15PL & MG18_16PL & MG18_17PL & MG18_18PL)
// End of MG18:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG21 to MG28:
//

// Beginning of MG21:
#if (G22PL >= G21PL) || (G22PL == 0)
#define  MG21_12PL   ~(1 << 1)
#else
#define  MG21_12PL   0xFFFF
#endif
#if (G23PL >= G21PL) || (G23PL == 0)
#define  MG21_13PL   ~(1 << 2)
#else
#define  MG21_13PL   0xFFFF
#endif
#if (G24PL >= G21PL) || (G24PL == 0)
#define  MG21_14PL   ~(1 << 3)
#else
#define  MG21_14PL   0xFFFF
#endif
#if (G25PL >= G21PL) || (G25PL == 0)
#define  MG21_15PL   ~(1 << 4)
#else
#define  MG21_15PL   0xFFFF
#endif
#if (G26PL >= G21PL) || (G26PL == 0)
#define  MG21_16PL   ~(1 << 5)
#else
#define  MG21_16PL   0xFFFF
#endif
#if (G27PL >= G21PL) || (G27PL == 0)
#define  MG21_17PL   ~(1 << 6)
#else
#define  MG21_17PL   0xFFFF
#endif
#if (G28PL >= G21PL) || (G28PL == 0)
#define  MG21_18PL   ~(1 << 7)
#else
#define  MG21_18PL   0xFFFF
#endif
#define  MG21_11PL   0x00FE
#define  MG21    (MG21_11PL & MG21_12PL & MG21_13PL & MG21_14PL & \
                  MG21_15PL & MG21_16PL & MG21_17PL & MG21_18PL)
// End of MG21:

// Beginning of MG22:
#if (G21PL >= G22PL) || (G21PL == 0)
#define  MG22_11PL   ~(1)
#else
#define  MG22_11PL   0xFFFF
#endif
#if (G23PL >= G22PL) || (G23PL == 0)
#define  MG22_13PL   ~(1 << 2)
#else
#define  MG22_13PL   0xFFFF
#endif
#if (G24PL >= G22PL) || (G24PL == 0)
#define  MG22_14PL   ~(1 << 3)
#else
#define  MG22_14PL   0xFFFF
#endif
#if (G25PL >= G22PL) || (G25PL == 0)
#define  MG22_15PL   ~(1 << 4)
#else
#define  MG22_15PL   0xFFFF
#endif
#if (G26PL >= G22PL) || (G26PL == 0)
#define  MG22_16PL   ~(1 << 5)
#else
#define  MG22_16PL   0xFFFF
#endif
#if (G27PL >= G22PL) || (G27PL == 0)
#define  MG22_17PL   ~(1 << 6)
#else
#define  MG22_17PL   0xFFFF
#endif
#if (G28PL >= G22PL) || (G28PL == 0)
#define  MG22_18PL   ~(1 << 7)
#else
#define  MG22_18PL   0xFFFF
#endif
#define  MG22_12PL   0x00FD
#define  MG22    (MG22_11PL & MG22_12PL & MG22_13PL & MG22_14PL & \
                  MG22_15PL & MG22_16PL & MG22_17PL & MG22_18PL)
// End of MG22:

// Beginning of MG23:
#if (G21PL >= G23PL) || (G21PL == 0)
#define  MG23_11PL   ~(1)
#else
#define  MG23_11PL   0xFFFF
#endif
#if (G22PL >= G23PL) || (G22PL == 0)
#define  MG23_12PL   ~(1 << 1)
#else
#define  MG23_12PL   0xFFFF
#endif
#if (G24PL >= G23PL) || (G24PL == 0)
#define  MG23_14PL   ~(1 << 3)
#else
#define  MG23_14PL   0xFFFF
#endif
#if (G25PL >= G23PL) || (G25PL == 0)
#define  MG23_15PL   ~(1 << 4)
#else
#define  MG23_15PL   0xFFFF
#endif
#if (G26PL >= G23PL) || (G26PL == 0)
#define  MG23_16PL   ~(1 << 5)
#else
#define  MG23_16PL   0xFFFF
#endif
#if (G27PL >= G23PL) || (G27PL == 0)
#define  MG23_17PL   ~(1 << 6)
#else
#define  MG23_17PL   0xFFFF
#endif
#if (G28PL >= G23PL) || (G28PL == 0)
#define  MG23_18PL   ~(1 << 7)
#else
#define  MG23_18PL   0xFFFF
#endif
#define  MG23_13PL   0x00FB
#define  MG23    (MG23_11PL & MG23_12PL & MG23_13PL & MG23_14PL & \
                  MG23_15PL & MG23_16PL & MG23_17PL & MG23_18PL)
// End of MG23:

// Beginning of MG24:
#if (G21PL >= G24PL) || (G21PL == 0)
#define  MG24_11PL   ~(1)
#else
#define  MG24_11PL   0xFFFF
#endif
#if (G22PL >= G24PL) || (G22PL == 0)
#define  MG24_12PL   ~(1 << 1)
#else
#define  MG24_12PL   0xFFFF
#endif
#if (G23PL >= G24PL) || (G23PL == 0)
#define  MG24_13PL   ~(1 << 2)
#else
#define  MG24_13PL   0xFFFF
#endif
#if (G25PL >= G24PL) || (G25PL == 0)
#define  MG24_15PL   ~(1 << 4)
#else
#define  MG24_15PL   0xFFFF
#endif
#if (G26PL >= G24PL) || (G26PL == 0)
#define  MG24_16PL   ~(1 << 5)
#else
#define  MG24_16PL   0xFFFF
#endif
#if (G27PL >= G24PL) || (G27PL == 0)
#define  MG24_17PL   ~(1 << 6)
#else
#define  MG24_17PL   0xFFFF
#endif
#if (G28PL >= G24PL) || (G28PL == 0)
#define  MG24_18PL   ~(1 << 7)
#else
#define  MG24_18PL   0xFFFF
#endif
#define  MG24_14PL   0x00F7
#define  MG24    (MG24_11PL & MG24_12PL & MG24_13PL & MG24_14PL & \
                  MG24_15PL & MG24_16PL & MG24_17PL & MG24_18PL)
// End of MG24:

// Beginning of MG25:
#if (G21PL >= G25PL) || (G21PL == 0)
#define  MG25_11PL   ~(1)
#else
#define  MG25_11PL   0xFFFF
#endif
#if (G22PL >= G25PL) || (G22PL == 0)
#define  MG25_12PL   ~(1 << 1)
#else
#define  MG25_12PL   0xFFFF
#endif
#if (G23PL >= G25PL) || (G23PL == 0)
#define  MG25_13PL   ~(1 << 2)
#else
#define  MG25_13PL   0xFFFF
#endif
#if (G24PL >= G25PL) || (G24PL == 0)
#define  MG25_14PL   ~(1 << 3)
#else
#define  MG25_14PL   0xFFFF
#endif
#if (G26PL >= G25PL) || (G26PL == 0)
#define  MG25_16PL   ~(1 << 5)
#else
#define  MG25_16PL   0xFFFF
#endif
#if (G27PL >= G25PL) || (G27PL == 0)
#define  MG25_17PL   ~(1 << 6)
#else
#define  MG25_17PL   0xFFFF
#endif
#if (G28PL >= G25PL) || (G28PL == 0)
#define  MG25_18PL   ~(1 << 7)
#else
#define  MG25_18PL   0xFFFF
#endif
#define  MG25_15PL   0x00EF
#define  MG25    (MG25_11PL & MG25_12PL & MG25_13PL & MG25_14PL & \
                  MG25_15PL & MG25_16PL & MG25_17PL & MG25_18PL)
// End of MG25:

// Beginning of MG26:
#if (G21PL >= G26PL) || (G21PL == 0)
#define  MG26_11PL   ~(1)
#else
#define  MG26_11PL   0xFFFF
#endif
#if (G22PL >= G26PL) || (G22PL == 0)
#define  MG26_12PL   ~(1 << 1)
#else
#define  MG26_12PL   0xFFFF
#endif
#if (G23PL >= G26PL) || (G23PL == 0)
#define  MG26_13PL   ~(1 << 2)
#else
#define  MG26_13PL   0xFFFF
#endif
#if (G24PL >= G26PL) || (G24PL == 0)
#define  MG26_14PL   ~(1 << 3)
#else
#define  MG26_14PL   0xFFFF
#endif
#if (G25PL >= G26PL) || (G25PL == 0)
#define  MG26_15PL   ~(1 << 4)
#else
#define  MG26_15PL   0xFFFF
#endif
#if (G27PL >= G26PL) || (G27PL == 0)
#define  MG26_17PL   ~(1 << 6)
#else
#define  MG26_17PL   0xFFFF
#endif
#if (G28PL >= G26PL) || (G28PL == 0)
#define  MG26_18PL   ~(1 << 7)
#else
#define  MG26_18PL   0xFFFF
#endif
#define  MG26_16PL   0x00DF
#define  MG26    (MG26_11PL & MG26_12PL & MG26_13PL & MG26_14PL & \
                  MG26_15PL & MG26_16PL & MG26_17PL & MG26_18PL)
// End of MG26:

// Beginning of MG27:
#if (G21PL >= G27PL) || (G21PL == 0)
#define  MG27_11PL   ~(1)
#else
#define  MG27_11PL   0xFFFF
#endif
#if (G22PL >= G27PL) || (G22PL == 0)
#define  MG27_12PL   ~(1 << 1)
#else
#define  MG27_12PL   0xFFFF
#endif
#if (G23PL >= G27PL) || (G23PL == 0)
#define  MG27_13PL   ~(1 << 2)
#else
#define  MG27_13PL   0xFFFF
#endif
#if (G24PL >= G27PL) || (G24PL == 0)
#define  MG27_14PL   ~(1 << 3)
#else
#define  MG27_14PL   0xFFFF
#endif
#if (G25PL >= G27PL) || (G25PL == 0)
#define  MG27_15PL   ~(1 << 4)
#else
#define  MG27_15PL   0xFFFF
#endif
#if (G26PL >= G27PL) || (G26PL == 0)
#define  MG27_16PL   ~(1 << 5)
#else
#define  MG27_16PL   0xFFFF
#endif
#if (G28PL >= G27PL) || (G28PL == 0)
#define  MG27_18PL   ~(1 << 7)
#else
#define  MG27_18PL   0xFFFF
#endif
#define  MG27_17PL   0x00BF
#define  MG27    (MG27_11PL & MG27_12PL & MG27_13PL & MG27_14PL & \
                  MG27_15PL & MG27_16PL & MG27_17PL & MG27_18PL)
// End of MG27:

// Beginning of MG28:
#if (G21PL >= G28PL) || (G21PL == 0)
#define  MG28_11PL   ~(1)
#else
#define  MG28_11PL   0xFFFF
#endif
#if (G22PL >= G28PL) || (G22PL == 0)
#define  MG28_12PL   ~(1 << 1)
#else
#define  MG28_12PL   0xFFFF
#endif
#if (G23PL >= G28PL) || (G23PL == 0)
#define  MG28_13PL   ~(1 << 2)
#else
#define  MG28_13PL   0xFFFF
#endif
#if (G24PL >= G28PL) || (G24PL == 0)
#define  MG28_14PL   ~(1 << 3)
#else
#define  MG28_14PL   0xFFFF
#endif
#if (G25PL >= G28PL) || (G25PL == 0)
#define  MG28_15PL   ~(1 << 4)
#else
#define  MG28_15PL   0xFFFF
#endif
#if (G26PL >= G28PL) || (G26PL == 0)
#define  MG28_16PL   ~(1 << 5)
#else
#define  MG28_16PL   0xFFFF
#endif
#if (G27PL >= G28PL) || (G27PL == 0)
#define  MG28_17PL   ~(1 << 6)
#else
#define  MG28_17PL   0xFFFF
#endif
#define  MG28_18PL   0x007F
#define  MG28    (MG28_11PL & MG28_12PL & MG28_13PL & MG28_14PL & \
                  MG28_15PL & MG28_16PL & MG28_17PL & MG28_18PL)
// End of MG28:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG31 to MG38:
//

// Beginning of MG31:
#if (G32PL >= G31PL) || (G32PL == 0)
#define  MG31_12PL   ~(1 << 1)
#else
#define  MG31_12PL   0xFFFF
#endif
#if (G33PL >= G31PL) || (G33PL == 0)
#define  MG31_13PL   ~(1 << 2)
#else
#define  MG31_13PL   0xFFFF
#endif
#if (G34PL >= G31PL) || (G34PL == 0)
#define  MG31_14PL   ~(1 << 3)
#else
#define  MG31_14PL   0xFFFF
#endif
#if (G35PL >= G31PL) || (G35PL == 0)
#define  MG31_15PL   ~(1 << 4)
#else
#define  MG31_15PL   0xFFFF
#endif
#if (G36PL >= G31PL) || (G36PL == 0)
#define  MG31_16PL   ~(1 << 5)
#else
#define  MG31_16PL   0xFFFF
#endif
#if (G37PL >= G31PL) || (G37PL == 0)
#define  MG31_17PL   ~(1 << 6)
#else
#define  MG31_17PL   0xFFFF
#endif
#if (G38PL >= G31PL) || (G38PL == 0)
#define  MG31_18PL   ~(1 << 7)
#else
#define  MG31_18PL   0xFFFF
#endif
#define  MG31_11PL   0x00FE
#define  MG31    (MG31_11PL & MG31_12PL & MG31_13PL & MG31_14PL & \
                  MG31_15PL & MG31_16PL & MG31_17PL & MG31_18PL)
// End of MG31:

// Beginning of MG32:
#if (G31PL >= G32PL) || (G31PL == 0)
#define  MG32_11PL   ~(1)
#else
#define  MG32_11PL   0xFFFF
#endif
#if (G33PL >= G32PL) || (G33PL == 0)
#define  MG32_13PL   ~(1 << 2)
#else
#define  MG32_13PL   0xFFFF
#endif
#if (G34PL >= G32PL) || (G34PL == 0)
#define  MG32_14PL   ~(1 << 3)
#else
#define  MG32_14PL   0xFFFF
#endif
#if (G35PL >= G32PL) || (G35PL == 0)
#define  MG32_15PL   ~(1 << 4)
#else
#define  MG32_15PL   0xFFFF
#endif
#if (G36PL >= G32PL) || (G36PL == 0)
#define  MG32_16PL   ~(1 << 5)
#else
#define  MG32_16PL   0xFFFF
#endif
#if (G37PL >= G32PL) || (G37PL == 0)
#define  MG32_17PL   ~(1 << 6)
#else
#define  MG32_17PL   0xFFFF
#endif
#if (G38PL >= G32PL) || (G38PL == 0)
#define  MG32_18PL   ~(1 << 7)
#else
#define  MG32_18PL   0xFFFF
#endif
#define  MG32_12PL   0x00FD
#define  MG32    (MG32_11PL & MG32_12PL & MG32_13PL & MG32_14PL & \
                  MG32_15PL & MG32_16PL & MG32_17PL & MG32_18PL)
// End of MG32:

// Beginning of MG33:
#if (G31PL >= G33PL) || (G31PL == 0)
#define  MG33_11PL   ~(1)
#else
#define  MG33_11PL   0xFFFF
#endif
#if (G32PL >= G33PL) || (G32PL == 0)
#define  MG33_12PL   ~(1 << 1)
#else
#define  MG33_12PL   0xFFFF
#endif
#if (G34PL >= G33PL) || (G34PL == 0)
#define  MG33_14PL   ~(1 << 3)
#else
#define  MG33_14PL   0xFFFF
#endif
#if (G35PL >= G33PL) || (G35PL == 0)
#define  MG33_15PL   ~(1 << 4)
#else
#define  MG33_15PL   0xFFFF
#endif
#if (G36PL >= G33PL) || (G36PL == 0)
#define  MG33_16PL   ~(1 << 5)
#else
#define  MG33_16PL   0xFFFF
#endif
#if (G37PL >= G33PL) || (G37PL == 0)
#define  MG33_17PL   ~(1 << 6)
#else
#define  MG33_17PL   0xFFFF
#endif
#if (G38PL >= G33PL) || (G38PL == 0)
#define  MG33_18PL   ~(1 << 7)
#else
#define  MG33_18PL   0xFFFF
#endif
#define  MG33_13PL   0x00FB
#define  MG33    (MG33_11PL & MG33_12PL & MG33_13PL & MG33_14PL & \
                  MG33_15PL & MG33_16PL & MG33_17PL & MG33_18PL)
// End of MG33:

// Beginning of MG34:
#if (G31PL >= G34PL) || (G31PL == 0)
#define  MG34_11PL   ~(1)
#else
#define  MG34_11PL   0xFFFF
#endif
#if (G32PL >= G34PL) || (G32PL == 0)
#define  MG34_12PL   ~(1 << 1)
#else
#define  MG34_12PL   0xFFFF
#endif
#if (G33PL >= G34PL) || (G33PL == 0)
#define  MG34_13PL   ~(1 << 2)
#else
#define  MG34_13PL   0xFFFF
#endif
#if (G35PL >= G34PL) || (G35PL == 0)
#define  MG34_15PL   ~(1 << 4)
#else
#define  MG34_15PL   0xFFFF
#endif
#if (G36PL >= G34PL) || (G36PL == 0)
#define  MG34_16PL   ~(1 << 5)
#else
#define  MG34_16PL   0xFFFF
#endif
#if (G37PL >= G34PL) || (G37PL == 0)
#define  MG34_17PL   ~(1 << 6)
#else
#define  MG34_17PL   0xFFFF
#endif
#if (G38PL >= G34PL) || (G38PL == 0)
#define  MG34_18PL   ~(1 << 7)
#else
#define  MG34_18PL   0xFFFF
#endif
#define  MG34_14PL   0x00F7
#define  MG34    (MG34_11PL & MG34_12PL & MG34_13PL & MG34_14PL & \
                  MG34_15PL & MG34_16PL & MG34_17PL & MG34_18PL)
// End of MG34:

// Beginning of MG35:
#if (G31PL >= G35PL) || (G31PL == 0)
#define  MG35_11PL   ~(1)
#else
#define  MG35_11PL   0xFFFF
#endif
#if (G32PL >= G35PL) || (G32PL == 0)
#define  MG35_12PL   ~(1 << 1)
#else
#define  MG35_12PL   0xFFFF
#endif
#if (G33PL >= G35PL) || (G33PL == 0)
#define  MG35_13PL   ~(1 << 2)
#else
#define  MG35_13PL   0xFFFF
#endif
#if (G34PL >= G35PL) || (G34PL == 0)
#define  MG35_14PL   ~(1 << 3)
#else
#define  MG35_14PL   0xFFFF
#endif
#if (G36PL >= G35PL) || (G36PL == 0)
#define  MG35_16PL   ~(1 << 5)
#else
#define  MG35_16PL   0xFFFF
#endif
#if (G37PL >= G35PL) || (G37PL == 0)
#define  MG35_17PL   ~(1 << 6)
#else
#define  MG35_17PL   0xFFFF
#endif
#if (G38PL >= G35PL) || (G38PL == 0)
#define  MG35_18PL   ~(1 << 7)
#else
#define  MG35_18PL   0xFFFF
#endif
#define  MG35_15PL   0x00EF
#define  MG35    (MG35_11PL & MG35_12PL & MG35_13PL & MG35_14PL & \
                  MG35_15PL & MG35_16PL & MG35_17PL & MG35_18PL)
// End of MG35:

// Beginning of MG36:
#if (G31PL >= G36PL) || (G31PL == 0)
#define  MG36_11PL   ~(1)
#else
#define  MG36_11PL   0xFFFF
#endif
#if (G32PL >= G36PL) || (G32PL == 0)
#define  MG36_12PL   ~(1 << 1)
#else
#define  MG36_12PL   0xFFFF
#endif
#if (G33PL >= G36PL) || (G33PL == 0)
#define  MG36_13PL   ~(1 << 2)
#else
#define  MG36_13PL   0xFFFF
#endif
#if (G34PL >= G36PL) || (G34PL == 0)
#define  MG36_14PL   ~(1 << 3)
#else
#define  MG36_14PL   0xFFFF
#endif
#if (G35PL >= G36PL) || (G35PL == 0)
#define  MG36_15PL   ~(1 << 4)
#else
#define  MG36_15PL   0xFFFF
#endif
#if (G37PL >= G36PL) || (G37PL == 0)
#define  MG36_17PL   ~(1 << 6)
#else
#define  MG36_17PL   0xFFFF
#endif
#if (G38PL >= G36PL) || (G38PL == 0)
#define  MG36_18PL   ~(1 << 7)
#else
#define  MG36_18PL   0xFFFF
#endif
#define  MG36_16PL   0x00DF
#define  MG36    (MG36_11PL & MG36_12PL & MG36_13PL & MG36_14PL & \
                  MG36_15PL & MG36_16PL & MG36_17PL & MG36_18PL)
// End of MG36:

// Beginning of MG37:
#if (G31PL >= G37PL) || (G31PL == 0)
#define  MG37_11PL   ~(1)
#else
#define  MG37_11PL   0xFFFF
#endif
#if (G32PL >= G37PL) || (G32PL == 0)
#define  MG37_12PL   ~(1 << 1)
#else
#define  MG37_12PL   0xFFFF
#endif
#if (G33PL >= G37PL) || (G33PL == 0)
#define  MG37_13PL   ~(1 << 2)
#else
#define  MG37_13PL   0xFFFF
#endif
#if (G34PL >= G37PL) || (G34PL == 0)
#define  MG37_14PL   ~(1 << 3)
#else
#define  MG37_14PL   0xFFFF
#endif
#if (G35PL >= G37PL) || (G35PL == 0)
#define  MG37_15PL   ~(1 << 4)
#else
#define  MG37_15PL   0xFFFF
#endif
#if (G36PL >= G37PL) || (G36PL == 0)
#define  MG37_16PL   ~(1 << 5)
#else
#define  MG37_16PL   0xFFFF
#endif
#if (G38PL >= G37PL) || (G38PL == 0)
#define  MG37_18PL   ~(1 << 7)
#else
#define  MG37_18PL   0xFFFF
#endif
#define  MG37_17PL   0x00BF
#define  MG37    (MG37_11PL & MG37_12PL & MG37_13PL & MG37_14PL & \
                  MG37_15PL & MG37_16PL & MG37_17PL & MG37_18PL)
// End of MG37:

// Beginning of MG38:
#if (G31PL >= G38PL) || (G31PL == 0)
#define  MG38_11PL   ~(1)
#else
#define  MG38_11PL   0xFFFF
#endif
#if (G32PL >= G38PL) || (G32PL == 0)
#define  MG38_12PL   ~(1 << 1)
#else
#define  MG38_12PL   0xFFFF
#endif
#if (G33PL >= G38PL) || (G33PL == 0)
#define  MG38_13PL   ~(1 << 2)
#else
#define  MG38_13PL   0xFFFF
#endif
#if (G34PL >= G38PL) || (G34PL == 0)
#define  MG38_14PL   ~(1 << 3)
#else
#define  MG38_14PL   0xFFFF
#endif
#if (G35PL >= G38PL) || (G35PL == 0)
#define  MG38_15PL   ~(1 << 4)
#else
#define  MG38_15PL   0xFFFF
#endif
#if (G36PL >= G38PL) || (G36PL == 0)
#define  MG38_16PL   ~(1 << 5)
#else
#define  MG38_16PL   0xFFFF
#endif
#if (G37PL >= G38PL) || (G37PL == 0)
#define  MG38_17PL   ~(1 << 6)
#else
#define  MG38_17PL   0xFFFF
#endif
#define  MG38_18PL   0x007F
#define  MG38    (MG38_11PL & MG38_12PL & MG38_13PL & MG38_14PL & \
                  MG38_15PL & MG38_16PL & MG38_17PL & MG38_18PL)
// End of MG38:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG41 to MG48:
//

// Beginning of MG41:
#if (G42PL >= G41PL) || (G42PL == 0)
#define  MG41_12PL   ~(1 << 1)
#else
#define  MG41_12PL   0xFFFF
#endif
#if (G43PL >= G41PL) || (G43PL == 0)
#define  MG41_13PL   ~(1 << 2)
#else
#define  MG41_13PL   0xFFFF
#endif
#if (G44PL >= G41PL) || (G44PL == 0)
#define  MG41_14PL   ~(1 << 3)
#else
#define  MG41_14PL   0xFFFF
#endif
#if (G45PL >= G41PL) || (G45PL == 0)
#define  MG41_15PL   ~(1 << 4)
#else
#define  MG41_15PL   0xFFFF
#endif
#if (G46PL >= G41PL) || (G46PL == 0)
#define  MG41_16PL   ~(1 << 5)
#else
#define  MG41_16PL   0xFFFF
#endif
#if (G47PL >= G41PL) || (G47PL == 0)
#define  MG41_17PL   ~(1 << 6)
#else
#define  MG41_17PL   0xFFFF
#endif
#if (G48PL >= G41PL) || (G48PL == 0)
#define  MG41_18PL   ~(1 << 7)
#else
#define  MG41_18PL   0xFFFF
#endif
#define  MG41_11PL   0x00FE
#define  MG41    (MG41_11PL & MG41_12PL & MG41_13PL & MG41_14PL & \
                  MG41_15PL & MG41_16PL & MG41_17PL & MG41_18PL)
// End of MG41:

// Beginning of MG42:
#if (G41PL >= G42PL) || (G41PL == 0)
#define  MG42_11PL   ~(1)
#else
#define  MG42_11PL   0xFFFF
#endif
#if (G43PL >= G42PL) || (G43PL == 0)
#define  MG42_13PL   ~(1 << 2)
#else
#define  MG42_13PL   0xFFFF
#endif
#if (G44PL >= G42PL) || (G44PL == 0)
#define  MG42_14PL   ~(1 << 3)
#else
#define  MG42_14PL   0xFFFF
#endif
#if (G45PL >= G42PL) || (G45PL == 0)
#define  MG42_15PL   ~(1 << 4)
#else
#define  MG42_15PL   0xFFFF
#endif
#if (G46PL >= G42PL) || (G46PL == 0)
#define  MG42_16PL   ~(1 << 5)
#else
#define  MG42_16PL   0xFFFF
#endif
#if (G47PL >= G42PL) || (G47PL == 0)
#define  MG42_17PL   ~(1 << 6)
#else
#define  MG42_17PL   0xFFFF
#endif
#if (G48PL >= G42PL) || (G48PL == 0)
#define  MG42_18PL   ~(1 << 7)
#else
#define  MG42_18PL   0xFFFF
#endif
#define  MG42_12PL   0x00FD
#define  MG42    (MG42_11PL & MG42_12PL & MG42_13PL & MG42_14PL & \
                  MG42_15PL & MG42_16PL & MG42_17PL & MG42_18PL)
// End of MG42:

// Beginning of MG43:
#if (G41PL >= G43PL) || (G41PL == 0)
#define  MG43_11PL   ~(1)
#else
#define  MG43_11PL   0xFFFF
#endif
#if (G42PL >= G43PL) || (G42PL == 0)
#define  MG43_12PL   ~(1 << 1)
#else
#define  MG43_12PL   0xFFFF
#endif
#if (G44PL >= G43PL) || (G44PL == 0)
#define  MG43_14PL   ~(1 << 3)
#else
#define  MG43_14PL   0xFFFF
#endif
#if (G45PL >= G43PL) || (G45PL == 0)
#define  MG43_15PL   ~(1 << 4)
#else
#define  MG43_15PL   0xFFFF
#endif
#if (G46PL >= G43PL) || (G46PL == 0)
#define  MG43_16PL   ~(1 << 5)
#else
#define  MG43_16PL   0xFFFF
#endif
#if (G47PL >= G43PL) || (G47PL == 0)
#define  MG43_17PL   ~(1 << 6)
#else
#define  MG43_17PL   0xFFFF
#endif
#if (G48PL >= G43PL) || (G48PL == 0)
#define  MG43_18PL   ~(1 << 7)
#else
#define  MG43_18PL   0xFFFF
#endif
#define  MG43_13PL   0x00FB
#define  MG43    (MG43_11PL & MG43_12PL & MG43_13PL & MG43_14PL & \
                  MG43_15PL & MG43_16PL & MG43_17PL & MG43_18PL)
// End of MG43:

// Beginning of MG44:
#if (G41PL >= G44PL) || (G41PL == 0)
#define  MG44_11PL   ~(1)
#else
#define  MG44_11PL   0xFFFF
#endif
#if (G42PL >= G44PL) || (G42PL == 0)
#define  MG44_12PL   ~(1 << 1)
#else
#define  MG44_12PL   0xFFFF
#endif
#if (G43PL >= G44PL) || (G43PL == 0)
#define  MG44_13PL   ~(1 << 2)
#else
#define  MG44_13PL   0xFFFF
#endif
#if (G45PL >= G44PL) || (G45PL == 0)
#define  MG44_15PL   ~(1 << 4)
#else
#define  MG44_15PL   0xFFFF
#endif
#if (G46PL >= G44PL) || (G46PL == 0)
#define  MG44_16PL   ~(1 << 5)
#else
#define  MG44_16PL   0xFFFF
#endif
#if (G47PL >= G44PL) || (G47PL == 0)
#define  MG44_17PL   ~(1 << 6)
#else
#define  MG44_17PL   0xFFFF
#endif
#if (G48PL >= G44PL) || (G48PL == 0)
#define  MG44_18PL   ~(1 << 7)
#else
#define  MG44_18PL   0xFFFF
#endif
#define  MG44_14PL   0x00F7
#define  MG44    (MG44_11PL & MG44_12PL & MG44_13PL & MG44_14PL & \
                  MG44_15PL & MG44_16PL & MG44_17PL & MG44_18PL)
// End of MG44:

// Beginning of MG45:
#if (G41PL >= G45PL) || (G41PL == 0)
#define  MG45_11PL   ~(1)
#else
#define  MG45_11PL   0xFFFF
#endif
#if (G42PL >= G45PL) || (G42PL == 0)
#define  MG45_12PL   ~(1 << 1)
#else
#define  MG45_12PL   0xFFFF
#endif
#if (G43PL >= G45PL) || (G43PL == 0)
#define  MG45_13PL   ~(1 << 2)
#else
#define  MG45_13PL   0xFFFF
#endif
#if (G44PL >= G45PL) || (G44PL == 0)
#define  MG45_14PL   ~(1 << 3)
#else
#define  MG45_14PL   0xFFFF
#endif
#if (G46PL >= G45PL) || (G46PL == 0)
#define  MG45_16PL   ~(1 << 5)
#else
#define  MG45_16PL   0xFFFF
#endif
#if (G47PL >= G45PL) || (G47PL == 0)
#define  MG45_17PL   ~(1 << 6)
#else
#define  MG45_17PL   0xFFFF
#endif
#if (G48PL >= G45PL) || (G48PL == 0)
#define  MG45_18PL   ~(1 << 7)
#else
#define  MG45_18PL   0xFFFF
#endif
#define  MG45_15PL   0x00EF
#define  MG45    (MG45_11PL & MG45_12PL & MG45_13PL & MG45_14PL & \
                  MG45_15PL & MG45_16PL & MG45_17PL & MG45_18PL)
// End of MG45:

// Beginning of MG46:
#if (G41PL >= G46PL) || (G41PL == 0)
#define  MG46_11PL   ~(1)
#else
#define  MG46_11PL   0xFFFF
#endif
#if (G42PL >= G46PL) || (G42PL == 0)
#define  MG46_12PL   ~(1 << 1)
#else
#define  MG46_12PL   0xFFFF
#endif
#if (G43PL >= G46PL) || (G43PL == 0)
#define  MG46_13PL   ~(1 << 2)
#else
#define  MG46_13PL   0xFFFF
#endif
#if (G44PL >= G46PL) || (G44PL == 0)
#define  MG46_14PL   ~(1 << 3)
#else
#define  MG46_14PL   0xFFFF
#endif
#if (G45PL >= G46PL) || (G45PL == 0)
#define  MG46_15PL   ~(1 << 4)
#else
#define  MG46_15PL   0xFFFF
#endif
#if (G47PL >= G46PL) || (G47PL == 0)
#define  MG46_17PL   ~(1 << 6)
#else
#define  MG46_17PL   0xFFFF
#endif
#if (G48PL >= G46PL) || (G48PL == 0)
#define  MG46_18PL   ~(1 << 7)
#else
#define  MG46_18PL   0xFFFF
#endif
#define  MG46_16PL   0x00DF
#define  MG46    (MG46_11PL & MG46_12PL & MG46_13PL & MG46_14PL & \
                  MG46_15PL & MG46_16PL & MG46_17PL & MG46_18PL)
// End of MG46:

// Beginning of MG47:
#if (G41PL >= G47PL) || (G41PL == 0)
#define  MG47_11PL   ~(1)
#else
#define  MG47_11PL   0xFFFF
#endif
#if (G42PL >= G47PL) || (G42PL == 0)
#define  MG47_12PL   ~(1 << 1)
#else
#define  MG47_12PL   0xFFFF
#endif
#if (G43PL >= G47PL) || (G43PL == 0)
#define  MG47_13PL   ~(1 << 2)
#else
#define  MG47_13PL   0xFFFF
#endif
#if (G44PL >= G47PL) || (G44PL == 0)
#define  MG47_14PL   ~(1 << 3)
#else
#define  MG47_14PL   0xFFFF
#endif
#if (G45PL >= G47PL) || (G45PL == 0)
#define  MG47_15PL   ~(1 << 4)
#else
#define  MG47_15PL   0xFFFF
#endif
#if (G46PL >= G47PL) || (G46PL == 0)
#define  MG47_16PL   ~(1 << 5)
#else
#define  MG47_16PL   0xFFFF
#endif
#if (G48PL >= G47PL) || (G48PL == 0)
#define  MG47_18PL   ~(1 << 7)
#else
#define  MG47_18PL   0xFFFF
#endif
#define  MG47_17PL   0x00BF
#define  MG47    (MG47_11PL & MG47_12PL & MG47_13PL & MG47_14PL & \
                  MG47_15PL & MG47_16PL & MG47_17PL & MG47_18PL)
// End of MG47:

// Beginning of MG48:
#if (G41PL >= G48PL) || (G41PL == 0)
#define  MG48_11PL   ~(1)
#else
#define  MG48_11PL   0xFFFF
#endif
#if (G42PL >= G48PL) || (G42PL == 0)
#define  MG48_12PL   ~(1 << 1)
#else
#define  MG48_12PL   0xFFFF
#endif
#if (G43PL >= G48PL) || (G43PL == 0)
#define  MG48_13PL   ~(1 << 2)
#else
#define  MG48_13PL   0xFFFF
#endif
#if (G44PL >= G48PL) || (G44PL == 0)
#define  MG48_14PL   ~(1 << 3)
#else
#define  MG48_14PL   0xFFFF
#endif
#if (G45PL >= G48PL) || (G45PL == 0)
#define  MG48_15PL   ~(1 << 4)
#else
#define  MG48_15PL   0xFFFF
#endif
#if (G46PL >= G48PL) || (G46PL == 0)
#define  MG48_16PL   ~(1 << 5)
#else
#define  MG48_16PL   0xFFFF
#endif
#if (G47PL >= G48PL) || (G47PL == 0)
#define  MG48_17PL   ~(1 << 6)
#else
#define  MG48_17PL   0xFFFF
#endif
#define  MG48_18PL   0x007F
#define  MG48    (MG48_11PL & MG48_12PL & MG48_13PL & MG48_14PL & \
                  MG48_15PL & MG48_16PL & MG48_17PL & MG48_18PL)
// End of MG48:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG51 to MG58:
//

// Beginning of MG51:
#if (G52PL >= G51PL) || (G52PL == 0)
#define  MG51_12PL   ~(1 << 1)
#else
#define  MG51_12PL   0xFFFF
#endif
#if (G53PL >= G51PL) || (G53PL == 0)
#define  MG51_13PL   ~(1 << 2)
#else
#define  MG51_13PL   0xFFFF
#endif
#if (G54PL >= G51PL) || (G54PL == 0)
#define  MG51_14PL   ~(1 << 3)
#else
#define  MG51_14PL   0xFFFF
#endif
#if (G55PL >= G51PL) || (G55PL == 0)
#define  MG51_15PL   ~(1 << 4)
#else
#define  MG51_15PL   0xFFFF
#endif
#if (G56PL >= G51PL) || (G56PL == 0)
#define  MG51_16PL   ~(1 << 5)
#else
#define  MG51_16PL   0xFFFF
#endif
#if (G57PL >= G51PL) || (G57PL == 0)
#define  MG51_17PL   ~(1 << 6)
#else
#define  MG51_17PL   0xFFFF
#endif
#if (G58PL >= G51PL) || (G58PL == 0)
#define  MG51_18PL   ~(1 << 7)
#else
#define  MG51_18PL   0xFFFF
#endif
#define  MG51_11PL   0x00FE
#define  MG51    (MG51_11PL & MG51_12PL & MG51_13PL & MG51_14PL & \
                  MG51_15PL & MG51_16PL & MG51_17PL & MG51_18PL)
// End of MG51:

// Beginning of MG52:
#if (G51PL >= G52PL) || (G51PL == 0)
#define  MG52_11PL   ~(1)
#else
#define  MG52_11PL   0xFFFF
#endif
#if (G53PL >= G52PL) || (G53PL == 0)
#define  MG52_13PL   ~(1 << 2)
#else
#define  MG52_13PL   0xFFFF
#endif
#if (G54PL >= G52PL) || (G54PL == 0)
#define  MG52_14PL   ~(1 << 3)
#else
#define  MG52_14PL   0xFFFF
#endif
#if (G55PL >= G52PL) || (G55PL == 0)
#define  MG52_15PL   ~(1 << 4)
#else
#define  MG52_15PL   0xFFFF
#endif
#if (G56PL >= G52PL) || (G56PL == 0)
#define  MG52_16PL   ~(1 << 5)
#else
#define  MG52_16PL   0xFFFF
#endif
#if (G57PL >= G52PL) || (G57PL == 0)
#define  MG52_17PL   ~(1 << 6)
#else
#define  MG52_17PL   0xFFFF
#endif
#if (G58PL >= G52PL) || (G58PL == 0)
#define  MG52_18PL   ~(1 << 7)
#else
#define  MG52_18PL   0xFFFF
#endif
#define  MG52_12PL   0x00FD
#define  MG52    (MG52_11PL & MG52_12PL & MG52_13PL & MG52_14PL & \
                  MG52_15PL & MG52_16PL & MG52_17PL & MG52_18PL)
// End of MG52:

// Beginning of MG53:
#if (G51PL >= G53PL) || (G51PL == 0)
#define  MG53_11PL   ~(1)
#else
#define  MG53_11PL   0xFFFF
#endif
#if (G52PL >= G53PL) || (G52PL == 0)
#define  MG53_12PL   ~(1 << 1)
#else
#define  MG53_12PL   0xFFFF
#endif
#if (G54PL >= G53PL) || (G54PL == 0)
#define  MG53_14PL   ~(1 << 3)
#else
#define  MG53_14PL   0xFFFF
#endif
#if (G55PL >= G53PL) || (G55PL == 0)
#define  MG53_15PL   ~(1 << 4)
#else
#define  MG53_15PL   0xFFFF
#endif
#if (G56PL >= G53PL) || (G56PL == 0)
#define  MG53_16PL   ~(1 << 5)
#else
#define  MG53_16PL   0xFFFF
#endif
#if (G57PL >= G53PL) || (G57PL == 0)
#define  MG53_17PL   ~(1 << 6)
#else
#define  MG53_17PL   0xFFFF
#endif
#if (G58PL >= G53PL) || (G58PL == 0)
#define  MG53_18PL   ~(1 << 7)
#else
#define  MG53_18PL   0xFFFF
#endif
#define  MG53_13PL   0x00FB
#define  MG53    (MG53_11PL & MG53_12PL & MG53_13PL & MG53_14PL & \
                  MG53_15PL & MG53_16PL & MG53_17PL & MG53_18PL)
// End of MG53:

// Beginning of MG54:
#if (G51PL >= G54PL) || (G51PL == 0)
#define  MG54_11PL   ~(1)
#else
#define  MG54_11PL   0xFFFF
#endif
#if (G52PL >= G54PL) || (G52PL == 0)
#define  MG54_12PL   ~(1 << 1)
#else
#define  MG54_12PL   0xFFFF
#endif
#if (G53PL >= G54PL) || (G53PL == 0)
#define  MG54_13PL   ~(1 << 2)
#else
#define  MG54_13PL   0xFFFF
#endif
#if (G55PL >= G54PL) || (G55PL == 0)
#define  MG54_15PL   ~(1 << 4)
#else
#define  MG54_15PL   0xFFFF
#endif
#if (G56PL >= G54PL) || (G56PL == 0)
#define  MG54_16PL   ~(1 << 5)
#else
#define  MG54_16PL   0xFFFF
#endif
#if (G57PL >= G54PL) || (G57PL == 0)
#define  MG54_17PL   ~(1 << 6)
#else
#define  MG54_17PL   0xFFFF
#endif
#if (G58PL >= G54PL) || (G58PL == 0)
#define  MG54_18PL   ~(1 << 7)
#else
#define  MG54_18PL   0xFFFF
#endif
#define  MG54_14PL   0x00F7
#define  MG54    (MG54_11PL & MG54_12PL & MG54_13PL & MG54_14PL & \
                  MG54_15PL & MG54_16PL & MG54_17PL & MG54_18PL)
// End of MG54:

// Beginning of MG55:
#if (G51PL >= G55PL) || (G51PL == 0)
#define  MG55_11PL   ~(1)
#else
#define  MG55_11PL   0xFFFF
#endif
#if (G52PL >= G55PL) || (G52PL == 0)
#define  MG55_12PL   ~(1 << 1)
#else
#define  MG55_12PL   0xFFFF
#endif
#if (G53PL >= G55PL) || (G53PL == 0)
#define  MG55_13PL   ~(1 << 2)
#else
#define  MG55_13PL   0xFFFF
#endif
#if (G54PL >= G55PL) || (G54PL == 0)
#define  MG55_14PL   ~(1 << 3)
#else
#define  MG55_14PL   0xFFFF
#endif
#if (G56PL >= G55PL) || (G56PL == 0)
#define  MG55_16PL   ~(1 << 5)
#else
#define  MG55_16PL   0xFFFF
#endif
#if (G57PL >= G55PL) || (G57PL == 0)
#define  MG55_17PL   ~(1 << 6)
#else
#define  MG55_17PL   0xFFFF
#endif
#if (G58PL >= G55PL) || (G58PL == 0)
#define  MG55_18PL   ~(1 << 7)
#else
#define  MG55_18PL   0xFFFF
#endif
#define  MG55_15PL   0x00EF
#define  MG55    (MG55_11PL & MG55_12PL & MG55_13PL & MG55_14PL & \
                  MG55_15PL & MG55_16PL & MG55_17PL & MG55_18PL)
// End of MG55:

// Beginning of MG56:
#if (G51PL >= G56PL) || (G51PL == 0)
#define  MG56_11PL   ~(1)
#else
#define  MG56_11PL   0xFFFF
#endif
#if (G52PL >= G56PL) || (G52PL == 0)
#define  MG56_12PL   ~(1 << 1)
#else
#define  MG56_12PL   0xFFFF
#endif
#if (G53PL >= G56PL) || (G53PL == 0)
#define  MG56_13PL   ~(1 << 2)
#else
#define  MG56_13PL   0xFFFF
#endif
#if (G54PL >= G56PL) || (G54PL == 0)
#define  MG56_14PL   ~(1 << 3)
#else
#define  MG56_14PL   0xFFFF
#endif
#if (G55PL >= G56PL) || (G55PL == 0)
#define  MG56_15PL   ~(1 << 4)
#else
#define  MG56_15PL   0xFFFF
#endif
#if (G57PL >= G56PL) || (G57PL == 0)
#define  MG56_17PL   ~(1 << 6)
#else
#define  MG56_17PL   0xFFFF
#endif
#if (G58PL >= G56PL) || (G58PL == 0)
#define  MG56_18PL   ~(1 << 7)
#else
#define  MG56_18PL   0xFFFF
#endif
#define  MG56_16PL   0x00DF
#define  MG56    (MG56_11PL & MG56_12PL & MG56_13PL & MG56_14PL & \
                  MG56_15PL & MG56_16PL & MG56_17PL & MG56_18PL)
// End of MG56:

// Beginning of MG57:
#if (G51PL >= G57PL) || (G51PL == 0)
#define  MG57_11PL   ~(1)
#else
#define  MG57_11PL   0xFFFF
#endif
#if (G52PL >= G57PL) || (G52PL == 0)
#define  MG57_12PL   ~(1 << 1)
#else
#define  MG57_12PL   0xFFFF
#endif
#if (G53PL >= G57PL) || (G53PL == 0)
#define  MG57_13PL   ~(1 << 2)
#else
#define  MG57_13PL   0xFFFF
#endif
#if (G54PL >= G57PL) || (G54PL == 0)
#define  MG57_14PL   ~(1 << 3)
#else
#define  MG57_14PL   0xFFFF
#endif
#if (G55PL >= G57PL) || (G55PL == 0)
#define  MG57_15PL   ~(1 << 4)
#else
#define  MG57_15PL   0xFFFF
#endif
#if (G56PL >= G57PL) || (G56PL == 0)
#define  MG57_16PL   ~(1 << 5)
#else
#define  MG57_16PL   0xFFFF
#endif
#if (G58PL >= G57PL) || (G58PL == 0)
#define  MG57_18PL   ~(1 << 7)
#else
#define  MG57_18PL   0xFFFF
#endif
#define  MG57_17PL   0x00BF
#define  MG57    (MG57_11PL & MG57_12PL & MG57_13PL & MG57_14PL & \
                  MG57_15PL & MG57_16PL & MG57_17PL & MG57_18PL)
// End of MG57:

// Beginning of MG58:
#if (G51PL >= G58PL) || (G51PL == 0)
#define  MG58_11PL   ~(1)
#else
#define  MG58_11PL   0xFFFF
#endif
#if (G52PL >= G58PL) || (G52PL == 0)
#define  MG58_12PL   ~(1 << 1)
#else
#define  MG58_12PL   0xFFFF
#endif
#if (G53PL >= G58PL) || (G53PL == 0)
#define  MG58_13PL   ~(1 << 2)
#else
#define  MG58_13PL   0xFFFF
#endif
#if (G54PL >= G58PL) || (G54PL == 0)
#define  MG58_14PL   ~(1 << 3)
#else
#define  MG58_14PL   0xFFFF
#endif
#if (G55PL >= G58PL) || (G55PL == 0)
#define  MG58_15PL   ~(1 << 4)
#else
#define  MG58_15PL   0xFFFF
#endif
#if (G56PL >= G58PL) || (G56PL == 0)
#define  MG58_16PL   ~(1 << 5)
#else
#define  MG58_16PL   0xFFFF
#endif
#if (G57PL >= G58PL) || (G57PL == 0)
#define  MG58_17PL   ~(1 << 6)
#else
#define  MG58_17PL   0xFFFF
#endif
#define  MG58_18PL   0x007F
#define  MG58    (MG58_11PL & MG58_12PL & MG58_13PL & MG58_14PL & \
                  MG58_15PL & MG58_16PL & MG58_17PL & MG58_18PL)
// End of MG58:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG61 to MG68:
//

// Beginning of MG61:
#if (G62PL >= G61PL) || (G62PL == 0)
#define  MG61_12PL   ~(1 << 1)
#else
#define  MG61_12PL   0xFFFF
#endif
#if (G63PL >= G61PL) || (G63PL == 0)
#define  MG61_13PL   ~(1 << 2)
#else
#define  MG61_13PL   0xFFFF
#endif
#if (G64PL >= G61PL) || (G64PL == 0)
#define  MG61_14PL   ~(1 << 3)
#else
#define  MG61_14PL   0xFFFF
#endif
#if (G65PL >= G61PL) || (G65PL == 0)
#define  MG61_15PL   ~(1 << 4)
#else
#define  MG61_15PL   0xFFFF
#endif
#if (G66PL >= G61PL) || (G66PL == 0)
#define  MG61_16PL   ~(1 << 5)
#else
#define  MG61_16PL   0xFFFF
#endif
#if (G67PL >= G61PL) || (G67PL == 0)
#define  MG61_17PL   ~(1 << 6)
#else
#define  MG61_17PL   0xFFFF
#endif
#if (G68PL >= G61PL) || (G68PL == 0)
#define  MG61_18PL   ~(1 << 7)
#else
#define  MG61_18PL   0xFFFF
#endif
#define  MG61_11PL   0x00FE
#define  MG61    (MG61_11PL & MG61_12PL & MG61_13PL & MG61_14PL & \
                  MG61_15PL & MG61_16PL & MG61_17PL & MG61_18PL)
// End of MG61:

// Beginning of MG62:
#if (G61PL >= G62PL) || (G61PL == 0)
#define  MG62_11PL   ~(1)
#else
#define  MG62_11PL   0xFFFF
#endif
#if (G63PL >= G62PL) || (G63PL == 0)
#define  MG62_13PL   ~(1 << 2)
#else
#define  MG62_13PL   0xFFFF
#endif
#if (G64PL >= G62PL) || (G64PL == 0)
#define  MG62_14PL   ~(1 << 3)
#else
#define  MG62_14PL   0xFFFF
#endif
#if (G65PL >= G62PL) || (G65PL == 0)
#define  MG62_15PL   ~(1 << 4)
#else
#define  MG62_15PL   0xFFFF
#endif
#if (G66PL >= G62PL) || (G66PL == 0)
#define  MG62_16PL   ~(1 << 5)
#else
#define  MG62_16PL   0xFFFF
#endif
#if (G67PL >= G62PL) || (G67PL == 0)
#define  MG62_17PL   ~(1 << 6)
#else
#define  MG62_17PL   0xFFFF
#endif
#if (G68PL >= G62PL) || (G68PL == 0)
#define  MG62_18PL   ~(1 << 7)
#else
#define  MG62_18PL   0xFFFF
#endif
#define  MG62_12PL   0x00FD
#define  MG62    (MG62_11PL & MG62_12PL & MG62_13PL & MG62_14PL & \
                  MG62_15PL & MG62_16PL & MG62_17PL & MG62_18PL)
// End of MG62:

// Beginning of MG63:
#if (G61PL >= G63PL) || (G61PL == 0)
#define  MG63_11PL   ~(1)
#else
#define  MG63_11PL   0xFFFF
#endif
#if (G62PL >= G63PL) || (G62PL == 0)
#define  MG63_12PL   ~(1 << 1)
#else
#define  MG63_12PL   0xFFFF
#endif
#if (G64PL >= G63PL) || (G64PL == 0)
#define  MG63_14PL   ~(1 << 3)
#else
#define  MG63_14PL   0xFFFF
#endif
#if (G65PL >= G63PL) || (G65PL == 0)
#define  MG63_15PL   ~(1 << 4)
#else
#define  MG63_15PL   0xFFFF
#endif
#if (G66PL >= G63PL) || (G66PL == 0)
#define  MG63_16PL   ~(1 << 5)
#else
#define  MG63_16PL   0xFFFF
#endif
#if (G67PL >= G63PL) || (G67PL == 0)
#define  MG63_17PL   ~(1 << 6)
#else
#define  MG63_17PL   0xFFFF
#endif
#if (G68PL >= G63PL) || (G68PL == 0)
#define  MG63_18PL   ~(1 << 7)
#else
#define  MG63_18PL   0xFFFF
#endif
#define  MG63_13PL   0x00FB
#define  MG63    (MG63_11PL & MG63_12PL & MG63_13PL & MG63_14PL & \
                  MG63_15PL & MG63_16PL & MG63_17PL & MG63_18PL)
// End of MG63:

// Beginning of MG64:
#if (G61PL >= G64PL) || (G61PL == 0)
#define  MG64_11PL   ~(1)
#else
#define  MG64_11PL   0xFFFF
#endif
#if (G62PL >= G64PL) || (G62PL == 0)
#define  MG64_12PL   ~(1 << 1)
#else
#define  MG64_12PL   0xFFFF
#endif
#if (G63PL >= G64PL) || (G63PL == 0)
#define  MG64_13PL   ~(1 << 2)
#else
#define  MG64_13PL   0xFFFF
#endif
#if (G65PL >= G64PL) || (G65PL == 0)
#define  MG64_15PL   ~(1 << 4)
#else
#define  MG64_15PL   0xFFFF
#endif
#if (G66PL >= G64PL) || (G66PL == 0)
#define  MG64_16PL   ~(1 << 5)
#else
#define  MG64_16PL   0xFFFF
#endif
#if (G67PL >= G64PL) || (G67PL == 0)
#define  MG64_17PL   ~(1 << 6)
#else
#define  MG64_17PL   0xFFFF
#endif
#if (G68PL >= G64PL) || (G68PL == 0)
#define  MG64_18PL   ~(1 << 7)
#else
#define  MG64_18PL   0xFFFF
#endif
#define  MG64_14PL   0x00F7
#define  MG64    (MG64_11PL & MG64_12PL & MG64_13PL & MG64_14PL & \
                  MG64_15PL & MG64_16PL & MG64_17PL & MG64_18PL)
// End of MG64:

// Beginning of MG65:
#if (G61PL >= G65PL) || (G61PL == 0)
#define  MG65_11PL   ~(1)
#else
#define  MG65_11PL   0xFFFF
#endif
#if (G62PL >= G65PL) || (G62PL == 0)
#define  MG65_12PL   ~(1 << 1)
#else
#define  MG65_12PL   0xFFFF
#endif
#if (G63PL >= G65PL) || (G63PL == 0)
#define  MG65_13PL   ~(1 << 2)
#else
#define  MG65_13PL   0xFFFF
#endif
#if (G64PL >= G65PL) || (G64PL == 0)
#define  MG65_14PL   ~(1 << 3)
#else
#define  MG65_14PL   0xFFFF
#endif
#if (G66PL >= G65PL) || (G66PL == 0)
#define  MG65_16PL   ~(1 << 5)
#else
#define  MG65_16PL   0xFFFF
#endif
#if (G67PL >= G65PL) || (G67PL == 0)
#define  MG65_17PL   ~(1 << 6)
#else
#define  MG65_17PL   0xFFFF
#endif
#if (G68PL >= G65PL) || (G68PL == 0)
#define  MG65_18PL   ~(1 << 7)
#else
#define  MG65_18PL   0xFFFF
#endif
#define  MG65_15PL   0x00EF
#define  MG65    (MG65_11PL & MG65_12PL & MG65_13PL & MG65_14PL & \
                  MG65_15PL & MG65_16PL & MG65_17PL & MG65_18PL)
// End of MG65:

// Beginning of MG66:
#if (G61PL >= G66PL) || (G61PL == 0)
#define  MG66_11PL   ~(1)
#else
#define  MG66_11PL   0xFFFF
#endif
#if (G62PL >= G66PL) || (G62PL == 0)
#define  MG66_12PL   ~(1 << 1)
#else
#define  MG66_12PL   0xFFFF
#endif
#if (G63PL >= G66PL) || (G63PL == 0)
#define  MG66_13PL   ~(1 << 2)
#else
#define  MG66_13PL   0xFFFF
#endif
#if (G64PL >= G66PL) || (G64PL == 0)
#define  MG66_14PL   ~(1 << 3)
#else
#define  MG66_14PL   0xFFFF
#endif
#if (G65PL >= G66PL) || (G65PL == 0)
#define  MG66_15PL   ~(1 << 4)
#else
#define  MG66_15PL   0xFFFF
#endif
#if (G67PL >= G66PL) || (G67PL == 0)
#define  MG66_17PL   ~(1 << 6)
#else
#define  MG66_17PL   0xFFFF
#endif
#if (G68PL >= G66PL) || (G68PL == 0)
#define  MG66_18PL   ~(1 << 7)
#else
#define  MG66_18PL   0xFFFF
#endif
#define  MG66_16PL   0x00DF
#define  MG66    (MG66_11PL & MG66_12PL & MG66_13PL & MG66_14PL & \
                  MG66_15PL & MG66_16PL & MG66_17PL & MG66_18PL)
// End of MG66:

// Beginning of MG67:
#if (G61PL >= G67PL) || (G61PL == 0)
#define  MG67_11PL   ~(1)
#else
#define  MG67_11PL   0xFFFF
#endif
#if (G62PL >= G67PL) || (G62PL == 0)
#define  MG67_12PL   ~(1 << 1)
#else
#define  MG67_12PL   0xFFFF
#endif
#if (G63PL >= G67PL) || (G63PL == 0)
#define  MG67_13PL   ~(1 << 2)
#else
#define  MG67_13PL   0xFFFF
#endif
#if (G64PL >= G67PL) || (G64PL == 0)
#define  MG67_14PL   ~(1 << 3)
#else
#define  MG67_14PL   0xFFFF
#endif
#if (G65PL >= G67PL) || (G65PL == 0)
#define  MG67_15PL   ~(1 << 4)
#else
#define  MG67_15PL   0xFFFF
#endif
#if (G66PL >= G67PL) || (G66PL == 0)
#define  MG67_16PL   ~(1 << 5)
#else
#define  MG67_16PL   0xFFFF
#endif
#if (G68PL >= G67PL) || (G68PL == 0)
#define  MG67_18PL   ~(1 << 7)
#else
#define  MG67_18PL   0xFFFF
#endif
#define  MG67_17PL   0x00BF
#define  MG67    (MG67_11PL & MG67_12PL & MG67_13PL & MG67_14PL & \
                  MG67_15PL & MG67_16PL & MG67_17PL & MG67_18PL)
// End of MG67:

// Beginning of MG68:
#if (G61PL >= G68PL) || (G61PL == 0)
#define  MG68_11PL   ~(1)
#else
#define  MG68_11PL   0xFFFF
#endif
#if (G62PL >= G68PL) || (G62PL == 0)
#define  MG68_12PL   ~(1 << 1)
#else
#define  MG68_12PL   0xFFFF
#endif
#if (G63PL >= G68PL) || (G63PL == 0)
#define  MG68_13PL   ~(1 << 2)
#else
#define  MG68_13PL   0xFFFF
#endif
#if (G64PL >= G68PL) || (G64PL == 0)
#define  MG68_14PL   ~(1 << 3)
#else
#define  MG68_14PL   0xFFFF
#endif
#if (G65PL >= G68PL) || (G65PL == 0)
#define  MG68_15PL   ~(1 << 4)
#else
#define  MG68_15PL   0xFFFF
#endif
#if (G66PL >= G68PL) || (G66PL == 0)
#define  MG68_16PL   ~(1 << 5)
#else
#define  MG68_16PL   0xFFFF
#endif
#if (G67PL >= G68PL) || (G67PL == 0)
#define  MG68_17PL   ~(1 << 6)
#else
#define  MG68_17PL   0xFFFF
#endif
#define  MG68_18PL   0x007F
#define  MG68    (MG68_11PL & MG68_12PL & MG68_13PL & MG68_14PL & \
                  MG68_15PL & MG68_16PL & MG68_17PL & MG68_18PL)
// End of MG68:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG71 to MG78:
//

// Beginning of MG71:
#if (G72PL >= G71PL) || (G72PL == 0)
#define  MG71_12PL   ~(1 << 1)
#else
#define  MG71_12PL   0xFFFF
#endif
#if (G73PL >= G71PL) || (G73PL == 0)
#define  MG71_13PL   ~(1 << 2)
#else
#define  MG71_13PL   0xFFFF
#endif
#if (G74PL >= G71PL) || (G74PL == 0)
#define  MG71_14PL   ~(1 << 3)
#else
#define  MG71_14PL   0xFFFF
#endif
#if (G75PL >= G71PL) || (G75PL == 0)
#define  MG71_15PL   ~(1 << 4)
#else
#define  MG71_15PL   0xFFFF
#endif
#if (G76PL >= G71PL) || (G76PL == 0)
#define  MG71_16PL   ~(1 << 5)
#else
#define  MG71_16PL   0xFFFF
#endif
#if (G77PL >= G71PL) || (G77PL == 0)
#define  MG71_17PL   ~(1 << 6)
#else
#define  MG71_17PL   0xFFFF
#endif
#if (G78PL >= G71PL) || (G78PL == 0)
#define  MG71_18PL   ~(1 << 7)
#else
#define  MG71_18PL   0xFFFF
#endif
#define  MG71_11PL   0x00FE
#define  MG71    (MG71_11PL & MG71_12PL & MG71_13PL & MG71_14PL & \
                  MG71_15PL & MG71_16PL & MG71_17PL & MG71_18PL)
// End of MG71:

// Beginning of MG72:
#if (G71PL >= G72PL) || (G71PL == 0)
#define  MG72_11PL   ~(1)
#else
#define  MG72_11PL   0xFFFF
#endif
#if (G73PL >= G72PL) || (G73PL == 0)
#define  MG72_13PL   ~(1 << 2)
#else
#define  MG72_13PL   0xFFFF
#endif
#if (G74PL >= G72PL) || (G74PL == 0)
#define  MG72_14PL   ~(1 << 3)
#else
#define  MG72_14PL   0xFFFF
#endif
#if (G75PL >= G72PL) || (G75PL == 0)
#define  MG72_15PL   ~(1 << 4)
#else
#define  MG72_15PL   0xFFFF
#endif
#if (G76PL >= G72PL) || (G76PL == 0)
#define  MG72_16PL   ~(1 << 5)
#else
#define  MG72_16PL   0xFFFF
#endif
#if (G77PL >= G72PL) || (G77PL == 0)
#define  MG72_17PL   ~(1 << 6)
#else
#define  MG72_17PL   0xFFFF
#endif
#if (G78PL >= G72PL) || (G78PL == 0)
#define  MG72_18PL   ~(1 << 7)
#else
#define  MG72_18PL   0xFFFF
#endif
#define  MG72_12PL   0x00FD
#define  MG72    (MG72_11PL & MG72_12PL & MG72_13PL & MG72_14PL & \
                  MG72_15PL & MG72_16PL & MG72_17PL & MG72_18PL)
// End of MG72:

// Beginning of MG73:
#if (G71PL >= G73PL) || (G71PL == 0)
#define  MG73_11PL   ~(1)
#else
#define  MG73_11PL   0xFFFF
#endif
#if (G72PL >= G73PL) || (G72PL == 0)
#define  MG73_12PL   ~(1 << 1)
#else
#define  MG73_12PL   0xFFFF
#endif
#if (G74PL >= G73PL) || (G74PL == 0)
#define  MG73_14PL   ~(1 << 3)
#else
#define  MG73_14PL   0xFFFF
#endif
#if (G75PL >= G73PL) || (G75PL == 0)
#define  MG73_15PL   ~(1 << 4)
#else
#define  MG73_15PL   0xFFFF
#endif
#if (G76PL >= G73PL) || (G76PL == 0)
#define  MG73_16PL   ~(1 << 5)
#else
#define  MG73_16PL   0xFFFF
#endif
#if (G77PL >= G73PL) || (G77PL == 0)
#define  MG73_17PL   ~(1 << 6)
#else
#define  MG73_17PL   0xFFFF
#endif
#if (G78PL >= G73PL) || (G78PL == 0)
#define  MG73_18PL   ~(1 << 7)
#else
#define  MG73_18PL   0xFFFF
#endif
#define  MG73_13PL   0x00FB
#define  MG73    (MG73_11PL & MG73_12PL & MG73_13PL & MG73_14PL & \
                  MG73_15PL & MG73_16PL & MG73_17PL & MG73_18PL)
// End of MG73:

// Beginning of MG74:
#if (G71PL >= G74PL) || (G71PL == 0)
#define  MG74_11PL   ~(1)
#else
#define  MG74_11PL   0xFFFF
#endif
#if (G72PL >= G74PL) || (G72PL == 0)
#define  MG74_12PL   ~(1 << 1)
#else
#define  MG74_12PL   0xFFFF
#endif
#if (G73PL >= G74PL) || (G73PL == 0)
#define  MG74_13PL   ~(1 << 2)
#else
#define  MG74_13PL   0xFFFF
#endif
#if (G75PL >= G74PL) || (G75PL == 0)
#define  MG74_15PL   ~(1 << 4)
#else
#define  MG74_15PL   0xFFFF
#endif
#if (G76PL >= G74PL) || (G76PL == 0)
#define  MG74_16PL   ~(1 << 5)
#else
#define  MG74_16PL   0xFFFF
#endif
#if (G77PL >= G74PL) || (G77PL == 0)
#define  MG74_17PL   ~(1 << 6)
#else
#define  MG74_17PL   0xFFFF
#endif
#if (G78PL >= G74PL) || (G78PL == 0)
#define  MG74_18PL   ~(1 << 7)
#else
#define  MG74_18PL   0xFFFF
#endif
#define  MG74_14PL   0x00F7
#define  MG74    (MG74_11PL & MG74_12PL & MG74_13PL & MG74_14PL & \
                  MG74_15PL & MG74_16PL & MG74_17PL & MG74_18PL)
// End of MG74:

// Beginning of MG75:
#if (G71PL >= G75PL) || (G71PL == 0)
#define  MG75_11PL   ~(1)
#else
#define  MG75_11PL   0xFFFF
#endif
#if (G72PL >= G75PL) || (G72PL == 0)
#define  MG75_12PL   ~(1 << 1)
#else
#define  MG75_12PL   0xFFFF
#endif
#if (G73PL >= G75PL) || (G73PL == 0)
#define  MG75_13PL   ~(1 << 2)
#else
#define  MG75_13PL   0xFFFF
#endif
#if (G74PL >= G75PL) || (G74PL == 0)
#define  MG75_14PL   ~(1 << 3)
#else
#define  MG75_14PL   0xFFFF
#endif
#if (G76PL >= G75PL) || (G76PL == 0)
#define  MG75_16PL   ~(1 << 5)
#else
#define  MG75_16PL   0xFFFF
#endif
#if (G77PL >= G75PL) || (G77PL == 0)
#define  MG75_17PL   ~(1 << 6)
#else
#define  MG75_17PL   0xFFFF
#endif
#if (G78PL >= G75PL) || (G78PL == 0)
#define  MG75_18PL   ~(1 << 7)
#else
#define  MG75_18PL   0xFFFF
#endif
#define  MG75_15PL   0x00EF
#define  MG75    (MG75_11PL & MG75_12PL & MG75_13PL & MG75_14PL & \
                  MG75_15PL & MG75_16PL & MG75_17PL & MG75_18PL)
// End of MG75:

// Beginning of MG76:
#if (G71PL >= G76PL) || (G71PL == 0)
#define  MG76_11PL   ~(1)
#else
#define  MG76_11PL   0xFFFF
#endif
#if (G72PL >= G76PL) || (G72PL == 0)
#define  MG76_12PL   ~(1 << 1)
#else
#define  MG76_12PL   0xFFFF
#endif
#if (G73PL >= G76PL) || (G73PL == 0)
#define  MG76_13PL   ~(1 << 2)
#else
#define  MG76_13PL   0xFFFF
#endif
#if (G74PL >= G76PL) || (G74PL == 0)
#define  MG76_14PL   ~(1 << 3)
#else
#define  MG76_14PL   0xFFFF
#endif
#if (G75PL >= G76PL) || (G75PL == 0)
#define  MG76_15PL   ~(1 << 4)
#else
#define  MG76_15PL   0xFFFF
#endif
#if (G77PL >= G76PL) || (G77PL == 0)
#define  MG76_17PL   ~(1 << 6)
#else
#define  MG76_17PL   0xFFFF
#endif
#if (G78PL >= G76PL) || (G78PL == 0)
#define  MG76_18PL   ~(1 << 7)
#else
#define  MG76_18PL   0xFFFF
#endif
#define  MG76_16PL   0x00DF
#define  MG76    (MG76_11PL & MG76_12PL & MG76_13PL & MG76_14PL & \
                  MG76_15PL & MG76_16PL & MG76_17PL & MG76_18PL)
// End of MG76:

// Beginning of MG77:
#if (G71PL >= G77PL) || (G71PL == 0)
#define  MG77_11PL   ~(1)
#else
#define  MG77_11PL   0xFFFF
#endif
#if (G72PL >= G77PL) || (G72PL == 0)
#define  MG77_12PL   ~(1 << 1)
#else
#define  MG77_12PL   0xFFFF
#endif
#if (G73PL >= G77PL) || (G73PL == 0)
#define  MG77_13PL   ~(1 << 2)
#else
#define  MG77_13PL   0xFFFF
#endif
#if (G74PL >= G77PL) || (G74PL == 0)
#define  MG77_14PL   ~(1 << 3)
#else
#define  MG77_14PL   0xFFFF
#endif
#if (G75PL >= G77PL) || (G75PL == 0)
#define  MG77_15PL   ~(1 << 4)
#else
#define  MG77_15PL   0xFFFF
#endif
#if (G76PL >= G77PL) || (G76PL == 0)
#define  MG77_16PL   ~(1 << 5)
#else
#define  MG77_16PL   0xFFFF
#endif
#if (G78PL >= G77PL) || (G78PL == 0)
#define  MG77_18PL   ~(1 << 7)
#else
#define  MG77_18PL   0xFFFF
#endif
#define  MG77_17PL   0x00BF
#define  MG77    (MG77_11PL & MG77_12PL & MG77_13PL & MG77_14PL & \
                  MG77_15PL & MG77_16PL & MG77_17PL & MG77_18PL)
// End of MG77:

// Beginning of MG78:
#if (G71PL >= G78PL) || (G71PL == 0)
#define  MG78_11PL   ~(1)
#else
#define  MG78_11PL   0xFFFF
#endif
#if (G72PL >= G78PL) || (G72PL == 0)
#define  MG78_12PL   ~(1 << 1)
#else
#define  MG78_12PL   0xFFFF
#endif
#if (G73PL >= G78PL) || (G73PL == 0)
#define  MG78_13PL   ~(1 << 2)
#else
#define  MG78_13PL   0xFFFF
#endif
#if (G74PL >= G78PL) || (G74PL == 0)
#define  MG78_14PL   ~(1 << 3)
#else
#define  MG78_14PL   0xFFFF
#endif
#if (G75PL >= G78PL) || (G75PL == 0)
#define  MG78_15PL   ~(1 << 4)
#else
#define  MG78_15PL   0xFFFF
#endif
#if (G76PL >= G78PL) || (G76PL == 0)
#define  MG78_16PL   ~(1 << 5)
#else
#define  MG78_16PL   0xFFFF
#endif
#if (G77PL >= G78PL) || (G77PL == 0)
#define  MG78_17PL   ~(1 << 6)
#else
#define  MG78_17PL   0xFFFF
#endif
#define  MG78_18PL   0x007F
#define  MG78    (MG78_11PL & MG78_12PL & MG78_13PL & MG78_14PL & \
                  MG78_15PL & MG78_16PL & MG78_17PL & MG78_18PL)
// End of MG78:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG81 to MG88:
//

// Beginning of MG81:
#if (G82PL >= G81PL) || (G82PL == 0)
#define  MG81_12PL   ~(1 << 1)
#else
#define  MG81_12PL   0xFFFF
#endif
#if (G83PL >= G81PL) || (G83PL == 0)
#define  MG81_13PL   ~(1 << 2)
#else
#define  MG81_13PL   0xFFFF
#endif
#if (G84PL >= G81PL) || (G84PL == 0)
#define  MG81_14PL   ~(1 << 3)
#else
#define  MG81_14PL   0xFFFF
#endif
#if (G85PL >= G81PL) || (G85PL == 0)
#define  MG81_15PL   ~(1 << 4)
#else
#define  MG81_15PL   0xFFFF
#endif
#if (G86PL >= G81PL) || (G86PL == 0)
#define  MG81_16PL   ~(1 << 5)
#else
#define  MG81_16PL   0xFFFF
#endif
#if (G87PL >= G81PL) || (G87PL == 0)
#define  MG81_17PL   ~(1 << 6)
#else
#define  MG81_17PL   0xFFFF
#endif
#if (G88PL >= G81PL) || (G88PL == 0)
#define  MG81_18PL   ~(1 << 7)
#else
#define  MG81_18PL   0xFFFF
#endif
#define  MG81_11PL   0x00FE
#define  MG81    (MG81_11PL & MG81_12PL & MG81_13PL & MG81_14PL & \
                  MG81_15PL & MG81_16PL & MG81_17PL & MG81_18PL)
// End of MG81:

// Beginning of MG82:
#if (G81PL >= G82PL) || (G81PL == 0)
#define  MG82_11PL   ~(1)
#else
#define  MG82_11PL   0xFFFF
#endif
#if (G83PL >= G82PL) || (G83PL == 0)
#define  MG82_13PL   ~(1 << 2)
#else
#define  MG82_13PL   0xFFFF
#endif
#if (G84PL >= G82PL) || (G84PL == 0)
#define  MG82_14PL   ~(1 << 3)
#else
#define  MG82_14PL   0xFFFF
#endif
#if (G85PL >= G82PL) || (G85PL == 0)
#define  MG82_15PL   ~(1 << 4)
#else
#define  MG82_15PL   0xFFFF
#endif
#if (G86PL >= G82PL) || (G86PL == 0)
#define  MG82_16PL   ~(1 << 5)
#else
#define  MG82_16PL   0xFFFF
#endif
#if (G87PL >= G82PL) || (G87PL == 0)
#define  MG82_17PL   ~(1 << 6)
#else
#define  MG82_17PL   0xFFFF
#endif
#if (G88PL >= G82PL) || (G88PL == 0)
#define  MG82_18PL   ~(1 << 7)
#else
#define  MG82_18PL   0xFFFF
#endif
#define  MG82_12PL   0x00FD
#define  MG82    (MG82_11PL & MG82_12PL & MG82_13PL & MG82_14PL & \
                  MG82_15PL & MG82_16PL & MG82_17PL & MG82_18PL)
// End of MG82:

// Beginning of MG83:
#if (G81PL >= G83PL) || (G81PL == 0)
#define  MG83_11PL   ~(1)
#else
#define  MG83_11PL   0xFFFF
#endif
#if (G82PL >= G83PL) || (G82PL == 0)
#define  MG83_12PL   ~(1 << 1)
#else
#define  MG83_12PL   0xFFFF
#endif
#if (G84PL >= G83PL) || (G84PL == 0)
#define  MG83_14PL   ~(1 << 3)
#else
#define  MG83_14PL   0xFFFF
#endif
#if (G85PL >= G83PL) || (G85PL == 0)
#define  MG83_15PL   ~(1 << 4)
#else
#define  MG83_15PL   0xFFFF
#endif
#if (G86PL >= G83PL) || (G86PL == 0)
#define  MG83_16PL   ~(1 << 5)
#else
#define  MG83_16PL   0xFFFF
#endif
#if (G87PL >= G83PL) || (G87PL == 0)
#define  MG83_17PL   ~(1 << 6)
#else
#define  MG83_17PL   0xFFFF
#endif
#if (G88PL >= G83PL) || (G88PL == 0)
#define  MG83_18PL   ~(1 << 7)
#else
#define  MG83_18PL   0xFFFF
#endif
#define  MG83_13PL   0x00FB
#define  MG83    (MG83_11PL & MG83_12PL & MG83_13PL & MG83_14PL & \
                  MG83_15PL & MG83_16PL & MG83_17PL & MG83_18PL)
// End of MG83:

// Beginning of MG84:
#if (G81PL >= G84PL) || (G81PL == 0)
#define  MG84_11PL   ~(1)
#else
#define  MG84_11PL   0xFFFF
#endif
#if (G82PL >= G84PL) || (G82PL == 0)
#define  MG84_12PL   ~(1 << 1)
#else
#define  MG84_12PL   0xFFFF
#endif
#if (G83PL >= G84PL) || (G83PL == 0)
#define  MG84_13PL   ~(1 << 2)
#else
#define  MG84_13PL   0xFFFF
#endif
#if (G85PL >= G84PL) || (G85PL == 0)
#define  MG84_15PL   ~(1 << 4)
#else
#define  MG84_15PL   0xFFFF
#endif
#if (G86PL >= G84PL) || (G86PL == 0)
#define  MG84_16PL   ~(1 << 5)
#else
#define  MG84_16PL   0xFFFF
#endif
#if (G87PL >= G84PL) || (G87PL == 0)
#define  MG84_17PL   ~(1 << 6)
#else
#define  MG84_17PL   0xFFFF
#endif
#if (G88PL >= G84PL) || (G88PL == 0)
#define  MG84_18PL   ~(1 << 7)
#else
#define  MG84_18PL   0xFFFF
#endif
#define  MG84_14PL   0x00F7
#define  MG84    (MG84_11PL & MG84_12PL & MG84_13PL & MG84_14PL & \
                  MG84_15PL & MG84_16PL & MG84_17PL & MG84_18PL)
// End of MG84:

// Beginning of MG85:
#if (G81PL >= G85PL) || (G81PL == 0)
#define  MG85_11PL   ~(1)
#else
#define  MG85_11PL   0xFFFF
#endif
#if (G82PL >= G85PL) || (G82PL == 0)
#define  MG85_12PL   ~(1 << 1)
#else
#define  MG85_12PL   0xFFFF
#endif
#if (G83PL >= G85PL) || (G83PL == 0)
#define  MG85_13PL   ~(1 << 2)
#else
#define  MG85_13PL   0xFFFF
#endif
#if (G84PL >= G85PL) || (G84PL == 0)
#define  MG85_14PL   ~(1 << 3)
#else
#define  MG85_14PL   0xFFFF
#endif
#if (G86PL >= G85PL) || (G86PL == 0)
#define  MG85_16PL   ~(1 << 5)
#else
#define  MG85_16PL   0xFFFF
#endif
#if (G87PL >= G85PL) || (G87PL == 0)
#define  MG85_17PL   ~(1 << 6)
#else
#define  MG85_17PL   0xFFFF
#endif
#if (G88PL >= G85PL) || (G88PL == 0)
#define  MG85_18PL   ~(1 << 7)
#else
#define  MG85_18PL   0xFFFF
#endif
#define  MG85_15PL   0x00EF
#define  MG85    (MG85_11PL & MG85_12PL & MG85_13PL & MG85_14PL & \
                  MG85_15PL & MG85_16PL & MG85_17PL & MG85_18PL)
// End of MG85:

// Beginning of MG86:
#if (G81PL >= G86PL) || (G81PL == 0)
#define  MG86_11PL   ~(1)
#else
#define  MG86_11PL   0xFFFF
#endif
#if (G82PL >= G86PL) || (G82PL == 0)
#define  MG86_12PL   ~(1 << 1)
#else
#define  MG86_12PL   0xFFFF
#endif
#if (G83PL >= G86PL) || (G83PL == 0)
#define  MG86_13PL   ~(1 << 2)
#else
#define  MG86_13PL   0xFFFF
#endif
#if (G84PL >= G86PL) || (G84PL == 0)
#define  MG86_14PL   ~(1 << 3)
#else
#define  MG86_14PL   0xFFFF
#endif
#if (G85PL >= G86PL) || (G85PL == 0)
#define  MG86_15PL   ~(1 << 4)
#else
#define  MG86_15PL   0xFFFF
#endif
#if (G87PL >= G86PL) || (G87PL == 0)
#define  MG86_17PL   ~(1 << 6)
#else
#define  MG86_17PL   0xFFFF
#endif
#if (G88PL >= G86PL) || (G88PL == 0)
#define  MG86_18PL   ~(1 << 7)
#else
#define  MG86_18PL   0xFFFF
#endif
#define  MG86_16PL   0x00DF
#define  MG86    (MG86_11PL & MG86_12PL & MG86_13PL & MG86_14PL & \
                  MG86_15PL & MG86_16PL & MG86_17PL & MG86_18PL)
// End of MG86:

// Beginning of MG87:
#if (G81PL >= G87PL) || (G81PL == 0)
#define  MG87_11PL   ~(1)
#else
#define  MG87_11PL   0xFFFF
#endif
#if (G82PL >= G87PL) || (G82PL == 0)
#define  MG87_12PL   ~(1 << 1)
#else
#define  MG87_12PL   0xFFFF
#endif
#if (G83PL >= G87PL) || (G83PL == 0)
#define  MG87_13PL   ~(1 << 2)
#else
#define  MG87_13PL   0xFFFF
#endif
#if (G84PL >= G87PL) || (G84PL == 0)
#define  MG87_14PL   ~(1 << 3)
#else
#define  MG87_14PL   0xFFFF
#endif
#if (G85PL >= G87PL) || (G85PL == 0)
#define  MG87_15PL   ~(1 << 4)
#else
#define  MG87_15PL   0xFFFF
#endif
#if (G86PL >= G87PL) || (G86PL == 0)
#define  MG87_16PL   ~(1 << 5)
#else
#define  MG87_16PL   0xFFFF
#endif
#if (G88PL >= G87PL) || (G88PL == 0)
#define  MG87_18PL   ~(1 << 7)
#else
#define  MG87_18PL   0xFFFF
#endif
#define  MG87_17PL   0x00BF
#define  MG87    (MG87_11PL & MG87_12PL & MG87_13PL & MG87_14PL & \
                  MG87_15PL & MG87_16PL & MG87_17PL & MG87_18PL)
// End of MG87:

// Beginning of MG88:
#if (G81PL >= G88PL) || (G81PL == 0)
#define  MG88_11PL   ~(1)
#else
#define  MG88_11PL   0xFFFF
#endif
#if (G82PL >= G88PL) || (G82PL == 0)
#define  MG88_12PL   ~(1 << 1)
#else
#define  MG88_12PL   0xFFFF
#endif
#if (G83PL >= G88PL) || (G83PL == 0)
#define  MG88_13PL   ~(1 << 2)
#else
#define  MG88_13PL   0xFFFF
#endif
#if (G84PL >= G88PL) || (G84PL == 0)
#define  MG88_14PL   ~(1 << 3)
#else
#define  MG88_14PL   0xFFFF
#endif
#if (G85PL >= G88PL) || (G85PL == 0)
#define  MG88_15PL   ~(1 << 4)
#else
#define  MG88_15PL   0xFFFF
#endif
#if (G86PL >= G88PL) || (G86PL == 0)
#define  MG88_16PL   ~(1 << 5)
#else
#define  MG88_16PL   0xFFFF
#endif
#if (G87PL >= G88PL) || (G87PL == 0)
#define  MG88_17PL   ~(1 << 6)
#else
#define  MG88_17PL   0xFFFF
#endif
#define  MG88_18PL   0x007F
#define  MG88    (MG88_11PL & MG88_12PL & MG88_13PL & MG88_14PL & \
                  MG88_15PL & MG88_16PL & MG88_17PL & MG88_18PL)
// End of MG88:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG91 to MG98:
//

// Beginning of MG91:
#if (G92PL >= G91PL) || (G92PL == 0)
#define  MG91_12PL   ~(1 << 1)
#else
#define  MG91_12PL   0xFFFF
#endif
#if (G93PL >= G91PL) || (G93PL == 0)
#define  MG91_13PL   ~(1 << 2)
#else
#define  MG91_13PL   0xFFFF
#endif
#if (G94PL >= G91PL) || (G94PL == 0)
#define  MG91_14PL   ~(1 << 3)
#else
#define  MG91_14PL   0xFFFF
#endif
#if (G95PL >= G91PL) || (G95PL == 0)
#define  MG91_15PL   ~(1 << 4)
#else
#define  MG91_15PL   0xFFFF
#endif
#if (G96PL >= G91PL) || (G96PL == 0)
#define  MG91_16PL   ~(1 << 5)
#else
#define  MG91_16PL   0xFFFF
#endif
#if (G97PL >= G91PL) || (G97PL == 0)
#define  MG91_17PL   ~(1 << 6)
#else
#define  MG91_17PL   0xFFFF
#endif
#if (G98PL >= G91PL) || (G98PL == 0)
#define  MG91_18PL   ~(1 << 7)
#else
#define  MG91_18PL   0xFFFF
#endif
#define  MG91_11PL   0x00FE
#define  MG91    (MG91_11PL & MG91_12PL & MG91_13PL & MG91_14PL & \
                  MG91_15PL & MG91_16PL & MG91_17PL & MG91_18PL)
// End of MG91:

// Beginning of MG92:
#if (G91PL >= G92PL) || (G91PL == 0)
#define  MG92_11PL   ~(1)
#else
#define  MG92_11PL   0xFFFF
#endif
#if (G93PL >= G92PL) || (G93PL == 0)
#define  MG92_13PL   ~(1 << 2)
#else
#define  MG92_13PL   0xFFFF
#endif
#if (G94PL >= G92PL) || (G94PL == 0)
#define  MG92_14PL   ~(1 << 3)
#else
#define  MG92_14PL   0xFFFF
#endif
#if (G95PL >= G92PL) || (G95PL == 0)
#define  MG92_15PL   ~(1 << 4)
#else
#define  MG92_15PL   0xFFFF
#endif
#if (G96PL >= G92PL) || (G96PL == 0)
#define  MG92_16PL   ~(1 << 5)
#else
#define  MG92_16PL   0xFFFF
#endif
#if (G97PL >= G92PL) || (G97PL == 0)
#define  MG92_17PL   ~(1 << 6)
#else
#define  MG92_17PL   0xFFFF
#endif
#if (G98PL >= G92PL) || (G98PL == 0)
#define  MG92_18PL   ~(1 << 7)
#else
#define  MG92_18PL   0xFFFF
#endif
#define  MG92_12PL   0x00FD
#define  MG92    (MG92_11PL & MG92_12PL & MG92_13PL & MG92_14PL & \
                  MG92_15PL & MG92_16PL & MG92_17PL & MG92_18PL)
// End of MG92:

// Beginning of MG93:
#if (G91PL >= G93PL) || (G91PL == 0)
#define  MG93_11PL   ~(1)
#else
#define  MG93_11PL   0xFFFF
#endif
#if (G92PL >= G93PL) || (G92PL == 0)
#define  MG93_12PL   ~(1 << 1)
#else
#define  MG93_12PL   0xFFFF
#endif
#if (G94PL >= G93PL) || (G94PL == 0)
#define  MG93_14PL   ~(1 << 3)
#else
#define  MG93_14PL   0xFFFF
#endif
#if (G95PL >= G93PL) || (G95PL == 0)
#define  MG93_15PL   ~(1 << 4)
#else
#define  MG93_15PL   0xFFFF
#endif
#if (G96PL >= G93PL) || (G96PL == 0)
#define  MG93_16PL   ~(1 << 5)
#else
#define  MG93_16PL   0xFFFF
#endif
#if (G97PL >= G93PL) || (G97PL == 0)
#define  MG93_17PL   ~(1 << 6)
#else
#define  MG93_17PL   0xFFFF
#endif
#if (G98PL >= G93PL) || (G98PL == 0)
#define  MG93_18PL   ~(1 << 7)
#else
#define  MG93_18PL   0xFFFF
#endif
#define  MG93_13PL   0x00FB
#define  MG93    (MG93_11PL & MG93_12PL & MG93_13PL & MG93_14PL & \
                  MG93_15PL & MG93_16PL & MG93_17PL & MG93_18PL)
// End of MG93:

// Beginning of MG94:
#if (G91PL >= G94PL) || (G91PL == 0)
#define  MG94_11PL   ~(1)
#else
#define  MG94_11PL   0xFFFF
#endif
#if (G92PL >= G94PL) || (G92PL == 0)
#define  MG94_12PL   ~(1 << 1)
#else
#define  MG94_12PL   0xFFFF
#endif
#if (G93PL >= G94PL) || (G93PL == 0)
#define  MG94_13PL   ~(1 << 2)
#else
#define  MG94_13PL   0xFFFF
#endif
#if (G95PL >= G94PL) || (G95PL == 0)
#define  MG94_15PL   ~(1 << 4)
#else
#define  MG94_15PL   0xFFFF
#endif
#if (G96PL >= G94PL) || (G96PL == 0)
#define  MG94_16PL   ~(1 << 5)
#else
#define  MG94_16PL   0xFFFF
#endif
#if (G97PL >= G94PL) || (G97PL == 0)
#define  MG94_17PL   ~(1 << 6)
#else
#define  MG94_17PL   0xFFFF
#endif
#if (G98PL >= G94PL) || (G98PL == 0)
#define  MG94_18PL   ~(1 << 7)
#else
#define  MG94_18PL   0xFFFF
#endif
#define  MG94_14PL   0x00F7
#define  MG94    (MG94_11PL & MG94_12PL & MG94_13PL & MG94_14PL & \
                  MG94_15PL & MG94_16PL & MG94_17PL & MG94_18PL)
// End of MG94:

// Beginning of MG95:
#if (G91PL >= G95PL) || (G91PL == 0)
#define  MG95_11PL   ~(1)
#else
#define  MG95_11PL   0xFFFF
#endif
#if (G92PL >= G95PL) || (G92PL == 0)
#define  MG95_12PL   ~(1 << 1)
#else
#define  MG95_12PL   0xFFFF
#endif
#if (G93PL >= G95PL) || (G93PL == 0)
#define  MG95_13PL   ~(1 << 2)
#else
#define  MG95_13PL   0xFFFF
#endif
#if (G94PL >= G95PL) || (G94PL == 0)
#define  MG95_14PL   ~(1 << 3)
#else
#define  MG95_14PL   0xFFFF
#endif
#if (G96PL >= G95PL) || (G96PL == 0)
#define  MG95_16PL   ~(1 << 5)
#else
#define  MG95_16PL   0xFFFF
#endif
#if (G97PL >= G95PL) || (G97PL == 0)
#define  MG95_17PL   ~(1 << 6)
#else
#define  MG95_17PL   0xFFFF
#endif
#if (G98PL >= G95PL) || (G98PL == 0)
#define  MG95_18PL   ~(1 << 7)
#else
#define  MG95_18PL   0xFFFF
#endif
#define  MG95_15PL   0x00EF
#define  MG95    (MG95_11PL & MG95_12PL & MG95_13PL & MG95_14PL & \
                  MG95_15PL & MG95_16PL & MG95_17PL & MG95_18PL)
// End of MG95:

// Beginning of MG96:
#if (G91PL >= G96PL) || (G91PL == 0)
#define  MG96_11PL   ~(1)
#else
#define  MG96_11PL   0xFFFF
#endif
#if (G92PL >= G96PL) || (G92PL == 0)
#define  MG96_12PL   ~(1 << 1)
#else
#define  MG96_12PL   0xFFFF
#endif
#if (G93PL >= G96PL) || (G93PL == 0)
#define  MG96_13PL   ~(1 << 2)
#else
#define  MG96_13PL   0xFFFF
#endif
#if (G94PL >= G96PL) || (G94PL == 0)
#define  MG96_14PL   ~(1 << 3)
#else
#define  MG96_14PL   0xFFFF
#endif
#if (G95PL >= G96PL) || (G95PL == 0)
#define  MG96_15PL   ~(1 << 4)
#else
#define  MG96_15PL   0xFFFF
#endif
#if (G97PL >= G96PL) || (G97PL == 0)
#define  MG96_17PL   ~(1 << 6)
#else
#define  MG96_17PL   0xFFFF
#endif
#if (G98PL >= G96PL) || (G98PL == 0)
#define  MG96_18PL   ~(1 << 7)
#else
#define  MG96_18PL   0xFFFF
#endif
#define  MG96_16PL   0x00DF
#define  MG96    (MG96_11PL & MG96_12PL & MG96_13PL & MG96_14PL & \
                  MG96_15PL & MG96_16PL & MG96_17PL & MG96_18PL)
// End of MG96:

// Beginning of MG97:
#if (G91PL >= G97PL) || (G91PL == 0)
#define  MG97_11PL   ~(1)
#else
#define  MG97_11PL   0xFFFF
#endif
#if (G92PL >= G97PL) || (G92PL == 0)
#define  MG97_12PL   ~(1 << 1)
#else
#define  MG97_12PL   0xFFFF
#endif
#if (G93PL >= G97PL) || (G93PL == 0)
#define  MG97_13PL   ~(1 << 2)
#else
#define  MG97_13PL   0xFFFF
#endif
#if (G94PL >= G97PL) || (G94PL == 0)
#define  MG97_14PL   ~(1 << 3)
#else
#define  MG97_14PL   0xFFFF
#endif
#if (G95PL >= G97PL) || (G95PL == 0)
#define  MG97_15PL   ~(1 << 4)
#else
#define  MG97_15PL   0xFFFF
#endif
#if (G96PL >= G97PL) || (G96PL == 0)
#define  MG97_16PL   ~(1 << 5)
#else
#define  MG97_16PL   0xFFFF
#endif
#if (G98PL >= G97PL) || (G98PL == 0)
#define  MG97_18PL   ~(1 << 7)
#else
#define  MG97_18PL   0xFFFF
#endif
#define  MG97_17PL   0x00BF
#define  MG97    (MG97_11PL & MG97_12PL & MG97_13PL & MG97_14PL & \
                  MG97_15PL & MG97_16PL & MG97_17PL & MG97_18PL)
// End of MG97:

// Beginning of MG98:
#if (G91PL >= G98PL) || (G91PL == 0)
#define  MG98_11PL   ~(1)
#else
#define  MG98_11PL   0xFFFF
#endif
#if (G92PL >= G98PL) || (G92PL == 0)
#define  MG98_12PL   ~(1 << 1)
#else
#define  MG98_12PL   0xFFFF
#endif
#if (G93PL >= G98PL) || (G93PL == 0)
#define  MG98_13PL   ~(1 << 2)
#else
#define  MG98_13PL   0xFFFF
#endif
#if (G94PL >= G98PL) || (G94PL == 0)
#define  MG98_14PL   ~(1 << 3)
#else
#define  MG98_14PL   0xFFFF
#endif
#if (G95PL >= G98PL) || (G95PL == 0)
#define  MG98_15PL   ~(1 << 4)
#else
#define  MG98_15PL   0xFFFF
#endif
#if (G96PL >= G98PL) || (G96PL == 0)
#define  MG98_16PL   ~(1 << 5)
#else
#define  MG98_16PL   0xFFFF
#endif
#if (G97PL >= G98PL) || (G97PL == 0)
#define  MG98_17PL   ~(1 << 6)
#else
#define  MG98_17PL   0xFFFF
#endif
#define  MG98_18PL   0x007F
#define  MG98    (MG98_11PL & MG98_12PL & MG98_13PL & MG98_14PL & \
                  MG98_15PL & MG98_16PL & MG98_17PL & MG98_18PL)
// End of MG98:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG101 to MG108:
//

// Beginning of MG101:
#if (G102PL >= G101PL) || (G102PL == 0)
#define  MG101_12PL   ~(1 << 1)
#else
#define  MG101_12PL   0xFFFF
#endif
#if (G103PL >= G101PL) || (G103PL == 0)
#define  MG101_13PL   ~(1 << 2)
#else
#define  MG101_13PL   0xFFFF
#endif
#if (G104PL >= G101PL) || (G104PL == 0)
#define  MG101_14PL   ~(1 << 3)
#else
#define  MG101_14PL   0xFFFF
#endif
#if (G105PL >= G101PL) || (G105PL == 0)
#define  MG101_15PL   ~(1 << 4)
#else
#define  MG101_15PL   0xFFFF
#endif
#if (G106PL >= G101PL) || (G106PL == 0)
#define  MG101_16PL   ~(1 << 5)
#else
#define  MG101_16PL   0xFFFF
#endif
#if (G107PL >= G101PL) || (G107PL == 0)
#define  MG101_17PL   ~(1 << 6)
#else
#define  MG101_17PL   0xFFFF
#endif
#if (G108PL >= G101PL) || (G108PL == 0)
#define  MG101_18PL   ~(1 << 7)
#else
#define  MG101_18PL   0xFFFF
#endif
#define  MG101_11PL   0x00FE
#define  MG101   (MG101_11PL & MG101_12PL & MG101_13PL & MG101_14PL & \
                  MG101_15PL & MG101_16PL & MG101_17PL & MG101_18PL)
// End of MG101:

// Beginning of MG102:
#if (G101PL >= G102PL) || (G101PL == 0)
#define  MG102_11PL   ~(1)
#else
#define  MG102_11PL   0xFFFF
#endif
#if (G103PL >= G102PL) || (G103PL == 0)
#define  MG102_13PL   ~(1 << 2)
#else
#define  MG102_13PL   0xFFFF
#endif
#if (G104PL >= G102PL) || (G104PL == 0)
#define  MG102_14PL   ~(1 << 3)
#else
#define  MG102_14PL   0xFFFF
#endif
#if (G105PL >= G102PL) || (G105PL == 0)
#define  MG102_15PL   ~(1 << 4)
#else
#define  MG102_15PL   0xFFFF
#endif
#if (G106PL >= G102PL) || (G106PL == 0)
#define  MG102_16PL   ~(1 << 5)
#else
#define  MG102_16PL   0xFFFF
#endif
#if (G107PL >= G102PL) || (G107PL == 0)
#define  MG102_17PL   ~(1 << 6)
#else
#define  MG102_17PL   0xFFFF
#endif
#if (G108PL >= G102PL) || (G108PL == 0)
#define  MG102_18PL   ~(1 << 7)
#else
#define  MG102_18PL   0xFFFF
#endif
#define  MG102_12PL   0x00FD
#define  MG102   (MG102_11PL & MG102_12PL & MG102_13PL & MG102_14PL & \
                  MG102_15PL & MG102_16PL & MG102_17PL & MG102_18PL)
// End of MG102:

// Beginning of MG103:
#if (G101PL >= G103PL) || (G101PL == 0)
#define  MG103_11PL   ~(1)
#else
#define  MG103_11PL   0xFFFF
#endif
#if (G102PL >= G103PL) || (G102PL == 0)
#define  MG103_12PL   ~(1 << 1)
#else
#define  MG103_12PL   0xFFFF
#endif
#if (G104PL >= G103PL) || (G104PL == 0)
#define  MG103_14PL   ~(1 << 3)
#else
#define  MG103_14PL   0xFFFF
#endif
#if (G105PL >= G103PL) || (G105PL == 0)
#define  MG103_15PL   ~(1 << 4)
#else
#define  MG103_15PL   0xFFFF
#endif
#if (G106PL >= G103PL) || (G106PL == 0)
#define  MG103_16PL   ~(1 << 5)
#else
#define  MG103_16PL   0xFFFF
#endif
#if (G107PL >= G103PL) || (G107PL == 0)
#define  MG103_17PL   ~(1 << 6)
#else
#define  MG103_17PL   0xFFFF
#endif
#if (G108PL >= G103PL) || (G108PL == 0)
#define  MG103_18PL   ~(1 << 7)
#else
#define  MG103_18PL   0xFFFF
#endif
#define  MG103_13PL   0x00FB
#define  MG103    (MG103_11PL & MG103_12PL & MG103_13PL & MG103_14PL & \
                  MG103_15PL & MG103_16PL & MG103_17PL & MG103_18PL)
// End of MG103:

// Beginning of MG104:
#if (G101PL >= G104PL) || (G101PL == 0)
#define  MG104_11PL   ~(1)
#else
#define  MG104_11PL   0xFFFF
#endif
#if (G102PL >= G104PL) || (G102PL == 0)
#define  MG104_12PL   ~(1 << 1)
#else
#define  MG104_12PL   0xFFFF
#endif
#if (G103PL >= G104PL) || (G103PL == 0)
#define  MG104_13PL   ~(1 << 2)
#else
#define  MG104_13PL   0xFFFF
#endif
#if (G105PL >= G104PL) || (G105PL == 0)
#define  MG104_15PL   ~(1 << 4)
#else
#define  MG104_15PL   0xFFFF
#endif
#if (G106PL >= G104PL) || (G106PL == 0)
#define  MG104_16PL   ~(1 << 5)
#else
#define  MG104_16PL   0xFFFF
#endif
#if (G107PL >= G104PL) || (G107PL == 0)
#define  MG104_17PL   ~(1 << 6)
#else
#define  MG104_17PL   0xFFFF
#endif
#if (G108PL >= G104PL) || (G108PL == 0)
#define  MG104_18PL   ~(1 << 7)
#else
#define  MG104_18PL   0xFFFF
#endif
#define  MG104_14PL   0x00F7
#define  MG104   (MG104_11PL & MG104_12PL & MG104_13PL & MG104_14PL & \
                  MG104_15PL & MG104_16PL & MG104_17PL & MG104_18PL)
// End of MG104:

// Beginning of MG105:
#if (G101PL >= G105PL) || (G101PL == 0)
#define  MG105_11PL   ~(1)
#else
#define  MG105_11PL   0xFFFF
#endif
#if (G102PL >= G105PL) || (G102PL == 0)
#define  MG105_12PL   ~(1 << 1)
#else
#define  MG105_12PL   0xFFFF
#endif
#if (G103PL >= G105PL) || (G103PL == 0)
#define  MG105_13PL   ~(1 << 2)
#else
#define  MG105_13PL   0xFFFF
#endif
#if (G104PL >= G105PL) || (G104PL == 0)
#define  MG105_14PL   ~(1 << 3)
#else
#define  MG105_14PL   0xFFFF
#endif
#if (G106PL >= G105PL) || (G106PL == 0)
#define  MG105_16PL   ~(1 << 5)
#else
#define  MG105_16PL   0xFFFF
#endif
#if (G107PL >= G105PL) || (G107PL == 0)
#define  MG105_17PL   ~(1 << 6)
#else
#define  MG105_17PL   0xFFFF
#endif
#if (G108PL >= G105PL) || (G108PL == 0)
#define  MG105_18PL   ~(1 << 7)
#else
#define  MG105_18PL   0xFFFF
#endif
#define  MG105_15PL   0x00EF
#define  MG105   (MG105_11PL & MG105_12PL & MG105_13PL & MG105_14PL & \
                  MG105_15PL & MG105_16PL & MG105_17PL & MG105_18PL)
// End of MG105:

// Beginning of MG106:
#if (G101PL >= G106PL) || (G101PL == 0)
#define  MG106_11PL   ~(1)
#else
#define  MG106_11PL   0xFFFF
#endif
#if (G102PL >= G106PL) || (G102PL == 0)
#define  MG106_12PL   ~(1 << 1)
#else
#define  MG106_12PL   0xFFFF
#endif
#if (G103PL >= G106PL) || (G103PL == 0)
#define  MG106_13PL   ~(1 << 2)
#else
#define  MG106_13PL   0xFFFF
#endif
#if (G104PL >= G106PL) || (G104PL == 0)
#define  MG106_14PL   ~(1 << 3)
#else
#define  MG106_14PL   0xFFFF
#endif
#if (G105PL >= G106PL) || (G105PL == 0)
#define  MG106_15PL   ~(1 << 4)
#else
#define  MG106_15PL   0xFFFF
#endif
#if (G107PL >= G106PL) || (G107PL == 0)
#define  MG106_17PL   ~(1 << 6)
#else
#define  MG106_17PL   0xFFFF
#endif
#if (G108PL >= G106PL) || (G108PL == 0)
#define  MG106_18PL   ~(1 << 7)
#else
#define  MG106_18PL   0xFFFF
#endif
#define  MG106_16PL   0x00DF
#define  MG106   (MG106_11PL & MG106_12PL & MG106_13PL & MG106_14PL & \
                  MG106_15PL & MG106_16PL & MG106_17PL & MG106_18PL)
// End of MG106:

// Beginning of MG107:
#if (G101PL >= G107PL) || (G101PL == 0)
#define  MG107_11PL   ~(1)
#else
#define  MG107_11PL   0xFFFF
#endif
#if (G102PL >= G107PL) || (G102PL == 0)
#define  MG107_12PL   ~(1 << 1)
#else
#define  MG107_12PL   0xFFFF
#endif
#if (G103PL >= G107PL) || (G103PL == 0)
#define  MG107_13PL   ~(1 << 2)
#else
#define  MG107_13PL   0xFFFF
#endif
#if (G104PL >= G107PL) || (G104PL == 0)
#define  MG107_14PL   ~(1 << 3)
#else
#define  MG107_14PL   0xFFFF
#endif
#if (G105PL >= G107PL) || (G105PL == 0)
#define  MG107_15PL   ~(1 << 4)
#else
#define  MG107_15PL   0xFFFF
#endif
#if (G106PL >= G107PL) || (G106PL == 0)
#define  MG107_16PL   ~(1 << 5)
#else
#define  MG107_16PL   0xFFFF
#endif
#if (G108PL >= G107PL) || (G108PL == 0)
#define  MG107_18PL   ~(1 << 7)
#else
#define  MG107_18PL   0xFFFF
#endif
#define  MG107_17PL   0x00BF
#define  MG107   (MG107_11PL & MG107_12PL & MG107_13PL & MG107_14PL & \
                  MG107_15PL & MG107_16PL & MG107_17PL & MG107_18PL)
// End of MG107:

// Beginning of MG108:
#if (G101PL >= G108PL) || (G101PL == 0)
#define  MG108_11PL   ~(1)
#else
#define  MG108_11PL   0xFFFF
#endif
#if (G102PL >= G108PL) || (G102PL == 0)
#define  MG108_12PL   ~(1 << 1)
#else
#define  MG108_12PL   0xFFFF
#endif
#if (G103PL >= G108PL) || (G103PL == 0)
#define  MG108_13PL   ~(1 << 2)
#else
#define  MG108_13PL   0xFFFF
#endif
#if (G104PL >= G108PL) || (G104PL == 0)
#define  MG108_14PL   ~(1 << 3)
#else
#define  MG108_14PL   0xFFFF
#endif
#if (G105PL >= G108PL) || (G105PL == 0)
#define  MG108_15PL   ~(1 << 4)
#else
#define  MG108_15PL   0xFFFF
#endif
#if (G106PL >= G108PL) || (G106PL == 0)
#define  MG108_16PL   ~(1 << 5)
#else
#define  MG108_16PL   0xFFFF
#endif
#if (G107PL >= G108PL) || (G107PL == 0)
#define  MG108_17PL   ~(1 << 6)
#else
#define  MG108_17PL   0xFFFF
#endif
#define  MG108_18PL   0x007F
#define  MG108    (MG108_11PL & MG108_12PL & MG108_13PL & MG108_14PL & \
                  MG108_15PL & MG108_16PL & MG108_17PL & MG108_18PL)
// End of MG108:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG111 to MG118:
//

// Beginning of MG111:
#if (G112PL >= G111PL) || (G112PL == 0)
#define  MG111_12PL   ~(1 << 1)
#else
#define  MG111_12PL   0xFFFF
#endif
#if (G113PL >= G111PL) || (G113PL == 0)
#define  MG111_13PL   ~(1 << 2)
#else
#define  MG111_13PL   0xFFFF
#endif
#if (G114PL >= G111PL) || (G114PL == 0)
#define  MG111_14PL   ~(1 << 3)
#else
#define  MG111_14PL   0xFFFF
#endif
#if (G115PL >= G111PL) || (G115PL == 0)
#define  MG111_15PL   ~(1 << 4)
#else
#define  MG111_15PL   0xFFFF
#endif
#if (G116PL >= G111PL) || (G116PL == 0)
#define  MG111_16PL   ~(1 << 5)
#else
#define  MG111_16PL   0xFFFF
#endif
#if (G117PL >= G111PL) || (G117PL == 0)
#define  MG111_17PL   ~(1 << 6)
#else
#define  MG111_17PL   0xFFFF
#endif
#if (G118PL >= G111PL) || (G118PL == 0)
#define  MG111_18PL   ~(1 << 7)
#else
#define  MG111_18PL   0xFFFF
#endif
#define  MG111_11PL   0x00FE
#define  MG111   (MG111_11PL & MG111_12PL & MG111_13PL & MG111_14PL & \
                  MG111_15PL & MG111_16PL & MG111_17PL & MG111_18PL)
// End of MG111:

// Beginning of MG112:
#if (G111PL >= G112PL) || (G111PL == 0)
#define  MG112_11PL   ~(1)
#else
#define  MG112_11PL   0xFFFF
#endif
#if (G113PL >= G112PL) || (G113PL == 0)
#define  MG112_13PL   ~(1 << 2)
#else
#define  MG112_13PL   0xFFFF
#endif
#if (G114PL >= G112PL) || (G114PL == 0)
#define  MG112_14PL   ~(1 << 3)
#else
#define  MG112_14PL   0xFFFF
#endif
#if (G115PL >= G112PL) || (G115PL == 0)
#define  MG112_15PL   ~(1 << 4)
#else
#define  MG112_15PL   0xFFFF
#endif
#if (G116PL >= G112PL) || (G116PL == 0)
#define  MG112_16PL   ~(1 << 5)
#else
#define  MG112_16PL   0xFFFF
#endif
#if (G117PL >= G112PL) || (G117PL == 0)
#define  MG112_17PL   ~(1 << 6)
#else
#define  MG112_17PL   0xFFFF
#endif
#if (G118PL >= G112PL) || (G118PL == 0)
#define  MG112_18PL   ~(1 << 7)
#else
#define  MG112_18PL   0xFFFF
#endif
#define  MG112_12PL   0x00FD
#define  MG112   (MG112_11PL & MG112_12PL & MG112_13PL & MG112_14PL & \
                  MG112_15PL & MG112_16PL & MG112_17PL & MG112_18PL)
// End of MG112:

// Beginning of MG113:
#if (G111PL >= G113PL) || (G111PL == 0)
#define  MG113_11PL   ~(1)
#else
#define  MG113_11PL   0xFFFF
#endif
#if (G112PL >= G113PL) || (G112PL == 0)
#define  MG113_12PL   ~(1 << 1)
#else
#define  MG113_12PL   0xFFFF
#endif
#if (G114PL >= G113PL) || (G114PL == 0)
#define  MG113_14PL   ~(1 << 3)
#else
#define  MG113_14PL   0xFFFF
#endif
#if (G115PL >= G113PL) || (G115PL == 0)
#define  MG113_15PL   ~(1 << 4)
#else
#define  MG113_15PL   0xFFFF
#endif
#if (G116PL >= G113PL) || (G116PL == 0)
#define  MG113_16PL   ~(1 << 5)
#else
#define  MG113_16PL   0xFFFF
#endif
#if (G117PL >= G113PL) || (G117PL == 0)
#define  MG113_17PL   ~(1 << 6)
#else
#define  MG113_17PL   0xFFFF
#endif
#if (G118PL >= G113PL) || (G118PL == 0)
#define  MG113_18PL   ~(1 << 7)
#else
#define  MG113_18PL   0xFFFF
#endif
#define  MG113_13PL   0x00FB
#define  MG113   (MG113_11PL & MG113_12PL & MG113_13PL & MG113_14PL & \
                  MG113_15PL & MG113_16PL & MG113_17PL & MG113_18PL)
// End of MG113:

// Beginning of MG114:
#if (G111PL >= G114PL) || (G111PL == 0)
#define  MG114_11PL   ~(1)
#else
#define  MG114_11PL   0xFFFF
#endif
#if (G112PL >= G114PL) || (G112PL == 0)
#define  MG114_12PL   ~(1 << 1)
#else
#define  MG114_12PL   0xFFFF
#endif
#if (G113PL >= G114PL) || (G113PL == 0)
#define  MG114_13PL   ~(1 << 2)
#else
#define  MG114_13PL   0xFFFF
#endif
#if (G115PL >= G114PL) || (G115PL == 0)
#define  MG114_15PL   ~(1 << 4)
#else
#define  MG114_15PL   0xFFFF
#endif
#if (G116PL >= G114PL) || (G116PL == 0)
#define  MG114_16PL   ~(1 << 5)
#else
#define  MG114_16PL   0xFFFF
#endif
#if (G117PL >= G114PL) || (G117PL == 0)
#define  MG114_17PL   ~(1 << 6)
#else
#define  MG114_17PL   0xFFFF
#endif
#if (G118PL >= G114PL) || (G118PL == 0)
#define  MG114_18PL   ~(1 << 7)
#else
#define  MG114_18PL   0xFFFF
#endif
#define  MG114_14PL   0x00F7
#define  MG114   (MG114_11PL & MG114_12PL & MG114_13PL & MG114_14PL & \
                  MG114_15PL & MG114_16PL & MG114_17PL & MG114_18PL)
// End of MG114:

// Beginning of MG115:
#if (G111PL >= G115PL) || (G111PL == 0)
#define  MG115_11PL   ~(1)
#else
#define  MG115_11PL   0xFFFF
#endif
#if (G112PL >= G115PL) || (G112PL == 0)
#define  MG115_12PL   ~(1 << 1)
#else
#define  MG115_12PL   0xFFFF
#endif
#if (G113PL >= G115PL) || (G113PL == 0)
#define  MG115_13PL   ~(1 << 2)
#else
#define  MG115_13PL   0xFFFF
#endif
#if (G114PL >= G115PL) || (G114PL == 0)
#define  MG115_14PL   ~(1 << 3)
#else
#define  MG115_14PL   0xFFFF
#endif
#if (G116PL >= G115PL) || (G116PL == 0)
#define  MG115_16PL   ~(1 << 5)
#else
#define  MG115_16PL   0xFFFF
#endif
#if (G117PL >= G115PL) || (G117PL == 0)
#define  MG115_17PL   ~(1 << 6)
#else
#define  MG115_17PL   0xFFFF
#endif
#if (G118PL >= G115PL) || (G118PL == 0)
#define  MG115_18PL   ~(1 << 7)
#else
#define  MG115_18PL   0xFFFF
#endif
#define  MG115_15PL   0x00EF
#define  MG115    (MG115_11PL & MG115_12PL & MG115_13PL & MG115_14PL & \
                  MG115_15PL & MG115_16PL & MG115_17PL & MG115_18PL)
// End of MG115:

// Beginning of MG116:
#if (G111PL >= G116PL) || (G111PL == 0)
#define  MG116_11PL   ~(1)
#else
#define  MG116_11PL   0xFFFF
#endif
#if (G112PL >= G116PL) || (G112PL == 0)
#define  MG116_12PL   ~(1 << 1)
#else
#define  MG116_12PL   0xFFFF
#endif
#if (G113PL >= G116PL) || (G113PL == 0)
#define  MG116_13PL   ~(1 << 2)
#else
#define  MG116_13PL   0xFFFF
#endif
#if (G114PL >= G116PL) || (G114PL == 0)
#define  MG116_14PL   ~(1 << 3)
#else
#define  MG116_14PL   0xFFFF
#endif
#if (G115PL >= G116PL) || (G115PL == 0)
#define  MG116_15PL   ~(1 << 4)
#else
#define  MG116_15PL   0xFFFF
#endif
#if (G117PL >= G116PL) || (G117PL == 0)
#define  MG116_17PL   ~(1 << 6)
#else
#define  MG116_17PL   0xFFFF
#endif
#if (G118PL >= G116PL) || (G118PL == 0)
#define  MG116_18PL   ~(1 << 7)
#else
#define  MG116_18PL   0xFFFF
#endif
#define  MG116_16PL   0x00DF
#define  MG116   (MG116_11PL & MG116_12PL & MG116_13PL & MG116_14PL & \
                  MG116_15PL & MG116_16PL & MG116_17PL & MG116_18PL)
// End of MG116:

// Beginning of MG117:
#if (G111PL >= G117PL) || (G111PL == 0)
#define  MG117_11PL   ~(1)
#else
#define  MG117_11PL   0xFFFF
#endif
#if (G112PL >= G117PL) || (G112PL == 0)
#define  MG117_12PL   ~(1 << 1)
#else
#define  MG117_12PL   0xFFFF
#endif
#if (G113PL >= G117PL) || (G113PL == 0)
#define  MG117_13PL   ~(1 << 2)
#else
#define  MG117_13PL   0xFFFF
#endif
#if (G114PL >= G117PL) || (G114PL == 0)
#define  MG117_14PL   ~(1 << 3)
#else
#define  MG117_14PL   0xFFFF
#endif
#if (G115PL >= G117PL) || (G115PL == 0)
#define  MG117_15PL   ~(1 << 4)
#else
#define  MG117_15PL   0xFFFF
#endif
#if (G116PL >= G117PL) || (G116PL == 0)
#define  MG117_16PL   ~(1 << 5)
#else
#define  MG117_16PL   0xFFFF
#endif
#if (G118PL >= G117PL) || (G118PL == 0)
#define  MG117_18PL   ~(1 << 7)
#else
#define  MG117_18PL   0xFFFF
#endif
#define  MG117_17PL   0x00BF
#define  MG117   (MG117_11PL & MG117_12PL & MG117_13PL & MG117_14PL & \
                  MG117_15PL & MG117_16PL & MG117_17PL & MG117_18PL)
// End of MG117:

// Beginning of MG118:
#if (G111PL >= G118PL) || (G111PL == 0)
#define  MG118_11PL   ~(1)
#else
#define  MG118_11PL   0xFFFF
#endif
#if (G112PL >= G118PL) || (G112PL == 0)
#define  MG118_12PL   ~(1 << 1)
#else
#define  MG118_12PL   0xFFFF
#endif
#if (G113PL >= G118PL) || (G113PL == 0)
#define  MG118_13PL   ~(1 << 2)
#else
#define  MG118_13PL   0xFFFF
#endif
#if (G114PL >= G118PL) || (G114PL == 0)
#define  MG118_14PL   ~(1 << 3)
#else
#define  MG118_14PL   0xFFFF
#endif
#if (G115PL >= G118PL) || (G115PL == 0)
#define  MG118_15PL   ~(1 << 4)
#else
#define  MG118_15PL   0xFFFF
#endif
#if (G116PL >= G118PL) || (G116PL == 0)
#define  MG118_16PL   ~(1 << 5)
#else
#define  MG118_16PL   0xFFFF
#endif
#if (G117PL >= G118PL) || (G117PL == 0)
#define  MG118_17PL   ~(1 << 6)
#else
#define  MG118_17PL   0xFFFF
#endif
#define  MG118_18PL   0x007F
#define  MG118   (MG118_11PL & MG118_12PL & MG118_13PL & MG118_14PL & \
                  MG118_15PL & MG118_16PL & MG118_17PL & MG118_18PL)
// End of MG118:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG121 to MG128:
//

// Beginning of MG121:
#if (G122PL >= G121PL) || (G122PL == 0)
#define  MG121_12PL   ~(1 << 1)
#else
#define  MG121_12PL   0xFFFF
#endif
#if (G123PL >= G121PL) || (G123PL == 0)
#define  MG121_13PL   ~(1 << 2)
#else
#define  MG121_13PL   0xFFFF
#endif
#if (G124PL >= G121PL) || (G124PL == 0)
#define  MG121_14PL   ~(1 << 3)
#else
#define  MG121_14PL   0xFFFF
#endif
#if (G125PL >= G121PL) || (G125PL == 0)
#define  MG121_15PL   ~(1 << 4)
#else
#define  MG121_15PL   0xFFFF
#endif
#if (G126PL >= G121PL) || (G126PL == 0)
#define  MG121_16PL   ~(1 << 5)
#else
#define  MG121_16PL   0xFFFF
#endif
#if (G127PL >= G121PL) || (G127PL == 0)
#define  MG121_17PL   ~(1 << 6)
#else
#define  MG121_17PL   0xFFFF
#endif
#if (G128PL >= G121PL) || (G128PL == 0)
#define  MG121_18PL   ~(1 << 7)
#else
#define  MG121_18PL   0xFFFF
#endif
#define  MG121_11PL   0x00FE
#define  MG121   (MG121_11PL & MG121_12PL & MG121_13PL & MG121_14PL & \
                  MG121_15PL & MG121_16PL & MG121_17PL & MG121_18PL)
// End of MG121:

// Beginning of MG121:
#if (G121PL >= G122PL) || (G121PL == 0)
#define  MG122_11PL   ~(1)
#else
#define  MG122_11PL   0xFFFF
#endif
#if (G123PL >= G122PL) || (G123PL == 0)
#define  MG122_13PL   ~(1 << 2)
#else
#define  MG122_13PL   0xFFFF
#endif
#if (G124PL >= G122PL) || (G124PL == 0)
#define  MG122_14PL   ~(1 << 3)
#else
#define  MG122_14PL   0xFFFF
#endif
#if (G125PL >= G122PL) || (G125PL == 0)
#define  MG122_15PL   ~(1 << 4)
#else
#define  MG122_15PL   0xFFFF
#endif
#if (G126PL >= G122PL) || (G126PL == 0)
#define  MG122_16PL   ~(1 << 5)
#else
#define  MG122_16PL   0xFFFF
#endif
#if (G127PL >= G122PL) || (G127PL == 0)
#define  MG122_17PL   ~(1 << 6)
#else
#define  MG122_17PL   0xFFFF
#endif
#if (G128PL >= G122PL) || (G128PL == 0)
#define  MG122_18PL   ~(1 << 7)
#else
#define  MG122_18PL   0xFFFF
#endif
#define  MG122_12PL   0x00FD
#define  MG122   (MG122_11PL & MG122_12PL & MG122_13PL & MG122_14PL & \
                  MG122_15PL & MG122_16PL & MG122_17PL & MG122_18PL)
// End of MG122:

// Beginning of MG123:
#if (G121PL >= G123PL) || (G121PL == 0)
#define  MG123_11PL   ~(1)
#else
#define  MG123_11PL   0xFFFF
#endif
#if (G122PL >= G123PL) || (G122PL == 0)
#define  MG123_12PL   ~(1 << 1)
#else
#define  MG123_12PL   0xFFFF
#endif
#if (G124PL >= G123PL) || (G124PL == 0)
#define  MG123_14PL   ~(1 << 3)
#else
#define  MG123_14PL   0xFFFF
#endif
#if (G125PL >= G123PL) || (G125PL == 0)
#define  MG123_15PL   ~(1 << 4)
#else
#define  MG123_15PL   0xFFFF
#endif
#if (G126PL >= G123PL) || (G126PL == 0)
#define  MG123_16PL   ~(1 << 5)
#else
#define  MG123_16PL   0xFFFF
#endif
#if (G127PL >= G123PL) || (G127PL == 0)
#define  MG123_17PL   ~(1 << 6)
#else
#define  MG123_17PL   0xFFFF
#endif
#if (G128PL >= G123PL) || (G128PL == 0)
#define  MG123_18PL   ~(1 << 7)
#else
#define  MG123_18PL   0xFFFF
#endif
#define  MG123_13PL   0x00FB
#define  MG123    (MG123_11PL & MG123_12PL & MG123_13PL & MG123_14PL & \
                  MG123_15PL & MG123_16PL & MG123_17PL & MG123_18PL)
// End of MG123:

// Beginning of MG124:
#if (G121PL >= G124PL) || (G121PL == 0)
#define  MG124_11PL   ~(1)
#else
#define  MG124_11PL   0xFFFF
#endif
#if (G122PL >= G124PL) || (G122PL == 0)
#define  MG124_12PL   ~(1 << 1)
#else
#define  MG124_12PL   0xFFFF
#endif
#if (G123PL >= G124PL) || (G123PL == 0)
#define  MG124_13PL   ~(1 << 2)
#else
#define  MG124_13PL   0xFFFF
#endif
#if (G125PL >= G124PL) || (G125PL == 0)
#define  MG124_15PL   ~(1 << 4)
#else
#define  MG124_15PL   0xFFFF
#endif
#if (G126PL >= G124PL) || (G126PL == 0)
#define  MG124_16PL   ~(1 << 5)
#else
#define  MG124_16PL   0xFFFF
#endif
#if (G127PL >= G124PL) || (G127PL == 0)
#define  MG124_17PL   ~(1 << 6)
#else
#define  MG124_17PL   0xFFFF
#endif
#if (G128PL >= G124PL) || (G128PL == 0)
#define  MG124_18PL   ~(1 << 7)
#else
#define  MG124_18PL   0xFFFF
#endif
#define  MG124_14PL   0x00F7
#define  MG124   (MG124_11PL & MG124_12PL & MG124_13PL & MG124_14PL & \
                  MG124_15PL & MG124_16PL & MG124_17PL & MG124_18PL)
// End of MG124:

// Beginning of MG125:
#if (G121PL >= G125PL) || (G121PL == 0)
#define  MG125_11PL   ~(1)
#else
#define  MG125_11PL   0xFFFF
#endif
#if (G122PL >= G125PL) || (G122PL == 0)
#define  MG125_12PL   ~(1 << 1)
#else
#define  MG125_12PL   0xFFFF
#endif
#if (G123PL >= G125PL) || (G123PL == 0)
#define  MG125_13PL   ~(1 << 2)
#else
#define  MG125_13PL   0xFFFF
#endif
#if (G124PL >= G125PL) || (G124PL == 0)
#define  MG125_14PL   ~(1 << 3)
#else
#define  MG125_14PL   0xFFFF
#endif
#if (G126PL >= G125PL) || (G126PL == 0)
#define  MG125_16PL   ~(1 << 5)
#else
#define  MG125_16PL   0xFFFF
#endif
#if (G127PL >= G125PL) || (G127PL == 0)
#define  MG125_17PL   ~(1 << 6)
#else
#define  MG125_17PL   0xFFFF
#endif
#if (G128PL >= G125PL) || (G128PL == 0)
#define  MG125_18PL   ~(1 << 7)
#else
#define  MG125_18PL   0xFFFF
#endif
#define  MG125_15PL   0x00EF
#define  MG125   (MG125_11PL & MG125_12PL & MG125_13PL & MG125_14PL & \
                  MG125_15PL & MG125_16PL & MG125_17PL & MG125_18PL)
// End of MG125:

// Beginning of MG126:
#if (G121PL >= G126PL) || (G121PL == 0)
#define  MG126_11PL   ~(1)
#else
#define  MG126_11PL   0xFFFF
#endif
#if (G122PL >= G126PL) || (G122PL == 0)
#define  MG126_12PL   ~(1 << 1)
#else
#define  MG126_12PL   0xFFFF
#endif
#if (G123PL >= G126PL) || (G123PL == 0)
#define  MG126_13PL   ~(1 << 2)
#else
#define  MG126_13PL   0xFFFF
#endif
#if (G124PL >= G126PL) || (G124PL == 0)
#define  MG126_14PL   ~(1 << 3)
#else
#define  MG126_14PL   0xFFFF
#endif
#if (G125PL >= G126PL) || (G125PL == 0)
#define  MG126_15PL   ~(1 << 4)
#else
#define  MG126_15PL   0xFFFF
#endif
#if (G127PL >= G126PL) || (G127PL == 0)
#define  MG126_17PL   ~(1 << 6)
#else
#define  MG126_17PL   0xFFFF
#endif
#if (G128PL >= G126PL) || (G128PL == 0)
#define  MG126_18PL   ~(1 << 7)
#else
#define  MG126_18PL   0xFFFF
#endif
#define  MG126_16PL   0x00DF
#define  MG126   (MG126_11PL & MG126_12PL & MG126_13PL & MG126_14PL & \
                  MG126_15PL & MG126_16PL & MG126_17PL & MG126_18PL)
// End of MG126:

// Beginning of MG127:
#if (G121PL >= G127PL) || (G121PL == 0)
#define  MG127_11PL   ~(1)
#else
#define  MG127_11PL   0xFFFF
#endif
#if (G122PL >= G127PL) || (G122PL == 0)
#define  MG127_12PL   ~(1 << 1)
#else
#define  MG127_12PL   0xFFFF
#endif
#if (G123PL >= G127PL) || (G123PL == 0)
#define  MG127_13PL   ~(1 << 2)
#else
#define  MG127_13PL   0xFFFF
#endif
#if (G124PL >= G127PL) || (G124PL == 0)
#define  MG127_14PL   ~(1 << 3)
#else
#define  MG127_14PL   0xFFFF
#endif
#if (G125PL >= G127PL) || (G125PL == 0)
#define  MG127_15PL   ~(1 << 4)
#else
#define  MG127_15PL   0xFFFF
#endif
#if (G126PL >= G127PL) || (G126PL == 0)
#define  MG127_16PL   ~(1 << 5)
#else
#define  MG127_16PL   0xFFFF
#endif
#if (G128PL >= G127PL) || (G128PL == 0)
#define  MG127_18PL   ~(1 << 7)
#else
#define  MG127_18PL   0xFFFF
#endif
#define  MG127_17PL   0x00BF
#define  MG127   (MG127_11PL & MG127_12PL & MG127_13PL & MG127_14PL & \
                  MG127_15PL & MG127_16PL & MG127_17PL & MG127_18PL)
// End of MG127:

// Beginning of MG128:
#if (G121PL >= G128PL) || (G121PL == 0)
#define  MG128_11PL   ~(1)
#else
#define  MG128_11PL   0xFFFF
#endif
#if (G122PL >= G128PL) || (G122PL == 0)
#define  MG128_12PL   ~(1 << 1)
#else
#define  MG128_12PL   0xFFFF
#endif
#if (G123PL >= G128PL) || (G123PL == 0)
#define  MG128_13PL   ~(1 << 2)
#else
#define  MG128_13PL   0xFFFF
#endif
#if (G124PL >= G128PL) || (G124PL == 0)
#define  MG128_14PL   ~(1 << 3)
#else
#define  MG128_14PL   0xFFFF
#endif
#if (G125PL >= G128PL) || (G125PL == 0)
#define  MG128_15PL   ~(1 << 4)
#else
#define  MG128_15PL   0xFFFF
#endif
#if (G126PL >= G128PL) || (G126PL == 0)
#define  MG128_16PL   ~(1 << 5)
#else
#define  MG128_16PL   0xFFFF
#endif
#if (G127PL >= G128PL) || (G127PL == 0)
#define  MG128_17PL   ~(1 << 6)
#else
#define  MG128_17PL   0xFFFF
#endif
#define  MG128_18PL   0x007F
#define  MG128   (MG128_11PL & MG128_12PL & MG128_13PL & MG128_14PL & \
                  MG128_15PL & MG128_16PL & MG128_17PL & MG128_18PL)
// End of MG128:

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif // eof

//===========================================================================
// No more.
//===========================================================================
