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

//! \brief Defines the base address of the Inter-Integrated Circuit (I2C) A registers
//!
#define I2CA_BASE_ADDR              (0x00007900)


//! \brief Defines the location of the NACKMOD bit in the I2CMDR register
//!
#define I2C_I2CMDR_NAKMOD_BIT       (1 << 15)

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

//! \brief Enumeration to define the I2C network mode control
//!
typedef enum
{
    I2C_Control_Stop           = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_STP_BIT, //!< Assert Stop Condition
    I2C_Control_Single_TX      = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_TRX_BIT 
                             | I2C_I2CMDR_STT_BIT | I2C_I2CMDR_STP_BIT, //!< Single TX Transaction
    I2C_Control_Single_RX      = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_STT_BIT 
                             | I2C_I2CMDR_STP_BIT,                      //!< Single RX Transaction
    I2C_Control_Burst_TX_Start = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_STT_BIT 
                             | I2C_I2CMDR_TRX_BIT,                      //!< Start Burst TX Transaction
    I2C_Control_Burst_TX_Stop  = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_STP_BIT 
                             | I2C_I2CMDR_TRX_BIT,                      //!< End Burst TX Transaction
    I2C_Control_Burst_RX_Start = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_STT_BIT, //!< Start Burst RX Transaction
    I2C_Control_Burst_RX_Stop  = I2C_I2CMDR_MST_BIT | I2C_I2CMDR_STP_BIT  //!< End Burst RX Transaction
} I2C_Control_e;
            

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
    I2C_IntSrc_Arb_Lost = (1 << 0),       //!< Arbitration Lost
    I2C_IntSrc_NACK = (2 << 0),           //!< No-Acknowledge Detected
    I2C_IntSrc_Reg_Rdy = (3 << 0),        //!< Register Ready for Access
    I2C_IntSrc_Rx_Rdy = (4 << 0),         //!< Recieve Data Ready
    I2C_IntSrc_Tx_Rdy = (5 << 0),         //!< Transmit Data Ready
    I2C_IntSrc_Stop = (6 << 0),           //!< Stop Condition Detected
    I2C_IntSrc_Slave_Addr = (7 << 0)      //!< Addressed as Slave
} I2C_IntSource_e;

//! \brief Enumeration to define the I2C Status
//!
typedef enum
{
    I2C_Status_None = (0 << 0),           //!< No Interrupt
    I2C_Status_Arb_Lost = (1 << 0),       //!< Arbitration Lost
    I2C_Status_NACK = (1 << 1),           //!< No-Acknowledge Detected
    I2C_Status_Reg_Rdy = (1 << 2),        //!< Register Ready for Access
    I2C_Status_Rx_Rdy = (1 << 3),         //!< Recieve Data Ready
    I2C_Status_Tx_Rdy = (1 << 4),         //!< Transmit Data Ready
    I2C_Status_Stop = (1 << 5),           //!< Stop Condition Detected
    I2C_Status_AD0 = (1 << 8),            //!< Address 0 Detected
    I2C_Status_Slave_Addr = (1 << 9),      //!< Addressed as Slave
    I2C_Status_Tx_Empty = (1 << 10),      //!< Transmit Empty
    I2C_Status_Rx_Full = (1 << 11),       //!< Recieve Full
    I2C_Status_Busy = (1 << 12),          //!< Bus Busy
    I2C_Status_NACK_Sent = (1 << 13),     //!< No Acknowlege Sent
    I2C_Status_Slave_Dir = (1 << 14)      //!< Slave Direction
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
    volatile uint16_t      I2CFFTX;       //!< I2C FIFO Transmit Register
    volatile uint16_t      I2CFFRX;       //!< I2C FIFO Recieve Register
} I2C_Obj;


//! \brief Defines the serial peripheral interface (SPI) handle
//!
typedef struct I2C_Obj  *I2C_Handle;


//! \brief     Sets up the clocking for the I2C peripheral
//! \param[in] i2cHandle  The I2C object handle
//! \param[in] preScalar  The clock pre-scalar
//! \param[in] bitTimeLow   Clock low time divider
//! \param[in] bitTimeHigh  Clock high time divider
void I2C_setupClock(I2C_Handle i2cHandle, const uint16_t preScalar,
        const  uint16_t bitTimeLow, const uint16_t bitTimeHigh);

#ifndef NDEBUG
extern bool_t I2C_isHandleValid(I2C_Handle i2cHandle);
#endif

