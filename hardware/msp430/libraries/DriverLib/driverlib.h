//*****************************************************************************
//
// driverlib.h - Energia header file for including driver library support
//
//*****************************************************************************

#if defined(__MSP430FR5969__)
	#include "utility/adc12_b.h"
#endif
#if defined(__MSP430FR5969__)
	#include "utility/aes256.h"
#endif
#if defined(__MSP430FR5969__)
	#include "utility/comp_e.h"
#endif
#include "utility/crc.h"
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/cs.h"
#endif
#include "utility/dma.h"
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/eusci_a_spi.h"
#endif
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/eusci_a_uart.h"
#endif
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/eusci_b_i2c.h"
#endif
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/eusci_b_spi.h"
#endif
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/fram.h"
#endif
#include "utility/gpio.h"
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/mpu.h"
#endif
#include "utility/mpy32.h"
#include "utility/pmm.h"
#if defined(__MSP430FR5969__)
	#include "utility/ref_a.h"
#endif
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)
	#include "utility/rtc_b.h"
#endif
#include "utility/sfr.h"
#include "utility/sys.h"
#include "utility/timer_a.h"
#include "utility/timer_b.h"
#include "utility/tlv.h"
#include "utility/wdt_a.h"
#if defined(__MSP430F5529__)
	#include "utility/adc12_a.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/comp_b.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/flash.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/pmap.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/ram.h"
#endif
#if defined(__MSP430F5529__) || defined(__MSP430FR5739__)
	#include "utility/ref.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/rtc_a.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/ucs.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/usci_a_spi.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/usci_a_uart.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/usci_b_i2c.h"
#endif
#if defined(__MSP430F5529__)
	#include "utility/usci_b_spi.h"
#endif
#if defined(__MSP430FR5739__)
	#include "utility/adc10_b.h"
#endif
#if defined(__MSP430FR5739__)
	#include "utility/comp_d.h"
#endif
