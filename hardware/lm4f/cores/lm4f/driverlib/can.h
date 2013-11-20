//*****************************************************************************
//
// can.h - Defines and Macros for the CAN controller.
//
// Copyright (c) 2006-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_CAN_H__
#define __DRIVERLIB_CAN_H__

//*****************************************************************************
//
//! \addtogroup can_api
//! @{
//
//*****************************************************************************

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
// Miscellaneous defines for Message ID Types
//
//*****************************************************************************

//*****************************************************************************
//
// These are the flags used by the tCANMsgObject.ui32Flags value when calling
// the CANMessageSet() and CANMessageGet() functions.
//
//*****************************************************************************

//
//! This indicates that transmit interrupts should be enabled, or are enabled.
//
#define MSG_OBJ_TX_INT_ENABLE   0x00000001

//
//! This indicates that receive interrupts should be enabled, or are
//! enabled.
//
#define MSG_OBJ_RX_INT_ENABLE   0x00000002

//
//! This indicates that a message object will use or is using an extended
//! identifier.
//
#define MSG_OBJ_EXTENDED_ID     0x00000004

//
//! This indicates that a message object will use or is using filtering
//! based on the object's message identifier.
//
#define MSG_OBJ_USE_ID_FILTER   0x00000008

//
//! This indicates that new data was available in the message object.
//
#define MSG_OBJ_NEW_DATA        0x00000080

//
//! This indicates that data was lost since this message object was last
//! read.
//
#define MSG_OBJ_DATA_LOST       0x00000100

//
//! This indicates that a message object will use or is using filtering
//! based on the direction of the transfer.  If the direction filtering is
//! used, then ID filtering must also be enabled.
//
#define MSG_OBJ_USE_DIR_FILTER  (0x00000010 | MSG_OBJ_USE_ID_FILTER)

//
//! This indicates that a message object will use or is using message
//! identifier filtering based on the extended identifier.  If the extended
//! identifier filtering is used, then ID filtering must also be enabled.
//
#define MSG_OBJ_USE_EXT_FILTER  (0x00000020 | MSG_OBJ_USE_ID_FILTER)

//
//! This indicates that a message object is a remote frame.
//
#define MSG_OBJ_REMOTE_FRAME    0x00000040

//
//! This indicates that this message object is part of a FIFO structure and
//! not the final message object in a FIFO.
//
#define MSG_OBJ_FIFO            0x00000200

//
//! This indicates that a message object has no flags set.
//
#define MSG_OBJ_NO_FLAGS        0x00000000

//*****************************************************************************
//
//! This define is used with the flag values to allow checking only status
//! flags and not configuration flags.
//
//*****************************************************************************
#define MSG_OBJ_STATUS_MASK     (MSG_OBJ_NEW_DATA | MSG_OBJ_DATA_LOST)

//*****************************************************************************
//
//! The structure used for encapsulating all the items associated with a CAN
//! message object in the CAN controller.
//
//*****************************************************************************
typedef struct
{
    //
    //! The CAN message identifier used for 11 or 29 bit identifiers.
    //
    uint32_t ui32MsgID;

    //
    //! The message identifier mask used when identifier filtering is enabled.
    //
    uint32_t ui32MsgIDMask;

    //
    //! This value holds various status flags and settings specified by
    //! tCANObjFlags.
    //
    uint32_t ui32Flags;

    //
    //! This value is the number of bytes of data in the message object.
    //
    uint32_t ui32MsgLen;

    //
    //! This is a pointer to the message object's data.
    //
    uint8_t *pui8MsgData;
}
tCANMsgObject;

//*****************************************************************************
//
//! This structure is used for encapsulating the values associated with setting
//! up the bit timing for a CAN controller.  The structure is used when calling
//! the CANGetBitTiming and CANSetBitTiming functions.
//
//*****************************************************************************
typedef struct
{
    //
    //! This value holds the sum of the Synchronization, Propagation, and Phase
    //! Buffer 1 segments, measured in time quanta.  The valid values for this
    //! setting range from 2 to 16.
    //
    uint32_t ui32SyncPropPhase1Seg;

    //
    //! This value holds the Phase Buffer 2 segment in time quanta.  The valid
    //! values for this setting range from 1 to 8.
    //
    uint32_t ui32Phase2Seg;

    //
    //! This value holds the Resynchronization Jump Width in time quanta.  The
    //! valid values for this setting range from 1 to 4.
    //
    uint32_t ui32SJW;

    //
    //! This value holds the CAN_CLK divider used to determine time quanta.
    //! The valid values for this setting range from 1 to 1023.
    //
    uint32_t ui32QuantumPrescaler;
}
tCANBitClkParms;

//*****************************************************************************
//
//! This data type is used to identify the interrupt status register.  This is
//! used when calling the CANIntStatus() function.
//
//*****************************************************************************
typedef enum
{
    //
    //! Read the CAN interrupt status information.
    //
    CAN_INT_STS_CAUSE,

    //
    //! Read a message object's interrupt status.
    //
    CAN_INT_STS_OBJECT
}
tCANIntStsReg;

