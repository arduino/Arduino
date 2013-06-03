#ifndef A110LR09_H
#define A110LR09_H
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
 *  The A110LR09 module operates in the 868/915MHz dual band and incorporates 
 *  the Texas Instruments CC110L value line low-power RF transceiver chip. The 
 *  settings provided in this interface are qualified if used as recommended. 
 *  For more information on certified use, please see the A110LR09 User's 
 *  Manual.
 *
 *  This interface provides settings to be used with the Anaren's A110LR09 
 *  modules. It also provides a layer of meaning to raw CC110L register values 
 *  such as output power levels, which are be dependent on the RF design.
 *
 *  Note: This interface is designed to work with Anaren's CC110X/2500 Device 
 *  Driver.
 *
 *  Note: The term "certified" used throughout ONLY HOLDS TRUE when this 
 *  interface is used as-is and as recommended by the A110LR09x User's Manual.
 *  Please refer to the A110LR09 User's Manual for more information on 
 *  requirements for regulatory compliance.
 *
 *  A110LR09 Module Settings Selection
 *  ----------------------------------------------------------------------------
 *
 *  The A110LR09 Module interface provides flexibility of defining how the radio
 *  hardware should operate. Definitions dictate the operation of the radio.
 *  These definitions need to be defined in an "A110LR09Config.h" file (the name 
 *  of the file is important!) or a preprocessor preincluded file. This 
 *  interface will attempt to include "A110LR09Config.h" even if the definitions 
 *  are in a preincluded file. If the file is not found, there will be a 
 *  compilation error. To prevent this, ALWAYS create a file named 
 *  "A110LR09Config.h" even if the file is empty.
 *
 *  Configuration and Power Settings
 *  ----------------------------------------------------------------------------
 *  
 *  Available configurations and power settings can be found in the A110LR09
 *  User's Manual, A110x2500 Programmer's Guide, or below.
 *  
 *  To select the configurations that should be available for use in your
 *  application, define any of the following in your compiler's preprocessor
 *  definitions:
 *    
 *      Configuration settings (FCC/IC)
 *
 *      #define A110LR09_FCC_2FSK_1_2_KBAUD         // 2FSK, 1.2kBaud, 902MHz
 *      #define A110LR09_FCC_2FSK_38_KBAUD          // 2FSK, 38kBaud, 902MHz
 *      #define A110LR09_FCC_2FSK_100_KBAUD         // 2FSK, 100kBaud, 902MHz
 *      #define A110LR09_FCC_2FSK_250_KBAUD         // 2FSK, 250kBaud, 902MHz
 *
 *      Configuration settings (ETSI)
 *
 *      #define A110LR09_ETSI_M4_2FSK_1_2_KBAUD     // M4, 2FSK, 1.2kBaud, 868MHz
 *      #define A110LR09_ETSI_M5_2FSK_10_KBAUD      // M5, 2FSK, 10kBaud, 868MHz
 *      #define A110LR09_ETSI_M6_GFSK_10_KBAUD      // M6, GFSK, 10kBaud, 868MHz
 *      #define A110LR09_ETSI_M7_GFSK_38_KBAUD      // M7, GFSK, 38kBaud, 868MHz
 *      #define A110LR09_ETSI_M11_2FSK_0_6_KBAUD    // M11, 2FSK, 0.6kBaud, 868MHz
 *      #define A110LR09_ETSI_M12_GFSK_4_8_KBAUD    // M12, GFSK, 4.8kBaud, 868MHz
 *      #define A110LR09_ETSI_M13_GFSK_19_2_KBAUD   // M13, GFSK, 19.2kBaud, 868MHz
 *      #define A110LR09_ETSI_M14_RX_4FSK_300_KBAUD // M14, RX, 4FSK, 300kBaud, 868MHz
 *      #define A110LR09_ETSI_M14_TX_4FSK_300_KBAUD // M14, TX, 4FSK, 300kBaud, 868MHz
 *      #define A110LR09_ETSI_ML1_GFSK_50_KBAUD     // ML1, GFSK, 50kBaud, 868MHz
 *      #define A110LR09_ETSI_ML2_GFSK_100_KBAUD    // ML2, GFSK, 100kBaud, 868MHz
 *      #define A110LR09_ETSI_ML3_4FSK_100_KBAUD    // ML3, 4FSK, 100kBaud, 868MHz
 *
 *  By defining any of the above, you will be compiling in the appropriate
 *  lookup tables that can be used by your application. The more configurations
 *  needed, the more ROM and RAM that will be used by this interface.
 *
 *  Note: When using this interface, at least one of the above configurations
 *  must be defined! If none are defined, compilation will fail.
 *
 *  All of the configurations require preprocessor defines for user modifiable
 *  register values. These register values are application specific and will be
 *  defined for all configurations in the lookup table. The following lists all 
 *  the required values from the user with some specified default values (these
 *  values should be changed based on the application):
 *
 *  Note: As per the A110LR09 User's Guide, the below settings do not affect
 *  compliance! They may be changed as needed to meet application requirements.
 *
 *      #define A110LR09_USER_IOCFG2    0x29  // GDO2 output pin configuration
 *      #define A110LR09_USER_IOCFG1    0x2E  // GDO1 output pin configuration
 *      #define A110LR09_USER_IOCFG0    0x3F  // GDO0 output pin configuration
 *      #define A110LR09_USER_FIFOTHR   0x07  // RX FIFO and TX FIFO thresholds
 *      #define A110LR09_USER_PKTLEN    0xFF  // packet length
 *      #define A110LR09_USER_PKTCTRL1  0x04  // packet automation control 1
 *      #define A110LR09_USER_PKTCTRL0  0x43  // packet automation control 0
 *      #define A110LR09_USER_ADDR      0x00  // device address
 *      #define A110LR09_USER_CHANNR    0x00  // channel number
 *      #define A110LR09_USER_FSCTRL0   0x00  // frequency synthesizer control 0
 *      #define A110LR09_USER_MDMCFG2   0x02  // modem configuration 2
 *      #define A110LR09_USER_MCSM2     0x07  // main radio control state machine configuration 2
 *      #define A110LR09_USER_MCSM1     0x30  // main radio control state machine configuration 1
 *      #define A110LR09_USER_MCSM0     0x04  // main radio control state machine configuration 0
 *      #define A110LR09_USER_AGCCTRL1  0x40  // AGC control 1
 *      #define A110LR09_USER_FSCAL3    0xA9  // frequency synthesizer calibration 3
 *  
 *  Power table values must be defined to compile the module as well. One or 
 *  more values may be compiled in depending on the application requirements.
 *  For each power value defined, an entry is added to the power table. This 
 *  allows for more entries to be used at run-time. The following list defines 
 *  possible power table values:
 *
 *      #define A110LR09_POWER_12_0_DBM       // 12.0dBm
 *      #define A110LR09_POWER_11_0_DBM       // 11.0dBm
 *      #define A110LR09_POWER_10_5_DBM       // 10.5dBm
 *      #define A110LR09_POWER_10_3_DBM       // 10.3dBm
 *      #define A110LR09_POWER_10_0_DBM       // 10.0dBm
 *      #define A110LR09_POWER_9_6_DBM        // 9.6dBm
 *      #define A110LR09_POWER_9_2_DBM        // 9.2dBm
 *      #define A110LR09_POWER_9_0_DBM        // 9.0dBm
 *      #define A110LR09_POWER_8_6_DBM        // 8.6dBm
 *      #define A110LR09_POWER_8_2_DBM        // 8.2dBm
 *      #define A110LR09_POWER_8_0_DBM        // 8.0dBm
 *      #define A110LR09_POWER_7_6_DBM        // 7.6dBm
 *      #define A110LR09_POWER_7_2_DBM        // 7.2dBm
 *      #define A110LR09_POWER_7_0_DBM        // 7.0dBm
 *      #define A110LR09_POWER_6_2_DBM        // 6.2dBm
 *      #define A110LR09_POWER_5_0_DBM        // 5.0dBm
 *      #define A110LR09_POWER_4_8_DBM        // 4.8dBm
 *      #define A110LR09_POWER_4_6_DBM        // 4.6dBm
 *      #define A110LR09_POWER_4_4_DBM        // 4.4dBm
 *      #define A110LR09_POWER_4_2_DBM        // 4.2dBm
 *      #define A110LR09_POWER_4_0_DBM        // 4.0dBm
 *      #define A110LR09_POWER_3_6_DBM        // 3.6dBm
 *      #define A110LR09_POWER_3_4_DBM        // 3.4dBm
 *      #define A110LR09_POWER_3_0_DBM        // 3.0dBm
 *      #define A110LR09_POWER_2_5_DBM        // 2.5dBm
 *      #define A110LR09_POWER_2_0_DBM        // 2.0dBm
 *      #define A110LR09_POWER_1_0_DBM        // 1.0dBm
 *      #define A110LR09_POWER_0_0_DBM        // 0.0dBm
 *      #define A110LR09_POWER_NEG_0_5_DBM    // -0.5dBm
 *      #define A110LR09_POWER_NEG_1_0_DBM    // -1.0dBm
 *      #define A110LR09_POWER_NEG_2_0_DBM    // -2.0dBm
 *      #define A110LR09_POWER_NEG_2_2_DBM    // -2.2dBm
 *      #define A110LR09_POWER_NEG_5_0_DBM    // -5.0dBm
 *      #define A110LR09_POWER_NEG_10_0_DBM   // -10.0dBm
 *      #define A110LR09_POWER_NEG_15_0_DBM   // -15.0dBm
 *      #define A110LR09_POWER_NEG_20_0_DBM   // -20.0dBm
 *      #define A110LR09_POWER_NEG_25_0_DBM   // -25.0dBm
 *      #define A110LR09_POWER_NEG_30_0_DBM   // -30.0dBm
 *
 *  The following documents were used during the development of this device
 *  driver:
 *  - A110LR09x User's Manual (updated on 31 Oct 2011)
 *
 *  assumptions
 *  ===========
 *  - Anaren's CC1101 Device Driver is being used in conjunction with this
 *  interface.
 *  - One or more configurations have been defined in the project's preprocessor
 *  options. If none are defined, the module will not compile.
 *  - All of the user modifiable settings have initial values and are included.
 *  If one or more are not defined, the module will not compile.
 *
 *  file dependency
 *  ===============
 *  - stdbool.h defines the datatype "bool" which represents values "true" and
 *  "false".
 *  - A110x2500.h defines common definitions for the Anaren Integrated Radio 
 *	(AIR) CC110x2500-based modules.
 *  - CC1101.h defines Anaren's CC110x2500 Device Driver.
 *  - A110LR09Config.h must contain some or all required definitions unless
 *  another configuration file is used (THE OTHER CONFIG FILE MUST BE 
 *  PREINCLUDED FOR A110LR09 MODULE INTERFACE VISIBILITY!).
 *
 *  revision history
 *  ================
 *	ver 1.0.01 : 28 Jan 2013
 *	- updated driver to compensate output power when changing configuration and
 *	initializing the driver
 *  ver 1.0.00 : 16 Jan 2013
 *  - initial release
 */
