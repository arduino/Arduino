#ifndef CC1101_H
#define CC1101_H
/**
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2012-13, Anaren Microwave, Inc.
 *
 *  For more information on licensing, please see Anaren Microwave, Inc's
 *  end user software licensing agreement: EULA.txt.
 *
 *  ----------------------------------------------------------------------------
 *
 *  CC1101.h - CC110x/2500 device driver.
 *
 *  @version    1.0.12
 *  @date       27 Sep 2012
 *  @author     BPB, air@anaren.com
 *
 *  The CC1101/110L is a transceiver intended for use in the Industrial, 
 *  Scientific, and Medical (ISM) bands at 315, 433, 868, and 915 MHz.
 *
 *  The CC2500 is a 2.4 GHz transceiver. It is mainly intended for use in the 
 *  ISM band and Short Range Device (SRD) frequency band at 2400-2483.5 MHz.
 *
 *  Note: The CC1101, CC110L, and CC2500 are all accessed the same way through 
 *  software. It is important to note that when CC1101 is stated throughout this 
 *  document, it is implied that the statement is also true for the CC110L and 
 *  CC2500. When there is a difference, it will be clearly stated.
 *
 *  Certain CC1101 Errata Note issues have been remedied in the implementation
 *  of this device driver. Due to this, there may be some additional overhead
 *  in some functions to provide correction to these issues. All basic CC1101
 *  operations are provided, but it is recommended to use functions written for
 *  specific operations instead of the generic ones such as GetRegister().
 *
 *  This interface defines the main functionality of these transceivers. To run 
 *  this interface, Serial Peripheral Interface (SPI) support must be available 
 *  and a SPI device driver must be used to communicate with internal radio 
 *  registers. SPI is used for all configuration and operation of the 
 *  transceiver chip.
 *
 *      Processor (Master) <=> SPI <=> CC1101_2500 (Slave)
 *
 *  The CC1101 interface defines function pointers to be used with your 
 *  implemented SPI interface. It provides a hook for a SPI initialization 
 *  routine and read/write routines. These are used heavily throughout this 
 *  interface, as SPI is the only communication channel to the transceiver.
 *
 *  ----------------------------------------------------------------------------
 *
 *      Note: The minimal SPI interface required must define the following,
 *
 *        SpiInit(void)
 *          - initialization routine for the SPI interface. Setup peripheral
 *          necessary for SPI communication and ports.
 *        SpiRead(unsigned char address, unsigned char *pBuffer, unsigned char count)
 *          - read from a SPI device; must use a buffer
 *        SpiWrite(unsigned char address, unsigned char *pBuffer, unsigned char count)
 *          - write to a SPI device, must use a buffer
 *
 *      The above routines MUST BE functions as they are required to have an
 *      address associated with them. MACROS WILL NOT WORK.
 *
 *      You may implement wrapper functions around your own SPI interface
 *      to follow the prototypes above. This allows for different SPI parameter
 *      implementations while still abiding by the rules set by the CC1101 
 *      interface. The wrapper would handle converting the CC1101 prototype into
 *      your SPI function prototype by providing the necessary parameters.
 *      
 *      The call procedure would be as follows:
 *      
 *        SpiInitWrapper(void) => SpiInit(...)
 *
 *  ----------------------------------------------------------------------------
 *
 *  For interrupt-driven solutions, a GDOx interface must be provided. Please
 *  see the sCC1101Gdo structure below for more information. The transceiver
 *  supports up to three GDO lines. The operation of each GDO is dependent on
 *  the transceiver's configuration.
 *
 *  ----------------------------------------------------------------------------
 *
 *  Each GDOx interface assumes the following implementation:
 *    
 *    Init()
 *      - initializes the GDOx port and pin. Interrupt capability is
 *      necessary for interrupt-driven solutions.
 *    Event(event)
 *      - returns a boolean value (true or false) determining whether a GDOx
 *      interrupt is pending. This function will be used in a I/O interrupt
 *      service routine to determine if GDOx caused the interrupt.
 *    WaitForAssert()
 *      - changes the polarity of the GDOx pin to wait for an interrupt when the 
 *      pin is asserted.
 *    WaitForDeassert()
 *      - changes the polarity of the GDOx pin to wait for an interrupt when the
 *      pin is deasserted.
 *    State()
 *      - get the current state of the GDOx pin interrupt polarity (assert or
 *      deassert). This is to be used to determine whether the next step is to
 *      WaitForAssert or WaitForDeassert.
 *    Enable(en)
 *      - enables or disables (based on boolean en) the GDOx interrupt.
 *
 *  ----------------------------------------------------------------------------
 *
 *  When device driver debugging is not needed, define "NDEBUG" in your 
 *  compiler's preprocessor options. Error handling can be turned on by defining
 *  "CC1101_ERROR_HANDLING".
 *
 *  The following documents were used during the development of this device
 *  driver:
 *  - CC1101 User's Guide Rev. G (swrs061g)
 *  - CC1101 Errata Notes Rev. B (swrz020b)
 *  - CC110L User's Guide Rev. A (swrs109a)
 *  - CC2500 User's Guide Rev. C (swrs040c)
 *
 *  assumptions
 *  ===========
 *  - when a GDOx line is desired to be used, an interface (set of functions)
 *  will be defined for that GDOx line. Otherwise, the GDOx line will be set
 *  to NULL as it is not needed. When a GDOx line is set to NULL, no GDOx
 *  interface function call shall be made (otherwise there will be undefined
 *  behavior).
 *  - reading of the RSSI hardware register will be averaged to ensure validity.
 *  - target is a CC1101 packetized implementation. This interface defines how
 *  to communicate with a device using packet transmission.
 *  - SPI driver defined/included and attached to CC1101 SPI function pointers
 *  These driver functions MUST follow the CC1101 function prototypes. They must
 *  also perform a check of the MISO pin going low after every CSn assert (this
 *  is device specific). An assert is when the CSn transitions from high to low.
 *  The CC1101 CSn is active low!
 *  - CC1101 device driver is provided a GDOx interface for each GDO to be used
 *  in an interrupt-driven solution.
 *
 *  file dependency
 *  ===============
 *  - stdbool.h defines the datatype "bool" which represents values "true" and
 *  "false"
 *
 *  revision history
 *  ================
 *	ver 1.0.12 : 27 Sep 2012
 *	- split CC1101Init into CC1101SpiInit and CC1101GdoInit. The GDO interface
 *	may not be desired in some circumstances (e.g. test).
 *  ver 1.0.11 : 31 Aug 2012
 *  - added the ability to turn error handling on/off with through a definition
 *  - removed return value from CC1101Wakeup
 *  - added legal header to the top of the file
 *  ver 1.0.10 : 27 Jul 2012
 *  - added critical region wrapper requirement
 *  ver 1.0.09 : 22 Jun 2012
 *  - removed some intelligence from the driver as it doesn't belong here.
 *  ver 1.0.08 : 15 Jun 2012
 *  - user interface comment cleanup and clearification
 *  ver 1.0.07 : 11 Jun 2012
 *  - added hardware register field masks
 *  - added macros to access physical information structure data
 *  ver 1.0.06 : 5 Jun 2012
 *  - created API functions for most CC1101 strobe commands.
 *  - converted single line API functions to macros to reduce function call 
 *  overhead (should increase runtime performance)
 *  - added basic error handling for device driver
 *  - corrected logic in SPI synchronization problem fix and created a separate
 *  function to be used with the registers affected (see CC1101 Errata Notes)
 *  ver 1.0.05 : 1 Jun 2012
 *  - removed receive status information (RSSI, CRC, LQI). 
 *  ver 1.0.04 : 25 May 2012
 *  - added GDOx interface to support the interrupt capability. This makes the
 *  the CC1101 device driver package more complete.
 *  ver 1.0.03 : 07 May 2012
 *  - added interface calibration when selecting manual calibration. Allows user
 *  to set calibration rate (transition between RX/TX and IDLE) before 
 *  performing a manual calibration.
 *  - finished initial comments for CC1101 public interface and structures.
 *  - created a Physical Layer (PHY) structure that contains information
 *  maintained by the CC1101 interface to be used by upper layers.
 *  ver 1.0.02 : 02 May 2012
 *  - cleaned up comments and structure
 *  - added support for storing local and remote Rx information
 *  ver 1.0.01 : 26 Apr 2012
 *  - added support for the CC110L transceiver
 *  ver 1.0.00 : 23 Apr 2012
 *  - initial release
 */
