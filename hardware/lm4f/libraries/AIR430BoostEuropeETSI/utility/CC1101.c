/**
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2012-13, Anaren Microwave, Inc.
 *
 *  For more information on licensing, please see Anaren Microwave, Inc's
 *  end user software licensing agreement: EULA.txt.
 *
 *  ----------------------------------------------------------------------------
 *
 *  CC1101.c - CC110x/2500 device driver.
 *
 *  @version    1.0.13
 *  @date       15 Jan 2013
 *  @author     BPB, air@anaren.com
 *
 *  For details on the interface, please see CC1101.h.
 *
 *  assumptions
 *  ===========
 *  Same as CC1101.h assumptions
 *
 *  file dependency
 *  ===============
 *  CC1101.h : provides interface function prototypes and global definitions
 *  assert.h : when debugging, assert is used to indicate device driver error
 *  conditions
 *
 *  revision history
 *  ================
 *  ver 1.0.13 : 15 Jan 2013
 *	- fixed an issue with the sleep flag so that it may be cleared prior to
 *	attempting to write the unretained registers in the wake up routine.
 *	- updated the SpiRead and SpiWrite routines to remove useless comparisons
 *	- updated helper function GetRegisterWithSpiSyncProblem to simplify the
 *	method for comparing state values
 *	ver 1.0.12 : 27 Sep 2012
 *	- split CC1101Init into CC1101SpiInit and CC1101GdoInit. The GDO interface
 *	may not be desired in some circumstances (e.g. test).
 *  ver 1.0.11 : 31 Aug 2012
 *  - fixed issue with sleep flag. Implemented a mechanism for forcing the
 *  application to call CC1101Wakeup if they called CC1101Sleep before any other
 *  SPI operation can be performed using this driver.
 *  - no longer force error handling to exist at all times; it is only included
 *  when desired.
 *  - removed the return statement from CC1101Wakeup. The current implementation
 *  will always perform the wake up sequence.
 *  - added legal header to the top of the file
 *  ver 1.0.10 : 27 Jul 2012
 *  - fixed issue with CC1101Sleep sleep flag. Strobe is now issued prior to
 *  setting the flag.
 *  - added critical region wrapper call to protect the sleep atomic operation
 *  ver 1.0.09 : 22 Jun 2012
 *  - same as CC1101.h
 *  ver 1.0.08 : 15 Jun 2012
 *  - same as CC1101.h
 *  ver 1.0.07 : 11 Jun 2012
 *  - fixed sleep flag; sleep flag is set to "false" everytime a SPI operation
 *  occurs. This is because the radio is woken up by a CSn state toggle. To
 *  ensure correct state (assuming the user uses this driver for all
 *  communication with the CC1101) this operation is necessary. Sleep() is the
 *  only location where the flag is set to "true".
 *  ver 1.0.06 : 5 Jun 2012
 *  - added support for error handling at a device driver level
 *  - added comments to private interface functions
 *  - removed small API functions and made them macros (included in the header
 *  file)
 *  - removed config and paTable members from the CC1101 physical information
 *  structure. This information should be controlled by other logic.
 *  ver 1.0.05 : 1 Jun 2012
 *  - removed receive status information (RSSI, CRC, LQI). 
 *  - cleaned up GetRxFifo and SetTxFifo functions to perform the bare hardware
 *  minimum.
 *  ver 1.0.04 : 25 May 2012
 *  - added initialization of the GDOx interface.
 *  ver 1.0.03 : 07 May 2012
 *  - added implementation of interface calibration.
 *  - finished initial comments for CC1101 private interface.
 *  - removed static global variables and replaced them with the Physical Layer
 *  (PHY) structure. Interface will support multiple radios much easier now.
 *  ver 1.0.02 : 02 May 2012
 *  - cleaned up comments and structure
 *  - added support for storing local and remote Rx information
 *  ver 1.0.01 : 26 Apr 2012
 *  - added support for the CC110L transceiver
 *  ver 1.0.00 : 23 Apr 2012
 *  - initial release
 */
#include "CC1101.h"
//#ifndef NDEBUG
//#include <assert.h>
//#endif

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

/**
 *  CC1101ErrorHandler - function pointer used to dictate what function to call
 *  when a device driver error occurs. If no handler is specified by the user,
 *  the device driver uses a default error handler.
 */
#ifdef CC1101_ERROR_HANDLING
static void(*CC1101ErrorHandler)(enum eCC1101Error) = NULL;
#endif

// -----------------------------------------------------------------------------
/**
 *  Private interface
 */

