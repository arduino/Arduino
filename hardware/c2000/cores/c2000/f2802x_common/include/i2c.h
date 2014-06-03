#ifndef __I2C_H__
#define __I2C_H__

//#############################################################################
//
//! \file   f2802x_common/include/i2c.h
//!
//! \brief  Contains public interface to various functions related to the
//!         inter-integrated circuit (I2C) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

//*****************************************************************************
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif


//!
//! \defgroup I2C

//!
//! \ingroup I2C
//@{


//*****************************************************************************
// Defines for the API.
//*****************************************************************************

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
//#define I2C_MAX_BUFFER_SIZE 16

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
typedef struct _I2CMSG_
{
    uint16_t MsgStatus;             // Word stating what state msg is in:
                                  //   I2C_MSGCMD_INACTIVE = do not send msg
                                  //   I2C_MSGCMD_BUSY = msg start has been sent,
                                  //                     awaiting stop
                                  //   I2C_MSGCMD_SEND_WITHSTOP = command to send
                                  //       master trans msg complete with a stop bit
                                  //   I2C_MSGCMD_SEND_NOSTOP = command to send
                                  //       master trans msg without the stop bit
                                  //   I2C_MSGCMD_RESTART = command to send a restart
                                  //       as a master receiver with a stop bit
    uint16_t SlaveAddress;          // I2C address of slave msg is intended for
    uint16_t NumOfBytes;            // Num of valid bytes in (or to be put in MsgBuffer)
    uint16_t MemoryHighAddr;        // EEPROM address of data associated with msg (high byte)
    uint16_t MemoryLowAddr;         // EEPROM address of data associated with msg (low byte)
    uint16_t MsgBuffer[I2C_MAX_BUFFER_SIZE];    // Array holding msg data - max that
                                              // MAX_BUFFER_SIZE can be is 16 due to
                                              // the FIFO's
} I2CMSG;


//! \brief Defines the base address of the Inter-Integrated Circuit (I2C) A registers
//!
#define I2CA_BASE_ADDR              (0x00007900)


//! \brief Defines the location of the NACKMOD bit in the I2CMDR register
//!
#define I2C_I2CMDR_NAKMOD_BIT       (1u << 15)

//! \brief Defines the location of the FREE bit in the I2CMDR register
//!
#define I2C_I2CMDR_FREE_BIT         (1 << 14)

//! \brief Defines the location of the STT bit in the I2CMDR register
//!
#define I2C_I2CMDR_STT_BIT          (1 << 13)

//! \brief Defines the location of the STP bit in the I2CMDR register
//!
#define I2C_I2CMDR_STP_BIT          (1 << 11)

//! \brief Defines the location of the MST bit in the I2CMDR register
//!
#define I2C_I2CMDR_MST_BIT          (1 << 10)

//! \brief Defines the location of the TRX bit in the I2CMDR register
//!
#define I2C_I2CMDR_TRX_BIT          (1 << 9)

//! \brief Defines the location of the XA bit in the I2CMDR register
//!
#define I2C_I2CMDR_XA_BIT           (1 << 8)

//! \brief Defines the location of the RM bit in the I2CMDR register
//!
#define I2C_I2CMDR_RM_BIT           (1 << 7)

//! \brief Defines the location of the DLB bit in the I2CMDR register
//!
#define I2C_I2CMDR_DLB_BIT          (1 << 6)

//! \brief Defines the location of the IRS bit in the I2CMDR register
//!
#define I2C_I2CMDR_IRS_BIT          (1 << 5)

//! \brief Defines the location of the STB bit in the I2CMDR register
//!
#define I2C_I2CMDR_STB_BIT          (1 << 4)

//! \brief Defines the location of the IRS bit in the I2CMDR register
//!
#define I2C_I2CMDR_FDF_BIT          (1 << 3)

//! \brief Defines the location of the BC bits in the I2CMDR register
//!
#define I2C_I2CMDR_BC_BITS          (7 << 0)


//! \brief Defines the location of the AAS bit in the I2CIER register
//!
#define I2C_I2CIER_AAS_BITS          (1 << 6)

//! \brief Defines the location of the SCD bit in the I2CIER register
//!
#define I2C_I2CIER_SCD_BITS          (1 << 5)

//! \brief Defines the location of the XRDY bit in the I2CIER register
//!
#define I2C_I2CIER_XRDY_BITS         (1 << 4)

