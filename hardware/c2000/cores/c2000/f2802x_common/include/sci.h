#ifndef _SCI_H_
#define _SCI_H_

//#############################################################################
//
//! \file   f2802x_common/include/sci.h
//!
//! \brief  Contains public interface to various functions related
//!         to the serial communications interface (SCI) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes

// drivers
#include "f2802x_common/include/cpu.h"


// modules


//!
//! \defgroup SCI

//!
//! \ingroup SCI
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the serial communications interface (SCI) A registers
//!
#define SCIA_BASE_ADDR              (0x00007050)


//! \brief Defines the location of the SCICHAR2-0 bits in the SCICCR register
//!
#define SCI_SCICCR_CHAR_LENGTH_BITS   (7 << 0)

//! \brief Defines the location of the ADDR/IDLE MODE bits in the SCICCR register
//!
#define SCI_SCICCR_MODE_BITS          (1 << 3)

//! \brief Defines the location of the LOOP BACK ENA bits in the SCICCR register
//!
#define SCI_SCICCR_LB_ENA_BITS        (1 << 4)

//! \brief Defines the location of the PARITY ENABLE bits in the SCICCR register
//!
#define SCI_SCICCR_PARITY_ENA_BITS    (1 << 5)

//! \brief Defines the location of the EVEN/ODD PARITY bits in the SCICCR register
//!
#define SCI_SCICCR_PARITY_BITS        (1 << 6)

//! \brief Defines the location of the STOP bits in the SCICCR register
//!
#define SCI_SCICCR_STOP_BITS          (1 << 7)


//! \brief Defines the location of the RXENA bits in the SCICTL1 register
//!
#define SCI_SCICTL1_RXENA_BITS           (1 << 0)

//! \brief Defines the location of the TXENA bits in the SCICTL1 register
//!
#define SCI_SCICTL1_TXENA_BITS           (1 << 1)

//! \brief Defines the location of the SLEEP bits in the SCICTL1 register
//!
#define SCI_SCICTL1_SLEEP_BITS           (1 << 2)

//! \brief Defines the location of the TXWAKE bits in the SCICTL1 register
//!
#define SCI_SCICTL1_TXWAKE_BITS          (1 << 3)

//! \brief Defines the location of the SW RESET bits in the SCICTL1 register
//!
#define SCI_SCICTL1_RESET_BITS           (1 << 5)

//! \brief Defines the location of the RX ERR INT ENA bits in the SCICTL1 register
//!
#define SCI_SCICTL1_RX_ERR_INT_ENA_BITS  (1 << 6)


//! \brief Defines the location of the TX INT ENA bits in the SCICTL2 register
//!
#define SCI_SCICTL2_TX_INT_ENA_BITS      (1 << 0)

//! \brief Defines the location of the RX/BK INT ENA bits in the SCICTL2 register
//!
#define SCI_SCICTL2_RX_INT_ENA_BITS      (1 << 1)  

//! \brief Defines the location of the TX EMPTY bits in the SCICTL2 register
//!
#define SCI_SCICTL2_TXEMPTY_BITS         (1 << 6)

//! \brief Defines the location of the RX EMPTY bits in the SCICTL2 register
//!
#define SCI_SCICTL2_TXRDY_BITS           (1 << 7)


//! \brief Defines the location of the RXWAKE bits in the SCIRXST register
//!
#define SCI_SCIRXST_RXWAKE_BITS          (1 << 1)

//! \brief Defines the location of the PE bits in the SCIRXST register
//!
#define SCI_SCIRXST_PE_BITS              (1 << 2)

//! \brief Defines the location of the OE bits in the SCIRXST register
//!
#define SCI_SCIRXST_OE_BITS              (1 << 3)

//! \brief Defines the location of the FE bits in the SCIRXST register
//!
#define SCI_SCIRXST_FE_BITS              (1 << 4)

//! \brief Defines the location of the BRKDT bits in the SCIRXST register
//!
#define SCI_SCIRXST_BRKDT_BITS           (1 << 5)

//! \brief Defines the location of the RXRDY bits in the SCIRXST register
//!
#define SCI_SCIRXST_RXRDY_BITS           (1 << 6)  