/**
 *  CC1101Read - read from the internal radio registers. Values returned from 
 *  the CC1101x/2500 device are written into the provided buffer based on
 *  the read count. Read and burst bits handled automatically. Any address that 
 *  is in the range of 0x30 to 0x3D will be interpretted as a status register 
 *  (strobe commands can not be read from). 
 *
 *  Note: Status and strobe commands share the same address space but are 
 *  differentiated by a burst bit.
 *
 *  Note: If the CC1101 is asleep, it can only be woken up by the CC1101Wakeup
 *  routine. If this is not used to wake up the chip, all read and write
 *  operations will be blocked.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  address The radio register address to start reading from.
 *    @param  buffer  A buffer used for storing values read from the CC1101. It 
 *                    is dependent on count.
 *    @param  count   Number of bytes to read from the hardware registers. For 
 *                    the CC110x/2500, this corresponds with the number of 
 *                    registers to read since each is a single byte in size.
 */
void CC1101Read(struct sCC1101PhyInfo *phyInfo, 
                unsigned char address, 
                unsigned char *buffer, 
                unsigned char count)
{
  if (!phyInfo->sleep)
  {
    // Check if this is a status register read. If so, the burst bit must be set
    // to distinguish between a strobe command and a status register address.
    if (address > 0x2F && address < 0x3E)
    {
      address |= CC1101_READ_BURST;
    }
    else
    {
      // Format command (R/W, Burst/Single, Address[5:0]).
      address = address | CC1101_READ_SINGLE;
      if (count > 1)
      {
        address = address | CC1101_READ_BURST;
      }
    }
  
    phyInfo->spi->Read(address, buffer, count);
  }
  #ifdef CC1101_ERROR_HANDLING
  else
  {
    /**
     *  If the chip was not asleep prior to this call, invoke the error handler.
     *  An unwanted sequence of steps in the application may exist causing a SPI
     *  operation to wake up the chip before desired.
     */
    CC1101ErrorHandler(eCC1101ErrorSleep);
  }
  #endif
}

/**
 *  CC1101Write - write to the internal radio registers. Read and burst bits
 *  handled automatically. Any address that is in the range of 0x30 to 0x3D
 *  will be interpretted as a strobe (status registers cannot be written to). It
 *  is assumed that the CC1101Strobe(...) function will be used for strobe
 *  commands explicitly.
 *
 *  Note: Status and strobe commands share the same address space but are 
 *  differentiated by a burst bit.
 *
 *  Note: If the CC1101 is asleep, it can only be woken up by the CC1101Wakeup
 *  routine. If this is not used to wake up the chip, all read and write
 *  operations will be blocked.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  address The radio register address to start writing to.
 *    @param  buffer  A buffer that contains values to be written to the CC1101. 
 *                    It is dependent on count.
 *    @param  count   Number of bytes to write to the hardware registers. For 
 *                    the CC110x/2500, this corresponds with the number of 
 *                    registers to write since each is a single byte in size.
 */
void CC1101Write(struct sCC1101PhyInfo *phyInfo, 
                unsigned char address, 
                const unsigned char *buffer, 
                unsigned char count)
{
  if (!phyInfo->sleep)
  {
    // Format command (R/W, Burst/Single, Address[5:0]).
    if (count > 1)
    {
      address = address | CC1101_WRITE_BURST;
    }
    
    phyInfo->spi->Write(address, buffer, count);
  }
  #ifdef CC1101_ERROR_HANDLING
  else
  {
    /**
     *  If the chip was not asleep prior to this call, invoke the error handler.
     *  An unwanted sequence of steps in the application may exist causing a SPI
     *  operation to wake up the chip before desired.
     */
    CC1101ErrorHandler(eCC1101ErrorSleep);
  }
  #endif
}

/**
 *  CC1101GetChipPartnum - get the hardware part number.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *
 *    @return unsigned char   The part number flashed into the chip.
 */
#define CC1101GetChipPartnum(phyInfo)\
  CC1101GetRegister(phyInfo, CC1101_PARTNUM)

/**
 *  CC1101GetChipVersion - get the hardware part version number.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *
 *    @return unsigned char   The part version flashed into the chip.
 */
#define CC1101GetChipVersion(phyInfo)\
  CC1101GetRegister(phyInfo, CC1101_VERSION)

/**
 *  CC1101GetRegisterWithSpiSyncProblem - get register value that is affected by
 *  the SPI synchronization issue. The register may be read up to four times,
 *  but is considered valid once two reads in a row yield the same result.
 *
 *  Note: There is a known bug affecting the synchronization mechanism 
 *  between the SPI clock domain and the internal 26 MHz clock domain where
 *  there may be incorrect read values for register fields that are
 *  continuously updated. This issue affects the following registers: SPI
 *  status byte (fields STATE and FIFO_BYTES_AVAILABLE), FREQEST or RSSI
 *  while the receiver is active, MARCSTATE at any time other than an IDLE
 *  radio state, RXBYTES when receiving or TXBYTES when transmitting, and
 *  WORTIME1/WORTIME0 at any time. For more information about this bug
 *  please see the Section 3 - "SPI Read Synchronization Issue" in the 
 *  CC1101 Errata Notes (swrz020b).
 *
 *  The workaround suggested by the Errata Notes is so read the register up
 *  to four times while comparing the last two reads with one another. Once 
 *  there is a match, you have read a valid value.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  address Address of register to read value from.
 *
 *    @return Valid value from register affected by SPI synchronization issue.
 */