//! \brief Defines the location of the RRDY bit in the I2CIER register
//!
#define I2C_I2CIER_RRDY_BITS         (1 << 3)

//! \brief Defines the location of the ARDY bit in the I2CIER register
//!
#define I2C_I2CIER_ARDY_BITS         (1 << 2)

//! \brief Defines the location of the NACK bit in the I2CIER register
//!
#define I2C_I2CIER_NACK_BITS         (1 << 1)

//! \brief Defines the location of the AL bit in the I2CIER register
//!
#define I2C_I2CIER_AL_BITS           (1 << 0)


//! \brief Defines the location of the SDIR bit in the I2CSTR register
//!
#define I2C_I2CSTR_SDIR_BITS         (1 << 14)

//! \brief Defines the location of the NACKSNT bit in the I2CSTR register
//!
#define I2C_I2CSTR_NACKSNT_BITS      (1 << 13)

//! \brief Defines the location of the BB bit in the I2CSTR register
//!
#define I2C_I2CSTR_BB_BITS           (1 << 12)

//! \brief Defines the location of the RSFULL bit in the I2CSTR register
//!
#define I2C_I2CSTR_RSFULL_BITS       (1 << 11)

//! \brief Defines the location of the XSMT bit in the I2CSTR register
//!
#define I2C_I2CSTR_XSMT_BITS         (1 << 10)

//! \brief Defines the location of the AAS bit in the I2CSTR register
//!
#define I2C_I2CSTR_AAS_BITS          (1 << 9)

//! \brief Defines the location of the AD0 bit in the I2CSTR register
//!
#define I2C_I2CSTR_AD0_BITS          (1 << 8)

//! \brief Defines the location of the SCD bit in the I2CSTR register
//!
#define I2C_I2CSTR_SCD_BITS          (1 << 5)

//! \brief Defines the location of the XRDY bit in the I2CSTR register
//!
#define I2C_I2CSTR_XRDY_BITS         (1 << 4)

//! \brief Defines the location of the RRDY bit in the I2CSTR register
//!
#define I2C_I2CSTR_RRDY_BITS         (1 << 3)

//! \brief Defines the location of the ARDY bit in the I2CSTR register
//!
#define I2C_I2CSTR_ARDY_BITS         (1 << 2)

//! \brief Defines the location of the NACK bit in the I2CSTR register
//!
#define I2C_I2CSTR_NACK_BITS         (1 << 1)

//! \brief Defines the location of the AL bit in the I2CSTR register
//!
#define I2C_I2CSTR_AL_BITS           (1 << 0)


//! \brief Defines the location of the IPSC bits in the I2CPSC register
//!
#define I2C_I2CPSC_IPSC_BITS         (255 << 0)


//! \brief Defines the location of the SAR bits in the I2CSAR register
//!
#define I2C_I2CSAR_SAR_BITS          (1023 << 0)


//! \brief Defines the location of the OAR bits in the I2COAR register
//!
#define I2C_I2COAR_OAR_BITS          (1023 << 0)


//! \brief Defines the location of the DATA bits in the I2CDRR register
//!
#define I2C_I2CDRR_DATA_BITS         (255 << 0)


//! \brief Defines the location of the DATA bits in the I2CDXR register
//!
#define I2C_I2CDXR_DATA_BITS         (255 << 0)


//! \brief Defines the location of the FFEN bit in the I2CFFTX register
//!
#define I2C_I2CFFTX_FFEN_BIT         (1 << 14)

//! \brief Defines the location of the TXFFRST bit in the I2CFFTX register
//!
#define I2C_I2CFFTX_TXFFRST_BIT      (1 << 13)

//! \brief Defines the location of the TXFFINT bit in the I2CFFTX register
//!
#define I2C_I2CFFTX_TXFFINT_BIT      (1 << 7)

//! \brief Defines the location of the TXFFINTCLR bit in the I2CFFTX register
//!
#define I2C_I2CFFTX_TXFFINTCLR_BIT    (1 << 6)

//! \brief Defines the location of the TXFFIENA bit in the I2CFFTX register
//!
#define I2C_I2CFFTX_TXFFIENA_BIT      (1 << 5)


//! \brief Defines the location of the RXFFRST bit in the I2CFFRX register
//!
#define I2C_I2CFFRX_RXFFRST_BIT      (1 << 13)

//! \brief Defines the location of the RXFFINT bit in the I2CFFRX register
//!
#define I2C_I2CFFRX_RXFFINT_BIT      (1 << 7)