//! \brief Defines the location of the RX ERROR bits in the SCIRXST register
//!
#define SCI_SCIRXST_RXERROR_BITS         (1 << 7)  


//! \brief Defines the location of the RXFFIL4-0 bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_IL_BITS           (31 << 0)

//! \brief Defines the location of the RXFFIENA bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_IENA_BITS         ( 1 << 5)

//! \brief Defines the location of the RXFFINT CLR bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_INTCLR_BITS       ( 1 << 6)

//! \brief Defines the location of the RXFFINT flag bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_INT_BITS          ( 1 << 7)

//! \brief Defines the location of the RXFFST4-0 bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_FIFO_ST_BITS      (31 << 8)

//! \brief Defines the location of the RXFIFO Reset bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_FIFO_RESET_BITS   ( 1 << 13)

//! \brief Defines the location of the RXFFOVF CLR bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_FIFO_OVFCLR_BITS  ( 1 << 14)

//! \brief Defines the location of the RXFFOVF bits in the SCIFFRX register
//!
#define SCI_SCIFFRX_FIFO_OVF_BITS     ( 1 << 15)


//! \brief Defines the location of the TXFFIL4-0 bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_IL_BITS           (31 << 0)

//! \brief Defines the location of the TXFFIENA bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_IENA_BITS         ( 1 << 5)

//! \brief Defines the location of the TXFFINT CLR bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_INTCLR_BITS       ( 1 << 6)

//! \brief Defines the location of the TXFFINT flag bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_INT_BITS          ( 1 << 7)

//! \brief Defines the location of the TXFFST4-0 bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_FIFO_ST_BITS      (31 << 8)

//! \brief Defines the location of the TXFIFO Reset bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_FIFO_RESET_BITS   ( 1 << 13)

//! \brief Defines the location of the SCIFFENA bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_FIFO_ENA_BITS     ( 1 << 14)

//! \brief Defines the location of the SCIRST bits in the SCIFFTX register
//!
#define SCI_SCIFFTX_CHAN_RESET_BITS   ( 1 << 15)


//! \brief Defines the location of the FFTXDLY7-0 bits in the SCIFFCT register
//!
#define SCI_SCIFFCT_DELAY_BITS        (255 << 0)

//! \brief Defines the location of the CDC bits in the SCIFFCT register
//!
#define SCI_SCIFFCT_CDC_BITS          (  1 << 13)

//! \brief Defines the location of the ABD CLR bits in the SCIFFCT register
//!
#define SCI_SCIFFCT_ABDCLR_BITS       (  1 << 14)

//! \brief Defines the location of the ABD bits in the SCIFFCT register
//!
#define SCI_SCIFFCT_ABD_BITS          (  1 << 15)


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the serial communications interface (SCI) baud rates.  This enumeration assume a device clock of 60Mhz and a LSPCLK of 15MHz
//!
typedef enum
{
    SCI_BaudRate_9_6_kBaud = 194,      //!< Denotes 9.6 kBaud
    SCI_BaudRate_19_2_kBaud = 97,      //!< Denotes 19.2 kBaud
    SCI_BaudRate_57_6_kBaud = 33,      //!< Denotes 57.6 kBaud
    SCI_BaudRate_115_2_kBaud = 15      //!< Denotes 115.2 kBaud
} SCI_BaudRate_e;


//! \brief Enumeration to define the serial communications interface (SCI) character lengths
//!
typedef enum
{
    SCI_CharLength_1_Bit=(0 << 0),     //!< Denotes a character length of 1 bit
    SCI_CharLength_2_Bits=(1 << 0),    //!< Denotes a character length of 2 bits
    SCI_CharLength_3_Bits=(2 << 0),    //!< Denotes a character length of 3 bits
    SCI_CharLength_4_Bits=(3 << 0),    //!< Denotes a character length of 4 bits
    SCI_CharLength_5_Bits=(4 << 0),    //!< Denotes a character length of 5 bits
    SCI_CharLength_6_Bits=(5 << 0),    //!< Denotes a character length of 6 bits
    SCI_CharLength_7_Bits=(6 << 0),    //!< Denotes a character length of 7 bits
    SCI_CharLength_8_Bits=(7 << 0)     //!< Denotes a character length of 8 bits
} SCI_CharLength_e;


