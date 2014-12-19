#ifndef A110X2500_RADIO_H
/**
 *  ----------------------------------------------------------------------------
 *  A110x2500Radio.h - AIR430Boost A110x2500 radio interface.
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
#include <inttypes.h>

/**
 *  sDataStream - message sent over-the-air.
 */
struct sDataStream
{
  uint8_t length;       // Length of the data stream (excluding length field)
  uint8_t address;      // Address for hardware filtering of data stream
  uint8_t *dataField;   // Data stream payload
  // Note: The following are provided on reception of a data stream (not sent
  // over-the-air).
  int8_t rssi;          // Receive signal strength indicator
  uint8_t status;       // CRC (BIT7) and LQI (BIT6:BIT0)
};

// Address aliases
#define ADDRESS_BROADCAST  0x00

/**
 *  eChannel - frequency (channel).
 *
 *  Note: These values meet regulatory compliance with the provided 
 *  configuration for both ETSI and FCC/IC.
 */
typedef enum eChannel
{
  CHANNEL_1  = 0x05,  // ETSI 868.3MHz; FCC/IC 903MHz
  CHANNEL_2  = 0x0F,  // ETSI 868.8MHz; FCC/IC 904MHz
  CHANNEL_3  = 0x19,  // ETSI 869.3MHz; FCC/IC 905MHz
  CHANNEL_4  = 0x23,  // ETSI 869.8MHz; FCC/IC 906MHz
} channel_t;

/**
 *  ePower - power table values as indexes into the compiled power lookup table.
 *
 *  Note: These values meet regulatory compliance with the provided 
 *  configuration for both ETSI and FCC/IC.
 */
typedef enum ePower
{
  POWER_4_DBM  = 0,   // 4dBm
  POWER_3_DBM  = 1,   // 3dBm
  POWER_2_DBM  = 2,   // 2dBm
  POWER_1_DBM  = 3,   // 1dBm
  POWER_0_DBM  = 4    // 0dBm
} power_t;

// Power aliases
#define POWER_MAX  POWER_4_DBM   // Alias for maximum provided power
#define POWER_MIN  POWER_0_DBM   // Alias for minimum provided power

class A110x2500Radio
{
// -----------------------------------------------------------------------------
/**
 *  Public interface
 */
public:
  
  /**
   *  begin - setup the SPI peripheral and I/O, GDO0 interrupt I/O, and
   *  initialize the radio session.
   *
   *    @param  address   Default device address used for hardware message 
   *                      filtering.
   *    @param  channel   Default frequency to receive/transmit on.
   *    @param  power     Default output power level to transmit at.
   */
  static void begin(uint8_t address, channel_t channel, power_t power);
  
  /**
   *  end - close a radio session.
   */
  static void end(void);
  
  /**
   *  busy - radio busy indicator (transmitting flag).
   *
   *    @return	True if the transmitter is currently in use; false otherwise.
   */
  static boolean busy(void);

  /**
   *  setAddress - set device address. This address is used for hardware message
   *  filtering. If a message is received but does not match the device address
   *  and is not a broadcast (message sent to broadcast address 0x00), the 
   *  message is automatically discarded; the radio driver is never notified.
   *
   *    @param  address   The device address of the receiving node.
   */
  static void setAddress(uint8_t address);
  
  /**
   *  setChannel - set operating frequency.
   *
   *    @param  channel   Frequency to receive/transmit on.
   */
  static void setChannel(channel_t channel);
  
  /**
   *  setPower - set operating transmit output power.
   *
   *    @param  power     Output power level to transmit at.
   */
  static void setPower(power_t power);
  
  /**
   *  getRssi - read the receive signal strength indicator for the last received
   *  data stream.
   *
   *    @return	RSSI value in absolute dBm increments.
   */
  static int8_t getRssi(void);
  
  /**
   *  getLqi - read the link quality indicator for the last received data 
   *  stream.
   *
   *    @return	LQI value.
   */
  static uint8_t getLqi(void);
  
  /**
   *  getCrcBit - read the cyclic redundancy check bit for the last received 
   *  data stream.
   *  
   *    @return	CRC bit value - valid (1) or invalid (0).
   */
  static uint8_t getCrcBit(void);
  
  /**
   *  transmit - build a data stream from the data field provided and transmit
   *  the resulting message over-the-air to a specified address.
   *
   *    @param  address     The device address of the receiving node. This 
   *                        address may go to a broadcast address (0x00).
   *    @param  dataField   Payload for the data stream.
   *    @param  length      Number of bytes in the data field buffer.
   */
  static void transmit(uint8_t address, uint8_t *dataField, uint8_t length);

  /**
   *  receiverOn - turn on the radio receiver and listen until a timeout occurs.
   *  
   *  Note: This method does not return until a message has been received or a
   *  timeout occurs.
   *
   *    @param	dataField   Buffer that stores the data field. This buffer is
   *                        assumed to be large enough to store the largest
   *                        expected data field.
   *	  @param	length      Size of the data field buffer in bytes.
   *	  @param	timeout     Period to listen for (maximum) in milliseconds.
   *
   *    @return Number of bytes read from the RX FIFO that were copied into the 
	 *						data field.
   */
  static unsigned char receiverOn(uint8_t *dataField,
																	uint8_t length,
																	uint16_t timeout);

// -----------------------------------------------------------------------------
/**
 *  Private interface
 */

private:
    
  struct sDataStream _dataStream; // Data stream used for RX/TX
  
  /**
   *  wakeup - put the radio into an active state.
   */
  static void _wakeup(void);
  
  /**
   *  sleep - put the radio into a low power state.
   */
  static void sleep(void);
  
  /**
   *  buildDataStream - build a data stream. Populate header and data field
   *  (payload). Write to the TX FIFO of the physical radio hardware.
   */
  static void buildDataStream(uint8_t address, uint8_t *data, uint8_t length);
   
  /**
   *  readDataStream - strip off the physical radio header/footer information
   *  and retrieve the data field.
   */
  static void readDataStream(void);
  
  /**
   *  gdo0Isr - GDO0 interrupt service routine. Issued when the End-of-Packet
   *  has finished being received or transmitted.
   */
  static void gdo0Isr(void);
  
};

extern A110x2500Radio Radio;

#endif  /* A110X2500_RADIO_H */