#define CC1101_INFO "CC1101 1.0.12"

#ifndef bool
#define bool unsigned char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

#ifndef NULL
#define NULL  (void*)0
#endif

#ifndef ST
/**
 *  This macro is for use by other macros to form a fully valid C statement.
 *  Without this, the if/else conditionals could show unexpected behavior.
 *
 *  For example, use...
 *    #define SET_REGS()  st( ioreg1 = 0; ioreg2 = 0; )
 *  instead of ...
 *    #define SET_REGS()  { ioreg1 = 0; ioreg2 = 0; }
 *  or
 *    #define  SET_REGS()    ioreg1 = 0; ioreg2 = 0;
 *  The last macro would not behave as expected in the if/else construct.
 *  The second to last macro will cause a compiler error in certain uses
 *  of if/else construct
 *
 *  It is not necessary, or recommended, to use this macro where there is
 *  already a valid C statement.  For example, the following is redundant...
 *    #define CALL_FUNC()   st(  func();  )
 *  This should simply be...
 *    #define CALL_FUNC()   func()
 *
 * (The while condition below evaluates false without generating a
 *  constant-controlling-loop type of warning on most compilers.)
 */
#define ST(X) do { X } while (0)
#endif

#ifndef ABS
#define ABS(a) ((a) < 0 ? -(a) : (a))
#endif

// Supported chip information
#define CC1101                1
#define CC1101_CHIPPARTNUM    0x00u
#define CC1101_CHIPVERSION    0x04u
#define CC110L                2
#define CC110L_CHIPPARTNUM    0x00u
#define CC110L_CHIPVERSION    0x07u
#define CC2500                3
#define CC2500_CHIPPARTNUM    0x80u
#define CC2500_CHIPVERSION    0x03u

// Command strobes
#define CC1101_SRES           0x30u // Reset chip
#define CC1101_SFSTXON        0x31u // Enable and calibrate frequency synthesizer
#define CC1101_SXOFF          0x32u // Turn off crystal oscillator
#define CC1101_SCAL           0x33u // Calibrate frequency synthesizer and turn it off
#define CC1101_SRX            0x34u // Enable rx
#define CC1101_STX            0x35u // In IDLE state: enable TX
#define CC1101_SIDLE          0x36u // Exit RX/TX, turn off frequency synthesizer
// Note: CC1101 datasheet skips register at 0x37u. Use is unavailable.
#define CC1101_SWOR           0x38u // Start automatic RX polling sequence
#define CC1101_SPWD           0x39u // Enter power down mode when CSn goes high
#define CC1101_SFRX           0x3Au // Flush the RX FIFO buffer
#define CC1101_SFTX           0x3Bu // Flush the TX FIFO buffer
#define CC1101_SWORRST        0x3Cu // Reset real time clock to Event1 value
#define CC1101_SNOP           0x3Du // No operation

// Status registers
#define CC1101_PARTNUM        0x30u // Chip ID
#define CC1101_VERSION        0x31u // Chip ID
#define CC1101_FREQEST        0x32u // Frequency offset estimate from demodulator
#define CC1101_LQI            0x33u // Demodulator estimate for link quality
#define CC1101_RSSI           0x34u // Received signal strength indication
#define CC1101_MARCSTATE      0x35u // Main radio control state machine state
#define CC1101_WORTIME1       0x36u // High byte of WOR time
#define CC1101_WORTIME0       0x37u // Low byte of WOR time
#define CC1101_PKTSTATUS      0x38u // Current GDOx status and packet status
#define CC1101_VCO_VC_DAC     0x39u // Current setting from PLL calibration module
#define CC1101_TXBYTES        0x3Au // Underflow and number of bytes
#define CC1101_RXBYTES        0x3Bu // Overflow and number of bytes
#define CC1101_RCCTRL1_STATUS 0x3Cu // Last RC oscillator calibration result
#define CC1101_RCCTRL0_STATUS 0x3Du // Last RC oscillator calibration result

// PA table register
#define CC1101_PATABLE        0x3Eu // RF output power level

// RX/TX FIFO registers
#define CC1101_RXFIFO         0x3Fu // Receive FIFO buffer (read-only)
#define CC1101_TXFIFO         0x3Fu // Transmit FIFO buffer (write-only)

// -----------------------------------------------------------------------------

// Configuration register addresses
/**
 *  Note: For the CC110L, some of the following registers are reserved. Please
 *  see the CC110L Value Line Transceiver User's Guide (swrs109a) for more
 *  information.
 */