unsigned char CC1101GetRegisterWithSpiSyncProblem(struct sCC1101PhyInfo *phyInfo, 
                                                  unsigned char address)
{
	unsigned char i;
	unsigned char state[4];
	
	for (i = 0; i < 4; i++)
	{
    CC1101Read(phyInfo, address, (unsigned char*)&state[i], 1);
    // If two consecutive reads yield the same result, then we are guaranteed
    // that the value is valid; no need to continue further...
    if ((i > 0) && (state[i] == state[i-1]))
		{
			break;
		}
	}

	return state[i];
}

/**
 *  CC1101DefaultErrorHandler - default error handler for the CC1101 device
 *  driver. When the user doesn't supply their own callback, this handler is
 *  used.
 *
 *    @param  error   Error code for the error that occurred. This can be used
 *                    for determining course of action.
 */
void CC1101DefaultErrorHandler(enum eCC1101Error error)
{
  #if (!defined(NDEBUG) && defined(DEBUG_VERBOSE))
  char *msg;
  switch (error)
  {
    case eCC1101ErrorChipUnknown:
      msg = "CC1101 Error: chip not supported";
      break;
    case eCC1101ErrorTimeout:
      msg = "CC1101 Error: timeout occurred";
      break;
    case eCC1101ErrorSleep:
      msg = "CC1101 Error: sleep-wakeup sequence incorrect";
      break;
    default:
      msg = "CC1101 Error: unknown";
      break;
  }
  assert(msg);
  #elif (!defined(NDEBUG) && defined(DEBUG_NONVERBOSE))
  unsigned int msg;
  switch (error)
  {
    case eCC1101ErrorChipUnknown:
      msg = eCC1101ErrorChipUnknown;
    case eCC1101ErrorTimeout:
      msg = eCC1101ErrorTimeout;
    case eCC1101ErrorSleep:
      msg = eCC1101ErrorSleep;
      break;
    default:
      break;
  }
  assert(msg);
  #endif
}

/**
 *  CC1101TimeoutEvent - check for timeout event. An incrementing tick must be
 *  supplied. When the tick exceeds the MAX_TIMEOUT value, a timeout event has
 *  occurred.
 *
 *    @param  tick  Amount of time passed waiting for an event to occur.
 *
 *    @return Status of a timeout event occurring.
 */
bool CC1101TimeoutEvent(unsigned int *tick)
{
  if (*tick < CC1101_MAX_TIMEOUT)
  {
    (*tick)++;
    return false;
  }
  
  return true;
}

/**
 *  CC1101SetAndVerifyState - strobe the CC1101 to go to a certain state. Verify 
 *  that the new state matches what was desired.
 *
 *  Note: The strobe command and verfication marc state should match. If they
 *  do not, this function is guaranteed to fail.
 *
 *    @param  phyInfo CC1101 interface state information used by the interface
 *                    for all chip interaction.
 *    @param  command Command strobe that will be issued to the radio and 
 *                    verified.
 *    @param  state   Command's associated state (e.g. if the command was to go
 *                    into an IDLE state, then eCC1101MarcStateIdle is the 
 *                    desired state).
 *
 *    @return Success of the operation.
 */
bool CC1101SetAndVerifyState(struct sCC1101PhyInfo *phyInfo,
                             unsigned char command, 
                             enum eCC1101MarcState state)
{
  unsigned int tick = 0;
  
  CC1101Strobe(phyInfo, command);
  while (CC1101GetMarcState(phyInfo) != state)
  {
    if (CC1101TimeoutEvent(&tick))
    {
      #ifdef CC1101_ERROR_HANDLING
      CC1101ErrorHandler(eCC1101ErrorTimeout);
      #endif
			// TODO: Add a reset-radio routine. Some of the operational states may
			// cause a irreversable state.
      return false;
    }
  }
  
  return true;
}

// -----------------------------------------------------------------------------
/**
 *  Public interface
 */

// -----------------------------------------------------------------------------
// Device configuration and status