//! \brief Defines the location of the RXFFINTCLR bit in the I2CFFRX register
//!
#define I2C_I2CFFRX_RXFFINTCLR_BIT    (1 << 6)

//! \brief Defines the location of the RXFFIENA bit in the I2CFFRX register
//!
#define I2C_I2CFFRX_RXFFIENA_BIT      (1 << 5)


// **************************************************************************
// the typedefs
//*****************************************************************************

//! \brief Enumeration to define the I2C bit counts
//!
typedef enum
{
    I2C_BitCount_1_Bit = (1 << 0),        //!< Next transaction is 1 bit
    I2C_BitCount_2_Bits = (2 << 0),       //!< Next transaction is 2 bits
    I2C_BitCount_3_Bits = (3 << 0),       //!< Next transaction is 3 bits
    I2C_BitCount_4_Bits = (4 << 0),       //!< Next transaction is 4 bits
    I2C_BitCount_5_Bits = (5 << 0),       //!< Next transaction is 5 bits
    I2C_BitCount_6_Bits = (6 << 0),       //!< Next transaction is 6 bits
    I2C_BitCount_7_Bits = (7 << 0),       //!< Next transaction is 7 bits
    I2C_BitCount_8_Bits = (0 << 0)        //!< Next transaction is 8 bits
} I2C_BitCount_e;

//! \brief Enumeration to define the I2C network mode control
//!
typedef enum 
{
    I2C_Mode_Slave = (0 << 10),      //!< Denotes slave mode
    I2C_Mode_Master = (1 << 10)      //!< Denotes master mode
} I2C_Mode_e;

//! \brief Enumeration to define the I2C Interrupt Enables
//!
typedef enum 
{
    I2C_IntEn_Arb_Lost = (1 << 0),       //!< Arbitration Lost
    I2C_IntEn_NACK = (1 << 1),           //!< No-Acknowledge Detected
    I2C_IntEn_Reg_Rdy = (1 << 2),        //!< Register Ready for Access
    I2C_IntEn_Rx_Rdy = (1 << 3),         //!< Recieve Data Ready
    I2C_IntEn_Tx_Rdy = (1 << 4),         //!< Transmit Data Ready
    I2C_IntEn_Stop = (1 << 5),           //!< Stop Condition Detected
    I2C_IntEn_Slave_Addr = (1 << 6)      //!< Addressed as Slave
} I2C_IntEnable_e;

//! \brief Enumeration to define the I2C Interrupt Sources
//!
typedef enum 
{
    I2C_IntSrc_None = (0 << 0),           //!< No Interrupt
    I2C_IntSrc_Arb_Lost = (1 << 0),       //!< AL      - Arbitration Lost
    I2C_IntSrc_NACK = (2 << 0),           //!< NACK    - No-Acknowledge Detected
    I2C_IntSrc_Reg_Rdy = (3 << 0),        //!< ARDY    - Register Ready for Access
    I2C_IntSrc_Rx_Rdy = (4 << 0),         //!< RRDY    - Recieve Data Ready
    I2C_IntSrc_Tx_Rdy = (5 << 0),         //!< XRDY    - Transmit Data Ready
    I2C_IntSrc_Stop = (6 << 0),           //!< SCD     - Stop Condition Detected
    I2C_IntSrc_Slave_Addr = (7 << 0)      //!< AAS     - Addressed as Slave
} I2C_IntSource_e;

//! \brief Enumeration to define the I2C Status
//!
typedef enum 
{
    I2C_Status_None = (0 << 0),           //!< No Interrupt
    I2C_Status_Arb_Lost = (1 << 0),       //!< AL      - Arbitration Lost
    I2C_Status_NACK = (1 << 1),           //!< NACK    - No-Acknowledge Detected
    I2C_Status_Reg_Rdy = (1 << 2),        //!< ARDY    - Register Ready for Access
    I2C_Status_Rx_Rdy = (1 << 3),         //!< RRDY    - Receive Data Ready
    I2C_Status_Tx_Rdy = (1 << 4),         //!< XRDY    - Transmit Data Ready
    I2C_Status_Stop = (1 << 5),           //!< SCD     - Stop Condition Detected
    I2C_Status_AD0 = (1 << 8),            //!< AD0     - Address 0 Detected
    I2C_Status_Slave_Addr = (1 << 9),     //!< AAS     - Addressed as Slave
    I2C_Status_Tx_Empty = (1 << 10),      //!< XSMT    - Transmit Empty
    I2C_Status_Rx_Full = (1 << 11),       //!< RSFULL  - Receive Shift Register Full
    I2C_Status_Busy = (1 << 12),          //!< BB      - Bus Busy
    I2C_Status_NACK_Sent = (1 << 13),     //!< NACKSNT - No Acknowlege Sent
    I2C_Status_Slave_Dir = (1 << 14)      //!< SDIR    - Slave Direction
} I2C_Status_e;