#define CC1101_REG_IOCFG2         0x00u // GDO2 Output Pin Configuration
#define CC1101_REG_IOCFG1         0x01u // GDO1 Output Pin Configuration
#define CC1101_REG_IOCFG0         0x02u // GDO0 Output Pin Configuration
#define CC1101_REG_FIFOTHR        0x03u // RX FIFO and TX FIFO Thresholds
#define CC1101_REG_SYNC1          0x04u // Sync Word, High Byte
#define CC1101_REG_SYNC0          0x05u // Sync Word, Low Byte
#define CC1101_REG_PKTLEN         0x06u // Packet Length
#define CC1101_REG_PKTCTRL1       0x07u // Packet Automation Control
#define CC1101_REG_PKTCTRL0       0x08u // Packet Automation Control
#define CC1101_REG_ADDR           0x09u // Device Address
#define CC1101_REG_CHANNR         0x0Au // Channel Number
#define CC1101_REG_FSCTRL1        0x0Bu // Frequency Synthesizer Control
#define CC1101_REG_FSCTRL0        0x0Cu // Frequency Synthesizer Control
#define CC1101_REG_FREQ2          0x0Du // Frequency Control Word, High Byte
#define CC1101_REG_FREQ1          0x0Eu // Frequency Control Word, Middle Byte
#define CC1101_REG_FREQ0          0x0Fu // Frequency Control Word, Low Byte
#define CC1101_REG_MDMCFG4        0x10u // Modem Configuration
#define CC1101_REG_MDMCFG3        0x11u // Modem Configuration
#define CC1101_REG_MDMCFG2        0x12u // Modem Configuration
#define CC1101_REG_MDMCFG1        0x13u // Modem Configuration
#define CC1101_REG_MDMCFG0        0x14u // Modem Configuration
#define CC1101_REG_DEVIATN        0x15u // Modem Deviation Setting
#define CC1101_REG_MCSM2          0x16u // Main Radio Control State Machine Configuration
#define CC1101_REG_MCSM1          0x17u // Main Radio Control State Machine Configuration
#define CC1101_REG_MCSM0          0x18u // Main Radio Control State Machine Configuration
#define CC1101_REG_FOCCFG         0x19u // Frequency Offset Compensation Configuration
#define CC1101_REG_BSCFG          0x1Au // Bit Synchronization Configuration
#define CC1101_REG_AGCCTRL2       0x1Bu // AGC Control
#define CC1101_REG_AGCCTRL1       0x1Cu // AGC Control
#define CC1101_REG_AGCCTRL0       0x1Du // AGC Control
#define CC1101_REG_WOREVT1        0x1Eu // High Byte Event0 Timeout
#define CC1101_REG_WOREVT0        0x1Fu // Low Byte Event0 Timeout
#define CC1101_REG_WORCTRL        0x20u // Wake On Radio Control
#define CC1101_REG_FREND1         0x21u // Front End RX Configuration
#define CC1101_REG_FREND0         0x22u // Front End TX Configuration
#define CC1101_REG_FSCAL3         0x23u // Frequency Synthesizer Calibration
#define CC1101_REG_FSCAL2         0x24u // Frequency Synthesizer Calibration
#define CC1101_REG_FSCAL1         0x25u // Frequency Synthesizer Calibration
#define CC1101_REG_FSCAL0         0x26u // Frequency Synthesizer Calibration
#define CC1101_REG_RCCTRL1        0x27u // RC Oscillator Configuration
#define CC1101_REG_RCCTRL0        0x28u // RC Oscillator Configuration
#define CC1101_REG_FSTEST         0x29u // Frequency Synthesizer Calibration Control
#define CC1101_REG_PTEST          0x2Au // Production Test
#define CC1101_REG_AGCTEST        0x2Bu // AGC Test
#define CC1101_REG_TEST2          0x2Cu // Various Test Settings
#define CC1101_REG_TEST1          0x2Du // Various Test Settings
#define CC1101_REG_TEST0          0x2Eu // Various Test Settings

// -----------------------------------------------------------------------------

