/**
 *  ----------------------------------------------------------------------------
 *  WirelessMonitorHub.ino - wireless monitor hub sketch using AIR430Boost FCC driver.
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
 *  This example demonstrates usage of the AIR430BoostFCC library which uses
 *  the 430Boost-CC110L AIR Module BoosterPack created by Anaren Microwave, Inc.
 *  and available through the TI eStore, for the European Union.
 *
 *  ----------------------------------------------------------------------------
 *
 *  Note: This file is part of AIR430Boost.
 *
 *  ----------------------------------------------------------------------------
 *
 *  Description
 *  ===========
 *
 *  Acts as a simple receiver for a star network. The hub node can receive both
 *  broadcast messages and messages directed to its assigned address. The hub
 *  node should not be assigned to address 0 (broadcast address). To create an
 *  additional network, simply change the hub address.
 *
 *  ----------------------------------------------------------------------------
 * 
 *  This example assumes that two BoosterPacks will be used to showcase the 
 *  wireless radio communication functionality. This same code should be 
 *  programmed to both LaunchPad development kits.
 *
 *  This BoosterPack relies on the SPI hardware peripheral and two additional 
 *  GPIO lines for SPI chip-select and GDO0 for packet handling. They use pins 18 
 *  and 19 respectively. 
 *
 *  In the default configuration, this BoosterPack is not compatible with an 
 *  external crystal oscillator. This can be changed, if necessary, and would
 *  require reconfiguration of the BoosterPack hardware and changes to the 
 *  AIR430BoostFCC library. Refer to the BoosterPack User's Manual if necessary.
 *
 *  For complete information, please refer to the BoosterPack User's Manual 
 *  available at:
 *  https://www.anaren.com/air/cc110l-air-module-boosterpack-embedded-antenna-module-anaren
 *  
 *  To purchase the 430Boost-CC110L AIR module BoosterPack kit, please visit the 
 *  TI eStore at:
 *  https://estore.ti.com/430BOOST-CC110L-CC110L-RF-Module-BoosterPack-P2734.aspx
 */

/**
 *  The AIR430BoostFCC library uses the SPI library internally. Energia does not
 *  copy the library to the output folder unless it is referenced here. The order 
 *  of includes is also important due to this fact.
 */
#include <SPI.h>
#include <AIR430BoostFCC.h>

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

#define ADDRESS_LOCAL    0x01

/**
 *  sPacket - packet format.
 */
struct sPacket
{
  uint8_t from;           // Local node address that message originated from
  uint8_t message[59];    // Local node message [MAX. 59 bytes]
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

struct sPacket rxPacket;

// -----------------------------------------------------------------------------
// Main example

void setup()
{
  // The radio library uses the SPI library internally, this call initializes
  // SPI/CSn and GDO0 lines. Also setup initial address, channel, and TX power.
  Radio.begin(ADDRESS_LOCAL, CHANNEL_1, POWER_MAX);

  rxPacket.from = 0;
  memset(rxPacket.message, 0, sizeof(rxPacket.message));

  // Setup serial for debug printing.
  Serial.begin(9600);

  /**
   *  Setup LED for example demonstration purposes.
   *
   *  Note: Set radio first to ensure that GDO2 line isn't being driven by the 
   *  MCU as it is an output from the radio.
   */
  pinMode(RED_LED, OUTPUT);       // Use red LED to display message reception
  digitalWrite(RED_LED, LOW);
}

void loop()
{
  // Turn on the receiver and listen for incoming data. Timeout after 1 seconds.
  // The receiverOn() method returns the number of bytes copied to rxData.
  if (Radio.receiverOn((unsigned char*)&rxPacket, sizeof(rxPacket), 1000) > 0)
  {
    digitalWrite(RED_LED, HIGH);
    Serial.print("FROM: ");
    Serial.print(rxPacket.from);
    Serial.print(" MSG: ");
    Serial.println((char*)rxPacket.message);
		digitalWrite(RED_LED, LOW);
  }
}
