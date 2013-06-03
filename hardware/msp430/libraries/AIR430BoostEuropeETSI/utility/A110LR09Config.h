#ifndef A110LR09_CONFIG_H
#define A110LR09_CONFIG_H
/**
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2012-13, Anaren Microwave, Inc.
 *
 *  For more information on licensing, please see Anaren Microwave, Inc's
 *  end user software licensing agreement: EULA.txt.
 *
 *  ----------------------------------------------------------------------------
 *
 *  A110LR09Config.h - configuration file for the A110LR09 module interface. The
 *	registers that are user-modifiable are listed below. These registers
 *	correspond to fields that are user-modifiable in the module User's Manual.
 *
 *	Note: The configuration registers below may be masked off to change only
 *	values (fields) that are allowed to be changed. Please refer to the module
 *	User's Manual for information on which register fields may be changed.
 *
 *  Note: This file must exist for the A110LR09 module interface to compile.
 *  However, the settings definitions may be defined in a preincluded file 
 *  instead of in this file. This is dependent on what the application is 
 *	trying to accomplish.
 */

// Configuration settings (FCC/IC)
//#define A110LR09_FCC_2FSK_1_2_KBAUD         // 2FSK, 1.2kBaud, 902MHz
//#define A110LR09_FCC_2FSK_38_KBAUD          // 2FSK, 38kBaud, 902MHz
//#define A110LR09_FCC_2FSK_100_KBAUD         // 2FSK, 100kBaud, 902MHz
//#define A110LR09_FCC_2FSK_250_KBAUD         // 2FSK, 250kBaud, 902MHz

// Configuration settings (ETSI)
//#define A110LR09_ETSI_M4_2FSK_1_2_KBAUD     // M4, 2FSK, 1.2kBaud, 868MHz
//#define A110LR09_ETSI_M5_2FSK_10_KBAUD      // M5, 2FSK, 10kBaud, 868MHz
//#define A110LR09_ETSI_M6_GFSK_10_KBAUD      // M6, GFSK, 10kBaud, 868MHz
#define A110LR09_ETSI_M7_GFSK_38_KBAUD      // M7, GFSK, 38kBaud, 868MHz
//#define A110LR09_ETSI_M11_2FSK_0_6_KBAUD    // M11, 2FSK, 0.6kBaud, 868MHz
//#define A110LR09_ETSI_M12_GFSK_4_8_KBAUD    // M12, GFSK, 4.8kBaud, 868MHz
//#define A110LR09_ETSI_M13_GFSK_19_2_KBAUD   // M13, GFSK, 19.2kBaud, 868MHz
//#define A110LR09_ETSI_M14_RX_4FSK_300_KBAUD // M14, RX, 4FSK, 300kBaud, 868MHz
//#define A110LR09_ETSI_M14_TX_4FSK_300_KBAUD // M14, TX, 4FSK, 300kBaud, 868MHz
//#define A110LR09_ETSI_ML1_GFSK_50_KBAUD     // ML1, GFSK, 50kBaud, 868MHz
//#define A110LR09_ETSI_ML2_GFSK_100_KBAUD    // ML2, GFSK, 100kBaud, 868MHz
//#define A110LR09_ETSI_ML3_4FSK_100_KBAUD    // ML3, 4FSK, 100kBaud, 868MHz

// Configuration user settings
#define A110LR09_USER_IOCFG2    0x2E  // GDO2 output pin configuration
#define A110LR09_USER_IOCFG1    0x2E  // GDO1 output pin configuration
#define A110LR09_USER_IOCFG0    0x06  // GDO0 output pin configuration
#define A110LR09_USER_FIFOTHR   0x87  // RX FIFO and TX FIFO thresholds
#define A110LR09_USER_PKTLEN    0x3D  // packet length
#define A110LR09_USER_PKTCTRL1  0x67  // packet automation control 1
#define A110LR09_USER_PKTCTRL0  0x45  // packet automation control 0
#define A110LR09_USER_ADDR      0x00  // device address
#define A110LR09_USER_CHANNR    0x00  // channel number
#define A110LR09_USER_FSCTRL0   0x00  // frequency synthesizer control 0
#define A110LR09_USER_MDMCFG2   0x73  // modem configuration 2
#define A110LR09_USER_MCSM2     0x07  // main radio control state machine configuration 2
#define A110LR09_USER_MCSM1     0x30  // main radio control state machine configuration 1
#define A110LR09_USER_MCSM0     0x18  // main radio control state machine configuration 0
#define A110LR09_USER_AGCCTRL1  0x00  // AGC control 1
#define A110LR09_USER_FSCAL3    0xEA  // frequency synthesizer calibration 3

// Power table user settings
//#define A110LR09_POWER_12_0_DBM       // 12.0dBm
//#define A110LR09_POWER_11_0_DBM       // 11.0dBm
//#define A110LR09_POWER_10_5_DBM       // 10.5dBm
//#define A110LR09_POWER_10_3_DBM       // 10.3dBm
//#define A110LR09_POWER_10_0_DBM       // 10.0dBm
//#define A110LR09_POWER_9_6_DBM        // 9.6dBm
//#define A110LR09_POWER_9_2_DBM        // 9.2dBm
//#define A110LR09_POWER_9_0_DBM        // 9.0dBm
//#define A110LR09_POWER_8_6_DBM        // 8.6dBm
//#define A110LR09_POWER_8_2_DBM        // 8.2dBm
//#define A110LR09_POWER_8_0_DBM        // 8.0dBm
//#define A110LR09_POWER_7_6_DBM        // 7.6dBm
//#define A110LR09_POWER_7_2_DBM        // 7.2dBm
//#define A110LR09_POWER_7_0_DBM        // 7.0dBm
//#define A110LR09_POWER_6_2_DBM        // 6.2dBm
//#define A110LR09_POWER_5_0_DBM        // 5.0dBm
//#define A110LR09_POWER_4_8_DBM        // 4.8dBm
//#define A110LR09_POWER_4_6_DBM        // 4.6dBm
//#define A110LR09_POWER_4_4_DBM        // 4.4dBm
//#define A110LR09_POWER_4_2_DBM        // 4.2dBm
#define A110LR09_POWER_4_0_DBM        // 4.0dBm
//#define A110LR09_POWER_3_6_DBM        // 3.6dBm
//#define A110LR09_POWER_3_4_DBM        // 3.4dBm
#define A110LR09_POWER_3_0_DBM        // 3.0dBm
//#define A110LR09_POWER_2_5_DBM        // 2.5dBm
#define A110LR09_POWER_2_0_DBM        // 2.0dBm
#define A110LR09_POWER_1_0_DBM        // 1.0dBm
#define A110LR09_POWER_0_0_DBM        // 0.0dBm
//#define A110LR09_POWER_NEG_0_5_DBM    // -0.5dBm
//#define A110LR09_POWER_NEG_1_0_DBM    // -1.0dBm
//#define A110LR09_POWER_NEG_2_0_DBM    // -2.0dBm
//#define A110LR09_POWER_NEG_2_2_DBM    // -2.2dBm
//#define A110LR09_POWER_NEG_5_0_DBM    // -5.0dBm
//#define A110LR09_POWER_NEG_10_0_DBM   // -10.0dBm
//#define A110LR09_POWER_NEG_15_0_DBM   // -15.0dBm
//#define A110LR09_POWER_NEG_20_0_DBM   // -20.0dBm
//#define A110LR09_POWER_NEG_25_0_DBM   // -25.0dBm
//#define A110LR09_POWER_NEG_30_0_DBM   // -30.0dBm

#endif /* A110LR09_CONFIG_H */
