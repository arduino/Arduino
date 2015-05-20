/**
 *  ----------------------------------------------------------------------------
 *  A110x2500Radio.cpp - AIR430Boost A110x2500 radio implementation.
 *  Copyright (C) 2012-2013 Anaren Microwave, Inc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 * 
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 * 
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 *  This example demonstrates usage of the AIR430BoostETSI library which uses
 *  the 430Boost-CC110L AIR Module BoosterPack created by Anaren Microwave, Inc.
 *  and available through the TI eStore, for the European Union.
 *  ----------------------------------------------------------------------------
 *
 *  Note: This file is part of AIR430Boost.
 */
#include <Energia.h>
#include "A110x2500Radio.h"
#include "Platform.h"     // 430Boost-CC110L and EXP430G2 Launchpad support

extern "C" { 
  #include "A110LR09.h"   // Module driver
}

// ----------------------------------------------------------------------------
// CC110L device driver

const struct sCC1101Spi gSpi = { 
  A110x2500SpiInit, 
  A110x2500SpiRead, 
  A110x2500SpiWrite 
};
const struct sCC1101Gdo gGdo0 = {
  A110x2500Gdo0Init,
  NULL,    // Not used
  NULL,    // Not used
  NULL,    // Not used
  NULL,    // Not used
  NULL     // Not used
};
const struct sCC1101Gdo *gGdo[3] = { &gGdo0, NULL, NULL };

// ----------------------------------------------------------------------------
// A110LR09 module driver

static struct sA110LR09PhyInfo gPhyInfo;

static volatile boolean gDataTransmitting = false;
static volatile boolean gDataReceived = false;
A110x2500Radio Radio;

// ----------------------------------------------------------------------------
/**
 *  Public interface
 */

void A110x2500Radio::begin(uint8_t address, channel_t channel, power_t power)
{
  gDataTransmitting = false;
  gDataReceived = false;
  
  // Configure the radio and set the default address, channel, and TX power.
  A110LR09Init(&gPhyInfo, &gSpi, gGdo);
  setAddress(address);
  setChannel(channel);
  setPower(power);

  attachInterrupt(RF_GDO0, gdo0Isr, FALLING);
  sleep();
}

void A110x2500Radio::end()
{
  // Wait until all operations complete.
  while (busy());

  detachInterrupt(RF_GDO0);
  pinMode (RF_SPI_CSN, INPUT);
}

boolean A110x2500Radio::busy()
{
  if (gDataTransmitting)
  {
    return true;
  }
  return false;
}

void A110x2500Radio::setAddress(uint8_t address)
{
  struct sA110LR09PhyInfo *phyInfo = &gPhyInfo;
  A110LR09SetAddr(phyInfo, address);
}

void A110x2500Radio::setChannel(channel_t channel)
{
  struct sA110LR09PhyInfo *phyInfo = &gPhyInfo;
  A110LR09SetChannr(phyInfo, channel);
}

void A110x2500Radio::setPower(power_t power)
{
  unsigned char paTable[A110LR09_PA_TABLE_SIZE];
  memset(paTable, power, A110LR09_PA_TABLE_SIZE);
  A110LR09SetPaTable(&gPhyInfo, paTable);
}

int8_t A110x2500Radio::getRssi()
{
  int8_t rssi = Radio._dataStream.rssi;
  Radio._dataStream.rssi = (int16_t)(A110LR09ConvertRssiToDbm(&gPhyInfo, rssi) + 1) >> 1;
  return Radio._dataStream.rssi;
}

uint8_t A110x2500Radio::getLqi()
{
  return (Radio._dataStream.status & 0x7F);
}

uint8_t A110x2500Radio::getCrcBit()
{
  return ((Radio._dataStream.status & 0x80) >> 7);
}

void A110x2500Radio::transmit(uint8_t address,
															uint8_t *dataField,
															uint8_t length)
{
  if (!busy())
  {
    // Bring the radio out of a low power state.
    wakeup();
    
    // Set the transmit buffer.
    Radio._dataStream.length = 0;
    Radio._dataStream.address = 0;
    Radio._dataStream.dataField = dataField;

    // Build and transmit a data stream.
    CC1101Idle(&gPhyInfo.cc1101);
    buildDataStream(address, Radio._dataStream.dataField, length);
    CC1101Transmit(&gPhyInfo.cc1101);
    gDataTransmitting = true;
  }
}