// Configuration register field masks
// IOCFG2
#define CC1101_GDO2_INV                   0x40u
#define CC1101_GDO2_CFG                   0x3Fu
// IOCFG1
#define CC1101_GDO1_DS                    0x80u
#define CC1101_GDO1_INV                   0x40u
#define CC1101_GDO1_CFG                   0x3Fu
// IOCFG0
#define CC1101_GDO0_TEMP_SENSOR_ENABLE    0x80u
#define CC1101_GDO0_INV                   0x40u
#define CC1101_GDO0_CFG                   0x3Fu
// FIFOTHR
#define CC1101_ADC_RETENTION              0x40u
#define CC1101_CLOSE_IN_RX                0x30u
#define CC1101_FIFO_THR                   0x0Fu
// SYNC1
#define CC1101_SYNC_MSB                   0xFFu
// SYNC0
#define CC1101_SYNC_LSB                   0xFFu
// PKTLEN
#define CC1101_PACKET_LENGTH              0xFFu
// PKTCTRL1
#define CC1101_PQT                        0xE0u
#define CC1101_CRC_AUTOFLUSH              0x08u
#define CC1101_APPEND_STATUS              0x04u
#define CC1101_ADR_CHK                    0x03u
// PKTCTRL0
#define CC1101_WHITE_DATA                 0x40u
#define CC1101_PKT_FORMAT                 0x30u
#define CC1101_CRC_EN                     0x04u
#define CC1101_LENGTH_CONFIG              0x03u
// ADDR
#define CC1101_DEVICE_ADDR                0xFFu
// CHANNR
#define CC1101_CHANNR_CHAN                0xFFu
// FSCTRL1
#define CC1101_FREQ_IF                    0x1Fu
// FSCTRL0
#define CC1101_FREQOFF                    0xFFu
// FREQ2
#define CC1101_FREQ_23_22                 0xC0u
#define CC1101_FREQ_21_16                 0x3Fu
// FREQ1
#define CC1101_FREQ_15_8                  0xFFu
// FREQ0
#define CC1101_FREQ_7_0                   0xFFu
// MDMCFG4
#define CC1101_CHANBW_E                   0xC0u
#define CC1101_CHANBW_M                   0x30u
#define CC1101_DRATE_E                    0x0Fu
// MDMCFG3
#define CC1101_DRATE_M                    0xFFu
// MDMCFG2
#define CC1101_DEM_DCFILT_OFF             0x80u
#define CC1101_MOD_FORMAT                 0x70u
#define CC1101_MANCHESTER_EN              0x08u
#define CC1101_SYNC_MODE                  0x07u
// MDMCFG1
#define CC1101_FEC_EN                     0x80u
#define CC1101_NUM_PREAMBLE               0x70u
#define CC1101_CHANSPC_E                  0x03u
// MDMCFG0
#define CC1101_CHANSPC_M                  0xFFu
// DEVIATN
#define CC1101_DEVIATION_E                0x70u
#define CC1101_DEVIATION_M                0x07u
// MCSM2
#define CC1101_RX_TIME_RSSI               0x10u
#define CC1101_RX_TIME_QUAL               0x08u
#define CC1101_RX_TIME                    0x07u
// MCSM1
#define CC1101_CCA_MODE                   0x30u
#define CC1101_RXOFF_MODE                 0x0Cu
#define CC1101_TXOFF_MODE                 0x03u
// MCSM0
#define CC1101_FS_AUTOCAL                 0x30u
#define CC1101_PO_TIMEOUT                 0x0Cu
#define CC1101_PIN_CTRL_EN                0x02u
#define CC1101_XOSC_FORCE_ON              0x01u
// FOCCFG
#define CC1101_FOC_BS_CS_GATE             0x20u
#define CC1101_FOC_PRE_K                  0x18u
#define CC1101_FOC_POST_K                 0x04u
#define CC1101_FOC_LIMIT                  0x03u
// BSCFG
#define CC1101_BS_PRE_K                   0xC0u
#define CC1101_BS_PRE_KP                  0x30u
#define CC1101_BS_POST_K                  0x08u
#define CC1101_BS_POST_KP                 0x04u
#define CC1101_BS_LIMIT                   0x03u
// AGCCTRL2
#define CC1101_MAX_DVGA_GAIN              0xC0u
#define CC1101_MAX_LNA_GAIN               0x38u
#define CC1101_MAGN_TARGET                0x07u
// AGCCTRL1
#define CC1101_AGC_LNA_PRIORITY           0x40u
#define CC1101_CARRIER_SENSR_REL_THR      0x30u
#define CC1101_CARRIER_SENSE_ABS_THR      0x0Fu
// AGCCTRL0
#define CC1101_HYST_LEVEL                 0xC0u
#define CC1101_WAIT_TIME                  0x30u
#define CC1101_AGC_FREEZE                 0x0Cu
#define CC1101_FILTER_LENGTH              0x03u
// WOREVT1
#define CC1101_EVENT0_15_8                0xFFu
// WOREVT0
#define CC1101_EVENT0_7_0                 0xFFu
// WORCTRL
#define CC1101_RC_PD                      0x80u
#define CC1101_EVENT1                     0x70u
#define CC1101_RC_CAL                     0x08u
#define CC1101_WOR_RES                    0x03u
// FREND1
#define CC1101_LNA_CURRENT                0xC0u
#define CC1101_LNA2MIX_CURRENT            0x30u
#define CC1101_LODIV_BUF_CURRENT          0x0Cu
#define CC1101_MIX_CURRENT                0x03u
// FREND0
#define CC1101_LODIV_BUF_CURRENT_TX       0x30u
#define CC1101_PA_POWER                   0x07u
// FSCAL3
#define CC1101_FSCAL3_7_6                 0xC0u
#define CC1101_CHP_CURR_CAL_EN            0x30u
#define CC1101_FSCAL3_3_0                 0x0Fu
// FSCAL2
#define CC1101_VCO_CORE_H_EN              0x20u
#define CC1101_FSCAL2_7_0                 0x1Fu
// FSCAL1
#define CC1101_FSCAL1_7_0                 0x3Fu
// FSCAL0
#define CC1101_FSCAL0_7_0                 0x7Fu
// RCCTRL1
#define CC1101_RCCTRL_1                   0x7Fu
// RCCTRL0
#define CC1101_RCCTRL_0                   0x7Fu
// FSTEST
#define CC1101_FSTEST_7_0                 0xFFu
// PTEST
#define CC1101_PTEST_7_0                  0xFFu
// AGCTEST
#define CC1101_AGCTEST_7_0                0xFFu
// TEST2
#define CC1101_TEST2_7_0                  0xFFu
// TEST1
#define CC1101_TEST1_7_0                  0xFFu
// TEST0
#define CC1101_TEST0_7_2                  0xFCu
#define CC1101_VCO_SEL_CAL_EN             0x02u
#define CC1101_TEST0_0                    0x01u

// Status register field masks
// PARTNUM
#define CC1101_PARTNUM_7_0                0xFFu
// VERSION
#define CC1101_VERSION_7_0                0xFFu
// FREQOFF_EST
#define CC1101_FREQOFF_EST                0xFFu
// LQI
#define CC1101_CRC_OK                     0x80u
#define CC1101_LQI_EST                    0x7Fu
// RSSI
#define CC1101_RSSI_7_0                   0xFFu
// MARC_STATE
#define CC1101_MARC_STATE                 0x1Fu
// WORTIME1
#define CC1101_TIME_15_8                  0xFFu
// WORTIME0
#define CC1101_TIME_7_0                   0xFFu
// PKTSTATUS
#define CC1101_PKTSTATUS_CRC_OK           0x80u
#define CC1101_PKSTATUS_CS                0x40u
#define CC1101_PKTSTATUS_PQT_REACHED      0x20u
#define CC1101_PKTSTATUS_CCA              0x10u
#define CC1101_PKSTATUS_SFD               0x08u
#define CC1101_PKTSTATUS_GDO2             0x04u
#define CC1101_PKTSTATUS_GDO0             0x01u
// VCO_VC_DAC
#define CC1101_VCO_VC_DAC_7_0             0xFFu
// TXBYTES
#define CC1101_TXFIFO_UNDERFLOW           0x80u
#define CC1101_NUM_TXBYTES                0x7Fu
// RXBYTES
#define CC1101_RXFIFO_OVERFLOW            0x80u
#define CC1101_NUM_RXBYTES                0x7Fu
// RCCTRL1_STATUS
#define CC1101_RCCTRL1_STATUS_7_0         0xFFu
// RCCTRL0_STATUS
#define CC1101_RCCTRL0_STATUS_7_0         0xFFu

// Burst/single access masks
#define CC1101_WRITE_SINGLE               0x00u
#define CC1101_WRITE_BURST                0x40u
#define CC1101_READ_SINGLE                0x80u
#define CC1101_READ_BURST                 0xC0u

// -----------------------------------------------------------------------------

// Physical FIFO size
#define CC1101_RXFIFO_SIZE        64 // Receive hardware FIFO absolute size
#define CC1101_TXFIFO_SIZE        64 // Transmit hardware FIFO absolute size

// Maximum timeout error ticks
#define CC1101_MAX_TIMEOUT        2000

// -----------------------------------------------------------------------------