#define A110LR09_INFO "A110LR09 1.0.01"

#ifndef bool
#define bool unsigned char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#include "A110x2500.h"
#include "CC1101.h"         // Includes CC110L support

// Radio configuration settings
#include "A110LR09Config.h"

#ifndef NULL
#define NULL  (void*)0
#endif

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */
 
// Power table
#define A110LR09_PA_TABLE_SIZE          2

// RSSI offset value definitions
#define A110LR09_0_6_KBAUD_RSSI_OFFSET  74
#define A110LR09_1_2_KBAUD_RSSI_OFFSET  74
#define A110LR09_4_8_KBAUD_RSSI_OFFSET  74
#define A110LR09_10_KBAUD_RSSI_OFFSET   74
#define A110LR09_19_2_KBAUD_RSSI_OFFSET 74
#define A110LR09_38_KBAUD_RSSI_OFFSET   74
#define A110LR09_50_KBAUD_RSSI_OFFSET   74
#define A110LR09_100_KBAUD_RSSI_OFFSET  74
#define A110LR09_250_KBAUD_RSSI_OFFSET  74
#define A110LR09_300_KBAUD_RSSI_OFFSET  74

// Modifiable configuration register masks
#define A110LR09_IOCFG2_MASK   (CC1101_GDO2_INV | CC1101_GDO2_CFG)
#define A110LR09_IOCFG1_MASK   (CC1101_GDO1_DS | CC1101_GDO1_INV | CC1101_GDO1_CFG)
#define A110LR09_IOCFG0_MASK   (CC1101_GDO0_TEMP_SENSOR_ENABLE | CC1101_GDO0_INV | CC1101_GDO0_CFG)
#define A110LR09_FIFOTHR_MASK  (CC1101_CLOSE_IN_RX | CC1101_FIFO_THR)
#define A110LR09_PKTLEN_MASK   CC1101_PACKET_LENGTH
#define A110LR09_PKTCTRL1_MASK (CC1101_PQT | CC1101_CRC_AUTOFLUSH | CC1101_APPEND_STATUS | CC1101_ADR_CHK)
#define A110LR09_PKTCTRL0_MASK (CC1101_CRC_EN | CC1101_LENGTH_CONFIG)
#define A110LR09_ADDR_MASK     CC1101_DEVICE_ADDR
#define A110LR09_CHANNR_MASK   CC1101_CHAN
#define A110LR09_FSCTRL0_MASK  CC1101_FREQOFF
#define A110LR09_MDMCFG2_MASK  CC1101_SYNC_MODE
#define A110LR09_MCSM2_MASK    (CC1101_RX_TIME_QUAL | CC1101_RX_TIME)
#define A110LR09_MCSM1_MASK    (CC1101_RXOFF_MODE | CC1101_TXOFF_MODE)
#define A110LR09_MCSM0_MASK    (CC1101_FS_AUTOCAL | CC1101_PO_TIMEOUT | CC1101_PIN_CTRL_EN | CC1101_XOSC_FORCE_ON)
#define A110LR09_AGCCTRL1_MASK (CC1101_CARRIER_SENSR_REL_THR | CC1101_CARRIER_SENSE_ABS_THR)
#define A110LR09_FSCAL3_MASK   CC1101_CHP_CURR_CAL_EN