void CC1101SpiInit(struct sCC1101PhyInfo *phyInfo, 
                   const struct sCC1101Spi *spi,
                   void(*const ErrorHandler)(enum eCC1101Error))
{
  phyInfo->sleep = false;
  
  // Attach error handler to be used by this device driver.
  #ifdef CC1101_ERROR_HANDLING
  if (ErrorHandler != NULL)
  {
    CC1101ErrorHandler = ErrorHandler;
  }  
  else
  {
    CC1101ErrorHandler = CC1101DefaultErrorHandler;
  }
  #endif
  
  phyInfo->spi = (struct sCC1101Spi*)spi;
  
  // Setup required Serial Peripheral Interface (SPI).
  phyInfo->spi->Init();
}

void CC1101GdoInit(struct sCC1101PhyInfo *phyInfo, 
                   const struct sCC1101Gdo *gdo[3])
{
  // Setup the GDOx lines.
  /**
   *  If a user does not desire to use the GDOx interface, they may set it to 
   *  NULL. If they set it to NULL, do not initialize anything. Otherwise, setup
   *  only the GDOx lines that are of a non-NULL value.
   */
  if (gdo != NULL)
  {
    unsigned char i;      // GDOx initialization iterator
    
    // Only allocate iterator if GDOx interface is being used.
    for (i = 0; i < 3; i++)
    {
      if (gdo[i] != NULL)
      {
        /**
         *  Initialize each non-NULL GDOx line. It is assumed that the user will
         *  set the GDOx interface pointer to NULL if that GDOx line is not 
         *  desired.
         */
        phyInfo->gdo[i] = (struct sCC1101Gdo*)gdo[i];
        phyInfo->gdo[i]->Init();
      }
    }
  }
}

bool CC1101Configure(struct sCC1101PhyInfo *phyInfo, const struct sCC1101 *config)
{
  /**
   *  Make sure the radio is in an IDLE state before attempting to configure any
   *  packet handling registers. See Table 28 in the CC1101 User's Guide for 
   *  more information (swrs061g).
   */
  if (!CC1101SetAndVerifyState(phyInfo, CC1101_SIDLE, eCC1101MarcStateIdle))
  {
    return false;
  }
  
  CC1101Write(phyInfo,
              0x00, 
              (unsigned char *)((struct sCC1101*)config), 
              sizeof(struct sCC1101)/sizeof(unsigned char));
  
  return true;
}

unsigned char CC1101GetRegister(struct sCC1101PhyInfo *phyInfo,
                                unsigned char address)
{
  switch (address)
  {
    /**
     *  Note: In order to allow for efficient continuous reading of the RSSI 
     *  value, the CC1101_RSSI case has been commented out. RSSI is not 
     *  protected by the fix for the Errata Notes issue. A fix must be performed 
     *  outside of this device driver (such as averaging).
     */
//    case CC1101_RSSI:
    case CC1101_FREQEST:
    case CC1101_MARCSTATE:
    case CC1101_RXBYTES:
    case CC1101_TXBYTES:
    case CC1101_WORTIME1:
    case CC1101_WORTIME0:
      return CC1101GetRegisterWithSpiSyncProblem(phyInfo, address);
    default:
      {
        unsigned char value;
        CC1101Read(phyInfo, address, &value, 1);
        return value;
      }
  }
}

void CC1101SetRegister(struct sCC1101PhyInfo *phyInfo, 
                       unsigned char address, 
                       unsigned char value)
{
  CC1101Write(phyInfo, address, &value, 1);
}

void CC1101ReadRegisters(struct sCC1101PhyInfo *phyInfo,
                         unsigned char address,
                         unsigned char *buffer,
                         unsigned char count)
{
  if (count == 1)
  {
    *buffer = CC1101GetRegister(phyInfo, address);
  }
  else if (count > 1)
  {
    CC1101Read(phyInfo, address, buffer, count);
  }
}

void CC1101WriteRegisters(struct sCC1101PhyInfo *phyInfo,
                          unsigned char address,
                          unsigned char *buffer,
                          unsigned char count)
{
  CC1101Write(phyInfo, address, buffer, count);
}

enum eCC1101Chip CC1101GetChip(struct sCC1101PhyInfo *phyInfo)
{
  volatile unsigned char partNum = CC1101GetChipPartnum(phyInfo);
  volatile unsigned char version = CC1101GetChipVersion(phyInfo) & 0xf;
  
  
  if (partNum == CC1101_CHIPPARTNUM && version == CC1101_CHIPVERSION)
    return eCC1101Chip1101;
  else if (partNum == CC2500_CHIPPARTNUM && version == CC2500_CHIPVERSION)
    return eCC1101Chip2500;
  else if (partNum == CC110L_CHIPPARTNUM && version == CC110L_CHIPVERSION)
    return eCC1101Chip110L;
  else
    return eCC1101ChipUnknown;
}

