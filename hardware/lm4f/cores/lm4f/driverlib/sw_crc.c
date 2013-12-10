//*****************************************************************************
//
// sw_crc.c - Software CRC functions.
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

//*****************************************************************************
//
//! \addtogroup sw_crc_api
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include "driverlib/sw_crc.h"

//*****************************************************************************
//
// The CRC table for the polynomial C(x) = x^8 + x^2 + x + 1 (CRC-8-CCITT).
//
//*****************************************************************************
static const uint8_t g_pui8Crc8CCITT[256] =
{
    0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
    0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
    0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
    0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
    0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
    0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
    0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
    0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
    0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
    0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
    0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
    0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
    0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
    0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
    0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
    0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
    0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
    0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
    0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
    0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
    0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
    0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
    0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
    0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
    0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
    0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
    0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
    0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
    0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
    0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
    0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
    0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3
};

//*****************************************************************************
//
// The CRC-16 table for the polynomial C(x) = x^16 + x^15 + x^2 + 1 (standard
// CRC-16, also known as CRC-16-IBM and CRC-16-ANSI).
//
//*****************************************************************************
static const uint16_t g_pui16Crc16[256] =
{
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
    0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
    0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
    0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
    0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
    0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
    0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
    0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
    0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
    0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
    0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
    0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
    0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
    0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
    0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
    0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
    0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
    0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
    0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
    0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
    0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
    0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
    0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
    0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
    0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
    0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
    0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
    0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
    0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
    0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};

//*****************************************************************************
//
// The CRC-32 table for the polynomial C(x) = x^32 + x^26 + x^23 + x^22 +
// x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1 (standard
// CRC32 as used in Ethernet, MPEG-2, PNG, etc.).
//
//*****************************************************************************
static const uint32_t g_pui32Crc32[] =
{
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
    0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
    0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
    0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
    0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
    0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
    0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
    0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
    0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
    0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
    0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
    0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
    0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
    0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
    0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
    0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
    0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
    0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
    0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
    0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
    0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
    0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
    0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
    0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
    0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
    0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
    0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
    0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
    0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
    0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
    0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
    0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
    0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
    0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
    0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
    0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
    0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
    0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
    0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
    0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
    0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
    0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
    0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
};

//*****************************************************************************
//
// This macro executes one iteration of the CRC-8-CCITT.
//
//*****************************************************************************
#define CRC8_ITER(crc, data)    g_pui8Crc8CCITT[(uint8_t)((crc) ^ (data))]

//*****************************************************************************
//
// This macro executes one iteration of the CRC-16.
//
//*****************************************************************************
#define CRC16_ITER(crc, data)   (((crc) >> 8) ^                               \
                                 g_pui16Crc16[(uint8_t)((crc) ^ (data))])

//*****************************************************************************
//
// This macro executes one iteration of the CRC-32.
//
//*****************************************************************************
#define CRC32_ITER(crc, data)   (((crc) >> 8) ^                               \
                                 g_pui32Crc32[(uint8_t)((crc & 0xFF) ^        \
                                                        (data))])