//! \brief Enumeration to define the serial communications interface (SCI) multiprocessor protocol mode
//!
typedef enum
{
    SCI_Mode_IdleLine=(0 << 3),    //!< Denotes idle-line mode protocol
    SCI_Mode_AddressBit=(1 << 3)   //!< Denotes address-bit mode protocol
} SCI_Mode_e;


//! \brief Enumeration to define the serial communications interface (SCI) number of stop bits
//!
typedef enum
{
    SCI_NumStopBits_One=(0 << 7),   //!< Denotes 1 stop bit
    SCI_NumStopBits_Two=(1 << 7)    //!< Denotes 2 stop bits
} SCI_NumStopBits_e;


//! \brief Enumeration to define the serial communications interface (SCI) parity
//!
typedef enum
{
    SCI_Parity_Odd=(0 << 5),        //!< Denotes odd parity
    SCI_Parity_Even=(1 << 5)        //!< Denotes even parity
} SCI_Parity_e;


//! \brief Enumeration to define the serial communications interface (SCI) emulation suspend priority
//!
typedef enum
{
    SCI_Priority_Immediate=(0 << 3),    //!< Denotes an immediate stop
    SCI_Priority_FreeRun=(1 << 3),      //!< Denotes free running
    SCI_Priority_AfterRxRxSeq=(2 << 3)  //!< Denotes that a stop after the current receive/transmit sequence
} SCI_Priority_e;


//! \brief Enumeration to define the serial communications interface (SCI) FIFO level
//!
typedef enum
{
    SCI_FifoLevel_Empty=(0 << 0),      //!< Denotes the fifo is empty
    SCI_FifoLevel_1_Word=(1 << 0),     //!< Denotes the fifo contains 1 word
    SCI_FifoLevel_2_Words=(2 << 0),    //!< Denotes the fifo contains 2 words
    SCI_FifoLevel_3_Words=(3 << 0),    //!< Denotes the fifo contains 3 words
    SCI_FifoLevel_4_Words=(4 << 0)     //!< Denotes the fifo contains 4 words
} SCI_FifoLevel_e;


//! \brief Enumeration to define the serial communications interface (SCI) FIFO status
//!
typedef enum
{
    SCI_FifoStatus_Empty=(0 << 8),      //!< Denotes the fifo is empty
    SCI_FifoStatus_1_Word=(1 << 8),     //!< Denotes the fifo contains 1 word
    SCI_FifoStatus_2_Words=(2 << 8),    //!< Denotes the fifo contains 2 words
    SCI_FifoStatus_3_Words=(3 << 8),    //!< Denotes the fifo contains 3 words
    SCI_FifoStatus_4_Words=(4 << 8)     //!< Denotes the fifo contains 4 words
}  SCI_FifoStatus_e;


//! \brief Defines the serial communications interface (SCI) object
//!
typedef struct _SCI_Obj_
{
    volatile uint16_t      SCICCR;        //!< SCI Configuration Control Register
    volatile uint16_t      SCICTL1;       //!< SCI Control Register 1
    volatile uint16_t      SCIHBAUD;      //!< SCI Baud Register, High Bits
    volatile uint16_t      SCILBAUD;      //!< SCI Baud Register, Low Bits
    volatile uint16_t      SCICTL2;       //!< SCI Control Register 2
    volatile uint16_t      SCIRXST;       //!< SCI Receive Status Register
    volatile uint16_t      SCIRXEMU;      //!< SCI Receive Emulation Data Buffer Register
    volatile uint16_t      SCIRXBUF;      //!< SCI Receive Data Buffer Register
    volatile uint16_t      rsvd_1;        //!< Reserved
    volatile uint16_t      SCITXBUF;      //!< SCI Transmit Data Buffer Register
    volatile uint16_t      SCIFFTX;       //!< SCI FIFO Transmit Register
    volatile uint16_t      SCIFFRX;       //!< SCI FIFO Receive Register
    volatile uint16_t      SCIFFCT;       //!< SCI FIFO Control Register
    volatile uint16_t      rsvd_2[2];     //!< Reserved
    volatile uint16_t      SCIPRI;        //!< SCI Priority Register
} SCI_Obj;