unsigned char CC1101ReadRxFifo(struct sCC1101PhyInfo *phyInfo, 
                               unsigned char *buffer, 
                               unsigned char count)
{
  volatile unsigned char rxBytes = CC1101GetRxFifoCount(phyInfo);

  if (rxBytes < count)
  {
    CC1101Read(phyInfo, CC1101_RXFIFO, buffer, rxBytes);
    return rxBytes;
  }
  else
  {
    CC1101Read(phyInfo, CC1101_RXFIFO, buffer, count);
    return count;
  }
}

void CC1101WriteTxFifo(struct sCC1101PhyInfo *phyInfo,
                       unsigned char *buffer,
                       unsigned char count)
{
  CC1101Write(phyInfo, CC1101_TXFIFO, buffer, count);
}

// -----------------------------------------------------------------------------
// Device state control

void CC1101Strobe(struct sCC1101PhyInfo *phyInfo, unsigned char command)
{
  CC1101Write(phyInfo, (command & 0xBF), NULL, 0);
}

bool CC1101TurnOffCrystalOscillator(struct sCC1101PhyInfo *phyInfo)
{
  // CC1101 must be in an IDLE state before powering down. Please see section
  // 19.2 - "Crystal Control" for more inforamtion.
  if (!CC1101SetAndVerifyState(phyInfo, CC1101_SIDLE, eCC1101MarcStateIdle))
  {
    return false;
  }
  
  CC1101Strobe(phyInfo, CC1101_SXOFF);
  
  return true;
}

bool CC1101Calibrate(struct sCC1101PhyInfo *phyInfo)
{
  // Calibrate once radio is in IDLE state.
  if (!CC1101SetAndVerifyState(phyInfo, CC1101_SIDLE, eCC1101MarcStateIdle))
  {
    return false;
  }
    
  CC1101Strobe(phyInfo, CC1101_SCAL);
  
  return true;
}

bool CC1101Sleep(struct sCC1101PhyInfo *phyInfo)
{
  if (!phyInfo->sleep)
  {
    // CC1101 must be in an IDLE state before powering down. Please see section
    // 19.2 - "Crystal Control" for more inforamtion.
    if (!CC1101SetAndVerifyState(phyInfo, CC1101_SIDLE, eCC1101MarcStateIdle))
    {
      return false;
    }
    
    /**
     *  Once the radio is asleep, any CSn toggling will wake the radio up. We have
     *  to assume the radio is going to sleep and must therefore set the state
     *  without the use of CC1101GetMarcState().
     */
    CC1101Strobe(phyInfo, CC1101_SPWD);
    phyInfo->sleep = true;
  }
      
  return true;
}

void CC1101Wakeup(struct sCC1101PhyInfo *phyInfo, 
                  const unsigned char agctest,
                  const unsigned char test[3],
                  const unsigned char *paTable,
                  unsigned char paTableSize)
{
  /**
   *  Assumes that the SPI Read/Write implementation automatically handles
   *  asserting CSn for this radio (active low) and has waited for the SPI MISO 
   *  pin to go low (CHIP_RDYn). If this is not done, this procedure WILL NOT 
   *  WORK CORRECTLY.
   */
  if (phyInfo->sleep)
  {
    // If the radio is coming out of a sleep state, perform a wake up routine to
    // reestablish the initial radio state.
    CC1101Strobe(phyInfo, CC1101_SIDLE);
    phyInfo->sleep = false;

    /**
     *  The last valid calibration results are maintained so calibration is
     *  still valid after waking up from a low power state. The TX/RX FIFOs have
     *  been flushed. If IOCFGx.GDOx_CFG setting is less that 0x20 and 
     *  IOCFGx.GDOx_INV is 0(1), GDO0 and GDO2 pins are hardwired to 0(1), and 
     *  GDO1 is hardwired to 1(0), until CSn goes low. The following registers 
     *  are not retained and must be rewritten: AGCTEST, TEST2, TEST1, TEST0, 
     *  PATABLE(contents of PATABLE are lost except the first byte).
     */
    CC1101Write(phyInfo, CC1101_REG_AGCTEST, &agctest, 1);
    CC1101Write(phyInfo, CC1101_REG_TEST2, test, 3);
    CC1101Write(phyInfo, CC1101_PATABLE, paTable, paTableSize);
  }
}

// -----------------------------------------------------------------------------
// Device interrupt

/**
 *  GDOx functionality is defined in the header file. Since these "functions" 
 *  are extremely simple, they are defined as macros for performance benefits of 
 *  reducing function calls. See the CC1101.h file for more information.
 */

// -----------------------------------------------------------------------------
/**
 *  Test stub - test functionality of CC1101.
 */

/**
 *  To test this module, define the following in your compiler preprocessor
 *  definitions: "TEST_CC1101".
 *
 *  It is strongly suggested that you leave the test stub in this source file.
 *  This stub will allow you to easily test your implementation using unit tests 
 *  defined and by adding more to suit your application needs.
 */
