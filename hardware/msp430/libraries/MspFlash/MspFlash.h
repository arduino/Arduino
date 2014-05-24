/*
  MspFlash.h - Read/Write flash memory library for MSP430 Energia 
  Copyright (c) 2012 Peter Brier.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Provide access to the MSP430 flash memory controller. 
  All flash memory can be read, erased and written (except SEGMENT_A, the LOCK bits are not in the code, for a good reason).
  Flash can only be erased per 512 byte segments (except the 4 special information segments, they are 64 bytes in size)
  
  The same flash locations can be written multiple times with new values, but flash bits can only be reset (from 1 to 0) and cannot
  change to a 1 (you need to flash erase the whole segment)

  functions:
  ~~~~~~~~~~
  erase():  Erase a flash segment, all bytes in the segment will read 0xFF after an erase
 
  read(): Read flash locations (actually just a proxy for memcpy)
 
  write(): Write flash locations (actually just a proxy for memcpy), the same location can be written multiple times, 
  but once a bit is reset, you cannot set it with a subsequent write, you need to flash the complete segment to do so.  
  
  NOTE: you are flashing the program memory, you can modify EVERYTHING (program and data) this is usually not what you want. 
  Be carefull when flashing data. You may use SEG_B to SEG_D for normal use, they should not be filled by the compiler with code
  or static data. If you wish to use main memory without wasting any space, you need to inform the linker NOT to use the required 
  segments. This is done in the linker script (this is not for the faint of heart). 
  
  An alternative approach is to allocate a static variable with a size of AT LEAST 2 SEGMENTS in your program. 
  This makes sure there is at least ONE COMPLETE SEGMENT in this static variable, so there is no colleteral damage when you flash this
  area. You need to find the pointer to the start of the next segment. There is a macro define to do this: SEGPTR(x)
  A example that makes 2 segments available for flashing by allocating 3 segments of constant data:
  
  static const unsigned char flash[3*512] = {0};
  
  Flash segments:     |...SEGMENT-0...|...SEGMENT-1...|...SEGMENT-2...|...SEGMENT-3...|...SEGMENT-4...|...SEGMENT-5...|
  Program output:     |Program code.......|flash[3*512***********************************]|Other data.................|
  Available segments: |-------------------------------|+++++++++++++++|+++++++++++++++|-------------------------------|  
  
  
*/

#include <Energia.h>

#ifndef MSP_FLASH_h
#define MSP_FLASH_h

#define SEGMENT_SIZE 512 // main segment size (smallest flasheable area)
#ifdef __MSP430_HAS_FLASH2__
#define INFO_SIZE 64 // information flah sizes (SEG_A to SEG_D)
#else
#define INFO_SIZE 128 // information flah sizes (SEG_A to SEG_D)
#endif

#ifdef __MSP430_HAS_FLASH2__
// segment addresses of 64 byte segments
#define SEGMENT_D ((unsigned char*)0x1000)
#define SEGMENT_C ((unsigned char*)0x1000+64)
#define SEGMENT_B ((unsigned char*)0x1000+128)
// #define SEGMENT_A ((unsigned char*)0x1000+192) // NOTE: Contains chip calibarion data, do not change or erase (the protection bit should prevent this happening)
#else
#define SEGMENT_D ((unsigned char*)0x1800)
#define SEGMENT_C ((unsigned char*)0x1800+128)
#define SEGMENT_B ((unsigned char*)0x1800+256)
// #define SEGMENT_A ((unsigned char*)0x1800+348) // NOTE: Contains chip calibarion data, do not change or erase (the protection bit should prevent this happening)
#endif

// Segment start addresses of 512 byte segments 0..63 (depending on device flash size)
#define SEGMENT(x) ( (unsigned char*) 0xFFFF - (x)*SEG_SIZE )

// return segment pointer inside variable. Note: return start of NEXT segment
#define SEGPTR(x) ( (unsigned char *) (((unsigned short)(&x)+512) & 0xFE00) )

class MspFlashClass
{
  public:
    void erase(unsigned char *flash); 
    void read(unsigned char *flash, unsigned char *dest, int len);
    void write(unsigned char *flash, unsigned char *src, int len);
};

extern MspFlashClass Flash;

#endif // MSP_FLASH_h

