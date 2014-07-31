// TI File $Revision: /main/2 $
// Checkin $Date: September 18, 2008   17:00:35 $
//###########################################################################
//
// FILE:    DSP2802x_I2cExample.h
//
// TITLE:    2802x I2C Example Code Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef DSP2802x_I2C_DEFINES_H
#define DSP2802x_I2C_DEFINES_H

//--------------------------------------------
// Defines
//--------------------------------------------

// Error Messages
#define I2C_ERROR               0xFFFF
#define I2C_ARB_LOST_ERROR      0x0001
#define I2C_NACK_ERROR          0x0002
#define I2C_BUS_BUSY_ERROR      0x1000
#define I2C_STP_NOT_READY_ERROR 0x5555
#define I2C_NO_FLAGS            0xAAAA
#define I2C_SUCCESS             0x0000

// Clear Status Flags
#define I2C_CLR_AL_BIT          0x0001
#define I2C_CLR_NACK_BIT        0x0002
#define I2C_CLR_ARDY_BIT        0x0004
#define I2C_CLR_RRDY_BIT        0x0008
#define I2C_CLR_SCD_BIT         0x0020

// Interrupt Source Messages
#define I2C_NO_ISRC             0x0000
#define I2C_ARB_ISRC            0x0001
#define I2C_NACK_ISRC           0x0002
#define I2C_ARDY_ISRC           0x0003
#define I2C_RX_ISRC             0x0004
#define I2C_TX_ISRC             0x0005
#define I2C_SCD_ISRC            0x0006
#define I2C_AAS_ISRC            0x0007

// I2CMSG structure defines
#define I2C_NO_STOP  0
#define I2C_YES_STOP 1
#define I2C_RECEIVE  0
#define I2C_TRANSMIT 1
#define I2C_MAX_BUFFER_SIZE 4

// I2C Slave State defines
#define I2C_NOTSLAVE      0
#define I2C_ADDR_AS_SLAVE 1
#define I2C_ST_MSG_READY  2

// I2C Slave Receiver messages defines
#define I2C_SND_MSG1 1
#define I2C_SND_MSG2 2

// I2C State defines
#define I2C_IDLE               0
#define I2C_SLAVE_RECEIVER     1
#define I2C_SLAVE_TRANSMITTER  2
#define I2C_MASTER_RECEIVER    3
#define I2C_MASTER_TRANSMITTER 4

// I2C  Message Commands for I2CMSG struct
#define I2C_MSGSTAT_INACTIVE          0x0000
#define I2C_MSGSTAT_SEND_WITHSTOP     0x0010
#define I2C_MSGSTAT_WRITE_BUSY        0x0011
#define I2C_MSGSTAT_SEND_NOSTOP       0x0020
#define I2C_MSGSTAT_SEND_NOSTOP_BUSY  0x0021
#define I2C_MSGSTAT_RESTART           0x0022
#define I2C_MSGSTAT_READ_BUSY         0x0023

// Generic defines
#define I2C_TRUE  1
#define I2C_FALSE 0
#define I2C_YES   1
#define I2C_NO    0
#define I2C_DUMMY_BYTE 0

//--------------------------------------------
// Structures
//--------------------------------------------

// I2C Message Structure
struct I2CMSG {
  Uint16 MsgStatus;                // Word stating what state msg is in:
                                  //   I2C_MSGCMD_INACTIVE = do not send msg
                                  //   I2C_MSGCMD_BUSY = msg start has been sent,
                                  //                     awaiting stop
                                  //   I2C_MSGCMD_SEND_WITHSTOP = command to send
                                  //       master trans msg complete with a stop bit
                                  //   I2C_MSGCMD_SEND_NOSTOP = command to send
                                  //       master trans msg without the stop bit
                                  //   I2C_MSGCMD_RESTART = command to send a restart
                                  //       as a master receiver with a stop bit
  Uint16 SlaveAddress;            // I2C address of slave msg is intended for
  Uint16 NumOfBytes;            // Num of valid bytes in (or to be put in MsgBuffer)
  Uint16 MemoryHighAddr;        // EEPROM address of data associated with msg (high byte)
  Uint16 MemoryLowAddr;            // EEPROM address of data associated with msg (low byte)
  Uint16 MsgBuffer[I2C_MAX_BUFFER_SIZE];    // Array holding msg data - max that
                                              // MAX_BUFFER_SIZE can be is 4 due to
                                              // the FIFO's
};

#endif  // end of DSP2802x_I2C_DEFINES_H definition

//===========================================================================
// End of file.
//===========================================================================
