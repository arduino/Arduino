//###########################################################################
//
// FILE:   F2806x_ECan.h
//
// TITLE:  F2806x Device eCAN Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_ECAN_H
#define F2806x_ECAN_H


#ifdef __cplusplus
extern "C" {
#endif


/* --------------------------------------------------- */
/* eCAN Control & Status Registers                     */
/* ----------------------------------------------------*/

/* eCAN Mailbox enable register (CANME) bit definitions */
struct  CANME_BITS {      // bit  description
   Uint16      ME0:1;     // 0   Enable Mailbox 0
   Uint16      ME1:1;     // 1   Enable Mailbox 1
   Uint16      ME2:1;     // 2   Enable Mailbox 2
   Uint16      ME3:1;     // 3   Enable Mailbox 3
   Uint16      ME4:1;     // 4   Enable Mailbox 4
   Uint16      ME5:1;     // 5   Enable Mailbox 5
   Uint16      ME6:1;     // 6   Enable Mailbox 6
   Uint16      ME7:1;     // 7   Enable Mailbox 7
   Uint16      ME8:1;     // 8   Enable Mailbox 8
   Uint16      ME9:1;     // 9   Enable Mailbox 9
   Uint16      ME10:1;    // 10  Enable Mailbox 10
   Uint16      ME11:1;    // 11  Enable Mailbox 11
   Uint16      ME12:1;    // 12  Enable Mailbox 12
   Uint16      ME13:1;    // 13  Enable Mailbox 13
   Uint16      ME14:1;    // 14  Enable Mailbox 14
   Uint16      ME15:1;    // 15  Enable Mailbox 15
   Uint16      ME16:1;    // 16  Enable Mailbox 16
   Uint16      ME17:1;    // 17  Enable Mailbox 17
   Uint16      ME18:1;    // 18  Enable Mailbox 18
   Uint16      ME19:1;    // 19  Enable Mailbox 19
   Uint16      ME20:1;    // 20  Enable Mailbox 20
   Uint16      ME21:1;    // 21  Enable Mailbox 21
   Uint16      ME22:1;    // 22  Enable Mailbox 22
   Uint16      ME23:1;    // 23  Enable Mailbox 23
   Uint16      ME24:1;    // 24  Enable Mailbox 24
   Uint16      ME25:1;    // 25  Enable Mailbox 25
   Uint16      ME26:1;    // 26  Enable Mailbox 26
   Uint16      ME27:1;    // 27  Enable Mailbox 27
   Uint16      ME28:1;    // 28  Enable Mailbox 28
   Uint16      ME29:1;    // 29  Enable Mailbox 29
   Uint16      ME30:1;    // 30  Enable Mailbox 30
   Uint16      ME31:1;    // 31  Enable Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANME_REG {
   Uint32             all;
   struct CANME_BITS  bit;
};

/* eCAN Mailbox direction register (CANMD) bit definitions */
struct  CANMD_BITS {      // bit  description
   Uint16      MD0:1;     // 0   0 -> Tx 1 -> Rx
   Uint16      MD1:1;     // 1   0 -> Tx 1 -> Rx
   Uint16      MD2:1;     // 2   0 -> Tx 1 -> Rx
   Uint16      MD3:1;     // 3   0 -> Tx 1 -> Rx
   Uint16      MD4:1;     // 4   0 -> Tx 1 -> Rx
   Uint16      MD5:1;     // 5   0 -> Tx 1 -> Rx
   Uint16      MD6:1;     // 6   0 -> Tx 1 -> Rx
   Uint16      MD7:1;     // 7   0 -> Tx 1 -> Rx
   Uint16      MD8:1;     // 8   0 -> Tx 1 -> Rx
   Uint16      MD9:1;     // 9   0 -> Tx 1 -> Rx
   Uint16      MD10:1;    // 10  0 -> Tx 1 -> Rx
   Uint16      MD11:1;    // 11  0 -> Tx 1 -> Rx
   Uint16      MD12:1;    // 12  0 -> Tx 1 -> Rx
   Uint16      MD13:1;    // 13  0 -> Tx 1 -> Rx
   Uint16      MD14:1;    // 14  0 -> Tx 1 -> Rx
   Uint16      MD15:1;    // 15  0 -> Tx 1 -> Rx
   Uint16      MD16:1;    // 16  0 -> Tx 1 -> Rx
   Uint16      MD17:1;    // 17  0 -> Tx 1 -> Rx
   Uint16      MD18:1;    // 18  0 -> Tx 1 -> Rx
   Uint16      MD19:1;    // 19  0 -> Tx 1 -> Rx
   Uint16      MD20:1;    // 20  0 -> Tx 1 -> Rx
   Uint16      MD21:1;    // 21  0 -> Tx 1 -> Rx
   Uint16      MD22:1;    // 22  0 -> Tx 1 -> Rx
   Uint16      MD23:1;    // 23  0 -> Tx 1 -> Rx
   Uint16      MD24:1;    // 24  0 -> Tx 1 -> Rx
   Uint16      MD25:1;    // 25  0 -> Tx 1 -> Rx
   Uint16      MD26:1;    // 26  0 -> Tx 1 -> Rx
   Uint16      MD27:1;    // 27  0 -> Tx 1 -> Rx
   Uint16      MD28:1;    // 28  0 -> Tx 1 -> Rx
   Uint16      MD29:1;    // 29  0 -> Tx 1 -> Rx
   Uint16      MD30:1;    // 30  0 -> Tx 1 -> Rx
   Uint16      MD31:1;    // 31  0 -> Tx 1 -> Rx

};

/* Allow access to the bit fields or entire register */
union CANMD_REG {
   Uint32             all;
   struct CANMD_BITS  bit;
};

/* eCAN Transmit Request Set register (CANTRS) bit definitions */
struct  CANTRS_BITS {      // bit  description
   Uint16      TRS0:1;     // 0   TRS for Mailbox 0
   Uint16      TRS1:1;     // 1   TRS for Mailbox 1
   Uint16      TRS2:1;     // 2   TRS for Mailbox 2
   Uint16      TRS3:1;     // 3   TRS for Mailbox 3
   Uint16      TRS4:1;     // 4   TRS for Mailbox 4
   Uint16      TRS5:1;     // 5   TRS for Mailbox 5
   Uint16      TRS6:1;     // 6   TRS for Mailbox 6
   Uint16      TRS7:1;     // 7   TRS for Mailbox 7
   Uint16      TRS8:1;     // 8   TRS for Mailbox 8
   Uint16      TRS9:1;     // 9   TRS for Mailbox 9
   Uint16      TRS10:1;    // 10  TRS for Mailbox 10
   Uint16      TRS11:1;    // 11  TRS for Mailbox 11
   Uint16      TRS12:1;    // 12  TRS for Mailbox 12
   Uint16      TRS13:1;    // 13  TRS for Mailbox 13
   Uint16      TRS14:1;    // 14  TRS for Mailbox 14
   Uint16      TRS15:1;    // 15  TRS for Mailbox 15
   Uint16      TRS16:1;    // 16  TRS for Mailbox 16
   Uint16      TRS17:1;    // 17  TRS for Mailbox 17
   Uint16      TRS18:1;    // 18  TRS for Mailbox 18
   Uint16      TRS19:1;    // 19  TRS for Mailbox 19
   Uint16      TRS20:1;    // 20  TRS for Mailbox 20
   Uint16      TRS21:1;    // 21  TRS for Mailbox 21
   Uint16      TRS22:1;    // 22  TRS for Mailbox 22
   Uint16      TRS23:1;    // 23  TRS for Mailbox 23
   Uint16      TRS24:1;    // 24  TRS for Mailbox 24
   Uint16      TRS25:1;    // 25  TRS for Mailbox 25
   Uint16      TRS26:1;    // 26  TRS for Mailbox 26
   Uint16      TRS27:1;    // 27  TRS for Mailbox 27
   Uint16      TRS28:1;    // 28  TRS for Mailbox 28
   Uint16      TRS29:1;    // 29  TRS for Mailbox 29
   Uint16      TRS30:1;    // 30  TRS for Mailbox 30
   Uint16      TRS31:1;    // 31  TRS for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTRS_REG {
   Uint32              all;
   struct CANTRS_BITS  bit;
};

/* eCAN Transmit Request Reset register (CANTRR) bit definitions */
struct  CANTRR_BITS {      // bit  description
   Uint16      TRR0:1;     // 0   TRR for Mailbox 0
   Uint16      TRR1:1;     // 1   TRR for Mailbox 1
   Uint16      TRR2:1;     // 2   TRR for Mailbox 2
   Uint16      TRR3:1;     // 3   TRR for Mailbox 3
   Uint16      TRR4:1;     // 4   TRR for Mailbox 4
   Uint16      TRR5:1;     // 5   TRR for Mailbox 5
   Uint16      TRR6:1;     // 6   TRR for Mailbox 6
   Uint16      TRR7:1;     // 7   TRR for Mailbox 7
   Uint16      TRR8:1;     // 8   TRR for Mailbox 8
   Uint16      TRR9:1;     // 9   TRR for Mailbox 9
   Uint16      TRR10:1;    // 10  TRR for Mailbox 10
   Uint16      TRR11:1;    // 11  TRR for Mailbox 11
   Uint16      TRR12:1;    // 12  TRR for Mailbox 12
   Uint16      TRR13:1;    // 13  TRR for Mailbox 13
   Uint16      TRR14:1;    // 14  TRR for Mailbox 14
   Uint16      TRR15:1;    // 15  TRR for Mailbox 15
   Uint16      TRR16:1;    // 16  TRR for Mailbox 16
   Uint16      TRR17:1;    // 17  TRR for Mailbox 17
   Uint16      TRR18:1;    // 18  TRR for Mailbox 18
   Uint16      TRR19:1;    // 19  TRR for Mailbox 19
   Uint16      TRR20:1;    // 20  TRR for Mailbox 20
   Uint16      TRR21:1;    // 21  TRR for Mailbox 21
   Uint16      TRR22:1;    // 22  TRR for Mailbox 22
   Uint16      TRR23:1;    // 23  TRR for Mailbox 23
   Uint16      TRR24:1;    // 24  TRR for Mailbox 24
   Uint16      TRR25:1;    // 25  TRR for Mailbox 25
   Uint16      TRR26:1;    // 26  TRR for Mailbox 26
   Uint16      TRR27:1;    // 27  TRR for Mailbox 27
   Uint16      TRR28:1;    // 28  TRR for Mailbox 28
   Uint16      TRR29:1;    // 29  TRR for Mailbox 29
   Uint16      TRR30:1;    // 30  TRR for Mailbox 30
   Uint16      TRR31:1;    // 31  TRR for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTRR_REG {
   Uint32              all;
   struct CANTRR_BITS  bit;
};

/* eCAN Transmit Acknowledge register (CANTA) bit definitions */
struct  CANTA_BITS {      // bit  description
   Uint16      TA0:1;     // 0   TA for Mailbox 0
   Uint16      TA1:1;     // 1   TA for Mailbox 1
   Uint16      TA2:1;     // 2   TA for Mailbox 2
   Uint16      TA3:1;     // 3   TA for Mailbox 3
   Uint16      TA4:1;     // 4   TA for Mailbox 4
   Uint16      TA5:1;     // 5   TA for Mailbox 5
   Uint16      TA6:1;     // 6   TA for Mailbox 6
   Uint16      TA7:1;     // 7   TA for Mailbox 7
   Uint16      TA8:1;     // 8   TA for Mailbox 8
   Uint16      TA9:1;     // 9   TA for Mailbox 9
   Uint16      TA10:1;    // 10  TA for Mailbox 10
   Uint16      TA11:1;    // 11  TA for Mailbox 11
   Uint16      TA12:1;    // 12  TA for Mailbox 12
   Uint16      TA13:1;    // 13  TA for Mailbox 13
   Uint16      TA14:1;    // 14  TA for Mailbox 14
   Uint16      TA15:1;    // 15  TA for Mailbox 15
   Uint16      TA16:1;    // 16  TA for Mailbox 16
   Uint16      TA17:1;    // 17  TA for Mailbox 17
   Uint16      TA18:1;    // 18  TA for Mailbox 18
   Uint16      TA19:1;    // 19  TA for Mailbox 19
   Uint16      TA20:1;    // 20  TA for Mailbox 20
   Uint16      TA21:1;    // 21  TA for Mailbox 21
   Uint16      TA22:1;    // 22  TA for Mailbox 22
   Uint16      TA23:1;    // 23  TA for Mailbox 23
   Uint16      TA24:1;    // 24  TA for Mailbox 24
   Uint16      TA25:1;    // 25  TA for Mailbox 25
   Uint16      TA26:1;    // 26  TA for Mailbox 26
   Uint16      TA27:1;    // 27  TA for Mailbox 27
   Uint16      TA28:1;    // 28  TA for Mailbox 28
   Uint16      TA29:1;    // 29  TA for Mailbox 29
   Uint16      TA30:1;    // 30  TA for Mailbox 30
   Uint16      TA31:1;    // 31  TA for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTA_REG {
   Uint32             all;
   struct CANTA_BITS  bit;
};

/* eCAN Transmit Abort Acknowledge register (CANAA) bit definitions */
struct  CANAA_BITS {      // bit  description
   Uint16      AA0:1;     // 0   AA for Mailbox 0
   Uint16      AA1:1;     // 1   AA for Mailbox 1
   Uint16      AA2:1;     // 2   AA for Mailbox 2
   Uint16      AA3:1;     // 3   AA for Mailbox 3
   Uint16      AA4:1;     // 4   AA for Mailbox 4
   Uint16      AA5:1;     // 5   AA for Mailbox 5
   Uint16      AA6:1;     // 6   AA for Mailbox 6
   Uint16      AA7:1;     // 7   AA for Mailbox 7
   Uint16      AA8:1;     // 8   AA for Mailbox 8
   Uint16      AA9:1;     // 9   AA for Mailbox 9
   Uint16      AA10:1;    // 10  AA for Mailbox 10
   Uint16      AA11:1;    // 11  AA for Mailbox 11
   Uint16      AA12:1;    // 12  AA for Mailbox 12
   Uint16      AA13:1;    // 13  AA for Mailbox 13
   Uint16      AA14:1;    // 14  AA for Mailbox 14
   Uint16      AA15:1;    // 15  AA for Mailbox 15
   Uint16      AA16:1;    // 16  AA for Mailbox 16
   Uint16      AA17:1;    // 17  AA for Mailbox 17
   Uint16      AA18:1;    // 18  AA for Mailbox 18
   Uint16      AA19:1;    // 19  AA for Mailbox 19
   Uint16      AA20:1;    // 20  AA for Mailbox 20
   Uint16      AA21:1;    // 21  AA for Mailbox 21
   Uint16      AA22:1;    // 22  AA for Mailbox 22
   Uint16      AA23:1;    // 23  AA for Mailbox 23
   Uint16      AA24:1;    // 24  AA for Mailbox 24
   Uint16      AA25:1;    // 25  AA for Mailbox 25
   Uint16      AA26:1;    // 26  AA for Mailbox 26
   Uint16      AA27:1;    // 27  AA for Mailbox 27
   Uint16      AA28:1;    // 28  AA for Mailbox 28
   Uint16      AA29:1;    // 29  AA for Mailbox 29
   Uint16      AA30:1;    // 30  AA for Mailbox 30
   Uint16      AA31:1;    // 31  AA for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANAA_REG {
   Uint32             all;
   struct CANAA_BITS  bit;
};

/* eCAN Received Message Pending register (CANRMP) bit definitions */
struct  CANRMP_BITS {      // bit  description
   Uint16      RMP0:1;     // 0   RMP for Mailbox 0
   Uint16      RMP1:1;     // 1   RMP for Mailbox 1
   Uint16      RMP2:1;     // 2   RMP for Mailbox 2
   Uint16      RMP3:1;     // 3   RMP for Mailbox 3
   Uint16      RMP4:1;     // 4   RMP for Mailbox 4
   Uint16      RMP5:1;     // 5   RMP for Mailbox 5
   Uint16      RMP6:1;     // 6   RMP for Mailbox 6
   Uint16      RMP7:1;     // 7   RMP for Mailbox 7
   Uint16      RMP8:1;     // 8   RMP for Mailbox 8
   Uint16      RMP9:1;     // 9   RMP for Mailbox 9
   Uint16      RMP10:1;    // 10  RMP for Mailbox 10
   Uint16      RMP11:1;    // 11  RMP for Mailbox 11
   Uint16      RMP12:1;    // 12  RMP for Mailbox 12
   Uint16      RMP13:1;    // 13  RMP for Mailbox 13
   Uint16      RMP14:1;    // 14  RMP for Mailbox 14
   Uint16      RMP15:1;    // 15  RMP for Mailbox 15
   Uint16      RMP16:1;    // 16  RMP for Mailbox 16
   Uint16      RMP17:1;    // 17  RMP for Mailbox 17
   Uint16      RMP18:1;    // 18  RMP for Mailbox 18
   Uint16      RMP19:1;    // 19  RMP for Mailbox 19
   Uint16      RMP20:1;    // 20  RMP for Mailbox 20
   Uint16      RMP21:1;    // 21  RMP for Mailbox 21
   Uint16      RMP22:1;    // 22  RMP for Mailbox 22
   Uint16      RMP23:1;    // 23  RMP for Mailbox 23
   Uint16      RMP24:1;    // 24  RMP for Mailbox 24
   Uint16      RMP25:1;    // 25  RMP for Mailbox 25
   Uint16      RMP26:1;    // 26  RMP for Mailbox 26
   Uint16      RMP27:1;    // 27  RMP for Mailbox 27
   Uint16      RMP28:1;    // 28  RMP for Mailbox 28
   Uint16      RMP29:1;    // 29  RMP for Mailbox 29
   Uint16      RMP30:1;    // 30  RMP for Mailbox 30
   Uint16      RMP31:1;    // 31  RMP for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANRMP_REG {
   Uint32              all;
   struct CANRMP_BITS  bit;
};

/* eCAN Received Message Lost register (CANRML) bit definitions */
struct  CANRML_BITS {      // bit  description
   Uint16      RML0:1;     // 0   RML for Mailbox 0
   Uint16      RML1:1;     // 1   RML for Mailbox 1
   Uint16      RML2:1;     // 2   RML for Mailbox 2
   Uint16      RML3:1;     // 3   RML for Mailbox 3
   Uint16      RML4:1;     // 4   RML for Mailbox 4
   Uint16      RML5:1;     // 5   RML for Mailbox 5
   Uint16      RML6:1;     // 6   RML for Mailbox 6
   Uint16      RML7:1;     // 7   RML for Mailbox 7
   Uint16      RML8:1;     // 8   RML for Mailbox 8
   Uint16      RML9:1;     // 9   RML for Mailbox 9
   Uint16      RML10:1;    // 10  RML for Mailbox 10
   Uint16      RML11:1;    // 11  RML for Mailbox 11
   Uint16      RML12:1;    // 12  RML for Mailbox 12
   Uint16      RML13:1;    // 13  RML for Mailbox 13
   Uint16      RML14:1;    // 14  RML for Mailbox 14
   Uint16      RML15:1;    // 15  RML for Mailbox 15
   Uint16      RML16:1;    // 16  RML for Mailbox 16
   Uint16      RML17:1;    // 17  RML for Mailbox 17
   Uint16      RML18:1;    // 18  RML for Mailbox 18
   Uint16      RML19:1;    // 19  RML for Mailbox 19
   Uint16      RML20:1;    // 20  RML for Mailbox 20
   Uint16      RML21:1;    // 21  RML for Mailbox 21
   Uint16      RML22:1;    // 22  RML for Mailbox 22
   Uint16      RML23:1;    // 23  RML for Mailbox 23
   Uint16      RML24:1;    // 24  RML for Mailbox 24
   Uint16      RML25:1;    // 25  RML for Mailbox 25
   Uint16      RML26:1;    // 26  RML for Mailbox 26
   Uint16      RML27:1;    // 27  RML for Mailbox 27
   Uint16      RML28:1;    // 28  RML for Mailbox 28
   Uint16      RML29:1;    // 29  RML for Mailbox 29
   Uint16      RML30:1;    // 30  RML for Mailbox 30
   Uint16      RML31:1;    // 31  RML for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANRML_REG {
   Uint32              all;
   struct CANRML_BITS  bit;
};

/* eCAN Remote Frame Pending register (CANRFP) bit definitions */
struct  CANRFP_BITS {      // bit  description
   Uint16      RFP0:1;     // 0   RFP for Mailbox 0
   Uint16      RFP1:1;     // 1   RFP for Mailbox 1
   Uint16      RFP2:1;     // 2   RFP for Mailbox 2
   Uint16      RFP3:1;     // 3   RFP for Mailbox 3
   Uint16      RFP4:1;     // 4   RFP for Mailbox 4
   Uint16      RFP5:1;     // 5   RFP for Mailbox 5
   Uint16      RFP6:1;     // 6   RFP for Mailbox 6
   Uint16      RFP7:1;     // 7   RFP for Mailbox 7
   Uint16      RFP8:1;     // 8   RFP for Mailbox 8
   Uint16      RFP9:1;     // 9   RFP for Mailbox 9
   Uint16      RFP10:1;    // 10  RFP for Mailbox 10
   Uint16      RFP11:1;    // 11  RFP for Mailbox 11
   Uint16      RFP12:1;    // 12  RFP for Mailbox 12
   Uint16      RFP13:1;    // 13  RFP for Mailbox 13
   Uint16      RFP14:1;    // 14  RFP for Mailbox 14
   Uint16      RFP15:1;    // 15  RFP for Mailbox 15
   Uint16      RFP16:1;    // 16  RFP for Mailbox 16
   Uint16      RFP17:1;    // 17  RFP for Mailbox 17
   Uint16      RFP18:1;    // 18  RFP for Mailbox 18
   Uint16      RFP19:1;    // 19  RFP for Mailbox 19
   Uint16      RFP20:1;    // 20  RFP for Mailbox 20
   Uint16      RFP21:1;    // 21  RFP for Mailbox 21
   Uint16      RFP22:1;    // 22  RFP for Mailbox 22
   Uint16      RFP23:1;    // 23  RFP for Mailbox 23
   Uint16      RFP24:1;    // 24  RFP for Mailbox 24
   Uint16      RFP25:1;    // 25  RFP for Mailbox 25
   Uint16      RFP26:1;    // 26  RFP for Mailbox 26
   Uint16      RFP27:1;    // 27  RFP for Mailbox 27
   Uint16      RFP28:1;    // 28  RFP for Mailbox 28
   Uint16      RFP29:1;    // 29  RFP for Mailbox 29
   Uint16      RFP30:1;    // 30  RFP for Mailbox 30
   Uint16      RFP31:1;    // 31  RFP for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANRFP_REG {
   Uint32              all;
   struct CANRFP_BITS  bit;
};

/* eCAN Global Acceptance Mask register (CANGAM) bit definitions */
struct  CANGAM_BITS {   // bits  description
   Uint16 GAM150:16;    // 15:0  Global acceptance mask bits 0-15
   Uint16 GAM2816:13;   // 28:16 Global acceptance mask bits 16-28
   Uint16 rsvd:2;       // 30:29 reserved
   Uint16 AMI:1;        // 31    AMI bit
};

/* Allow access to the bit fields or entire register */
union CANGAM_REG {
   Uint32              all;
   struct CANGAM_BITS  bit;
};


/* eCAN Master Control register (CANMC) bit definitions */
struct  CANMC_BITS {       // bits  description
   Uint16      MBNR:5;     // 4:0   MBX # for CDR bit
   Uint16      SRES:1;     // 5     Soft reset
   Uint16      STM:1;      // 6     Self-test mode
   Uint16      ABO:1;      // 7     Auto bus-on
   Uint16      CDR:1;      // 8     Change data request
   Uint16      WUBA:1;     // 9     Wake-up on bus activity
   Uint16      DBO:1;      // 10    Data-byte order
   Uint16      PDR:1;      // 11    Power-down mode request
   Uint16      CCR:1;      // 12    Change configuration request
   Uint16      SCB:1;      // 13    SCC compatibility bit
   Uint16      TCC:1;      // 14    TSC MSB clear bit
   Uint16      MBCC:1;     // 15    TSC clear bit thru mailbox 16
   Uint16      SUSP:1;     // 16    SUSPEND free/soft bit
   Uint16      rsvd:15;    // 31:17  reserved
};

/* Allow access to the bit fields or entire register */
union CANMC_REG {
   Uint32             all;
   struct CANMC_BITS  bit;
};

/* eCAN Bit -timing configuration register (CANBTC) bit definitions */
struct  CANBTC_BITS {  // bits  description
   Uint16  TSEG2REG:3; // 2:0   TSEG2 register value
   Uint16  TSEG1REG:4; // 6:3   TSEG1 register value
   Uint16  SAM:1;      // 7     Sample-point setting
   Uint16  SJWREG:2;   // 9:8   Synchroniztion Jump Width register value
   Uint16  rsvd1:6;    // 15:10 reserved
   Uint16  BRPREG:8;   // 23:16 Baudrate prescaler register value
   Uint16  rsvd2:8;    // 31:24 reserved
};

/* Allow access to the bit fields or entire register */
union CANBTC_REG {
   Uint32              all;
   struct CANBTC_BITS  bit;
};

/* eCAN Error & Status register (CANES) bit definitions */
struct  CANES_BITS {    // bits  description
   Uint16   TM:1;       // 0     Transmit Mode
   Uint16   RM:1;       // 1     Receive Mode
   Uint16   rsvd1:1;    // 2     reserved
   Uint16   PDA:1;      // 3     Power-down acknowledge
   Uint16   CCE:1;      // 4     Change Configuration Enable
   Uint16   SMA:1;      // 5     Suspend Mode Acknowledge
   Uint16   rsvd2:10;   // 15:6  reserved
   Uint16   EW:1;       // 16    Warning status
   Uint16   EP:1;       // 17    Error Passive status
   Uint16   BO:1;       // 18    Bus-off status
   Uint16   ACKE:1;     // 19    Acknowledge error
   Uint16   SE:1;       // 20    Stuff error
   Uint16   CRCE:1;     // 21    CRC error
   Uint16   SA1:1;      // 22    Stuck at Dominant error
   Uint16   BE:1;       // 23    Bit error
   Uint16   FE:1;       // 24    Framing error
   Uint16   rsvd3:7;    // 31:25 reserved
};

/* Allow access to the bit fields or entire register */
union CANES_REG {
   Uint32             all;
   struct CANES_BITS  bit;
};


/* eCAN Transmit Error Counter register (CANTEC) bit definitions */
struct  CANTEC_BITS {  // bits  description
   Uint16 TEC:8;       // 7:0   TEC
   Uint16 rsvd1:8;     // 15:8  reserved
   Uint16 rsvd2:16;    // 31:16  reserved
};

/* Allow access to the bit fields or entire register */
union CANTEC_REG {
   Uint32              all;
   struct CANTEC_BITS  bit;
};

/* eCAN Receive Error Counter register (CANREC) bit definitions */
struct  CANREC_BITS {  // bits  description
   Uint16 REC:8;       // 7:0   REC
   Uint16 rsvd1:8;     // 15:8  reserved
   Uint16 rsvd2:16;    // 31:16 reserved
};

/* Allow access to the bit fields or entire register */
union CANREC_REG {
   Uint32              all;
   struct CANREC_BITS  bit;
};

/* eCAN Global Interrupt Flag 0 (CANGIF0) bit definitions */
struct  CANGIF0_BITS {  // bits  description
   Uint16   MIV0:5;     // 4:0   Mailbox Interrupt Vector
   Uint16   rsvd1:3;    // 7:5   reserved
   Uint16   WLIF0:1;    // 8     Warning level interrupt flag
   Uint16   EPIF0:1;    // 9     Error-passive interrupt flag
   Uint16   BOIF0:1;    // 10    Bus-off interrupt flag
   Uint16   RMLIF0:1;   // 11    Received message lost interrupt flag
   Uint16   WUIF0:1;    // 12    Wakeup interrupt flag
   Uint16   WDIF0:1;    // 13    Write denied interrupt flag
   Uint16   AAIF0:1;    // 14    Abort Ack interrupt flag
   Uint16   GMIF0:1;    // 15    Global MBX interrupt flag
   Uint16   TCOF0:1;    // 16    TSC Overflow flag
   Uint16   MTOF0:1;    // 17    Mailbox Timeout flag
   Uint16   rsvd2:14;   // 31:18 reserved
};

/* Allow access to the bit fields or entire register */
union CANGIF0_REG {
   Uint32               all;
   struct CANGIF0_BITS  bit;
};

/* eCAN Global Interrupt Mask register (CANGIM) bit definitions */
struct  CANGIM_BITS { // bits  description
   Uint16  I0EN:1;    // 0      Interrupt 0 enable
   Uint16  I1EN:1;    // 1      Interrupt 1 enable
   Uint16  GIL:1;     // 2      Global Interrupt Level
   Uint16  rsvd1:5;   // 7:3    reserved
   Uint16  WLIM:1;    // 8      Warning level interrupt mask
   Uint16  EPIM:1;    // 9      Error-passive interrupt mask
   Uint16  BOIM:1;    // 10     Bus-off interrupt mask
   Uint16  RMLIM:1;   // 11     Received message lost interrupt mask
   Uint16  WUIM:1;    // 12     Wakeup interrupt mask
   Uint16  WDIM:1;    // 13     Write denied interrupt mask
   Uint16  AAIM:1;    // 14     Abort Ack interrupt mask
   Uint16  rsvd2:1;   // 15     reserved
   Uint16  TCOM:1;    // 16     TSC overflow interrupt mask
   Uint16  MTOM:1;    // 17     MBX Timeout interrupt mask
   Uint16  rsvd3:14;  // 31:18  reserved
};

/* Allow access to the bit fields or entire register */
union CANGIM_REG {
   Uint32              all;
   struct CANGIM_BITS  bit;
};


/* eCAN Global Interrupt Flag 1 (eCANGIF1) bit definitions */
struct  CANGIF1_BITS {     // bits  description
   Uint16      MIV1:5;     // 4:0   Mailbox Interrupt Vector
   Uint16      rsvd1:3;    // 7:5   reserved
   Uint16      WLIF1:1;    // 8     Warning level interrupt flag
   Uint16      EPIF1:1;    // 9     Error-passive interrupt flag
   Uint16      BOIF1:1;    // 10    Bus-off interrupt flag
   Uint16      RMLIF1:1;   // 11    Received message lost interrupt flag
   Uint16      WUIF1:1;    // 12    Wakeup interrupt flag
   Uint16      WDIF1:1;    // 13    Write denied interrupt flag
   Uint16      AAIF1:1;    // 14    Abort Ack interrupt flag
   Uint16      GMIF1:1;    // 15    Global MBX interrupt flag
   Uint16      TCOF1:1;    // 16    TSC Overflow flag
   Uint16      MTOF1:1;    // 17    Mailbox Timeout flag
   Uint16      rsvd2:14;   // 31:18 reserved
};

/* Allow access to the bit fields or entire register */
union CANGIF1_REG {
   Uint32               all;
   struct CANGIF1_BITS  bit;
};


/* eCAN Mailbox Interrupt Mask register (CANMIM) bit definitions */
struct  CANMIM_BITS {      // bit  description
   Uint16      MIM0:1;     // 0   MIM for Mailbox 0
   Uint16      MIM1:1;     // 1   MIM for Mailbox 1
   Uint16      MIM2:1;     // 2   MIM for Mailbox 2
   Uint16      MIM3:1;     // 3   MIM for Mailbox 3
   Uint16      MIM4:1;     // 4   MIM for Mailbox 4
   Uint16      MIM5:1;     // 5   MIM for Mailbox 5
   Uint16      MIM6:1;     // 6   MIM for Mailbox 6
   Uint16      MIM7:1;     // 7   MIM for Mailbox 7
   Uint16      MIM8:1;     // 8   MIM for Mailbox 8
   Uint16      MIM9:1;     // 9   MIM for Mailbox 9
   Uint16      MIM10:1;    // 10  MIM for Mailbox 10
   Uint16      MIM11:1;    // 11  MIM for Mailbox 11
   Uint16      MIM12:1;    // 12  MIM for Mailbox 12
   Uint16      MIM13:1;    // 13  MIM for Mailbox 13
   Uint16      MIM14:1;    // 14  MIM for Mailbox 14
   Uint16      MIM15:1;    // 15  MIM for Mailbox 15
   Uint16      MIM16:1;    // 16  MIM for Mailbox 16
   Uint16      MIM17:1;    // 17  MIM for Mailbox 17
   Uint16      MIM18:1;    // 18  MIM for Mailbox 18
   Uint16      MIM19:1;    // 19  MIM for Mailbox 19
   Uint16      MIM20:1;    // 20  MIM for Mailbox 20
   Uint16      MIM21:1;    // 21  MIM for Mailbox 21
   Uint16      MIM22:1;    // 22  MIM for Mailbox 22
   Uint16      MIM23:1;    // 23  MIM for Mailbox 23
   Uint16      MIM24:1;    // 24  MIM for Mailbox 24
   Uint16      MIM25:1;    // 25  MIM for Mailbox 25
   Uint16      MIM26:1;    // 26  MIM for Mailbox 26
   Uint16      MIM27:1;    // 27  MIM for Mailbox 27
   Uint16      MIM28:1;    // 28  MIM for Mailbox 28
   Uint16      MIM29:1;    // 29  MIM for Mailbox 29
   Uint16      MIM30:1;    // 30  MIM for Mailbox 30
   Uint16      MIM31:1;    // 31  MIM for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANMIM_REG {
   Uint32              all;
   struct CANMIM_BITS  bit;
};

/* eCAN Mailbox Interrupt Level register (CANMIL) bit definitions */
struct  CANMIL_BITS {      // bit  description
   Uint16      MIL0:1;     // 0   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL1:1;     // 1   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL2:1;     // 2   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL3:1;     // 3   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL4:1;     // 4   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL5:1;     // 5   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL6:1;     // 6   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL7:1;     // 7   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL8:1;     // 8   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL9:1;     // 9   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL10:1;    // 10  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL11:1;    // 11  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL12:1;    // 12  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL13:1;    // 13  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL14:1;    // 14  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL15:1;    // 15  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL16:1;    // 16  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL17:1;    // 17  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL18:1;    // 18  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL19:1;    // 19  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL20:1;    // 20  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL21:1;    // 21  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL22:1;    // 22  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL23:1;    // 23  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL24:1;    // 24  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL25:1;    // 25  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL26:1;    // 26  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL27:1;    // 27  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL28:1;    // 28  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL29:1;    // 29  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL30:1;    // 30  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL31:1;    // 31  0 -> Int 9.5   1 -> Int 9.6

};

/* Allow access to the bit fields or entire register */
union CANMIL_REG {
   Uint32              all;
   struct CANMIL_BITS  bit;
};


/* eCAN Overwrite Protection Control register (CANOPC) bit definitions */
struct  CANOPC_BITS {      // bit  description
   Uint16      OPC0:1;     // 0   OPC for Mailbox 0
   Uint16      OPC1:1;     // 1   OPC for Mailbox 1
   Uint16      OPC2:1;     // 2   OPC for Mailbox 2
   Uint16      OPC3:1;     // 3   OPC for Mailbox 3
   Uint16      OPC4:1;     // 4   OPC for Mailbox 4
   Uint16      OPC5:1;     // 5   OPC for Mailbox 5
   Uint16      OPC6:1;     // 6   OPC for Mailbox 6
   Uint16      OPC7:1;     // 7   OPC for Mailbox 7
   Uint16      OPC8:1;     // 8   OPC for Mailbox 8
   Uint16      OPC9:1;     // 9   OPC for Mailbox 9
   Uint16      OPC10:1;    // 10  OPC for Mailbox 10
   Uint16      OPC11:1;    // 11  OPC for Mailbox 11
   Uint16      OPC12:1;    // 12  OPC for Mailbox 12
   Uint16      OPC13:1;    // 13  OPC for Mailbox 13
   Uint16      OPC14:1;    // 14  OPC for Mailbox 14
   Uint16      OPC15:1;    // 15  OPC for Mailbox 15
   Uint16      OPC16:1;    // 16  OPC for Mailbox 16
   Uint16      OPC17:1;    // 17  OPC for Mailbox 17
   Uint16      OPC18:1;    // 18  OPC for Mailbox 18
   Uint16      OPC19:1;    // 19  OPC for Mailbox 19
   Uint16      OPC20:1;    // 20  OPC for Mailbox 20
   Uint16      OPC21:1;    // 21  OPC for Mailbox 21
   Uint16      OPC22:1;    // 22  OPC for Mailbox 22
   Uint16      OPC23:1;    // 23  OPC for Mailbox 23
   Uint16      OPC24:1;    // 24  OPC for Mailbox 24
   Uint16      OPC25:1;    // 25  OPC for Mailbox 25
   Uint16      OPC26:1;    // 26  OPC for Mailbox 26
   Uint16      OPC27:1;    // 27  OPC for Mailbox 27
   Uint16      OPC28:1;    // 28  OPC for Mailbox 28
   Uint16      OPC29:1;    // 29  OPC for Mailbox 29
   Uint16      OPC30:1;    // 30  OPC for Mailbox 30
   Uint16      OPC31:1;    // 31  OPC for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANOPC_REG {
   Uint32              all;
   struct CANOPC_BITS  bit;
};


/* eCAN TX I/O Control Register (CANTIOC) bit definitions */
struct  CANTIOC_BITS { // bits  description
   Uint16  rsvd1:3;    // 2:0   reserved
   Uint16  TXFUNC:1;   // 3     TXFUNC
   Uint16  rsvd2:12;   // 15:4  reserved
   Uint16  rsvd3:16;   // 31:16 reserved
};

/* Allow access to the bit fields or entire register */
union CANTIOC_REG {
   Uint32               all;
   struct CANTIOC_BITS  bit;
};

/* eCAN RX I/O Control Register (CANRIOC) bit definitions */
struct  CANRIOC_BITS { // bits  description
   Uint16  rsvd1:3;    // 2:0   reserved
   Uint16  RXFUNC:1;   // 3     RXFUNC
   Uint16  rsvd2:12;   // 15:4  reserved
   Uint16  rsvd3:16;   // 31:16 reserved
};

/* Allow access to the bit fields or entire register */
union CANRIOC_REG {
   Uint32               all;
   struct CANRIOC_BITS  bit;
};


/* eCAN Time-out Control register (CANTOC) bit definitions */
struct  CANTOC_BITS {      // bit  description
   Uint16      TOC0:1;     // 0   TOC for Mailbox 0
   Uint16      TOC1:1;     // 1   TOC for Mailbox 1
   Uint16      TOC2:1;     // 2   TOC for Mailbox 2
   Uint16      TOC3:1;     // 3   TOC for Mailbox 3
   Uint16      TOC4:1;     // 4   TOC for Mailbox 4
   Uint16      TOC5:1;     // 5   TOC for Mailbox 5
   Uint16      TOC6:1;     // 6   TOC for Mailbox 6
   Uint16      TOC7:1;     // 7   TOC for Mailbox 7
   Uint16      TOC8:1;     // 8   TOC for Mailbox 8
   Uint16      TOC9:1;     // 9   TOC for Mailbox 9
   Uint16      TOC10:1;    // 10  TOC for Mailbox 10
   Uint16      TOC11:1;    // 11  TOC for Mailbox 11
   Uint16      TOC12:1;    // 12  TOC for Mailbox 12
   Uint16      TOC13:1;    // 13  TOC for Mailbox 13
   Uint16      TOC14:1;    // 14  TOC for Mailbox 14
   Uint16      TOC15:1;    // 15  TOC for Mailbox 15
   Uint16      TOC16:1;    // 16  TOC for Mailbox 16
   Uint16      TOC17:1;    // 17  TOC for Mailbox 17
   Uint16      TOC18:1;    // 18  TOC for Mailbox 18
   Uint16      TOC19:1;    // 19  TOC for Mailbox 19
   Uint16      TOC20:1;    // 20  TOC for Mailbox 20
   Uint16      TOC21:1;    // 21  TOC for Mailbox 21
   Uint16      TOC22:1;    // 22  TOC for Mailbox 22
   Uint16      TOC23:1;    // 23  TOC for Mailbox 23
   Uint16      TOC24:1;    // 24  TOC for Mailbox 24
   Uint16      TOC25:1;    // 25  TOC for Mailbox 25
   Uint16      TOC26:1;    // 26  TOC for Mailbox 26
   Uint16      TOC27:1;    // 27  TOC for Mailbox 27
   Uint16      TOC28:1;    // 28  TOC for Mailbox 28
   Uint16      TOC29:1;    // 29  TOC for Mailbox 29
   Uint16      TOC30:1;    // 30  TOC for Mailbox 30
   Uint16      TOC31:1;    // 31  TOC for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTOC_REG {
   Uint32              all;
   struct CANTOC_BITS  bit;
};


/* eCAN Time-out Status register (CANTOS) bit definitions */
struct  CANTOS_BITS {            // bit  description
   Uint16      TOS0:1;     // 0   TOS for Mailbox 0
   Uint16      TOS1:1;     // 1   TOS for Mailbox 1
   Uint16      TOS2:1;     // 2   TOS for Mailbox 2
   Uint16      TOS3:1;     // 3   TOS for Mailbox 3
   Uint16      TOS4:1;     // 4   TOS for Mailbox 4
   Uint16      TOS5:1;     // 5   TOS for Mailbox 5
   Uint16      TOS6:1;     // 6   TOS for Mailbox 6
   Uint16      TOS7:1;     // 7   TOS for Mailbox 7
   Uint16      TOS8:1;     // 8   TOS for Mailbox 8
   Uint16      TOS9:1;     // 9   TOS for Mailbox 9
   Uint16      TOS10:1;    // 10  TOS for Mailbox 10
   Uint16      TOS11:1;    // 11  TOS for Mailbox 11
   Uint16      TOS12:1;    // 12  TOS for Mailbox 12
   Uint16      TOS13:1;    // 13  TOS for Mailbox 13
   Uint16      TOS14:1;    // 14  TOS for Mailbox 14
   Uint16      TOS15:1;    // 15  TOS for Mailbox 15
   Uint16      TOS16:1;    // 16  TOS for Mailbox 16
   Uint16      TOS17:1;    // 17  TOS for Mailbox 17
   Uint16      TOS18:1;    // 18  TOS for Mailbox 18
   Uint16      TOS19:1;    // 19  TOS for Mailbox 19
   Uint16      TOS20:1;    // 20  TOS for Mailbox 20
   Uint16      TOS21:1;    // 21  TOS for Mailbox 21
   Uint16      TOS22:1;    // 22  TOS for Mailbox 22
   Uint16      TOS23:1;    // 23  TOS for Mailbox 23
   Uint16      TOS24:1;    // 24  TOS for Mailbox 24
   Uint16      TOS25:1;    // 25  TOS for Mailbox 25
   Uint16      TOS26:1;    // 26  TOS for Mailbox 26
   Uint16      TOS27:1;    // 27  TOS for Mailbox 27
   Uint16      TOS28:1;    // 28  TOS for Mailbox 28
   Uint16      TOS29:1;    // 29  TOS for Mailbox 29
   Uint16      TOS30:1;    // 30  TOS for Mailbox 30
   Uint16      TOS31:1;    // 31  TOS for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTOS_REG {
   Uint32              all;
   struct CANTOS_BITS  bit;
};

/**************************************/
/* eCAN Control & Status register file */
/**************************************/

struct ECAN_REGS {
   union CANME_REG   CANME;          // Mailbox Enable
   union CANMD_REG   CANMD;          // Mailbox Direction
   union CANTRS_REG  CANTRS;         // Transmit Request Set
   union CANTRR_REG  CANTRR;         // Transmit Request Reset
   union CANTA_REG   CANTA;          // Transmit Acknowledge
   union CANAA_REG   CANAA;          // Abort Acknowledge
   union CANRMP_REG  CANRMP;         // Received Message Pending
   union CANRML_REG  CANRML;         // Received Message Lost
   union CANRFP_REG  CANRFP;         // Remote Frame Pending
   union CANGAM_REG  CANGAM;         // Global Acceptance Mask
   union CANMC_REG   CANMC;          // Master Control
   union CANBTC_REG  CANBTC;         // Bit Timing
   union CANES_REG   CANES;          // Error Status
   union CANTEC_REG  CANTEC;         // Transmit Error Counter
   union CANREC_REG  CANREC;         // Receive Error Counter
   union CANGIF0_REG CANGIF0;        // Global Interrupt Flag 0
   union CANGIM_REG  CANGIM;         // Global Interrupt Mask 0
   union CANGIF1_REG CANGIF1;        // Global Interrupt Flag 1
   union CANMIM_REG  CANMIM;         // Mailbox Interrupt Mask
   union CANMIL_REG  CANMIL;         // Mailbox Interrupt Level
   union CANOPC_REG  CANOPC;         // Overwrite Protection Control
   union CANTIOC_REG CANTIOC;        // TX I/O Control
   union CANRIOC_REG CANRIOC;        // RX I/O Control
   Uint32            CANTSC;         // Time-stamp counter
   union CANTOC_REG  CANTOC;         // Time-out Control
   union CANTOS_REG  CANTOS;         // Time-out Status

};

/* --------------------------------------------------- */
/* eCAN Mailbox Registers                               */
/* ----------------------------------------------------*/

/* eCAN Message ID (MSGID) bit definitions */
struct  CANMSGID_BITS {        // bits  description
   Uint16      EXTMSGID_L:16;  // 15:0
   Uint16      EXTMSGID_H:2;   // 17:16
   Uint16      STDMSGID:11;    // 28:18
   Uint16      AAM:1;          // 29
   Uint16      AME:1;          // 30
   Uint16      IDE:1;          // 31

};

/* Allow access to the bit fields or entire register */
union CANMSGID_REG {
   Uint32                all;
   struct CANMSGID_BITS  bit;
};

/* eCAN Message Control Register (MSGCTRL) bit definitions */
struct  CANMSGCTRL_BITS {     // bits  description
   Uint16 DLC:4;          // 3:0
   Uint16 RTR:1;          // 4
   Uint16 rsvd1:3;        // 7:5   reserved
   Uint16 TPL:5;          // 12:8
   Uint16 rsvd2:3;        // 15:13 reserved
   Uint16 rsvd3:16;       // 31:16 reserved
};

/* Allow access to the bit fields or entire register */
union CANMSGCTRL_REG {
   Uint32                  all;
   struct CANMSGCTRL_BITS  bit;
};

/* eCAN Message Data Register low (MDR_L) word definitions */
struct  CANMDL_WORDS {      // bits  description
   Uint16      LOW_WORD:16; // 15:0
   Uint16      HI_WORD:16;  // 31:16
};

/* eCAN Message Data Register low (MDR_L) byte definitions */
struct  CANMDL_BYTES {      // bits   description
   Uint16      BYTE3:8;     // 7:0
   Uint16      BYTE2:8;     // 15:8
   Uint16      BYTE1:8;     // 23:16
   Uint16      BYTE0:8;     // 31:24
};


/* Allow access to the bit fields or entire register */

union CANMDL_REG {
   Uint32                all;
   struct CANMDL_WORDS   word;
   struct CANMDL_BYTES   byte;
};



/* eCAN Message Data Register high  (MDR_H) word definitions */
struct  CANMDH_WORDS {         // bits  description
   Uint16      LOW_WORD:16;    // 15:0
   Uint16      HI_WORD:16;     // 31:16
};

/* eCAN Message Data Register low (MDR_H) byte definitions */
struct  CANMDH_BYTES {      // bits   description
   Uint16      BYTE7:8;     // 7:0
   Uint16      BYTE6:8;     // 15:8
   Uint16      BYTE5:8;     // 23:16
   Uint16      BYTE4:8;     // 31:24
};

/* Allow access to the bit fields or entire register */
union CANMDH_REG {
   Uint32                  all;
   struct CANMDH_WORDS     word;
   struct CANMDH_BYTES     byte;
};


struct MBOX {
   union CANMSGID_REG     MSGID;
   union CANMSGCTRL_REG   MSGCTRL;
   union CANMDL_REG       MDL;
   union CANMDH_REG       MDH;
};

/**************************************/
/*          eCAN Mailboxes             */
/**************************************/

struct ECAN_MBOXES {
   struct MBOX MBOX0;
   struct MBOX MBOX1;
   struct MBOX MBOX2;
   struct MBOX MBOX3;
   struct MBOX MBOX4;
   struct MBOX MBOX5;
   struct MBOX MBOX6;
   struct MBOX MBOX7;
   struct MBOX MBOX8;
   struct MBOX MBOX9;
   struct MBOX MBOX10;
   struct MBOX MBOX11;
   struct MBOX MBOX12;
   struct MBOX MBOX13;
   struct MBOX MBOX14;
   struct MBOX MBOX15;
   struct MBOX MBOX16;
   struct MBOX MBOX17;
   struct MBOX MBOX18;
   struct MBOX MBOX19;
   struct MBOX MBOX20;
   struct MBOX MBOX21;
   struct MBOX MBOX22;
   struct MBOX MBOX23;
   struct MBOX MBOX24;
   struct MBOX MBOX25;
   struct MBOX MBOX26;
   struct MBOX MBOX27;
   struct MBOX MBOX28;
   struct MBOX MBOX29;
   struct MBOX MBOX30;
   struct MBOX MBOX31;
};

/* eCAN Local Acceptance Mask (LAM) bit definitions */
struct  CANLAM_BITS {                // bits  description
   Uint16      LAM_L:16;     // 15:0
   Uint16      LAM_H:13;     // 28:16
   Uint16 rsvd1:2;           // 30:29   reserved
   Uint16      LAMI:1;       // 31
};

/* Allow access to the bit fields or entire register */
union CANLAM_REG {
   Uint32        all;
   struct CANLAM_BITS  bit;
};


/**************************************/
/*    eCAN Local Acceptance Masks      */
/**************************************/

/* eCAN LAM File */
struct LAM_REGS {
   union CANLAM_REG LAM0;
   union CANLAM_REG LAM1;
   union CANLAM_REG LAM2;
   union CANLAM_REG LAM3;
   union CANLAM_REG LAM4;
   union CANLAM_REG LAM5;
   union CANLAM_REG LAM6;
   union CANLAM_REG LAM7;
   union CANLAM_REG LAM8;
   union CANLAM_REG LAM9;
   union CANLAM_REG LAM10;
   union CANLAM_REG LAM11;
   union CANLAM_REG LAM12;
   union CANLAM_REG LAM13;
   union CANLAM_REG LAM14;
   union CANLAM_REG LAM15;
   union CANLAM_REG LAM16;
   union CANLAM_REG LAM17;
   union CANLAM_REG LAM18;
   union CANLAM_REG LAM19;
   union CANLAM_REG LAM20;
   union CANLAM_REG LAM21;
   union CANLAM_REG LAM22;
   union CANLAM_REG LAM23;
   union CANLAM_REG LAM24;
   union CANLAM_REG LAM25;
   union CANLAM_REG LAM26;
   union CANLAM_REG LAM27;
   union CANLAM_REG LAM28;
   union CANLAM_REG LAM29;
   union CANLAM_REG LAM30;
   union CANLAM_REG LAM31;
};

/* Mailbox MOTS File */

struct MOTS_REGS {
   Uint32 MOTS0;
   Uint32 MOTS1;
   Uint32 MOTS2;
   Uint32 MOTS3;
   Uint32 MOTS4;
   Uint32 MOTS5;
   Uint32 MOTS6;
   Uint32 MOTS7;
   Uint32 MOTS8;
   Uint32 MOTS9;
   Uint32 MOTS10;
   Uint32 MOTS11;
   Uint32 MOTS12;
   Uint32 MOTS13;
   Uint32 MOTS14;
   Uint32 MOTS15;
   Uint32 MOTS16;
   Uint32 MOTS17;
   Uint32 MOTS18;
   Uint32 MOTS19;
   Uint32 MOTS20;
   Uint32 MOTS21;
   Uint32 MOTS22;
   Uint32 MOTS23;
   Uint32 MOTS24;
   Uint32 MOTS25;
   Uint32 MOTS26;
   Uint32 MOTS27;
   Uint32 MOTS28;
   Uint32 MOTS29;
   Uint32 MOTS30;
   Uint32 MOTS31;
};

/* Mailbox MOTO File */

struct MOTO_REGS {
   Uint32 MOTO0;
   Uint32 MOTO1;
   Uint32 MOTO2;
   Uint32 MOTO3;
   Uint32 MOTO4;
   Uint32 MOTO5;
   Uint32 MOTO6;
   Uint32 MOTO7;
   Uint32 MOTO8;
   Uint32 MOTO9;
   Uint32 MOTO10;
   Uint32 MOTO11;
   Uint32 MOTO12;
   Uint32 MOTO13;
   Uint32 MOTO14;
   Uint32 MOTO15;
   Uint32 MOTO16;
   Uint32 MOTO17;
   Uint32 MOTO18;
   Uint32 MOTO19;
   Uint32 MOTO20;
   Uint32 MOTO21;
   Uint32 MOTO22;
   Uint32 MOTO23;
   Uint32 MOTO24;
   Uint32 MOTO25;
   Uint32 MOTO26;
   Uint32 MOTO27;
   Uint32 MOTO28;
   Uint32 MOTO29;
   Uint32 MOTO30;
   Uint32 MOTO31;
};


//---------------------------------------------------------------------------
// eCAN External References & Function Declarations:
//
extern volatile struct ECAN_REGS ECanaRegs;
extern volatile struct ECAN_MBOXES ECanaMboxes;
extern volatile struct LAM_REGS ECanaLAMRegs;
extern volatile struct MOTO_REGS ECanaMOTORegs;
extern volatile struct MOTS_REGS ECanaMOTSRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2806x_ECAN.H definition

//===========================================================================
// End of file.
//===========================================================================
