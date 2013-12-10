// TI File $Revision: /main/1 $
// Checkin $Date: August 13, 2012   15:28:49 $
//###########################################################################
//
// FILE:    Shared_Boot.c
//
// TITLE:   Boot loader shared functions
//
// Functions:
//
//     void   CopyData(void)
//     Uint32 GetLongData(void)
//     void ReadReservedFn(void)
//
//###########################################################################
// $TI Release: 2802x Boot ROM V2.00 $
// $Release Date: December 10, 2009 $
//###########################################################################


#include "Boot.h"
#include "Flash2802x_API_Library.h"

//#pragma    DATA_SECTION(EmuKey,"EmuKeyVar");
//#pragma    DATA_SECTION(EmuBMode,"EmuBModeVar");
//Uint16     EmuKey;
//Uint16     EmuBMode;

// GetWordData is a pointer to the function that interfaces to the peripheral.
// Each loader assigns this pointer to it's particular GetWordData function.
uint16fptr GetOnlyWordData;

// Function prototypes
Uint32 GetLongData();
//void   CopyData(void);
void ReadReservedFn(void);
//After flash_program, send checksum to PC
void SendCheckSum();

#pragma CODE_SECTION(CopyData, "ramfuncs");
//Programming Buffer
Uint16 progBuf[PROG_BUFFER_LENGTH];
//Flash Status Structure
FLASH_ST FlashStatus;

extern Uint32 Flash_CPUScaleFactor;
extern void (*Flash_CallbackPtr) (void);
unsigned int checksum;

//#################################################
// void CopyData(void)
//-----------------------------------------------------
// This routine copies multiple blocks of data from the host
// to the specified RAM locations.  There is no error
// checking on any of the destination addresses.
// That is it is assumed all addresses and block size
// values are correct.
//
// Multiple blocks of data are copied until a block
// size of 00 00 is encountered.
//
//-----------------------------------------------------

void CopyData()
{

   struct HEADER {
     Uint16 BlockSize;
     Uint32 DestAddr;
     Uint32 ProgBuffAddr;
   } BlockHeader;

   Uint16 wordData;
   Uint16 status;
   Uint16 i,j;

   //Make sure code security is disabled
   CsmUnlock();

   EALLOW;
   Flash_CPUScaleFactor = SCALE_FACTOR;
   Flash_CallbackPtr = NULL;
   EDIS;

   status = Flash_Erase((SECTORA | SECTORB | SECTORC | SECTORD), &FlashStatus);
   if(status != STATUS_SUCCESS)
   {
	   //TODO fix so that it returns a serial error and reboot device
       return;
   }

   // After Flash Erase, send the checksum to PC program.
   SendCheckSum();
   // Get the size in words of the first block
   BlockHeader.BlockSize = (*GetOnlyWordData)();

   // While the block size is > 0 copy the data
   // to the DestAddr.  There is no error checking
   // as it is assumed the DestAddr is a valid
   // memory location

   while(BlockHeader.BlockSize != (Uint16)0x0000)
   {

	  if(BlockHeader.BlockSize > PROG_BUFFER_LENGTH){
		  //Block is to big to fit into our buffer so we must program it in chunks
	      BlockHeader.DestAddr = GetLongData();
	      //Program as many full buffers as possible
	      for(j = 0; j < (BlockHeader.BlockSize / PROG_BUFFER_LENGTH); j++){
		      BlockHeader.ProgBuffAddr = (Uint32)progBuf;
		      for(i = 1; i <= PROG_BUFFER_LENGTH; i++)
		      {
		          wordData = (*GetOnlyWordData)();
		          *(Uint16 *)BlockHeader.ProgBuffAddr++ = wordData;
		      }
		      status = Flash_Program((Uint16 *) BlockHeader.DestAddr, (Uint16 *)progBuf, PROG_BUFFER_LENGTH, &FlashStatus);
		      if(status != STATUS_SUCCESS)
		      {
		          return;
		      }
		      BlockHeader.DestAddr += PROG_BUFFER_LENGTH;
		      // After Flash program, send the checksum to PC program.
		      SendCheckSum();
	      }
	      //Program the leftovers
	      BlockHeader.ProgBuffAddr = (Uint32)progBuf;
	      for(i = 1; i <= (BlockHeader.BlockSize % PROG_BUFFER_LENGTH); i++)
	      {
	          wordData = (*GetOnlyWordData)();
	          *(Uint16 *)BlockHeader.ProgBuffAddr++ = wordData;
	      }
	      status = Flash_Program((Uint16 *) BlockHeader.DestAddr, (Uint16 *)progBuf, (BlockHeader.BlockSize % PROG_BUFFER_LENGTH), &FlashStatus);
	      if(status != STATUS_SUCCESS)
	      {
	          return;
	      }
	      // After Flash program, send the checksum to PC program.
	      SendCheckSum();
	  }else{
		  //Block will fit into our buffer so we'll program it all at once
	      BlockHeader.DestAddr = GetLongData();
	      BlockHeader.ProgBuffAddr = (Uint32)progBuf;
	      for(i = 1; i <= BlockHeader.BlockSize; i++)
	      {
	          wordData = (*GetOnlyWordData)();
	          *(Uint16 *)BlockHeader.ProgBuffAddr++ = wordData;
	      }
	      status = Flash_Program((Uint16 *) BlockHeader.DestAddr, (Uint16 *)progBuf, BlockHeader.BlockSize, &FlashStatus);
	      if(status != STATUS_SUCCESS)
	      {
	          return;
	      }
	      // After Flash program, send the checksum to PC program.
	      SendCheckSum();
	  }



      // Get the size of the next block
      BlockHeader.BlockSize = (*GetOnlyWordData)();
   }
   return;
}

//#################################################
// Uint32 GetLongData(void)
//-----------------------------------------------------
// This routine fetches a 32-bit value from the peripheral
// input stream.
//-----------------------------------------------------

Uint32 GetLongData()
{
    Uint32 longData;

    // Fetch the upper 1/2 of the 32-bit value
    longData = ( (Uint32)(*GetOnlyWordData)() << 16);

    // Fetch the lower 1/2 of the 32-bit value
    longData |= (Uint32)(*GetOnlyWordData)();

    return longData;
}

//#################################################
// void Read_ReservedFn(void)
//-------------------------------------------------
// This function reads 8 reserved words in the header.
// None of these reserved words are used by the
// this boot loader at this time, they may be used in
// future devices for enhancements.  Loaders that use
// these words use their own read function.
//-------------------------------------------------

void ReadReservedFn()
{
    Uint16 i;
    // Read and discard the 8 reserved words.
    for(i = 1; i <= 8; i++)
    {
    	GetOnlyWordData();
    }
    return;
}

//#################################################
// void SendCheckSum(void)
//-----------------------------------------------------
// This function sends checksum to PC program
// After flash memory erases or writes something, this functions will be running
//-----------------------------------------------------
void SendCheckSum()
{
	while(!SciaRegs.SCICTL2.bit.TXRDY)
	{
	}
	SciaRegs.SCITXBUF = checksum & 0xFF;

	while(!SciaRegs.SCICTL2.bit.TXRDY)
	{
	}
	SciaRegs.SCITXBUF = (checksum >> 8) & 0xFF;

	checksum = 0;

   return;
}