//*****************************************************************************
//
//! Calculates the CRC-8-CCITT of an array of bytes.
//!
//! \param ui8Crc is the starting CRC-8-CCITT value.
//! \param pui8Data is a pointer to the data buffer.
//! \param ui32Count is the number of bytes in the data buffer.
//!
//! This function is used to calculate the CRC-8-CCITT of the input buffer.
//! The CRC-8-CCITT is computed in a running fashion, meaning that the entire
//! data block that is to have its CRC-8-CCITT computed does not need to be
//! supplied all at once.  If the input buffer contains the entire block of
//! data, then \b ui8Crc should be set to 0.  If, however, the entire block of
//! data is not available, then \b ui8Crc should be set to 0 for the first
//! portion of the data, and then the returned value should be passed back in
//! as \b ui8Crc for the next portion of the data.
//!
//! For example, to compute the CRC-8-CCITT of a block that has been split into
//! three pieces, use the following:
//!
//! \verbatim
//!     ui8Crc = Crc8CCITT(0, pui8Data1, ui32Len1);
//!     ui8Crc = Crc8CCITT(ui8Crc, pui8Data2, ui32Len2);
//!     ui8Crc = Crc8CCITT(ui8Crc, pui8Data3, ui32Len3);
//! \endverbatim
//!
//! Computing a CRC-8-CCITT in a running fashion is useful in cases where the
//! data is arriving via a serial link (for example) and is therefore not all
//! available at one time.
//!
//! \return The CRC-8-CCITT of the input data.
//
//*****************************************************************************
uint8_t
Crc8CCITT(uint8_t ui8Crc, const uint8_t *pui8Data, uint32_t ui32Count)
{
    uint32_t ui32Temp;

    //
    // If the data buffer is not 16 bit-aligned, then perform a single step of
    // the CRC to make it 16 bit-aligned.
    //
    if((uint32_t)pui8Data & 1)
    {
        //
        // Perform the CRC on this input byte.
        //
        ui8Crc = CRC8_ITER(ui8Crc, *pui8Data);

        //
        // Skip this input byte.
        //
        pui8Data++;
        ui32Count--;
    }

    //
    // If the data buffer is not word-aligned and there are at least two bytes
    // of data left, then perform two steps of the CRC to make it word-aligned.
    //
    if(((uint32_t)pui8Data & 2) && (ui32Count > 1))
    {
        //
        // Read the next 16 bits.
        //
        ui32Temp = *(uint16_t *)pui8Data;

        //
        // Perform the CRC on these two bytes.
        //
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp);
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp >> 8);

        //
        // Skip these input bytes.
        //
        pui8Data += 2;
        ui32Count -= 2;
    }

    //
    // While there is at least a word remaining in the data buffer, perform
    // four steps of the CRC to consume a word.
    //
    while(ui32Count > 3)
    {
        //
        // Read the next word.
        //
        ui32Temp = *(uint32_t *)pui8Data;

        //
        // Perform the CRC on these four bytes.
        //
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp);
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp >> 8);
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp >> 16);
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp >> 24);

        //
        // Skip these input bytes.
        //
        pui8Data += 4;
        ui32Count -= 4;
    }

    //
    // If there are 16 bits left in the input buffer, then perform two steps of
    // the CRC.
    //
    if(ui32Count > 1)
    {
        //
        // Read the 16 bits.
        //
        ui32Temp = *(uint16_t *)pui8Data;

        //
        // Perform the CRC on these two bytes.
        //
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp);
        ui8Crc = CRC8_ITER(ui8Crc, ui32Temp >> 8);

        //
        // Skip these input bytes.
        //
        pui8Data += 2;
        ui32Count -= 2;
    }

    //
    // If there is a final byte remaining in the input buffer, then perform a
    // single step of the CRC.
    //
    if(ui32Count != 0)
    {
        ui8Crc = CRC8_ITER(ui8Crc, *pui8Data);
    }

    //
    // Return the resulting CRC-8-CCITT value.
    //
    return(ui8Crc);
}

//*****************************************************************************
//
//! Calculates the CRC-16 of an array of bytes.
//!
//! \param ui16Crc is the starting CRC-16 value.
//! \param pui8Data is a pointer to the data buffer.
//! \param ui32Count is the number of bytes in the data buffer.
//!
//! This function is used to calculate the CRC-16 of the input buffer.  The
//! CRC-16 is computed in a running fashion, meaning that the entire data block
//! that is to have its CRC-16 computed does not need to be supplied all at
//! once.  If the input buffer contains the entire block of data, then
//! \b ui16Crc should be set to 0.  If, however, the entire block of data is
//! not available, then \b ui16Crc should be set to 0 for the first portion of
//! the data, and then the returned value should be passed back in as
//! \b ui16Crc for the next portion of the data.
//!
//! For example, to compute the CRC-16 of a block that has been split into
//! three pieces, use the following:
//!
//! \verbatim
//!     ui16Crc = Crc16(0, pui8Data1, ui32Len1);
//!     ui16Crc = Crc16(ui16Crc, pui8Data2, ui32Len2);
//!     ui16Crc = Crc16(ui16Crc, pui8Data3, ui32Len3);
//! \endverbatim
//!
//! Computing a CRC-16 in a running fashion is useful in cases where the data
//! is arriving via a serial link (for example) and is therefore not all
//! available at one time.
//!
//! \return The CRC-16 of the input data.
//
//*****************************************************************************
uint16_t
Crc16(uint16_t ui16Crc, const uint8_t *pui8Data, uint32_t ui32Count)
{
    uint32_t ui32Temp;

    //
    // If the data buffer is not 16 bit-aligned, then perform a single step of
    // the CRC to make it 16 bit-aligned.
    //
    if((uint32_t)pui8Data & 1)
    {
        //
        // Perform the CRC on this input byte.
        //
        ui16Crc = CRC16_ITER(ui16Crc, *pui8Data);

        //
        // Skip this input byte.
        //
        pui8Data++;
        ui32Count--;
    }

    //
    // If the data buffer is not word-aligned and there are at least two bytes
    // of data left, then perform two steps of the CRC to make it word-aligned.
    //
    if(((uint32_t)pui8Data & 2) && (ui32Count > 1))
    {
        //
        // Read the next 16 bits.
        //
        ui32Temp = *(uint16_t *)pui8Data;

        //
        // Perform the CRC on these two bytes.
        //
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 8);

        //
        // Skip these input bytes.
        //
        pui8Data += 2;
        ui32Count -= 2;
    }

    //
    // While there is at least a word remaining in the data buffer, perform
    // four steps of the CRC to consume a word.
    //
    while(ui32Count > 3)
    {
        //
        // Read the next word.
        //
        ui32Temp = *(uint32_t *)pui8Data;

        //
        // Perform the CRC on these four bytes.
        //
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 8);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 16);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 24);

        //
        // Skip these input bytes.
        //
        pui8Data += 4;
        ui32Count -= 4;
    }

    //
    // If there are two bytes left in the input buffer, then perform two steps
    // of the CRC.
    //
    if(ui32Count > 1)
    {
        //
        // Read the two bytes.
        //
        ui32Temp = *(uint16_t *)pui8Data;

        //
        // Perform the CRC on these two bytes.
        //
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 8);

        //
        // Skip these input bytes.
        //
        pui8Data += 2;
        ui32Count -= 2;
    }

    //
    // If there is a final byte remaining in the input buffer, then perform a
    // single step of the CRC.
    //
    if(ui32Count != 0)
    {
        ui16Crc = CRC16_ITER(ui16Crc, *pui8Data);
    }

    //
    // Return the resulting CRC-16 value.
    //
    return(ui16Crc);
}