/**
 *  sA110LR09PhyInfo - the A110LR09 module's information. It is composed of a
 *  CC1101 and the module's configurations, power, and rssi offset values.
 *
 *  Note: It is assumed that this structure is defined in static memory. This is
 *  because the A110LR09 interface depends on the integrity of the data stored
 *  for all its operations.
 */
struct sA110LR09PhyInfo
{
  struct sCC1101PhyInfo cc1101;
  struct sA110LR09Module
  {
    struct sA110x2500Lookup *lookup;                // Configuration lookup table
    unsigned char paTable[A110LR09_PA_TABLE_SIZE];  // Current PA table
  } module;
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */
// -----------------------------------------------------------------------------
/**
 *  Public interface
 */

/**
 *  A110LR09Init - initialize the A110LR09 module. Sets up the CC1101 SPI
 *  interface peripheral and I/O as well as the GDOx interface I/O. Configures
 *  the CC1101 with default certified settings and power based on selection from
 *  the lookup table.
 *
 *  Note: On successful initialization, the CC1101 will be in an IDLE state. The
 *  default certified configuration (index 0 in the lookup) and default power
 *  level (index 0 or maximum allowed) will be set.
 *
 *    @param  phyInfo             A110LR09 module state information used by the 
 *                                interface for all CC1101 chip interaction.
 *    @param  spi                 CC1101 SPI interface function pointers. This 
 *                                SPI interface is used for all radio 
 *                                configuration and operation.
 *    @param  gdo                 CC1101 GDOx interface function pointers. The 
 *                                GDOx line use is dependent on configuration 
 *                                register settings.
 *
 *    @return Success of the operation. If initialization was not successful, it
 *            was caused by either a failure to recognize compatible hardware
 *            (i.e. CC1101 chip) or an inability to configure the device (see
 *            A110LR09Configure for more information).
 */
bool A110LR09Init(struct sA110LR09PhyInfo *phyInfo,
                  const struct sCC1101Spi *spi,
                  const struct sCC1101Gdo *gdo[3]);

/**
 *  A110LR09GetLookup - get an entry from the certified settings lookup table.
 *
 *    @param  entry   Index of the desired lookup table entry.
 *
 *    @return Pointer to entry (if it exists) in the lookup table. Otherwise,
 *            NULL pointer (index-out-of-range error).
 */
const struct sA110x2500Lookup* A110LR09GetLookup(unsigned char entry);

/**
 *  A110LR09GetLookupSize - get the size of the certified settings lookup table.
 *
 *    @return Number of configurations available in the certified lookup table.
 */
unsigned char A110LR09GetLookupSize(void);

/**
 *  A110LR09GetPowerLookup - get an entry from the power lookup table.
 *
 *    @param  entry   Index of the desired power lookup table entry.
 *
 *    @return Pointer to entry (if it exists) in the lookup table. Otherwise,
 *            NULL pointer (index-out-of-range error).
 */
const struct sA110x2500PowerLookup* A110LR09GetPowerLookup(unsigned char entry);

/**
 *  A110LR09GetPowerLookupSize - get the size of the power lookup table.
 *
 *    @return Number of power values available.
 */
unsigned char A110LR09GetPowerLookupSize(void);

/**
 *  A110LR09Configure - configure the hardware using the certified settings
 *  lookup table.
 *
 *    @param  phyInfo   A110LR09 module state information used by the 
 *                      interface for all CC1101 chip interaction.
 *    @param  config    Entry in the certified configuration lookup table.
 *  
 *    @return Success of the operation. Configuration may fail if the config
 *            pointer provided is NULL or configuring the device has failed.
 *            Please see CC1101Configure for more information.
 */
bool A110LR09Configure(struct sA110LR09PhyInfo *phyInfo,
                       const struct sA110x2500Lookup* config);

/**
 *  A110LR09SetPaTable - set the power table.
 *
 *  Note: This operation cannot fail. To prevent it from failing, the following
 *  conditions are in place to set an appropriate power level,
 *
 *      1.  If the entry index provided does not exist and the last entry in the 
 *          power lookup exceeds the configuration's max power level, the max 
 *          limit will be set. 
 *      2.  If the entry provided does not exist and the last entry in the power
 *          lookup does not exceed the configuration's max power level, the last
 *          entry will be set.
 *      3.  If the entry index exists but exceeds the configuration's max power
 *          level, the max limit will be set.
 *      4.  If the entry index exists and does not exceed the configuration's
 *          max power level, the entry will be set.
 *
 *	Note: It is important that power entry indices are entered into the array
 *	in ascending order. This is because the power table should start at the
 *	lowest power and work towards the highest.
 *
 *    @param  phyInfo     A110LR09 module state information used by the
 *                        interface for all CC1101 chip interaction.
 *    @param  powerEntry  Index of the desired power level.
 */
void A110LR09SetPaTable(struct sA110LR09PhyInfo *phyInfo, 
                        unsigned char powerEntry[A110LR09_PA_TABLE_SIZE]);

/**
 *  A110LR09ConvertRssiToDbm - converts a raw RSSI value into an absolute power
 *  reading in 1/2dB increments.
 *
 *  Note: The value obtained is a fixed-point number formatted as follows,
 *  
 *           -------------------------------------------
 *          | sign | whole part |.|   fractional part   |
 *           -------------------------------------------
 *    Bits:    1         14                  1
 *
 *	If 1/2dB increments are not desired, the fractional part of the fixed point 
 *	number can be truncated using the following formula,
 *
 *			RssiDbm = (A110LR09ConvertRssiToDbm(Rssi) + 1) >> 1
 *
 *	where RssiDbm is the absolute reading in 1dB steps and Rssi is the raw RSSI
 *	value. The new value can be stored in one signed byte (e.g. char).
 *
 *    @param  phyInfo   A110LR09 module state information used by the interface
 *                      for all CC1101 chip interaction.
 *    @param  rssi			Raw reading from the RSSI hardware register.
 *
 *    @return	Fixed-point single RSSI reading.
 */
signed int A110LR09ConvertRssiToDbm(struct sA110LR09PhyInfo *phyInfo,
                                    signed char rssi);

/**
 *  A110LR09Wakeup - bring the device out of a low power state.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 */
#define A110LR09Wakeup(phyInfo)\
  CC1101Wakeup(&phyInfo->cc1101,\
               phyInfo->module.lookup->certified.agctest,\
               &phyInfo->module.lookup->certified.test2,\
               phyInfo->module.paTable,\
               (phyInfo->module.lookup->certified.frend0 & CC1101_PA_POWER) + 1)

// -----------------------------------------------------------------------------
// Modifiable configuration registers

/**
 *  A110LR09SetIocfg2 - set GDO2 output pin configuration.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for IOCFG2 register.
 */
#define A110LR09SetIocfg2(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_IOCFG2,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.iocfg2, value, A110LR09_IOCFG2_MASK))

/**
 *  A110LR09SetIocfg1 - set GDO1 output pin configuration.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for IOCFG1 register.
 */
#define A110LR09SetIocfg1(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_IOCFG1,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.iocfg1, value, 0xFF))

/**
 *  A110LR09SetIocfg0 - set GDO0 output pin configuration.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for IOCFG0 register.
 */
#define A110LR09SetIocfg0(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_IOCFG0,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.iocfg0, value, 0xFF))

/**
 *  A110LR09SetFifothr - set RF/TX FIFO thresholds.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for FIFOTHR register.
 */
#define A110LR09SetFifothr(phyInfo, value)\
   CC1101SetRegister(&phyInfo->cc1101,\
                     CC1101_REG_FIFOTHR,\
                     READ_MODIFY_WRITE(phyInfo->module.lookup->certified.fifothr, value, A110LR09_FIFOTHR_MASK))

/**
 *  A110LR09SetPktlen - set packet length (fixed) or maximum packet length
 *  (variable).
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for PKTLEN register.
 */
#define A110LR09SetPktlen(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_PKTLEN,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.pktlen, value, 0xFF))

/**
 *  A110LR09SetPktctrl1 - set packet automation control 1.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for PKTCTRL1 register.
 */
#define A110LR09SetPktctrl1(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_PKTCTRL1,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.pktctrl1, value, A110LR09_PKTCTRL1_MASK))

/**
 *  A110LR09SetPktctrl0 - set packet automation control 0.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for PKTCTRL0 register.
 */
#define A110LR09SetPktctrl0(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_PKTCTRL0,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.pktctrl0, value, A110LR09_PKTCTRL0_MASK))

/**
 *  A110LR09SetAddr - set device address.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for ADDR register.
 */
#define A110LR09SetAddr(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_ADDR,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.addr, value, 0xFF))

/**
 *  A110LR09SetChannr - set channel number.
 *
 *  Note: For information on configuration channel restrictions, please see the
 *  A110LR09 User's Manual.
 *
 *    @param  phyInfo   A110LR09 module state information used by the interface
 *                      for all CC1101 chip interaction.
 *    @param  value     Value for CHANNR register.
 *
 *    @return Success of the operation. If changing the channel was not 
 *            successful, the channel chosen is not approved for the selected
 *            certified configuration. If unsuccessful, the first possible
 *            approved channel is set.
 */
bool A110LR09SetChannr(struct sA110LR09PhyInfo *phyInfo, unsigned char value);

/**
 *  A110LR09SetFsctrl0 - set frequency synthesizer control 0.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for FSCTRL0 register.
 */
#define A110LR09SetFsctrl0(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_FSCTRL0,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.fsctrl0, value, 0xFF))

/**
 *  A110LR09SetMdmcfg2 - set modem configuration 2.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for MDMCFG2 register.
 */
#define A110LR09SetMdmcfg2(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_MDMCFG2,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.mdmcfg2, value, A110LR09_MDMCFG2_MASK))

/**
 *  A110LR09SetMcsm2 - set main radio control state machine configuration 2.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for MCSM2 register.
 */
#define A110LR09SetMcsm2(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_MCSM2,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.mcsm2, value, A110LR09_MCSM2_MASK))
/**
 *  A110LR09SetMcsm1 - set main radio control state machine configuration 1.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for MCSM1 register.
 */
#define A110LR09SetMcsm1(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_MCSM1,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.mcsm1, value, A110LR09_MCSM1_MASK))

/**
 *  A110LR09SetMcsm0 - set main radio control state machine configuration 0.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for MCSM0 register.
 */
#define A110LR09SetMcsm0(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_MCSM0,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.mcsm0, value, A110LR09_MCSM0_MASK))

/**
 *  A110LR09SetAgcctrl1 - set AGC control 1.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for AGCCTRL1 register.
 */
#define A110LR09SetAgcctrl1(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_AGCCTRL1,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.agcctrl1, value, A110LR09_AGCCTRL1_MASK))

/**
 *  A110LR09SetWorevt1 - set high byte event0 timeout.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value    Value for WOREVT1 register.
 */
#define A110LR09SetWorevt1(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_WOREVT1,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.worevt1, value, 0xFF))

/**
 *  A110LR09SetWorevt0 - set low byte event0 timeout.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value    Value for WOREVT0 register.
 */
#define A110LR09SetWorevt0(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_WOREVT0,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.worevt0, value, 0xFF))

/**
 *  A110LR09SetWorctrl - set wake on radio control.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for WORCTRL register.
 */
#define A110LR09SetWorctrl(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_WORCTRL,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.worctrl, value, 0xFF))

/**
 *  A110LR09SetFscal3 - set frequency synthesizer calibration 3.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for FSCAL3 register.
 */
#define A110LR09SetFscal3(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_FSCAL3,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.fscal3, value, A110LR09_FSCAL3_MASK))

/**
 *  A110LR09SetRcctrl1 - set RC oscillator configuration 1.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for RCCTRL1 register.
 */
#define A110LR09SetRcctrl1(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_RCCTRL1,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.rcctrl1, value, A110LR09_RCCTRL1_MASK))

/**
 *  A110LR09SetRcctrl0 - set RC oscillator configuration 0.
 *
 *  Note: Some fields in the register cannot be changed due to performance and 
 *  regulatory compliance. These fields are masked off so that they cannot be
 *  changed. Please refer to the module user's manual for more information on 
 *  performance and regulatory restrictions.
 *
 *    @param  struct sA110LR09PhyInfo*  phyInfo   A110LR09 module state 
 *                                                information used by the 
 *                                                interface for all chip 
 *                                                interaction.
 *    @param  unsigned char             value     Value for RCCTRL0 register.
 */
#define A110LR09SetRcctrl0(phyInfo, value)\
  CC1101SetRegister(&phyInfo->cc1101,\
                    CC1101_REG_RCCTRL0,\
                    READ_MODIFY_WRITE(phyInfo->module.lookup->certified.rcctrl0, value, A110LR09_RCCTRL0_MASK))

#endif  /* A110LR09_H */
