//*****************************************************************************
//
// i2c.h - Prototypes for the I2C Driver.
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

#ifndef __I2C_H__
#define __I2C_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Defines for the API.
//
//*****************************************************************************

#define I2C_MASTER_BASE         (I2CS0_BASE)


//*****************************************************************************
//
// Interrupt defines.
//
//*****************************************************************************
#define I2C_INT_MASTER           0x00000001
#define I2C_INT_SLAVE            0x00000002

#define I2C_MASTER_INT_RXFF      0x00000800
#define I2C_MASTER_INT_TXFE      0x00000400
#define I2C_MASTER_INT_RXFR      0x00000200
#define I2C_MASTER_INT_TXFR      0x00000100
#define I2C_MASTER_INT_ARBL      0x00000080
#define I2C_MASTER_INT_STOP      0x00000040
#define I2C_MASTER_INT_START     0x00000020
#define I2C_MASTER_INT_NACK      0x00000010
#define I2C_MASTER_INT_DMATX     0x00000008
#define I2C_MASTER_INT_DMARX     0x00000004
#define I2C_MASTER_INT_TIMEOUT   0x00000002
#define I2C_MASTER_INT_DATA      0x00000001

#define I2C_SLAVE_INT_RXFF    0x00000100
#define I2C_SLAVE_INT_TXFF    0x00000080
#define I2C_SLAVE_INT_RXFR    0x00000040
#define I2C_SLAVE_INT_TXFR    0x00000020
#define I2C_SLAVE_INT_DMATX   0x00000010
#define I2C_SLAVE_INT_DMARX   0x00000008

//*****************************************************************************
//
// I2C Master commands.
//
//*****************************************************************************
#define I2C_MASTER_CMD_SINGLE_SEND                                            \
                                0x00000007
#define I2C_MASTER_CMD_SINGLE_RECEIVE                                         \
                                0x00000007
#define I2C_MASTER_CMD_BURST_SEND_START                                       \
                                0x00000003
#define I2C_MASTER_CMD_BURST_SEND_CONT                                        \
                                0x00000001
#define I2C_MASTER_CMD_BURST_SEND_FINISH                                      \
                                0x00000005
#define I2C_MASTER_CMD_BURST_SEND_STOP                                        \
                                0x00000004
#define I2C_MASTER_CMD_BURST_SEND_ERROR_STOP                                  \
                                0x00000004
#define I2C_MASTER_CMD_BURST_RECEIVE_START                                    \
                                0x0000000b
#define I2C_MASTER_CMD_BURST_RECEIVE_CONT                                     \
                                0x00000009
#define I2C_MASTER_CMD_BURST_RECEIVE_FINISH                                   \
                                0x00000005
#define I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP                               \
                                0x00000004

#define I2C_MASTER_CMD_QUICK_COMMAND                                          \
                                0x00000027

#define I2C_MASTER_CMD_BURST_EX_SEND_SINGLE                                   \
                                0x00000046
#define I2C_MASTER_CMD_BURST_EX_SEND_START                                    \
                                0x00000042
#define I2C_MASTER_CMD_BURST_EX_SEND_CONT                                     \
                                0x00000040
#define I2C_MASTER_CMD_BURST_EX_SEND_FINISH                                   \
                                0x0000044
#define I2C_MASTER_CMD_BURST_EX_SEND_STOP                                     \
                                0x00000004

#define I2C_MASTER_CMD_BURST_EX_RECEIVE_SINGLE                                \
                                0x00000046
#define I2C_MASTER_CMD_BURST_EX_RECEIVE_START                                 \
                                0x0000004a
#define I2C_MASTER_CMD_BURST_EX_RECEIVE_CONT                                  \
                                0x00000048
#define I2C_MASTER_CMD_BURST_EX_RECEIVE_FINISH                                \
                                0x00000044
#define I2C_MASTER_CMD_BURST_EX_RECEIVE_STOP                                  \
                                0x00000005


//*****************************************************************************
//
// I2C Master error status.
//
//*****************************************************************************
#define I2C_MASTER_ERR_NONE     0
#define I2C_MASTER_ERR_CLKTOUT   0x00000080
#define I2C_MASTER_ERR_ADDR_ACK 0x00000004
#define I2C_MASTER_ERR_DATA_ACK 0x00000008
#define I2C_MASTER_ERR_ARB_LOST 0x00000010

