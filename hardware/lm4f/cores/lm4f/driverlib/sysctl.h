//*****************************************************************************
//
// sysctl.h - Prototypes for the system control driver.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __SYSCTL_H__
#define __SYSCTL_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// The following are values that can be passed to the
// SysCtlPeripheralPresent(), SysCtlPeripheralEnable(),
// SysCtlPeripheralDisable(), and SysCtlPeripheralReset() APIs as the
// ulPeripheral parameter.  The peripherals in the fourth group (upper nibble
// is 3) can only be used with the SysCtlPeripheralPresent() API.
//
//*****************************************************************************
#ifndef DEPRECATED
#define SYSCTL_PERIPH_WDOG      0x00000008  // Watchdog
#endif
#define SYSCTL_PERIPH_WDOG0     0x00000008  // Watchdog 0
#define SYSCTL_PERIPH_HIBERNATE 0x00000040  // Hibernation module
#ifndef DEPRECATED
#define SYSCTL_PERIPH_ADC       0x00100001  // ADC
#endif
#define SYSCTL_PERIPH_ADC0      0x00100001  // ADC0
#define SYSCTL_PERIPH_ADC1      0x00100002  // ADC1
#ifndef DEPRECATED
#define SYSCTL_PERIPH_PWM       0x00100010  // PWM
#endif
#define SYSCTL_PERIPH_PWM0      0x00100010  // PWM
#define SYSCTL_PERIPH_CAN0      0x00100100  // CAN 0
#define SYSCTL_PERIPH_CAN1      0x00100200  // CAN 1
#define SYSCTL_PERIPH_CAN2      0x00100400  // CAN 2
#define SYSCTL_PERIPH_WDOG1     0x00101000  // Watchdog 1
#define SYSCTL_PERIPH_UART0     0x10000001  // UART 0
#define SYSCTL_PERIPH_UART1     0x10000002  // UART 1
#define SYSCTL_PERIPH_UART2     0x10000004  // UART 2
#ifndef DEPRECATED
#define SYSCTL_PERIPH_SSI       0x10000010  // SSI
#endif
#define SYSCTL_PERIPH_SSI0      0x10000010  // SSI 0
#define SYSCTL_PERIPH_SSI1      0x10000020  // SSI 1
#ifndef DEPRECATED
#define SYSCTL_PERIPH_QEI       0x10000100  // QEI
#endif
#define SYSCTL_PERIPH_QEI0      0x10000100  // QEI 0
#define SYSCTL_PERIPH_QEI1      0x10000200  // QEI 1
#ifndef DEPRECATED
#define SYSCTL_PERIPH_I2C       0x10001000  // I2C
#endif
#define SYSCTL_PERIPH_I2C0      0x10001000  // I2C 0
#define SYSCTL_PERIPH_I2C1      0x10004000  // I2C 1
#define SYSCTL_PERIPH_TIMER0    0x10100001  // Timer 0
#define SYSCTL_PERIPH_TIMER1    0x10100002  // Timer 1
#define SYSCTL_PERIPH_TIMER2    0x10100004  // Timer 2
#define SYSCTL_PERIPH_TIMER3    0x10100008  // Timer 3
#define SYSCTL_PERIPH_COMP0     0x10100100  // Analog comparator 0
#define SYSCTL_PERIPH_COMP1     0x10100200  // Analog comparator 1
#define SYSCTL_PERIPH_COMP2     0x10100400  // Analog comparator 2
#define SYSCTL_PERIPH_I2S0      0x10101000  // I2S0
#define SYSCTL_PERIPH_EPI0      0x10104000  // EPI0
#define SYSCTL_PERIPH_GPIOA     0x20000001  // GPIO A
#define SYSCTL_PERIPH_GPIOB     0x20000002  // GPIO B
#define SYSCTL_PERIPH_GPIOC     0x20000004  // GPIO C
#define SYSCTL_PERIPH_GPIOD     0x20000008  // GPIO D
#define SYSCTL_PERIPH_GPIOE     0x20000010  // GPIO E
#define SYSCTL_PERIPH_GPIOF     0x20000020  // GPIO F
#define SYSCTL_PERIPH_GPIOG     0x20000040  // GPIO G
#define SYSCTL_PERIPH_GPIOH     0x20000080  // GPIO H
#define SYSCTL_PERIPH_GPIOJ     0x20000100  // GPIO J
#define SYSCTL_PERIPH_UDMA      0x20002000  // uDMA
#define SYSCTL_PERIPH_USB0      0x20100001  // USB0
#define SYSCTL_PERIPH_ETH       0x20105000  // Ethernet
#define SYSCTL_PERIPH_IEEE1588  0x20100100  // IEEE1588
#define SYSCTL_PERIPH_PLL       0x30000010  // PLL
#define SYSCTL_PERIPH_TEMP      0x30000020  // Temperature sensor
#define SYSCTL_PERIPH_MPU       0x30000080  // Cortex M3 MPU
#define SYSCTL_PERIPH2_ADC0     0xf0003800  // ADC 0
#define SYSCTL_PERIPH2_ADC1     0xf0003801  // ADC 1
#define SYSCTL_PERIPH2_CAN0     0xf0003400  // CAN 0
#define SYSCTL_PERIPH2_CAN1     0xf0003401  // CAN 1
#define SYSCTL_PERIPH2_CAN2     0xf0003402  // CAN 2
#define SYSCTL_PERIPH2_COMP0    0xf0003c00  // Analog comparator 0
#define SYSCTL_PERIPH_EEPROM0   0xf0005800  // EEPROM 0
#define SYSCTL_PERIPH2_EPI0     0xf0001000  // EPI0
#define SYSCTL_PERIPH2_ETH      0xf0002c00  // ETH
#define SYSCTL_PERIPH_FAN0      0xf0005400  // FAN 0
#define SYSCTL_PERIPH2_GPIOA    0xf0000800  // GPIO A
#define SYSCTL_PERIPH2_GPIOB    0xf0000801  // GPIO B
#define SYSCTL_PERIPH2_GPIOC    0xf0000802  // GPIO C
#define SYSCTL_PERIPH2_GPIOD    0xf0000803  // GPIO D
#define SYSCTL_PERIPH2_GPIOE    0xf0000804  // GPIO E
#define SYSCTL_PERIPH2_GPIOF    0xf0000805  // GPIO F
#define SYSCTL_PERIPH2_GPIOG    0xf0000806  // GPIO G
#define SYSCTL_PERIPH2_GPIOH    0xf0000807  // GPIO H
#define SYSCTL_PERIPH2_GPIOJ    0xf0000808  // GPIO J
#define SYSCTL_PERIPH_GPIOK     0xf0000809  // GPIO K
#define SYSCTL_PERIPH_GPIOL     0xf000080a  // GPIO L
#define SYSCTL_PERIPH_GPIOM     0xf000080b  // GPIO M
#define SYSCTL_PERIPH_GPION     0xf000080c  // GPIO N
#define SYSCTL_PERIPH_GPIOP     0xf000080d  // GPIO P
#define SYSCTL_PERIPH_GPIOQ     0xf000080e  // GPIO Q
#define SYSCTL_PERIPH_GPIOR     0xf000080f  // GPIO R
#define SYSCTL_PERIPH_GPIOS     0xf0000810  // GPIO S
#define SYSCTL_PERIPH2_HIB      0xf0001400  // Hibernation module
#define SYSCTL_PERIPH2_I2C0     0xf0002000  // I2C 0
#define SYSCTL_PERIPH2_I2C1     0xf0002001  // I2C 1
#define SYSCTL_PERIPH_I2C2      0xf0002002  // I2C 2
#define SYSCTL_PERIPH_I2C3      0xf0002003  // I2C 3
#define SYSCTL_PERIPH_I2C4      0xf0002004  // I2C 4
#define SYSCTL_PERIPH_I2C5      0xf0002005  // I2C 5
#define SYSCTL_PERIPH2_I2S0     0xf0002400  // I2S0
#define SYSCTL_PERIPH_LPC0      0xf0004800  // LPC 0
#define SYSCTL_PERIPH_PECI0     0xf0005000  // PECI 0
#define SYSCTL_PERIPH2_PWM0     0xf0004000  // PWM 0
#define SYSCTL_PERIPH_PWM1      0xf0004001  // PWM 1
#define SYSCTL_PERIPH2_QEI0     0xf0004400  // QEI 0
#define SYSCTL_PERIPH2_QEI1     0xf0004401  // QEI 1
#define SYSCTL_PERIPH2_SSI0     0xf0001c00  // SSI 0
#define SYSCTL_PERIPH2_SSI1     0xf0001c01  // SSI 1
#define SYSCTL_PERIPH_SSI2      0xf0001c02  // SSI 2
#define SYSCTL_PERIPH_SSI3      0xf0001c03  // SSI 3
#define SYSCTL_PERIPH2_TIMER0   0xf0000400  // Timer 0
#define SYSCTL_PERIPH2_TIMER1   0xf0000401  // Timer 1
#define SYSCTL_PERIPH2_TIMER2   0xf0000402  // Timer 2
#define SYSCTL_PERIPH2_TIMER3   0xf0000403  // Timer 3
#define SYSCTL_PERIPH_TIMER4    0xf0000404  // Timer 4
#define SYSCTL_PERIPH_TIMER5    0xf0000405  // Timer 5
#define SYSCTL_PERIPH_WTIMER0   0xf0005c00  // Wide Timer 0
#define SYSCTL_PERIPH_WTIMER1   0xf0005c01  // Wide Timer 1
#define SYSCTL_PERIPH_WTIMER2   0xf0005c02  // Wide Timer 2
#define SYSCTL_PERIPH_WTIMER3   0xf0005c03  // Wide Timer 3
#define SYSCTL_PERIPH_WTIMER4   0xf0005c04  // Wide Timer 4
#define SYSCTL_PERIPH_WTIMER5   0xf0005c05  // Wide Timer 5
#define SYSCTL_PERIPH2_UART0    0xf0001800  // UART 0
#define SYSCTL_PERIPH2_UART1    0xf0001801  // UART 1
#define SYSCTL_PERIPH2_UART2    0xf0001802  // UART 2
#define SYSCTL_PERIPH_UART3     0xf0001803  // UART 3
#define SYSCTL_PERIPH_UART4     0xf0001804  // UART 4
#define SYSCTL_PERIPH_UART5     0xf0001805  // UART 5
#define SYSCTL_PERIPH_UART6     0xf0001806  // UART 6
#define SYSCTL_PERIPH_UART7     0xf0001807  // UART 7
#define SYSCTL_PERIPH2_UDMA     0xf0000c00  // uDMA
#define SYSCTL_PERIPH2_USB0     0xf0002800  // USB 0
#define SYSCTL_PERIPH2_WDOG0    0xf0000000  // Watchdog 0
#define SYSCTL_PERIPH2_WDOG1    0xf0000001  // Watchdog 1
#define SYSCTL_PERIPH2_HIBERNATE \
                                0xf0001400  // Hibernate

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlPinPresent() API
// as the ulPin parameter.
//
//*****************************************************************************
#define SYSCTL_PIN_PWM0         0x00000001  // PWM0 pin
#define SYSCTL_PIN_PWM1         0x00000002  // PWM1 pin
#define SYSCTL_PIN_PWM2         0x00000004  // PWM2 pin
#define SYSCTL_PIN_PWM3         0x00000008  // PWM3 pin
#define SYSCTL_PIN_PWM4         0x00000010  // PWM4 pin
#define SYSCTL_PIN_PWM5         0x00000020  // PWM5 pin
#define SYSCTL_PIN_PWM6         0x00000040  // PWM6 pin
#define SYSCTL_PIN_PWM7         0x00000080  // PWM7 pin
#define SYSCTL_PIN_C0MINUS      0x00000040  // C0- pin
#define SYSCTL_PIN_C0PLUS       0x00000080  // C0+ pin
#define SYSCTL_PIN_C0O          0x00000100  // C0o pin
#define SYSCTL_PIN_C1MINUS      0x00000200  // C1- pin
#define SYSCTL_PIN_C1PLUS       0x00000400  // C1+ pin
#define SYSCTL_PIN_C1O          0x00000800  // C1o pin
#define SYSCTL_PIN_C2MINUS      0x00001000  // C2- pin
#define SYSCTL_PIN_C2PLUS       0x00002000  // C2+ pin
#define SYSCTL_PIN_C2O          0x00004000  // C2o pin
#define SYSCTL_PIN_MC_FAULT0    0x00008000  // MC0 Fault pin
#define SYSCTL_PIN_ADC0         0x00010000  // ADC0 pin
#define SYSCTL_PIN_ADC1         0x00020000  // ADC1 pin
#define SYSCTL_PIN_ADC2         0x00040000  // ADC2 pin
#define SYSCTL_PIN_ADC3         0x00080000  // ADC3 pin
#define SYSCTL_PIN_ADC4         0x00100000  // ADC4 pin
#define SYSCTL_PIN_ADC5         0x00200000  // ADC5 pin
#define SYSCTL_PIN_ADC6         0x00400000  // ADC6 pin
#define SYSCTL_PIN_ADC7         0x00800000  // ADC7 pin
#define SYSCTL_PIN_CCP0         0x01000000  // CCP0 pin
#define SYSCTL_PIN_CCP1         0x02000000  // CCP1 pin
#define SYSCTL_PIN_CCP2         0x04000000  // CCP2 pin
#define SYSCTL_PIN_CCP3         0x08000000  // CCP3 pin
#define SYSCTL_PIN_CCP4         0x10000000  // CCP4 pin
#define SYSCTL_PIN_CCP5         0x20000000  // CCP5 pin
#define SYSCTL_PIN_32KHZ        0x80000000  // 32kHz pin

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlLDOSet() API as
// the ulVoltage value, or returned by the SysCtlLDOGet() API.
//
//*****************************************************************************
#define SYSCTL_LDO_2_25V        0x00000005  // LDO output of 2.25V
#define SYSCTL_LDO_2_30V        0x00000004  // LDO output of 2.30V
#define SYSCTL_LDO_2_35V        0x00000003  // LDO output of 2.35V
#define SYSCTL_LDO_2_40V        0x00000002  // LDO output of 2.40V
#define SYSCTL_LDO_2_45V        0x00000001  // LDO output of 2.45V
#define SYSCTL_LDO_2_50V        0x00000000  // LDO output of 2.50V
#define SYSCTL_LDO_2_55V        0x0000001f  // LDO output of 2.55V
#define SYSCTL_LDO_2_60V        0x0000001e  // LDO output of 2.60V
#define SYSCTL_LDO_2_65V        0x0000001d  // LDO output of 2.65V
#define SYSCTL_LDO_2_70V        0x0000001c  // LDO output of 2.70V
#define SYSCTL_LDO_2_75V        0x0000001b  // LDO output of 2.75V

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlLDOConfigSet() API.
//
//*****************************************************************************
#define SYSCTL_LDOCFG_ARST      0x00000001  // Allow LDO failure to reset
#define SYSCTL_LDOCFG_NORST     0x00000000  // Do not reset on LDO failure

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlIntEnable(),
// SysCtlIntDisable(), and SysCtlIntClear() APIs, or returned in the bit mask
// by the SysCtlIntStatus() API.
//
//*****************************************************************************
#define SYSCTL_INT_MOSC_PUP     0x00000100  // MOSC power-up interrupt
#define SYSCTL_INT_USBPLL_LOCK  0x00000080  // USB PLL lock interrupt
#define SYSCTL_INT_PLL_LOCK     0x00000040  // PLL lock interrupt
#define SYSCTL_INT_CUR_LIMIT    0x00000020  // Current limit interrupt
#define SYSCTL_INT_IOSC_FAIL    0x00000010  // Internal oscillator failure int
#define SYSCTL_INT_MOSC_FAIL    0x00000008  // Main oscillator failure int
#define SYSCTL_INT_POR          0x00000004  // Power on reset interrupt
#define SYSCTL_INT_BOR          0x00000002  // Brown out interrupt
#define SYSCTL_INT_PLL_FAIL     0x00000001  // PLL failure interrupt

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlResetCauseClear()
// API or returned by the SysCtlResetCauseGet() API.
//
//*****************************************************************************
#define SYSCTL_CAUSE_LDO        0x00000020  // LDO power not OK reset
#define SYSCTL_CAUSE_WDOG1      0x00000020  // Watchdog 1 reset
#define SYSCTL_CAUSE_SW         0x00000010  // Software reset
#define SYSCTL_CAUSE_WDOG0      0x00000008  // Watchdog 0 reset
#define SYSCTL_CAUSE_WDOG       0x00000008  // Watchdog reset
#define SYSCTL_CAUSE_BOR        0x00000004  // Brown-out reset
#define SYSCTL_CAUSE_POR        0x00000002  // Power on reset
#define SYSCTL_CAUSE_EXT        0x00000001  // External reset

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlBrownOutConfigSet()
// API as the ulConfig parameter.
//
//*****************************************************************************
#define SYSCTL_BOR_RESET        0x00000002  // Reset instead of interrupting
#define SYSCTL_BOR_RESAMPLE     0x00000001  // Resample BOR before asserting

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlPWMClockSet() API
// as the ulConfig parameter, and can be returned by the SysCtlPWMClockGet()
// API.
//
//*****************************************************************************
#define SYSCTL_PWMDIV_1         0x00000000  // PWM clock is processor clock /1
#define SYSCTL_PWMDIV_2         0x00100000  // PWM clock is processor clock /2
#define SYSCTL_PWMDIV_4         0x00120000  // PWM clock is processor clock /4
#define SYSCTL_PWMDIV_8         0x00140000  // PWM clock is processor clock /8
#define SYSCTL_PWMDIV_16        0x00160000  // PWM clock is processor clock /16
#define SYSCTL_PWMDIV_32        0x00180000  // PWM clock is processor clock /32
#define SYSCTL_PWMDIV_64        0x001A0000  // PWM clock is processor clock /64

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlADCSpeedSet() API
// as the ulSpeed parameter, and can be returned by the SyCtlADCSpeedGet()
// API.
//
//*****************************************************************************
#define SYSCTL_ADCSPEED_1MSPS   0x00000F00  // 1,000,000 samples per second
#define SYSCTL_ADCSPEED_500KSPS 0x00000A00  // 500,000 samples per second
#define SYSCTL_ADCSPEED_250KSPS 0x00000500  // 250,000 samples per second
#define SYSCTL_ADCSPEED_125KSPS 0x00000000  // 125,000 samples per second

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlClockSet() API as
// the ulConfig parameter.
//
//*****************************************************************************
#define SYSCTL_SYSDIV_1         0x07800000  // Processor clock is osc/pll /1
#define SYSCTL_SYSDIV_2         0x00C00000  // Processor clock is osc/pll /2
#define SYSCTL_SYSDIV_3         0x01400000  // Processor clock is osc/pll /3
#define SYSCTL_SYSDIV_4         0x01C00000  // Processor clock is osc/pll /4
#define SYSCTL_SYSDIV_5         0x02400000  // Processor clock is osc/pll /5
#define SYSCTL_SYSDIV_6         0x02C00000  // Processor clock is osc/pll /6
#define SYSCTL_SYSDIV_7         0x03400000  // Processor clock is osc/pll /7
#define SYSCTL_SYSDIV_8         0x03C00000  // Processor clock is osc/pll /8
#define SYSCTL_SYSDIV_9         0x04400000  // Processor clock is osc/pll /9
#define SYSCTL_SYSDIV_10        0x04C00000  // Processor clock is osc/pll /10
#define SYSCTL_SYSDIV_11        0x05400000  // Processor clock is osc/pll /11
#define SYSCTL_SYSDIV_12        0x05C00000  // Processor clock is osc/pll /12
#define SYSCTL_SYSDIV_13        0x06400000  // Processor clock is osc/pll /13
#define SYSCTL_SYSDIV_14        0x06C00000  // Processor clock is osc/pll /14
#define SYSCTL_SYSDIV_15        0x07400000  // Processor clock is osc/pll /15
#define SYSCTL_SYSDIV_16        0x07C00000  // Processor clock is osc/pll /16
#define SYSCTL_SYSDIV_17        0x88400000  // Processor clock is osc/pll /17
#define SYSCTL_SYSDIV_18        0x88C00000  // Processor clock is osc/pll /18
#define SYSCTL_SYSDIV_19        0x89400000  // Processor clock is osc/pll /19
#define SYSCTL_SYSDIV_20        0x89C00000  // Processor clock is osc/pll /20
#define SYSCTL_SYSDIV_21        0x8A400000  // Processor clock is osc/pll /21
#define SYSCTL_SYSDIV_22        0x8AC00000  // Processor clock is osc/pll /22
#define SYSCTL_SYSDIV_23        0x8B400000  // Processor clock is osc/pll /23
#define SYSCTL_SYSDIV_24        0x8BC00000  // Processor clock is osc/pll /24
#define SYSCTL_SYSDIV_25        0x8C400000  // Processor clock is osc/pll /25
#define SYSCTL_SYSDIV_26        0x8CC00000  // Processor clock is osc/pll /26
#define SYSCTL_SYSDIV_27        0x8D400000  // Processor clock is osc/pll /27
#define SYSCTL_SYSDIV_28        0x8DC00000  // Processor clock is osc/pll /28
#define SYSCTL_SYSDIV_29        0x8E400000  // Processor clock is osc/pll /29
#define SYSCTL_SYSDIV_30        0x8EC00000  // Processor clock is osc/pll /30
#define SYSCTL_SYSDIV_31        0x8F400000  // Processor clock is osc/pll /31
#define SYSCTL_SYSDIV_32        0x8FC00000  // Processor clock is osc/pll /32
#define SYSCTL_SYSDIV_33        0x90400000  // Processor clock is osc/pll /33
#define SYSCTL_SYSDIV_34        0x90C00000  // Processor clock is osc/pll /34
#define SYSCTL_SYSDIV_35        0x91400000  // Processor clock is osc/pll /35
#define SYSCTL_SYSDIV_36        0x91C00000  // Processor clock is osc/pll /36
#define SYSCTL_SYSDIV_37        0x92400000  // Processor clock is osc/pll /37
#define SYSCTL_SYSDIV_38        0x92C00000  // Processor clock is osc/pll /38
#define SYSCTL_SYSDIV_39        0x93400000  // Processor clock is osc/pll /39
#define SYSCTL_SYSDIV_40        0x93C00000  // Processor clock is osc/pll /40
#define SYSCTL_SYSDIV_41        0x94400000  // Processor clock is osc/pll /41
#define SYSCTL_SYSDIV_42        0x94C00000  // Processor clock is osc/pll /42
#define SYSCTL_SYSDIV_43        0x95400000  // Processor clock is osc/pll /43
#define SYSCTL_SYSDIV_44        0x95C00000  // Processor clock is osc/pll /44
#define SYSCTL_SYSDIV_45        0x96400000  // Processor clock is osc/pll /45
#define SYSCTL_SYSDIV_46        0x96C00000  // Processor clock is osc/pll /46
#define SYSCTL_SYSDIV_47        0x97400000  // Processor clock is osc/pll /47
#define SYSCTL_SYSDIV_48        0x97C00000  // Processor clock is osc/pll /48
#define SYSCTL_SYSDIV_49        0x98400000  // Processor clock is osc/pll /49
#define SYSCTL_SYSDIV_50        0x98C00000  // Processor clock is osc/pll /50
#define SYSCTL_SYSDIV_51        0x99400000  // Processor clock is osc/pll /51
#define SYSCTL_SYSDIV_52        0x99C00000  // Processor clock is osc/pll /52
#define SYSCTL_SYSDIV_53        0x9A400000  // Processor clock is osc/pll /53
#define SYSCTL_SYSDIV_54        0x9AC00000  // Processor clock is osc/pll /54
#define SYSCTL_SYSDIV_55        0x9B400000  // Processor clock is osc/pll /55
#define SYSCTL_SYSDIV_56        0x9BC00000  // Processor clock is osc/pll /56
#define SYSCTL_SYSDIV_57        0x9C400000  // Processor clock is osc/pll /57
#define SYSCTL_SYSDIV_58        0x9CC00000  // Processor clock is osc/pll /58
#define SYSCTL_SYSDIV_59        0x9D400000  // Processor clock is osc/pll /59
#define SYSCTL_SYSDIV_60        0x9DC00000  // Processor clock is osc/pll /60
#define SYSCTL_SYSDIV_61        0x9E400000  // Processor clock is osc/pll /61
#define SYSCTL_SYSDIV_62        0x9EC00000  // Processor clock is osc/pll /62
#define SYSCTL_SYSDIV_63        0x9F400000  // Processor clock is osc/pll /63
#define SYSCTL_SYSDIV_64        0x9FC00000  // Processor clock is osc/pll /64
#define SYSCTL_SYSDIV_2_5       0xC1000000  // Processor clock is pll / 2.5
#define SYSCTL_SYSDIV_3_5       0xC1800000  // Processor clock is pll / 3.5
#define SYSCTL_SYSDIV_4_5       0xC2000000  // Processor clock is pll / 4.5
#define SYSCTL_SYSDIV_5_5       0xC2800000  // Processor clock is pll / 5.5
#define SYSCTL_SYSDIV_6_5       0xC3000000  // Processor clock is pll / 6.5
#define SYSCTL_SYSDIV_7_5       0xC3800000  // Processor clock is pll / 7.5
#define SYSCTL_SYSDIV_8_5       0xC4000000  // Processor clock is pll / 8.5
#define SYSCTL_SYSDIV_9_5       0xC4800000  // Processor clock is pll / 9.5
#define SYSCTL_SYSDIV_10_5      0xC5000000  // Processor clock is pll / 10.5
#define SYSCTL_SYSDIV_11_5      0xC5800000  // Processor clock is pll / 11.5
#define SYSCTL_SYSDIV_12_5      0xC6000000  // Processor clock is pll / 12.5
#define SYSCTL_SYSDIV_13_5      0xC6800000  // Processor clock is pll / 13.5
#define SYSCTL_SYSDIV_14_5      0xC7000000  // Processor clock is pll / 14.5
#define SYSCTL_SYSDIV_15_5      0xC7800000  // Processor clock is pll / 15.5
#define SYSCTL_SYSDIV_16_5      0xC8000000  // Processor clock is pll / 16.5
#define SYSCTL_SYSDIV_17_5      0xC8800000  // Processor clock is pll / 17.5
#define SYSCTL_SYSDIV_18_5      0xC9000000  // Processor clock is pll / 18.5
#define SYSCTL_SYSDIV_19_5      0xC9800000  // Processor clock is pll / 19.5
#define SYSCTL_SYSDIV_20_5      0xCA000000  // Processor clock is pll / 20.5
#define SYSCTL_SYSDIV_21_5      0xCA800000  // Processor clock is pll / 21.5
#define SYSCTL_SYSDIV_22_5      0xCB000000  // Processor clock is pll / 22.5
#define SYSCTL_SYSDIV_23_5      0xCB800000  // Processor clock is pll / 23.5
#define SYSCTL_SYSDIV_24_5      0xCC000000  // Processor clock is pll / 24.5
#define SYSCTL_SYSDIV_25_5      0xCC800000  // Processor clock is pll / 25.5
#define SYSCTL_SYSDIV_26_5      0xCD000000  // Processor clock is pll / 26.5
#define SYSCTL_SYSDIV_27_5      0xCD800000  // Processor clock is pll / 27.5
#define SYSCTL_SYSDIV_28_5      0xCE000000  // Processor clock is pll / 28.5
#define SYSCTL_SYSDIV_29_5      0xCE800000  // Processor clock is pll / 29.5
#define SYSCTL_SYSDIV_30_5      0xCF000000  // Processor clock is pll / 30.5
#define SYSCTL_SYSDIV_31_5      0xCF800000  // Processor clock is pll / 31.5
#define SYSCTL_SYSDIV_32_5      0xD0000000  // Processor clock is pll / 32.5
#define SYSCTL_SYSDIV_33_5      0xD0800000  // Processor clock is pll / 33.5
#define SYSCTL_SYSDIV_34_5      0xD1000000  // Processor clock is pll / 34.5
#define SYSCTL_SYSDIV_35_5      0xD1800000  // Processor clock is pll / 35.5
#define SYSCTL_SYSDIV_36_5      0xD2000000  // Processor clock is pll / 36.5
#define SYSCTL_SYSDIV_37_5      0xD2800000  // Processor clock is pll / 37.5
#define SYSCTL_SYSDIV_38_5      0xD3000000  // Processor clock is pll / 38.5
#define SYSCTL_SYSDIV_39_5      0xD3800000  // Processor clock is pll / 39.5
#define SYSCTL_SYSDIV_40_5      0xD4000000  // Processor clock is pll / 40.5
#define SYSCTL_SYSDIV_41_5      0xD4800000  // Processor clock is pll / 41.5
#define SYSCTL_SYSDIV_42_5      0xD5000000  // Processor clock is pll / 42.5
#define SYSCTL_SYSDIV_43_5      0xD5800000  // Processor clock is pll / 43.5
#define SYSCTL_SYSDIV_44_5      0xD6000000  // Processor clock is pll / 44.5
#define SYSCTL_SYSDIV_45_5      0xD6800000  // Processor clock is pll / 45.5
#define SYSCTL_SYSDIV_46_5      0xD7000000  // Processor clock is pll / 46.5
#define SYSCTL_SYSDIV_47_5      0xD7800000  // Processor clock is pll / 47.5
#define SYSCTL_SYSDIV_48_5      0xD8000000  // Processor clock is pll / 48.5
#define SYSCTL_SYSDIV_49_5      0xD8800000  // Processor clock is pll / 49.5
#define SYSCTL_SYSDIV_50_5      0xD9000000  // Processor clock is pll / 50.5
#define SYSCTL_SYSDIV_51_5      0xD9800000  // Processor clock is pll / 51.5
#define SYSCTL_SYSDIV_52_5      0xDA000000  // Processor clock is pll / 52.5
#define SYSCTL_SYSDIV_53_5      0xDA800000  // Processor clock is pll / 53.5
#define SYSCTL_SYSDIV_54_5      0xDB000000  // Processor clock is pll / 54.5
#define SYSCTL_SYSDIV_55_5      0xDB800000  // Processor clock is pll / 55.5
#define SYSCTL_SYSDIV_56_5      0xDC000000  // Processor clock is pll / 56.5
#define SYSCTL_SYSDIV_57_5      0xDC800000  // Processor clock is pll / 57.5
#define SYSCTL_SYSDIV_58_5      0xDD000000  // Processor clock is pll / 58.5
#define SYSCTL_SYSDIV_59_5      0xDD800000  // Processor clock is pll / 59.5
#define SYSCTL_SYSDIV_60_5      0xDE000000  // Processor clock is pll / 60.5
#define SYSCTL_SYSDIV_61_5      0xDE800000  // Processor clock is pll / 61.5
#define SYSCTL_SYSDIV_62_5      0xDF000000  // Processor clock is pll / 62.5
#define SYSCTL_SYSDIV_63_5      0xDF800000  // Processor clock is pll / 63.5
#define SYSCTL_USE_PLL          0x00000000  // System clock is the PLL clock
#define SYSCTL_USE_OSC          0x00003800  // System clock is the osc clock
#define SYSCTL_XTAL_1MHZ        0x00000000  // External crystal is 1MHz
#define SYSCTL_XTAL_1_84MHZ     0x00000040  // External crystal is 1.8432MHz
#define SYSCTL_XTAL_2MHZ        0x00000080  // External crystal is 2MHz
#define SYSCTL_XTAL_2_45MHZ     0x000000C0  // External crystal is 2.4576MHz
#define SYSCTL_XTAL_3_57MHZ     0x00000100  // External crystal is 3.579545MHz
#define SYSCTL_XTAL_3_68MHZ     0x00000140  // External crystal is 3.6864MHz
#define SYSCTL_XTAL_4MHZ        0x00000180  // External crystal is 4MHz
#define SYSCTL_XTAL_4_09MHZ     0x000001C0  // External crystal is 4.096MHz
#define SYSCTL_XTAL_4_91MHZ     0x00000200  // External crystal is 4.9152MHz
#define SYSCTL_XTAL_5MHZ        0x00000240  // External crystal is 5MHz
#define SYSCTL_XTAL_5_12MHZ     0x00000280  // External crystal is 5.12MHz
#define SYSCTL_XTAL_6MHZ        0x000002C0  // External crystal is 6MHz
#define SYSCTL_XTAL_6_14MHZ     0x00000300  // External crystal is 6.144MHz
#define SYSCTL_XTAL_7_37MHZ     0x00000340  // External crystal is 7.3728MHz
#define SYSCTL_XTAL_8MHZ        0x00000380  // External crystal is 8MHz
#define SYSCTL_XTAL_8_19MHZ     0x000003C0  // External crystal is 8.192MHz
#define SYSCTL_XTAL_10MHZ       0x00000400  // External crystal is 10 MHz
#define SYSCTL_XTAL_12MHZ       0x00000440  // External crystal is 12 MHz
#define SYSCTL_XTAL_12_2MHZ     0x00000480  // External crystal is 12.288 MHz
#define SYSCTL_XTAL_13_5MHZ     0x000004C0  // External crystal is 13.56 MHz
#define SYSCTL_XTAL_14_3MHZ     0x00000500  // External crystal is 14.31818 MHz
#define SYSCTL_XTAL_16MHZ       0x00000540  // External crystal is 16 MHz
#define SYSCTL_XTAL_16_3MHZ     0x00000580  // External crystal is 16.384 MHz
#define SYSCTL_XTAL_18MHZ       0x000005C0  // External crystal is 18.0 MHz
#define SYSCTL_XTAL_20MHZ       0x00000600  // External crystal is 20.0 MHz
#define SYSCTL_XTAL_24MHZ       0x00000640  // External crystal is 24.0 MHz
#define SYSCTL_XTAL_25MHZ       0x00000680  // External crystal is 25.0 MHz
#define SYSCTL_OSC_MAIN         0x00000000  // Osc source is main osc
#define SYSCTL_OSC_INT          0x00000010  // Osc source is int. osc
#define SYSCTL_OSC_INT4         0x00000020  // Osc source is int. osc /4
#define SYSCTL_OSC_INT30        0x00000030  // Osc source is int. 30 KHz
#define SYSCTL_OSC_EXT4_19      0x80000028  // Osc source is ext. 4.19 MHz
#define SYSCTL_OSC_EXT32        0x80000038  // Osc source is ext. 32 KHz
#define SYSCTL_INT_OSC_DIS      0x00000002  // Disable internal oscillator
#define SYSCTL_MAIN_OSC_DIS     0x00000001  // Disable main oscillator