//! \brief Enumeration to define the I2C FIFO level
//!
typedef enum 
{
    I2C_FifoLevel_Empty = (0 << 0),      //!< Denotes the fifo is empty
    I2C_FifoLevel_1_Word = (1 << 0),     //!< Denotes the fifo contains 1 word
    I2C_FifoLevel_2_Words = (2 << 0),    //!< Denotes the fifo contains 2 words
    I2C_FifoLevel_3_Words = (3 << 0),    //!< Denotes the fifo contains 3 words
    I2C_FifoLevel_4_Words = (4 << 0)     //!< Denotes the fifo contains 4 words
} I2C_FifoLevel_e;


//! \brief Enumeration to define the I2C FIFO status
//!
typedef enum 
{
    I2C_FifoStatus_Empty = (0 << 8),      //!< Denotes the fifo is empty
    I2C_FifoStatus_1_Word = (1 << 8),     //!< Denotes the fifo contains 1 word
    I2C_FifoStatus_2_Words = (2 << 8),    //!< Denotes the fifo contains 2 words
    I2C_FifoStatus_3_Words = (3 << 8),    //!< Denotes the fifo contains 3 words
    I2C_FifoStatus_4_Words = (4 << 8)     //!< Denotes the fifo contains 4 words
}  I2C_FifoStatus_e;


typedef struct _I2C_Obj_ 
{
    volatile uint16_t      I2COAR;        //!< I2C Own Address Register
    volatile uint16_t      I2CIER;        //!< I2C Interrupt Enable Register
    volatile uint16_t      I2CSTR;        //!< I2C Status Register
    volatile uint16_t      I2CCLKL;       //!< I2C Clock Low-Time Divier Register
    volatile uint16_t      I2CCLKH;       //!< I2C Clock High-Time Divier Register
    volatile uint16_t      I2CCNT;        //!< I2C Data Count Register
    volatile uint16_t      I2CDRR;        //!< I2C Data Recieve Register
    volatile uint16_t      I2CSAR;        //!< I2C Slave Address Register
    volatile uint16_t      I2CDXR;        //!< I2C Data Transmit Register
    volatile uint16_t      I2CMDR;        //!< I2C Mode Register
    volatile uint16_t      I2CISRC;       //!< I2C Interrupt Source Register
    volatile uint16_t      I2CEMDR;       //!< I2C Extended Mode Register
    volatile uint16_t      I2CPSC;        //!< I2C Pre-Scalar Register
    volatile uint32_t      I2CD1;         //!< Dummy registers to cover gap to FF regs
    volatile uint32_t      I2CD2;
    volatile uint32_t      I2CD3;
    volatile uint32_t      I2CD4;
    volatile uint32_t      I2CD5;
    volatile uint32_t      I2CD6;
    volatile uint32_t      I2CD7;
    volatile uint32_t      I2CD8;
    volatile uint32_t      I2CD9;
    volatile uint16_t      I2CFFTX;       //!< I2C FIFO Transmit Register
    volatile uint16_t      I2CFFRX;       //!< I2C FIFO Recieve Register
} I2C_Obj;


//! \brief Defines the serial peripheral interface (SPI) handle
//!
typedef struct I2C_Obj  *I2C_Handle;

void I2C_setupClock(I2C_Handle i2cHandle, const uint16_t preScalar,
                    const  uint16_t bitTimeLow, const uint16_t bitTimeHigh);