unsigned char A110x2500Radio::receiverOn(uint8_t *dataField,
																				 uint8_t length,
																				 uint16_t timeout)
{
  if (!busy())
  {
    // Bring the radio out of a low power state.
    wakeup();
    
    // Set the receive buffer.
    Radio._dataStream.length = 0;
    Radio._dataStream.address = 0;
    Radio._dataStream.dataField = dataField;

    // Listen for a data stream.
    CC1101Idle(&gPhyInfo.cc1101);
    CC1101FlushRxFifo(&gPhyInfo.cc1101);
    CC1101ReceiverOn(&gPhyInfo.cc1101);
    
    // Listen for a period of time.
    if (timeout == 0)
    {
      // Listen forever until a message is received.
      while (!gDataReceived);
      gDataReceived = false;
      return Radio._dataStream.length;
    }
    else
    {
      // Listen for at most the timeout period or until a message is received.
      while (timeout-- > 0)
      {
        delay(1);
        if (gDataReceived)
        {
          gDataReceived = false;
          return Radio._dataStream.length;
        }
      }
    }
  }
  
  return 0;    // No data stream received
}

// ----------------------------------------------------------------------------
/**
 *  Private interface
 */

void A110x2500Radio::wakeup()
{
  struct sA110LR09PhyInfo *phyInfo = &gPhyInfo;
  
  // Wakeup and write registers that aren't retained in low power mode.
  A110LR09Wakeup(phyInfo);
}

void A110x2500Radio::sleep()
{
  CC1101Sleep(&gPhyInfo.cc1101);
}

void A110x2500Radio::buildDataStream(uint8_t address, 
                                     uint8_t *dataField, 
                                     uint8_t length)
{
  /**
   *  Note: The length of the data stream is the address and the data field. 
   *  Length does not include itself into the total! The address is required
   *  as this physical implementation uses this for filtering. The broadcast
   *  addresse may be used at any time (0x00).
   */
  Radio._dataStream.length = length + 1;  // Include address
  Radio._dataStream.address = address;
  Radio._dataStream.dataField = dataField;

  // Flush the TX FIFO before writing any new data to it.
  CC1101FlushTxFifo(&gPhyInfo.cc1101);

  // Write the length field to the TX FIFO.
  CC1101WriteTxFifo(&gPhyInfo.cc1101, &Radio._dataStream.length, 1);
                    
  // Write the address field to the TX FIFO.
  CC1101WriteTxFifo(&gPhyInfo.cc1101, &Radio._dataStream.address, 1);
                    
  // Write the data field to the TX FIFO.
  CC1101WriteTxFifo(&gPhyInfo.cc1101,
                    Radio._dataStream.dataField,
                    Radio._dataStream.length);
}

void A110x2500Radio::readDataStream(void)
{
  unsigned char rxBytes = CC1101ReadRxFifo(&gPhyInfo.cc1101, 
                                           &Radio._dataStream.length, 
                                           1);
  
  // Check if the RX FIFO has any data in it. If not, exit early as the RX FIFO
  // does not have any useful data in it. A bogus interrupt has occurred.
  if (rxBytes > 0)
  {
    // Read the address.
    CC1101ReadRxFifo(&gPhyInfo.cc1101, &Radio._dataStream.address, 1);
    
    // Read the data field.
    CC1101ReadRxFifo(&gPhyInfo.cc1101, 
                     Radio._dataStream.dataField, 
                     Radio._dataStream.length-1);

		// Read the RSSI and CRC/LQI status.
    CC1101ReadRxFifo(&gPhyInfo.cc1101, (unsigned char*)&Radio._dataStream.rssi, 2);
  }
  else
  {
    Radio._dataStream.length = 0;
  }
}

void A110x2500Radio::gdo0Isr()
{
  // Note: It is assumed that interrupts are disabled.
  
  // The GDO0 ISR will only look for the EOP edge. Therefore, if the radio
  // is not transmitting the EOP, it must be receiving an EOP signal.
  if (gDataTransmitting)
  {
    /**
     *  Note: GDO0 is issued prior to the transmitter being completely
     *  finished. The state machine will remain in TX_END until transmission
     *  completes. The following waits for TX_END to correct the hardware
     *  behavior.
     */ 
    while (CC1101GetMarcState(&gPhyInfo.cc1101) == eCC1101MarcStateTx_end);
    gDataTransmitting = false;
  }
  else
  {
    gDataReceived = true;
    readDataStream();
  }
  
  // Always go back to sleep.
  sleep();
}
