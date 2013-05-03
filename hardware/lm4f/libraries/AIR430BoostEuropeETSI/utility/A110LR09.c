/**
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2012-13, Anaren Microwave, Inc.
 *
 *  For more information on licensing, please see Anaren Microwave, Inc's
 *  end user software licensing agreement: EULA.txt.
 *
 *  ----------------------------------------------------------------------------
 *
 *  A110LR09.h - Anaren Integrated Radio (AIR) module interface for the 
 *  A110LR09.
 *
 *  @version    1.0.01
 *  @date       28 Jan 2013
 *  @author     BPB, air@anaren.com
 *
 *  For details on the interface, please see A110LR09.h
 *
 *  assumptions
 *  ===========
 *  Same as A110LR09.h assumptions
 *
 *  file dependency
 *  ===============
 *	string.h : provides memset  
 *  A110LR09.h : provides interface function prototypes and global definitions
 *
 *  revision history
 *  ================
 *	ver 1.0.01 : 28 Jan 2013
 *	- updated driver to compensate output power when changing configuration and
 *	initializing the driver
 *  ver 1.0.00 : 16 Jan 2013
 *  - initial release
 */
#include <string.h>			// memset
#include "A110LR09.h"

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */
 
// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// -----------------------------------------------------------------------------
// A110LR09 ETSI applicable channels for sub-bands
// Note: It is assumed that all configurations are using 50kHz channel spacing
const unsigned char gA110LR09ChannelList[] = {
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
  30, 31, 32, 33, 34, 35, 36, 37
};

const struct sA110x2500ChannelList gA110LR09ChannelLookup[] = {
  // Approved channels: 2-37
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[2],
    36
  },
  // Approved channels: 3-35
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[3],
    33
  },
  // Approved channels: 1-37
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[1],
    37
  },
  // Approved channels: 2-36
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[2],
    35
  },
  // Approved channels: 12-26
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[12],
    15
  },
  // Approved channels: 4-35
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[4],
    32
  },
  // Approved channels: 5-34
  {
    eA110x2500ChannelListApproved,
    &gA110LR09ChannelList[5],
    30
  },
};

// -----------------------------------------------------------------------------
// A110LR09 certified configuration definitions