//*****************************************************************************
//
//! This data type is used to identify which of several status registers to
//! read when calling the CANStatusGet() function.
//
//*****************************************************************************
typedef enum
{
    //
    //! Read the full CAN controller status.
    //
    CAN_STS_CONTROL,

    //
    //! Read the full 32-bit mask of message objects with a transmit request
    //! set.
    //
    CAN_STS_TXREQUEST,

    //
    //! Read the full 32-bit mask of message objects with new data available.
    //
    CAN_STS_NEWDAT,

    //
    //! Read the full 32-bit mask of message objects that are enabled.
    //
    CAN_STS_MSGVAL
}
tCANStsReg;

//*****************************************************************************
//
// These definitions are used to specify interrupt sources to CANIntEnable()
// and CANIntDisable().
//
//*****************************************************************************
//
//! This flag is used to allow a CAN controller to generate error
//! interrupts.
//
#define CAN_INT_ERROR           0x00000008

//
//! This flag is used to allow a CAN controller to generate status
//! interrupts.
//
#define CAN_INT_STATUS          0x00000004

//
//! This flag is used to allow a CAN controller to generate any CAN
//! interrupts.  If this is not set, then no interrupts will be generated
//! by the CAN controller.
//
#define CAN_INT_MASTER          0x00000002

//*****************************************************************************
//
//! This definition is used to determine the type of message object that will
//! be set up via a call to the CANMessageSet() API.
//
//*****************************************************************************
typedef enum
{
    //
    //! Transmit message object.
    //
    MSG_OBJ_TYPE_TX,

    //
    //! Transmit remote request message object
    //
    MSG_OBJ_TYPE_TX_REMOTE,

    //
    //! Receive message object.
    //
    MSG_OBJ_TYPE_RX,

    //
    //! Receive remote request message object.
    //
    MSG_OBJ_TYPE_RX_REMOTE,

    //
    //! Remote frame receive remote, with auto-transmit message object.
    //
    MSG_OBJ_TYPE_RXTX_REMOTE
}
tMsgObjType;

//*****************************************************************************
//
// The following enumeration contains all error or status indicators that can
// be returned when calling the CANStatusGet() function.
//
//*****************************************************************************
//
//! CAN controller has entered a Bus Off state.
//
#define CAN_STATUS_BUS_OFF      0x00000080

//
//! CAN controller error level has reached warning level.
//
#define CAN_STATUS_EWARN        0x00000040

//
//! CAN controller error level has reached error passive level.
//
#define CAN_STATUS_EPASS        0x00000020

//
//! A message was received successfully since the last read of this status.
//
#define CAN_STATUS_RXOK         0x00000010

//
//! A message was transmitted successfully since the last read of this
//! status.
//
#define CAN_STATUS_TXOK         0x00000008

//
//! This is the mask for the last error code field.
//
#define CAN_STATUS_LEC_MSK      0x00000007

//
//! There was no error.
//
#define CAN_STATUS_LEC_NONE     0x00000000

//
//! A bit stuffing error has occurred.
//
#define CAN_STATUS_LEC_STUFF    0x00000001

//
//! A formatting error has occurred.
//
#define CAN_STATUS_LEC_FORM     0x00000002

//
//! An acknowledge error has occurred.
//
#define CAN_STATUS_LEC_ACK      0x00000003

//
//! The bus remained a bit level of 1 for longer than is allowed.
//
#define CAN_STATUS_LEC_BIT1     0x00000004

//
//! The bus remained a bit level of 0 for longer than is allowed.
//
#define CAN_STATUS_LEC_BIT0     0x00000005

//
//! A CRC error has occurred.
//
#define CAN_STATUS_LEC_CRC      0x00000006

//
//! This is the mask for the CAN Last Error Code (LEC).
//
#define CAN_STATUS_LEC_MASK     0x00000007

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void CANBitTimingGet(uint32_t ui32Base, tCANBitClkParms *psClkParms);
extern void CANBitTimingSet(uint32_t ui32Base, tCANBitClkParms *psClkParms);
extern uint32_t CANBitRateSet(uint32_t ui32Base, uint32_t ui32SourceClock,
                              uint32_t ui32BitRate);
extern void CANDisable(uint32_t ui32Base);
extern void CANEnable(uint32_t ui32Base);
extern bool CANErrCntrGet(uint32_t ui32Base, uint32_t *pui32RxCount,
                          uint32_t *pui32TxCount);
extern void CANInit(uint32_t ui32Base);
extern void CANIntClear(uint32_t ui32Base, uint32_t ui32IntClr);
extern void CANIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void CANIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void CANIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
extern uint32_t CANIntStatus(uint32_t ui32Base, tCANIntStsReg eIntStsReg);
extern void CANIntUnregister(uint32_t ui32Base);
extern void CANMessageClear(uint32_t ui32Base, uint32_t ui32ObjID);
extern void CANMessageGet(uint32_t ui32Base, uint32_t ui32ObjID,
                          tCANMsgObject *psMsgObject, bool bClrPendingInt);
extern void CANMessageSet(uint32_t ui32Base, uint32_t ui32ObjID,
                          tCANMsgObject *psMsgObject, tMsgObjType eMsgType);
extern bool CANRetryGet(uint32_t ui32Base);
extern void CANRetrySet(uint32_t ui32Base, bool bAutoRetry);
extern uint32_t CANStatusGet(uint32_t ui32Base, tCANStsReg eStatusReg);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_CAN_H__