#ifdef TEST_CC1101

/**
 *  Test Example - test the functionality of the CC110x/2500 device driver.
 *
 *  @version    1.0.03
 *  @date       06 Jun 2012
 *  @author     BPB, air@anaren.com
 *  @platform   Texas Instruments MSP430 (MSP430G2553/LaunchPad Dev Kit)
 *  @compiler   IAR C/C++ Compiler for MSP430
 *              5.30.3 (5.30.3.50305)
 *
 *  assumptions
 *  ===========
 *  - A Serial Peripheral Interface (SPI) driver has been implemented with
 *  the required routines for the CC1101 interface. One is implemented to work
 *  with the platform specified above.
 *  - GDO0 interface is implemented for interrupt-driven capabilities
 *
 *  file dependency
 *  ===============
 *  intrinsics.h : processor intrinsic functions
 *  - This file also depend on the compiler that is listed above.
 *  msp430g2553.h : processor register definitions
 *
 *  revision history
 *  ================
 *  ver 1.0.03 : 06 Jun 2012
 *  - restructured test stub; removed redundant test cases
 *  ver 1.0.02 : 08 May 2012
 *  - added test cases for configuration of channel and power.
 *  ver 1.0.01 : 02 May 2012
 *  - removed some unnecessary test cases and cleaned up current ones
 *  ver 1.0.00 : 23 Apr 2012
 *  - initial release
 */
// msp430 intrinsic functions (compiler specific).
#include "intrinsics.h"
// msp430g2553 peripheral and register definitions.
#include "msp430g2553.h"

// -----------------------------------------------------------------------------

// LaunchPad board support package spi device definitions.
#define SPI_CSN_OUT     P2OUT
#define SPI_CSN_DIR     P2DIR
#define SPI_CSN_SEL     P2SEL
#define SPI_CSN_SEL2    P2SEL2
#define SPI_CSN_PIN     BIT7
#define SPI_MISO_IN     P1IN
#define SPI_MISO_PIN    BIT6

// Required functions that would be defined by an application that desires to
// use the CC1101

// SPI control implementations for the LaunchPad platform.
void SpiInit()
{
  // Setup CSn line.
  SPI_CSN_DIR |= SPI_CSN_PIN;
  SPI_CSN_SEL &= ~SPI_CSN_PIN;
  SPI_CSN_SEL2 &= ~SPI_CSN_PIN;
  SPI_CSN_OUT |= SPI_CSN_PIN;
  
  // Setup the USCIB0 peripheral for SPI operation.
  UCB0CTL1 |= UCSWRST;
  UCB0CTL0 |= (UCMODE_0 | UCCKPH | UCMSB | UCMST | UCSYNC);
  UCB0CTL1 |= UCSSEL_2;
  UCB0BR1 = 0;
  UCB0BR0 = 2;
  
  // Setup SCLK, MOSI, and MISO lines.
  P1SEL |= BIT7 | BIT6 | BIT5;
  P1SEL2 |= BIT7 | BIT6 | BIT5;
  
  UCB0CTL1 &= ~UCSWRST;
}

void SpiRead(unsigned char address, unsigned char *pBuffer, unsigned char count)
{
  unsigned char i;
  
  SPI_CSN_OUT &= ~SPI_CSN_PIN;
  // Look for CHIP_RDYn from radio.
  while (SPI_MISO_IN & SPI_MISO_PIN);
  UCB0TXBUF = address;
  while (!(IFG2 & UCB0TXIFG));
  for (i = 0; i < count; i++)
  {
    UCB0TXBUF = 0xFF;
    while (!(IFG2 & UCB0TXIFG));
    *(pBuffer+i) = UCB0RXBUF;
  }
  while(UCB0STAT & UCBUSY);
  SPI_CSN_OUT |= SPI_CSN_PIN;
}

void SpiWrite(unsigned char address, const unsigned char *pBuffer, unsigned char count)
{
  unsigned char i;
  
  SPI_CSN_OUT &= ~SPI_CSN_PIN;
  // Look for CHIP_RDYn from radio.
  while (SPI_MISO_IN & SPI_MISO_PIN);
  UCB0TXBUF = address;
  while (!(IFG2 & UCB0TXIFG));
  for (i = 0; i < count; i++)
  {
    UCB0TXBUF = *(pBuffer+i);
    while (!(IFG2 & UCB0TXIFG));
  }
  while(UCB0STAT & UCBUSY);
  SPI_CSN_OUT |= SPI_CSN_PIN;
}

