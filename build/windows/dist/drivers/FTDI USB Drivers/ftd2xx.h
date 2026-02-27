/*++

Copyright © 2001-2021 Future Technology Devices International Limited

THIS SOFTWARE IS PROVIDED BY FUTURE TECHNOLOGY DEVICES INTERNATIONAL LIMITED "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
FUTURE TECHNOLOGY DEVICES INTERNATIONAL LIMITED BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

FTDI DRIVERS MAY BE USED ONLY IN CONJUNCTION WITH PRODUCTS BASED ON FTDI PARTS.

FTDI DRIVERS MAY BE DISTRIBUTED IN ANY FORM AS LONG AS LICENSE INFORMATION IS NOT MODIFIED.

IF A CUSTOM VENDOR ID AND/OR PRODUCT ID OR DESCRIPTION STRING ARE USED, IT IS THE
RESPONSIBILITY OF THE PRODUCT MANUFACTURER TO MAINTAIN ANY CHANGES AND SUBSEQUENT WHQL
RE-CERTIFICATION AS A RESULT OF MAKING THESE CHANGES.


Module Name:

ftd2xx.h

Abstract:

Native USB device driver for FTDI FT232x, FT245x, FT2232x, FT4232x, FT2233H and FT4233H devices
FTD2XX library definitions

Environment:

kernel & user mode


--*/


#ifndef FTD2XX_H
#define FTD2XX_H

#ifdef _WIN32
// Compiling on Windows
#include <windows.h>

// The following ifdef block is the standard way of creating macros
// which make exporting from a DLL simpler.  All files within this DLL
// are compiled with the FTD2XX_EXPORTS symbol defined on the command line.
// This symbol should not be defined on any project that uses this DLL.
// This way any other project whose source files include this file see
// FTD2XX_API functions as being imported from a DLL, whereas this DLL
// sees symbols defined with this macro as being exported.

#ifdef FTD2XX_EXPORTS
#define FTD2XX_API __declspec(dllexport)
#elif defined(FTD2XX_STATIC)
// Avoid decorations when linking statically to D2XX.
#define FTD2XX_API
// Static D2XX depends on these Windows libs:
#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "user32.lib")
#else
#define FTD2XX_API __declspec(dllimport)
#endif

#else // _WIN32
// Compiling on non-Windows platform.
#include "WinTypes.h"
// No decorations needed.
#define FTD2XX_API

#endif // _WIN32

typedef PVOID	FT_HANDLE;
typedef ULONG	FT_STATUS;

//
// Device status
//
enum {
	FT_OK,
	FT_INVALID_HANDLE,
	FT_DEVICE_NOT_FOUND,
	FT_DEVICE_NOT_OPENED,
	FT_IO_ERROR,
	FT_INSUFFICIENT_RESOURCES,
	FT_INVALID_PARAMETER,
	FT_INVALID_BAUD_RATE,

	FT_DEVICE_NOT_OPENED_FOR_ERASE,
	FT_DEVICE_NOT_OPENED_FOR_WRITE,
	FT_FAILED_TO_WRITE_DEVICE,
	FT_EEPROM_READ_FAILED,
	FT_EEPROM_WRITE_FAILED,
	FT_EEPROM_ERASE_FAILED,
	FT_EEPROM_NOT_PRESENT,
	FT_EEPROM_NOT_PROGRAMMED,
	FT_INVALID_ARGS,
	FT_NOT_SUPPORTED,
	FT_OTHER_ERROR,
	FT_DEVICE_LIST_NOT_READY,
};


#define FT_SUCCESS(status) ((status) == FT_OK)

//
// FT_OpenEx Flags
//

#define FT_OPEN_BY_SERIAL_NUMBER	1
#define FT_OPEN_BY_DESCRIPTION		2
#define FT_OPEN_BY_LOCATION			4

#define FT_OPEN_MASK (FT_OPEN_BY_SERIAL_NUMBER | \
                      FT_OPEN_BY_DESCRIPTION | \
                      FT_OPEN_BY_LOCATION)

//
// FT_ListDevices Flags (used in conjunction with FT_OpenEx Flags
//

#define FT_LIST_NUMBER_ONLY			0x80000000
#define FT_LIST_BY_INDEX			0x40000000
#define FT_LIST_ALL					0x20000000

#define FT_LIST_MASK (FT_LIST_NUMBER_ONLY|FT_LIST_BY_INDEX|FT_LIST_ALL)

//
// Baud Rates
//

#define FT_BAUD_300			300
#define FT_BAUD_600			600
#define FT_BAUD_1200		1200
#define FT_BAUD_2400		2400
#define FT_BAUD_4800		4800
#define FT_BAUD_9600		9600
#define FT_BAUD_14400		14400
#define FT_BAUD_19200		19200
#define FT_BAUD_38400		38400
#define FT_BAUD_57600		57600
#define FT_BAUD_115200		115200
#define FT_BAUD_230400		230400
#define FT_BAUD_460800		460800
#define FT_BAUD_921600		921600

//
// Word Lengths
//

#define FT_BITS_8			(UCHAR) 8
#define FT_BITS_7			(UCHAR) 7

//
// Stop Bits
//

#define FT_STOP_BITS_1		(UCHAR) 0
#define FT_STOP_BITS_2		(UCHAR) 2

//
// Parity
//

#define FT_PARITY_NONE		(UCHAR) 0
#define FT_PARITY_ODD		(UCHAR) 1
#define FT_PARITY_EVEN		(UCHAR) 2
#define FT_PARITY_MARK		(UCHAR) 3
#define FT_PARITY_SPACE		(UCHAR) 4

//
// Flow Control
//

#define FT_FLOW_NONE		0x0000
#define FT_FLOW_RTS_CTS		0x0100
#define FT_FLOW_DTR_DSR		0x0200
#define FT_FLOW_XON_XOFF	0x0400

//
// Purge rx and tx buffers
//
#define FT_PURGE_RX			1
#define FT_PURGE_TX			2

//
// Events
//

typedef void(*PFT_EVENT_HANDLER)(DWORD, DWORD);

#define FT_EVENT_RXCHAR			1
#define FT_EVENT_MODEM_STATUS	2
#define FT_EVENT_LINE_STATUS	4

//
// Timeouts
//

#define FT_DEFAULT_RX_TIMEOUT	300
#define FT_DEFAULT_TX_TIMEOUT	300

//
// Device types
//

typedef ULONG	FT_DEVICE;

enum {
	FT_DEVICE_BM,
	FT_DEVICE_AM,
	FT_DEVICE_100AX,
	FT_DEVICE_UNKNOWN,
	FT_DEVICE_2232C,
	FT_DEVICE_232R,
	FT_DEVICE_2232H,
	FT_DEVICE_4232H,
	FT_DEVICE_232H,
	FT_DEVICE_X_SERIES,
	FT_DEVICE_4222H_0,
	FT_DEVICE_4222H_1_2,
	FT_DEVICE_4222H_3,
	FT_DEVICE_4222_PROG,
	FT_DEVICE_900,
	FT_DEVICE_930,
	FT_DEVICE_UMFTPD3A,
	FT_DEVICE_2233HP,
	FT_DEVICE_4233HP,
	FT_DEVICE_2232HP,
	FT_DEVICE_4232HP,
	FT_DEVICE_233HP,
	FT_DEVICE_232HP,
	FT_DEVICE_2232HA,
	FT_DEVICE_4232HA,
	FT_DEVICE_232RN,
};

//
// Bit Modes
//

