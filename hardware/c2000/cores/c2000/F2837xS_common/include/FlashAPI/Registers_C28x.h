/*--------------------------------------------------------*/
/* F021\Registers_C28x.h                                  */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.53                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Registers_C28x.h
    \brief A complete mapping of the F021 Flash Registers

    Allows named access to the F021 Flash Registers.
*/
#ifndef F021_REGISTERS_C28X_H_
#define F021_REGISTERS_C28X_H_

#include "Types.h"

/*  Flash Configuration Registers */

/*typedef union Fapi_Register*/
/*!
    Structure describing the Flash Wrapper registers allowing register and bit
    level accesses.
*/
typedef volatile struct FMC_REGISTERS
{
   /*!
       Defines whole and bit level accesses to the Read Control Register - 0x00
   */
   union FRDCNTL
   {
      uint32 u32Register; /* Read Control Register, bits 31:0 */
      struct
      {
         uint16 RM                      :1;/*!< Read Mode, bit 0 */
         uint16 _FRDCNTL_Reserved_03_01 :3;/*!< Reserved, bits 3:1 */
         uint16 ASWSTEN                 :1;/*!< Address Setup Wait State Enable, bit 4 */
         uint16 _FRDCNTL_Reserved_07_05 :3;/*!< Reserved, bits 7:5 */
         uint16 RWAIT                   :4;/*!< Random Read Wait State, bits 11:8 */
         uint16 _FRDCNTL_Reserved_15_12 :4;/*!< Reserved, bits 15:12 */
         uint16 IDLEN                   :1;/*!< Incoming Data Latch, bit 16 */
         uint16 _FRDCNTL_Reserved_23_17 :7;/*!< Reserved, bits 23:17 */
         uint16 IFLUSH_HOLD             :4;/*!< Hold off IFLUSH for this long, bits 27:24 */
         uint16 _FRDCNTL_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FRDCNTRL_BITS;
   } FrdCntl;

   /*!
       Defines whole and bit level accesses to the Special Read Control Register - 0x04
   */
   union FSPRD
   {
      uint32 u32Register; /* Special Read Control Register, bits 31:0 */
      struct
      {
         uint16  RM0                   :1; /*!< Read Margin 0, bit 0 */
         uint16  RM1                   :1; /*!< Read Margin 1, bit 1 */
         uint16 _FSPRD_Reserved_07_02  :6; /*!< Reserved, bits 7:2 */
         uint16 RMBSEM                 :8; /*!< RMBSEM, bits 15:8 */
         uint16  DIS_PREEMPT           :1; /*!< Disable Pre-empt, bit 16 */
#if defined(C021)
         uint16 _FSPRD_Reserved_23_17  :7;/*!< Reserved, bits 23:17 */
         uint16 ROM_KEY                :4;/*!< ROM_KEY, bits 27:24 */
         uint16 _FSPRD_Reserved_31_28  :4;/*!< Reserved, bits 31:28 */
#else
         uint16 _FSPRD_Reserved_31_17 :15;/*!< Reserved, bits 31:17 */
#endif
      } FSPRD_BITS;
   } FsPrd;

   /*!
       Defines whole and bit level accesses to the Error Correction Control Register1 - 0x08
   */
   union FEDACCTRL1
   {
      uint32 u32Register; /* Error Correction Control Register1, bits 31:0 */
      struct
      {
         uint16 EDACEN                     :4;/*!< Error Detection and Correction Enable, bits 3:0 */
         uint16 EZCV                       :1;/*!< Zero Condition Valid, bit 4 */
         uint16 EOCV                       :1;/*!< One Condition Valid, bit 5 */
         uint16 _FEDACCTRL1_Reserved_07_06 :2;/*!< Reserved, bits 7:6 */
         uint16 EPEN                       :1;/*!< Error Profiling Enable, bit 8 */
         uint16 EZFEN                      :1;/*!< Error on Zero Fail Enable, bit 9 */
         uint16 EOFEN                      :1;/*!< Error on One Fail Enable, bit 10 */
         uint16 _FEDACCTRL1_Reserved_15_11 :5;/*!< Reserved, bits 15:11 */
         uint16 EDACMODE                   :4;/*!< Error Correction Mode, bits 19:16 */
         uint16 _FEDACCTRL1_Reserved_23_20 :4;/*!< Reserved, bits 23:20 */
         uint16 SUSP_IGNR                  :1;/*!< Suspend Ignore, bit 24 */
         uint16 _FEDACCTRL1_Reserved_31_25 :7;/*!< Reserved, bits 31:25 */
      } FEDACCTRL1_BITS;
   } FedAcCtrl1;

   /*!
       Defines whole and bit level accesses to the Error Correction Control Register2 - 0x0C
   */
   union FEDACCTRL2
   {
      uint32 u32Register; /* Error Correction Control Register2, bits 31:0 */
      struct
      {
         uint16 SEC_THRESHOLD              :16;/*!< Single Error Correction Threshold, bits 15:0 */
         uint16 _FEDACCTRL2_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FEDACCTRL2_BITS;
   } FedAcCtrl2;

   /*!
       Defines whole and bit level accesses to the Error Correction Counter Register - 0x10
   */
   union FCOR_ERR_CNT
   {
      uint32 u32Register; /* Error Correction Counter Register, bits 31:0 */
      struct
      {
         uint16 COR_ERR_CNT                  :16;/*!< Correctable Error Counter, bits 15:0 */
         uint16 _FCOR_ERR_CNT_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FCOR_ERR_CNT_BITS;
   } FcorErrCnt;

   /*!
       Defines whole and bit level accesses to the Correctable Error Address Register - 0x14
   */
   union FCOR_ERR_ADD
   {
      uint32 u32Register; /* Correctable Error Address Register, bits 31:0 */
   } FcorErrAdd;

   /*!
       Defines whole and bit level accesses to the Correctable Error Position Register - 0x18
   */
   union FCOR_ERR_POS
   {
      uint32 u32Register; /* Correctable Error Position Register, bits 31:0 */
      struct
      {
         uint16  SERR_POS                     :8; /*!< Single Error Position, bits 7:0 */
         uint16  ECC_ERR                      :1; /*!< Error Type, bit 8 */
         uint16  B2_ERR                       :1; /*!< Bus 2 error position, bit 9 */
         uint16 _FCOR_ERR_POS_Reserved_15_10  :6;/*!< Reserved, bits 31:10 */
         uint16 _FCOR_ERR_POS_Reserved_31_16  :16;/*!< Reserved, bits 31:10 */
      } FCOR_ERR_POS_BITS;
   } FcorErrPos;

   /*!
       Defines whole and bit level accesses to the Error Status Register - 0x1C
   */
   union FEDACSTATUS
   {
      uint32 u32Register; /* Error Status Register, bits 31:0 */
      struct
      {
         uint16 ERR_PRF_FLG                 :1;/*!< Error Profiling Status Flag, bit 0 */
         uint16 ERR_ZERO_FLG                :1;/*!< Error On Zero Fail Status Flag, bit 1 */
         uint16 ERR_ONE_FLG                 :1;/*!< Error On One Fail Status Flag, bit 2 */
         uint16 D_COR_ERR                   :1;/*!< Diagnostic Correctable Error Status Flag, bit 3 */
         uint16 ECC0_MAL_ERR                :1;/*!< ECC Malfunction Status Flag, bit 4 */
         uint16 ECC1_MAL_ERR                :1;/*!< ECC Malfunction Status Flag, bit 5 */
         uint16 COM0_MAL_GOOD               :1;/*!< Compare Malfunction Flag, bit 6 */
         uint16 COM1_MAL_GOOD               :1;/*!< Compare Malfunction Flag, bit 7 */
         uint16 ECC_MUL_ERR                 :1;/*!< Multiple bit ECC or Parity Error Status Flag, bit 8 */
         uint16 BUF_PAR_ERR                 :1;/*!< Pipeline Buffer Parity Error Status Flag, bit 9 */
         uint16 ADD_PAR_ERR                 :1;/*!< Address Parity Error, bit 10 */
         uint16 ADD_TAG_ERR                 :1;/*!< Address Tag Register Error Status Flag, bit 11 */
         uint16 D_UNC_ERR                   :1;/*!< Diagnostic Un-correctable Error Status Flag, bit 12 */
         uint16 B2_ERR_IS_EE                :1;/*!< Bus 2 Error is due to EEPROM, bit 13 */
         uint16 _FEDACSTATUS_Reserved_15_14 :2;/*!< Reserved, bits 15:14 */
         uint16 B2_COR_ERR                  :1;/*!< Bus2 Correctable Error, bit 16 */
         uint16 B2_UNC_ERR                  :1;/*!< Bus2 Uncorrectable Error, bit 17 */
         uint16 ECCB2_MAL_ERR               :1;/*!< Bus2 ECC Malfunction Status Flag, bit 18 */
         uint16 COMB2_BUS_MAL_GOOD          :1;/*!< Bus2 Compare Malfunction Flag, bit 19 */
         uint16 ECC2_MAL_ERR                :1;/*!< ECC Malfunction Status Flag, bit 20 */
         uint16 ECC3_MAL_ERR                :1;/*!< ECC Malfunction Status Flag, bit 21 */
         uint16 COM2_MAL_GOOD               :1;/*!< Compare Malfunction Flag, bit 22 */
         uint16 COM3_MAL_GOOD               :1;/*!< Compare Malfunction Flag, bit 23 */
         uint16 FSM_DONE                    :1;/*!< FSM is Finished, bit 24 */
         uint16 RVF_INT                     :1;/*!< FSM command Read_verify failed interrupt, bit 25 */
         uint16 _FEDACSTATUS_Reserved_31_26 :6;/*!< Reserved, bits 31:26 */
      } FEDACSTATUS_BITS;
   } FedAcStatus;

   /*!
       Defines whole and bit level accesses to the Un-correctable Error Address Register - 0x20
   */
   union FUNC_ERR_ADD
   {
      uint32 u32Register; /* Error Status Register, bits 31:0 */
   } FuncErrAdd;

   /*!
       Defines whole and bit level accesses to the Error Detection Sector Disable Register - 0x24
   */
   union FEDACSDIS
   {
      uint32 u32Register; /* Error Detection Sector Disable Register, bits 31:0 */
      struct
      {
         uint16 SectorID0              :4;/*!< Sector ID0 , bits 3:0 */
         uint16 _FEDACSDIS_Reserved_04 :1;/*!< Reserved, bit 4 */
         uint16 BankID0                :3;/*!< Bank ID0 , bits 7:5 */
         uint16 SectorID0_inverse      :4;/*!< Sector ID0 Inverse, bits 11:8 */
         uint16 _FEDACSDIS_Reserved_12 :1;/*!< Reserved, bit 12 */
         uint16 BankID0_inverse        :3;/*!< Bank ID0 Inverse, bits 15:13 */
         uint16 SectorID1              :4;/*!< Sector ID1 , bits 19:16 */
         uint16 _FEDACSDIS_Reserved_20 :1;/*!< Reserved, bit 20 */
         uint16 BankID1                :3;/*!< Bank ID1 , bits 23:21 */
         uint16 SectorID1_inverse      :4;/*!< Sector ID1 Inverse, bits 27:24 */
         uint16 _FEDACSDIS_Reserved_28 :1;/*!< Reserved, bit 28 */
         uint16 BankID1_inverse        :3;/*!< Bank ID1 Inverse, bits 31:29 */
      } FEDACSDIS_BITS;
   } FedAcsDis;

   /*!
       Defines whole and bit level accesses to the Primary Address Tag Register - 0x28
   */
   union FPRIM_ADD_TAG
   {
      uint32 u32Register; /* Primary Address Tag Register, bits 31:0 */
      struct
      {
         uint16 PRIM_ADD_TAG_0_15             :16;/*!< Primary Address Tag Register, bits 15:0 */
         uint16 PRIM_ADD_TAG_16_22            :7;/*!< Primary Address Tag Register, bits 22:16 */
         uint16 _FPRIM_ADD_TAG_Reserved_31_23 :9;/*!< Reserved, bits 31:23 */
      } FPRIM_ADD_TAG_BITS;
   } FprimAddTag;

   /*!
       Defines whole and bit level accesses to the Redundant Address Tag Register - 0x2C
   */
   union FREDU_ADD_TAG
   {
      uint32 u32Register; /* Redundant Address Tag Register, bits 31:0 */
      struct
      {
         uint16 REDU_ADD_TAG_0_15             :16;/*!< Redundant Address Tag Register, bits 15:0 */
         uint16 REDU_ADD_TAG_16_22            :7;/*!< Redundant Address Tag Register, bits 22:16 */
         uint16 _FREDU_ADD_TAG_Reserved_31_23 :9;/*!< Reserved, bits 31:23 */
      } FREDU_ADD_TAG_BITS;
   } FreduAddTag;

   /*!
       Defines whole and bit level accesses to the Bank Sector Enable Register - 0x30
   */
   union FBPROT
   {
      uint32 u32Register; /* Bank Protection Register, bits 31:0 */
      struct
      {
         uint16  PROTL1DIS              :1; /*!< Level 1 Protection Disabled, bit 0 */
         uint16 _FBPROT_Reserved_15_02  :15;/*!< Reserved, bits 31:1 */
         uint16 _FBPROT_Reserved_31_16  :16;/*!< Reserved, bits 31:1 */
      } FBPROT_BITS;
   } Fbprot;

   /*!
       Defines whole and bit level accesses to the Bank Protection Register - 0x34
   */
   union FBSE
   {
      uint32 u32Register; /* Bank Protection Register, bits 31:0 */
      struct
      {
         uint16 BSE                  :16;/*!< Bank Sector Enable, bits 15:0 */
         uint16 _FBSE_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FBSE_BITS;
   } Fbse;

   /*!
       Defines whole and bit level accesses to the Bank Busy Register - 0x38
   */
   union FBBUSY
   {
      uint32 u32Register; /* Bank Busy Register, bits 31:0 */
      struct
      {
         uint16  BUSY                   :8; /*!< Bank Busy, bits 7:0 */
         uint16 _FBBUSY_Reserved_15_08  :8;/*!< Reserved, bits 31:8 */
         uint16 _FBBUSY_Reserved_31_06  :16;/*!< Reserved, bits 31:8 */
      } FBPROT_BITS;
   } Fbbusy;

   /*!
       Defines whole and bit level accesses to the Bank Access Control Register - 0x3C
   */
   union FBAC
   {
      uint32 u32Register; /* Bank Access Control Register, bits 31:0 */
      struct
      {
         uint16 VREADS               :8;/*!< VREAD Setup, bits 7:0 */
         uint16 BAGP                 :8;/*!< Bank Active Grace Period, bits 15:8 */
         uint16 OTPPROTDIS           :8;/*!< OTP Sector Protection Disable, bits 23:16 */
         uint16 _FBAC_Reserved_31_24 :8;/*!< Reserved, bits 31:24 */
      } FBAC_BITS;
   } Fbac;

   /*!
       Defines whole and bit level accesses to the Bank Fallback Power Register - 0x40
   */
   union FBFALLBACK
   {
      uint32 u32Register; /* Bank Fallback Power Register, bits 31:0 */
      struct
      {
         uint16 BANKPWR0             :2;/*!< Bank 0 Fallback Power Mode, bits 1:0 */
         uint16 BANKPWR1             :2;/*!< Bank 1 Fallback Power Mode, bits 3:2 */
         uint16 BANKPWR2             :2;/*!< Bank 2 Fallback Power Mode, bits 5:4 */
         uint16 BANKPWR3             :2;/*!< Bank 3 Fallback Power Mode, bits 7:6 */
         uint16 BANKPWR4             :2;/*!< Bank 4 Fallback Power Mode, bits 9:8 */
         uint16 BANKPWR5             :2;/*!< Bank 5 Fallback Power Mode, bits 11:10 */
         uint16 BANKPWR6             :2;/*!< Bank 6 Fallback Power Mode, bits 13:12 */
         uint16 BANKPWR7             :2;/*!< Bank 7 Fallback Power Mode, bits 15:14 */
         uint16 REG_PWRSAV           :4;/*!< Power saving clocking control, bits 19:16 */
         uint16 _FBAC_Reserved_23_20 :4;/*!< Reserved, bits 23:20 */
         uint16 FSM_PWRSAV           :4;/*!< Power saving clocking control, bits 27:24 */
         uint16 _FBAC_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FBFALLBACK_BITS;
   } Fbfallback;

   /*!
       Defines whole and bit level accesses to the Bank/Pump Ready Register - 0x44
   */
   union FBPRDY
   {
      uint32 u32Register; /* Bank/Pump Ready Register, bits 31:0 */
      struct
      {
         uint16 BANKRDY                :8;/*!< Bank Ready, bits 7:0 */
         uint16 _FBPRDY_Reserved_14_08 :7;/*!< Reserved, bits 14:8 */
         uint16 PUMPRDY                :1;/*!< Pump Ready, bit 15 */
         uint16 BANKBUSY               :8;/*!< Bank Busy with FSM, SW_INTF, CPU or PMT, bits 23:16 */
         uint16 _FBPRDY_Reserved_31_24 :8;/*!< Reserved, bits 31:24 */
      } FBPRDY_BITS;
   } Fbprdy;

   /*!
       Defines whole and bit level accesses to the Pump Access Control Register 1 - 0x48
   */
   union FBAC1
   {
      uint32 u32Register; /* Bank Access Control Register 1, bits 31:0 */
      struct
      {
         uint16  PUMPPWR               :1; /*!< Flash Charge Pump Fallback Power Mode, bit 0 */
         uint16 _FBAC1_Reserved_15_01 :15;/*!< Reserved, bits 15:1 */
         uint16 PSLEEPTDIS            :11;/*!< Pump Sleep, bits 26:16 */
         uint16  _FBAC1_Reserved_31_27 :5; /*!< Reserved, bits 31:27 */
      } FBAC1_BITS;
   } Fbac1;

   /*!
       Defines whole and bit level accesses to the Pump Access Control Register 2 - 0x4C
   */
   union FBAC2
   {
      uint32 u32Register; /* Bank Access Control Register 2, bits 31:0 */
      struct
      {
         uint16 PAGP                  :16;/*!< Pump Active Grace Period, bits 15:0 */
         uint16 _FBAC2_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FBAC2_BITS;
   } Fbac2;

   /*!
       Defines whole and bit level accesses to the Module Access Control Register - 0x50
   */
   union FMAC
   {
      uint32 u32Register; /* Module Access Control Register, bits 31:0 */
      struct
      {
         uint16  BANK                 :3; /*!< Bank Enable, bits 2:0 */
         uint16 _FMAC_Reserved_15_03  :13;/*!< Reserved, bits 31:3 */
         uint16 _FMAC_Reserved_31_15  :16;/*!< Reserved, bits 31:3 */
      } FMAC_BITS;
   } Fmac;

   /*!
       Defines whole and bit level accesses to the Module Status Register - 0x54
   */
   union FMSTAT
   {
      uint32 u32Register; /* Module Status Register, bits 31:0 */
      struct
      {
         uint16 SLOCK                   :1; /*!< Sector Lock Status, bit 0 */
         uint16 PSUSP                   :1; /*!< Program Suspend, bit 1 */
         uint16 ESUSP                   :1; /*!< Erase Suspend, bit 2 */
         uint16 VOLSTAT                 :1; /*!< Core Voltage Status, bit 3 */
         uint16 CSTAT                   :1; /*!< Command Status, bit 4 */
         uint16 INVDAT                  :1; /*!< Invalid Data, bit 5 */
         uint16 PGM                     :1; /*!< Program Active, bit 6 */
         uint16 ERS                     :1; /*!< Erase Active, bit 7 */
         uint16 Busy                    :1; /*!< Busy, bit 8 */
         uint16 CV                      :1; /*!< Compact Verify, bit 9 */
         uint16 EV                      :1; /*!< Erase verify, bit 10 */
         uint16 PCV                     :1; /*!< Precondidition verify, bit 11 */
         uint16 PGV                     :1; /*!< Program verify, bit 12 */
         uint16 DBF                     :1; /*!< Disturbance Test Fail, bit 13 */
         uint16 ILA                     :1; /*!< Illegal Address, bit 14 */
         uint16 RVF                     :1; /*!< Read Verify Failure, bit 15 */
         uint16 RDVER                   :1; /*!< Read Verify command currently underway, bit 16 */
         uint16 RVSUSP                  :1; /*!< Read Verify Suspend, bit 17 */
         uint16 _FMSTAT_Reserved_31_18 :14;/*!< Reserved, bits 31:18 */
      } FMSTAT_BITS;
   } FmStat;

   /*!
       Defines whole and bit level accesses to the EEPROM Emulation Data MSW Register - 0x58
   */
   union FEMU_DMSW
   {
      uint32 u32Register; /* EEPROM Emulation Data MSW Register, bits 31:0 */
   } FemuDmsw;

   /*!
       Defines whole and bit level accesses to the EEPROM Emulation Data LSW Register - 0x5C
   */
   union FEMU_DLSW
   {
      uint32 u32Register; /* EEPROM Emulation Data LSW Register, bits 31:0 */
   } FemuDlsw;

   /*!
       Defines whole and bit level accesses to the EEPROM Emulation ECC Register - 0x60
   */
   union FEMU_ECC
   {
      uint32 u32Register; /* EEPROM Emulation ECC Register, bits 31:0 */
      struct
      {
         uint16  EMU_ECC                  :8; /*!< EEPROM Emulation ECC, bits 7:0 */
         uint16 _FEMU_ECC_Reserved_15_08  :8;/*!< Reserved, bits 31:8 */
         uint16 _FEMU_ECC_Reserved_31_16  :16;/*!< Reserved, bits 31:8 */
      } FEMU_ECC_BITS;
   } FemuEcc;

   /*!
       Defines whole and bit level accesses to the Flash Lock Register - 0x64
   */
   union FLOCK
   {
      uint32 u32Register; /* Flash Lock Register, bits 31:0 */
      struct
      {
         uint16 ENCOM                 :16;/*!< Enable Command Registers, bits 15:0 */
         uint16 _FLOCK_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FLOCK_BITS;
   } Flock;

   /*!
       Defines whole and bit level accesses to the EEPROM Emulation Address Register - 0x68
   */
   union FEMU_ADDR
   {
      uint32 u32Register; /* EEPROM Emulation Address, bits 31:0 */
      struct
      {
         uint16 EMU_ADDR_15_0                  :16;/*!< EEPROM Emulation Address, bits 21:0 */
         uint16 EMU_ADDR_21_16                 :6;/*!< EEPROM Emulation Address, bits 21:0 */
         uint16 _FEMU_ADDR_Reserved_31_22      :10;/*!< Reserved, bits 31:22 */
      } FEMU_ADDR_BITS;
   } FemuAddr;

   /*!
       Defines whole and bit level accesses to the Diagnostic Control Register - 0x6C
   */
   union FDIAGCTRL
   {
      uint32 u32Register; /* Diagnostic Control Register, bits 31:0 */
      struct
      {
         uint16 DIAGMODE                  :3;/*!< Diagnostic Mode, bits 2:0 */
         uint16 _FDIAGCTRL_Reserved_07_03 :5;/*!< Reserved, bits 7:3 */
         uint16 DIAG_BUF_SEL              :2;/*!< Diagnostic Buffer Select, bits 9:8 */
         uint16 _FDIAGCTRL_Reserved_11_10 :2;/*!< Reserved, bits 11:10 */
         uint16 DIAG_ECC_SEL              :3;/*!< Diagnostic SECDED Select, bits 14-12 */
         uint16 _FDIAGCTRL_Reserved_15    :1;/*!< Reserved, bit 15 */
         uint16 DIAG_EN_KEY               :4;/*!< Diagnostic Enable Key, bits 19:16 */
         uint16 _FDIAGCTRL_Reserved_23_20 :4;/*!< Reserved, bits 23:20 */
         uint16 DIAG_TRIG                 :1;/*!< Diagnostic Trigger, bit 24 */
         uint16 _FDIAGCTRL_Reserved_31_25 :7;/*!< Reserved, bits 31:25 */
      } FDIAGCTRL_BITS;
   } FdiagCtrl;

   /*!
       Defines whole and bit level accesses to the Uncorrected Raw Data High Register - 0x70
   */
   union FRAW_DATAH
   {
      uint32 u32Register; /* Uncorrected Raw Data High, bits 31:0 */
   } FrawDatah;

   /*!
       Defines whole and bit level accesses to the Uncorrected Raw Data Low Register - 0x74
   */
   union FRAW_DATAL
   {
      uint32 u32Register; /* Uncorrected Raw Data Low, bits 31:0 */
   } FrawDatal;

   /*!
       Defines whole and bit level accesses to the Uncorrected Raw ECC Register - 0x78
   */
   union FRAW_ECC
   {
      uint32 u32Register; /* Uncorrected Raw ECC, bits 31:0 */
      struct
      {
         uint16  RAW_ECC                  :8; /*!< Uncorrected Raw ECC, bits 7:0 */
         uint16 _FRAW_ECC_Reserved_15_08  :8;/*!< Reserved, bits 31:8 */
         uint16 _FRAW_ECC_Reserved_31_16  :16;/*!< Reserved, bits 31:8 */
      } FRAW_ECC_BITS;
   } FrawEcc;

   /*!
       Defines whole and bit level accesses to the Parity Override Register - 0x7C
   */
   union FPAR_OVR
   {
      uint32 u32Register; /* Parity Override, bits 31:0 */
      struct
      {
         uint16  DAT_INV_PAR              :8; /*!< Data Odd Parity, bits 7:0 */
         uint16  ADD_INV_PAR              :1; /*!< Address Odd Parity, bit 8 */
         uint16  PAR_OVR_KEY              :3; /*!< Parity Override Key, bits 11:9 */
         uint16  BUS_PAR_DIS              :4; /*!< Disable bus parity, bits 15:12 */
         uint16  BNK_INV_PAR              :1; /*!< Buffer Invert Parity, bit 16 */
         uint16 _FPAR_OVR_Reserved_31_17 :15;/*!< Reserved, bits 31:17 */
      } FPAR_OVR_BITS;
   } FparOvr;

   /*!
       Defines whole and bit level accesses to the VREADCT Register - 0x80
   */
   union FVREADCT
   {
      uint32 u32Register; /* VREADCT Register, bits 31:0 */
      struct
      {
         uint16  VREADCT                  :4; /*!< VREADCT, bits 3:0 */
         uint16 _FVREADCT_Reserved_15_04  :12;/*!< Reserved, bits 31:4 */
         uint16 _FVREADCT_Reserved_31_16  :16;/*!< Reserved, bits 31:4 */
      } FVREADCT_BITS;
   } Fvreadct;

   /*!
       Defines whole and bit level accesses to the FVHVCT1 Register - 0x84
   */
   union FVHVCT1
   {
      uint32 u32Register; /* FVHVCT1 Register, bits 31:0 */
      struct
      {
         uint16 VHVCT_PV                :9; /*!< VHVCT_PV, bits 8:0 */
         uint16  _FVHVCT1_Reserved_15_09 :7;/*!< Reserved, bits 15:9 */
         uint16 VHVCT_E                 :9; /*!< VHVCT_E, bits 24:16 */
         uint16  _FVHVCT1_Reserved_31_25 :7;/*!< Reserved, bits 31:25 */
      } FVHVCT1_BITS;
   } Fvhvct1;

   /*!
       Defines whole and bit level accesses to the FVHVCT2 Register - 0x88
   */
   union FVHVCT2
   {
      uint32 u32Register; /* FVHVCT2 Register, bits 31:0 */
      struct
      {
         uint16 VHVCT_C                 :9; /*!< VHVCT_C, bits 8:0 */
         uint16  _FVHVCT2_Reserved_15_09 :7;/*!< Reserved, bits 15:9 */
         uint16 VHVCT_P                 :9; /*!< VHVCT_P, bits 24:16 */
         uint16  _FVHVCT2_Reserved_31_25 :7;/*!< Reserved, bits 31:25 */
      } FVHVCT2_BITS;
   } Fvhvct2;

   /*!
       Defines whole and bit level accesses to the FVHVCT3 Register - 0x8C
   */
   union FVHVCT3
   {
      uint32 u32Register; /* FVHVCT3 Register, bits 31:0 */
      struct
      {
         uint16 VHVCT_READ              :9; /*!< VHVCT_READ, bits 8:0 */
         uint16  _FVHVCT3_Reserved_15_09 :7;/*!< Reserved, bits 15:9 */
         uint16  WCT                     :4; /*!< WCT, bits 19:16 */
         uint16 _FVHVCT3_Reserved_31_20 :12;/*!< Reserved, bits 31:20 */
      } FVHVCT3_BITS;
   } Fvhvct3;

   /*!
       Defines whole and bit level accesses to the VNVCT Register - 0x90
   */
   union FVNVCT
   {
      uint32 u32Register; /* VNVCT Register, bits 31:0 */
      struct
      {
         uint16 VIN_CT                  :5; /*!< VIN_CT, bits 4:0 */
         uint16  _FVNVCT_Reserved_07_05 :3; /*!< Reserved, bits 7:5 */
         uint16  VCG2P5CT               :5; /*!< VCG2P5CT, bits 13:8 */
         uint16 _FVNVCT_Reserved_15_13  :3;/*!< Reserved, bits 31:13 */
         uint16 _FVNVCT_Reserved_31_16  :16;/*!< Reserved, bits 31:13 */
      } FVNVCT_BITS;
   } Fvnvct;

   /*!
       Defines whole and bit level accesses to the VLSP Register - 0x94
   */
   union FVSLP
   {
      uint32 u32Register; /* VLSP Register, bits 31:0 */
      struct
      {
         uint16 _FVLSP_Reserved_11_00 :12; /*!< Reserved, bits 11:0 */
         uint16  VSL_P                 :4; /*!< VSL_P, bits 15:12 */
         uint16 _FVLSP_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FVSLP_BITS;
   } Fvslp;

   /*!
       Defines whole and bit level accesses to the VWLCT Register - 0x98
   */
   union FVWLCT
   {
      uint32 u32Register; /* VWLCT Register, bits 31:0 */
      struct
      {
         uint16  VWLCT_P                :5; /*!< VWLCT_C/P, bits 4:0 */
         uint16 _FVWLCT_Reserved_15_05  :11;/*!< Reserved, bits 31:5 */
         uint16 _FVWLCT_Reserved_31_16  :16;/*!< Reserved, bits 31:5 */
      } FVWLCT_BITS;
   } Fvwlct;

   /*!
       Defines whole and bit level accesses to the FEFUSE Control Register - 0x9C
   */
   union FEFUSECTRL
   {
      uint32 u32Register; /* FEFUSE Control Register, bits 31:0 */
      struct
      {
         uint16 EFUSE_EN                   :4;/*!< Efuse Soft test enable, bits 3:0 */
         uint16 EF_TEST                    :1;/*!< Efuse Test, bit 4 */
         uint16 _FEFUSECTRL_Reserved_07_05 :3;/*!< Reserved, bits 7:5 */
         uint16 EF_CLRZ                    :1;/*!< Efuse Reset, bit 8 */
         uint16 _FEFUSECTRL_Reserved_15_09 :7;/*!< Reserved, bits 15:9 */
         uint16 BP_SEL                     :1;/*!< Bank Pump Select, bit 16 */
         uint16 WRITE_EN                   :1;/*!< WRITE_EN, bit 17 */
         uint16 _FEFUSECTRL_Reserved_23_18 :6;/*!< Reserved, bits 23:18 */
         uint16 CHAIN_SEL                  :3;/*!< CHAIN_SEL, bits 26:24 */
         uint16 _FEFUSECTRL_Reserved_31_27 :5;/*!< Reserved, bits 31:27 */
      } FEFUSE_BITS;
   } FefuseCtrl;

   /*!
       Defines whole and bit level accesses to the FEFUSE Status Register - 0xA0
   */
   union FEFUSESTAT
   {
      uint32 u32Register; /* FEFUSE Status Register, bits 31:0 */
      struct
      {
         uint16  SHIFT_DONE             :1; /*!< Shift Done, bit 0 */
         uint16 _FEFUSE_Reserved_15_01  :15;/*!< Reserved, bits 31:1 */
         uint16 _FEFUSE_Reserved_31_16  :16;/*!< Reserved, bits 31:1 */
      } FEFUSESTAT_BITS;
   } FefuseStat;

   /*!
       Defines whole and bit level accesses to the FEFUSE DATA Register - 0xA4
   */
   union FEFUSEDATA
   {
      uint32 u32Register; /* FEFUSE DATA Register, bits 31:0 */
   } FefuseData;

   /*!
       Defines whole and bit level accesses to the SEQ PUMP Register - 0xA8
   */
   union FSEQPMP
   {
      uint32 u32Register; /* SEQ PUMP Register, bits 31:0 */
      struct
      {
         uint16  SEQ_PUMP                :8; /*!< SEQ_PUMP, bits 7:0 */
         uint16 _FSEQPMP_Reserved_15_08  :8;/*!< Reserved, bits 31:8 */
         uint16 _FSEQPMP_Reserved_31_15  :16;/*!< Reserved, bits 31:8 */
      } FSEQPMP_BITS;
   } FseqPmp;

   /*!
       Defines whole and bit level accesses to the Clock Trimming Register - 0xAC
   */
   union FCLKTRIM
   {
      uint32 u32Register; /* Clock Trimming Register, bits 31:0 */
      struct
      {
         uint16 CLK_TRIM_0_15            :16;/*!< Pump Oscillator clock trimming value, bits 18:0 */
         uint16 CLK_TRIM_18_16           :3;/*!< Pump Oscillator clock trimming value, bits 18:0 */
         uint16 _FCLKTRIM_Reserved_31_19 :13;/*!< Reserved, bits 31:19 */
      } FCLKTRIM_BITS;
   } FclkTrim;

#if defined(C021)
   /*!
       Defines whole and bit level accesses to the ROM testing bits Register - 0xB0
   */
   union ROM_TEST
   {
      uint32 u32Register; /* ROM testing bits, bits 31:0 */
      struct
      {
         uint16  ROM_KEY                  :4; /*!< ROM Key, bits 3:0 */
         uint16  _ROM_TEST_Reserved_07_04 :4; /*!< Reserved, bits 7:4 */
         uint16 ROM_TEST                 :24;/*!< ROM testing bits, bits 18:0 */
      } ROM_TEST_BITS;
   } RomTest;
#else
   uint32 _Reserved_B0;/* Reserved Address Location 0xB0 */
#endif

   uint32 _Reserved_B4_BC[3];/* Reserved Address Locations 0xB4 - 0xBC */

   /*!
       Defines whole and bit level accesses to the Error Detection Sector Disable2 Register - 0xC0
   */
   union FEDACSDIS2
   {
      uint32 u32Register; /* Error Detection Sector Disable Register, bits 31:0 */
      struct
      {
         uint16 SectorID2               :4;/*!< Sector ID2 , bits 3:0 */
         uint16 _FEDACSDIS2_Reserved_4  :1;/*!< Reserved, bit 4 */
         uint16 BankID2                 :3;/*!< Bank ID2 , bits 7:5 */
         uint16 SectorID2_inverse       :4;/*!< Sector ID2 Inverse, bits 11:8 */
         uint16 _FEDACSDIS2_Reserved_12 :1;/*!< Reserved, bit 12 */
         uint16 BankID2_inverse         :3;/*!< Bank ID2 Inverse, bits 15:13 */
         uint16 SectorID3               :4;/*!< Sector ID3 , bits 19:16 */
         uint16 _FEDACSDIS2_Reserved_20 :1;/*!< Reserved, bit 20 */
         uint16 BankID3                 :3;/*!< Bank ID3 , bits 23:21 */
         uint16 SectorID3_inverse       :4;/*!< Sector ID3 Inverse, bits 27:24 */
         uint16 _FEDACSDIS2_Reserved_28 :1;/*!< Reserved, bit 28 */
         uint16 BankID3_inverse         :3;/*!< Bank ID3 Inverse, bits 31:29 */
      } FEDACSDIS2_BITS;
   } FedAcsDis2;

   uint32 _Reserved_C4_FC[15];/* Reserved Address Locations 0xC4 - 0xFC */

   /*!
       Defines whole and bit level accesses to the Bank Signal Strobe Register - 0x100
   */
   union FBSTROBES
   {
      uint32 u32Register; /* Bank Signal Strobe Register, bits 31:0 */
      struct
      {
         uint16 _FBSTROBES_Reserved_01_00 :2;/*!< Reserved, bits 1:0 */
         uint16 TEZ                       :1;/*!< TEZ, bit 2 */
         uint16 OTP                       :1;/*!< OTP, bit 3 */
         uint16 TI_OTP                    :1;/*!< TI_OTP, bit 4 */
         uint16 PRECOL                    :1;/*!< PRECOL, bit 5 */
         uint16 NOCOLRED                  :1;/*!< NOCOLRED, bit 6 */
         uint16 _FBSTROBES_Reserved_07    :1;/*!< Reserved, bit 7 */
         uint16 CTRLENZ                   :1;/*!< Control Enable, bit 8 */
         uint16 _FBSTROBES_Reserved_15_9  :7;/*!< Reserved, bits 15:9 */
         uint16 FCLKEN                    :1;/*!< Flash Clock Enable, bit 16 */
         uint16 _FBSTROBES_Reserved_23_17 :7;/*!< Reserved, bits 23:17 */
         uint16 ECBIT                     :1;/*!< ECC Bit Enable, bit 24 */
         uint16 _FBSTROBES_Reserved_31_25 :7;/*!< Reserved, bits 31:25 */
      } FBSTROBES_BITS;
   } Fbstrobes;

   /*!
       Defines whole and bit level accesses to the Pump Signal Strobe Register - 0x104
   */
   union FPSTROBES
   {
      uint32 u32Register; /* Pump Signal Strobe Register, bits 31:0 */
      struct
      {
         uint16 _5VPWRDNZ                  :1; /*!< 5VPWRDNZ, bit 0 */
         uint16 _3VPWRDNZ                  :1; /*!< 3VPWRDNZ, bit 1 */
         uint16 _FBSTROBES_Reserved_07_02  :6; /*!< Reserved, bits 7:2 */
         uint16  EXECUTEZ                  :1; /*!< EXECUTEZ, bit 8 */
         uint16 _FPSTROBES_Reserved_15_09  :7;/*!< Reserved, bits 31:9 */
         uint16 _FPSTROBES_Reserved_31_16  :16;/*!< Reserved, bits 31:9 */
      } FPSTROBES_BITS;
   } Fpstrobes;

   /*!
       Defines whole and bit level accesses to the Bank Mode Register - 0x108
   */
   union FBMODE
   {
      uint32 u32Register; /* Bank Mode Register, bits 31:0 */
      struct
      {
         uint16  MODE                   :3; /*!< Bank and Pump Mode, bits 2:0 */
         uint16 _FBMODE_Reserved_15_03  :13;/*!< Reserved, bits 31:3 */
         uint16 _FBMODE_Reserved_31_16  :16;/*!< Reserved, bits 31:3 */
      } FBMODE_BITS;
   } Fbmode;

   /*!
       Defines whole and bit level accesses to the TCR Register - 0x10C
   */
   union FTCR
   {
      uint32 u32Register; /* TCR Register, bits 31:0 */
      struct
      {
         uint16  TCR                  :7; /*!< Test Control Register mode for Banks and Pumps, bits 6:0 */
         uint16 _FTCR_Reserved_15_07  :9;/*!< Reserved, bits 31:7 */
         uint16 _FTCR_Reserved_31_16  :16;/*!< Reserved, bits 31:7 */
      } FTCR_BITS;
   } Ftcr;

   /*!
       Defines whole and bit level accesses to the Bank Addr Register - 0x110
   */
   union FADDR
   {
      uint32 u32Register; /* Bank Addr Register, bits 31:0 */
   } Faddr;

   /*!
       Defines whole and bit level accesses to the PMT Control Register - 0x114
   */
   union FPMT_CTRL
   {
      uint32 u32Register; /* PMT Control Register, bits 31:0 */
      struct
      {
         uint16 ADDR_INCR                 :11;/*!< Address Increment, bits 10:0 */
         uint16  TP_BUSY_SEL               :3; /*!< TP_BUSY select, bits 13:11 */
         uint16  FL_DATAIN_SEL             :2; /*!< Flash data input select, bits 15:14 */
         uint16  TP_DATA_SEL               :2; /*!< TP_DATA output port selection, bits 17:16 */
         uint16  WDAT_CHANGE               :2; /*!< Randomize or invert FWPWRITE register, bits 19:18 */
         uint16  SW_MODE                   :1; /*!< Switch modes, bit 20 */
         uint16 _FPMT_CTRL_Reserved_31_21 :11;/*!< Reserved, bits 31:21 */
      } FPMT_CTRL_BITS;
   } FpmtCtrl;

   /*!
       Defines whole and bit level accesses to the PBIST Control Register - 0x118
   */
   union PBIST_CTRL
   {
      uint32 u32Register; /* PBIST Control Register, bits 31:0 */
      struct
      {
         uint16  PBIST_KEY                  :4; /*!< PBIST enable Key, bits 3:0 */
         uint16  GRP1_EN                    :1; /*!< PBIST signal Group 1 Enable, bit 4 */
         uint16 _PBIST_CTRL_Reserved_15_05  :11;/*!< Reserved, bits 31:5 */
         uint16 _PBIST_CTRL_Reserved_31_16  :16;/*!< Reserved, bits 31:5 */
      } PBIST_CTRL_BITS;
   } PbistCtrl;

   /*!
       Defines whole and bit level accesses to the FTCTRL Register - 0x11C
   */
   union FTCTRL
   {
      uint32 u32Register; /* FTCTRL Register, bits 31:0 */
      struct
      {
         uint16 _FTCTRL_Reserved_00     :1; /*!< Reserved, bit 0 */
         uint16  TEST_EN                :1; /*!< Enable Test Commands, bit 1 */
         uint16 _FTCTRL_Reserved_15_02 :14;/*!< Reserved, bits 15:2 */
         uint16  WDATA_BLK_CLR          :1; /*!< Block clearing of FWPWRITE register, bit 16 */
         uint16 _FTCTRL_Reserved_23_17  :7;/*!< Reserved, bits 23:17 */
         uint16  AUTOCALC_EN            :1;/*!< AutoCalc Enable, bit 24*/
         uint16 _FTCTRL_Reserved_31_25  :7;/*!< Reserved, bits 31:25 */
      } FTCTRL_BITS;
   } Ftctrl;

   /*!
       Defines whole and bit level accesses to the FWPWRITE0 Register - 0x120
   */
   union FWPWRITE0
   {
      uint32 u32Register; /* FWPWRITE0 Register, bits 31:0 */
   } Fwpwrite0;

   /*!
       Defines whole and bit level accesses to the FWPWRITE1 Register - 0x124
   */
   union FWPWRITE1
   {
      uint32 u32Register; /* FWPWRITE1 Register, bits 31:0 */
   } Fwpwrite1;

   /*!
       Defines whole and bit level accesses to the FWPWRITE2 Register - 0x128
   */
   union FWPWRITE2
   {
      uint32 u32Register; /* FWPWRITE2 Register, bits 31:0 */
   } Fwpwrite2;

   /*!
       Defines whole and bit level accesses to the FWPWRITE3 Register - 0x12C
   */
   union FWPWRITE3
   {
      uint32 u32Register; /* FWPWRITE3 Register, bits 31:0 */
   } Fwpwrite3;

   /*!
       Defines whole and bit level accesses to the FWPWRITE4 Register - 0x130
   */
   union FWPWRITE4
   {
      uint32 u32Register; /* FWPWRITE4 Register, bits 31:0 */
   } Fwpwrite4;

   /*!
       Defines whole and bit level accesses to the FWPWRITE5 Register - 0x134
   */
   union FWPWRITE5
   {
      uint32 u32Register; /* FWPWRITE5 Register, bits 31:0 */
   } Fwpwrite5;

   /*!
       Defines whole and bit level accesses to the FWPWRITE6 Register - 0x138
   */
   union FWPWRITE6
   {
      uint32 u32Register; /* FWPWRITE6 Register, bits 31:0 */
   } Fwpwrite6;

   /*!
       Defines whole and bit level accesses to the FWPWRITE7 Register - 0x13C
   */
   union FWPWRITE7
   {
      uint32 u32Register; /* FWPWRITE7 Register, bits 31:0 */
   } Fwpwrite7;

   /*!
       Defines whole and bit level accesses to the FWPWRITE_ECC Register - 0x140
   */
   union FWPWRITE_ECC
   {
      uint32 u32Register; /* FWPWRITE_ECC Register, bits 31:0 */
      struct
      {
         uint32 WPDATA_287_256; /*!< WPDATA[287:256], bits 31:0 */
      } FWPWRITE_ECC_BITS;
      struct
      {
         uint16 u8Bytes31_24:8;
         uint16 u8Bytes23_16:8;
         uint16 u8Bytes15_08:8;
         uint16 u8Bytes07_00:8;
      } FWPWRITE_ECC_BYTES;
   } FwpwriteEcc;

   /*!
       Defines whole and bit level accesses to the Software Interface Status Register - 0x144
   */
   union FSWSTAT
   {
      uint32 u32Register; /* Software Interface Status Register, bits 31:0 */
      struct
      {
         uint16  SAFELV                 :1; /*!< Low Voltage Safe Signal, bit 0 */
         uint16 _FSWSTAT_Reserved_15_01 :15;/*!< Reserved, bits 31:1 */
         uint16 _FSWSTAT_Reserved_31_16 :16;/*!< Reserved, bits 31:1 */
      } FSWSTAT_BITS;
   } Fswstat;

   uint32 _Reserved_148_1FC[46];/* Reserved Address Locations 0x148 - 0x1FC */

   /*!
       Defines whole and bit level accesses to the FSM Global Control Register - 0x200
   */
   union FSM_GLBCTRL
   {
      uint32 u32Register; /* FSM Global Control, bits 31:0 */
      struct
      {
         uint16  CLKSEL                      :1; /*!< FSM Reference Clock Select, bit 0 */
         uint16 _FSM_GLBCTRL_Reserved_15_01  :15;/*!< Reserved, bits 31:1 */
         uint16 _FSM_GLBCTRL_Reserved_31_16  :16;/*!< Reserved, bits 31:1 */
      } FSM_GLBCTRL_BITS;
   } FsmGlbctrl;

   /*!
       Defines whole and bit level accesses to the FSM State status Register - 0x204
   */
   union FSM_STATE
   {
      uint32 u32Register; /* FSM State status, bits 31:0 */
      struct
      {
         uint16  _FSM_STATE_Reserved_05_00 :6;/*!< Reserved, bits 5:0 */
         uint16  OTP_ACT                   :1; /*!< One Time Programmable array signal is active, bit 6 */
         uint16  TIOTP_ACT                 :1; /*!< TI OTP (Engineering) array signal is active, bit 7 */
         uint16  FSM_ACT                   :1; /*!< Flash State Machine is now active, bit 8 */
         uint16  _FSM_STATE_Reserved_09    :1; /*!< Reserved, bit 9 */
         uint16  EXECUTEZ                  :1; /*!< EXECUTEZ signal value, bit 10 */
         uint16  CTRLENZ                   :1; /*!< CTRLENZ signal value, bit 11 */
         uint16 _FSM_STATE_Reserved_15_12  :4;/*!< Reserved, bits 31:12 */
         uint16 _FSM_STATE_Reserved_31_16  :16;/*!< Reserved, bits 31:12 */
      } FSM_STATE_BITS;
   } FsmState;

   /*!
       Defines whole and bit level accesses to the FSM status Register - 0x208
   */
   union FSM_STATUS
   {
      uint32 u32Register; /* FSM status, bits 31:0 */
      struct
      {
         uint16  INV_DAT                    :1; /*!< Invalid Data is detected, bit 0 */
         uint16  OVR_PUL_CNT                :1; /*!< Over Pulse Count, bit 1 */
         uint16  NON_OP                     :1; /*!< Not currently doing an operation, bit 2 */
         uint16 _FSM_STATUS_Reserved_15_03  :13;/*!< Reserved, bits 31:3 */
         uint16 _FSM_STATUS_Reserved_31_16  :16;/*!< Reserved, bits 31:3 */
      } FSM_STATUS_BITS;
   } FsmStatus;

   /*!
       Defines whole and bit level accesses to the FSM Command Register - 0x20C
   */
   union FSM_COMMAND
   {
      uint32 u32Register; /* FSM Command, bits 31:0 */
      struct
      {
         uint16  FSMCMD                      :6; /*!< Flash State Machine Command, bits 5:0 */
         uint16 _FSM_COMMAND_Reserved_15_06  :10;/*!< Reserved, bits 31:6 */
         uint16 _FSM_COMMAND_Reserved_31_16  :16;/*!< Reserved, bits 31:6 */
      } FSM_COMMAND_BITS;
   } FsmCommand;

   /*!
       Defines whole and bit level accesses to the FSM Program/Erase Operation Setup Register - 0x210
   */
   union FSM_PE_OSU
   {
      uint32 u32Register; /* FSM Program/Erase Operation Setup, bits 31:0 */
      struct
      {
         uint16  ERA_OSU                    :8; /*!< Erase Operation Setup Time, bits 7:0 */
         uint16  PGM_OSU                    :8; /*!< Program Operation Setup Time, bits 15:8 */
         uint16 _FSM_PE_OSU_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_PE_OSU_BITS;
   } FsmPeOsu;

   /*!
       Defines whole and bit level accesses to the FSM Compact Operation Setup Register - 0x214
   */
   union FSM_VSTAT
   {
      uint32 u32Register; /* FSM Compact Operation Setup, bits 31:0 */
      struct
      {
         uint16 _FSM_VSTAT_Reserved_11_00 :12;/*!< Reserved, bits 11:0 */
         uint16  VSTAT_CNT                 :4; /*!< Voltage Status Count, bits 15:12 */
         uint16 _FSM_VSTAT_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_VSTAT_BITS;
   } FsmVstat;

   /*!
       Defines whole and bit level accesses to the FSM Program/Erase Verify Setup Register - 0x218
   */
   union FSM_PE_VSU
   {
      uint32 u32Register; /* FSM Program/Erase Verify Setup, bits 31:0 */
      struct
      {
         uint16  ERA_VSU                    :8; /*!< Erase Verify Setup Time, bits 7:0 */
         uint16  PGM_VSU                    :8; /*!< Program Verify Setup Time, bits 15:8 */
         uint16 _FSM_PE_VSU_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_PE_VSU_BITS;
   } FsmPeVsu;

   /*!
       Defines whole and bit level accesses to the FSM Compare Verify Setup Register - 0x21C
   */
   union FSM_CMP_VSU
   {
      uint32 u32Register; /* FSM Compare Verify Setup, bits 31:0 */
      struct
      {
         uint16 CMP_VSU                     :12;/*!< Compact Verify Setup Time, bits 12:0 */
         uint16  ADD_EXZ                     :4; /*!< Address to EXECUTEZ low setup time, bits 15:12 */
         uint16 _FSM_CMP_VSU_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_CMP_VSU_BITS;
   } FsmCmpVsu;

   /*!
       Defines whole and bit level accesses to the FSM EXECUTEZ to Valid Data Register - 0x220
   */
   union FSM_EX_VAL
   {
      uint32 u32Register; /* FSM EXECUTEZ to Valid Data, bits 31:0 */
      struct
      {
         uint16  EXE_VALD                   :8; /*!< EXECUTEZ low to valid Data, bits 7:0 */
         uint16  REP_VSU                    :8; /*!< Repeat Verify action setup, bits 15:8 */
         uint16 _FSM_EX_VAL_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_EX_VAL_BITS;
   } FsmExVal;

   /*!
       Defines whole and bit level accesses to the FSM Read Mode Hold Register - 0x224
   */
   union FSM_RD_H
   {
      uint32 u32Register; /* FSM Read Mode Hold, bits 31:0 */
      struct
      {
         uint16  RD_H                     :8; /*!< Read mode hold, bits 7:0 */
         uint16 _FSM_RD_H_Reserved_15_08  :8;/*!< Reserved, bits 31:8 */
         uint16 _FSM_RD_H_Reserved_31_16  :16;/*!< Reserved, bits 31:8 */
      } FSM_RD_H_BITS;
   } FsmRdH;

   /*!
       Defines whole and bit level accesses to the FSM Program Hold Register - 0x228
   */
   union FSM_P_OH
   {
      uint32 u32Register; /* FSM Program Hold, bits 31:0 */
      struct
      {
         uint16  _FSM_P_OH_Reserved_07_00 :8; /*!< Reserved, bits 7:0 */
         uint16  PGM_OH                   :8; /*!< EXECUTEZ high to mode change, bits 15:8 */
         uint16 _FSM_P_OH_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_P_OH_BITS;
   } FsmPOh;

   /*!
       Defines whole and bit level accesses to the FSM Erase Operation Hold Register - 0x22C
   */
   union FSM_ERA_OH
   {
      uint32 u32Register; /* FSM Program Hold, bits 31:0 */
      struct
      {
         uint16 ERA_OH                     :16;/*!< EXECUTEZ high to mode change, bits 15:0 */
         uint16 _FSM_ERA_OH_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_ERA_OH_BITS;
   } FsmEraOh;

   /*!
       Defines whole and bit level accesses to the FSM Saved Program Pulses Register - 0x230
   */
   union FSM_SAV_PPUL
   {
      uint32 u32Register; /* FSM Saved Program Pulses, bits 31:0 */
      struct
      {
         uint16 SAV_P_PUL                    :12;/*!< Saved Program Pulses, bits 11:0 */
         uint16 _FSM_SAV_PPUL_Reserved_15_12 :4;/*!< Reserved, bits 31:12 */
         uint16 _FSM_SAV_PPUL_Reserved_31_16 :16;/*!< Reserved, bits 31:12 */
      } FSM_SAV_PUL_BITS;
   } FsmSavPul;

   /*!
       Defines whole and bit level accesses to the FSM Program/Erase Verify Hold Register - 0x234
   */
   union FSM_PE_VH
   {
      uint32 u32Register; /* FSM Program/Erase Verify Hold, bits 31:0 */
      struct
      {
         uint16  ERA_VH                    :8; /*!< Erase Verify Hold, bits 7:0 */
         uint16  PGM_VH                    :8; /*!< Program Verify Hold, bits 15:8 */
         uint16 _FSM_PE_VH_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_PE_VH_BITS;
   } FsmPeVh;

   uint32 _Reserved_238_23C[2];/* Reserved Address Locations 0x238 - 0x23C */

   /*!
       Defines whole and bit level accesses to the FSM Program Pulse Width Register - 0x240
   */
   union FSM_PRG_PW
   {
      uint32 u32Register; /* FSM Program Pulse Width, bits 31:0 */
      struct
      {
         uint16 PROG_PUL_WIDTH             :16;/*!< Program Pulse width, bits 15:0 */
         uint16 _FSM_PRG_PW_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_PRG_PW_BITS;
   } FsmPrgPw;

   /*!
       Defines whole and bit level accesses to the FSM Erase Pulse Width Register - 0x244
   */
   union FSM_ERA_PW
   {
      uint32 u32Register; /* FSM Erase Pulse Width, bits 31:0 */
   } FsmEraPw;

   uint32 _Reserved_248_250[3];/* Reserved Address Location 0x248-0x250 */

   /*!
       Defines whole and bit level accesses to the FSM Saved Erased Pulses Register - 0x254
   */
   union FSM_SAV_ERA_PUL
   {
      uint32 u32Register; /* FSM Saved Erased Pulses, bits 31:0 */
      struct
      {
         uint16 SAV_ERA_PUL                     :12;/*!< Saved Erase Pulses, bits 11:0 */
         uint16 _FSM_SAV_ERA_PUL_Reserved_15_12 :4;/*!< Reserved, bits 31:12 */
         uint16 _FSM_SAV_ERA_PUL_Reserved_31_16 :16;/*!< Reserved, bits 31:12 */
      } FSM_SAV_ERA_PUL_BITS;
   } FsmSavEraPul;

   /*!
       Defines whole and bit level accesses to the FSM Timer Register - 0x258
   */
   union FSM_TIMER
   {
      uint32 u32Register; /* FSM Timer, bits 31:0 */
   } FsmTimer;

   /*!
       Defines whole and bit level accesses to the FSM MODE Register - 0x25C
   */
   union FSM_MODE
   {
      uint32 u32Register; /* FSM MODE Register, bits 31:0 */
      struct
      {
         uint16  CMD                      :3; /*!< Current Flash command operation, bits 2:0 */
         uint16  MODE                     :3; /*!< Current Flash mode operation, bits 5:3 */
         uint16  SAV_ERA_MODE             :3; /*!< Command saved during erase suspend, bits 8:6 */
         uint16  SAV_PGM_CMD              :3; /*!< Command saved during program suspend, bits 11:9 */
         uint16  SUBMODE                  :2; /*!< Current submode of the FSM operation, bits 13:12 */
         uint16  ERA_SUBMODE              :2; /*!< Submode saved during erase suspend, bits 15:14 */
         uint16  PGM_SUBMODE              :2; /*!< Submode saved during program suspend, bits 17:16 */
         uint16  RDV_SUBMODE              :2; /*!< Submode saved during read_verify suspend, bits 19:18 */
         uint16 _FSM_MODE_Reserved_31_20 :12;/*!< Reserved, bits 31:20 */
      } FSM_MODE_BITS;
   } FsmMode;

   /*!
       Defines whole and bit level accesses to the FSM Program bits Register - 0x260
   */
   union FSM_PGM
   {
      uint32 u32Register; /* FSM Program bits Register, bits 31:0 */
      struct
      {
         uint16  PGM_ADDR_15_0           :16;/*!< Saved Address During Program Suspend, bits 22:0 */
         uint16  PGM_ADDR_22_16          :7;/*!< Saved Address During Program Suspend, bits 22:0 */
         uint16  PGM_BANK                :3; /*!< Saved Bank during program suspend, bits 25:23 */
         uint16  _FSM_PGM_Reserved_27_26 :2; /*!< Reserved, bits 27:26 */
         uint16  SAV_SEC                 :4; /*!< Save sectors, bits 31:28 */
      } FSM_PGM_BITS;
   } FsmPgm;

   /*!
       Defines whole and bit level accesses to the FSM Erase bits Register - 0x264
   */
   union FSM_ERA
   {
      uint32 u32Register; /* FSM Erase bits Register, bits 31:0 */
      struct
      {
         uint16 ERA_ADDR_15_0            :16;/*!< Saved Address During Erase Suspend, bits 22:0 */
         uint16 ERA_ADDR_22_16           :7;/*!< Saved Address During Erase Suspend, bits 22:0 */
         uint16  ERA_BANK                :3; /*!< Saved Bank during Erase Suspend, bits 25:23 */
         uint16  _FSM_ERA_Reserved_31_26 :6; /*!< Reserved, bits 31:26 */
      } FSM_ERA_BITS;
   } FsmEra;

   /*!
       Defines whole and bit level accesses to the FSM Maximum Programming Pulses Register - 0x268
   */
   union FSM_PRG_PUL
   {
      uint32 u32Register; /* FSM Maximum Programming Pulses, bits 31:0 */
      struct
      {
         uint16 MAX_PRG_PUL                  :12;/*!< Maximum Programming Pulses, bits 11:0 */
         uint16  _FSM_PRG_PUL_Reserved_15_12 :4; /*!< Reserved, bits 15:12 */
         uint16 BEG_EC_LEVEL                 :9; /*!< Begining level for VHVCT, bits 24:16 */
         uint16  _FSM_PRG_PUL_Reserved_31_25 :7; /*!< Reserved, bits 31:25 */
      } FSM_PRG_PUL_BITS;
   } FsmPrgPul;

   /*!
       Defines whole and bit level accesses to the FSM Maximum Erase Pulses Register - 0x26C
   */
   union FSM_ERA_PUL
   {
      uint32 u32Register; /* FSM Maximum Erase Pulses, bits 31:0 */
      struct
      {
         uint16 MAX_ERA_PUL                  :12;/*!< Maximum Erase Pulses, bits 11:0 */
         uint16  _FSM_ERA_PUL_Reserved_15_12 :4; /*!< Reserved, bits 15:12 */
         uint16 MAX_EC_LEVEL                 :9; /*!< Maximum VNVCT/VHVCT Level, bits 24:16 */
         uint16  _FSM_ERA_PUL_Reserved_31_25 :7; /*!< Reserved, bits 31:25 */
      } FSM_ERA_PUL_BITS;
   } FsmEraPul;

   /*!
       Defines whole and bit level accesses to the FSM Step Size Register - 0x270
   */
   union FSM_STEP_SIZE
   {
      uint32 u32Register; /* FSM Step Size, bits 31:0 */
      struct
      {
         uint16 _FSM_STEP_SIZE_Reserved_15_00 :16;/*!< Reserved, bits 15:0 */
         uint16 EC_STEP_SIZE                  :9; /*!< VNVCT/VHVCT Step Size, bits 24:16 */
         uint16  _FSM_STEP_SIZE_Reserved_31_25 :7; /*!< Reserved, bits 31:25 */
      } FSM_STEP_SIZE_BITS;
   } FsmStepSize;

   /*!
       Defines whole and bit level accesses to the FSM Pulse Counter Register - 0x274
   */
   union FSM_PUL_CNTR
   {
      uint32 u32Register; /* FSM Maximum Pulse Counter, bits 31:0 */
      struct
      {
         uint16 PUL_CNTR                     :12;/*!< Pulse Counter, bits 11:0 */
         uint16  _FSM_PUL_CNTR_Reserved_15_12 :4; /*!< Reserved, bits 15:12 */
         uint16 CUR_EC_LEVEL                 :9; /*!< Current VNVCT Level, bits 24:16 */
         uint16  _FSM_PUL_CNTR_Reserved_31_25 :7; /*!< Reserved, bits 31:25 */
      } FSM_PUL_CNTR_BITS;
   } FsmPulCntr;

   /*!
       Defines whole and bit level accesses to the FSM Step Height Register - 0x278
   */
   union FSM_EC_STEP_HEIGHT
   {
      uint32 u32Register; /* FSM Step Height Size, bits 31:0 */
      struct
      {
         uint16 EC_STEP_HEIGHT                     :7;  /*!< EC_STEP_HEIGHT, bits 6:0 */
         uint16  _FSM_EC_STEP_HEIGHT_Reserved_15_7 :9; /*!< Reserved, bits 31:25 */
         uint16  _FSM_EC_STEP_HEIGHT_Reserved_31_16:16; /*!< Reserved, bits 31:25 */
      } FSM_EC_STEP_HEIGHT_BITS;
   } FsmEcStepHeightSize;


   /*!
       Defines whole and bit level accesses to the FSM State Machine Register - 0x27C
   */
   union FSM_ST_MACHINE
   {
      uint32 u32Register; /* Module Status Register, bits 31:0 */
      struct
      {
         uint16 OVERRIDE                       :1;/*!< Override, bit 0 */
         uint16 INV_DATA                       :1;/*!< Invert Data for checkerboard and other patterns, bit 1 */
         uint16 CMD_EN                         :1;/*!< Command Enable, bit 2 */
         uint16 DIS_TST_EN                     :1;/*!< Disturbance Test Enable, bit 3 */
         uint16 PREC_STOP_EN                   :1;/*!< Pre-condition Stop Enable, bit 4 */
         uint16 PGM_SEC_COF_EN                 :1;/*!< Program Sector Continue on Failure Enable, bit 5 */
         uint16 BNK_ERA_MODE                   :1;/*!< Bank Erase Mode, bit 6 */
         uint16 DBG_SHORT_ROW                  :4;/*!< Debugging Short rows, bits 10:7 */
         uint16 DO_REDU_COL                    :1;/*!< Do Redundant Columns, bit 11 */
         uint16 _FSM_ST_MACHINE_Reserved_12    :1;/*!< Reserved, bit 12 */
         uint16 RESTRT_ADDR                    :1;/*!< Restart Address, bit 13 */
         uint16 ONE_TIME_GOOD                  :1;/*!< One Time Good function, bit 14 */
         uint16 _FSM_ST_MACHINE_Reserved_15    :1;/*!< Reserved, bit 15 */
         uint16 RV_INT_EN                      :1;/*!< Read Verify Interrupt Enable, bit 16 */
         uint16 RV_RES                         :1;/*!< Read Verify Resume, bit 17 */
         uint16 RV_SEC_EN                      :1;/*!< Read Verify Sector Enable, bit 18 */
         uint16 RANDOM                         :1;/*!< Enable Psuedo-Random Pattern Generation, bit 19 */
         uint16 CMPV_ALLOWED                   :1;/*!< Compaction Verify allowed, bit 20 */
         uint16 ALL_BANKS                      :1;/*!< All bank operations, bit 21 */
         uint16 FSM_INT_EN                     :1;/*!< FSM interrupt enable, bit 22 */
         uint16 DO_PRECOND                     :1;/*!< Do Preconditioning, bit 23 */
         uint16 _FSM_ST_MACHINE_Reserved_31_24 :8;/*!< Reserved, bits 31:24 */
      } FSM_ST_MACHINE_BITS;
   } FsmStMachine;

   uint32 _Reserved_280_284[2];/* Reserved Address Locations 0x280 - 0x284 */

   /*!
       Defines whole and bit level accesses to the FSM Register Write Enable- 0x288
   */
   /*revisit*/
   union FSM_WR_ENA
   {
      uint32 u32Register; /* FSM Register Write Enable, bits 31:0 */
      struct
      {
         uint16  WR_ENA                     :3; /*!< FSM Write Enable, bits 2:0 */
         uint16 _FSM_WR_ENA_Reserved_15_03  :13;/*!< Reserved, bits 31:3 */
         uint16 _FSM_WR_ENA_Reserved_31_16  :16;/*!< Reserved, bits 31:3 */
      } FSM_WR_ENA_BITS;
   } FsmWrEna;

   /*!
       Defines whole and bit level accesses to the FSM Accumulate Program Pulses Register - 0x28C
   */
   union FSM_ACC_PP
   {
      uint32 u32Register; /* FSM Accumulate Program Pulses, bits 31:0 */
   } FsmAccPp;

   /*!
       Defines whole and bit level accesses to the FSM Accumulate Erase Pulses Register - 0x290
   */
   union FSM_ACC_EP
   {
      uint32 u32Register; /* FSM Accumulate Erase Pulses, bits 31:0 */
      struct
      {
         uint16  ACC_EP                    :16; /*!< Accumulate Erase Pulses, bits 15:0 */
         uint16 _FSM_ACC_EP_Reserved_31_16 :16;/*!< Reserved, bits 31:16 */
      } FSM_ACC_EP_BITS;
   } FsmAccEp;

   uint32 _Reserved_294_29C[3];/* Reserved Address Locations 0x294 - 0x29C */

   /*!
       Defines whole and bit level accesses to the FSM Address Register - 0x2A0
   */
   union FSM_ADDR
   {
      uint32 u32Register; /* FSM Address, bits 31:0 */
      #if(0)
      struct
      {
         uint16  _FSM_ADDR_Reserved_31 :1; /*!< Reserved, bit 31 */
         uint16  BANK                  :3; /*!< Current Bank, bits 30:28 */
         uint16 CUR_ADDR              :28; /*!< Current Address, bits 27:0 */
      } FSM_ADDR;
      #endif
   } FsmAddr;

   /*!
       Defines whole and bit level accesses to the FSM Sector Register - 0x2A4
   */
   /*revisit*/
   union FSM_SECTOR
   {
      uint32 u32Register; /* FSM Sector, bits 31:0 */
      struct
      {
         uint16  SEC_OUT                    :4; /*!< Sector Output, bits 3:0 */
         uint16  SECTOR                     :4; /*!< Sector, bits 7:4 */
         uint16  _FSM_SECTOR_Reserved_15_08 :8; /*!< Reserved, bits 15:8 */
         uint16 SECT_ERASED                :16;/*!< Sectors Erased, bits 31:16 */
      } FSM_SECTOR_BITS;
   } FsmSector;

   /*!
       Defines whole and bit level accesses to the FSM Revision Identification Register - 0x2A8
   */
   union FMC_REV_ID
   {
      uint32 u32Register; /* FSM Revision Identification, bits 31:0 */
      struct
      {
         uint16 CONFIG_CRC        :12;/*!< Configuration Magic Number code, bits 11:0 */
         uint16 MOD_VERSION_15_12 :4;/*!< Module Version, bits 31:12 */
         uint16 MOD_VERSION_31_16 :16;/*!< Module Version, bits 31:12 */
      } FMC_REV_ID_BITS;
   } FmcRevId;

   /*!
       Defines whole and bit level accesses to the FSM Error Address Register - 0x2AC
   */
   union FSM_ERR_ADDR
   {
      uint32 u32Register; /* FSM Error Address, bits 31:0 */
      #if(0)
      struct
      {
         uint16  FSM_ERR_BANK                 :4; /*!< FSM Error Bank, bits 31:28 */
         uint16  _FSM_ERR_ADDR_Reserved_27_24 :4; /*!< Reserved, bits 27:24 */
         uint16 FSM_ERR_ADDR                 :24;/*!< FSM Error Address, bits 23:0 */
      } FSM_ERR_ADDR_BITS;
      #endif
   } FsmErrAddr;

   /*!
       Defines whole and bit level accesses to the FSM Maximum Program Pulse Register - 0x2B0
   */
   union FSM_PGM_MAXPUL
   {
      uint32 u32Register; /* FSM Maximum Program Pulse, bits 31:0 */
      #if(0)
      struct
      {
         uint16 _FSM_PGM_MAXPUL_Reserved_31_12 :20; /*!< Reserved, bits 31:12 */
         uint16 FSM_PGM_MAXPUL                 :12; /*!< FSM Program Maximum pulses used, bits 11:0 */
      } FSM_PGM_MAXPUL_BITS;
      #endif
   } FsmAPgmMaxPul;

   /*!
       Defines whole and bit level accesses to the FSM Command Execute Register - 0x2B4
   */
   union FSM_EXECUTE
   {
      uint32 u32Register; /* FSM Command Execute, bits 31:0 */
      struct
      {
         uint16  FSMEXECUTE                  :5; /*!< FSM Command Execute, bits 4:0 */
         uint16 _FSM_EXECUTE_Reserved_15_05 :11;/*!< Reserved, bits 15:5 */
         uint16  SUSPEND_NOW                 :4; /*!< FSM Command Suspend, bits 19:16 */
         uint16 _FSM_EXECUTE_Reserved_31_20 :12;/*!< Reserved, bits 31:20 */
      } FSM_EXECUTE_BITS;
   } FsmExecute;

   /*!
       Defines whole and bit level accesses to the EEPROM Emulation configuration Register - 0x2B8
   */
   union EEPROM_CONFIG
   {
      uint32 u32Register; /* EEPROM Emulation configuration, bits 31:0 */
      struct
      {
         uint16  AUTOSTART_GRACE               :8; /*!< Auto-suspend Startup Grace Period, bits 7:0 */
         uint16  AUTOSUSP_EN                   :1; /*!< Auto-suspend Enable, bit 8 */
         uint16  _EEPROM_CONFIG_Reserved_15_09 :7;/*!< Reserved, bits 15:9 */
         uint16  EWAIT                         :4; /*!< EEPROM Wait state Counter, bits 19:16 */
         uint16 _EEPROM_CONFIG_Reserved_31_20 :12; /*!< Reserved, bits 31:20 */
      } EEPROM_CONFIG_BITS;
   } EepromConfig;

   uint32 _Reserved_2BC;  /* Reserved Address Locations 0x2BC */

   /*!
       Defines whole and bit level accesses to the FSM Sector1 Register - 0x2C0
   */
   union FSM_SECTOR1
   {
      uint32 u32Register; /* FSM Sector1, bits 31:0 */
   } FsmSector1;

   /*!
       Defines whole and bit level accesses to the FSM Sector2 Register - 0x2C4
   */
   union FSM_SECTOR2
   {
      uint32 u32Register; /* FSM Sector1, bits 31:0 */
   } FsmSector2;

   uint32 _Reserved_2C8_3FC[78];/* Reserved Address Locations 0x2C8 - 0x400 */

   /*!
       Defines whole and bit level accesses to the FCFG BANK Register - 0x400
   */
   union FCFG_BANK
   {
      uint32 u32Register; /* Flash Bank configuration, bits 31:0 */
      struct
      {
         uint16  MAIN_NUM_BANK                  :4; /*!< MAIN_NUM_BANK, bits 3:0 */
         uint16  MAIN_BANK_WIDTH                :12;/*!< MAIN_BANK_WIDTH, bits 15:4 */
         uint16  EE_NUM_BANK                    :4; /*!< EE_NUM_BANK, bits 19:16 */
         uint16  EE_BANK_WIDTH                  :12;/*!< EE_BANK_WIDTH, bits 31:20 */
      } FCFG_BANK_BITS;
   } FcfgBank;

   /*!
       Defines whole and bit level accesses to the FCFG Wrapper Register - 0x404
   */
   union FCFG_WRAPPER
   {
      uint32 u32Register; /* Flash Wrapper configuration, bits 31:0 */
      struct
      {
         uint16  CPU_TYPE1                      :4; /*!< CPU Type, bits 3:0 */
         uint16  UERR                           :2; /*!< Uncorrectable Error Type, bits 5:4 */
         uint16  AUTO_SUSP                      :2; /*!< Auto-suspend logic, bits 7:6 */
         uint16  ECCA                           :1; /*!< ECC has an Address component, bit 8 */
         uint16  SIL3                           :1; /*!< SIL3 Configuration, bit 9 */
         uint16  IFLUSH                         :1; /*!< Instruction Flush Supported, bit 10 */
         uint16  ROM                            :1; /*!< Replace Flash banks with ROM, bit 11 */
         uint16  EE_IN_MAIN                     :4; /*!< EEPROM emulation in Main data space, bits 15:12 */
         uint16  CPU2t                          :4; /*!< CPU Type 2, bits 20:16 */ /*vamsi modified as CPU2t instead of CPU2*/
         uint16  MEM_MAP                        :1; /*!< Memory Map Type, bit 20 */
         uint16  AUTOCALC                       :1; /*!< AUTOCALC feature, bit 21 */
         uint16  _FCFG_WRAPPER_Reserved_23_22   :2; /*!< Reserved, bits 23:22 */
         uint16  FAMILY_TYPE                    :8; /*!< FAMILY_TYPE, bits 31:24 */
      } FCFG_WRAPPER_BITS;
   } FcfgWrapper;

   /*!
       Defines whole and bit level accesses to the FCFG BNK TYPE Register - 0x408
   */
   union FCFG_BNK_TYPE
   {
      uint32 u32Register; /* Flash Bank Type configuration, bits 31:0 */
      struct
      {
         uint16  B0_TYPE                        :4;/*!< B0_TYPE, bits  3:0  */
         uint16  B1_TYPE                        :4;/*!< B1_TYPE, bits  7:4  */
         uint16  B2_TYPE                        :4;/*!< B2_TYPE, bits 11:8  */
         uint16  B3_TYPE                        :4;/*!< B3_TYPE, bits 15:12 */
         uint16  B4_TYPE                        :4;/*!< B4_TYPE, bits 19:16 */
         uint16  B5_TYPE                        :4;/*!< B5_TYPE, bits 23:20 */
         uint16  B6_TYPE                        :4;/*!< B6_TYPE, bits 27:24 */
         uint16  B7_TYPE                        :4;/*!< B7_TYPE, bits 31:28 */
      } FCFG_BNK_TYPE_BITS;
   } FcfgBnkType;

   uint32 _Reserved_40C; /* Reserved Address Locations 0x40C */

   /*!
       Defines whole and bit level accesses to the FCFG B0 START Register - 0x410
   */
   union FCFG_B0_START
   {
      uint32 u32Register; /* Flash Bank 0 Start configuration, bits 31:0 */
      struct
      {
         uint16  B0_START_ADDR_0_15             :16;/*!< Starting Address of Bank 0, bits 15:0 */
         uint16  B0_START_ADDR_16_23            :8;/*!< Starting Address of Bank 0, bits 23:16 */
         uint16  B0_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 0 divided by 8, bits 27:24 */
         uint16  B0_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 0, bits 31:28 */
      } FCFG_B0_START_BITS;
   } FcfgB0Start;

   /*!
       Defines whole and bit level accesses to the FCFG B1 START Register - 0x414
   */
   union FCFG_B1_START
   {
      uint32 u32Register; /* Flash Bank 1 Start configuration, bits 31:0 */
      struct
      {
         uint16  B1_START_ADDR_0_15             :16;/*!< Starting Address of Bank 1, bits 15:0 */
         uint16  B1_START_ADDR_16_23            :8;/*!< Starting Address of Bank 1, bits 23:16 */
         uint16  B1_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 1 divided by 8, bits 27:24 */
         uint16  B1_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 1, bits 31:28 */
      } FCFG_B1_START_BITS;
   } FcfgB1Start;

   /*!
       Defines whole and bit level accesses to the FCFG B2 START Register - 0x418
   */
   union FCFG_B2_START
   {
      uint32 u32Register; /* Flash Bank 2 Start configuration, bits 31:0 */
      struct
      {
         uint16  B2_START_ADDR_0_15             :16;/*!< Starting Address of Bank 2, bits 15:0 */
         uint16  B2_START_ADDR_16_23            :8;/*!< Starting Address of Bank 2, bits 23:16 */
         uint16  B2_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 2 divided by 8, bits 27:24 */
         uint16  B2_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 2, bits 31:28 */
      } FCFG_B2_START_BITS;
   } FcfgB2Start;

   /*!
       Defines whole and bit level accesses to the FCFG 3 START Register - 0x41C
   */
   union FCFG_B3_START
   {
      uint32 u32Register; /* Flash Bank 3 Start configuration, bits 31:0 */
      struct
      {
         uint16  B3_START_ADDR_0_15             :16;/*!< Starting Address of Bank 3, bits 15:0 */
         uint16  B3_START_ADDR_16_23            :8;/*!< Starting Address of Bank 3, bits 23:16 */
         uint16  B3_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 3 divided by 8, bits 27:24 */
         uint16  B3_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 3, bits 31:28 */
      } FCFG_B3_START_BITS;
   } FcfgB3Start;

   /*!
       Defines whole and bit level accesses to the FCFG B4 START Register - 0x420
   */
   union FCFG_B4_START
   {
      uint32 u32Register; /* Flash Bank 4 Start configuration, bits 31:0 */
      struct
      {
         uint16  B4_START_ADDR_0_15             :16;/*!< Starting Address of Bank 4, bits 15:0 */
         uint16  B4_START_ADDR_16_23            :8;/*!< Starting Address of Bank 4, bits 23:16 */
         uint16  B4_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 4 divided by 8, bits 27:24 */
         uint16  B4_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 4, bits 31:28 */
      } FCFG_B4_START_BITS;
   } FcfgB4Start;

   /*!
       Defines whole and bit level accesses to the FCFG B5 START Register - 0x424
   */
   union FCFG_B5_START
   {
      uint32 u32Register; /* Flash Bank 5 Start configuration, bits 31:0 */
      struct
      {
         uint16  B5_START_ADDR_0_15             :16;/*!< Starting Address of Bank 5, bits 15:0 */
         uint16  B5_START_ADDR_16_23            :8;/*!< Starting Address of Bank 5, bits 23:16 */
         uint16  B5_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 5 divided by 8, bits 27:24 */
         uint16  B5_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 5, bits 31:28 */
      } FCFG_B5_START_BITS;
   } FcfgB5Start;

   /*!
       Defines whole and bit level accesses to the FCFG B6 START Register - 0x428
   */
   union FCFG_B6_START
   {
      uint32 u32Register; /* Flash Bank 6 Start configuration, bits 31:0 */
      struct
      {
         uint16  B6_START_ADDR_0_15             :16;/*!< Starting Address of Bank 6, bits 15:0 */
         uint16  B6_START_ADDR_16_23            :8;/*!< Starting Address of Bank 6, bits 23:16 */
         uint16  B6_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 6 divided by 8, bits 27:24 */
         uint16  B6_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 6, bits 31:28 */
      } FCFG_B6_START_BITS;
   } FcfgB6Start;

   /*!
       Defines whole and bit level accesses to the FCFG B7 START Register - 0x42C
   */
   union FCFG_B7_START
   {
      uint32 u32Register; /* Flash Bank 7 Start configuration, bits 31:0 */
      struct
      {
         uint16  B7_START_ADDR_0_15             :16;/*!< Starting Address of Bank 7, bits 15:0 */
         uint16  B7_START_ADDR_16_23            :8;/*!< Starting Address of Bank 7, bits 23:16 */
         uint16  B7_MUX_FACTOR                  :4;/*!< Mux Factor of Bank 7 divided by 8, bits 27:24 */
         uint16  B7_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank 7, bits 31:28 */
      } FCFG_B7_START_BITS;
   } FcfgB7Start;

   /*!
       Defines whole and bit level accesses to the FCFG B0 SSIZE0 Register - 0x430
   */
   union FCFG_B0_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 0 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B0_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 0, bits 7:0 */
         uint16  B0_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 0, bits 15:8 */
         uint16  B0_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 0, bits 23:16 */
         uint16  B0_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 0, bits 31:24 */
      } FCFG_B0_SSIZE0_STD_BITS;
      struct
      {
         uint16  B0_SECT_SIZE                   :4;/*!< Size of sectors in Bank 0, bits 3:0 */
         uint16  _FCFG_B0_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B0_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 0, bits 27:16 */
         uint16  _FCFG_B0_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B0_SSIZE0_FLEE_BITS;
   } FcfgB0Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B0 SSIZE1 Register - 0x434
   */
   union FCFG_B0_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 0 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B0_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 0, bits 7:0 */
         uint16  B0_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 0, bits 15:8 */
         uint16  B0_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 0, bits 23:16 */
         uint16  B0_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 0, bits 31:24 */
      } FCFG_B0_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B0_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B0_SSIZE1_FLEE_BITS;
   } FcfgB0Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B0 SSIZE2 Register - 0x438
   */
   union FCFG_B0_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 0 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B0_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 0, bits 7:0 */
         uint16  B0_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 0, bits 15:8 */
         uint16  B0_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 0, bits 23:16 */
         uint16  B0_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 0, bits 31:24 */
      } FCFG_B0_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B0_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B0_SSIZE2_FLEE_BITS;
   } FcfgB0Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B0 SSIZE3 Register - 0x43C
   */
   union FCFG_B0_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 0 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B0_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 0, bits 7:0 */
         uint16  B0_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 0, bits 15:8 */
         uint16  B0_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 0, bits 23:16 */
         uint16  B0_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 0, bits 31:24 */
      } FCFG_B0_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B0_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B0_SSIZE3_FLEE_BITS;
   } FcfgB0Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B1 SSIZE0 Register - 0x440
   */
   union FCFG_B1_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 1 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B1_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 1, bits 7:0 */
         uint16  B1_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 1, bits 15:8 */
         uint16  B1_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 1, bits 23:16 */
         uint16  B1_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 1, bits 31:24 */
      } FCFG_B1_SSIZE0_STD_BITS;
      struct
      {
         uint16  B1_SECT_SIZE                   :4;/*!< Size of sectors in Bank 1, bits 3:0 */
         uint16  _FCFG_B1_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B1_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 1, bits 27:16 */
         uint16  _FCFG_B1_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B1_SSIZE0_FLEE_BITS;
   } FcfgB1Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B1 SSIZE1 Register - 0x444
   */
   union FCFG_B1_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 1 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B1_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 1, bits 7:0 */
         uint16  B1_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 1, bits 15:8 */
         uint16  B1_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 1, bits 23:16 */
         uint16  B1_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 1, bits 31:24 */
      } FCFG_B1_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B1_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B1_SSIZE1_FLEE_BITS;
   } FcfgB1Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B1 SSIZE2 Register - 0x448
   */
   union FCFG_B1_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 1 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B1_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 1, bits 7:0 */
         uint16  B1_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 1, bits 15:8 */
         uint16  B1_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 1, bits 23:16 */
         uint16  B1_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 1, bits 31:24 */
      } FCFG_B1_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B1_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B1_SSIZE2_FLEE_BITS;
   } FcfgB1Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B1 SSIZE3 Register - 0x44C
   */
   union FCFG_B1_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 1 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B1_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 1, bits 7:0 */
         uint16  B1_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 1, bits 15:8 */
         uint16  B1_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 1, bits 23:16 */
         uint16  B1_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 1, bits 31:24 */
      } FCFG_B1_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B1_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B1_SSIZE3_FLEE_BITS;
   } FcfgB1Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B2 SSIZE0 Register - 0x450
   */
   union FCFG_B2_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 2 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B2_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 2, bits 7:0 */
         uint16  B2_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 2, bits 15:8 */
         uint16  B2_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 2, bits 23:16 */
         uint16  B2_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 2, bits 31:24 */
      } FCFG_B2_SSIZE0_STD_BITS;
      struct
      {
         uint16  B2_SECT_SIZE                   :4;/*!< Size of sectors in Bank 2, bits 3:0 */
         uint16  _FCFG_B2_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B2_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 2, bits 27:16 */
         uint16  _FCFG_B2_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B2_SSIZE0_FLEE_BITS;
   } FcfgB2Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B2 SSIZE1 Register - 0x454
   */
   union FCFG_B2_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 2 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B2_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 2, bits 7:0 */
         uint16  B2_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 2, bits 15:8 */
         uint16  B2_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 2, bits 23:16 */
         uint16  B2_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 2, bits 31:24 */
      } FCFG_B2_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B2_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B2_SSIZE1_FLEE_BITS;
   } FcfgB2Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B2 SSIZE2 Register - 0x458
   */
   union FCFG_B2_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 2 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B2_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 2, bits 7:0 */
         uint16  B2_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 2, bits 15:8 */
         uint16  B2_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 2, bits 23:16 */
         uint16  B2_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 2, bits 31:24 */
      } FCFG_B2_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B2_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B2_SSIZE2_FLEE_BITS;
   } FcfgB2Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B2 SSIZE3 Register - 0x45C
   */
   union FCFG_B2_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 2 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B2_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 2, bits 7:0 */
         uint16  B2_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 2, bits 15:8 */
         uint16  B2_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 2, bits 23:16 */
         uint16  B2_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 2, bits 31:24 */
      } FCFG_B2_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B2_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B2_SSIZE3_FLEE_BITS;
   } FcfgB2Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B3 SSIZE0 Register - 0x460
   */
   union FCFG_B3_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 3 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B3_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 3, bits 31:24 */
         uint16  B3_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 3, bits 15:8 */
         uint16  B3_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 3, bits 23:16 */
         uint16  B3_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 3, bits 7:0 */
      } FCFG_B3_SSIZE0_STD_BITS;
      struct
      {
         uint16  B3_SECT_SIZE                   :4;/*!< Size of sectors in Bank 3, bits 3:0 */
         uint16  _FCFG_B3_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B3_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 3, bits 27:16 */
         uint16  _FCFG_B3_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B3_SSIZE0_FLEE_BITS;
   } FcfgB3Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B3 SSIZE1 Register - 0x464
   */
   union FCFG_B3_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 3 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B3_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 3, bits 7:0 */
         uint16  B3_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 3, bits 15:8 */
         uint16  B3_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 3, bits 23:16 */
         uint16  B3_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 3, bits 31:24 */
      } FCFG_B3_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B3_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B3_SSIZE1_FLEE_BITS;
   } FcfgB3Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B3 SSIZE2 Register - 0x468
   */
   union FCFG_B3_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 3 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B3_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 3, bits 7:0 */
         uint16  B3_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 3, bits 15:8 */
         uint16  B3_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 3, bits 23:16 */
         uint16  B3_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 3, bits 31:24 */
      } FCFG_B3_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B3_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B3_SSIZE2_FLEE_BITS;
   } FcfgB3Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B3 SSIZE3 Register - 0x46C
   */
   union FCFG_B3_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 3 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B3_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 3, bits 7:0 */
         uint16  B3_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 3, bits 15:8 */
         uint16  B3_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 3, bits 23:16 */
         uint16  B3_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 3, bits 31:24 */
      } FCFG_B3_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B3_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B3_SSIZE3_FLEE_BITS;
   } FcfgB3Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B4 SSIZE0 Register - 0x470
   */
   union FCFG_B4_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 4 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B4_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 4, bits 7:0 */
         uint16  B4_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 4, bits 15:8 */
         uint16  B4_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 4, bits 23:16 */
         uint16  B4_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 4, bits 31:24 */
      } FCFG_B4_SSIZE0_STD_BITS;
      struct
      {
         uint16  B4_SECT_SIZE                   :4;/*!< Size of sectors in Bank 4, bits 3:0 */
         uint16  _FCFG_B4_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B4_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 4, bits 27:16 */
         uint16  _FCFG_B4_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B4_SSIZE0_FLEE_BITS;
   } FcfgB4Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B4 SSIZE1 Register - 0x474
   */
   union FCFG_B4_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 4 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B4_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 4, bits 7:0 */
         uint16  B4_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 4, bits 15:8 */
         uint16  B4_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 4, bits 23:16 */
         uint16  B4_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 4, bits 31:24 */
      } FCFG_B4_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B4_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B4_SSIZE1_FLEE_BITS;
   } FcfgB4Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B4 SSIZE2 Register - 0x478
   */
   union FCFG_B4_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 4 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B4_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 4, bits 7:0 */
         uint16  B4_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 4, bits 15:8 */
         uint16  B4_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 4, bits 23:16 */
         uint16  B4_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 4, bits 31:24 */
      } FCFG_B4_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B4_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B4_SSIZE2_FLEE_BITS;
   } FcfgB4Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B4 SSIZE3 Register - 0x47C
   */
   union FCFG_B4_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 4 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B4_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 4, bits 7:0 */
         uint16  B4_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 4, bits 15:8 */
         uint16  B4_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 4, bits 23:16 */
         uint16  B4_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 4, bits 31:24 */
      } FCFG_B4_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B4_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B4_SSIZE3_FLEE_BITS;
   } FcfgB4Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B5 SSIZE0 Register - 0x480
   */
   union FCFG_B5_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 5 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B5_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 5, bits 7:0 */
         uint16  B5_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 5, bits 15:8 */
         uint16  B5_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 5, bits 23:16 */
         uint16  B5_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 5, bits 31:24 */
      } FCFG_B5_SSIZE0_STD_BITS;
      struct
      {
         uint16  B5_SECT_SIZE                   :4;/*!< Size of sectors in Bank 5, bits 3:0 */
         uint16  _FCFG_B5_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B5_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 5, bits 27:16 */
         uint16  _FCFG_B5_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B5_SSIZE0_FLEE_BITS;
   } FcfgB5Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B5 SSIZE1 Register - 0x484
   */
   union FCFG_B5_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 5 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B5_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 5, bits 7:0 */
         uint16  B5_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 5, bits 15:8 */
         uint16  B5_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 5, bits 23:16 */
         uint16  B5_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 5, bits 31:24 */
      } FCFG_B5_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B5_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B5_SSIZE1_FLEE_BITS;
   } FcfgB5Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B5 SSIZE2 Register - 0x488
   */
   union FCFG_B5_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 5 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B5_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 5, bits 7:0 */
         uint16  B5_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 5, bits 15:8 */
         uint16  B5_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 5, bits 23:16 */
         uint16  B5_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 5, bits 31:24 */
      } FCFG_B5_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B5_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B5_SSIZE2_FLEE_BITS;
   } FcfgB5Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B5 SSIZE3 Register - 0x48C
   */
   union FCFG_B5_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 5 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B5_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 5, bits 7:0 */
         uint16  B5_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 5, bits 15:8 */
         uint16  B5_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 5, bits 23:16 */
         uint16  B5_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 5, bits 31:24 */
      } FCFG_B5_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B5_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B5_SSIZE3_FLEE_BITS;
   } FcfgB5Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B6 SSIZE0 Register - 0x490
   */
   union FCFG_B6_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 6 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B6_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 6, bits 7:0 */
         uint16  B6_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 6, bits 15:8 */
         uint16  B6_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 6, bits 23:16 */
         uint16  B6_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 6, bits 31:24 */
      } FCFG_B6_SSIZE0_STD_BITS;
      struct
      {
         uint16  B6_SECT_SIZE                   :4;/*!< Size of sectors in Bank 6, bits 3:0 */
         uint16  _FCFG_B6_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B6_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 6, bits 27:16 */
         uint16  _FCFG_B6_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B6_SSIZE0_FLEE_BITS;
   } FcfgB6Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B6 SSIZE1 Register - 0x494
   */
   union FCFG_B6_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 6 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B6_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 6, bits 7:0 */
         uint16  B6_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 6, bits 15:8 */
         uint16  B6_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 6, bits 23:16 */
         uint16  B6_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 6, bits 31:24 */
      } FCFG_B6_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B6_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B6_SSIZE1_FLEE_BITS;
   } FcfgB6Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B6 SSIZE2 Register - 0x498
   */
   union FCFG_B6_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 6 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B6_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 6, bits 7:0 */
         uint16  B6_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 6, bits 15:8 */
         uint16  B6_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 6, bits 23:16 */
         uint16  B6_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 6, bits 31:24 */
      } FCFG_B6_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B6_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B6_SSIZE2_FLEE_BITS;
   } FcfgB6Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B6 SSIZE3 Register - 0x49C
   */
   union FCFG_B6_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 6 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B6_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 6, bits 7:0 */
         uint16  B6_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 6, bits 15:8 */
         uint16  B6_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 6, bits 23:16 */
         uint16  B6_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 6, bits 31:24 */
      } FCFG_B6_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B6_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B6_SSIZE3_FLEE_BITS;
   } FcfgB6Ssize3;

   /*!
       Defines whole and bit level accesses to the FCFG B7 SSIZE0 Register - 0x4A0
   */
   union FCFG_B7_SSIZE0
   {
      uint32 u32Register; /* Flash Bank 7 Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  B7_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank 7, bits 7:0 */
         uint16  B7_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank 7, bits 15:8 */
         uint16  B7_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank 7, bits 23:16 */
         uint16  B7_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank 7, bits 31:24 */
      } FCFG_B7_SSIZE0_STD_BITS;
      struct
      {
         uint16  B7_SECT_SIZE                   :4;/*!< Size of sectors in Bank 7, bits 3:0 */
         uint16  _FCFG_B7_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  B7_NUM_SECTORS                 :12;/*!< Number of sectors in Bank 7, bits 27:16 */
         uint16  _FCFG_B7_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_B7_SSIZE0_FLEE_BITS;
   } FcfgB7Ssize0;

   /*!
       Defines whole and bit level accesses to the FCFG B7 SSIZE1 Register - 0x4A4
   */
   union FCFG_B7_SSIZE1
   {
      uint32 u32Register; /* Flash Bank 7 Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  B7_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank 7, bits 7:0 */
         uint16  B7_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank 7, bits 15:8 */
         uint16  B7_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank 7, bits 23:16 */
         uint16  B7_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank 7, bits 31:24 */
      } FCFG_B7_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_B7_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B7_SSIZE1_FLEE_BITS;
   } FcfgB7Ssize1;

   /*!
       Defines whole and bit level accesses to the FCFG B7 SSIZE2 Register - 0x4A8
   */
   union FCFG_B7_SSIZE2
   {
      uint32 u32Register; /* Flash Bank 7 Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  B7_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank 7, bits 7:0 */
         uint16  B7_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank 7, bits 15:8 */
         uint16  B7_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank 7, bits 23:16 */
         uint16  B7_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank 7, bits 31:24 */
      } FCFG_B7_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_B7_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B7_SSIZE2_FLEE_BITS;
   } FcfgB7Ssize2;

   /*!
       Defines whole and bit level accesses to the FCFG B7 SSIZE3 Register - 0x4AC
   */
   union FCFG_B7_SSIZE3
   {
      uint32 u32Register; /* Flash Bank 7 Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  B7_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank 7, bits 7:0 */
         uint16  B7_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank 7, bits 15:8 */
         uint16  B7_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank 7, bits 23:16 */
         uint16  B7_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank 7, bits 31:24 */
      } FCFG_B7_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_B7_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_B7_SSIZE3_FLEE_BITS;
   } FcfgB7Ssize3;

} Fapi_FmcRegistersType;