//! \brief Defines the serial communications interface (SCI) handle
//!
typedef struct SCI_Obj  *SCI_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Clears the auto baud detect mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_clearAutoBaudDetect(SCI_Handle sciHandle);


//! \brief     Clears the Rx FIFO overflow flag
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_clearRxFifoOvf(SCI_Handle sciHandle);


//! \brief     Clears the Rx FIFO interrupt flag
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_clearRxFifoInt(SCI_Handle sciHandle);


//! \brief     Clears the Tx FIFO interrupt flag
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_clearTxFifoInt(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disable(SCI_Handle sciHandle);


//! \brief     Disable the serial communications interface (SCI) auto baud alignment
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableAutoBaudAlign(SCI_Handle sciHandle);


//! \brief     Disables the serial peripheral interface (SCI) loop back mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableLoopBack(SCI_Handle sciHandle);


//! \brief     Disable the parity
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableParity(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) master/slave receive mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableRx(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) receive error interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableRxErrorInt(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) receive FIFO interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableRxFifoInt(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) receive interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableRxInt(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) sleep mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableSleep(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) master/slave transmit mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableTx(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) FIFO enhancements
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableFifoEnh(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) transmit FIFO interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableTxFifoInt(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) transmit interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableTxInt(SCI_Handle sciHandle);


//! \brief     Disables the serial communications interface (SCI) wakeup method
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_disableTxWake(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enable(SCI_Handle sciHandle);


//! \brief     Enable the serial communications interface (SCI) auto baud alignment
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableAutoBaudAlign(SCI_Handle sciHandle);


//! \brief     Enables the serial peripheral interface (SCI) loop back mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableLoopBack(SCI_Handle sciHandle);


//! \brief     Enables the serial peripheral interface (SCI) parity
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableParity(SCI_Handle sciHandle);


//! \brief     Enables the serial peripheral interface (SCI) receiver
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableRx(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) receive error interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableRxErrorInt(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) receive interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableRxInt(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) sleep mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableSleep(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) receive FIFO interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableRxFifoInt(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) masater/slave transmit mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableTx(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) FIFO enhancements
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableFifoEnh(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) transmit FIFO interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableTxFifoInt(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) transmit interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableTxInt(SCI_Handle sciHandle);


//! \brief     Enables the serial communications interface (SCI) wakeup method
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_enableTxWake(SCI_Handle sciHandle);


//! \brief     Gets data from the serial communications interface (Blocking)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \return    Data from the serial peripheral
uint16_t SCI_getDataBlocking(SCI_Handle sciHandle);


//! \brief     Read data from the serial communications interface (Non-Blocking)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[out] success  Pointer to a variable which will house whether the read was successful or not (true on success)
//! \return    Data if successful, or NULL if no characters 
uint16_t SCI_getDataNonBlocking(SCI_Handle sciHandle, uint16_t * success);


//! \brief     Gets the serial communications interface (SCI) receive FIFO status
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \return    The receive FIFO status
SCI_FifoStatus_e SCI_getRxFifoStatus(SCI_Handle sciHandle);


//! \brief     Gets the serial communications interface (SCI) transmit FIFO status
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \return    The transmit FIFO status
SCI_FifoStatus_e SCI_getTxFifoStatus(SCI_Handle sciHandle);


//! \brief     Initializes the serial communications interface (SCI) object handle
//! \param[in] pMemory     A pointer to the base address of the SCI registers
//! \param[in] numBytes    The number of bytes allocated for the SCI object, bytes
//! \return    The serial communications interface (SCI) object handle
SCI_Handle SCI_init(void *pMemory,const size_t numBytes);


//! \brief     Writes data to the serial communications interface (Blocking)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] data       The data value
void SCI_putDataBlocking(SCI_Handle sciHandle, uint16_t data);


//! \brief     Writes data to the serial communications interface (Non-Blocking)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] data       The data value
//! \return    True on successful write, false if no space is available in the transmit buffer
uint16_t SCI_putDataNonBlocking(SCI_Handle sciHandle, uint16_t data);


//! \brief     Reads data from the serial communications interface (SCI)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \return    The received data value
inline uint16_t SCI_getData(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;

    // get the data
    uint16_t data = sci->SCIRXBUF;

    return(data);
} // end of SCI_getData() function


//! \brief     Resets the serial communications interface (SCI)
//! \param[in] sciHandle  The serial communication interface (SCI) object handle
void SCI_reset(SCI_Handle sciHandle);


//! \brief     Resets the serial communications interface (SCI) transmit and receive channels
//! \param[in] sciHandle  The serial communication interface (SCI) object handle
void SCI_resetChannels(SCI_Handle sciHandle);


//! \brief     Resets the serial communications interface (SCI) receive FIFO
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_resetRxFifo(SCI_Handle sciHandle);


//! \brief     Resets the serial communications interface (SCI) transmit FIFO
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
void SCI_resetTxFifo(SCI_Handle sciHandle);


//! \brief     Determines if the serial communications interface (SCI) has receive data ready
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \return    The receive data status
inline bool_t SCI_isRxDataReady(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;
    bool_t status;

    status = (sci->SCIRXST & SCI_SCIRXST_RXRDY_BITS) >> 6;

    return((bool_t)status);
} // end of SCI_isRxDataReady() function


//! \brief     Sets the serial communications interface (SCI) baud rate
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] baudRate   The baud rate
void SCI_setBaudRate(SCI_Handle sciHandle,const SCI_BaudRate_e baudRate);


//! \brief     Sets the serial communications interface (SCI) character length
//! \param[in] sciHandle   The serial communications interface (SCI) object handle
//! \param[in] charLength  The character length
void SCI_setCharLength(SCI_Handle sciHandle,const SCI_CharLength_e charLength);


//! \brief     Sets the serial communications interface (SCI) miltprocessor mode
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] mode       The multiprocessor mode
void SCI_setMode(SCI_Handle sciHandle,const SCI_Mode_e mode);


