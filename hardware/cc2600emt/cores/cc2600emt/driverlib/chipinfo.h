/******************************************************************************
*  Filename:       chipinfo.h
*  Revised:        2015-10-27 13:41:27 +0100 (Tue, 27 Oct 2015)
*  Revision:       44843
*
*  Description:    Collection of functions returning chip information.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

//*****************************************************************************
//
//! \addtogroup system_control_group
//! @{
//! \addtogroup ChipInfo
//! @{
//
//*****************************************************************************

#ifndef __CHIP_INFO_H__
#define __CHIP_INFO_H__

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

#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <inc/hw_fcfg1.h>

//*****************************************************************************
//
//! \brief Enumeration identifying the protocols supported.
//!
//! \note
//! This is a bit vector enumeration that indicates supported protocols.
//! E.g: 0x06 means that the chip supports both BLE and IEEE 802.15.4
//
//*****************************************************************************
typedef enum {
   PROTOCOL_Unknown          = 0   , //!< None of the known protocols are supported.
   PROTOCOLBIT_BLE           = 0x02, //!< Bit[1] set, indicates that Bluetooth Low Energy is supported.
   PROTOCOLBIT_IEEE_802_15_4 = 0x04, //!< Bit[2] set, indicates that IEEE 802.15.4 is supported.
   PROTOCOLBIT_Proprietary   = 0x08  //!< Bit[3] set, indicates that proprietary protocols are supported.
} ProtocolBitVector_t;

//*****************************************************************************
//
//! \brief Returns bit vector showing supported protocols.
//!
//! \return
//! Returns \ref ProtocolBitVector_t which is a bit vector indicating supported protocols.
//
//*****************************************************************************
extern ProtocolBitVector_t ChipInfo_GetSupportedProtocol_BV( void );


//*****************************************************************************
//
//! \brief Returns true if the chip supports the BLE protocol.
//!
//! \return
//! Returns \c true if supporting the BLE protocol, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_SupportsBLE( void )
{
   return (( ChipInfo_GetSupportedProtocol_BV() & PROTOCOLBIT_BLE ) != 0 );
}

//*****************************************************************************
//
//! \brief Returns true if the chip supports the IEEE 802.15.4 protocol.
//!
//! \return
//! Returns \c true if supporting the IEEE 802.15.4 protocol, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_SupportsIEEE_802_15_4( void )
{
   return (( ChipInfo_GetSupportedProtocol_BV() & PROTOCOLBIT_IEEE_802_15_4 ) != 0 );
}

//*****************************************************************************
//
//! \brief Returns true if the chip supports propriatary protocols.
//!
//! \return
//! Returns \c true if supporting propriatary protocols, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_SupportsPROPRIETARY( void )
{
   return (( ChipInfo_GetSupportedProtocol_BV() & PROTOCOLBIT_Proprietary ) != 0 );
}


//*****************************************************************************
//
//! \brief Package type enumeration
//
//*****************************************************************************
typedef enum {
   PACKAGE_Unknown   = -1, //!< -1 means that current chip type is unknown.
   PACKAGE_4x4       =  0, //!<  0 means that this is a 4x4mm chip.
   PACKAGE_5x5       =  1, //!<  1 means that this is a 5x5mm chip.
   PACKAGE_7x7       =  2  //!<  2 means that this is a 7x7mm chip.
} PackageType_t;

//*****************************************************************************
//
//! \brief Returns package type.
//!
//! \return
//! Returns \ref PackageType_t
//
//*****************************************************************************
extern PackageType_t ChipInfo_GetPackageType( void );

//*****************************************************************************
//
//! \brief Returns true if this is a 4x4mm chip.
//!
//! \return
//! Returns \c true if this is a 4x4mm chip, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_PackageTypeIs4x4( void )
{
   return ( ChipInfo_GetPackageType() == PACKAGE_4x4 );
}

//*****************************************************************************
//
//! \brief Returns true if this is a 5x5mm chip.
//!
//! \return
//! Returns \c true if this is a 5x5mm chip, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_PackageTypeIs5x5( void )
{
   return ( ChipInfo_GetPackageType() == PACKAGE_5x5 );
}

//*****************************************************************************
//
//! \brief Returns true if this is a 7x7mm chip.
//!
//! \return
//! Returns \c true if this is a 7x7mm chip, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_PackageTypeIs7x7( void )
{
   return ( ChipInfo_GetPackageType() == PACKAGE_7x7 );
}


//*****************************************************************************
//
//! \brief Returns the internal chip HW revision code.
//!
//! \return
//! Returns the internal chip HW revision code (in range 0-15)
//*****************************************************************************
__STATIC_INLINE uint32_t
ChipInfo_GetDeviceIdHwRevCode( void )
{
   // Returns HwRevCode = FCFG1_O_ICEPICK_DEVICE_ID[31:28]
   return ( HWREG( FCFG1_BASE + FCFG1_O_ICEPICK_DEVICE_ID ) >> 28 );
}

//*****************************************************************************
//
//! \brief Returns minor hardware revision number
//!
//! The minor revision number is set to 0 for the first market released chip
//! and thereafter incremented by 1 for each minor hardware change.
//!
//! \return
//! Returns the minor hardware revision number (in range 0-127)
//
//*****************************************************************************
__STATIC_INLINE uint32_t
ChipInfo_GetMinorHwRev( void )
{
   uint32_t minorRev = (( HWREG( FCFG1_BASE + FCFG1_O_MISC_CONF_1 ) &
                             FCFG1_MISC_CONF_1_DEVICE_MINOR_REV_M ) >>
                             FCFG1_MISC_CONF_1_DEVICE_MINOR_REV_S ) ;

   if ( minorRev >= 0x80 ) {
      minorRev = 0;
   }

   return( minorRev );
}


//*****************************************************************************
//
//! \brief Chip family enumeration
//
//*****************************************************************************
typedef enum {
   FAMILY_Unknown       = -1, //!< -1 means that the chip's family member is unknown.
   FAMILY_CC26xx        =  0, //!<  0 means that the chip is a CC26xx family member.
   FAMILY_CC13xx        =  1, //!<  1 means that the chip is a CC13xx family member.
   FAMILY_CC26xxLizard  =  2, //!<  2 means that the chip is a CC26xxLizard family member.
   FAMILY_CC26xxAgama   =  3  //!<  3 means that the chip is a CC26xxAgama family member.
} ChipFamily_t;

//*****************************************************************************
//
//! \brief Returns chip family member.
//!
//! \return
//! Returns \ref ChipFamily_t
//
//*****************************************************************************
extern ChipFamily_t ChipInfo_GetChipFamily( void );

//*****************************************************************************
//
//! \brief Returns true if this chip is member of the CC26xx family.
//!
//! \return
//! Returns \c true if this chip is member of the CC26xx family, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_ChipFamilyIsCC26xx( void )
{
   return ( ChipInfo_GetChipFamily() == FAMILY_CC26xx );
}

//*****************************************************************************
//
//! \brief Returns true if this chip is member of the CC13xx family.
//!
//! \return
//! Returns \c true if this chip is member of the CC13xx family, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_ChipFamilyIsCC13xx( void )
{
   return ( ChipInfo_GetChipFamily() == FAMILY_CC13xx );
}

//*****************************************************************************
//
//! \brief Returns true if this chip is member of the CC26xxLizard family.
//!
//! \return
//! Returns \c true if this chip is member of the CC26xxLizard family, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_ChipFamilyIsCC26xxLizard( void )
{
   return ( ChipInfo_GetChipFamily() == FAMILY_CC26xxLizard );
}

//*****************************************************************************
//
//! \brief Returns true if this chip is member of the CC26xxAgama family.
//!
//! \return
//! Returns \c true if this chip is member of the CC26xxAgama family, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_ChipFamilyIsCC26xxAgama( void )
{
   return ( ChipInfo_GetChipFamily() == FAMILY_CC26xxAgama );
}

//*****************************************************************************
//
//! \brief HW revision enumeration.
//
//*****************************************************************************
typedef enum {
   HWREV_Unknown     = -1, //!< -1 means that the chip's HW revision is unknown.
   HWREV_1_0         = 10, //!< 10 means that the chip's HW revision is 1.0
   HWREV_2_0         = 20, //!< 20 means that the chip's HW revision is 2.0
   HWREV_2_1         = 21, //!< 21 means that the chip's HW revision is 2.1
   HWREV_2_2         = 22, //!< 22 means that the chip's HW revision is 2.2
   HWREV_2_3         = 23  //!< 23 means that the chip's HW revision is 2.3
} HwRevision_t;

//*****************************************************************************
//
//! \brief Returns chip HW revision.
//!
//! \return
//! Returns \ref HwRevision_t
//
//*****************************************************************************
extern HwRevision_t ChipInfo_GetHwRevision( void );

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 1.0.
//!
//! \return
//! Returns \c true if HW revision for this chip is 1.0, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_1_0( void )
{
   return ( ChipInfo_GetHwRevision() == HWREV_1_0 );
}

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 2.0 or greater.
//!
//! \return
//! Returns \c true if HW revision for this chip is 2.0 or greater, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_GTEQ_2_0( void )
{
   return ( ChipInfo_GetHwRevision() >= HWREV_2_0 );
}

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 2.0.
//!
//! \return
//! Returns \c true if HW revision for this chip is 2.0, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_2_0( void )
{
   return ( ChipInfo_GetHwRevision() == HWREV_2_0 );
}

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 2.1.
//!
//! \return
//! Returns \c true if HW revision for this chip is 2.1, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_2_1( void )
{
   return ( ChipInfo_GetHwRevision() == HWREV_2_1 );
}

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 2.2.
//!
//! \return
//! Returns \c true if HW revision for this chip is 2.2, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_2_2( void )
{
   return ( ChipInfo_GetHwRevision() == HWREV_2_2 );
}

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 2.2 or greater.
//!
//! \return
//! Returns \c true if HW revision for this chip is 2.2 or greater, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_GTEQ_2_2( void )
{
   return ( ChipInfo_GetHwRevision() >= HWREV_2_2 );
}

//*****************************************************************************
//
//! \brief Returns true if HW revision for this chip is 2.3 or greater.
//!
//! \return
//! Returns \c true if HW revision for this chip is 2.3 or greater, \c false otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
ChipInfo_HwRevisionIs_GTEQ_2_3( void )
{
   return ( ChipInfo_GetHwRevision() >= HWREV_2_3 );
}


//*****************************************************************************
//
//! \brief Verifies that current chip is built for CC26xx HwRev 2.2 or later and never returns if violated.
//!
//! \return None
//
//*****************************************************************************
extern void ThisCodeIsBuiltForCC26xxHwRev22AndLater_HaltIfViolated( void );

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __CHIP_INFO_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//*****************************************************************************