// AIR Boosterpack board support package radio device definitions.
#define CC1101_GDO0_IN    P2IN
#define CC1101_GDO0_DIR   P2DIR
#define CC1101_GDO0_IE    P2IE
#define CC1101_GDO0_IES   P2IES
#define CC1101_GDO0_IFG   P2IFG
#define CC1101_GDO0_SEL   P2SEL
#define CC1101_GDO0_SEL2  P2SEL2
#define CC1101_GDO0_PIN   BIT6

void Gdo0Init()
{
  CC1101_GDO0_DIR &= ~CC1101_GDO0_PIN;
  CC1101_GDO0_SEL &= ~CC1101_GDO0_PIN;
  CC1101_GDO0_SEL2 &= ~CC1101_GDO0_PIN;
  CC1101_GDO0_IES |= CC1101_GDO0_PIN;
}

bool Gdo0Event(unsigned char event)
{
  return (CC1101_GDO0_PIN & event) ? true : false;
}

void Gdo0Assert()
{
  CC1101_GDO0_IES &= ~CC1101_GDO0_PIN;  // Look for low-to-high transition
}

void Gdo0Deassert()
{
  CC1101_GDO0_IES |= CC1101_GDO0_PIN;   // Look for high-to-low transition
}

enum eCC1101GdoState Gdo0State()
{
  return ((CC1101_GDO0_IES & CC1101_GDO0_PIN) ? eCC1101GdoStateWaitForDeassert : eCC1101GdoStateWaitForAssert);
}

void Gdo0Enable(bool en)
{
  if (en)
    CC1101_GDO0_IE |= CC1101_GDO0_PIN;
  else
    CC1101_GDO0_IE &= ~CC1101_GDO0_PIN;
}

// -----------------------------------------------------------------------------

static const struct sCC1101 gCC1101Settings = {
  0x2E,               // GDO2 output pin configuration.                     
  0x2E,               // GDO1 output pin configuration.
  0x06,               // GDO0 output pin configuration.
  0x07,               // RXFIFO and TXFIFO thresholds.
  0xD3,               // Sync word, high byte
  0x91,               // Sync word, low byte
  0xFF,               // Packet length.                                     
  0x0C,               // Packet automation control.                         
  0x05,               // Packet automation control.
  0x00,               // Device address.
  0x00,               // Channel number.
  0x0A,               // Frequency synthesizer control.
  0x00,               // Frequency synthesizer control.
  0x22,               // Frequency control word, high byte.
  0xB6,               // Frequency control word, middle byte.
  0x27,               // Frequency control word, low byte.
  0x35,               // Modem configuration.
  0x83,               // Modem configuration.
  0x03,               // Modem configuration.
  0x21,               // Modem configuration.
  0xEE,               // Modem configuration.
  0x65,               // Modem deviation setting (when FSK modulation is enabled).
  0x07,               // Main Radio Control State Machine configuration.
  0x00,               // Main Radio Control State Machine configuration.    
  0x18,               // Main Radio Control State Machine configuration.
  0x16,               // Frequency Offset Compensation Configuration.
  0x6C,               // Bit synchronization Configuration.
  0x07,               // AGC control.
  0x40,               // AGC control.
  0x91,               // AGC control.
  0x87,               // High byte Event 0 timeout
  0x6B,               // Low byte Event 0 timeout
  0xF8,               // Wake On Radio control
  0x57,               // Front end RX configuration.
  0x10,               // Front end RX configuration.
  0xE9,               // Frequency synthesizer calibration.
  0x2A,               // Frequency synthesizer calibration.
  0x00,               // Frequency synthesizer calibration.
  0x1F,               // Frequency synthesizer calibration.
  0x41,               // RC oscillator configuration
  0x00,               // RC oscillator configuration  
  0x59,               // Frequency synthesizer calibration control
  0x7F,               // Production test
  0x3C,               // AGC test
  0x88,               // Various test settings.
  0x35,               // Various test settings.
  0x09                // Various test settings.
};

const struct sCC1101 *gConfig = &gCC1101Settings;
struct sCC1101PhyInfo gPhyInfo;
struct sCC1101Spi gSpi = { SpiInit, SpiRead, SpiWrite };
static const struct sCC1101Gdo gGdo0 = { 
  Gdo0Init, 
  Gdo0Event, 
  Gdo0Assert, 
  Gdo0Deassert,
  Gdo0State,
  Gdo0Enable
};
static const struct sCC1101Gdo *gGdo[3] = { &gGdo0, NULL, NULL };
static unsigned char gPaTable[8] = { 0xC0 };

#ifdef TEST_CC1101_TRANSMITTER
static unsigned char txData[8] = { 0x07, 0x00, 0x00, 'H', 'e', 'l', 'l', '0'};
#endif

#ifdef TEST_CC1101_RECEIVER
static unsigned char rxData[8];
volatile static bool packetAvailable = false;
#endif