////*****************************************************************************
//// Interrupt defines.
////*****************************************************************************
//#define I2C_INT_MASTER                             0x00000001
//#define I2C_INT_SLAVE                              0x00000002
//
////*****************************************************************************
//// I2C Master commands.
////*****************************************************************************
//#define I2C_MASTER_CMD_SINGLE_SEND                 0x00000007
//#define I2C_MASTER_CMD_SINGLE_RECEIVE              0x00000007
//#define I2C_MASTER_CMD_BURST_SEND_START            0x00000003
//#define I2C_MASTER_CMD_BURST_SEND_CONT             0x00000001
//#define I2C_MASTER_CMD_BURST_SEND_FINISH           0x00000005
//#define I2C_MASTER_CMD_BURST_SEND_ERROR_STOP       0x00000004
//#define I2C_MASTER_CMD_BURST_RECEIVE_START         0x0000000b
//#define I2C_MASTER_CMD_BURST_RECEIVE_CONT          0x00000009
//#define I2C_MASTER_CMD_BURST_RECEIVE_FINISH        0x00000005
//#define I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP    0x00000004
//
////*****************************************************************************
//// I2C Master error status.
////*****************************************************************************
//#define I2C_MASTER_ERR_NONE                        0
//#define I2C_MASTER_ERR_ADDR_ACK                    0x00000004
//#define I2C_MASTER_ERR_DATA_ACK                    0x00000008
//#define I2C_MASTER_ERR_ARB_LOST                    0x00000010
//
////*****************************************************************************
//// I2C Slave action requests
////*****************************************************************************
//#define I2C_SLAVE_ACT_NONE                         0
//#define I2C_SLAVE_ACT_RREQ                         0x00000001   // Master has
//                                                                // sent data
//#define I2C_SLAVE_ACT_TREQ                         0x00000002   // Master has
//                                                                // requested
//                                                                // data
//#define I2C_SLAVE_ACT_RREQ_FBR                     0x00000005   // Master has
//                                                                // sent first
//                                                                // byte
//
////*****************************************************************************
//// Miscellaneous I2C driver definitions.
////*****************************************************************************
//#define I2C_MASTER_MAX_RETRIES                     1000         // Number of
//                                                                // retries
//
//
////*****************************************************************************
//// I2C Slave interrupts.
////*****************************************************************************
//#define I2C_SLAVE_INT_STOP                         0x00000004   // Stop
//                                                                // Condition
//                                                                // Interrupt.
//#define I2C_SLAVE_INT_START                        0x00000002   // Start
//                                                                // Condition
//                                                                // Interrupt.
//#define I2C_SLAVE_INT_DATA                         0x00000001   // Data
//                                                                // Interrupt.


//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
//extern void I2CIntRegister(unsigned long ulBase, void(fnHandler) (void));
//extern void I2CIntUnregister(unsigned long ulBase);
//extern tBoolean I2CMasterBusBusy(unsigned long ulBase);
//extern tBoolean I2CMasterBusy(unsigned long ulBase);
//extern void I2CMasterControl(unsigned long ulBase, unsigned long ulCmd);
//extern unsigned long I2CMasterDataGet(unsigned long ulBase);
//extern void I2CMasterDataPut(unsigned long ulBase, unsigned char ucData);
//extern void I2CMasterDisable(unsigned long ulBase);
//extern void I2CMasterEnable(unsigned long ulBase);
//extern unsigned long I2CMasterErr(unsigned long ulBase);
//extern void I2CMasterInitExpClk(unsigned long ulBase, unsigned long ulI2CClk,
//                                tBoolean bFast);
//extern void I2CMasterIntClear(unsigned long ulBase);
//extern void I2CMasterIntDisable(unsigned long ulBase);
//extern void I2CMasterIntEnable(unsigned long ulBase);
//extern tBoolean I2CMasterIntStatus(unsigned long ulBase, tBoolean bMasked);
//extern void I2CMasterSlaveAddrSet(unsigned long ulBase,
//                                  unsigned char ucSlaveAddr,
//                                  tBoolean      bReceive);
//extern unsigned long I2CSlaveDataGet(unsigned long ulBase);
//extern void I2CSlaveDataPut(unsigned long ulBase, unsigned char ucData);
//extern void I2CSlaveDisable(unsigned long ulBase);
//extern void I2CSlaveEnable(unsigned long ulBase);
//extern void I2CSlaveInit(unsigned long ulBase, unsigned char ucSlaveAddr);
//extern void I2CSlaveIntClear(unsigned long ulBase);
//extern void I2CSlaveIntDisable(unsigned long ulBase);
//extern void I2CSlaveIntEnable(unsigned long ulBase);
//extern void I2CSlaveIntClearEx(unsigned long ulBase, unsigned long ulIntFlags);
//extern void I2CSlaveIntDisableEx(unsigned long ulBase,
//                                 unsigned long ulIntFlags);
//extern void I2CSlaveIntEnableEx(unsigned long ulBase, unsigned long ulIntFlags);
//extern tBoolean I2CSlaveIntStatus(unsigned long ulBase, tBoolean bMasked);
//extern unsigned long I2CSlaveIntStatusEx(unsigned long ulBase,
//                                         tBoolean      bMasked);
//extern unsigned long I2CSlaveStatus(unsigned long ulBase);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __I2C_H__