//! \brief     Sets the serial communications interface (SCI) number of stop bits
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] numBits    The number of bits
void SCI_setNumStopBits(SCI_Handle sciHandle,const SCI_NumStopBits_e numBits);


//! \brief     Sets the serial communications interface (SCI) priority
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] priority   The priority
void SCI_setPriority(SCI_Handle sciHandle,const SCI_Priority_e priority);


//! \brief     Sets the serial communications interface (SCI) parity
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] parity     The parity
void SCI_setParity(SCI_Handle sciHandle,const SCI_Parity_e parity);


//! \brief     Sets the serial communications interface (SCI) transmit delay
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] delay     The transmit delay
void SCI_setTxDelay(SCI_Handle sciHandle,const uint8_t delay);


//! \brief     Sets the serial communications interface (SCI) transmit FIFO level for generating an interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] fifoLevel  The FIFO level
void SCI_setTxFifoIntLevel(SCI_Handle sciHandle,const SCI_FifoLevel_e fifoLevel);


//! \brief     Sets the serial communications interface (SCI) receive FIFO level for generating an interrupt
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] fifoLevel  The FIFO level
void SCI_setRxFifoIntLevel(SCI_Handle sciHandle,const SCI_FifoLevel_e fifoLevel);


//! \brief     Determines if the serial communications interface (SCI) is ready to transmit
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \return    The transmit status
inline bool_t SCI_isTxReady(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;
    bool_t status;

    status = (sci->SCICTL2 & SCI_SCICTL2_TXRDY_BITS) >> 7;

    return((bool_t)status);
} // end of SCI_isTxReady() function


//! \brief     Writes data to the serial communications interface (SCI)
//! \param[in] sciHandle  The serial communications interface (SCI) object handle
//! \param[in] data       The data value
inline void SCI_putData(SCI_Handle sciHandle,const uint16_t data)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // write the data
    sci->SCITXBUF = data;

    return;
} // end of SCI_putData() function


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _SCI_H_ definition

