//*****************************************************************************
//
// eeprom.h - Prototypes for the EEPROM driver.
//
// Copyright (c) 2010-2013 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __DRIVERLIB_EEPROM_H__
#define __DRIVERLIB_EEPROM_H__

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
//! \addtogroup eeprom_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// Values returned by EEPROMInit.
//
//*****************************************************************************

//
//! This value may be returned from a call to EEPROMInit().  It indicates that
//! no previous write operations were interrupted by a reset event and that the
//! EEPROM peripheral is ready for use.
//
#define EEPROM_INIT_OK      0

//
//! This value may be returned from a call to EEPROMInit().  It indicates that
//! a previous data or protection write operation was interrupted by a reset
//! event.  The EEPROM peripheral has recovered its state but the last write
//! operation may have been lost.  The application must check the validity of
//! data it has written and retry any writes as required.
//
#define EEPROM_INIT_RETRY   1

//
//! This value may be returned from a call to EEPROMInit().  It indicates that
//! a previous data or protection write operation was interrupted by a reset
//! event and that the EEPROM peripheral was unable to clean up after the
//! problem.  This situation may be resolved with another reset or may be fatal
//! depending upon the cause of the problem.  For example, if the voltage to
//! the part is unstable, retrying once the voltage has stabilized may clear
//! the error.
//
#define EEPROM_INIT_ERROR   2

//*****************************************************************************
//
// Error indicators returned by various EEPROM API calls.  These will be ORed
// together into the final return code.
//
//*****************************************************************************

//
//! This return code bit indicates that the EEPROM programming state machine
//! failed to write a value due to the voltage level dropping below that
//! required for EEPROM programming.  The operation may be retried once the
//! voltage stabilizes.
//
#define EEPROM_RC_INVPL             0x00000100

//
//! This return code bit indicates that an attempt was made to read from
//! the EEPROM while a write operation was in progress.
//
#define EEPROM_RC_WRBUSY            0x00000020

//
//! This return code bit indicates that an attempt was made to write a
//! value but the destination permissions disallow write operations.  This
//! may be due to the destination block being locked, access protection set
//! to prohibit writes or an attempt to write a password when one is already
//! written.
//
#define EEPROM_RC_NOPERM            0x00000010

//
//! This return code bit indicates that the EEPROM programming state machine
//! is currently copying to or from the internal copy buffer to make room for
//! a newly written value.  It is provided as a status indicator and does not
//! indicate an error.
//
#define EEPROM_RC_WKCOPY            0x00000008

//
//! This return code bit indicates that the EEPROM programming state machine
//! is currently erasing the internal copy buffer.  It is provided as a
//! status indicator and does not indicate an error.
//
#define EEPROM_RC_WKERASE           0x00000004

//
//! This return code bit indicates that the EEPROM programming state machine
//! is currently working.  No new write operations should be attempted until
//! this bit is clear.
//
#define EEPROM_RC_WORKING           0x00000001

//*****************************************************************************
//
// Values that can be passed to EEPROMBlockProtectSet() in the ui32Protect
// parameter, and returned by EEPROMBlockProtectGet().
//
//*****************************************************************************

//
//! This bit may be ORed with the protection option passed to
//! EEPROMBlockProtectSet() or returned from EEPROMBlockProtectGet().  It
//! restricts EEPROM access to threads running in supervisor mode and prevents
//! access to an EEPROM block when the CPU is in user mode.
//
#define EEPROM_PROT_SUPERVISOR_ONLY 0x00000008

//
//! This value may be passed to EEPROMBlockProtectSet() or returned from
//! EEPROMBlockProtectGet().  It indicates that the block should offer
//! read/write access when no password is set or when a password is set and
//! the block is unlocked, and read-only access when a password is set but
//! the block is locked.
//
#define EEPROM_PROT_RW_LRO_URW      0x00000000

//
//! This value may be passed to EEPROMBlockProtectSet() or returned from
//! EEPROMBlockProtectGet().  It indicates that the block should offer neither
//! read nor write access unless it is protected by a password and unlocked.
//
#define EEPROM_PROT_NA_LNA_URW      0x00000001

//
//! This value may be passed to EEPROMBlockProtectSet() or returned from
//! EEPROMBlockProtectGet().  It indicates that the block should offer
//! read-only access when no password is set or when a password is set and the
//! block is unlocked.  When a password is set and the block is locked, neither
//! read nor write access is permitted.
//
#define EEPROM_PROT_RO_LNA_URO      0x00000002

//*****************************************************************************
//
//! This value may be passed to EEPROMIntEnable() and EEPROMIntDisable() and is
//! returned by EEPROMIntStatus() if an EEPROM interrupt is currently being
//! signaled.
//
//*****************************************************************************
#define EEPROM_INT_PROGRAM          0x00000004

//*****************************************************************************
//
//! Returns the EEPROM block number containing a given offset address.
//!
//! \param ui32Addr is the linear, byte address of the EEPROM location whose
//! block number is to be returned.  This is a zero-based offset from the start
//! of the EEPROM storage.
//!
//! This macro may be used to translate an EEPROM address offset into a
//! block number suitable for use in any of the driver's block protection
//! functions.  The address provided is expressed as a byte offset from the
//! base of the EEPROM.
//!
//! \return Returns the zero-based block number which contains the passed
//! address.
//
//*****************************************************************************
#define EEPROMBlockFromAddr(ui32Addr) ((ui32Addr) >> 6)

//*****************************************************************************
//
//! Returns the offset address of the first word in an EEPROM block.
//!
//! \param ui32Block is the index of the EEPROM block whose first word address
//! is to be returned.
//!
//! This macro may be used to determine the address of the first word in a
//! given EEPROM block.  The address returned is expressed as a byte offset
//! from the base of EEPROM storage.
//!
//! \return Returns the address of the first word in the given EEPROM block.
//
//*****************************************************************************
#define EEPROMAddrFromBlock(ui32Block) ((ui32Block) << 6)

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern uint32_t EEPROMInit(void);
extern uint32_t EEPROMSizeGet(void);
extern uint32_t EEPROMBlockCountGet(void);
extern void EEPROMRead(uint32_t *pui32Data, uint32_t ui32Address,
                       uint32_t ui32Count);
extern uint32_t EEPROMProgram(uint32_t *pui32Data,
                              uint32_t ui32Address,
                              uint32_t ui32Count);
extern uint32_t EEPROMProgramNonBlocking(uint32_t ui32Data,
                                         uint32_t ui32Address);
extern uint32_t EEPROMStatusGet(void);
extern uint32_t EEPROMMassErase(void);
extern uint32_t EEPROMBlockProtectGet(uint32_t ui32Block);
extern uint32_t EEPROMBlockProtectSet(uint32_t ui32Block,
                                      uint32_t ui32Protect);
extern uint32_t EEPROMBlockPasswordSet(uint32_t ui32Block,
                                       uint32_t *pui32Password,
                                       uint32_t ui32Count);
extern uint32_t EEPROMBlockLock(uint32_t ui32Block);
extern uint32_t EEPROMBlockUnlock(uint32_t ui32Block,
                                  uint32_t *pui32Password,
                                  uint32_t ui32Count);
extern void EEPROMBlockHide(uint32_t ui32Block);
extern void EEPROMIntEnable(uint32_t ui32IntFlags);
extern void EEPROMIntDisable(uint32_t ui32IntFlags);
extern uint32_t EEPROMIntStatus(bool bMasked);
extern void EEPROMIntClear(uint32_t ui32IntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_EEPROM_H__