const struct sA110x2500Lookup gA110LR09Lookup[] = {
  // FCC/IC approved configurations
  // 2-FSK, 1.2kBaud, 7dBm max output power, 902MHz
  #ifdef A110LR09_FCC_2FSK_1_2_KBAUD
	#define	A110LR09_FCC
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0x3D, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x0C,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x21,                                                                     // Frequency control word, high byte
      0x6B,                                                                     // Frequency control word, middle byte
      0x24,                                                                     // Frequency control word, low byte
      0x15,                                                                     // Modem configuration
      0x75,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x21,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      0x71,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x47,                                                                     // AGC control
      READ_MODIFY_WRITE(0x40, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0xB7,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3E,                                                                     // Not supporter (agctest)
      0x88,                                                                     // Various test settings
      0x31,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(7.0), 0xCD },      // 7dBm max
    NULL,                               // No channel restrictions
    2 * A110LR09_1_2_KBAUD_RSSI_OFFSET,
    {
      12,                               // 1.2kBaud
      A110LR09_BAUD_RATE_MULTIPLIER     
    },
    1000                                // No duty cycle requirements
  },
  #endif
  // 2-FSK, 38kBaud, 8dBm max output power, 902MHz
  #ifdef A110LR09_FCC_2FSK_38_KBAUD
	#define	A110LR09_FCC
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x0C,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x21,                                                                     // Frequency control word, high byte
      0x6B,                                                                     // Frequency control word, middle byte
      0x24,                                                                     // Frequency control word, low byte
      0x1A,                                                                     // Modem configuration
      0x71,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x21,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      0x71,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x47,                                                                     // AGC control
      READ_MODIFY_WRITE(0x40, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0xB7,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x88,                                                                     // Various test settings
      0x31,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(8.0), 0xCA },      // 8dBm max
    NULL,                               // No channel restrictions
    2 * A110LR09_38_KBAUD_RSSI_OFFSET,
    {
      380,                              // 38kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1000                                // No duty cycle requirements
  },
  #endif
  // 2-FSK, 100kBaud, 10dBm max output power, 902MHz
  #ifdef A110LR09_FCC_2FSK_100_KBAUD
	#define	A110LR09_FCC
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x0D,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x21,                                                                     // Frequency control word, high byte
      0x6B,                                                                     // Frequency control word, middle byte
      0x24,                                                                     // Frequency control word, low byte
      0x1B,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x21,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      0x71,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x47,                                                                     // AGC control
      READ_MODIFY_WRITE(0x40, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0xB7,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xEA, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x88,                                                                     // Various test settings
      0x31,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(10.0), 0xC4 },     // 10dBm max
    NULL,                               // No channel restrictions
    2 * A110LR09_100_KBAUD_RSSI_OFFSET,
    {
      1000,                             // 100kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1000                                // No duty cycle requirements
  },
  #endif
  // 2-FSK, 250kBaud, 12dBm max output power, 902MHz
  #ifdef A110LR09_FCC_2FSK_250_KBAUD
	#define	A110LR09_FCC
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0x3D, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x0D,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x21,                                                                     // Frequency control word, high byte
      0x6B,                                                                     // Frequency control word, middle byte
      0x24,                                                                     // Frequency control word, low byte
      0x0D,                                                                     // Modem configuration
      0x2F,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x21,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      0x71,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0xC7,                                                                     // AGC control
      READ_MODIFY_WRITE(0x40, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0xB7,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xEA, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x88,                                                                     // Various test settings
      0x31,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(12.0), 0xC0 },     // 12dBm max
    NULL,                               // No channel restrictions
    2 * A110LR09_250_KBAUD_RSSI_OFFSET,
    {
      2500,                             // 250kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1000                                // No duty cycle requirements
  },
  #endif

  // ETSI approved configurations
  // M4, 2-FSK, 1.2kBaud, 868MHz
  #ifdef A110LR09_ETSI_M4_2FSK_1_2_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x06,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xD5,                                                                     // Modem configuration
      0x75,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x40,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x6C,                                                                     // Bit synchronization Configuration
      0x04,                                                                     // AGC control
      READ_MODIFY_WRITE(0x41, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0x91,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0x56,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[0],         // Approved channels: 2-37
    2 * A110LR09_1_2_KBAUD_RSSI_OFFSET,
    {
      12,                               // 1.2kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M5, 2-FSK, 10kBaud, 868MHz
  #ifdef A110LR09_ETSI_M5_2FSK_10_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x06,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xB8,                                                                     // Modem configuration
      0x84,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x43,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x6C,                                                                     // Bit synchronization Configuration
      0x43,                                                                     // AGC control
      READ_MODIFY_WRITE(0x40, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0x91,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0x56,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[1],         // Approved channels: 3-35
    2 * A110LR09_10_KBAUD_RSSI_OFFSET,
    {
      100,                              // 10kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M6, GFSK, 10kBaud, 868MHz
  #ifdef A110LR09_ETSI_M6_GFSK_10_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x06,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xF8,                                                                     // Modem configuration
      0x84,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x13, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x30,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x6C,                                                                     // Bit synchronization Configuration
      0x43,                                                                     // AGC control
      READ_MODIFY_WRITE(0x4D, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0x91,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0x56,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[2],         // Approved channels: 1-37
    2 * A110LR09_10_KBAUD_RSSI_OFFSET,
    {
      100,                              // 10kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M7, GFSK, 38kBaud, 868MHz
  #ifdef A110LR09_ETSI_M7_GFSK_38_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x06,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xEA,                                                                     // Modem configuration
      0x71,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x13, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x33,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x6C,                                                                     // Bit synchronization Configuration
      0x43,                                                                     // AGC control
      READ_MODIFY_WRITE(0x4F, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0x91,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0x56,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[0],         // Approved channels: 2-37
    2 * A110LR09_38_KBAUD_RSSI_OFFSET,
    {
      38,                               // 38kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M11, 2-FSK, 0.6kBaud, 868MHz
  #ifdef A110LR09_ETSI_M11_2FSK_0_6_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x04,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xF4,                                                                     // Modem configuration
      0x75,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x03, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x32,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x6C,                                                                     // Bit synchronization Configuration
      0x03,                                                                     // AGC control
      READ_MODIFY_WRITE(0x43, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0x91,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xFB,                                                                     // Not supported (worctrl1)
      0x56,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[0],         // Approved channels: 2-37
    2 * A110LR09_0_6_KBAUD_RSSI_OFFSET,
    {
      6,                                // 0.6kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M12, GFSK, 4.8kBaud, 868MHz
  #ifdef A110LR09_ETSI_M12_GFSK_4_8_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0x3D, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x05,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xF7,                                                                     // Modem configuration
      0x75,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x13, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x30,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x6C,                                                                     // Bit synchronization Configuration
      0x04,                                                                     // AGC control
      READ_MODIFY_WRITE(0x4F, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0x91,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xFB,                                                                     // Not supported (worctrl1)
      0x56,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[0],         // Approved channels: 2-37
    2 * A110LR09_4_8_KBAUD_RSSI_OFFSET,
    {
      48,                               // 4.8kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M13, GFSK, 19.2kBaud, 868MHz
  #ifdef A110LR09_ETSI_M13_GFSK_19_2_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0x3D, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x05,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xF9,                                                                     // Modem configuration
      0x75,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x13, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x30,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x16,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x05,                                                                     // AGC control
      READ_MODIFY_WRITE(0x4E, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xFB,                                                                     // Not supported (worctrl1)
      0xB6,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[2],         // Approved channels: 1-37
    2 * A110LR09_19_2_KBAUD_RSSI_OFFSET,
    {
      192,                              // 19.2kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M14, RX, 4-FSK, 300kBaud, 868MHz
  #ifdef A110LR09_ETSI_M14_RX_4FSK_300_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0x3D, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x0E,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0x0D,                                                                     // Modem configuration
      0x6C,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x43, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x72,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0xC4,                                                                     // AGC control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xFB,                                                                     // Not supported (worctrl1)
      0xB7,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xEA, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3C,                                                                     // Not supporter (agctest)
      0x88,                                                                     // Various test settings
      0x31,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.4), 0x83 },      // 4.4dBm max
    &gA110LR09ChannelLookup[4],         // Approved channels: 12-26
    2 * A110LR09_300_KBAUD_RSSI_OFFSET,
    {
      3000,                             // 300kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // M14, TX, 4-FSK, 300kBaud
  #ifdef A110LR09_ETSI_M14_TX_4FSK_300_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x87, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0x3D, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x0E,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0x0D,                                                                     // Modem configuration
      0x6C,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x43, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x71,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0xC4,                                                                     // AGC control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xFB,                                                                     // Not supported (worctrl1)
      0xB7,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xEA, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3C,                                                                     // Not supporter (agctest)
      0x88,                                                                     // Various test settings
      0x31,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.4), 0x83 },      // 4.4dBm max
    &gA110LR09ChannelLookup[4],         // Approved channels: 12-26
    2 * A110LR09_300_KBAUD_RSSI_OFFSET,
    {
      3000,                             // 300kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // ML1, GFSK, 50kBaud, 868MHz
  #ifdef A110LR09_ETSI_ML1_GFSK_50_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x05,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0xBA,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x13, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x37,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x82,                                                                     // AGC control
      READ_MODIFY_WRITE(0x0D, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB2,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0xB6,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xE9, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(4.6), 0x82 },      // 4.6dBm max (low temp)
    &gA110LR09ChannelLookup[3],         // Approved channels: 2-36
    2 * A110LR09_50_KBAUD_RSSI_OFFSET,
    {
      500,                              // 50kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
  // ML2, GFSK, 100kBaud, 868MHz
  #ifdef A110LR09_ETSI_ML2_GFSK_100_KBAUD
	#define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x07, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x08,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0x8B,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x13, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x20,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x47,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x85,                                                                     // AGC control
      READ_MODIFY_WRITE(0x0D, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xB2,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xF8,                                                                     // Not supported (worctrl1)
      0xB6,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xEA, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(-2.0), 0x40 },     // -2.0dBm max
    &gA110LR09ChannelLookup[5],         // Approved channels: 4-35
    2 * A110LR09_100_KBAUD_RSSI_OFFSET,
    {
      1000,                             // 100kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },  
  #endif
  // ML3, 4-FSK, 100kBaud, 868MHz
  #ifdef A110LR09_ETSI_ML3_4FSK_100_KBAUD
  #define	A110LR09_ETSI
  {
    {
      READ_MODIFY_WRITE(0x29, A110LR09_USER_IOCFG2, 0xFF),                      // GDO2 output pin configuration
      READ_MODIFY_WRITE(0x2E, A110LR09_USER_IOCFG1, 0xFF),                      // GDO1 output pin configuration
      READ_MODIFY_WRITE(0x06, A110LR09_USER_IOCFG0, 0xFF),                      // GDO0 output pin configuration
      READ_MODIFY_WRITE(0x87, A110LR09_USER_FIFOTHR, A110X2500_FIFOTHR_MASK),   // RXFIFO and TXFIFO thresholds
      0xD3,                                                                     // Sync word, high byte
      0x91,                                                                     // Sync word, low byte
      READ_MODIFY_WRITE(0xFF, A110LR09_USER_PKTLEN, 0xFF),                      // Packet length
      READ_MODIFY_WRITE(0x04, A110LR09_USER_PKTCTRL1, A110X2500_PKTCTRL1_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x45, A110LR09_USER_PKTCTRL0, A110X2500_PKTCTRL0_MASK), // Packet automation control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_ADDR, 0xFF),                        // Device address
      READ_MODIFY_WRITE(0x00, A110LR09_USER_CHANNR, 0xFF),                      // Channel number
      0x06,                                                                     // Frequency synthesizer control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_FSCTRL0, 0xFF),                     // Frequency synthesizer control
      0x20,                                                                     // Frequency control word, high byte
      0x25,                                                                     // Frequency control word, middle byte
      0xED,                                                                     // Frequency control word, low byte
      0x8B,                                                                     // Modem configuration
      0xE5,                                                                     // Modem configuration
      READ_MODIFY_WRITE(0x43, A110LR09_USER_MDMCFG2, A110X2500_MDMCFG2_MASK),   // Modem configuration
      0x40,                                                                     // Modem configuration
      0xF8,                                                                     // Modem configuration
      0x47,                                                                     // Modem deviation setting (when FSK modulation is enabled)
      READ_MODIFY_WRITE(0x07, A110LR09_USER_MCSM2, A110X2500_MCSM2_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x30, A110LR09_USER_MCSM1, A110X2500_MCSM1_MASK),       // Main Radio Control State Machine configuration
      READ_MODIFY_WRITE(0x18, A110LR09_USER_MCSM0, 0xFF),                       // Main Radio Control State Machine configuration
      0x1D,                                                                     // Frequency Offset Compensation Configuration
      0x1C,                                                                     // Bit synchronization Configuration
      0x84,                                                                     // AGC control
      READ_MODIFY_WRITE(0x00, A110LR09_USER_AGCCTRL1, A110X2500_AGCCTRL1_MASK), // AGC control
      0xF0,                                                                     // AGC control
      0x00,                                                                     // Not supported (worevt1)
      0x00,                                                                     // Not supported (worevt0)
      0xFB,                                                                     // Not supported (worctrl1)
      0xB6,                                                                     // Front end RX configuration
      0x10,                                                                     // Front end RX configuration
      READ_MODIFY_WRITE(0xEA, A110LR09_USER_FSCAL3, A110X2500_FSCAL3_MASK),     // Frequency synthesizer calibration
      0x2A,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Frequency synthesizer calibration
      0x1F,                                                                     // Frequency synthesizer calibration
      0x00,                                                                     // Not supported (rcctrl1)
      0x00,                                                                     // Not supported (rcctrl0)
      0x59,                                                                     // Not supported (fstest)
      0x7F,                                                                     // Not supported (ptest)
      0x3F,                                                                     // Not supporter (agctest)
      0x81,                                                                     // Various test settings
      0x35,                                                                     // Various test settings
      0x09                                                                      // Various test settings
    },
    { POWER_TO_VALUE(-2.0), 0x40 },     // -2.0dBm max
    &gA110LR09ChannelLookup[6],         // Approved channels: 5-34
    2 * A110LR09_100_KBAUD_RSSI_OFFSET,
    {
      1000,                             // 100kBaud
      A110LR09_BAUD_RATE_MULTIPLIER
    },
    1                                   // 0.1% duty cycle or LBT+AFA
  },
  #endif
};

#if defined( A110LR09_ETSI) && defined( A110LR09_FCC )
#error "A110LR09 Error: ETSI and FCC configurations may not be selected at the same time"
#endif

// -----------------------------------------------------------------------------
// A110LR09 power lookup table

/**
 *  gA110LR09PowerLookup - power lookup table for all A110LR09 modules. 
 *
 *  Note: When defining multiple A110LR09 physical information structures, all
 *  modules will have to use the same power lookup table values. It is currently
 *  not possible for each A110LR09 module to have their own dedicated and 
 *  unique lookup table.
 */
const struct sA110x2500PowerLookup gA110LR09PowerLookup[] = {
  #ifdef A110LR09_POWER_12_0_DBM
  { POWER_TO_VALUE(12.0),   0xC0 },
  #endif
  #ifdef A110LR09_POWER_11_0_DBM
  { POWER_TO_VALUE(11.0),   0xC1 },
  #endif
  #ifdef A110LR09_POWER_10_5_DBM
  { POWER_TO_VALUE(10.5),   0xC2 },
  #endif
  #ifdef A110LR09_POWER_10_3_DBM
  { POWER_TO_VALUE(10.3),   0xC3 },
  #endif
  #ifdef A110LR09_POWER_10_0_DBM
  { POWER_TO_VALUE(10.0),   0xC4 },
  #endif
  #ifdef A110LR09_POWER_9_6_DBM
  { POWER_TO_VALUE(9.6),    0xC5 },
  #endif
  #ifdef A110LR09_POWER_9_2_DBM
  { POWER_TO_VALUE(9.2),    0xC6 },
  #endif
  #ifdef A110LR09_POWER_9_0_DBM
  { POWER_TO_VALUE(9.0),    0xC7 },
  #endif
  #ifdef A110LR09_POWER_8_6_DBM
  { POWER_TO_VALUE(8.6),    0xC8 },
  #endif
  #ifdef A110LR09_POWER_8_2_DBM
  { POWER_TO_VALUE(8.2),    0xC9 },
  #endif
  #ifdef A110LR09_POWER_8_0_DBM
  { POWER_TO_VALUE(8.0),    0xCA },
  #endif
  #ifdef A110LR09_POWER_7_6_DBM
  { POWER_TO_VALUE(7.6),    0xCB },
  #endif
  #ifdef A110LR09_POWER_7_2_DBM
  { POWER_TO_VALUE(7.2),    0xCC },
  #endif
  #ifdef A110LR09_POWER_7_0_DBM
  { POWER_TO_VALUE(7.0),    0xCD },
  #endif
  #ifdef A110LR09_POWER_6_2_DBM
  { POWER_TO_VALUE(6.2),    0xCE },
  #endif
  #ifdef A110LR09_POWER_5_0_DBM
  { POWER_TO_VALUE(5.0),    0x80 },
  #endif
  #ifdef A110LR09_POWER_4_8_DBM
  { POWER_TO_VALUE(4.8),    0x81 },
  #endif
  #ifdef A110LR09_POWER_4_6_DBM
  { POWER_TO_VALUE(4.6),    0x82 },
  #endif
  #ifdef A110LR09_POWER_4_4_DBM
  { POWER_TO_VALUE(4.4),    0x83 },
  #endif
  #ifdef A110LR09_POWER_4_2_DBM
  { POWER_TO_VALUE(4.2),    0x84 },
  #endif
  #ifdef A110LR09_POWER_4_0_DBM
  { POWER_TO_VALUE(4.0),    0x85 },
  #endif
  #ifdef A110LR09_POWER_3_6_DBM
  { POWER_TO_VALUE(3.6),    0x86 },
  #endif
  #ifdef A110LR09_POWER_3_4_DBM
  { POWER_TO_VALUE(3.4),    0xCF },
  #endif
  #ifdef A110LR09_POWER_3_0_DBM
  { POWER_TO_VALUE(3.0),    0x88 },
  #endif
  #ifdef A110LR09_POWER_2_5_DBM
  { POWER_TO_VALUE(2.5),    0x8A },
  #endif
  #ifdef A110LR09_POWER_2_0_DBM
  { POWER_TO_VALUE(2.0),    0x8B },
  #endif
  #ifdef A110LR09_POWER_1_0_DBM
  { POWER_TO_VALUE(1.0),    0x8D },
  #endif
  #ifdef A110LR09_POWER_0_0_DBM
  { POWER_TO_VALUE(0.0),    0x8E },
  #endif
  #ifdef A110LR09_POWER_NEG_0_5_DBM
  { POWER_TO_VALUE(-0.5),   0x70 },
  #endif
  #ifdef A110LR09_POWER_NEG_1_0_DBM
  { POWER_TO_VALUE(-1.0),   0x60 },
  #endif
  #ifdef A110LR09_POWER_NEG_2_0_DBM
  { POWER_TO_VALUE(-2.0),   0x40 },
  #endif
  #ifdef A110LR09_POWER_NEG_2_2_DBM
  { POWER_TO_VALUE(-2.2),   0x62 },
  #endif
  #ifdef A110LR09_POWER_NEG_5_0_DBM
  { POWER_TO_VALUE(-5.0),   0x67 },
  #endif
  #ifdef A110LR09_POWER_NEG_10_0_DBM
  { POWER_TO_VALUE(-10.0),  0x6D },
  #endif
  #ifdef A110LR09_POWER_NEG_15_0_DBM
  { POWER_TO_VALUE(-15.0),  0x24 },
  #endif
  #ifdef A110LR09_POWER_NEG_20_0_DBM
  { POWER_TO_VALUE(-20.0),  0x22 },
  #endif
  #ifdef A110LR09_POWER_NEG_25_0_DBM
  { POWER_TO_VALUE(-25.0),  0x14 },
  #endif
  #ifdef A110LR09_POWER_NEG_30_0_DBM
  { POWER_TO_VALUE(-30.0),  0x03 },
  #endif
};

// -----------------------------------------------------------------------------
/**
 *  Private interface
 */

// -----------------------------------------------------------------------------
/**
 *  Public interface
 */
bool A110LR09Init(struct sA110LR09PhyInfo *phyInfo,
                  const struct sCC1101Spi *spi,
                  const struct sCC1101Gdo *gdo[3])
{ 
  // Setup CC1101 device SPI driver.
  CC1101SpiInit(&phyInfo->cc1101, spi, NULL);
   
  // Setup CC1101 GDOx interface.
  CC1101GdoInit(&phyInfo->cc1101, gdo);
  
  // Verify that the CC110L is in a known (IDLE) state.
  CC1101Strobe(&phyInfo->cc1101, CC1101_SRES);
  
  // Verify that the underlying radio hardware is a CC110L.
  if (CC1101GetChip(&phyInfo->cc1101) != eCC1101Chip110L)
  {
		// Attempt to identify the chip a second time.
		if (CC1101GetChip(&phyInfo->cc1101) != eCC1101Chip110L)
		{
			// Fatal Error: Failed to identify chip. This module may only be used in
			// conjunction with the CC110L chip.
			while (true);
		}
  }
  
  // Configure the CC1101 using the default certified settings (index 0 in the
  // lookup table).
  if (!A110LR09Configure(phyInfo, A110LR09GetLookup(0)))
  {
    return false;
  }

  return true;
}

const struct sA110x2500Lookup* A110LR09GetLookup(unsigned char entry)
{
  if (entry < sizeof(gA110LR09Lookup) / sizeof(struct sA110x2500Lookup))
  {
    return &gA110LR09Lookup[entry];
  }
  
  return NULL;
}

unsigned char A110LR09GetLookupSize()
{
  return sizeof(gA110LR09Lookup) / sizeof(struct sA110x2500Lookup);
}

const struct sA110x2500PowerLookup* A110LR09GetPowerLookup(unsigned char entry)
{
  if (entry < sizeof(gA110LR09PowerLookup) / sizeof(struct sA110x2500PowerLookup))
  {
    return &gA110LR09PowerLookup[entry];
  }
  
  return NULL;
}

unsigned char A110LR09GetPowerLookupSize(void)
{
  return sizeof(gA110LR09PowerLookup) / sizeof(struct sA110x2500PowerLookup);
}

bool A110LR09Configure(struct sA110LR09PhyInfo *phyInfo,
                       const struct sA110x2500Lookup* config)
{
  // Setup A1101R09 physical information.
  if (config == NULL)
  {
    // Cannot configure with a NULL configuration lookup table entry.
    return false;
  }
  phyInfo->module.lookup = (struct sA110x2500Lookup*)config;

  // Configure hardware registers that can effect certification and RF 
  // performance. Set up output power table.
  if (!CC1101Configure(&phyInfo->cc1101, &phyInfo->module.lookup->certified))
  {
    return false;
  }

  // Set the initial power level (index 0 in the lookup or the maximum allowed).
  memset(phyInfo->module.paTable, 0, A110LR09_PA_TABLE_SIZE);
  A110LR09SetPaTable(phyInfo, phyInfo->module.paTable);
  
  // Set the initial channel (first approved).
  if (!A110LR09SetChannr(phyInfo, phyInfo->module.lookup->certified.channr))
  {
    return false;
  }
  
  return true;
}

void A110LR09SetPaTable(struct sA110LR09PhyInfo *phyInfo, 
                        unsigned char powerEntry[A110LR09_PA_TABLE_SIZE])
{
  unsigned char value = 0x00;
  unsigned char i;

  // Verify index is within bounds of the power lookup table and that the level
  // does not exceed the maximum allowed.
	for (i = 0; i < A110LR09_PA_TABLE_SIZE; i++)
	{
		if (powerEntry[i] > A110LR09GetPowerLookupSize())
		{
			// Check if the last entry in the lookup table exceeds the maximum power
			// level.
			if (gA110LR09PowerLookup[A110LR09GetPowerLookupSize()-1].dBm > phyInfo->module.lookup->maxPower.dBm)
			{
				// Override entry provided using the maximum power.
				value = phyInfo->module.lookup->maxPower.value;
			}
			else
			{
				// Set the last power level specified in the lookup table.
				value = gA110LR09PowerLookup[A110LR09GetPowerLookupSize()-1].value;
			}
		}
		else
		{
			// The entry was within valid bounds, does it exceed the maximum power 
			// limit?
			if (gA110LR09PowerLookup[powerEntry[i]].dBm > phyInfo->module.lookup->maxPower.dBm)
			{
				// Override entry provided using the maximum power.
				value = phyInfo->module.lookup->maxPower.value;
			}
			else
			{
				// Entry provided is a valid power level for this configuration. The value
				// does not exceed the maximum allowed.
				value = gA110LR09PowerLookup[powerEntry[i]].value;
			}
		}

		// Adjust the PA table to use the selected power level value(s).
    phyInfo->module.paTable[i] = value;
	}

  CC1101WriteRegisters(&(phyInfo->cc1101), 
                       CC1101_PATABLE, 
                       phyInfo->module.paTable,
                       (phyInfo->module.lookup->certified.frend0 & CC1101_PA_POWER) + 1);
}

signed int A110LR09ConvertRssiToDbm(struct sA110LR09PhyInfo *phyInfo,
                                    signed char rssi)
{  
  /**
   *  Convert the RSSI into absolute RSSI while keeping the 1/2 dB resolution.
   *  The number will appear twice as large because the demical point is implied
   *  between bit zero and bit one of the integer. For more information, please
   *  see Jim Noxon's answer describing how to convert the raw value into 
   *  absolute here: http://e2e.ti.com/support/low_power_rf/f/156/t/100344.aspx
   *
   *  Note: The RSSI offset should be represented as RSSI_OFFSET * 2.
   */
  return ((signed int)rssi) - phyInfo->module.lookup->rssiOffset;
}

// -----------------------------------------------------------------------------
// Modifiable configuration registers

bool A110LR09SetChannr(struct sA110LR09PhyInfo *phyInfo, unsigned char value)
{
  struct sA110x2500Lookup *lookup = (struct sA110x2500Lookup*)phyInfo->module.lookup;
  
  // Is there any restrictions for channel usage with this configuration?
  if (lookup->channelList != NULL)
  {
    bool found = false;   // Entry found flag
    unsigned char i;      // Channel list iterator
    
    // Search for entry in the channel list.  
    for (i = 0; i < lookup->channelList->size; i++)
    {
      if (lookup->channelList->list[i] == value)
      {
        // Entry found in the channel list.
        found = true;
        break;
      }
    }
    if (!found)
    {
      // Check if the list represents approved channels. If so, the desired
      // channel is not approved for usage with the selected configuration.
      if (lookup->channelList->listApproval == eA110x2500ChannelListApproved)
      {
        // Set the first possible channel by default - choose the first approved
        // channel in the list.
        CC1101SetRegister(&phyInfo->cc1101, 
                          CC1101_REG_CHANNR, 
                          lookup->channelList->list[0]);
        return false;
      }
    }
    else
    {
      // Check if the list represents disapproved channels. If so, the desired
      // channel is not approved for usage with the selected configuration.
      if (lookup->channelList->listApproval == eA110x2500ChannelListDisapproved)
      {
        unsigned char i;
        
        // Set the first possible channel by default - since the list represents
        // disapproved channels, search for first available channel.
        for (i = 0; i < 255; i++)
        {
          if (i != lookup->channelList->list[i])
          {
            break;
          }
        }
        CC1101SetRegister(&phyInfo->cc1101, CC1101_REG_CHANNR, i);
        return false;
      }
    }
  }

  CC1101SetRegister(&phyInfo->cc1101, CC1101_REG_CHANNR, value);

  return true;
}
