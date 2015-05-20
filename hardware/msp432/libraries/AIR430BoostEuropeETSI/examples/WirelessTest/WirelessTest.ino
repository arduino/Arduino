/**
 *  ----------------------------------------------------------------------------
 *  WirelessTest.ino - test transceiver sketch using AIR430Boost ETSI driver.
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
 *  Each radio will send a message consisting of: 1 byte counter, 5 byte static 
 *  text. The counter will count from 0 to 9 and will rollover. Each radio will 
 *  wait in receive mode for approximately one second. Upon receiving data, or 
 *  timeout of one second, the radio receive function will return. If valid data 
 *  was received, the radio's receiverOn() method will return the number of bytes
 *  that were received. In this example, the data can be monitored on the serial 
 *  port (please refer to printTxData() and printRxData() functions).
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
 *  AIR430BoostETSI library. Refer to the BoosterPack User's Manual if necessary.
 *
 *  ETSI regulations must be followed when using this library. This example 
 *  limits the wireless duty cycle to 0.1% per ETSI.
 *
 *  For complete information, please refer to the BoosterPack User's Manual 
 *  available at:
 *  https://www.anaren.com/air/cc110l-air-module-boosterpack-embedded-antenna-module-anaren
 *  
 *  To purchase the 430Boost-CC110L AIR module BoosterPack kit, please visit the 
 *  TI eStore at:
 *  https://estore.ti.com/430BOOST-CC110L-CC110L-RF-Module-BoosterPack-P2734.aspx
 */

// The AIR430BoostETSI library uses the SPI library internally. Energia does not
// copy the library to the output folder unless it is referenced here.
// The order of includes is also important due to this fact.
#include <SPI.h>
#include <AIR430BoostETSI.h>

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// Data to write to radio TX FIFO (60 bytes MAX.)
unsigned char txData[6] = { 0x30, 'A', 'i', 'r', '!', '\0' };

// Data to read from radio RX FIFO (60 bytes MAX.)
unsigned char rxData[6] = { '\0', '\0', '\0', '\0', '\0', '\0' };

// -----------------------------------------------------------------------------
// Debug print functions

void printTxData()
{
  Serial.print("TX (DATA): ");
  Serial.println((char*)txData); 
}

void printRxData()
{
  /**
   *  The following illustrates various information that can be obtained when
   *  receiving a message. This includes: the received data and associated 
   *  status information (RSSI, LQI, and CRC_OK bit).
   */
  Serial.print("RX (DATA, RSSI, LQI, CRCBIT): ");
  Serial.print("(");
  Serial.print((char*)rxData);
  Serial.print(", ");
  Serial.print(Radio.getRssi());
  Serial.print(", ");
  Serial.print(Radio.getLqi());
  Serial.print(", ");
  Serial.print(Radio.getCrcBit());
  Serial.println(")");
}

// -----------------------------------------------------------------------------
// Main example

void setup()
{
  // The radio library uses the SPI library internally, this call initializes
  // SPI/CSn and GDO0 lines. Also setup initial address, channel, and TX power.
  Radio.begin(0x01, CHANNEL_1, POWER_MAX);

  // Setup serial for debug printing.
  Serial.begin(9600);
  
  /**
   *  Setup LED for example demonstration purposes.
   *
   *  Note: Set radio first to ensure that GDO2 line isn't being driven by the 
   *  MCU as it is an output from the radio.
   */
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);   // set the LED on
}

void loop()
{
  // Load the txData into the radio TX FIFO and transmit it to the broadcast
  // address.
  Radio.transmit(ADDRESS_BROADCAST, txData, 6);
  printTxData();                    // TX debug information
  
  // Increment tx data sequence number ('0'-'9' ASCII) for next transmission.
  if (txData[0] >= '0' && txData[0] < '9')
  {
    txData[0]++;
  }
  else
  {
    txData[0] = '0';
  }
  
  /**
   *  The radio transmitter and receiver cannot be operated at the same time.
   *  Wait until transmit completes before turning on the receiver. Please note
   *  that the radio is considered busy when it is transmitting.
   *
   *  WARNING: If busy is not checked between two successive radio operations
   *  receiverOn/transmit, the radio may not perform the specified task. The
   *  radio must be complete with the transmission before it can begin the next
   */
  while (Radio.busy());
  
  // Turn on the receiver and listen for incoming data. Timeout after 1 seconds.
  // The receiverOn() method returns the number of bytes copied to rxData.
  if (Radio.receiverOn(rxData, sizeof(rxData), 1000) > 0)
  {
    /**
     *  Data has been received and has been copied to the rxData buffer provided
     *  to the receiverOn() method. At this point, rxData is available. See
     *  printRxData() for more information.
     */
    digitalWrite(RED_LED, HIGH);
    printRxData();                  // RX debug information
  }
  digitalWrite(RED_LED, LOW);
  
  /**
   *  Warning: ETSI regulations require duty cycling of 0.1% per hour. Changing this
   *  may invalidate ETSI compliance. Some margin has been added. Please refer to
   *  Anaren's A110LR09 User's Manual for more information.
   */
  delay(500);
}