//*****************************************************************************
//
// The following are values that can be passed to the SysCtlDeepSleepClockSet()
// API as the ulConfig parameter.
//
//*****************************************************************************
#define SYSCTL_DSLP_DIV_1       0x00000000  // Deep-sleep clock is osc /1
#define SYSCTL_DSLP_DIV_2       0x00800000  // Deep-sleep clock is osc /2
#define SYSCTL_DSLP_DIV_3       0x01000000  // Deep-sleep clock is osc /3
#define SYSCTL_DSLP_DIV_4       0x01800000  // Deep-sleep clock is osc /4
#define SYSCTL_DSLP_DIV_5       0x02000000  // Deep-sleep clock is osc /5
#define SYSCTL_DSLP_DIV_6       0x02800000  // Deep-sleep clock is osc /6
#define SYSCTL_DSLP_DIV_7       0x03000000  // Deep-sleep clock is osc /7
#define SYSCTL_DSLP_DIV_8       0x03800000  // Deep-sleep clock is osc /8
#define SYSCTL_DSLP_DIV_9       0x04000000  // Deep-sleep clock is osc /9
#define SYSCTL_DSLP_DIV_10      0x04800000  // Deep-sleep clock is osc /10
#define SYSCTL_DSLP_DIV_11      0x05000000  // Deep-sleep clock is osc /11
#define SYSCTL_DSLP_DIV_12      0x05800000  // Deep-sleep clock is osc /12
#define SYSCTL_DSLP_DIV_13      0x06000000  // Deep-sleep clock is osc /13
#define SYSCTL_DSLP_DIV_14      0x06800000  // Deep-sleep clock is osc /14
#define SYSCTL_DSLP_DIV_15      0x07000000  // Deep-sleep clock is osc /15
#define SYSCTL_DSLP_DIV_16      0x07800000  // Deep-sleep clock is osc /16
#define SYSCTL_DSLP_DIV_17      0x08000000  // Deep-sleep clock is osc /17
#define SYSCTL_DSLP_DIV_18      0x08800000  // Deep-sleep clock is osc /18
#define SYSCTL_DSLP_DIV_19      0x09000000  // Deep-sleep clock is osc /19
#define SYSCTL_DSLP_DIV_20      0x09800000  // Deep-sleep clock is osc /20
#define SYSCTL_DSLP_DIV_21      0x0A000000  // Deep-sleep clock is osc /21
#define SYSCTL_DSLP_DIV_22      0x0A800000  // Deep-sleep clock is osc /22
#define SYSCTL_DSLP_DIV_23      0x0B000000  // Deep-sleep clock is osc /23
#define SYSCTL_DSLP_DIV_24      0x0B800000  // Deep-sleep clock is osc /24
#define SYSCTL_DSLP_DIV_25      0x0C000000  // Deep-sleep clock is osc /25
#define SYSCTL_DSLP_DIV_26      0x0C800000  // Deep-sleep clock is osc /26
#define SYSCTL_DSLP_DIV_27      0x0D000000  // Deep-sleep clock is osc /27
#define SYSCTL_DSLP_DIV_28      0x0D800000  // Deep-sleep clock is osc /28
#define SYSCTL_DSLP_DIV_29      0x0E000000  // Deep-sleep clock is osc /29
#define SYSCTL_DSLP_DIV_30      0x0E800000  // Deep-sleep clock is osc /30
#define SYSCTL_DSLP_DIV_31      0x0F000000  // Deep-sleep clock is osc /31
#define SYSCTL_DSLP_DIV_32      0x0F800000  // Deep-sleep clock is osc /32
#define SYSCTL_DSLP_DIV_33      0x10000000  // Deep-sleep clock is osc /33
#define SYSCTL_DSLP_DIV_34      0x10800000  // Deep-sleep clock is osc /34
#define SYSCTL_DSLP_DIV_35      0x11000000  // Deep-sleep clock is osc /35
#define SYSCTL_DSLP_DIV_36      0x11800000  // Deep-sleep clock is osc /36
#define SYSCTL_DSLP_DIV_37      0x12000000  // Deep-sleep clock is osc /37
#define SYSCTL_DSLP_DIV_38      0x12800000  // Deep-sleep clock is osc /38
#define SYSCTL_DSLP_DIV_39      0x13000000  // Deep-sleep clock is osc /39
#define SYSCTL_DSLP_DIV_40      0x13800000  // Deep-sleep clock is osc /40
#define SYSCTL_DSLP_DIV_41      0x14000000  // Deep-sleep clock is osc /41
#define SYSCTL_DSLP_DIV_42      0x14800000  // Deep-sleep clock is osc /42
#define SYSCTL_DSLP_DIV_43      0x15000000  // Deep-sleep clock is osc /43
#define SYSCTL_DSLP_DIV_44      0x15800000  // Deep-sleep clock is osc /44
#define SYSCTL_DSLP_DIV_45      0x16000000  // Deep-sleep clock is osc /45
#define SYSCTL_DSLP_DIV_46      0x16800000  // Deep-sleep clock is osc /46
#define SYSCTL_DSLP_DIV_47      0x17000000  // Deep-sleep clock is osc /47
#define SYSCTL_DSLP_DIV_48      0x17800000  // Deep-sleep clock is osc /48
#define SYSCTL_DSLP_DIV_49      0x18000000  // Deep-sleep clock is osc /49
#define SYSCTL_DSLP_DIV_50      0x18800000  // Deep-sleep clock is osc /50
#define SYSCTL_DSLP_DIV_51      0x19000000  // Deep-sleep clock is osc /51
#define SYSCTL_DSLP_DIV_52      0x19800000  // Deep-sleep clock is osc /52
#define SYSCTL_DSLP_DIV_53      0x1A000000  // Deep-sleep clock is osc /53
#define SYSCTL_DSLP_DIV_54      0x1A800000  // Deep-sleep clock is osc /54
#define SYSCTL_DSLP_DIV_55      0x1B000000  // Deep-sleep clock is osc /55
#define SYSCTL_DSLP_DIV_56      0x1B800000  // Deep-sleep clock is osc /56
#define SYSCTL_DSLP_DIV_57      0x1C000000  // Deep-sleep clock is osc /57
#define SYSCTL_DSLP_DIV_58      0x1C800000  // Deep-sleep clock is osc /58
#define SYSCTL_DSLP_DIV_59      0x1D000000  // Deep-sleep clock is osc /59
#define SYSCTL_DSLP_DIV_60      0x1D800000  // Deep-sleep clock is osc /60
#define SYSCTL_DSLP_DIV_61      0x1E000000  // Deep-sleep clock is osc /61
#define SYSCTL_DSLP_DIV_62      0x1E800000  // Deep-sleep clock is osc /62
#define SYSCTL_DSLP_DIV_63      0x1F000000  // Deep-sleep clock is osc /63
#define SYSCTL_DSLP_DIV_64      0x1F800000  // Deep-sleep clock is osc /64
#define SYSCTL_DSLP_OSC_MAIN    0x00000000  // Osc source is main osc
#define SYSCTL_DSLP_OSC_INT     0x00000010  // Osc source is int. osc
#define SYSCTL_DSLP_OSC_INT30   0x00000030  // Osc source is int. 30 KHz
#define SYSCTL_DSLP_OSC_EXT32   0x00000070  // Osc source is ext. 32 KHz
#define SYSCTL_DSLP_PIOSC_PD    0x00000002  // Power down PIOSC in deep-sleep

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern unsigned long SysCtlSRAMSizeGet(void);
extern unsigned long SysCtlFlashSizeGet(void);
extern tBoolean SysCtlPinPresent(unsigned long ulPin);
extern tBoolean SysCtlPeripheralPresent(unsigned long ulPeripheral);
extern tBoolean SysCtlPeripheralReady(unsigned long ulPeripheral);
extern void SysCtlPeripheralPowerOn(unsigned long ulPeripheral);
extern void SysCtlPeripheralPowerOff(unsigned long ulPeripheral);
extern void SysCtlPeripheralReset(unsigned long ulPeripheral);
extern void SysCtlPeripheralEnable(unsigned long ulPeripheral);
extern void SysCtlPeripheralDisable(unsigned long ulPeripheral);
extern void SysCtlPeripheralSleepEnable(unsigned long ulPeripheral);
extern void SysCtlPeripheralSleepDisable(unsigned long ulPeripheral);
extern void SysCtlPeripheralDeepSleepEnable(unsigned long ulPeripheral);
extern void SysCtlPeripheralDeepSleepDisable(unsigned long ulPeripheral);
extern void SysCtlPeripheralClockGating(tBoolean bEnable);
extern void SysCtlIntRegister(void (*pfnHandler)(void));
extern void SysCtlIntUnregister(void);
extern void SysCtlIntEnable(unsigned long ulInts);
extern void SysCtlIntDisable(unsigned long ulInts);
extern void SysCtlIntClear(unsigned long ulInts);
extern unsigned long SysCtlIntStatus(tBoolean bMasked);
extern void SysCtlLDOSet(unsigned long ulVoltage);
extern unsigned long SysCtlLDOGet(void);
extern void SysCtlLDOConfigSet(unsigned long ulConfig);
extern void SysCtlReset(void);
extern void SysCtlSleep(void);
extern void SysCtlDeepSleep(void);
extern unsigned long SysCtlResetCauseGet(void);
extern void SysCtlResetCauseClear(unsigned long ulCauses);
extern void SysCtlBrownOutConfigSet(unsigned long ulConfig,
                                    unsigned long ulDelay);