//*****************************************************************************
//
//! Calculates the CRC-16 of an array of words.
//!
//! \param ui32WordLen is the length of the array in words (the number of bytes
//! divided by 4).
//! \param pui32Data is a pointer to the data buffer.
//!
//! This function is a wrapper around the running CRC-16 function, providing
//! the CRC-16 for a single block of data.
//!
//! \return The CRC-16 of the input data.
//
//*****************************************************************************
uint16_t
Crc16Array(uint32_t ui32WordLen, const uint32_t *pui32Data)
{
    //
    // Calculate and return the CRC-16 of this array of words.
    //
    return(Crc16(0, (const uint8_t *)pui32Data, ui32WordLen * 4));
}

//*****************************************************************************
//
//! Calculates three CRC-16s of an array of words.
//!
//! \param ui32WordLen is the length of the array in words (the number of bytes
//! divided by 4).
//! \param pui32Data is a pointer to the data buffer.
//! \param pui16Crc3 is a pointer to an array in which to place the three
//! CRC-16 values.
//!
//! This function is used to calculate three CRC-16s of the input buffer; the
//! first uses every byte from the array, the second uses only the even-index
//! bytes from the array (in other words, bytes 0, 2, 4, etc.), and the third
//! uses only the odd-index bytes from the array (in other words, bytes 1, 3,
//! 5, etc.).
//!
//! \return None
//
//*****************************************************************************
void
Crc16Array3(uint32_t ui32WordLen, const uint32_t *pui32Data,
            uint16_t *pui16Crc3)
{
    uint16_t ui16Crc, ui16Cri8Odd, ui16Cri8Even;
    uint32_t ui32Temp;

    //
    // Initialize the CRC values to zero.
    //
    ui16Crc = 0;
    ui16Cri8Odd = 0;
    ui16Cri8Even = 0;

    //
    // Loop while there are more words in the data buffer.
    //
    while(ui32WordLen--)
    {
        //
        // Read the next word.
        //
        ui32Temp = *pui32Data++;

        //
        // Perform the first CRC on all four data bytes.
        //
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 8);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 16);
        ui16Crc = CRC16_ITER(ui16Crc, ui32Temp >> 24);

        //
        // Perform the second CRC on only the even-index data bytes.
        //
        ui16Cri8Even = CRC16_ITER(ui16Cri8Even, ui32Temp);
        ui16Cri8Even = CRC16_ITER(ui16Cri8Even, ui32Temp >> 16);

        //
        // Perform the third CRC on only the odd-index data bytes.
        //
        ui16Cri8Odd = CRC16_ITER(ui16Cri8Odd, ui32Temp >> 8);
        ui16Cri8Odd = CRC16_ITER(ui16Cri8Odd, ui32Temp >> 24);
    }

    //
    // Return the resulting CRC-16 values.
    //
    pui16Crc3[0] = ui16Crc;
    pui16Crc3[1] = ui16Cri8Even;
    pui16Crc3[2] = ui16Cri8Odd;
}

