#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "wiring_private.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "driverlib/gpio.h"
#include "driverlib/prcm.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/i2c.h"
#include "Wire.h"

#define I2C_BASE I2CA0_BASE

#define TX_BUFFER_EMPTY    (txReadIndex == txWriteIndex)
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % BUFFER_LENGTH) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % BUFFER_LENGTH) == rxReadIndex)

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxReadIndex = 0;
uint8_t TwoWire::rxWriteIndex = 0;
uint8_t TwoWire::txAddress = 0;

uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint8_t TwoWire::txReadIndex = 0;
uint8_t TwoWire::txWriteIndex = 0;

uint8_t TwoWire::transmitting = 0;
uint8_t TwoWire::currentState = IDLE;

void (*TwoWire::user_onRequest)(void);
void (*TwoWire::user_onReceive)(int);

uint8_t TwoWire::slaveAddress = 0;

TwoWire::TwoWire(){}

void TwoWire::begin(void)
{
	MAP_PRCMPeripheralClkEnable(PRCM_I2CA0, PRCM_RUN_MODE_CLK);
	MAP_PinTypeI2C(PIN_01, PIN_MODE_1);
	MAP_PinTypeI2C(PIN_02, PIN_MODE_1);
	MAP_PRCMPeripheralReset(PRCM_I2CA0);
	MAP_I2CMasterInitExpClk(I2C_BASE, F_CPU, true);
}

void TwoWire::beginTransmission(uint8_t address)
{
	transmitting = 1;
	txAddress = address;
}

void TwoWire::beginTransmission(int address)
{
	beginTransmission((uint8_t)address);
}

uint8_t TwoWire::I2CTransact(unsigned long ulCmd)
{
	MAP_I2CMasterIntClearEx(I2C_BASE, MAP_I2CMasterIntStatusEx(I2C_BASE, false));
	MAP_I2CMasterTimeoutSet(I2C_BASE, I2C_TIMEOUT_VAL);
	MAP_I2CMasterControl(I2C_BASE, ulCmd);

	while((MAP_I2CMasterIntStatusEx(I2C_BASE, false)
			& (I2C_INT_MASTER | I2C_MRIS_CLKTOUT)) == 0) {
		if(!MAP_I2CMasterBusy(I2C_BASE)) return -1;
	}

	/* Check for any errors in transfer */
	if(MAP_I2CMasterErr(I2C_BASE) != I2C_MASTER_ERR_NONE) {
		switch(ulCmd) {
		case I2C_MASTER_CMD_BURST_SEND_START:
		case I2C_MASTER_CMD_BURST_SEND_CONT:
		case I2C_MASTER_CMD_BURST_SEND_STOP:
			MAP_I2CMasterControl(I2C_BASE,
				I2C_MASTER_CMD_BURST_SEND_ERROR_STOP);
			break;
		case I2C_MASTER_CMD_BURST_RECEIVE_START:
		case I2C_MASTER_CMD_BURST_RECEIVE_CONT:
		case I2C_MASTER_CMD_BURST_RECEIVE_FINISH:
			MAP_I2CMasterControl(I2C_BASE,
				I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP);
			break;
		default:
			break;
		}

		return 0;
	}

	return -1;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
	if (!quantity) return 0;

	uint8_t oldWriteIndex = rxWriteIndex;
	uint8_t spaceAvailable = (rxWriteIndex >= rxReadIndex) ?
		BUFFER_LENGTH - (rxWriteIndex - rxReadIndex)
		: (rxReadIndex - rxWriteIndex);

	if (quantity > spaceAvailable)
		quantity = spaceAvailable;

	MAP_I2CMasterSlaveAddrSet(I2C_BASE, address, true);

	if(quantity == 1)
		I2CTransact(I2C_MASTER_CMD_SINGLE_RECEIVE);
	else
		I2CTransact(I2C_MASTER_CMD_BURST_RECEIVE_START);

	quantity--;

	while(quantity) {
		rxBuffer[rxWriteIndex] = MAP_I2CMasterDataGet(I2C_BASE);
		rxWriteIndex = (rxWriteIndex + 1) % BUFFER_LENGTH;

		quantity--;
		if(quantity)
			I2CTransact(I2C_MASTER_CMD_BURST_RECEIVE_CONT);
		else
			I2CTransact(I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
	}

	rxBuffer[rxWriteIndex] = MAP_I2CMasterDataGet(I2C_BASE);
	rxWriteIndex = (rxWriteIndex + 1) % BUFFER_LENGTH;

	uint8_t bytesWritten = (rxWriteIndex >= oldWriteIndex) ?
		BUFFER_LENGTH - (rxWriteIndex - oldWriteIndex) 
		: (oldWriteIndex - rxWriteIndex);

	return bytesWritten;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity)
{
	return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}
uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
	return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop);
}

uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
	uint8_t error = I2C_MASTER_ERR_NONE;

	if(TX_BUFFER_EMPTY) return 0;

	MAP_I2CMasterSlaveAddrSet(I2C_BASE, txAddress, false);

	MAP_I2CMasterDataPut(I2C_BASE, txBuffer[txReadIndex]);
	I2CTransact(I2C_MASTER_CMD_BURST_SEND_START);

	txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;

	while(!TX_BUFFER_EMPTY) {
		MAP_I2CMasterDataPut(I2C_BASE, txBuffer[txReadIndex]);
		I2CTransact(I2C_MASTER_CMD_BURST_SEND_CONT);
		txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
	}

	if(sendStop) {
		I2CTransact(I2C_MASTER_CMD_BURST_SEND_STOP);
	} else {
		currentState = MASTER_TX;
	}

	/* Indicate that we are done transmitting */
	transmitting = 0;
	return error;
}

uint8_t TwoWire::endTransmission(void)
{
	return endTransmission(true);
}

size_t TwoWire::write(uint8_t data)
{
	if(TX_BUFFER_FULL && transmitting) return 0;

	if(TX_BUFFER_FULL && !transmitting) {
		I2CSlaveDataPut(I2C_BASE, txBuffer[txReadIndex]);
		txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
	}

	txBuffer[txWriteIndex] = data;
	txWriteIndex = (txWriteIndex + 1) % BUFFER_LENGTH;

	return 1;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
	for(size_t i = 0; i < quantity; i++) {
		write(data[i]);
	}

	return quantity;
}

int TwoWire::read(void)
{
	int value = -1;

	if(RX_BUFFER_EMPTY) return -1;

	value = rxBuffer[rxReadIndex];
	rxReadIndex = (rxReadIndex + 1) % BUFFER_LENGTH;

	return value;
}

int TwoWire::peek(void)
{
	if(RX_BUFFER_EMPTY) return -1;

	return rxBuffer[rxReadIndex];
}

void TwoWire::flush(void)
{
	txWriteIndex = 0;
	rxReadIndex = rxWriteIndex;
}

int TwoWire::available(void)
{
	return((rxWriteIndex >= rxReadIndex) ?
		(rxWriteIndex - rxReadIndex) : BUFFER_LENGTH - (rxReadIndex - rxWriteIndex));
}

TwoWire Wire;