// -----------------------------------------------------------------------------

/**
 *  Transmitter - operator strictly as a transmitting unit. Send out TX data
 *  periodically (using a software delay) while incrementing a sequence counter.
 *  On every transmission, toggle an LED.
 *
 *  Note: The transmitter uses a polling approach to determine when TX data has
 *  been sent. An interrupt-driven approach is demonstrated by the receiver.
 */
void Transmitter(void);

/**
 *  Receiver - operate strictly as a receiving unit. On every reception, toggle
 *  an LED.
 *
 *  Note: The receiver uses an interrupt-driven approach to determine when data
 *  has been received. A polling approach is demonstrated by the transmitter.
 */
void Receiver(void);

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR |= BIT0;
  P1OUT &= ~BIT0;
  
  // Test: initialize the CC1101 physical information structure. Once this is
  // initialized, regular operation may begin.
  CC1101SpiInit(&gPhyInfo, &gSpi, NULL);
  CC1101GdoInit(&gPhyInfo, gGdo);
  
  // Test: configure with default settings.
  CC1101Configure(&gPhyInfo, &gCC1101Settings);
  
  // Test: set the PA table to an initial power level.
  CC1101WriteRegisters(&gPhyInfo, CC1101_PATABLE, gPaTable, 8);
  
  // ---------------------------------------------------------------------------
  /**
   *  Test polling transmit/receive operations on two different units. One unit
   *  is designated the receiver while the other is the transmitter. This method
   *  can be modified to use an interrupt-driven approach. Toggle an LED when 
   *  done receiving and transmitting.
   */
  #if defined(TEST_CC1101_RECEIVER)
  Receiver();
  #elif defined(TEST_CC1101_TRANSMITTER)
  Transmitter();
  #endif
  
  return 0;
}

#ifdef TEST_CC1101_TRANSMITTER
void Transmitter()
{
  while (true)
  {
    unsigned int i;
    
    // Increase the sequence number on every transmission. This is mainly used
    // to display differentiation between messages (demo purposes).
    txData[2]++;
    
    // Add delay between transmits for visual effect
    for (i = 0; i < 60000; i++);
    
    // Put the radio into an IDLE state.
    CC1101Idle(&gPhyInfo);
    
    // Flush the TX FIFO and then write new data to it. Transmit.
    CC1101FlushTxFifo(&gPhyInfo);
    CC1101WriteTxFifo(&gPhyInfo, txData, sizeof(txData)/sizeof(unsigned char));
    CC1101Transmit(&gPhyInfo);
    
    // On every transmission, toggle the LED from on to off.
    P1OUT |= BIT0;
    while (!CC1101GdoEvent(gPhyInfo.gdo[0], P2IN)); // Sync sent
    while (CC1101GdoEvent(gPhyInfo.gdo[0], P2IN));  // Transmit complete
    P1OUT &= ~BIT0;
  }
}
#endif

#ifdef TEST_CC1101_RECEIVER
void Receiver()
{
  // Enable GDO interrupt and global interrupts.
  CC1101GdoEnable(gPhyInfo.gdo[0]);
  __enable_interrupt();
  
  while (true)
  {
    // Put the radio into an IDLE state.
    CC1101Idle(&gPhyInfo);
    
    // Flush the RX FIFO to prepare it for the next RF packet and turn on the
    // receiver.
    CC1101FlushRxFifo(&gPhyInfo);
    CC1101ReceiverOn(&gPhyInfo);
    
    /**
     *  On every reception, toggle the LED from off to on. This method uses a
     *  flag to determine when the interrupt has occurred and the End-Of-Packet
     *  (EOP) has been received.
     */
    P1OUT &= ~BIT0;
    while (!packetAvailable);
    P1OUT |= BIT0;
    
    // Read the data from the RX FIFO.
    CC1101ReadRxFifo(&gPhyInfo, rxData, sizeof(rxData)/sizeof(unsigned char));
    
    packetAvailable = false;
  }
}

/**
 *  
 */
#pragma vector=PORT2_VECTOR
__interrupt void Port2Isr()
{
  if (CC1101GdoEvent(gPhyInfo.gdo[0], P2IFG))
  {
    if (CC1101GdoGetState(gPhyInfo.gdo[0]) == eCC1101GdoStateWaitForAssert)
    {
      // Sync word received, begin looking for end-of-packet signal.
      CC1101GdoWaitForDeassert(gPhyInfo.gdo[0]);
    }  
    else
    {
      // End-of-packet signal has been received.
      CC1101GdoWaitForAssert(gPhyInfo.gdo[0]);
      packetAvailable = true;
    }
  }
  
  // Clear port interrupt flag.
  P2IFG = 0;
}
#endif

#endif  /* TEST_CC1101 */