//*****************************************************************************
//
// I2C Slave action requests
//
//*****************************************************************************
#define I2C_SLAVE_ACT_NONE      0
#define I2C_SLAVE_ACT_RREQ      0x00000001  // Master has sent data
#define I2C_SLAVE_ACT_TREQ      0x00000002  // Master has requested data
#define I2C_SLAVE_ACT_RREQ_FBR  0x00000005  // Master has sent first byte
#define I2C_SLAVE_ACT_OWN2SEL   0x00000008  // Master requested secondary slave
#define I2C_SLAVE_ACT_QCMD      0x00000010  // Master has sent a Quick Command
#define I2C_SLAVE_ACT_QCMD_DATA 0x00000020  // Master Quick Command value


//*****************************************************************************
//
// Miscellaneous I2C driver definitions.
//
//*****************************************************************************
#define I2C_MASTER_MAX_RETRIES  1000        // Number of retries


//*****************************************************************************
//
// I2C Master interrupts.
//
//*****************************************************************************
#define I2C_MASTER_INT_TIMEOUT   0x00000002  // Clock Timeout Interrupt.
#define I2C_MASTER_INT_DATA      0x00000001  // Data Interrupt.

//*****************************************************************************
//
// I2C Slave interrupts.
//
//*****************************************************************************
#define I2C_SLAVE_INT_STOP      0x00000004  // Stop Condition Interrupt.
#define I2C_SLAVE_INT_START     0x00000002  // Start Condition Interrupt.
#define I2C_SLAVE_INT_DATA      0x00000001  // Data Interrupt.


//*****************************************************************************
//
// I2C DMA configurations.
//
//*****************************************************************************
#define I2C_DMA_SHARED          0x00000004  // TX and RX shared channel.
#define I2C_DMA_TXONLY          0x00000002  // TX only channel.
#define I2C_DMA_RXONLY          0x00000001  // RX only channel.
#define I2C_DMA_NONE            0x00000000  // DMA not selected.

//*****************************************************************************
//
// I2C FIFO configurations.
//
//*****************************************************************************
#define I2C_FIFO_SLAVE   0x00008000
#define I2C_FIFO_FLUSH   0x00004000
#define I2C_FIFO_DMA_EN  0x00002000
#define I2C_FIFO_TRIG_0   0x00000000
#define I2C_FIFO_TRIG_1   0x00000001
#define I2C_FIFO_TRIG_2   0x00000002
#define I2C_FIFO_TRIG_3   0x00000003
#define I2C_FIFO_TRIG_4   0x00000004
#define I2C_FIFO_TRIG_5   0x00000005
#define I2C_FIFO_TRIG_6   0x00000006
#define I2C_FIFO_TRIG_7   0x00000007

//*****************************************************************************
//
// I2C Master Seed
//
//*****************************************************************************

#define I2C_MASTER_MODE_STD   0
#define I2C_MASTER_MODE_FST   1
#define I2C_MASTER_MODE_FPLS  2


//*****************************************************************************
//
// I2CFIFO Status
//
//*****************************************************************************
#define I2C_FIFO_RX_ABVTRIG   0x00040000
#define I2C_FIFO_RX_FF        0x00020000
#define I2C_FIFO_RX_FE        0x00010000
#define I2C_FIFO_TX_BVLTRIG   0x00000004
#define I2C_FIFO_TX_FF        0x00000002
#define I2C_FIFO_TX_FE        0x00000001
#define I2C_FIFO_NONE         0x00000000



//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void I2CIntRegister(unsigned long ulBase, void(fnHandler)(void));
extern void I2CIntUnregister(unsigned long ulBase);
extern tBoolean I2CMasterBusBusy(unsigned long ulBase);
extern tBoolean I2CMasterBusy(unsigned long ulBase);
extern void I2CMasterControl(unsigned long ulBase, unsigned long ulCmd);
extern unsigned long I2CMasterDataGet(unsigned long ulBase);
extern void I2CMasterDataPut(unsigned long ulBase, unsigned char ucData);
extern void I2CMasterDisable(unsigned long ulBase);
extern void I2CMasterEnable(unsigned long ulBase);
extern unsigned long I2CMasterErr(unsigned long ulBase);
extern void I2CMasterInitExpClk(unsigned long ulBase, unsigned long ulI2CClk,
                                tBoolean bFast);