//*****************************************************************************
//
//! Calculates the CRC-32 of an array of bytes.
//!
//! \param ui32Crc is the starting CRC-32 value.
//! \param pui8Data is a pointer to the data buffer.
//! \param ui32Count is the number of bytes in the data buffer.
//!
//! This function is used to calculate the CRC-32 of the input buffer.  The
//! CRC-32 is computed in a running fashion, meaning that the entire data block
//! that is to have its CRC-32 computed does not need to be supplied all at
//! once.  If the input buffer contains the entire block of data, then
//! \b ui32Crc should be set to 0xFFFFFFFF.  If, however, the entire block of
//! data is not available, then \b ui32Crc should be set to 0xFFFFFFFF for the
//! first portion of the data, and then the returned value should be passed
//! back in as \b ui32Crc for the next portion of the data.  Once all data has
//! been passed to the function, the final CRC-32 can be obtained by inverting
//! the last returned value.
//!
//! For example, to compute the CRC-32 of a block that has been split into
//! three pieces, use the following:
//!
//! \verbatim
//!     ui32Crc = Crc32(0xFFFFFFFF, pui8Data1, ui32Len1);
//!     ui32Crc = Crc32(ui32Crc, pui8Data2, ui32Len2);
//!     ui32Crc = Crc32(ui32Crc, pui8Data3, ui32Len3);
//!     ui32Crc ^= 0xFFFFFFFF;
//! \endverbatim
//!
//! Computing a CRC-32 in a running fashion is useful in cases where the data
//! is arriving via a serial link (for example) and is therefore not all
//! available at one time.
//!
//! \return The accumulated CRC-32 of the input data.
//
//*****************************************************************************
uint32_t
Crc32(uint32_t ui32Crc, const uint8_t *pui8Data, uint32_t ui32Count)
{
    uint32_t ui32Temp;

    //
    // If the data buffer is not 16 bit-aligned, then perform a single step
    // of the CRC to make it 16 bit-aligned.
    //
    if((uint32_t)pui8Data & 1)
    {
        //
        // Perform the CRC on this input byte.
        //
        ui32Crc = CRC32_ITER(ui32Crc, *pui8Data);

        //
        // Skip this input byte.
        //
        pui8Data++;
        ui32Count--;
    }

    //
    // If the data buffer is not word-aligned and there are at least two bytes
    // of data left, then perform two steps of the CRC to make it word-aligned.
    //
    if(((uint32_t)pui8Data & 2) && (ui32Count > 1))
    {
        //
        // Read the next int16_t.
        //
        ui32Temp = *(uint16_t *)pui8Data;

        //
        // Perform the CRC on these two bytes.
        //
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp);
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp >> 8);

        //
        // Skip these input bytes.
        //
        pui8Data += 2;
        ui32Count -= 2;
    }

    //
    // While there is at least a word remaining in the data buffer, perform
    // four steps of the CRC to consume a word.
    //
    while(ui32Count > 3)
    {
        //
        // Read the next word.
        //
        ui32Temp = *(uint32_t *)pui8Data;

        //
        // Perform the CRC on these four bytes.
        //
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp);
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp >> 8);
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp >> 16);
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp >> 24);

        //
        // Skip these input bytes.
        //
        pui8Data += 4;
        ui32Count -= 4;
    }

    //
    // If there are 16 bits left in the input buffer, then perform two steps of
    // the CRC.
    //
    if(ui32Count > 1)
    {
        //
        // Read the two bytes.
        //
        ui32Temp = *(uint16_t *)pui8Data;

        //
        // Perform the CRC on these two bytes.
        //
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp);
        ui32Crc = CRC32_ITER(ui32Crc, ui32Temp >> 8);

        //
        // Skip these input bytes.
        //
        pui8Data += 2;
        ui32Count -= 2;
    }

    //
    // If there is a final byte remaining in the input buffer, then perform a
    // single step of the CRC.
    //
    if(ui32Count != 0)
    {
        ui32Crc = CRC32_ITER(ui32Crc, *pui8Data);
    }

    //
    // Return the resulting CRC-32 value.
    //
    return(ui32Crc);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