extern void SysCtlDelay(unsigned long ulCount);
extern void SysCtlMOSCConfigSet(unsigned long ulConfig);
extern unsigned long SysCtlPIOSCCalibrate(unsigned long ulType);
extern void SysCtlClockSet(unsigned long ulConfig);
extern unsigned long SysCtlClockGet(void);
extern void SysCtlDeepSleepClockSet(unsigned long ulConfig);
extern void SysCtlPWMClockSet(unsigned long ulConfig);
extern unsigned long SysCtlPWMClockGet(void);
extern void SysCtlADCSpeedSet(unsigned long ulSpeed);
extern unsigned long SysCtlADCSpeedGet(void);
extern void SysCtlIOSCVerificationSet(tBoolean bEnable);
extern void SysCtlMOSCVerificationSet(tBoolean bEnable);
extern void SysCtlPLLVerificationSet(tBoolean bEnable);
extern void SysCtlClkVerificationClear(void);
extern void SysCtlGPIOAHBEnable(unsigned long ulGPIOPeripheral);
extern void SysCtlGPIOAHBDisable(unsigned long ulGPIOPeripheral);
extern void SysCtlUSBPLLEnable(void);
extern void SysCtlUSBPLLDisable(void);
extern unsigned long SysCtlI2SMClkSet(unsigned long ulInputClock,
                                      unsigned long ulMClk);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __SYSCTL_H__
