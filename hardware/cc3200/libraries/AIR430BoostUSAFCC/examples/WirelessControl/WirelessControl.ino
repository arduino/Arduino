/**
 *  ----------------------------------------------------------------------------
 *  WirelessControl.ino - wireless controller sketch using AIR430Boost FCC driver.
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
 *  On each loop cycle, a message is transmitted and a message is received from
 *  a remote node or a timeout occurs. The message contains a control command.
 *  The control command turns the red LED on or off. Both nodes can control
 *  each others red LED through a button press. When the button on one node is
 *  pressed or held down, the red LED should light up on the remote node, and
 *  vice versa.
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

// The AIR430BoostFCC library uses the SPI library internally. Energia does not
// copy the library to the output folder unless it is referenced here.
// The order of includes is also important due to this fact.
#include <SPI.h>
#include <AIR430BoostFCC.h>

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

#define CMD_OFF         0
#define CMD_ON          1

/**
 *  sControl - control packet.
 */
struct sControl
{
  unsigned char cmd;
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

struct sControl txControl = { CMD_OFF };      // TX control packet
struct sControl rxControl = { CMD_OFF };      // RX control packet

// -----------------------------------------------------------------------------
// Debug print functions

void printRxData()
{
  // Print the last received command to the serial port. 
  Serial.print("RX Command: ");
  Serial.println(rxControl.cmd);
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
  digitalWrite(RED_LED, LOW);
  
  // Setup push button.
  pinMode(PUSH2, INPUT_PULLUP);
}

void loop()
{
  // Check for a button press. If the button is being pressed, load the txControl 
  // into the radio TX FIFO and transmit it to the broadcast address. 
  if (digitalRead(PUSH2) == LOW)
  {
    txControl.cmd = CMD_ON;
  }
  else
  {
    txControl.cmd = CMD_OFF;
  }
  Radio.transmit(ADDRESS_BROADCAST, (unsigned char*)&txControl, sizeof(txControl));
  
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
  if (Radio.receiverOn((unsigned char*)&rxControl, sizeof(rxControl), 1000) > 0)
  {
    // Perform action based on incoming command: turn on/off red LED.
    if (rxControl.cmd == CMD_ON)
    {
      digitalWrite(RED_LED, HIGH);
    }
    else
    {
      digitalWrite(RED_LED, LOW);
    }
    
    printRxData();                  // RX debug information
  }
}