extern void I2CMasterIntClear(unsigned long ulBase);
extern void I2CMasterIntDisable(unsigned long ulBase);
extern void I2CMasterIntEnable(unsigned long ulBase);
extern tBoolean I2CMasterIntStatus(unsigned long ulBase, tBoolean bMasked);

extern void I2CMasterIntEnableEx(unsigned long ulBase,
                                 unsigned long ulIntFlags);
extern void I2CMasterIntDisableEx(unsigned long ulBase,
                                  unsigned long ulIntFlags);
extern unsigned long I2CMasterIntStatusEx(unsigned long ulBase,
                                          tBoolean bMasked);
extern void I2CMasterInitExpClkEx(unsigned long ulBase, unsigned long ulI2CClk,
                    tBoolean bConfHiSpd,unsigned long ulMode);

extern void I2CMasterIntClearEx(unsigned long ulBase,
                                unsigned long ulIntFlags);
extern void I2CMasterTimeoutSet(unsigned long ulBase, unsigned long ulValue);
extern void I2CSlaveACKOverride(unsigned long ulBase, tBoolean bEnable);
extern void I2CSlaveACKValueSet(unsigned long ulBase, tBoolean bACK);
extern unsigned long I2CMasterLineStateGet(unsigned long ulBase);
extern void I2CMasterSlaveAddrSet(unsigned long ulBase,
                                  unsigned char ucSlaveAddr,
                                  tBoolean bReceive);
extern unsigned long I2CSlaveDataGet(unsigned long ulBase);
extern void I2CSlaveDataPut(unsigned long ulBase, unsigned char ucData);
extern void I2CSlaveDisable(unsigned long ulBase);
extern void I2CSlaveEnable(unsigned long ulBase);
extern void I2CSlaveInit(unsigned long ulBase, unsigned char ucSlaveAddr);
extern void I2CSlaveAddressSet(unsigned long ulBase, unsigned char ucAddrNum,
                               unsigned char ucSlaveAddr);
extern void I2CSlaveIntClear(unsigned long ulBase);
extern void I2CSlaveIntDisable(unsigned long ulBase);
extern void I2CSlaveIntEnable(unsigned long ulBase);
extern void I2CSlaveIntClearEx(unsigned long ulBase, unsigned long ulIntFlags);
extern void I2CSlaveIntDisableEx(unsigned long ulBase,
                                 unsigned long ulIntFlags);
extern void I2CSlaveIntEnableEx(unsigned long ulBase, unsigned long ulIntFlags);
extern tBoolean I2CSlaveIntStatus(unsigned long ulBase, tBoolean bMasked);
extern unsigned long I2CSlaveIntStatusEx(unsigned long ulBase,
                                         tBoolean bMasked);
extern unsigned long I2CSlaveStatus(unsigned long ulBase);
extern void I2CLoopBackEnable(unsigned long ulBase);
extern void I2CLoopBackDisable(unsigned long ulBase);
extern void I2CFIFOCtrlSet(unsigned long ulBase, unsigned long ulTxTrigLvl,
               unsigned long ulTxFlag, unsigned ulRxTrigLvl,
               unsigned long ulRxFlag);
extern void I2CFIFOWrite(unsigned long ulBase,unsigned char ucData);
extern unsigned long I2CFIFORead(unsigned long ulBase);
extern unsigned long I2CFIFOStatusGet(unsigned long ulBase);
extern void I2CMultiMasterEnable(unsigned long ulBase);
extern void I2CMultiMasterDisable(unsigned long ulBase);


//*****************************************************************************
//
// Several I2C APIs have been renamed, with the original function name being
// deprecated.  These defines provide backward compatibility.
//
//*****************************************************************************
#ifndef DEPRECATED
#define I2CMasterInit(a, b)                         \
        I2CMasterInitExpClk(a, SysCtlClockGet(), b)
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __I2C_H__