/*!
    Defines whole and bit level accesses to the FCFG Bx START Register - 0x410
*/
typedef union FCFG_Bx_START
{
   uint32 u32Register; /* Flash Bank x Start configuration, bits 31:0 */
   struct
   {
      uint16  Bx_START_ADDR_15_0             :16;/*!< Starting Address of Bank x, bits 23:0 */
      uint16  Bx_START_ADDR_23_16            :8;/*!< Starting Address of Bank x, bits 23:0 */
      uint16  Bx_MUX_FACTOR                  :4;/*!< Mux Factor of Bank x divided by 8, bits 27:24 */
      uint16  Bx_MAX_SECTOR                  :4;/*!< Number of highest sector in Bank x, bits 31:28 */
   } FCFG_Bx_START_BITS;
} FcfgBxStartType;

/*!
    Structure allowing easier programatic access to FMC Bank config registers.
*/
typedef volatile struct FMC_Bx_SSIZE
{
   /*!
       Defines whole and bit level accesses to the FCFG Bx SSIZE0 Register - 0x4A0
   */
   union FCFG_Bx_SSIZE0
   {
      uint32 u32Register; /* Flash Bank x Sector Size 0 configuration, bits 31:0 */
      struct
      {
         uint16  Bx_SECT_SIZE_0                 :8;/*!< Size of sector 0 of Bank x, bits 7:0 */
         uint16  Bx_SECT_SIZE_1                 :8;/*!< Size of sector 1 of Bank x, bits 15:8 */
         uint16  Bx_SECT_SIZE_2                 :8;/*!< Size of sector 2 of Bank x, bits 23:16 */
         uint16  Bx_SECT_SIZE_3                 :8;/*!< Size of sector 3 of Bank x, bits 31:24 */
      } FCFG_Bx_SSIZE0_STD_BITS;
      struct
      {
         uint16  Bx_SECT_SIZE                   :4;/*!< Size of sectors in Bank x, bits 3:0 */
         uint16  _FCFG_Bx_SSIZE0_Reserved_15_4  :12;/*!< Reserved, bits 15:4 */
         uint16  Bx_NUM_SECTORS                 :12;/*!< Number of sectors in Bank x, bits 27:16 */
         uint16  _FCFG_Bx_SSIZE0_Reserved_31_28 :4;/*!< Reserved, bits 31:28 */
      } FCFG_Bx_SSIZE0_FLEE_BITS;
   } FcfgBxSsize0;

   /*!
       Defines whole and bit level accesses to the FCFG Bx SSIZE1 Register - 0x4A4
   */
   union FCFG_Bx_SSIZE1
   {
      uint32 u32Register; /* Flash Bank x Sector Size 1 configuration, bits 31:0 */
      struct
      {
         uint16  Bx_SECT_SIZE_4                 :8;/*!< Size of sector 4 of Bank x, bits 7:0 */
         uint16  Bx_SECT_SIZE_5                 :8;/*!< Size of sector 5 of Bank x, bits 15:8 */
         uint16  Bx_SECT_SIZE_6                 :8;/*!< Size of sector 6 of Bank x, bits 23:16 */
         uint16  Bx_SECT_SIZE_7                 :8;/*!< Size of sector 7 of Bank x, bits 31:24 */
      } FCFG_Bx_SSIZE1_STD_BITS;
      struct
      {
         uint32  _FCFG_Bx_SSIZE1_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_Bx_SSIZE1_FLEE_BITS;
   } FcfgBxSsize1;

   /*!
       Defines whole and bit level accesses to the FCFG Bx SSIZE2 Register - 0x4A8
   */
   union FCFG_Bx_SSIZE2
   {
      uint32 u32Register; /* Flash Bank x Sector Size 2 configuration, bits 31:0 */
      struct
      {
         uint16  Bx_SECT_SIZE_8                 :8;/*!< Size of sector 8 of Bank x, bits 7:0 */
         uint16  Bx_SECT_SIZE_9                 :8;/*!< Size of sector 9 of Bank x, bits 15:8 */
         uint16  Bx_SECT_SIZE_10                :8;/*!< Size of sector 10 of Bank x, bits 23:16 */
         uint16  Bx_SECT_SIZE_11                :8;/*!< Size of sector 11 of Bank x, bits 31:24 */
      } FCFG_Bx_SSIZE2_STD_BITS;
      struct
      {
         uint32  _FCFG_Bx_SSIZE2_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_Bx_SSIZE2_FLEE_BITS;
   } FcfgBxSsize2;

   /*!
       Defines whole and bit level accesses to the FCFG Bx SSIZE3 Register - 0x4AC
   */
   union FCFG_Bx_SSIZE3
   {
      uint32 u32Register; /* Flash Bank x Sector Size 3 configuration, bits 31:0 */
      struct
      {
         uint16  Bx_SECT_SIZE_12                :8;/*!< Size of sector 12 of Bank x, bits 7:0 */
         uint16  Bx_SECT_SIZE_13                :8;/*!< Size of sector 13 of Bank x, bits 15:8 */
         uint16  Bx_SECT_SIZE_14                :8;/*!< Size of sector 14 of Bank x, bits 23:16 */
         uint16  Bx_SECT_SIZE_15                :8;/*!< Size of sector 15 of Bank x, bits 31:24 */
      } FCFG_Bx_SSIZE3_STD_BITS;
      struct
      {
         uint32  _FCFG_Bx_SSIZE3_Reserved_31_0; /*!< Reserved, bits 31:0 */
      } FCFG_Bx_SSIZE3_FLEE_BITS;
   } FcfgBxSsize3;
}FcfgBxSSizeType;

/*!
    Structure allowing easier programatic access to FMC Bank config registers.
*/
typedef volatile struct FMC_BANK_CONFIG
{
   FcfgBxStartType FcfgBxStart[8];
   FcfgBxSSizeType FcfgBxSSize[8];
} Fapi_FmcBankConfigType;

#define FMC_BANK_CONFIG_ADDRESS ((Fapi_FmcBankConfigType *)((uint32)Fapi_GlobalInit.m_poFlashControlRegisters + 0x208))

typedef volatile uint8  FwpWriteByteAccessorType;
typedef volatile uint16 FwpWriteWordAccessorType;
typedef volatile uint32 FwpWriteDWordAccessorType;

#define FWP_WRITE_OFFSET 0x90
#define FWPWRITE_BYTE_ACCESSOR_ADDRESS ((FwpWriteByteAccessorType *)((uint32)Fapi_GlobalInit.m_poFlashControlRegisters + 0x90))
#define FWPWRITE_ECC_BYTE_ACCESSOR_ADDRESS ((FwpWriteByteAccessorType *)((uint32)Fapi_GlobalInit.m_poFlashControlRegisters + 0xA0))
#define FWPWRITE_DWORD_ACCESSOR_ADDRESS ((FwpWriteDWordAccessorType *)((uint32)Fapi_GlobalInit.m_poFlashControlRegisters + 0x90))
#define FWPWRITE_WORD_ACCESSOR_ADDRESS ((FwpWriteWordAccessorType *)((uint32)Fapi_GlobalInit.m_poFlashControlRegisters + 0x90))
#define FWPWRITE_ECC_WORD_ACCESSOR_ADDRESS ((FwpWriteWordAccessorType *)((uint32)Fapi_GlobalInit.m_poFlashControlRegisters + 0xA0))

#endif /*F021_REGISTERS_C28X_H_*/