#define FT_BITMODE_RESET					0x00
#define FT_BITMODE_ASYNC_BITBANG			0x01
#define FT_BITMODE_MPSSE					0x02
#define FT_BITMODE_SYNC_BITBANG				0x04
#define FT_BITMODE_MCU_HOST					0x08
#define FT_BITMODE_FAST_SERIAL				0x10
#define FT_BITMODE_CBUS_BITBANG				0x20
#define FT_BITMODE_SYNC_FIFO				0x40

//
// FT232R CBUS Options EEPROM values
//

#define FT_232R_CBUS_TXDEN					0x00	//	Tx Data Enable
#define FT_232R_CBUS_PWRON					0x01	//	Power On
#define FT_232R_CBUS_RXLED					0x02	//	Rx LED
#define FT_232R_CBUS_TXLED					0x03	//	Tx LED
#define FT_232R_CBUS_TXRXLED				0x04	//	Tx and Rx LED
#define FT_232R_CBUS_SLEEP					0x05	//	Sleep
#define FT_232R_CBUS_CLK48					0x06	//	48MHz clock
#define FT_232R_CBUS_CLK24					0x07	//	24MHz clock
#define FT_232R_CBUS_CLK12					0x08	//	12MHz clock
#define FT_232R_CBUS_CLK6					0x09	//	6MHz clock
#define FT_232R_CBUS_IOMODE					0x0A	//	IO Mode for CBUS bit-bang
#define FT_232R_CBUS_BITBANG_WR				0x0B	//	Bit-bang write strobe
#define FT_232R_CBUS_BITBANG_RD				0x0C	//	Bit-bang read strobe

//
// FT232H CBUS Options EEPROM values
//

#define FT_232H_CBUS_TRISTATE				0x00	//	Tristate
#define FT_232H_CBUS_TXLED					0x01	//	Tx LED
#define FT_232H_CBUS_RXLED					0x02	//	Rx LED
#define FT_232H_CBUS_TXRXLED				0x03	//	Tx and Rx LED
#define FT_232H_CBUS_PWREN					0x04	//	Power Enable
#define FT_232H_CBUS_SLEEP					0x05	//	Sleep
#define FT_232H_CBUS_DRIVE_0				0x06	//	Drive pin to logic 0
#define FT_232H_CBUS_DRIVE_1				0x07	//	Drive pin to logic 1
#define FT_232H_CBUS_IOMODE					0x08	//	IO Mode for CBUS bit-bang
#define FT_232H_CBUS_TXDEN					0x09	//	Tx Data Enable
#define FT_232H_CBUS_CLK30					0x0A	//	30MHz clock
#define FT_232H_CBUS_CLK15					0x0B	//	15MHz clock
#define FT_232H_CBUS_CLK7_5					0x0C	//	7.5MHz clock

//
// FT X Series CBUS Options EEPROM values
//

#define FT_X_SERIES_CBUS_TRISTATE			0x00	//	Tristate
#define FT_X_SERIES_CBUS_TXLED				0x01	//	Tx LED
#define FT_X_SERIES_CBUS_RXLED				0x02	//	Rx LED
#define FT_X_SERIES_CBUS_TXRXLED			0x03	//	Tx and Rx LED
#define FT_X_SERIES_CBUS_PWREN				0x04	//	Power Enable
#define FT_X_SERIES_CBUS_SLEEP				0x05	//	Sleep
#define FT_X_SERIES_CBUS_DRIVE_0			0x06	//	Drive pin to logic 0
#define FT_X_SERIES_CBUS_DRIVE_1			0x07	//	Drive pin to logic 1
#define FT_X_SERIES_CBUS_IOMODE				0x08	//	IO Mode for CBUS bit-bang
#define FT_X_SERIES_CBUS_TXDEN				0x09	//	Tx Data Enable
#define FT_X_SERIES_CBUS_CLK24				0x0A	//	24MHz clock
#define FT_X_SERIES_CBUS_CLK12				0x0B	//	12MHz clock
#define FT_X_SERIES_CBUS_CLK6				0x0C	//	6MHz clock
#define FT_X_SERIES_CBUS_BCD_CHARGER		0x0D	//	Battery charger detected
#define FT_X_SERIES_CBUS_BCD_CHARGER_N		0x0E	//	Battery charger detected inverted
#define FT_X_SERIES_CBUS_I2C_TXE			0x0F	//	I2C Tx empty
#define FT_X_SERIES_CBUS_I2C_RXF			0x10	//	I2C Rx full
#define FT_X_SERIES_CBUS_VBUS_SENSE			0x11	//	Detect VBUS
#define FT_X_SERIES_CBUS_BITBANG_WR			0x12	//	Bit-bang write strobe
#define FT_X_SERIES_CBUS_BITBANG_RD			0x13	//	Bit-bang read strobe
#define FT_X_SERIES_CBUS_TIMESTAMP			0x14	//	Toggle output when a USB SOF token is received
#define FT_X_SERIES_CBUS_KEEP_AWAKE			0x15	//	


// Driver types
#define FT_DRIVER_TYPE_D2XX		0
#define FT_DRIVER_TYPE_VCP		1



