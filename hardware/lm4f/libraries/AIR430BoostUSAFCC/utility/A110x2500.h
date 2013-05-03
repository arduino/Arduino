#ifndef A110X2500_H
#define A110X2500_H
/**
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2012-13, Anaren Microwave, Inc.
 *
 *  For more information on licensing, please see Anaren Microwave, Inc's
 *  end user software licensing agreement: EULA.txt.
 *
 *  ----------------------------------------------------------------------------
 *
 *  A110X2500.h - Anaren Integrated Radio (AIR) module interface common
 *	definitions for the CC110x/2500-based modules.
 *
 *  @version    1.0.04
 *  @date       07 Dec 2012
 *  @author     BPB, air@anaren.com
 *
 *  The Anaren Integrated Radio (AIR) module product line features a broad range
 *  of low-power transceivers that can be used in Original Equipment 
 *  Manufacturer's (OEM) products. This file defines some common definitions
 *  used across the module interfaces. All supported AIR radio interfaces 
 *  require this common definitions file to be present.
 *
 *  assumptions
 *  ===========
 *  none
 *
 *  file dependency
 *  ===============
 *  none
 *
 *  revision history
 *  ================
 *	ver 1.0.04 : 07 Dec 2012
 *	- moved common structures into this file to reduce redundancy across the
 *	different modules
 *	- name changed from A1101 to A110x2500
 *  ver 1.0.03 : 23 Aug 2012
 *  - added a generic read-modify-write method
 *  ver 1.0.02 : 20 Jun 2012
 *  - added channel list structure
 *  - added power table entry structure
 *  ver 1.0.01 : 29 May 2012
 *  - removed power defines and replaced with a conversion macro. Defined 
 *  frequency bands that the AIR modules operate in.
 *  ver 1.0.00 : 21 May 2012
 *  - initial release
 */
#define A110X2500_INFO "A110X2500 1.0.04"

#ifndef bool
#define bool unsigned char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#include "CC1101.h"

// Supported chip information
#define A1101R04   0x01u
#define A1101R08   0x02u
#define A1101R09   0x03u
#define A110LR09   0x04u
#define A2500R24   0x05u

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

#ifndef READ_MODIFY_WRITE
#define READ_MODIFY_WRITE(old, new, mask) ((old & ~mask) | (new & mask))
#endif

// Power level
#ifndef POWER_TO_VALUE
#define POWER_TO_VALUE(power)      ((signed int)(power * 256)) // Multiply to keep 1/2dB resolution
#endif

// Baud rate multiplier
#define A110LR09_BAUD_RATE_MULTIPLIER   100

// Modifiable configuration register masks
#define A110X2500_IOCFG2_MASK   (CC1101_GDO2_INV | CC1101_GDO2_CFG)
#define A110X2500_IOCFG1_MASK   (CC1101_GDO1_DS | CC1101_GDO1_INV | CC1101_GDO1_CFG)
#define A110X2500_IOCFG0_MASK   (CC1101_GDO0_TEMP_SENSOR_ENABLE | CC1101_GDO0_INV | CC1101_GDO0_CFG)
#define A110X2500_FIFOTHR_MASK  (CC1101_CLOSE_IN_RX | CC1101_FIFO_THR)
#define A110X2500_PKTLEN_MASK   CC1101_PACKET_LENGTH
#define A110X2500_PKTCTRL1_MASK (CC1101_CRC_AUTOFLUSH | CC1101_APPEND_STATUS | CC1101_ADR_CHK)
#define A110X2500_PKTCTRL0_MASK (CC1101_CRC_EN | CC1101_LENGTH_CONFIG)
#define A110X2500_ADDR_MASK     CC1101_DEVICE_ADDR
#define A110X2500_CHANNR_MASK   CC1101_CHAN
#define A110X2500_FSCTRL0_MASK  CC1101_FREQOFF
#define A110X2500_MDMCFG2_MASK  CC1101_SYNC_MODE
#define A110X2500_MCSM2_MASK    (CC1101_RX_TIME_QUAL | CC1101_RX_TIME)
#define A110X2500_MCSM1_MASK    (CC1101_RXOFF_MODE | CC1101_TXOFF_MODE)
#define A110X2500_MCSM0_MASK    (CC1101_FS_AUTOCAL | CC1101_PO_TIMEOUT | CC1101_PIN_CTRL_EN | CC1101_XOSC_FORCE_ON)
#define A110X2500_AGCCTRL1_MASK (CC1101_CARRIER_SENSR_REL_THR | CC1101_CARRIER_SENSE_ABS_THR)
#define A110X2500_WOREVT1_MASK  CC1101_EVENT0_15_8
#define A110X2500_WOREVT0_MASK  CC1101_EVENT0_7_0
#define A110X2500_WORCTRL_MASK  (CC1101_RC_PD | CC1101_EVENT1 | CC1101_RC_CAL | CC1101_WOR_RES)
#define A110X2500_FSCAL3_MASK   CC1101_CHP_CURR_CAL_EN
#define A110X2500_RCCTRL1_MASK  CC1101_RCCTRL_1
#define A110X2500_RCCTRL0_MASK  CC1101_RCCTRL_0

/**
 *  eA110X2500Module - 
 */
enum eA110x2500Module
{
  eA110x2500ModuleUnknown = 0x00u,
  eA110x2500ModuleR04     = A1101R04,
  eA110x2500ModuleR08     = A1101R08,
  eA110x2500ModuleR09     = A1101R09,
  eA110x2500ModuleLR09    = A110LR09,
  eA110x2500ModuleR24     = A2500R24
};

/**
 *  sA110x2500PowerLookup - lookup table entry to correlate power in dBm with a
 *  PA table value.
 */
struct sA110x2500PowerLookup
{
  signed int dBm;         // Power is represented in dBm
  unsigned char value;    // Hardware register value representing power
};

/**
 *  sA110x2500ChannelList - the channel list used to hold channels that are
 *  approved or disapproved depending on the list approval type. Some certified
 *  configurations limit the channel usage. This structure will contain 
 *  information pertaining to which channels are approved or which channels are
 *  disapproved for use.
 */
struct sA110x2500ChannelList
{
  const enum eA110x2500ChannelList
  {
    eA110x2500ChannelListApproved,    // List contains approved channels
    eA110x2500ChannelListDisapproved  // List contains disapproved channels
  } listApproval;
  const unsigned char *list;    // List of channels
  const unsigned char size;     // Number of channels in the list
};

/**
 *  sA110X2500Lookup - configuration, power, and rssi offset settings for the 
 *  module. A global lookup table is defined and should be used by applications 
 *  desiring A1101R09 support. This structure is to be used in conjunction with 
 *  the A110x2500 physical information structure.
 *
 *  Note: The max duty cycle is represented as a fixed point number to allow for
 *  one decimal place precision. The decimal falls between the first and second
 *  decimal digits (i.e. 1000 = 100.0% and 1 = 0.1%).
 */
struct sA110x2500Lookup
{
  const struct sCC1101 certified;                   // Certified configuration
  const struct sA110x2500PowerLookup maxPower;      // Maximum configuration power
  const struct sA110x2500ChannelList *channelList;  // Approved configuration channel list
  const unsigned char rssiOffset;                   // Configuration RSSI offset
  struct sA110x2500BaudRate
  {
    const unsigned int value;         // Scaled baud rate value
    const unsigned int scaleFactor;   // Scale factor multiplier
  } baudRate;
  const unsigned int maxDutyCycle;    // Maximum configuration duty cycle
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// -----------------------------------------------------------------------------
/**
 *  Public interface
 */

#endif  /* A110X2500_H */