I2C_Handle I2C_init(void *pMemory, const size_t num_bytes);
void I2C_setMode(I2C_Handle i2cHandle, unsigned int bitMask);
void I2C_disable(I2C_Handle i2cHandle);
void I2C_enable(I2C_Handle i2cHandle);
void I2C_setMaster(I2C_Handle i2cHandle);
void I2C_setSlave(I2C_Handle i2cHandle);
void I2C_setTransmit(I2C_Handle i2cHandle);
void I2C_setReceive(I2C_Handle i2cHandle);
void I2C_setStop(I2C_Handle i2cHandle);
void I2C_clearStop(I2C_Handle i2cHandle);
void I2C_setStart(I2C_Handle i2cHandle);
void I2C_clearStart(I2C_Handle i2cHandle);
void I2C_enableInt(I2C_Handle i2cHandle, const I2C_IntEnable_e interrupts);
void I2C_enableFifo(I2C_Handle i2cHandle);
void I2C_clearTxFifoInt(I2C_Handle i2cHandle);
void I2C_clearRxFifoInt(I2C_Handle i2cHandle);
void I2C_disableFifo(I2C_Handle i2cHandle);
void I2C_resetTxFifo(I2C_Handle i2cHandle);
void I2C_resetRxFifo(I2C_Handle i2cHandle);
void I2C_disableInt(I2C_Handle i2cHandle, const I2C_IntEnable_e interrupts);
I2C_IntSource_e I2C_getIntSource(I2C_Handle i2cHandle);
uint16_t I2C_getStatus(I2C_Handle i2cHandle);
void I2C_clearArbLost(I2C_Handle i2cHandle);
void I2C_clearNACK(I2C_Handle i2cHandle);
void I2C_clearAccessReady(I2C_Handle i2cHandle);
void I2C_clearReceiveDataReady(I2C_Handle i2cHandle);
void I2C_clearStopCondDetected(I2C_Handle i2cHandle);
void I2C_setSlaveAddress(I2C_Handle i2cHandle, const uint16_t slaveAddress);
void I2C_setMasterSlaveAddr(I2C_Handle i2cHandle, const uint16_t slaveAddress);
bool_t I2C_isMasterBusy(I2C_Handle i2cHandle);
void I2C_putData(I2C_Handle i2cHandle, uint16_t data);
uint16_t I2C_getData(I2C_Handle i2cHandle);
void I2C_setRxFifoIntLevel(I2C_Handle i2cHandle, const I2C_FifoLevel_e fifoLevel);
void I2C_setTxFifoIntLevel(I2C_Handle i2cHandle, const I2C_FifoLevel_e fifoLevel);
void I2C_disableTxFifoInt(I2C_Handle i2cHandle);
void I2C_disableRxFifoInt(I2C_Handle i2cHandle);
void I2C_enableTxFifoInt(I2C_Handle i2cHandle);
void I2C_enableRxFifoInt(I2C_Handle i2cHandle);
void I2C_setCharLength(I2C_Handle i2cHandle, const I2C_BitCount_e charLength);
void I2C_setNackmod(I2C_Handle i2cHandle);
void I2C_clearNackmod(I2C_Handle i2cHandle);
void I2C_setDebugFree(I2C_Handle i2cHandle);
void I2C_clearDebugFree(I2C_Handle i2cHandle);
void I2C_set7BitAddress(I2C_Handle i2cHandle);
void I2C_set10BitAddress(I2C_Handle i2cHandle);
void I2C_setFreeRun(I2C_Handle i2cHandle);
void I2C_setRptMode(I2C_Handle i2cHandle);
void I2C_clearRptMode(I2C_Handle i2cHandle);
void I2C_setDigitalLoopback(I2C_Handle i2cHandle);
void I2C_clearDigitalLoopback(I2C_Handle i2cHandle);
void I2C_setExtendedStart(I2C_Handle i2cHandle);
void I2C_setNormalStart(I2C_Handle i2cHandle);
void I2C_setFreeDataFormat(I2C_Handle i2cHandle);
void I2C_clearFreeDataFormat(I2C_Handle i2cHandle);
void I2C_setBitCount(I2C_Handle i2cHandle, int bcount);
void I2C_setDataCount(I2C_Handle i2cHandle, int dcount);
I2C_FifoStatus_e I2C_getTxFifoStatus(I2C_Handle i2cHandle);
I2C_FifoStatus_e I2C_getRxFifoStatus(I2C_Handle i2cHandle);
int I2C_getRxFifoInt(I2C_Handle i2cHandle);
int I2C_getBusBusy(I2C_Handle i2cHandle);
int I2C_getRxReady(I2C_Handle i2cHandle);
int I2C_getStopCondition(I2C_Handle i2cHandle);
int I2C_getStopCondDetected(I2C_Handle i2cHandle);
void I2C_clearModuleReset(I2C_Handle i2cHandle);
void I2C_setModuleReset(I2C_Handle i2cHandle);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
#endif

#endif // __I2C_H__