/**
 *  eCC1101Error - error codes issued by the device driver.
 */
enum eCC1101Error
{
  eCC1101ErrorTimeout     = 0x01u,
  eCC1101ErrorSleep       = 0x02u
};

/**
 *  eCC1101Chip - device driver supported chipsets.
 */
enum eCC1101Chip
{
  eCC1101ChipUnknown    = 0,
  eCC1101Chip1101       = CC1101,
  eCC1101Chip110L       = CC110L,
  eCC1101Chip2500       = CC2500
};

/**
 *  eCC1101MarcState - all possible MARCSTATEs that the radio state machine can
 *  traverse.
 */
enum eCC1101MarcState
{
  eCC1101MarcStateSleep             = 0x00u,
  eCC1101MarcStateIdle              = 0x01u,
  eCC1101MarcStateXOff              = 0x02u,
  eCC1101MarcStateVcoon_mc          = 0x03u,
  eCC1101MarcStateRegon_mc          = 0x04u,
  eCC1101MarcStateMancal            = 0x05u,
  eCC1101MarcStateVcoon             = 0x06u,
  eCC1101MarcStateRegon             = 0x07u,
  eCC1101MarcStateStartcal          = 0x08u,
  eCC1101MarcStateBwboost           = 0x09u,
  eCC1101MarcStateFs_lock           = 0x0Au,
  eCC1101MarcStateIfadcon           = 0x0Bu,
  eCC1101MarcStateEndcal            = 0x0Cu,
  eCC1101MarcStateRx                = 0x0Du,
  eCC1101MarcStateRx_end            = 0x0Eu,
  eCC1101MarcStateRx_rst            = 0x0Fu,
  eCC1101MarcStateTxrx_switch       = 0x10u,
  eCC1101MarcStateRxfifo_overflow   = 0x11u,
  eCC1101MarcStateFstxon            = 0x12u,
  eCC1101MarcStateTx                = 0x13u,
  eCC1101MarcStateTx_end            = 0x14u,
  eCC1101MarcStateRxtx_switch       = 0x15u,
  eCC1101MarcStateTxfifo_underflow  = 0x16u,
  eCC1101MarcStateUnknown           = 0xFFu
};

/**
 *  eCC1101GdoState - possible states that the GDOx line can be in.
 */
enum eCC1101GdoState
{
  eCC1101GdoStateWaitForAssert    = 0x00u,
  eCC1101GdoStateWaitForDeassert  = 0x01u
};

// -----------------------------------------------------------------------------

/**
 *  sCC1101 - configuration registers for the CC1101. These registers control
 *  the operation of the transceiver chip and are the same for the 110L and 
 *  2500.
 *
 *  Note: The following registers are unavailable in the CC110L, mdmcfg0, 
 *  worevt1, worevt0, worctrl1, rcctrl1, rcctrl0, fstest, ptest, agctest. These
 *  registers should only be written to with their appropriate default values.
 *  Please see the CC110L User's Guide (swrs109a) for more information.
 */
struct sCC1101
{
  unsigned char iocfg2;   // GDO2 output pin configuration
  unsigned char iocfg1;   // GDO1 output pin configuration  
  unsigned char iocfg0;   // GDO0 output pin configuration
  unsigned char fifothr;  // RXFIFO and TXFIFO thresholds
  unsigned char sync1;    // Sync word, high byte
  unsigned char sync0;    // Sync word, low byte
  unsigned char pktlen;   // Packet length
  unsigned char pktctrl1; // Packet automation control
  unsigned char pktctrl0; // Packet automation control
  unsigned char addr;     // Device address
  unsigned char channr;   // Channel number
  unsigned char fsctrl1;  // Frequency synthesizer control
  unsigned char fsctrl0;  // Frequency synthesizer control
  unsigned char freq2;    // Frequency control word, high byte
  unsigned char freq1;    // Frequency control word, middle byte
  unsigned char freq0;    // Frequency control word, low byte
  unsigned char mdmcfg4;  // Modem configuration 4
  unsigned char mdmcfg3;  // Modem configuration 3
  unsigned char mdmcfg2;  // Modem configuration 2
  unsigned char mdmcfg1;  // Modem configuration 1
  unsigned char mdmcfg0;  // Modem configuration 0
  unsigned char deviatn;  // Modem deviation setting
  unsigned char mcsm2;    // Main radio control state machine configuration
  unsigned char mcsm1;    // Main radio control state machine configuration
  unsigned char mcsm0;    // Main radio control state machine configuration
  unsigned char foccfg;   // Frequency offset compensation configuration
  unsigned char bscfg;    // Bit synchronization configuration
  unsigned char agcctrl2; // AGC control 2
  unsigned char agcctrl1; // AGC control 1
  unsigned char agcctrl0; // AGC control 0
  unsigned char worevt1;  // High byte event0 timeout
  unsigned char worevt0;  // Low byte event0 timeout
  unsigned char worctrl;  // Wake on radio control
  unsigned char frend1;   // Front end RX configuration
  unsigned char frend0;   // Front end TX configuration
  unsigned char fscal3;   // Frequency synthesizer calibration
  unsigned char fscal2;   // Frequency synthesizer calibration
  unsigned char fscal1;   // Frequency synthesizer calibration
  unsigned char fscal0;   // Frequency synthesizer calibration
  unsigned char rcctrl1;  // RC oscillator configuration
  unsigned char rcctrl0;  // RC oscillator configuration
  unsigned char fstest;   // Frequency synthesizer calibration control
  unsigned char ptest;    // Production test
  unsigned char agctest;  // AGC test
  unsigned char test2;    // Various test settings 2
  unsigned char test1;    // Various test settings 1
  unsigned char test0;    // Various test settings 0
};

/**
 *  sCC1101Spi - SPI implementation pointers. These function pointers, when
 *  initialized properly, will be pointing to the addresses of your SPI 
 *  interface. This will allow the CC1101 interface to operate correctly.
 *
 *  Note: It is assumed that this structure is defined in static memory. This is
 *  because the CC1101 interface depends on the integrity of the data stored for
 *  all its operations.
 */
struct sCC1101Spi
{
  void(*const Init)(void);
  void(*const Read)(unsigned char, unsigned char*, unsigned char);
  void(*const Write)(unsigned char, const unsigned char*, unsigned char);
};

/**
 *  sCC1101Gdo - GDOx implementation pointers. These function pointers, when
 *  initialized properly, will be pointing to the addresses of your GDOx
 *  interface. This will allow the CC1101 interface to operate correclty.
 *
 *  Note: It is assumed that this structure is defined in static memory. This is
 *  because the CC1101 interface depends on the integrity of the data stored for
 *  all its operations.
 */