#ifdef __cplusplus
extern "C" {
#endif


#ifdef FTD2XX_STATIC
	FTD2XX_API
		FT_STATUS WINAPI FT_Initialise(
		void
		);

	FTD2XX_API
		void WINAPI FT_Finalise(
		void
		);
#endif // FTD2XX_STATIC

	FTD2XX_API
		FT_STATUS WINAPI FT_Open(
		int deviceNumber,
		FT_HANDLE *pHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_OpenEx(
		PVOID pArg1,
		DWORD Flags,
		FT_HANDLE *pHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ListDevices(
		PVOID pArg1,
		PVOID pArg2,
		DWORD Flags
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_Close(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_Read(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD dwBytesToRead,
		LPDWORD lpBytesReturned
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_Write(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD dwBytesToWrite,
		LPDWORD lpBytesWritten
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_IoCtl(
		FT_HANDLE ftHandle,
		DWORD dwIoControlCode,
		LPVOID lpInBuf,
		DWORD nInBufSize,
		LPVOID lpOutBuf,
		DWORD nOutBufSize,
		LPDWORD lpBytesReturned,
		LPOVERLAPPED lpOverlapped
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBaudRate(
		FT_HANDLE ftHandle,
		ULONG BaudRate
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDivisor(
		FT_HANDLE ftHandle,
		USHORT Divisor
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDataCharacteristics(
		FT_HANDLE ftHandle,
		UCHAR WordLength,
		UCHAR StopBits,
		UCHAR Parity
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetFlowControl(
		FT_HANDLE ftHandle,
		USHORT FlowControl,
		UCHAR XonChar,
		UCHAR XoffChar
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ResetDevice(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDtr(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ClrDtr(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetRts(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ClrRts(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetModemStatus(
		FT_HANDLE ftHandle,
		ULONG *pModemStatus
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetChars(
		FT_HANDLE ftHandle,
		UCHAR EventChar,
		UCHAR EventCharEnabled,
		UCHAR ErrorChar,
		UCHAR ErrorCharEnabled
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_Purge(
		FT_HANDLE ftHandle,
		ULONG Mask
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetTimeouts(
		FT_HANDLE ftHandle,
		ULONG ReadTimeout,
		ULONG WriteTimeout
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetQueueStatus(
		FT_HANDLE ftHandle,
		DWORD *dwRxBytes
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetEventNotification(
		FT_HANDLE ftHandle,
		DWORD Mask,
		PVOID Param
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetStatus(
		FT_HANDLE ftHandle,
		DWORD *dwRxBytes,
		DWORD *dwTxBytes,
		DWORD *dwEventDWord
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBreakOn(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBreakOff(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetWaitMask(
		FT_HANDLE ftHandle,
		DWORD Mask
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_WaitOnMask(
		FT_HANDLE ftHandle,
		DWORD *Mask
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetEventStatus(
		FT_HANDLE ftHandle,
		DWORD *dwEventDWord
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ReadEE(
		FT_HANDLE ftHandle,
		DWORD dwWordOffset,
		LPWORD lpwValue
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_WriteEE(
		FT_HANDLE ftHandle,
		DWORD dwWordOffset,
		WORD wValue
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EraseEE(
		FT_HANDLE ftHandle
		);

	//
	// structure to hold program data for FT_EE_Program, FT_EE_ProgramEx, FT_EE_Read 
	// and FT_EE_ReadEx functions
	//
	typedef struct ft_program_data {

		DWORD Signature1;			// Header - must be 0x00000000 
		DWORD Signature2;			// Header - must be 0xffffffff
		DWORD Version;				// Header - FT_PROGRAM_DATA version
		//			0 = original
		//			1 = FT2232 extensions
		//			2 = FT232R extensions
		//			3 = FT2232H extensions
		//			4 = FT4232H extensions
		//			5 = FT232H extensions

		WORD VendorId;				// 0x0403
		WORD ProductId;				// 0x6001
		char *Manufacturer;			// "FTDI"
		char *ManufacturerId;		// "FT"
		char *Description;			// "USB HS Serial Converter"
		char *SerialNumber;			// "FT000001" if fixed, or NULL
		WORD MaxPower;				// 0 < MaxPower <= 500
		WORD PnP;					// 0 = disabled, 1 = enabled
		WORD SelfPowered;			// 0 = bus powered, 1 = self powered
		WORD RemoteWakeup;			// 0 = not capable, 1 = capable
		//
		// Rev4 (FT232B) extensions
		//
		UCHAR Rev4;					// non-zero if Rev4 chip, zero otherwise
		UCHAR IsoIn;				// non-zero if in endpoint is isochronous
		UCHAR IsoOut;				// non-zero if out endpoint is isochronous
		UCHAR PullDownEnable;		// non-zero if pull down enabled
		UCHAR SerNumEnable;			// non-zero if serial number to be used
		UCHAR USBVersionEnable;		// non-zero if chip uses USBVersion
		WORD USBVersion;			// BCD (0x0200 => USB2)
		//
		// Rev 5 (FT2232) extensions
		//
		UCHAR Rev5;					// non-zero if Rev5 chip, zero otherwise
		UCHAR IsoInA;				// non-zero if in endpoint is isochronous
		UCHAR IsoInB;				// non-zero if in endpoint is isochronous
		UCHAR IsoOutA;				// non-zero if out endpoint is isochronous
		UCHAR IsoOutB;				// non-zero if out endpoint is isochronous
		UCHAR PullDownEnable5;		// non-zero if pull down enabled
		UCHAR SerNumEnable5;		// non-zero if serial number to be used
		UCHAR USBVersionEnable5;	// non-zero if chip uses USBVersion
		WORD USBVersion5;			// BCD (0x0200 => USB2)
		UCHAR AIsHighCurrent;		// non-zero if interface is high current
		UCHAR BIsHighCurrent;		// non-zero if interface is high current
		UCHAR IFAIsFifo;			// non-zero if interface is 245 FIFO
		UCHAR IFAIsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR IFAIsFastSer;			// non-zero if interface is Fast serial
		UCHAR AIsVCP;				// non-zero if interface is to use VCP drivers
		UCHAR IFBIsFifo;			// non-zero if interface is 245 FIFO
		UCHAR IFBIsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR IFBIsFastSer;			// non-zero if interface is Fast serial
		UCHAR BIsVCP;				// non-zero if interface is to use VCP drivers
		//
		// Rev 6 (FT232R) extensions
		//
		UCHAR UseExtOsc;			// Use External Oscillator
		UCHAR HighDriveIOs;			// High Drive I/Os
		UCHAR EndpointSize;			// Endpoint size
		UCHAR PullDownEnableR;		// non-zero if pull down enabled
		UCHAR SerNumEnableR;		// non-zero if serial number to be used
		UCHAR InvertTXD;			// non-zero if invert TXD
		UCHAR InvertRXD;			// non-zero if invert RXD
		UCHAR InvertRTS;			// non-zero if invert RTS
		UCHAR InvertCTS;			// non-zero if invert CTS
		UCHAR InvertDTR;			// non-zero if invert DTR
		UCHAR InvertDSR;			// non-zero if invert DSR
		UCHAR InvertDCD;			// non-zero if invert DCD
		UCHAR InvertRI;				// non-zero if invert RI
		UCHAR Cbus0;				// Cbus Mux control
		UCHAR Cbus1;				// Cbus Mux control
		UCHAR Cbus2;				// Cbus Mux control
		UCHAR Cbus3;				// Cbus Mux control
		UCHAR Cbus4;				// Cbus Mux control
		UCHAR RIsD2XX;				// non-zero if using D2XX driver
		//
		// Rev 7 (FT2232H) Extensions
		//
		UCHAR PullDownEnable7;		// non-zero if pull down enabled
		UCHAR SerNumEnable7;		// non-zero if serial number to be used
		UCHAR ALSlowSlew;			// non-zero if AL pins have slow slew
		UCHAR ALSchmittInput;		// non-zero if AL pins are Schmitt input
		UCHAR ALDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR AHSlowSlew;			// non-zero if AH pins have slow slew
		UCHAR AHSchmittInput;		// non-zero if AH pins are Schmitt input
		UCHAR AHDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR BLSlowSlew;			// non-zero if BL pins have slow slew
		UCHAR BLSchmittInput;		// non-zero if BL pins are Schmitt input
		UCHAR BLDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR BHSlowSlew;			// non-zero if BH pins have slow slew
		UCHAR BHSchmittInput;		// non-zero if BH pins are Schmitt input
		UCHAR BHDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR IFAIsFifo7;			// non-zero if interface is 245 FIFO
		UCHAR IFAIsFifoTar7;		// non-zero if interface is 245 FIFO CPU target
		UCHAR IFAIsFastSer7;		// non-zero if interface is Fast serial
		UCHAR AIsVCP7;				// non-zero if interface is to use VCP drivers
		UCHAR IFBIsFifo7;			// non-zero if interface is 245 FIFO
		UCHAR IFBIsFifoTar7;		// non-zero if interface is 245 FIFO CPU target
		UCHAR IFBIsFastSer7;		// non-zero if interface is Fast serial
		UCHAR BIsVCP7;				// non-zero if interface is to use VCP drivers
		UCHAR PowerSaveEnable;		// non-zero if using BCBUS7 to save power for self-powered designs
		//
		// Rev 8 (FT4232H) Extensions
		//
		UCHAR PullDownEnable8;		// non-zero if pull down enabled
		UCHAR SerNumEnable8;		// non-zero if serial number to be used
		UCHAR ASlowSlew;			// non-zero if A pins have slow slew
		UCHAR ASchmittInput;		// non-zero if A pins are Schmitt input
		UCHAR ADriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR BSlowSlew;			// non-zero if B pins have slow slew
		UCHAR BSchmittInput;		// non-zero if B pins are Schmitt input
		UCHAR BDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR CSlowSlew;			// non-zero if C pins have slow slew
		UCHAR CSchmittInput;		// non-zero if C pins are Schmitt input
		UCHAR CDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR DSlowSlew;			// non-zero if D pins have slow slew
		UCHAR DSchmittInput;		// non-zero if D pins are Schmitt input
		UCHAR DDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR ARIIsTXDEN;			// non-zero if port A uses RI as RS485 TXDEN
		UCHAR BRIIsTXDEN;			// non-zero if port B uses RI as RS485 TXDEN
		UCHAR CRIIsTXDEN;			// non-zero if port C uses RI as RS485 TXDEN
		UCHAR DRIIsTXDEN;			// non-zero if port D uses RI as RS485 TXDEN
		UCHAR AIsVCP8;				// non-zero if interface is to use VCP drivers
		UCHAR BIsVCP8;				// non-zero if interface is to use VCP drivers
		UCHAR CIsVCP8;				// non-zero if interface is to use VCP drivers
		UCHAR DIsVCP8;				// non-zero if interface is to use VCP drivers
		//
		// Rev 9 (FT232H) Extensions
		//
		UCHAR PullDownEnableH;		// non-zero if pull down enabled
		UCHAR SerNumEnableH;		// non-zero if serial number to be used
		UCHAR ACSlowSlewH;			// non-zero if AC pins have slow slew
		UCHAR ACSchmittInputH;		// non-zero if AC pins are Schmitt input
		UCHAR ACDriveCurrentH;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR ADSlowSlewH;			// non-zero if AD pins have slow slew
		UCHAR ADSchmittInputH;		// non-zero if AD pins are Schmitt input
		UCHAR ADDriveCurrentH;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR Cbus0H;				// Cbus Mux control
		UCHAR Cbus1H;				// Cbus Mux control
		UCHAR Cbus2H;				// Cbus Mux control
		UCHAR Cbus3H;				// Cbus Mux control
		UCHAR Cbus4H;				// Cbus Mux control
		UCHAR Cbus5H;				// Cbus Mux control
		UCHAR Cbus6H;				// Cbus Mux control
		UCHAR Cbus7H;				// Cbus Mux control
		UCHAR Cbus8H;				// Cbus Mux control
		UCHAR Cbus9H;				// Cbus Mux control
		UCHAR IsFifoH;				// non-zero if interface is 245 FIFO
		UCHAR IsFifoTarH;			// non-zero if interface is 245 FIFO CPU target
		UCHAR IsFastSerH;			// non-zero if interface is Fast serial
		UCHAR IsFT1248H;			// non-zero if interface is FT1248
		UCHAR FT1248CpolH;			// FT1248 clock polarity - clock idle high (1) or clock idle low (0)
		UCHAR FT1248LsbH;			// FT1248 data is LSB (1) or MSB (0)
		UCHAR FT1248FlowControlH;	// FT1248 flow control enable
		UCHAR IsVCPH;				// non-zero if interface is to use VCP drivers
		UCHAR PowerSaveEnableH;		// non-zero if using ACBUS7 to save power for self-powered designs

	} FT_PROGRAM_DATA, *PFT_PROGRAM_DATA;

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_Program(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ProgramEx(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_Read(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ReadEx(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_UASize(
		FT_HANDLE ftHandle,
		LPDWORD lpdwSize
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_UAWrite(
		FT_HANDLE ftHandle,
		PUCHAR pucData,
		DWORD dwDataLen
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_UARead(
		FT_HANDLE ftHandle,
		PUCHAR pucData,
		DWORD dwDataLen,
		LPDWORD lpdwBytesRead
		);


	typedef struct ft_eeprom_header {
		FT_DEVICE deviceType;		// FTxxxx device type to be programmed
		// Device descriptor options
		WORD VendorId;				// 0x0403
		WORD ProductId;				// 0x6001
		UCHAR SerNumEnable;			// non-zero if serial number to be used
		// Config descriptor options
		WORD MaxPower;				// 0 < MaxPower <= 500
		UCHAR SelfPowered;			// 0 = bus powered, 1 = self powered
		UCHAR RemoteWakeup;			// 0 = not capable, 1 = capable
		// Hardware options
		UCHAR PullDownEnable;		// non-zero if pull down in suspend enabled
	} FT_EEPROM_HEADER, *PFT_EEPROM_HEADER;


	// FT232B EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_232b {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
	} FT_EEPROM_232B, *PFT_EEPROM_232B;


	// FT2232 EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_2232 {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		// Drive options
		UCHAR AIsHighCurrent;		// non-zero if interface is high current
		UCHAR BIsHighCurrent;		// non-zero if interface is high current
		// Hardware options
		UCHAR AIsFifo;				// non-zero if interface is 245 FIFO
		UCHAR AIsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR AIsFastSer;			// non-zero if interface is Fast serial
		UCHAR BIsFifo;				// non-zero if interface is 245 FIFO
		UCHAR BIsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR BIsFastSer;			// non-zero if interface is Fast serial
		// Driver option
		UCHAR ADriverType;			// non-zero if interface is to use VCP drivers
		UCHAR BDriverType;			// non-zero if interface is to use VCP drivers
	} FT_EEPROM_2232, *PFT_EEPROM_2232;


	// FT232R EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_232r {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		// Drive options
		UCHAR IsHighCurrent;		// non-zero if interface is high current
		// Hardware options
		UCHAR UseExtOsc;			// Use External Oscillator
		UCHAR InvertTXD;			// non-zero if invert TXD
		UCHAR InvertRXD;			// non-zero if invert RXD
		UCHAR InvertRTS;			// non-zero if invert RTS
		UCHAR InvertCTS;			// non-zero if invert CTS
		UCHAR InvertDTR;			// non-zero if invert DTR
		UCHAR InvertDSR;			// non-zero if invert DSR
		UCHAR InvertDCD;			// non-zero if invert DCD
		UCHAR InvertRI;				// non-zero if invert RI
		UCHAR Cbus0;				// Cbus Mux control
		UCHAR Cbus1;				// Cbus Mux control
		UCHAR Cbus2;				// Cbus Mux control
		UCHAR Cbus3;				// Cbus Mux control
		UCHAR Cbus4;				// Cbus Mux control
		// Driver option
		UCHAR DriverType;			// non-zero if using D2XX driver
	} FT_EEPROM_232R, *PFT_EEPROM_232R;


	// FT2232H EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_2232h {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		// Drive options
		UCHAR ALSlowSlew;			// non-zero if AL pins have slow slew
		UCHAR ALSchmittInput;		// non-zero if AL pins are Schmitt input
		UCHAR ALDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR AHSlowSlew;			// non-zero if AH pins have slow slew
		UCHAR AHSchmittInput;		// non-zero if AH pins are Schmitt input
		UCHAR AHDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR BLSlowSlew;			// non-zero if BL pins have slow slew
		UCHAR BLSchmittInput;		// non-zero if BL pins are Schmitt input
		UCHAR BLDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR BHSlowSlew;			// non-zero if BH pins have slow slew
		UCHAR BHSchmittInput;		// non-zero if BH pins are Schmitt input
		UCHAR BHDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		// Hardware options
		UCHAR AIsFifo;				// non-zero if interface is 245 FIFO
		UCHAR AIsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR AIsFastSer;			// non-zero if interface is Fast serial
		UCHAR BIsFifo;				// non-zero if interface is 245 FIFO
		UCHAR BIsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR BIsFastSer;			// non-zero if interface is Fast serial
		UCHAR PowerSaveEnable;		// non-zero if using BCBUS7 to save power for self-powered designs
		// Driver option
		UCHAR ADriverType;			// non-zero if interface is to use VCP drivers
		UCHAR BDriverType;			// non-zero if interface is to use VCP drivers
	} FT_EEPROM_2232H, *PFT_EEPROM_2232H;


	// FT4232H EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_4232h {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		// Drive options
		UCHAR ASlowSlew;			// non-zero if A pins have slow slew
		UCHAR ASchmittInput;		// non-zero if A pins are Schmitt input
		UCHAR ADriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR BSlowSlew;			// non-zero if B pins have slow slew
		UCHAR BSchmittInput;		// non-zero if B pins are Schmitt input
		UCHAR BDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR CSlowSlew;			// non-zero if C pins have slow slew
		UCHAR CSchmittInput;		// non-zero if C pins are Schmitt input
		UCHAR CDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR DSlowSlew;			// non-zero if D pins have slow slew
		UCHAR DSchmittInput;		// non-zero if D pins are Schmitt input
		UCHAR DDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		// Hardware options
		UCHAR ARIIsTXDEN;			// non-zero if port A uses RI as RS485 TXDEN
		UCHAR BRIIsTXDEN;			// non-zero if port B uses RI as RS485 TXDEN
		UCHAR CRIIsTXDEN;			// non-zero if port C uses RI as RS485 TXDEN
		UCHAR DRIIsTXDEN;			// non-zero if port D uses RI as RS485 TXDEN
		// Driver option
		UCHAR ADriverType;			// non-zero if interface is to use VCP drivers
		UCHAR BDriverType;			// non-zero if interface is to use VCP drivers
		UCHAR CDriverType;			// non-zero if interface is to use VCP drivers
		UCHAR DDriverType;			// non-zero if interface is to use VCP drivers
	} FT_EEPROM_4232H, *PFT_EEPROM_4232H;


	// FT232H EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_232h {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		// Drive options
		UCHAR ACSlowSlew;			// non-zero if AC bus pins have slow slew
		UCHAR ACSchmittInput;		// non-zero if AC bus pins are Schmitt input
		UCHAR ACDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR ADSlowSlew;			// non-zero if AD bus pins have slow slew
		UCHAR ADSchmittInput;		// non-zero if AD bus pins are Schmitt input
		UCHAR ADDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		// CBUS options
		UCHAR Cbus0;				// Cbus Mux control
		UCHAR Cbus1;				// Cbus Mux control
		UCHAR Cbus2;				// Cbus Mux control
		UCHAR Cbus3;				// Cbus Mux control
		UCHAR Cbus4;				// Cbus Mux control
		UCHAR Cbus5;				// Cbus Mux control
		UCHAR Cbus6;				// Cbus Mux control
		UCHAR Cbus7;				// Cbus Mux control
		UCHAR Cbus8;				// Cbus Mux control
		UCHAR Cbus9;				// Cbus Mux control
		// FT1248 options
		UCHAR FT1248Cpol;			// FT1248 clock polarity - clock idle high (1) or clock idle low (0)
		UCHAR FT1248Lsb;			// FT1248 data is LSB (1) or MSB (0)
		UCHAR FT1248FlowControl;	// FT1248 flow control enable
		// Hardware options
		UCHAR IsFifo;				// non-zero if interface is 245 FIFO
		UCHAR IsFifoTar;			// non-zero if interface is 245 FIFO CPU target
		UCHAR IsFastSer;			// non-zero if interface is Fast serial
		UCHAR IsFT1248;			// non-zero if interface is FT1248
		UCHAR PowerSaveEnable;		// 
		// Driver option
		UCHAR DriverType;			// non-zero if interface is to use VCP drivers
	} FT_EEPROM_232H, *PFT_EEPROM_232H;


	// FT X Series EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_x_series {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		// Drive options
		UCHAR ACSlowSlew;			// non-zero if AC bus pins have slow slew
		UCHAR ACSchmittInput;		// non-zero if AC bus pins are Schmitt input
		UCHAR ACDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR ADSlowSlew;			// non-zero if AD bus pins have slow slew
		UCHAR ADSchmittInput;		// non-zero if AD bus pins are Schmitt input
		UCHAR ADDriveCurrent;		// valid values are 4mA, 8mA, 12mA, 16mA
		// CBUS options
		UCHAR Cbus0;				// Cbus Mux control
		UCHAR Cbus1;				// Cbus Mux control
		UCHAR Cbus2;				// Cbus Mux control
		UCHAR Cbus3;				// Cbus Mux control
		UCHAR Cbus4;				// Cbus Mux control
		UCHAR Cbus5;				// Cbus Mux control
		UCHAR Cbus6;				// Cbus Mux control
		// UART signal options
		UCHAR InvertTXD;			// non-zero if invert TXD
		UCHAR InvertRXD;			// non-zero if invert RXD
		UCHAR InvertRTS;			// non-zero if invert RTS
		UCHAR InvertCTS;			// non-zero if invert CTS
		UCHAR InvertDTR;			// non-zero if invert DTR
		UCHAR InvertDSR;			// non-zero if invert DSR
		UCHAR InvertDCD;			// non-zero if invert DCD
		UCHAR InvertRI;				// non-zero if invert RI
		// Battery Charge Detect options
		UCHAR BCDEnable;			// Enable Battery Charger Detection
		UCHAR BCDForceCbusPWREN;	// asserts the power enable signal on CBUS when charging port detected
		UCHAR BCDDisableSleep;		// forces the device never to go into sleep mode
		// I2C options
		WORD I2CSlaveAddress;		// I2C slave device address
		DWORD I2CDeviceId;			// I2C device ID
		UCHAR I2CDisableSchmitt;	// Disable I2C Schmitt trigger
		// FT1248 options
		UCHAR FT1248Cpol;			// FT1248 clock polarity - clock idle high (1) or clock idle low (0)
		UCHAR FT1248Lsb;			// FT1248 data is LSB (1) or MSB (0)
		UCHAR FT1248FlowControl;	// FT1248 flow control enable
		// Hardware options
		UCHAR RS485EchoSuppress;	// 
		UCHAR PowerSaveEnable;		// 
		// Driver option
		UCHAR DriverType;			// non-zero if interface is to use VCP drivers
	} FT_EEPROM_X_SERIES, *PFT_EEPROM_X_SERIES;


	// FT4222H EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	typedef struct ft_eeprom_4222h {
		// Common header
		FT_EEPROM_HEADER common;	// common elements for all device EEPROMs
		CHAR Revision;				// 'A', 'B', 'C', or 'D'.
		UCHAR I2C_Slave_Address;
		// Suspend
		UCHAR SPISuspend;			// 0 for "Disable SPI, tristate pins", 2 for "Keep SPI pin status", 3 for "Enable SPI pin control"
		UCHAR SuspendOutPol;		// 0 for negative, 1 for positive (not implemented on Rev A)
		UCHAR EnableSuspendOut;		// non-zero to enable (not implemented on Rev A)
		// QSPI
		UCHAR Clock_SlowSlew;		// non-zero if clock pin has slow slew
		UCHAR Clock_Drive;			// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR IO0_SlowSlew;			// non-zero if IO0 pin has slow slew
		UCHAR IO1_SlowSlew;			// non-zero if IO1 pin has slow slew
		UCHAR IO2_SlowSlew;			// non-zero if IO2 pin has slow slew
		UCHAR IO3_SlowSlew;			// non-zero if IO3 pin has slow slew
		UCHAR IO_Drive; 			// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR SlaveSelect_PullUp;	// non-zero to enable pull up
		UCHAR SlaveSelect_PullDown;	// non-zero to enable pull down
		UCHAR SlaveSelect_Drive;	// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR SlaveSelect_SlowSlew;	// non-zero if slave select pin has slow slew
		UCHAR MISO_Suspend;			// 2 for push-low, 3 for push high, 0 and 1 reserved
		UCHAR SIMO_Suspend;			// 2 for push-low, 3 for push high, 0 and 1 reserved
		UCHAR IO2_IO3_Suspend;		// 2 for push-low, 3 for push high, 0 and 1 reserved
		UCHAR SlaveSelect_Suspend;	// 0 for no-change (not implemented on Rev A), 2 for push-low, 3 for push high, 1 reserved
		// GPIO
		UCHAR GPIO0_Drive;			// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR GPIO1_Drive;			// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR GPIO2_Drive;			// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR GPIO3_Drive;			// valid values are 4mA, 8mA, 12mA, 16mA
		UCHAR GPIO0_SlowSlew;		// non-zero if IO0 pin has slow slew
		UCHAR GPIO1_SlowSlew;		// non-zero if IO0 pin has slow slew
		UCHAR GPIO2_SlowSlew;		// non-zero if IO0 pin has slow slew
		UCHAR GPIO3_SlowSlew;		// non-zero if IO0 pin has slow slew
		UCHAR GPIO0_PullDown;		// non-zero to enable pull down
		UCHAR GPIO1_PullDown;		// non-zero to enable pull down
		UCHAR GPIO2_PullDown;		// non-zero to enable pull down
		UCHAR GPIO3_PullDown;		// non-zero to enable pull down
		UCHAR GPIO0_PullUp;			// non-zero to enable pull up
		UCHAR GPIO1_PullUp;			// non-zero to enable pull up
		UCHAR GPIO2_PullUp;			// non-zero to enable pull up
		UCHAR GPIO3_PullUp;			// non-zero to enable pull up
		UCHAR GPIO0_OpenDrain;		// non-zero to enable open drain
		UCHAR GPIO1_OpenDrain;		// non-zero to enable open drain
		UCHAR GPIO2_OpenDrain;		// non-zero to enable open drain
		UCHAR GPIO3_OpenDrain;		// non-zero to enable open drain
		UCHAR GPIO0_Suspend;		// 0 for no-change, 1 for input (not implemented on Rev A), 2 for push-low, 3 for push high
		UCHAR GPIO1_Suspend;		// 0 for no-change, 1 for input (not implemented on Rev A), 2 for push-low, 3 for push high
		UCHAR GPIO2_Suspend;		// 0 for no-change, 1 for input (not implemented on Rev A), 2 for push-low, 3 for push high
		UCHAR GPIO3_Suspend;		// 0 for no-change, 1 for input (not implemented on Rev A), 2 for push-low, 3 for push high
		UCHAR FallingEdge;			// non-zero to change GPIO on falling edge
		// BCD
		UCHAR BCD_Disable;			// non-zero to disable BCD
		UCHAR BCD_OutputActiveLow;	// non-zero to set BCD output active low
		UCHAR BCD_Drive;			// valid values are 4mA, 8mA, 12mA, 16mA
	} FT_EEPROM_4222H, *PFT_EEPROM_4222H;


	// Power Delivery structures for use with FT_EEPROM_Read and FT_EEPROM_Program
	// PDO Configuration structure, mA supported values 0 to 10230mA, mV supported values 0 to 51100mV
	// This is part of the FT_EEPROM_PD structure.
	typedef struct ft_eeprom_PD_PDO_mv_ma {
		USHORT PDO1ma;	// PDO1 mA
		USHORT PDO1mv;	// PDO1 mV
		USHORT PDO2ma;	// PDO2 mA
		USHORT PDO2mv;	// PDO2 mV
		USHORT PDO3ma;	// PDO3 mA
		USHORT PDO3mv;	// PDO3 mV
		USHORT PDO4ma;	// PDO4 mA
		USHORT PDO4mv;	// PDO4 mV
		USHORT PDO5ma;	// PDO5 mA (FTx233HP only)
		USHORT PDO5mv;	// PDO5 mV (FTx233HP only)
		USHORT PDO6ma;	// PDO6 mA (FTx233HP only)
		USHORT PDO6mv;	// PDO6 mV (FTx233HP only)
		USHORT PDO7ma;	// PDO7 mA (FTx233HP only)
		USHORT PDO7mv;	// PDO7 mV (FTx233HP only)
	} FT_EEPROM_PD_PDO_mv_ma;

	// PD EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// This is appended to the end of the base device structure. e_g. 
	//		struct {
	//			FT_EEPROM_xxx base;
	//			FT_EEPROM_PD pd;
	//		};
	// Device GPIO values are:
	//	FTx233HP - 0 to 7, 15 for N/A
	//	FTx232HP - 0 to 3, 15 for N/A
	typedef struct ft_eeprom_pd {
		// Configuration
		UCHAR srprs;		// non-zero to enable Sink Request Power Role Swap
		UCHAR sraprs;		// non-zero to enable Sink Accept PR Swap
		UCHAR srrprs;		// non-zero to enable Source Request PR SWAP
		UCHAR saprs;		// non-zero to enable Source Accept PR SWAP
		UCHAR vconns;		// non-zero to enable vConn Swap
		UCHAR passthru;		// non-zero to enable Pass Through (FTx233HP only)
		UCHAR extmcu;		// non-zero to enable External MCU
		UCHAR pd2en;		// non-zero to enable PD2 (FTx233HP only)
		UCHAR pd1autoclk;	// non-zero to enable PD1 Auto Clock
		UCHAR pd2autoclk;	// non-zero to enable PD2 Auto Clock (FTx233HP only)
		UCHAR useefuse;		// non-zero to Use EFUSE
		UCHAR extvconn;		// non-zero to enable External vConn

		// GPIO Configuration
		UCHAR count;		// GPIO Count, supported values are 0 to 7 
		UCHAR gpio1;		// GPIO Number 1, supports device GPIO values
		UCHAR gpio2;		// GPIO Number 2, supports device GPIO values
		UCHAR gpio3;		// GPIO Number 3, supports device GPIO values
		UCHAR gpio4;		// GPIO Number 4, supports device GPIO values
		UCHAR gpio5;		// GPIO Number 5, supports device GPIO values (FTx233HP only)
		UCHAR gpio6;		// GPIO Number 6, supports device GPIO values (FTx233HP only)
		UCHAR gpio7;		// GPIO Number 7, supports device GPIO values (FTx233HP only)
		UCHAR pd1lden;		// PD1 Load Enable, supports device GPIO values
		UCHAR pd2lden;		// PD2 Load Enable, supports device GPIO values (FTx233HP only)
		UCHAR dispin;		// Discharge Pin, supports device GPIO values
		UCHAR disenbm;		// Discharge Enable BM, 0 for "Drive Hi", 1 for "Drive Low", 2 for "Input Mode", 3 for "Don't Care"
		UCHAR disdisbm;		// Discharge Disable BM, 0 for "Drive Hi", 1 for "Drive Low", 2 for "Input Mode", 3 for "Don't Care"
		UCHAR ccselect;		// CC Select Indicator, supports device GPIO values

		// ISET Configuration
		UCHAR iset1;		// ISET1, supports device GPIO values
		UCHAR iset2;		// ISET2, supports device GPIO values
		UCHAR iset3;		// ISET3, supports device GPIO values
		UCHAR extiset;		// non-zero to enable EXTEND_ISET
		UCHAR isetpd2;		// non-zero to enable ISET_PD2
		UCHAR iseten;		// non-zero to set ISET_ENABLED

		// BM Configuration, 0 for "Drive Hi", 1 for "Drive Low", 2 for "Input Mode", 3 for "Don't Care"
		UCHAR PDO1_GPIO[7];		// PDO1 GPIO1 to GPIO7
		UCHAR PDO2_GPIO[7];		// PDO2 GPIO1 to GPIO7
		UCHAR PDO3_GPIO[7];		// PDO3 GPIO1 to GPIO7
		UCHAR PDO4_GPIO[7];		// PDO4 GPIO1 to GPIO7
		UCHAR PDO5_GPIO[7];		// PDO5 GPIO1 to GPIO7 (FTx233HP only)
		UCHAR PDO6_GPIO[7];		// PDO6 GPIO1 to GPIO7 (FTx233HP only)
		UCHAR PDO7_GPIO[7];		// PDO7 GPIO1 to GPIO7 (FTx233HP only)
		UCHAR VSET0V_GPIO[7];	// PDO7 GPIO1 to GPIO7
		UCHAR VSAFE5V_GPIO[7];	// PDO7 GPIO1 to GPIO7

		FT_EEPROM_PD_PDO_mv_ma BM_PDO_Sink;
		FT_EEPROM_PD_PDO_mv_ma BM_PDO_Source;
		FT_EEPROM_PD_PDO_mv_ma BM_PDO_Sink_2; // (FTx233HP only)

		// PD Timers
		UCHAR srt;			// Sender Response Timer
		UCHAR hrt;			// Hard Reset Timer
		UCHAR sct;			// Source Capability Timer
		UCHAR dit;			// Discover Identity Timer
		USHORT srcrt;		// Source Recover Timer
		USHORT trt;			// Transition Timer
		USHORT sofft;		// Source off timer
		USHORT nrt;			// No Response Timer
		USHORT swct;		// Sink Wait Capability Timer
		USHORT snkrt;		// Sink Request Timer
		UCHAR dt;			// Discharge Timer
		UCHAR cnst;			// Chunk not supported timer
		USHORT it;			// Idle Timer

		// PD Control
		UCHAR i2caddr;		// I2C Address (hex)
		UINT prou;			// Power Reserved for OWN use
		UINT trim1;			// TRIM1
		UINT trim2;			// TRIM2
		UCHAR extdc;		// non-zero to enable ETERNAL_DC_POWER
	} FT_EEPROM_PD, *PFT_EEPROM_PD;

	// FT2233HP EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// FT2232H with power delivery
	typedef struct _ft_eeprom_2233hp
	{
		FT_EEPROM_2232H	ft2232h;
		FT_EEPROM_PD	pd;
	} FT_EEPROM_2233HP, *PFT_EEPROM_2233HP;

	// FT4233HP EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// FT4232H with power delivery
	typedef struct _ft_eeprom_4233hp
	{
		FT_EEPROM_4232H	ft4232h;
		FT_EEPROM_PD	pd;
	} FT_EEPROM_4233HP, *PFT_EEPROM_4233HP;

	// FT2232HP EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// FT2232H with power delivery
	typedef struct _ft_eeprom_2232hp
	{
		FT_EEPROM_2232H	ft2232h;
		FT_EEPROM_PD	pd;
	} FT_EEPROM_2232HP, *PFT_EEPROM_2232HP;

	// FT4232HP EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// FT4232H with power delivery
	typedef struct _ft_eeprom_4232hp
	{
		FT_EEPROM_4232H	ft4232h;
		FT_EEPROM_PD	pd;
	} FT_EEPROM_4232HP, *PFT_EEPROM_4232HP;

	// FT233HP EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// FT233H with power delivery
	typedef struct _ft_eeprom_233hp
	{
		FT_EEPROM_232H	ft232h;
		FT_EEPROM_PD	pd;
	} FT_EEPROM_233HP, *PFT_EEPROM_233HP;

	// FT232HP EEPROM structure for use with FT_EEPROM_Read and FT_EEPROM_Program
	// FT232H with power delivery
	typedef struct _ft_eeprom_232hp
	{
		FT_EEPROM_232H	ft232h;
		FT_EEPROM_PD	pd;
	} FT_EEPROM_232HP, *PFT_EEPROM_232HP;

	FTD2XX_API
		FT_STATUS WINAPI FT_EEPROM_Read(
		FT_HANDLE ftHandle,
		void *eepromData,
		DWORD eepromDataSize,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		);


	FTD2XX_API
		FT_STATUS WINAPI FT_EEPROM_Program(
		FT_HANDLE ftHandle,
		void *eepromData,
		DWORD eepromDataSize,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		);


	FTD2XX_API
		FT_STATUS WINAPI FT_SetLatencyTimer(
		FT_HANDLE ftHandle,
		UCHAR ucLatency
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetLatencyTimer(
		FT_HANDLE ftHandle,
		PUCHAR pucLatency
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBitMode(
		FT_HANDLE ftHandle,
		UCHAR ucMask,
		UCHAR ucEnable
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetBitMode(
		FT_HANDLE ftHandle,
		PUCHAR pucMode
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetUSBParameters(
		FT_HANDLE ftHandle,
		ULONG ulInTransferSize,
		ULONG ulOutTransferSize
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDeadmanTimeout(
		FT_HANDLE ftHandle,
		ULONG ulDeadmanTimeout
		);

#ifndef _WIN32
	// Extra functions for non-Windows platforms to compensate
	// for lack of .INF file to specify Vendor and Product IDs.

	FTD2XX_API
		FT_STATUS FT_SetVIDPID(
		DWORD dwVID,
		DWORD dwPID
		);

	FTD2XX_API
		FT_STATUS FT_GetVIDPID(
		DWORD * pdwVID,
		DWORD * pdwPID
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceLocId(
		FT_HANDLE ftHandle,
		LPDWORD lpdwLocId
		);
#endif // _WIN32        

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceInfo(
		FT_HANDLE ftHandle,
		FT_DEVICE *lpftDevice,
		LPDWORD lpdwID,
		PCHAR SerialNumber,
		PCHAR Description,
		LPVOID Dummy
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_StopInTask(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_RestartInTask(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_SetResetPipeRetryCount(
		FT_HANDLE ftHandle,
		DWORD dwCount
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ResetPort(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_CyclePort(
		FT_HANDLE ftHandle
		);


	//
	// Win32-type functions
	//

	FTD2XX_API
		FT_HANDLE WINAPI FT_W32_CreateFile(
		LPCTSTR					lpszName,
		DWORD					dwAccess,
		DWORD					dwShareMode,
		LPSECURITY_ATTRIBUTES	lpSecurityAttributes,
		DWORD					dwCreate,
		DWORD					dwAttrsAndFlags,
		HANDLE					hTemplate
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_CloseHandle(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_ReadFile(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD nBufferSize,
		LPDWORD lpBytesReturned,
		LPOVERLAPPED lpOverlapped
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_WriteFile(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD nBufferSize,
		LPDWORD lpBytesWritten,
		LPOVERLAPPED lpOverlapped
		);

	FTD2XX_API
		DWORD WINAPI FT_W32_GetLastError(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_GetOverlappedResult(
		FT_HANDLE ftHandle,
		LPOVERLAPPED lpOverlapped,
		LPDWORD lpdwBytesTransferred,
		BOOL bWait
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_CancelIo(
		FT_HANDLE ftHandle
		);


	//
	// Win32 COMM API type functions
	//
	typedef struct _FTCOMSTAT {
		DWORD fCtsHold : 1;
		DWORD fDsrHold : 1;
		DWORD fRlsdHold : 1;
		DWORD fXoffHold : 1;
		DWORD fXoffSent : 1;
		DWORD fEof : 1;
		DWORD fTxim : 1;
		DWORD fReserved : 25;
		DWORD cbInQue;
		DWORD cbOutQue;
	} FTCOMSTAT, *LPFTCOMSTAT;

	typedef struct _FTDCB {
		DWORD DCBlength;			/* sizeof(FTDCB)						*/
		DWORD BaudRate;				/* Baudrate at which running			*/
		DWORD fBinary : 1;			/* Binary Mode (skip EOF check)			*/
		DWORD fParity : 1;			/* Enable parity checking				*/
		DWORD fOutxCtsFlow : 1;		/* CTS handshaking on output			*/
		DWORD fOutxDsrFlow : 1;		/* DSR handshaking on output			*/
		DWORD fDtrControl : 2;		/* DTR Flow control						*/
		DWORD fDsrSensitivity : 1;	/* DSR Sensitivity						*/
		DWORD fTXContinueOnXoff : 1;	/* Continue TX when Xoff sent			*/
		DWORD fOutX : 1;				/* Enable output X-ON/X-OFF				*/
		DWORD fInX : 1;				/* Enable input X-ON/X-OFF				*/
		DWORD fErrorChar : 1;		/* Enable Err Replacement				*/
		DWORD fNull : 1;				/* Enable Null stripping				*/
		DWORD fRtsControl : 2;		/* Rts Flow control						*/
		DWORD fAbortOnError : 1;		/* Abort all reads and writes on Error	*/
		DWORD fDummy2 : 17;			/* Reserved								*/
		WORD wReserved;				/* Not currently used					*/
		WORD XonLim;				/* Transmit X-ON threshold				*/
		WORD XoffLim;				/* Transmit X-OFF threshold				*/
		BYTE ByteSize;				/* Number of bits/byte, 4-8				*/
		BYTE Parity;				/* 0-4=None,Odd,Even,Mark,Space			*/
		BYTE StopBits;				/* FT_STOP_BITS_1 or FT_STOP_BITS_2		*/
		char XonChar;				/* Tx and Rx X-ON character				*/
		char XoffChar;				/* Tx and Rx X-OFF character			*/
		char ErrorChar;				/* Error replacement char				*/
		char EofChar;				/* End of Input character				*/
		char EvtChar;				/* Received Event character				*/
		WORD wReserved1;			/* Fill for now.						*/
	} FTDCB, *LPFTDCB;

	typedef struct _FTTIMEOUTS {
		DWORD ReadIntervalTimeout;			/* Maximum time between read chars.	*/
		DWORD ReadTotalTimeoutMultiplier;	/* Multiplier of characters.		*/
		DWORD ReadTotalTimeoutConstant;		/* Constant in milliseconds.		*/
		DWORD WriteTotalTimeoutMultiplier;	/* Multiplier of characters.		*/
		DWORD WriteTotalTimeoutConstant;	/* Constant in milliseconds.		*/
	} FTTIMEOUTS, *LPFTTIMEOUTS;


	FTD2XX_API
		BOOL WINAPI FT_W32_ClearCommBreak(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_ClearCommError(
		FT_HANDLE ftHandle,
		LPDWORD lpdwErrors,
		LPFTCOMSTAT lpftComstat
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_EscapeCommFunction(
		FT_HANDLE ftHandle,
		DWORD dwFunc
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommModemStatus(
		FT_HANDLE ftHandle,
		LPDWORD lpdwModemStatus
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommState(
		FT_HANDLE ftHandle,
		LPFTDCB lpftDcb
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommTimeouts(
		FT_HANDLE ftHandle,
		FTTIMEOUTS *pTimeouts
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_PurgeComm(
		FT_HANDLE ftHandle,
		DWORD dwMask
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommBreak(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommMask(
		FT_HANDLE ftHandle,
		ULONG ulEventMask
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommMask(
		FT_HANDLE ftHandle,
		LPDWORD lpdwEventMask
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommState(
		FT_HANDLE ftHandle,
		LPFTDCB lpftDcb
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommTimeouts(
		FT_HANDLE ftHandle,
		FTTIMEOUTS *pTimeouts
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_SetupComm(
		FT_HANDLE ftHandle,
		DWORD dwReadBufferSize,
		DWORD dwWriteBufferSize
		);

	FTD2XX_API
		BOOL WINAPI FT_W32_WaitCommEvent(
		FT_HANDLE ftHandle,
		PULONG pulEvent,
		LPOVERLAPPED lpOverlapped
		);


	//
	// Device information
	//

	typedef struct _ft_device_list_info_node {
		ULONG Flags;
		ULONG Type;
		ULONG ID;
		DWORD LocId;
		char SerialNumber[16];
		char Description[64];
		FT_HANDLE ftHandle;
	} FT_DEVICE_LIST_INFO_NODE;

	// Device information flags
	enum {
		FT_FLAGS_OPENED = 1,
		FT_FLAGS_HISPEED = 2
	};


	FTD2XX_API
		FT_STATUS WINAPI FT_CreateDeviceInfoList(
		LPDWORD lpdwNumDevs
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceInfoList(
		FT_DEVICE_LIST_INFO_NODE *pDest,
		LPDWORD lpdwNumDevs
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceInfoDetail(
		DWORD dwIndex,
		LPDWORD lpdwFlags,
		LPDWORD lpdwType,
		LPDWORD lpdwID,
		LPDWORD lpdwLocId,
		LPVOID lpSerialNumber,
		LPVOID lpDescription,
		FT_HANDLE *pftHandle
		);


	//
	// Version information
	//

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDriverVersion(
		FT_HANDLE ftHandle,
		LPDWORD lpdwVersion
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetLibraryVersion(
		LPDWORD lpdwVersion
		);


	FTD2XX_API
		FT_STATUS WINAPI FT_Rescan(
		void
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_Reload(
		WORD wVid,
		WORD wPid
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetComPortNumber(
		FT_HANDLE ftHandle,
		LPLONG	lpdwComPortNumber
		);


	//
	// FT232H additional EEPROM functions
	//

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ReadConfig(
		FT_HANDLE ftHandle,
		UCHAR ucAddress,
		PUCHAR pucValue
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_WriteConfig(
		FT_HANDLE ftHandle,
		UCHAR ucAddress,
		UCHAR ucValue
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ReadECC(
		FT_HANDLE ftHandle,
		UCHAR ucOption,
		LPWORD lpwValue
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_GetQueueStatusEx(
		FT_HANDLE ftHandle,
		DWORD *dwRxBytes
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ComPortIdle(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_ComPortCancelIdle(
		FT_HANDLE ftHandle
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdGet(
		FT_HANDLE ftHandle,
		UCHAR Request,
		UCHAR *Buf,
		USHORT Len
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdSet(
		FT_HANDLE ftHandle,
		UCHAR Request,
		UCHAR *Buf,
		USHORT Len
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdGetEx(
		FT_HANDLE ftHandle,
		USHORT wValue,
		UCHAR *Buf,
		USHORT Len
		);

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdSetEx(
		FT_HANDLE ftHandle,
		USHORT wValue,
		UCHAR *Buf,
		USHORT Len
		);

#ifdef __cplusplus
}
#endif


#endif	/* FTD2XX_H */