struct sCC1101Gdo
{
  void(*const Init)(void);
  bool(*const Event)(volatile const unsigned char);
  void(*const WaitForAssert)(void);
  void(*const WaitForDeassert)(void);
  enum eCC1101GdoState(*const GetState)(void);
  void(*const Enable)(bool);
};

/**
 *  sCC1101PhyInfo - the CC1101 physical device's information. The information
 *  is updated by the CC1101 interface throughout its lifetime of operation. In
 *  order to keep this structure's integrity, it is recommended that the caller
 *  does not change any of the contents in this structure manually. The CC1101
 *  interface provides functions to directly manipulate and see the contents of
 *  this structure.
 *
 *  Note: It is assumed that this structure is defined in static memory. This is
 *  because the CC1101 interface depends on the integrity of the data stored for
 *  all its operations.
 */
struct sCC1101PhyInfo
{
  struct sCC1101Spi *spi;     // Interface for SPI
  struct sCC1101Gdo *gdo[3];  // Interface for GDOx
  volatile bool sleep;        // Chip sleep flag
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// -----------------------------------------------------------------------------
/**
 *  Public Interface
 */

// -----------------------------------------------------------------------------
// Device physical information

/**
 *  CC1101GetSleepState - get the physical information sleep flag that indicates
 *  if the CC1101 is asleep or not. Any SPI operation will cause this flag to be
 *  set to "false" because the radio will wake up on CSn toggling. To ensure
 *  proper configuration of the CC1101, it is very important that the radio is
 *  only woken up by the Wakeup() function.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return bool  Physical information structure's sleep flag state.
 */
#define CC1101GetSleepState(phyInfo) (phyInfo->sleep)


// -----------------------------------------------------------------------------
// Device configuration and status

/**
 *  CC1101SpiInit - calls the initialization routine for a SPI interface. Sets 
 *  hardware registers to initial state dictated by caller provided 
 *  configuration. 
 *
 *    @param  phyInfo       CC1101 interface state information used by the 
 *                          interface for all chip interaction.
 *    @param  spi           CC1101 SPI interface function pointers. This SPI 
 *                          interface is used for all radio configuration and 
 *                          operation.
 *    @param  ErrorHandler  User specified callback function when the CC1101
 *                          driver encounters an error condition. This is only
 *                          issued when "CC1101_ERROR_HANDLING" is defined. 
 */
void CC1101SpiInit(struct sCC1101PhyInfo *phyInfo, 
                   const struct sCC1101Spi *spi,
                   void(*const ErrorHandler)(enum eCC1101Error));

/**
 *  CC1101GdoInit - initialize the General Digital Output (GDOx) interface 
 *  (GDO0, GDO1, GDO2).
 *
 *  Note: If a GDOx interface is not desired (i.e. you are only using GDO0 and
 *  don't need GDO1 or GDO2), NULL can be passed in for each GDOx as an 
 *  argument. That GDOx line will not be initialized and the user should not 
 *  call any of the corresponding GDO functions for that GDOx line.
 *
 *    @param  phyInfo CC1101 interface state information used by the 
 *                    interface for all chip interaction.
 *    @param  gdo     CC1101 GDOx interface function pointers. The GDOx line
 *                    use is dependent on configuration register settings.
 */
void CC1101GdoInit(struct sCC1101PhyInfo *phyInfo, 
                   const struct sCC1101Gdo *gdo[3]);

/**
 *  CC1101Configure - set all hardware configuration registers excluding the PA
 *  table.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  pConfig Radio configuration register settings.
 *
 *    @return Success of the operation.
 */
bool CC1101Configure(struct sCC1101PhyInfo *phyInfo, const struct sCC1101 *config);

/**
 *  CC1101GetRegister - get a configuration register value. This is limited to
 *  registers that use single read access (no PA table as it requires burst read
 *  access).
 *  
 *  Note: This function is provided for completeness. It is recommended that
 *  It is recommended that the specific strobe functions be used as they may 
 *  perform additional operations that are required by the CC1101 User's Guide.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  address Hardware register address to read value from.
 *    
 *    @return Value at the address specified.
 */
unsigned char CC1101GetRegister(struct sCC1101PhyInfo *phyInfo,
                                unsigned char address);

/**
 *  CC1101SetRegister - set a configuration register value. This is limited to
 *  registers that use single write access (no PA table as it requires burst
 *  write access).
 *
 *  Note: This function is provided for completeness. It is recommended that
 *  It is recommended that the specific strobe functions be used as they may 
 *  perform additional operations that are required by the CC1101 User's Guide.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  address Hardware register address to write value to.
 *    @param  value   Value to be written.
 */
void CC1101SetRegister(struct sCC1101PhyInfo *phyInfo, 
                       unsigned char address, 
                       unsigned char value);

/**
 *  CC1101ReadRegisters - read from hardware registers. This function allows for
 *  burst reads. A burst read will read from contiguous hardware registers. 
 *  Pointers are updated automatically in hardware. The read data is written to 
 *  the supplied buffer.
 *
 *  Note: This function is provided for completeness. It is recommended that
 *  It is recommended that the specific strobe functions be used as they may 
 *  perform additional operations that are required by the CC1101 User's Guide.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *            for all chip interaction.
 *    @param  address Hardware register address to read a value from or the 
 *                    start address for reading multiple values.
 *    @param  buffer  Buffer to store the values read from the CC1101.
 *    @param  count   Number of bytes to read. This number should not exceed 
 *                    the size of the buffer provided or an overflow can occur.
 */
void CC1101ReadRegisters(struct sCC1101PhyInfo *phyInfo,
                         unsigned char address,
                         unsigned char *buffer,
                         unsigned char count);

/**
 *  CC1101WriteRegisters - write to hardware registers. This function allows for
 *  burst writes. A burst write will write to contiguous hardware registers.
 *  Pointers are updated automatically in hardware.
 *
 *  Note: This function is provided for completeness. It is recommended that
 *  It is recommended that the specific strobe functions be used as they may 
 *  perform additional operations that are required by the CC1101 User's Guide.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *            for all chip interaction.
 *    @param  address Hardware register address to write a value to or the start
 *                    address of writting multiple values.
 *    @param  buffer  Buffer storing values to write to the CC1101.
 *    @param  count   Number of bytes to write. This number should not exceed 
 *                    the size of the buffer provided or an overflow can occur.
 */
void CC1101WriteRegisters(struct sCC1101PhyInfo *phyInfo,
                          unsigned char address,
                          unsigned char *buffer,
                          unsigned char count);

/**
 *  CC1101GetChip - get the current chip that the SPI interface is communicating
 *  with.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *
 *    @return Chip connected to the current active SPI interface.
 */
enum eCC1101Chip CC1101GetChip(struct sCC1101PhyInfo *phyInfo);

/**
 *  CC1101ReadRxFifo - read data from the receive hardware FIFO. Any newly
 *  received data will be added to the RX FIFO. A read or flush is required to 
 *  clear data from the RX FIFO.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  buffer  Buffer to store the values read from the RX FIFO. Number
 *                    of bytes read is dependent on the count.
 *    @param  count   Number of bytes to read from the RX FIFO. If there are
 *                    less bytes available than desired, fill the buffer until
 *                    no more data exists in the RX FIFO.
 *
 *    @return Number of bytes read from the RX FIFO. This value may be different
 *            from the number desired if there wasn't enough bytes in the FIFO
 *            to fulfill the request.
 */
unsigned char CC1101ReadRxFifo(struct sCC1101PhyInfo *phyInfo, 
                               unsigned char *buffer, 
                               unsigned char count);

/**
 *  CC1101WriteTxFifo - write data to the transmit hardware FIFO. If data
 *  already exists in the FIFO, this data will be appended to it. A flush is
 *  required to clear all the data from the TX FIFO.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  buffer  Buffer with values to write to the TX FIFO.
 *    @param  count   Number of bytes to write from the buffer into the TX FIFO.
 */
void CC1101WriteTxFifo(struct sCC1101PhyInfo *phyInfo, 
                       unsigned char *buffer, 
                       unsigned char count);

/**
 *  CC1101GetRxFifoCount - get the number of bytes available in the RX FIFO.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return unsigned char   Number of bytes available in the RX FIFO.
 */
#define CC1101GetRxFifoCount(phyInfo)\
  CC1101GetRegister(phyInfo, CC1101_RXBYTES)

/**
 *  CC1101GetTxFifoCount - get the number of bytes available in the TX FIFO.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return unsigned char   Number of bytes in the TX FIFO.
 */
#define CC1101GetTxFifoCount(phyInfo)\
  CC1101GetRegister(phyInfo, CC1101_TXBYTES)

/**
 *  CC1101GetMarcState - get the radio state machine's current state.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return enum eCC1101MarcState   The last MARCSTATE read from the CC1101.
 */
#define CC1101GetMarcState(phyInfo)\
  (enum eCC1101MarcState)CC1101GetRegister(phyInfo, CC1101_MARCSTATE)

/**
 *  CC1101GetRssi - get the receive signal strength indicator (RSSI) value.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *  
 *    @return unsigned char   Last RSSI sample value obtained.
 */
#define CC1101GetRssi(phyInfo)\
  CC1101GetRegister(phyInfo, CC1101_RSSI)

/**
 *  CC1101GetLqi - get the link quality indicator (LQI) value for the last RX 
 *  state.
 *
 *  Note: The following provides some information about an LQI reading (courtesy 
 *  of Jim Noxon from TI E2E Community http://e2e.ti.com). The specific article 
 *  is found here, http://e2e.ti.com/support/low_power_rf/f/155/t/127875.aspx.
 *
 *  LQI can be interpreted using the following,
 *  --------------------------------------------------------------------------
 *  1. low signal means low RSSI and low signal means low SNR so LQI gets 
 *  worse (higher).
 *  2. low signal means low RSSI and low with no noise means higher SNR so LQI
 *  is good (lower).
 *  3. high noise means high RSSI as RSSI measures RF energy only, not 
 *  necessarily a signal you want, no noise but invalid signaling means poor 
 *  LQI (high value).
 *  4. strong signal means high RSSI and strong signal means higher SNR so LQI
 *  is good (lower).
 *  5. very strong signal causing receiver to saturate means high RSSI but due
 *  to saturation demodulation is poor so LQI is poor as well (higher).
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return unsigned char   Last LQI value obtained.
 */
#define CC1101GetLqi(phyInfo)\
  ((CC1101GetRegister(phyInfo, CC1101_LQI)) & CC1101_LQI_EST)

/**
 *  CC1101GetCrc - get the cyclic redundancy check (CRC) OK value from the last 
 *  RX state.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return unsigned char   Last CRC OK bit value obtained.
 */
#define CC1101GetCrc(phyInfo)\
  ((CC1101GetRegister(phyInfo, CC1101_LQI)) & CC1101_CRC_OK)

// -----------------------------------------------------------------------------
// Device state control

/**
 *  CC1101Strobe - perform a strobe to the radio. A strobe is a special command
 *  that writes a single address and no SPI data.
 *
 *  Note: This function is provided for completeness. It is recommended that
 *  It is recommended that the specific strobe functions be used as they may 
 *  perform additional operations that are required by the CC1101 User's Guide.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *
 *    @param  command CC1101 strobe command to be executed.
 */
void CC1101Strobe(struct sCC1101PhyInfo *phyInfo, unsigned char command);

/**
 *  CC1101Reset - software reset of the CC1101. It is assumed that the radio has
 *  been in an IDLE state before calling.
 *
 *  Note: It is assumed that the device is currently being powered and that the
 *  reset is occurring a significant time after the power supply is stable. If 
 *  not, a separate hardware reset procedure is required to put the CC1101 into 
 *  an initial IDLE state. Please see the CC1101 User's Guide Section 19.1.2 
 *  (swrs061g) for more information.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101Reset(phyInfo)  CC1101Strobe(phyInfo, CC1101_SRES)

/**
 *  CC1101EnableFrequencySynthesizer - enable and calibrate the frequency 
 *  synthesizer.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101EnableFrequencySynthesizer(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_SFSTXON)

/**
 *  CC1101TurnOffCrystalOscillator - turn off the crystal oscillator (XOSC).
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
bool CC1101TurnOffCrystalOscillator(struct sCC1101PhyInfo *phyInfo);

/**
 *  CC1101Calibrate - perform a manual calibration of the radio.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 *
 *    @return Success of the operation.
 */
bool CC1101Calibrate(struct sCC1101PhyInfo *phyInfo);

/**
 *  CC1101ReceiverOn - turn on the radio receiver.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101ReceiverOn(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_SRX);

/**
 *  CC1101Transmit - turn on the radio transmitter. Transmit the data that
 *  resides in the TX FIFO.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101Transmit(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_STX);

/**
 *  CC1101Idle - put the radio into an idle state.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101Idle(phyInfo) CC1101Strobe(phyInfo, CC1101_SIDLE)

/**
 *  CC1101StartWakeOnRadio - start automatic RX polling sequence (wake-on radio)
 *  operation. The period and duty cycle is dictated by your configuration.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101StartWakeOnRadio(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_SWOR)

/**
 *  CC1101FlushRxFifo - clear all data from the receive hardware FIFO.
 *
 *  Note: Buffer flush can only be done in IDLE, TXFIFO_UNDERFLOW, or 
 *  RXFIFO_OVERFLOW states. Strobe the radio to an IDLE state prior to flushing 
 *  the FIFOs. For more information, please see Section 10.5 - "FIFO Access" in
 *  the CC1101 User's Guide.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101FlushRxFifo(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_SFRX)
  
/**
 *  CC1101FlushTxFifo - clear all data from the transmit hardware FIFO.
 *
 *  Note: Buffer flush can only be done in IDLE, TXFIFO_UNDERFLOW, or 
 *  RXFIFO_OVERFLOW states. Strobe the radio to an IDLE state prior to flushing 
 *  the FIFOs. For more information, please see Section 10.5 - "FIFO Access" in
 *  the CC1101 User's Guide.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101FlushTxFifo(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_SFTX)

/**
 *  CC1101Sleep - put the CC1101 into a low power state.
 *
 *  Note: This function should be used in conjunction with CC1101Wakeup ONLY.
 *  Any CSn toggling will wake up the CC1101. To prevent this from occurring
 *  accidentally, the driver prevents any SPI read/write operation when asleep 
 *  until the wake up routine has been issued.
 *
 *  Note: This routine should be placed in a critical section. The operation 
 *  should be considered ATOMIC.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *
 *    @return Success of the operation.
 */
bool CC1101Sleep(struct sCC1101PhyInfo *phyInfo);

/**
 *  CC1101Wakeup - bring the CC1101 out of a low power state into idle.
 *
 *  Note: This function should be used in conjunction with CC1101Sleep ONLY.
 *  Any CSn toggling will wake up the CC1101. To prevent this from occurring
 *  accidentally, the driver prevents any SPI read/write operation when asleep 
 *  until the wake up routine has been issued.
 *
 *  Note: This routine should be placed in a critical section. The operation 
 *  should be considered ATOMIC.
 *  
 *    @param  phyInfo     CC1101 interface state information used by the 
 *                        interface for all chip interaction.
 *    @param  agctest     AGCTEST register value.
 *    @param  test[2:0]   TEST2, TEST1, and TEST0 register values.
 *    @param  paTable     Current power settings to be used when waking up. The 
 *                        radio DOES NOT RETAIN PA table settings in SLEEP.
 *    @param  paTableSize Size of the PA table. Dependent on the chip. The 
 *                        CC1101/CC2500 PA table is size 8 bytes while the 
 *                        CC110L is 2 bytes.
 */
void CC1101Wakeup(struct sCC1101PhyInfo *phyInfo, 
                  const unsigned char agctest,
                  const unsigned char test[3],
                  const unsigned char *paTable,
                  unsigned char paTableSize);

/**
 *  CC1101ResetWakeOnRadio - reset real time clock to Event1 value for wake-on
 *  radio operation.
 *
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101ResetWakeOnRadio(phyInfo)\
  CC1101Strobe(phyInfo, CC1101_SWORRST)

/**
 *  CC1101Nop - perform a radio no operation command.
 *    
 *    @param  struct sCC1101PhyInfo*  phyInfo CC1101 interface state information 
 *                                            used by the interface for all chip 
 *                                            interaction.
 */
#define CC1101Nop(phyInfo)  CC1101Strobe(phyInfo, CC1101_SNOP)

// -----------------------------------------------------------------------------
// Device interrupt

/**
 *  CC1101GdoEvent - check if a GDOx event has occurred. This should be used in
 *  an I/O interrupt service routine to determine if a GDOx interrupt is pending
 *  for service.
 *
 *  Note: This function does not perform any error checking. If the gdo passed
 *  in does not exist (is NULL), undefined behavior can occur.
 *
 *    @param  gdo   GDOx pin interface. The pin looking for an event to occur.
 *    @param  event Event that has triggered an interrupt. This is used as a
 *                  mask to check if the GDOx pin has been interrupted.
 *
 *    @return true if a GDOx event has occurred; false otherwise.
 */
#define CC1101GdoEvent(gdo, event) (gdo->Event(event))

/**
 *  CC1101GdoWaitForAssert - change the polarity of the GDOx pin to look for a
 *  assertion.
 *
 *  Note: This function does not perform any error checking. If the gdo passed
 *  in does not exist (is NULL), undefined behavior can occur.
 *
 *    @param  gdo   GDOx pin interface. The pin waiting for an assertion.
 */
#define CC1101GdoWaitForAssert(gdo) gdo->WaitForAssert()

/**
 *  CC1101GdoWaitForDeassert - change polarity of the GDOx pin to look for a
 *  deassertion.
 *
 *  Note: This function does not perform any error checking. If the gdo passed
 *  in does not exist (is NULL), undefined behavior can occur.
 *
 *    @param  gdo   GDOx pin interface. The pin waiting for a deassertion.
 */
#define CC1101GdoWaitForDeassert(gdo) gdo->WaitForDeassert()

/**
 *  CC1101GdoEnable - enable the GDOx interrupt.
 *
 *  Note: This function does not perform any error checking. If the gdo passed
 *  in does not exist (is NULL), undefined behavior can occur.
 *
 *    @param  gdo   GDOx pin interface. The pin interrupt to be enabled.
 */
#define CC1101GdoEnable(gdo)  gdo->Enable(true)

/**
 *  CC1101GdoDisable - disable the GDOx interrupt.
 *
 *  Note: This function does not perform any error checking. If the gdo passed
 *  in does not exist (is NULL), undefined behavior can occur.
 *
 *    @param  gdo   GDOx pin interface. The pin interrupt to be disabled.
 */
#define CC1101GdoDisable(gdo) gdo->Enable(false)

/**
 *  CC1101GdoGetState - get the current state of the GDOx pin. State refers to 
 *  the polarity of the pin (asserted or deasserted).
 *
 *  Note: This function does not perform any error checking. If the gdo passed
 *  in does not exist (is NULL), undefined behavior can occur.
 *
 *    @param  gdo   GDOx pin interface. The pin that state is desired for.
 *
 *    @return WaitForAssert when the polarity of the GDOx pin is configured for
 *            an assert; WaitForDeassert when the polarity of the GDOx pin is
 *            configured for a deassert.
 */
#define CC1101GdoGetState(gdo)  (gdo->GetState())

#endif  /* CC1101_H */
