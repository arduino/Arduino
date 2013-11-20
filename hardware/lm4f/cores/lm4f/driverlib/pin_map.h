//*****************************************************************************
//
// pin_map.h - Mapping of peripherals to pins for all parts.
//
// Copyright (c) 2007-2013 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_PIN_MAP_H__
#define __DRIVERLIB_PIN_MAP_H__

//*****************************************************************************
//
// TM4C1230C3PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1230C3PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1230C3PM

//*****************************************************************************
//
// TM4C1230D5PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1230D5PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1230D5PM

//*****************************************************************************
//
// TM4C1230E6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1230E6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1230E6PM

//*****************************************************************************
//
// TM4C1230H6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1230H6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1230H6PM

//*****************************************************************************
//
// TM4C1231C3PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231C3PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1231C3PM

//*****************************************************************************
//
// TM4C1231D5PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231D5PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1231D5PM

//*****************************************************************************
//
// TM4C1231D5PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231D5PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1231D5PZ

//*****************************************************************************
//
// TM4C1231E6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231E6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1231E6PM

//*****************************************************************************
//
// TM4C1231E6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231E6PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1231E6PZ

//*****************************************************************************
//
// TM4C1231H6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231H6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1231H6PM

//*****************************************************************************
//
// TM4C1231H6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231H6PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1231H6PZ

//*****************************************************************************
//
// TM4C1232C3PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1232C3PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1232C3PM

//*****************************************************************************
//
// TM4C1232D5PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1232D5PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1232D5PM

//*****************************************************************************
//
// TM4C1232E6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1232E6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1232E6PM

//*****************************************************************************
//
// TM4C1232H6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1232H6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C1232H6PM

//*****************************************************************************
//
// TM4C1233C3PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233C3PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1233C3PM

//*****************************************************************************
//
// TM4C1233D5PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233D5PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1233D5PM

//*****************************************************************************
//
// TM4C1233D5PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233D5PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1233D5PZ

//*****************************************************************************
//
// TM4C1233E6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233E6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1233E6PM

//*****************************************************************************
//
// TM4C1233E6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233E6PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1233E6PZ

//*****************************************************************************
//
// TM4C1233H6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233H6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C1233H6PM

//*****************************************************************************
//
// TM4C1233H6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233H6PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1233H6PZ

//*****************************************************************************
//
// TM4C1236D5PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1236D5PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#endif // PART_TM4C1236D5PM

//*****************************************************************************
//
// TM4C1236E6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1236E6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#endif // PART_TM4C1236E6PM

//*****************************************************************************
//
// TM4C1236H6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1236H6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#endif // PART_TM4C1236H6PM

//*****************************************************************************
//
// TM4C1237D5PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237D5PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#endif // PART_TM4C1237D5PM

//*****************************************************************************
//
// TM4C1237D5PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237D5PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1237D5PZ

//*****************************************************************************
//
// TM4C1237E6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237E6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#endif // PART_TM4C1237E6PM

//*****************************************************************************
//
// TM4C1237E6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237E6PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1237E6PZ

//*****************************************************************************
//
// TM4C1237H6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237H6PM

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#endif // PART_TM4C1237H6PM

//*****************************************************************************
//
// TM4C1237H6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237H6PZ

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#endif // PART_TM4C1237H6PZ

//*****************************************************************************
//
// TM4C123AE6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123AE6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C123AE6PM

//*****************************************************************************
//
// TM4C123AH6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123AH6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407

#endif // PART_TM4C123AH6PM

//*****************************************************************************
//
// TM4C123BE6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123BE6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C123BE6PM

//*****************************************************************************
//
// TM4C123BE6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123BE6PZ

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#endif // PART_TM4C123BE6PZ

//*****************************************************************************
//
// TM4C123BH6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123BH6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007

#endif // PART_TM4C123BH6PM

//*****************************************************************************
//
// TM4C123BH6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123BH6PZ

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#endif // PART_TM4C123BH6PZ

//*****************************************************************************
//
// TM4C123FE6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123FE6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#endif // PART_TM4C123FE6PM

//*****************************************************************************
//
// TM4C123FH6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123FH6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#endif // PART_TM4C123FH6PM

//*****************************************************************************
//
// TM4C123GE6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123GE6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#endif // PART_TM4C123GE6PM

//*****************************************************************************
//
// TM4C123GE6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123GE6PZ

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#endif // PART_TM4C123GE6PZ

//*****************************************************************************
//
// TM4C123GH6PM Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123GH6PM

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#endif // PART_TM4C123GH6PM

//*****************************************************************************
//
// TM4C123GH6PZ Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123GH6PZ

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#endif // PART_TM4C123GH6PZ

//*****************************************************************************
//
// TM4C1231H6PGE Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1231H6PGE

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_T5CCP0         0x000D0807

#endif // PART_TM4C1231H6PGE

//*****************************************************************************
//
// TM4C1233H6PGE Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1233H6PGE

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_T5CCP0         0x000D0807

#endif // PART_TM4C1233H6PGE

//*****************************************************************************
//
// TM4C1237H6PGE Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1237H6PGE

#define GPIO_PA0_U0RX           0x00000001

#define GPIO_PA1_U0TX           0x00000401

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803

#define GPIO_PA7_I2C1SDA        0x00001C03

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE7_U1RI           0x00041C01

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002

#define GPIO_PK1_SSI3FSS        0x00090402

#define GPIO_PK2_SSI3RX         0x00090802

#define GPIO_PK3_SSI3TX         0x00090C02

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_T5CCP0         0x000D0807

#endif // PART_TM4C1237H6PGE

//*****************************************************************************
//
// TM4C123BH6PGE Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123BH6PGE

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_M0FAULT0       0x00091006
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_M0FAULT1       0x00091406
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_M0FAULT2       0x00091806
#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_M0FAULT3       0x00091C06
#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_M0PWM4         0x000B1802
#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_M0PWM5         0x000B1C02
#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_M0PWM6         0x000C0802
#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_M0PWM7         0x000C0C02
#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_M1PWM4         0x000C1002
#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_M1PWM5         0x000C1402
#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_M1PWM6         0x000C1802
#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_M1PWM7         0x000C1C02
#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_M0PWM0         0x000D0001
#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_M0PWM1         0x000D0401
#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_M0PWM2         0x000D0801
#define GPIO_PP2_T5CCP0         0x000D0807

#endif // PART_TM4C123BH6PGE

//*****************************************************************************
//
// TM4C123BH6ZRB Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123BH6ZRB

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_M0FAULT0       0x00091006
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_M0FAULT1       0x00091406
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_M0FAULT2       0x00091806
#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_M0FAULT3       0x00091C06
#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_M0PWM4         0x000B1802
#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_M0PWM5         0x000B1C02
#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_M0PWM6         0x000C0802
#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_M0PWM7         0x000C0C02
#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_M1PWM4         0x000C1002
#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_M1PWM5         0x000C1402
#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_M1PWM6         0x000C1802
#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_M1PWM7         0x000C1C02
#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_M0PWM0         0x000D0001
#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_M0PWM1         0x000D0401
#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_M0PWM2         0x000D0801
#define GPIO_PP2_T5CCP0         0x000D0807

#define GPIO_PP3_M0PWM3         0x000D0C01
#define GPIO_PP3_T5CCP1         0x000D0C07

#define GPIO_PP4_M0PWM4         0x000D1001
#define GPIO_PP4_WT0CCP0        0x000D1007

#define GPIO_PP5_M0PWM5         0x000D1401
#define GPIO_PP5_WT0CCP1        0x000D1407

#define GPIO_PP6_M0PWM6         0x000D1801
#define GPIO_PP6_WT1CCP0        0x000D1807

#define GPIO_PP7_M0PWM7         0x000D1C01
#define GPIO_PP7_WT1CCP1        0x000D1C07

#define GPIO_PQ0_M1PWM0         0x000E0001
#define GPIO_PQ0_WT2CCP0        0x000E0007

#define GPIO_PQ1_M1PWM1         0x000E0401
#define GPIO_PQ1_WT2CCP1        0x000E0407

#define GPIO_PQ2_M1PWM2         0x000E0801
#define GPIO_PQ2_WT3CCP0        0x000E0807

#define GPIO_PQ3_M1PWM3         0x000E0C01
#define GPIO_PQ3_WT3CCP1        0x000E0C07

#define GPIO_PQ4_M1PWM4         0x000E1001
#define GPIO_PQ4_WT4CCP0        0x000E1007

#define GPIO_PQ5_M1PWM5         0x000E1401
#define GPIO_PQ5_WT4CCP1        0x000E1407

#define GPIO_PQ6_M1PWM6         0x000E1801
#define GPIO_PQ6_WT5CCP0        0x000E1807

#define GPIO_PQ7_M1PWM7         0x000E1C01
#define GPIO_PQ7_WT5CCP1        0x000E1C07

#endif // PART_TM4C123BH6ZRB

//*****************************************************************************
//
// TM4C123GH6PGE Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123GH6PGE

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_M0FAULT0       0x00091006
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_M0FAULT1       0x00091406
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_M0FAULT2       0x00091806
#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_M0FAULT3       0x00091C06
#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_M0PWM4         0x000B1802
#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_M0PWM5         0x000B1C02
#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_M0PWM6         0x000C0802
#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_M0PWM7         0x000C0C02
#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_M1PWM4         0x000C1002
#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_M1PWM5         0x000C1402
#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_M1PWM6         0x000C1802
#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_M1PWM7         0x000C1C02
#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_M0PWM0         0x000D0001
#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_M0PWM1         0x000D0401
#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_M0PWM2         0x000D0801
#define GPIO_PP2_T5CCP0         0x000D0807

#endif // PART_TM4C123GH6PGE

//*****************************************************************************
//
// TM4C123GH6ZRB Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C123GH6ZRB

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_I2C5SCL        0x00011803
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_I2C5SDA        0x00011C03
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_M0FAULT1       0x00031C04
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PE6_CAN1RX         0x00041808

#define GPIO_PE7_U1RI           0x00041C01
#define GPIO_PE7_CAN1TX         0x00041C08

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009
#define GPIO_PF0_TRD2           0x0005000E

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_U1DCD          0x00050801
#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_C2O            0x00050809
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_U1DSR          0x00050C01
#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M0FAULT1       0x00050C04
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_U1DTR          0x00051001
#define GPIO_PF4_M0FAULT2       0x00051004
#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008
#define GPIO_PF4_TRD3           0x0005100E

#define GPIO_PF5_M0FAULT3       0x00051404
#define GPIO_PF5_T2CCP1         0x00051407
#define GPIO_PF5_USB0PFLT       0x00051408

#define GPIO_PF6_I2C2SCL        0x00051803
#define GPIO_PF6_T3CCP0         0x00051807

#define GPIO_PF7_I2C2SDA        0x00051C03
#define GPIO_PF7_M1FAULT0       0x00051C05
#define GPIO_PF7_T3CCP1         0x00051C07

#define GPIO_PG0_I2C3SCL        0x00060003
#define GPIO_PG0_M1FAULT1       0x00060005
#define GPIO_PG0_PHA1           0x00060006
#define GPIO_PG0_T4CCP0         0x00060007

#define GPIO_PG1_I2C3SDA        0x00060403
#define GPIO_PG1_M1FAULT2       0x00060405
#define GPIO_PG1_PHB1           0x00060406
#define GPIO_PG1_T4CCP1         0x00060407

#define GPIO_PG2_I2C4SCL        0x00060803
#define GPIO_PG2_M0FAULT1       0x00060804
#define GPIO_PG2_M1PWM0         0x00060805
#define GPIO_PG2_T5CCP0         0x00060807

#define GPIO_PG3_I2C4SDA        0x00060C03
#define GPIO_PG3_M0FAULT2       0x00060C04
#define GPIO_PG3_M1PWM1         0x00060C05
#define GPIO_PG3_PHA1           0x00060C06
#define GPIO_PG3_T5CCP1         0x00060C07

#define GPIO_PG4_U2RX           0x00061001
#define GPIO_PG4_I2C1SCL        0x00061003
#define GPIO_PG4_M0PWM4         0x00061004
#define GPIO_PG4_M1PWM2         0x00061005
#define GPIO_PG4_PHB1           0x00061006
#define GPIO_PG4_WT0CCP0        0x00061007
#define GPIO_PG4_USB0EPEN       0x00061008

#define GPIO_PG5_U2TX           0x00061401
#define GPIO_PG5_I2C1SDA        0x00061403
#define GPIO_PG5_M0PWM5         0x00061404
#define GPIO_PG5_M1PWM3         0x00061405
#define GPIO_PG5_IDX1           0x00061406
#define GPIO_PG5_WT0CCP1        0x00061407
#define GPIO_PG5_USB0PFLT       0x00061408

#define GPIO_PG6_I2C5SCL        0x00061803
#define GPIO_PG6_M0PWM6         0x00061804
#define GPIO_PG6_WT1CCP0        0x00061807

#define GPIO_PG7_I2C5SDA        0x00061C03
#define GPIO_PG7_M0PWM7         0x00061C04
#define GPIO_PG7_IDX1           0x00061C05
#define GPIO_PG7_WT1CCP1        0x00061C07

#define GPIO_PH0_SSI3CLK        0x00070002
#define GPIO_PH0_M0PWM0         0x00070004
#define GPIO_PH0_M0FAULT0       0x00070006
#define GPIO_PH0_WT2CCP0        0x00070007

#define GPIO_PH1_SSI3FSS        0x00070402
#define GPIO_PH1_M0PWM1         0x00070404
#define GPIO_PH1_IDX0           0x00070405
#define GPIO_PH1_M0FAULT1       0x00070406
#define GPIO_PH1_WT2CCP1        0x00070407

#define GPIO_PH2_SSI3RX         0x00070802
#define GPIO_PH2_M0PWM2         0x00070804
#define GPIO_PH2_M0FAULT2       0x00070806
#define GPIO_PH2_WT5CCP0        0x00070807

#define GPIO_PH3_SSI3TX         0x00070C02
#define GPIO_PH3_M0PWM3         0x00070C04
#define GPIO_PH3_M0FAULT3       0x00070C06
#define GPIO_PH3_WT5CCP1        0x00070C07

#define GPIO_PH4_SSI2CLK        0x00071002
#define GPIO_PH4_M0PWM4         0x00071004
#define GPIO_PH4_PHA0           0x00071005
#define GPIO_PH4_WT3CCP0        0x00071007

#define GPIO_PH5_SSI2FSS        0x00071402
#define GPIO_PH5_M0PWM5         0x00071404
#define GPIO_PH5_PHB0           0x00071405
#define GPIO_PH5_WT3CCP1        0x00071407

#define GPIO_PH6_SSI2RX         0x00071802
#define GPIO_PH6_M0PWM6         0x00071804
#define GPIO_PH6_WT4CCP0        0x00071807

#define GPIO_PH7_SSI2TX         0x00071C02
#define GPIO_PH7_M0PWM7         0x00071C04
#define GPIO_PH7_WT4CCP1        0x00071C07

#define GPIO_PJ0_U4RX           0x00080001
#define GPIO_PJ0_T1CCP0         0x00080007

#define GPIO_PJ1_U4TX           0x00080401
#define GPIO_PJ1_T1CCP1         0x00080407

#define GPIO_PJ2_U5RX           0x00080801
#define GPIO_PJ2_IDX0           0x00080805
#define GPIO_PJ2_T2CCP0         0x00080807

#define GPIO_PJ3_U5TX           0x00080C01
#define GPIO_PJ3_T2CCP1         0x00080C07

#define GPIO_PJ4_U6RX           0x00081001
#define GPIO_PJ4_T3CCP0         0x00081007

#define GPIO_PJ5_U6TX           0x00081401
#define GPIO_PJ5_T3CCP1         0x00081407

#define GPIO_PK0_SSI3CLK        0x00090002
#define GPIO_PK0_M1FAULT0       0x00090006

#define GPIO_PK1_SSI3FSS        0x00090402
#define GPIO_PK1_M1FAULT1       0x00090406

#define GPIO_PK2_SSI3RX         0x00090802
#define GPIO_PK2_M1FAULT2       0x00090806

#define GPIO_PK3_SSI3TX         0x00090C02
#define GPIO_PK3_M1FAULT3       0x00090C06

#define GPIO_PK4_U7RX           0x00091001
#define GPIO_PK4_M0FAULT0       0x00091006
#define GPIO_PK4_RTCCLK         0x00091007
#define GPIO_PK4_C0O            0x00091008

#define GPIO_PK5_U7TX           0x00091401
#define GPIO_PK5_M0FAULT1       0x00091406
#define GPIO_PK5_C1O            0x00091408

#define GPIO_PK6_M0FAULT2       0x00091806
#define GPIO_PK6_WT1CCP0        0x00091807
#define GPIO_PK6_C2O            0x00091808

#define GPIO_PK7_M0FAULT3       0x00091C06
#define GPIO_PK7_WT1CCP1        0x00091C07

#define GPIO_PL0_T0CCP0         0x000A0007
#define GPIO_PL0_WT0CCP0        0x000A0008

#define GPIO_PL1_T0CCP1         0x000A0407
#define GPIO_PL1_WT0CCP1        0x000A0408

#define GPIO_PL2_T1CCP0         0x000A0807
#define GPIO_PL2_WT1CCP0        0x000A0808

#define GPIO_PL3_T1CCP1         0x000A0C07
#define GPIO_PL3_WT1CCP1        0x000A0C08

#define GPIO_PL4_T2CCP0         0x000A1007
#define GPIO_PL4_WT2CCP0        0x000A1008

#define GPIO_PL5_T2CCP1         0x000A1407
#define GPIO_PL5_WT2CCP1        0x000A1408

#define GPIO_PL6_T3CCP0         0x000A1807
#define GPIO_PL6_WT3CCP0        0x000A1808

#define GPIO_PL7_T3CCP1         0x000A1C07
#define GPIO_PL7_WT3CCP1        0x000A1C08

#define GPIO_PM0_T4CCP0         0x000B0007
#define GPIO_PM0_WT4CCP0        0x000B0008

#define GPIO_PM1_T4CCP1         0x000B0407
#define GPIO_PM1_WT4CCP1        0x000B0408

#define GPIO_PM2_T5CCP0         0x000B0807
#define GPIO_PM2_WT5CCP0        0x000B0808

#define GPIO_PM3_T5CCP1         0x000B0C07
#define GPIO_PM3_WT5CCP1        0x000B0C08

#define GPIO_PM6_M0PWM4         0x000B1802
#define GPIO_PM6_WT0CCP0        0x000B1807

#define GPIO_PM7_M0PWM5         0x000B1C02
#define GPIO_PM7_WT0CCP1        0x000B1C07

#define GPIO_PN0_CAN0RX         0x000C0001

#define GPIO_PN1_CAN0TX         0x000C0401

#define GPIO_PN2_M0PWM6         0x000C0802
#define GPIO_PN2_WT2CCP0        0x000C0807

#define GPIO_PN3_M0PWM7         0x000C0C02
#define GPIO_PN3_WT2CCP1        0x000C0C07

#define GPIO_PN4_M1PWM4         0x000C1002
#define GPIO_PN4_WT3CCP0        0x000C1007

#define GPIO_PN5_M1PWM5         0x000C1402
#define GPIO_PN5_WT3CCP1        0x000C1407

#define GPIO_PN6_M1PWM6         0x000C1802
#define GPIO_PN6_WT4CCP0        0x000C1807

#define GPIO_PN7_M1PWM7         0x000C1C02
#define GPIO_PN7_WT4CCP1        0x000C1C07

#define GPIO_PP0_M0PWM0         0x000D0001
#define GPIO_PP0_T4CCP0         0x000D0007

#define GPIO_PP1_M0PWM1         0x000D0401
#define GPIO_PP1_T4CCP1         0x000D0407

#define GPIO_PP2_M0PWM2         0x000D0801
#define GPIO_PP2_T5CCP0         0x000D0807

#define GPIO_PP3_M0PWM3         0x000D0C01
#define GPIO_PP3_T5CCP1         0x000D0C07

#define GPIO_PP4_M0PWM4         0x000D1001
#define GPIO_PP4_WT0CCP0        0x000D1007

#define GPIO_PP5_M0PWM5         0x000D1401
#define GPIO_PP5_WT0CCP1        0x000D1407

#define GPIO_PP6_M0PWM6         0x000D1801
#define GPIO_PP6_WT1CCP0        0x000D1807

#define GPIO_PP7_M0PWM7         0x000D1C01
#define GPIO_PP7_WT1CCP1        0x000D1C07

#define GPIO_PQ0_M1PWM0         0x000E0001
#define GPIO_PQ0_WT2CCP0        0x000E0007

#define GPIO_PQ1_M1PWM1         0x000E0401
#define GPIO_PQ1_WT2CCP1        0x000E0407

#define GPIO_PQ2_M1PWM2         0x000E0801
#define GPIO_PQ2_WT3CCP0        0x000E0807

#define GPIO_PQ3_M1PWM3         0x000E0C01
#define GPIO_PQ3_WT3CCP1        0x000E0C07

#define GPIO_PQ4_M1PWM4         0x000E1001
#define GPIO_PQ4_WT4CCP0        0x000E1007

#define GPIO_PQ5_M1PWM5         0x000E1401
#define GPIO_PQ5_WT4CCP1        0x000E1407

#define GPIO_PQ6_M1PWM6         0x000E1801
#define GPIO_PQ6_WT5CCP0        0x000E1807

#define GPIO_PQ7_M1PWM7         0x000E1C01
#define GPIO_PQ7_WT5CCP1        0x000E1C07

#endif // PART_TM4C123GH6ZRB

//*****************************************************************************
//
// TM4C1290NCPDT Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1290NCPDT

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401

#define GPIO_PQ6_U1DTR          0x000E1801

#endif // PART_TM4C1290NCPDT

//*****************************************************************************
//
// TM4C1290NCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1290NCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001

#define GPIO_PH5_U0RI           0x00071401

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801

#define GPIO_PJ3_U2CTS          0x00080C01

#define GPIO_PJ4_U3RTS          0x00081001

#define GPIO_PJ5_U3CTS          0x00081401

#define GPIO_PJ6_U4RTS          0x00081801

#define GPIO_PJ7_U4CTS          0x00081C01

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401

#define GPIO_PQ6_U1DTR          0x000E1801

#define GPIO_PQ7_U1RI           0x000E1C01

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_M0PWM0         0x000F0006

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_M0PWM1         0x000F0406

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_M0PWM2         0x000F0806

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_M0PWM3         0x000F0C06

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_M0PWM4         0x000F1006

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_M0PWM5         0x000F1406

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_M0PWM6         0x000F1806

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_M0PWM7         0x000F1C06

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_M0FAULT0       0x00100006

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_M0FAULT1       0x00100406

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_M0FAULT2       0x00100806

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_M0FAULT3       0x00100C06

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_PHA0           0x00101006

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_PHB0           0x00101406

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_IDX0           0x00101806

#define GPIO_PS7_T5CCP1         0x00101C03

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_CAN0RX         0x00110007

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_CAN0TX         0x00110407

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_CAN1RX         0x00110807

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_CAN1TX         0x00110C07

#endif // PART_TM4C1290NCZAD

//*****************************************************************************
//
// TM4C1292NCPDT Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1292NCPDT

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EN0RXCK        0x0000180E
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_EN0MDC         0x00010805
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_EN0MDIO        0x00010C05
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_EN0MDC         0x00050805
#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_EN0MDIO        0x00050C05
#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_EN0TXCK        0x0006080E
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_EN0TXEN        0x00060C0E
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_EN0TXD0        0x0006100E
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_EN0TXD1        0x0006140E
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_EN0RXER        0x0006180E
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_EN0RXDV        0x00061C0E
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EN0INTRN       0x00091007
#define GPIO_PK4_EN0RXD3        0x0009100E
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EN0RXD2        0x0009140E
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EN0TXD2        0x0009180E
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EN0TXD3        0x00091C0E
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003
#define GPIO_PM4_EN0RREF_CLK    0x000B100E

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803
#define GPIO_PM6_EN0CRS         0x000B180E

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03
#define GPIO_PM7_EN0COL         0x000B1C0E

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_EN0INTRN       0x000D0007
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401
#define GPIO_PQ5_EN0RXD0        0x000E140E

#define GPIO_PQ6_U1DTR          0x000E1801
#define GPIO_PQ6_EN0RXD1        0x000E180E

#endif // PART_TM4C1292NCPDT

//*****************************************************************************
//
// TM4C1292NCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1292NCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EN0RXCK        0x0000180E
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_EN0MDC         0x00010805
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_EN0MDIO        0x00010C05
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_EN0MDC         0x00050805
#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_EN0MDIO        0x00050C05
#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_EN0TXCK        0x0006080E
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_EN0TXEN        0x00060C0E
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_EN0TXD0        0x0006100E
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_EN0TXD1        0x0006140E
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_EN0RXER        0x0006180E
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_EN0RXDV        0x00061C0E
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001

#define GPIO_PH5_U0RI           0x00071401

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801

#define GPIO_PJ3_U2CTS          0x00080C01

#define GPIO_PJ4_U3RTS          0x00081001

#define GPIO_PJ5_U3CTS          0x00081401

#define GPIO_PJ6_U4RTS          0x00081801

#define GPIO_PJ7_U4CTS          0x00081C01

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EN0INTRN       0x00091007
#define GPIO_PK4_EN0RXD3        0x0009100E
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EN0RXD2        0x0009140E
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EN0TXD2        0x0009180E
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EN0TXD3        0x00091C0E
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003
#define GPIO_PM4_EN0RREF_CLK    0x000B100E

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803
#define GPIO_PM6_EN0CRS         0x000B180E

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03
#define GPIO_PM7_EN0COL         0x000B1C0E

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802
#define GPIO_PN6_EN0TXER        0x000C180E

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_EN0INTRN       0x000D0007
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401
#define GPIO_PQ5_EN0RXD0        0x000E140E

#define GPIO_PQ6_U1DTR          0x000E1801
#define GPIO_PQ6_EN0RXD1        0x000E180E

#define GPIO_PQ7_U1RI           0x000E1C01

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_M0PWM0         0x000F0006

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_M0PWM1         0x000F0406

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_M0PWM2         0x000F0806

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_M0PWM3         0x000F0C06

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_M0PWM4         0x000F1006

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_M0PWM5         0x000F1406

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_M0PWM6         0x000F1806

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_M0PWM7         0x000F1C06
#define GPIO_PR7_EN0TXEN        0x000F1C0E

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_M0FAULT0       0x00100006

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_M0FAULT1       0x00100406

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_M0FAULT2       0x00100806

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_M0FAULT3       0x00100C06

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_PHA0           0x00101006
#define GPIO_PS4_EN0TXD0        0x0010100E

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_PHB0           0x00101406
#define GPIO_PS5_EN0TXD1        0x0010140E

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_IDX0           0x00101806
#define GPIO_PS6_EN0RXER        0x0010180E

#define GPIO_PS7_T5CCP1         0x00101C03
#define GPIO_PS7_EN0RXDV        0x00101C0E

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_CAN0RX         0x00110007
#define GPIO_PT0_EN0RXD0        0x0011000E

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_CAN0TX         0x00110407
#define GPIO_PT1_EN0RXD1        0x0011040E

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_CAN1RX         0x00110807

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_CAN1TX         0x00110C07

#endif // PART_TM4C1292NCZAD

//*****************************************************************************
//
// TM4C1294NCPDT Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1294NCPDT

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PF0_EN0LED0        0x00050005
#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_EN0LED2        0x00050405
#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_EN0LED1        0x00051005
#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_EN0PPS         0x00060005
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PJ0_U3RX           0x00080001
#define GPIO_PJ0_EN0PPS         0x00080005

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_EN0LED0        0x00091005
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_EN0LED2        0x00091405
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_EN0LED1        0x00091805
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#endif // PART_TM4C1294NCPDT

//*****************************************************************************
//
// TM4C1294NCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C1294NCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_EN0LED0        0x00050005
#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_EN0LED2        0x00050405
#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_EN0LED1        0x00051005
#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_EN0PPS         0x00060005
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001

#define GPIO_PH5_U0RI           0x00071401
#define GPIO_PH5_EN0PPS         0x00071405

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02

#define GPIO_PJ0_U3RX           0x00080001
#define GPIO_PJ0_EN0PPS         0x00080005

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801

#define GPIO_PJ3_U2CTS          0x00080C01

#define GPIO_PJ4_U3RTS          0x00081001

#define GPIO_PJ5_U3CTS          0x00081401

#define GPIO_PJ6_U4RTS          0x00081801

#define GPIO_PJ7_U4CTS          0x00081C01

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_EN0LED0        0x00091005
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_EN0LED2        0x00091405
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_EN0LED1        0x00091805
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401

#define GPIO_PQ6_U1DTR          0x000E1801

#define GPIO_PQ7_U1RI           0x000E1C01

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_M0PWM0         0x000F0006

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_M0PWM1         0x000F0406

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_M0PWM2         0x000F0806

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_M0PWM3         0x000F0C06

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_M0PWM4         0x000F1006

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_M0PWM5         0x000F1406

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_M0PWM6         0x000F1806

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_M0PWM7         0x000F1C06

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_M0FAULT0       0x00100006

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_M0FAULT1       0x00100406

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_M0FAULT2       0x00100806

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_M0FAULT3       0x00100C06

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_PHA0           0x00101006

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_PHB0           0x00101406

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_IDX0           0x00101806

#define GPIO_PS7_T5CCP1         0x00101C03

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_CAN0RX         0x00110007

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_CAN0TX         0x00110407

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_CAN1RX         0x00110807

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_CAN1TX         0x00110C07

#endif // PART_TM4C1294NCZAD

//*****************************************************************************
//
// TM4C129CNCPDT Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129CNCPDT

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401

#define GPIO_PQ6_U1DTR          0x000E1801

#endif // PART_TM4C129CNCPDT

//*****************************************************************************
//
// TM4C129CNCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129CNCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001

#define GPIO_PH5_U0RI           0x00071401

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801

#define GPIO_PJ3_U2CTS          0x00080C01

#define GPIO_PJ4_U3RTS          0x00081001

#define GPIO_PJ5_U3CTS          0x00081401

#define GPIO_PJ6_U4RTS          0x00081801

#define GPIO_PJ7_U4CTS          0x00081C01

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401

#define GPIO_PQ6_U1DTR          0x000E1801

#define GPIO_PQ7_U1RI           0x000E1C01

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_M0PWM0         0x000F0006

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_M0PWM1         0x000F0406

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_M0PWM2         0x000F0806

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_M0PWM3         0x000F0C06

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_M0PWM4         0x000F1006

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_M0PWM5         0x000F1406

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_M0PWM6         0x000F1806

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_M0PWM7         0x000F1C06

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_M0FAULT0       0x00100006

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_M0FAULT1       0x00100406

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_M0FAULT2       0x00100806

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_M0FAULT3       0x00100C06

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_PHA0           0x00101006

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_PHB0           0x00101406

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_IDX0           0x00101806

#define GPIO_PS7_T5CCP1         0x00101C03

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_CAN0RX         0x00110007

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_CAN0TX         0x00110407

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_CAN1RX         0x00110807

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_CAN1TX         0x00110C07

#endif // PART_TM4C129CNCZAD

//*****************************************************************************
//
// TM4C129DNCPDT Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129DNCPDT

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EN0RXCK        0x0000180E
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_EN0MDC         0x00010805
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_EN0MDIO        0x00010C05
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_EN0MDC         0x00050805
#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_EN0MDIO        0x00050C05
#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_EN0TXCK        0x0006080E
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_EN0TXEN        0x00060C0E
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_EN0TXD0        0x0006100E
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_EN0TXD1        0x0006140E
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_EN0RXER        0x0006180E
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_EN0RXDV        0x00061C0E
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EN0INTRN       0x00091007
#define GPIO_PK4_EN0RXD3        0x0009100E
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EN0RXD2        0x0009140E
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EN0TXD2        0x0009180E
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EN0TXD3        0x00091C0E
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003
#define GPIO_PM4_EN0RREF_CLK    0x000B100E

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803
#define GPIO_PM6_EN0CRS         0x000B180E

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03
#define GPIO_PM7_EN0COL         0x000B1C0E

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_EN0INTRN       0x000D0007
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401
#define GPIO_PQ5_EN0RXD0        0x000E140E

#define GPIO_PQ6_U1DTR          0x000E1801
#define GPIO_PQ6_EN0RXD1        0x000E180E

#endif // PART_TM4C129DNCPDT

//*****************************************************************************
//
// TM4C129DNCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129DNCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EN0RXCK        0x0000180E
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_EN0MDC         0x00010805
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_EN0MDIO        0x00010C05
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_EN0MDC         0x00050805
#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_EN0MDIO        0x00050C05
#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_EN0TXCK        0x0006080E
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_EN0TXEN        0x00060C0E
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_EN0TXD0        0x0006100E
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_EN0TXD1        0x0006140E
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_EN0RXER        0x0006180E
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_EN0RXDV        0x00061C0E
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001

#define GPIO_PH5_U0RI           0x00071401

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02

#define GPIO_PJ0_U3RX           0x00080001

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801

#define GPIO_PJ3_U2CTS          0x00080C01

#define GPIO_PJ4_U3RTS          0x00081001

#define GPIO_PJ5_U3CTS          0x00081401

#define GPIO_PJ6_U4RTS          0x00081801

#define GPIO_PJ7_U4CTS          0x00081C01

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EN0INTRN       0x00091007
#define GPIO_PK4_EN0RXD3        0x0009100E
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EN0RXD2        0x0009140E
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EN0TXD2        0x0009180E
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EN0TXD3        0x00091C0E
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003
#define GPIO_PM4_EN0RREF_CLK    0x000B100E

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803
#define GPIO_PM6_EN0CRS         0x000B180E

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03
#define GPIO_PM7_EN0COL         0x000B1C0E

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802
#define GPIO_PN6_EN0TXER        0x000C180E

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_EN0INTRN       0x000D0007
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401
#define GPIO_PQ5_EN0RXD0        0x000E140E

#define GPIO_PQ6_U1DTR          0x000E1801
#define GPIO_PQ6_EN0RXD1        0x000E180E

#define GPIO_PQ7_U1RI           0x000E1C01

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_M0PWM0         0x000F0006

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_M0PWM1         0x000F0406

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_M0PWM2         0x000F0806

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_M0PWM3         0x000F0C06

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_M0PWM4         0x000F1006

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_M0PWM5         0x000F1406

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_M0PWM6         0x000F1806

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_M0PWM7         0x000F1C06
#define GPIO_PR7_EN0TXEN        0x000F1C0E

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_M0FAULT0       0x00100006

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_M0FAULT1       0x00100406

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_M0FAULT2       0x00100806

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_M0FAULT3       0x00100C06

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_PHA0           0x00101006
#define GPIO_PS4_EN0TXD0        0x0010100E

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_PHB0           0x00101406
#define GPIO_PS5_EN0TXD1        0x0010140E

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_IDX0           0x00101806
#define GPIO_PS6_EN0RXER        0x0010180E

#define GPIO_PS7_T5CCP1         0x00101C03
#define GPIO_PS7_EN0RXDV        0x00101C0E

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_CAN0RX         0x00110007
#define GPIO_PT0_EN0RXD0        0x0011000E

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_CAN0TX         0x00110407
#define GPIO_PT1_EN0RXD1        0x0011040E

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_CAN1RX         0x00110807

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_CAN1TX         0x00110C07

#endif // PART_TM4C129DNCZAD

//*****************************************************************************
//
// TM4C129ENCPDT Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129ENCPDT

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PF0_EN0LED0        0x00050005
#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_EN0LED2        0x00050405
#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_EN0LED1        0x00051005
#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_EN0PPS         0x00060005
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PJ0_U3RX           0x00080001
#define GPIO_PJ0_EN0PPS         0x00080005

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_EN0LED0        0x00091005
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_EN0LED2        0x00091405
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_EN0LED1        0x00091805
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#endif // PART_TM4C129ENCPDT

//*****************************************************************************
//
// TM4C129ENCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129ENCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401

#define GPIO_PC2_TDI            0x00020801

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_EN0LED0        0x00050005
#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_EN0LED2        0x00050405
#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_EN0LED1        0x00051005
#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_EN0PPS         0x00060005
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001

#define GPIO_PH5_U0RI           0x00071401
#define GPIO_PH5_EN0PPS         0x00071405

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02

#define GPIO_PJ0_U3RX           0x00080001
#define GPIO_PJ0_EN0PPS         0x00080005

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801

#define GPIO_PJ3_U2CTS          0x00080C01

#define GPIO_PJ4_U3RTS          0x00081001

#define GPIO_PJ5_U3CTS          0x00081401

#define GPIO_PJ6_U4RTS          0x00081801

#define GPIO_PJ7_U4CTS          0x00081C01

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_EN0LED0        0x00091005
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_EN0LED2        0x00091405
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_EN0LED1        0x00091805
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803

#define GPIO_PL7_T1CCP1         0x000A1C03

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_T5CCP0         0x000B1803

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_T5CCP1         0x000B1C03

#define GPIO_PN0_U1RTS          0x000C0001

#define GPIO_PN1_U1CTS          0x000C0401

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401

#define GPIO_PQ6_U1DTR          0x000E1801

#define GPIO_PQ7_U1RI           0x000E1C01

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_M0PWM0         0x000F0006

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_M0PWM1         0x000F0406

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_M0PWM2         0x000F0806

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_M0PWM3         0x000F0C06

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_M0PWM4         0x000F1006

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_M0PWM5         0x000F1406

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_M0PWM6         0x000F1806

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_M0PWM7         0x000F1C06

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_M0FAULT0       0x00100006

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_M0FAULT1       0x00100406

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_M0FAULT2       0x00100806

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_M0FAULT3       0x00100C06

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_PHA0           0x00101006

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_PHB0           0x00101406

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_IDX0           0x00101806

#define GPIO_PS7_T5CCP1         0x00101C03

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_CAN0RX         0x00110007

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_CAN0TX         0x00110407

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_CAN1RX         0x00110807

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_CAN1TX         0x00110C07

#endif // PART_TM4C129ENCZAD

//*****************************************************************************
//
// TM4C129XNCZAD Port/Pin Mapping Definitions
//
//*****************************************************************************
#ifdef PART_TM4C129XNCZAD

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_I2C9SCL        0x00000002
#define GPIO_PA0_T0CCP0         0x00000003
#define GPIO_PA0_FAN1PWM5       0x00000004
#define GPIO_PA0_KBCOUT08       0x00000005
#define GPIO_PA0_CAN0RX         0x00000007

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_I2C9SDA        0x00000402
#define GPIO_PA1_T0CCP1         0x00000403
#define GPIO_PA1_FAN1TACH5      0x00000404
#define GPIO_PA1_KBCOUT09       0x00000405
#define GPIO_PA1_CAN0TX         0x00000407

#define GPIO_PA2_U4RX           0x00000801
#define GPIO_PA2_I2C8SCL        0x00000802
#define GPIO_PA2_T1CCP0         0x00000803
#define GPIO_PA2_SSI0CLK        0x0000080F

#define GPIO_PA3_U4TX           0x00000C01
#define GPIO_PA3_I2C8SDA        0x00000C02
#define GPIO_PA3_T1CCP1         0x00000C03
#define GPIO_PA3_SSI0FSS        0x00000C0F

#define GPIO_PA4_U3RX           0x00001001
#define GPIO_PA4_T2CCP0         0x00001003
#define GPIO_PA4_I2C7SCL        0x00001002
#define GPIO_PA4_SSI0XDAT0      0x0000100F

#define GPIO_PA5_U3TX           0x00001401
#define GPIO_PA5_T2CCP1         0x00001403
#define GPIO_PA5_I2C7SDA        0x00001402
#define GPIO_PA5_SSI0XDAT1      0x0000140F

#define GPIO_PA6_U2RX           0x00001801
#define GPIO_PA6_I2C6SCL        0x00001802
#define GPIO_PA6_T3CCP0         0x00001803
#define GPIO_PA6_PS2CLK0        0x00001804
#define GPIO_PA6_USB0EPEN       0x00001805
#define GPIO_PA6_SSI0XDAT2      0x0000180D
#define GPIO_PA6_EN0RXCK        0x0000180E
#define GPIO_PA6_EPI0S8         0x0000180F

#define GPIO_PA7_U2TX           0x00001C01
#define GPIO_PA7_I2C6SDA        0x00001C02
#define GPIO_PA7_T3CCP1         0x00001C03
#define GPIO_PA7_PS2DAT0        0x00001C04
#define GPIO_PA7_USB0PFLT       0x00001C05
#define GPIO_PA7_USB0EPEN       0x00001C0B
#define GPIO_PA7_SSI0XDAT3      0x00001C0D
#define GPIO_PA7_EPI0S9         0x00001C0F

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_I2C5SCL        0x00010002
#define GPIO_PB0_PS2CLK1        0x00010004
#define GPIO_PB0_LPC0COMYRX     0x00010005
#define GPIO_PB0_CAN1RX         0x00010007
#define GPIO_PB0_T4CCP0         0x00010003

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_I2C5SDA        0x00010402
#define GPIO_PB1_PS2DAT1        0x00010404
#define GPIO_PB1_LPC0COMYTX     0x00010405
#define GPIO_PB1_CAN1TX         0x00010407
#define GPIO_PB1_T4CCP1         0x00010403

#define GPIO_PB2_T5CCP0         0x00010803
#define GPIO_PB2_I2C0SCL        0x00010802
#define GPIO_PB2_PS2CLK2        0x00010804
#define GPIO_PB2_EN0MDC         0x00010805
#define GPIO_PB2_LPC0A20        0x0001080D
#define GPIO_PB2_USB0STP        0x0001080E
#define GPIO_PB2_EPI0S27        0x0001080F

#define GPIO_PB3_I2C0SDA        0x00010C02
#define GPIO_PB3_T5CCP1         0x00010C03
#define GPIO_PB3_PS2DAT2        0x00010C04
#define GPIO_PB3_EN0MDIO        0x00010C05
#define GPIO_PB3_LPC0RESET_N    0x00010C0D
#define GPIO_PB3_USB0CLK        0x00010C0E
#define GPIO_PB3_EPI0S28        0x00010C0F

#define GPIO_PB4_U0CTS          0x00011001
#define GPIO_PB4_I2C5SCL        0x00011002
#define GPIO_PB4_SSI1FSS        0x0001100F

#define GPIO_PB5_U0RTS          0x00011401
#define GPIO_PB5_I2C5SDA        0x00011402
#define GPIO_PB5_SSI1CLK        0x0001140F

#define GPIO_PB6_I2C6SCL        0x00011802
#define GPIO_PB6_T6CCP0         0x00011803
#define GPIO_PB6_PS2CLK3        0x00011804

#define GPIO_PB7_I2C6SDA        0x00011C02
#define GPIO_PB7_T6CCP1         0x00011C03
#define GPIO_PB7_PS2DAT3        0x00011C04

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_HLED0          0x00020004
#define GPIO_PC0_KBCOUT00       0x00020005

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_HLED1          0x00020404
#define GPIO_PC1_KBCOUT01       0x00020405

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_HLED2          0x00020804
#define GPIO_PC2_KBCOUT02       0x00020805

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_KBCOUT03       0x00020C05
#define GPIO_PC3_HLED3          0x00020C04

#define GPIO_PC4_U7RX           0x00021001
#define GPIO_PC4_T7CCP0         0x00021003
#define GPIO_PC4_FAN0PWM0       0x00021004
#define GPIO_PC4_EPI0S7         0x0002100F

#define GPIO_PC5_U7TX           0x00021401
#define GPIO_PC5_T7CCP1         0x00021403
#define GPIO_PC5_FAN0TACH0      0x00021404
#define GPIO_PC5_RTCCLK         0x00021407
#define GPIO_PC5_EPI0S6         0x0002140F

#define GPIO_PC6_U5RX           0x00021801
#define GPIO_PC6_FAN0PWM1       0x00021804
#define GPIO_PC6_EPI0S5         0x0002180F

#define GPIO_PC7_U5TX           0x00021C01
#define GPIO_PC7_FAN0TACH1      0x00021C04
#define GPIO_PC7_EPI0S4         0x00021C0F

#define GPIO_PD0_I2C7SCL        0x00030002
#define GPIO_PD0_T0CCP0         0x00030003
#define GPIO_PD0_FAN0PWM4       0x00030004
#define GPIO_PD0_C0O            0x00030005
#define GPIO_PD0_SSI2XDAT1      0x0003000F

#define GPIO_PD1_I2C7SDA        0x00030402
#define GPIO_PD1_T0CCP1         0x00030403
#define GPIO_PD1_FAN0TACH4      0x00030404
#define GPIO_PD1_C1O            0x00030405
#define GPIO_PD1_SSI2XDAT0      0x0003040F

#define GPIO_PD2_I2C8SCL        0x00030802
#define GPIO_PD2_T1CCP0         0x00030803
#define GPIO_PD2_C2O            0x00030805
#define GPIO_PD2_SSI2FSS        0x0003080F

#define GPIO_PD3_I2C8SDA        0x00030C02
#define GPIO_PD3_T1CCP1         0x00030C03
#define GPIO_PD3_SSI2CLK        0x00030C0F

#define GPIO_PD4_U2RX           0x00031001
#define GPIO_PD4_T3CCP0         0x00031003
#define GPIO_PD4_KBCOUT19       0x00031004
#define GPIO_PD4_SSI1XDAT2      0x0003100F

#define GPIO_PD5_U2TX           0x00031401
#define GPIO_PD5_T3CCP1         0x00031403
#define GPIO_PD5_KBCOUT18       0x00031404
#define GPIO_PD5_SSI1XDAT3      0x0003140F

#define GPIO_PD6_U2RTS          0x00031801
#define GPIO_PD6_T4CCP0         0x00031803
#define GPIO_PD6_USB0EPEN       0x00031805
#define GPIO_PD6_SSI2XDAT3      0x0003180F

#define GPIO_PD7_U2CTS          0x00031C01
#define GPIO_PD7_T4CCP1         0x00031C03
#define GPIO_PD7_USB0PFLT       0x00031C05
#define GPIO_PD7_NMI            0x00031C08
#define GPIO_PD7_SSI2XDAT2      0x00031C0F

#define GPIO_PE0_U1RTS          0x00040001

#define GPIO_PE1_U1DSR          0x00040401

#define GPIO_PE2_U1DCD          0x00040801

#define GPIO_PE3_U1DTR          0x00040C01

#define GPIO_PE4_U1RI           0x00041001
#define GPIO_PE4_FAN0TACH7      0x00041004
#define GPIO_PE4_SSI1XDAT0      0x0004100F

#define GPIO_PE5_FAN0PWM7       0x00041404
#define GPIO_PE5_SSI1XDAT1      0x0004140F

#define GPIO_PE6_U0CTS          0x00041801
#define GPIO_PE6_I2C9SCL        0x00041802
#define GPIO_PE6_HLED2          0x00041804

#define GPIO_PE7_U0RTS          0x00041C01
#define GPIO_PE7_I2C9SDA        0x00041C02
#define GPIO_PE7_HLED3          0x00041C04
#define GPIO_PE7_NMI            0x00041C08

#define GPIO_PF0_KBCOUT00       0x00050003
#define GPIO_PF0_FAN0PWM2       0x00050004
#define GPIO_PF0_EN0LED0        0x00050005
#define GPIO_PF0_M0PWM0         0x00050006
#define GPIO_PF0_KBCOUT07       0x00050007
#define GPIO_PF0_SSI3XDAT1      0x0005000E
#define GPIO_PF0_TRD2           0x0005000F

#define GPIO_PF1_KBCOUT01       0x00050403
#define GPIO_PF1_FAN0TACH2      0x00050404
#define GPIO_PF1_EN0LED2        0x00050405
#define GPIO_PF1_M0PWM1         0x00050406
#define GPIO_PF1_KBCOUT06       0x00050407
#define GPIO_PF1_SSI3XDAT0      0x0005040E
#define GPIO_PF1_TRD1           0x0005040F

#define GPIO_PF2_KBCOUT02       0x00050803
#define GPIO_PF2_FAN0PWM3       0x00050804
#define GPIO_PF2_EN0MDC         0x00050805
#define GPIO_PF2_M0PWM2         0x00050806
#define GPIO_PF2_KBCOUT05       0x00050807
#define GPIO_PF2_SSI3FSS        0x0005080E
#define GPIO_PF2_TRD0           0x0005080F

#define GPIO_PF3_KBCOUT03       0x00050C03
#define GPIO_PF3_FAN0TACH3      0x00050C04
#define GPIO_PF3_EN0MDIO        0x00050C05
#define GPIO_PF3_M0PWM3         0x00050C06
#define GPIO_PF3_KBCOUT04       0x00050C07
#define GPIO_PF3_SSI3CLK        0x00050C0E
#define GPIO_PF3_TRCLK          0x00050C0F

#define GPIO_PF4_KBCOUT16       0x00051003
#define GPIO_PF4_FAN0PWM4       0x00051004
#define GPIO_PF4_EN0LED1        0x00051005
#define GPIO_PF4_M0FAULT0       0x00051006
#define GPIO_PF4_SSI3XDAT2      0x0005100E
#define GPIO_PF4_TRD3           0x0005100F

#define GPIO_PF5_KBCOUT17       0x00051403
#define GPIO_PF5_FAN0TACH4      0x00051404
#define GPIO_PF5_SSI3XDAT3      0x0005140E

#define GPIO_PF6_FAN0PWM5       0x00051804
#define GPIO_PF6_LCDMCLK        0x0005180F

#define GPIO_PF7_FAN0TACH5      0x00051C04
#define GPIO_PF7_LCDDATA02      0x00051C0F

#define GPIO_PG0_I2C1SCL        0x00060002
#define GPIO_PG0_FAN1PWM0       0x00060003
#define GPIO_PG0_FAN0PWM6       0x00060004
#define GPIO_PG0_EN0PPS         0x00060005
#define GPIO_PG0_M0PWM4         0x00060006
#define GPIO_PG0_EPI0S11        0x0006000F

#define GPIO_PG1_I2C1SDA        0x00060402
#define GPIO_PG1_KBRST_N        0x00060403
#define GPIO_PG1_FAN0TACH6      0x00060404
#define GPIO_PG1_FAN1TACH0      0x00060405
#define GPIO_PG1_M0PWM5         0x00060406
#define GPIO_PG1_EPI0S10        0x0006040F

#define GPIO_PG2_I2C2SCL        0x00060802
#define GPIO_PG2_KBCOUT00       0x00060803
#define GPIO_PG2_FAN0PWM7       0x00060804
#define GPIO_PG2_FAN1PWM1       0x00060805
#define GPIO_PG2_EN0TXCK        0x0006080E
#define GPIO_PG2_SSI2XDAT3      0x0006080F

#define GPIO_PG3_I2C2SDA        0x00060C02
#define GPIO_PG3_KBCOUT01       0x00060C03
#define GPIO_PG3_FAN0TACH7      0x00060C04
#define GPIO_PG3_FAN1TACH1      0x00060C05
#define GPIO_PG3_EN0TXEN        0x00060C0E
#define GPIO_PG3_SSI2XDAT2      0x00060C0F

#define GPIO_PG4_U0CTS          0x00061001
#define GPIO_PG4_I2C3SCL        0x00061002
#define GPIO_PG4_OWIRE          0x00061005
#define GPIO_PG4_EN0TXD0        0x0006100E
#define GPIO_PG4_SSI2XDAT1      0x0006100F

#define GPIO_PG5_U0RTS          0x00061401
#define GPIO_PG5_I2C3SDA        0x00061402
#define GPIO_PG5_KBRST_N        0x00061404
#define GPIO_PG5_OWALT          0x00061405
#define GPIO_PG5_EN0TXD1        0x0006140E
#define GPIO_PG5_SSI2XDAT0      0x0006140F

#define GPIO_PG6_I2C4SCL        0x00061802
#define GPIO_PG6_KBCOUT00       0x00061804
#define GPIO_PG6_EN0RXER        0x0006180E
#define GPIO_PG6_SSI2FSS        0x0006180F

#define GPIO_PG7_I2C4SDA        0x00061C02
#define GPIO_PG7_KBCOUT01       0x00061C04
#define GPIO_PG7_EN0RXDV        0x00061C0E
#define GPIO_PG7_SSI2CLK        0x00061C0F

#define GPIO_PH0_U0RTS          0x00070001
#define GPIO_PH0_LPC0COMXRTS    0x00070002
#define GPIO_PH0_KBCIN04        0x00070004
#define GPIO_PH0_FAN1PWM3       0x00070005
#define GPIO_PH0_EPI0S0         0x0007000F

#define GPIO_PH1_U0CTS          0x00070401
#define GPIO_PH1_LPC0COMXCTS    0x00070402
#define GPIO_PH1_KBCIN05        0x00070404
#define GPIO_PH1_FAN1TACH3      0x00070405
#define GPIO_PH1_EPI0S1         0x0007040F

#define GPIO_PH2_U0DCD          0x00070801
#define GPIO_PH2_LPC0COMXDCD    0x00070802
#define GPIO_PH2_KBCIN06        0x00070804
#define GPIO_PH2_FAN0PWM4       0x00070805
#define GPIO_PH2_EPI0S2         0x0007080F

#define GPIO_PH3_U0DSR          0x00070C01
#define GPIO_PH3_LPC0COMXDSR    0x00070C02
#define GPIO_PH3_KBCIN07        0x00070C04
#define GPIO_PH3_FAN0TACH4      0x00070C05
#define GPIO_PH3_EPI0S3         0x00070C0F

#define GPIO_PH4_U0DTR          0x00071001
#define GPIO_PH4_LPC0COMXDTR    0x00071002
#define GPIO_PH4_LPC0COMXRTS    0x00071003
#define GPIO_PH4_PS2CLK0        0x00071004

#define GPIO_PH5_U0RI           0x00071401
#define GPIO_PH5_LPC0COMXRI     0x00071402
#define GPIO_PH5_LPC0COMXCTS    0x00071403
#define GPIO_PH5_PS2DAT0        0x00071404
#define GPIO_PH5_EN0PPS         0x00071405

#define GPIO_PH6_U5RX           0x00071801
#define GPIO_PH6_U7RX           0x00071802
#define GPIO_PH6_LPC0COMXDCD    0x00071803
#define GPIO_PH6_FAN1PWM0       0x00071804
#define GPIO_PH6_KBCIN04        0x00071805

#define GPIO_PH7_U5TX           0x00071C01
#define GPIO_PH7_U7TX           0x00071C02
#define GPIO_PH7_LPC0COMXDSR    0x00071C03
#define GPIO_PH7_FAN1TACH0      0x00071C04
#define GPIO_PH7_KBCIN05        0x00071C05

#define GPIO_PJ0_U3RX           0x00080001
#define GPIO_PJ0_EN0PPS         0x00080005

#define GPIO_PJ1_U3TX           0x00080401

#define GPIO_PJ2_U2RTS          0x00080801
#define GPIO_PJ2_KBCOUT02       0x00080804
#define GPIO_PJ2_FAN1PWM1       0x00080805
#define GPIO_PJ2_LCDDATA14      0x0008080F

#define GPIO_PJ3_U2CTS          0x00080C01
#define GPIO_PJ3_KBCOUT03       0x00080C04
#define GPIO_PJ3_FAN1TACH1      0x00080C05
#define GPIO_PJ3_LCDDATA15      0x00080C0F

#define GPIO_PJ4_U3RTS          0x00081001
#define GPIO_PJ4_KBCOUT04       0x00081004
#define GPIO_PJ4_FAN1PWM5       0x00081005
#define GPIO_PJ4_LCDDATA16      0x0008100F

#define GPIO_PJ5_U3CTS          0x00081401
#define GPIO_PJ5_KBCOUT05       0x00081404
#define GPIO_PJ5_FAN1TACH5      0x00081405
#define GPIO_PJ5_LCDDATA17      0x0008140F

#define GPIO_PJ6_U4RTS          0x00081801
#define GPIO_PJ6_KBCOUT06       0x00081804
#define GPIO_PJ6_LCDAC          0x0008180F

#define GPIO_PJ7_U4CTS          0x00081C01
#define GPIO_PJ7_KBCOUT07       0x00081C04

#define GPIO_PK0_U4RX           0x00090001
#define GPIO_PK0_KBCIN06        0x00090003
#define GPIO_PK0_FAN1PWM6       0x00090004
#define GPIO_PK0_EPI0S0         0x0009000F

#define GPIO_PK1_U4TX           0x00090401
#define GPIO_PK1_KBCIN07        0x00090403
#define GPIO_PK1_FAN1TACH6      0x00090404
#define GPIO_PK1_EPI0S1         0x0009040F

#define GPIO_PK2_U4RTS          0x00090801
#define GPIO_PK2_KBCOUT05       0x00090803
#define GPIO_PK2_FAN1PWM7       0x00090804
#define GPIO_PK2_EPI0S2         0x0009080F

#define GPIO_PK3_U4CTS          0x00090C01
#define GPIO_PK3_KBCOUT06       0x00090C03
#define GPIO_PK3_FAN1TACH7      0x00090C04
#define GPIO_PK3_EPI0S3         0x00090C0F

#define GPIO_PK4_I2C3SCL        0x00091002
#define GPIO_PK4_KBCIN00        0x00091004
#define GPIO_PK4_EN0LED0        0x00091005
#define GPIO_PK4_M0PWM6         0x00091006
#define GPIO_PK4_EN0INTRN       0x00091007
#define GPIO_PK4_EN0RXD3        0x0009100E
#define GPIO_PK4_EPI0S32        0x0009100F

#define GPIO_PK5_I2C3SDA        0x00091402
#define GPIO_PK5_KBCIN01        0x00091404
#define GPIO_PK5_EN0LED2        0x00091405
#define GPIO_PK5_M0PWM7         0x00091406
#define GPIO_PK5_EN0RXD2        0x0009140E
#define GPIO_PK5_EPI0S31        0x0009140F

#define GPIO_PK6_I2C4SCL        0x00091802
#define GPIO_PK6_KBCIN02        0x00091804
#define GPIO_PK6_EN0LED1        0x00091805
#define GPIO_PK6_M0FAULT1       0x00091806
#define GPIO_PK6_EN0TXD2        0x0009180E
#define GPIO_PK6_EPI0S25        0x0009180F

#define GPIO_PK7_U0RI           0x00091C01
#define GPIO_PK7_I2C4SDA        0x00091C02
#define GPIO_PK7_KBCIN03        0x00091C04
#define GPIO_PK7_RTCCLK         0x00091C05
#define GPIO_PK7_M0FAULT2       0x00091C06
#define GPIO_PK7_EN0TXD3        0x00091C0E
#define GPIO_PK7_EPI0S24        0x00091C0F

#define GPIO_PL0_I2C2SDA        0x000A0002
#define GPIO_PL0_M0FAULT3       0x000A0006
#define GPIO_PL0_LPC0FRAME_N    0x000A000D
#define GPIO_PL0_USB0D0         0x000A000E
#define GPIO_PL0_EPI0S16        0x000A000F

#define GPIO_PL1_I2C2SCL        0x000A0402
#define GPIO_PL1_PHA0           0x000A0406
#define GPIO_PL1_LPC0CLK        0x000A040D
#define GPIO_PL1_USB0D1         0x000A040E
#define GPIO_PL1_EPI0S17        0x000A040F

#define GPIO_PL2_C0O            0x000A0805
#define GPIO_PL2_PHB0           0x000A0806
#define GPIO_PL2_LPC0CLKRUN_N   0x000A080D
#define GPIO_PL2_USB0D2         0x000A080E
#define GPIO_PL2_EPI0S18        0x000A080F

#define GPIO_PL3_C1O            0x000A0C05
#define GPIO_PL3_IDX0           0x000A0C06
#define GPIO_PL3_LPC0SERIRQ     0x000A0C0D
#define GPIO_PL3_USB0D3         0x000A0C0E
#define GPIO_PL3_EPI0S19        0x000A0C0F

#define GPIO_PL4_T0CCP0         0x000A1003
#define GPIO_PL4_LPC0SCI_N      0x000A100D
#define GPIO_PL4_USB0D4         0x000A100E
#define GPIO_PL4_EPI0S26        0x000A100F

#define GPIO_PL5_T0CCP1         0x000A1403
#define GPIO_PL5_EPI0S33        0x000A140F
#define GPIO_PL5_LPC0PD_N       0x000A140D
#define GPIO_PL5_USB0D5         0x000A140E

#define GPIO_PL6_T1CCP0         0x000A1803
#define GPIO_PL6_FAN1PWM4       0x000A1804

#define GPIO_PL7_T1CCP1         0x000A1C03
#define GPIO_PL7_FAN1TACH4      0x000A1C04

#define GPIO_PM0_T2CCP0         0x000B0003
#define GPIO_PM0_FAN0PWM5       0x000B0005
#define GPIO_PM0_LPC0AD3        0x000B000D
#define GPIO_PM0_EPI0S15        0x000B000F

#define GPIO_PM1_T2CCP1         0x000B0403
#define GPIO_PM1_FAN0TACH5      0x000B0405
#define GPIO_PM1_LPC0AD2        0x000B040D
#define GPIO_PM1_EPI0S14        0x000B040F

#define GPIO_PM2_T3CCP0         0x000B0803
#define GPIO_PM2_FAN1PWM4       0x000B0805
#define GPIO_PM2_LPC0AD1        0x000B080D
#define GPIO_PM2_EPI0S13        0x000B080F

#define GPIO_PM3_T3CCP1         0x000B0C03
#define GPIO_PM3_FAN1TACH4      0x000B0C05
#define GPIO_PM3_LPC0AD0        0x000B0C0D
#define GPIO_PM3_EPI0S12        0x000B0C0F

#define GPIO_PM4_U0CTS          0x000B1001
#define GPIO_PM4_T4CCP0         0x000B1003
#define GPIO_PM4_KBCIN04        0x000B1004
#define GPIO_PM4_EN0RREF_CLK    0x000B100E

#define GPIO_PM5_U0DCD          0x000B1401
#define GPIO_PM5_T4CCP1         0x000B1403
#define GPIO_PM5_KBCIN05        0x000B1404

#define GPIO_PM6_U0DSR          0x000B1801
#define GPIO_PM6_LPC0COMXRTS    0x000B1802
#define GPIO_PM6_KBCIN06        0x000B1804
#define GPIO_PM6_T5CCP0         0x000B1803
#define GPIO_PM6_EN0CRS         0x000B180E

#define GPIO_PM7_U0RI           0x000B1C01
#define GPIO_PM7_LPC0COMXCTS    0x000B1C02
#define GPIO_PM7_KBCIN07        0x000B1C04
#define GPIO_PM7_T5CCP1         0x000B1C03
#define GPIO_PM7_EN0COL         0x000B1C0E

#define GPIO_PN0_U1RTS          0x000C0001
#define GPIO_PN0_LPC0COMYRTS    0x000C0002
#define GPIO_PN0_KBCOUT11       0x000C0003
#define GPIO_PN0_PS2CLK1        0x000C0004
#define GPIO_PN0_FAN0PWM5       0x000C0005

#define GPIO_PN1_U1CTS          0x000C0401
#define GPIO_PN1_LPC0COMYCTS    0x000C0402
#define GPIO_PN1_KBCOUT12       0x000C0403
#define GPIO_PN1_PS2DAT1        0x000C0404
#define GPIO_PN1_FAN0TACH5      0x000C0405

#define GPIO_PN2_U1DCD          0x000C0801
#define GPIO_PN2_U2RTS          0x000C0802
#define GPIO_PN2_LPC0COMXDTR    0x000C0803
#define GPIO_PN2_FAN1PWM4       0x000C0805
#define GPIO_PN2_EPI0S29        0x000C080F

#define GPIO_PN3_U1DSR          0x000C0C01
#define GPIO_PN3_U2CTS          0x000C0C02
#define GPIO_PN3_LPC0COMXRI     0x000C0C03
#define GPIO_PN3_KBCOUT17       0x000C0C04
#define GPIO_PN3_FAN1TACH4      0x000C0C05
#define GPIO_PN3_EPI0S30        0x000C0C0F

#define GPIO_PN4_U1DTR          0x000C1001
#define GPIO_PN4_U3RTS          0x000C1002
#define GPIO_PN4_I2C2SDA        0x000C1003
#define GPIO_PN4_KBCOUT14       0x000C1004
#define GPIO_PN4_EPI0S34        0x000C100F

#define GPIO_PN5_U1RI           0x000C1401
#define GPIO_PN5_U3CTS          0x000C1402
#define GPIO_PN5_I2C2SCL        0x000C1403
#define GPIO_PN5_KBCOUT15       0x000C1404
#define GPIO_PN5_EPI0S35        0x000C140F

#define GPIO_PN6_U4RTS          0x000C1802
#define GPIO_PN6_KBCOUT07       0x000C1803
#define GPIO_PN6_FAN1PWM3       0x000C1804
#define GPIO_PN6_PS2CLK2        0x000C1805
#define GPIO_PN6_EN0TXER        0x000C180E
#define GPIO_PN6_LCDDATA13      0x000C180F

#define GPIO_PN7_U1RTS          0x000C1C01
#define GPIO_PN7_U4CTS          0x000C1C02
#define GPIO_PN7_FAN1TACH3      0x000C1C04
#define GPIO_PN7_PS2DAT2        0x000C1C05
#define GPIO_PN7_LCDDATA12      0x000C1C0F

#define GPIO_PP0_U6RX           0x000D0001
#define GPIO_PP0_KBCOUT18       0x000D0003
#define GPIO_PP0_HLED0          0x000D0004
#define GPIO_PP0_T6CCP0         0x000D0005
#define GPIO_PP0_EN0INTRN       0x000D0007
#define GPIO_PP0_SSI3XDAT2      0x000D000F

#define GPIO_PP1_U6TX           0x000D0401
#define GPIO_PP1_KBCOUT19       0x000D0403
#define GPIO_PP1_HLED1          0x000D0404
#define GPIO_PP1_T6CCP1         0x000D0405
#define GPIO_PP1_SSI3XDAT3      0x000D040F

#define GPIO_PP2_U0DTR          0x000D0801
#define GPIO_PP2_FAN1PWM2       0x000D0804
#define GPIO_PP2_USB0NXT        0x000D080E
#define GPIO_PP2_EPI0S29        0x000D080F

#define GPIO_PP3_U1CTS          0x000D0C01
#define GPIO_PP3_U0DCD          0x000D0C02
#define GPIO_PP3_KBCOUT08       0x000D0C03
#define GPIO_PP3_FAN1TACH2      0x000D0C04
#define GPIO_PP3_RTCCLK         0x000D0C07
#define GPIO_PP3_USB0DIR        0x000D0C0E
#define GPIO_PP3_EPI0S30        0x000D0C0F

#define GPIO_PP4_U3RTS          0x000D1001
#define GPIO_PP4_U0DSR          0x000D1002
#define GPIO_PP4_KBCOUT09       0x000D1003
#define GPIO_PP4_OWIRE          0x000D1004
#define GPIO_PP4_USB0D7         0x000D100E

#define GPIO_PP5_U3CTS          0x000D1401
#define GPIO_PP5_I2C2SCL        0x000D1402
#define GPIO_PP5_KBCOUT10       0x000D1403
#define GPIO_PP5_OWALT          0x000D1404
#define GPIO_PP5_USB0D6         0x000D140E

#define GPIO_PP6_U1DCD          0x000D1801
#define GPIO_PP6_I2C2SDA        0x000D1802
#define GPIO_PP6_KBCOUT11       0x000D1803

#define GPIO_PP7_KBCOUT12       0x000D1C03

#define GPIO_PQ0_T6CCP0         0x000E0003
#define GPIO_PQ0_KBCOUT04       0x000E0004
#define GPIO_PQ0_KBCOUT00       0x000E0005
#define GPIO_PQ0_FAN1PWM1       0x000E0006
#define GPIO_PQ0_SSI3CLK        0x000E000E
#define GPIO_PQ0_EPI0S20        0x000E000F

#define GPIO_PQ1_T6CCP1         0x000E0403
#define GPIO_PQ1_KBCOUT05       0x000E0404
#define GPIO_PQ1_KBCOUT01       0x000E0405
#define GPIO_PQ1_FAN1TACH1      0x000E0406
#define GPIO_PQ1_SSI3FSS        0x000E040E
#define GPIO_PQ1_EPI0S21        0x000E040F

#define GPIO_PQ2_T7CCP0         0x000E0803
#define GPIO_PQ2_KBCOUT06       0x000E0804
#define GPIO_PQ2_KBCOUT02       0x000E0805
#define GPIO_PQ2_SSI3XDAT0      0x000E080E
#define GPIO_PQ2_EPI0S22        0x000E080F

#define GPIO_PQ3_T7CCP1         0x000E0C03
#define GPIO_PQ3_KBCOUT07       0x000E0C04
#define GPIO_PQ3_KBCOUT03       0x000E0C05
#define GPIO_PQ3_SSI3XDAT1      0x000E0C0E
#define GPIO_PQ3_EPI0S23        0x000E0C0F

#define GPIO_PQ4_U1RX           0x000E1001
#define GPIO_PQ4_KBCOUT13       0x000E1003
#define GPIO_PQ4_FAN1PWM0       0x000E1004
#define GPIO_PQ4_LPC0COMYRX     0x000E1005
#define GPIO_PQ4_DIVSCLK        0x000E1007

#define GPIO_PQ5_U1TX           0x000E1401
#define GPIO_PQ5_KBCOUT14       0x000E1403
#define GPIO_PQ5_FAN1TACH0      0x000E1404
#define GPIO_PQ5_LPC0COMYTX     0x000E1405
#define GPIO_PQ5_EN0RXD0        0x000E140E

#define GPIO_PQ6_U1DTR          0x000E1801
#define GPIO_PQ6_KBCOUT15       0x000E1803
#define GPIO_PQ6_FAN1PWM1       0x000E1804
#define GPIO_PQ6_EN0RXD1        0x000E180E

#define GPIO_PQ7_U1RI           0x000E1C01
#define GPIO_PQ7_FAN1TACH1      0x000E1C04

#define GPIO_PR0_U4TX           0x000F0001
#define GPIO_PR0_I2C1SCL        0x000F0002
#define GPIO_PR0_KBCOUT08       0x000F0004
#define GPIO_PR0_M0PWM0         0x000F0006
#define GPIO_PR0_LCDCP          0x000F000F

#define GPIO_PR1_U4RX           0x000F0401
#define GPIO_PR1_I2C1SDA        0x000F0402
#define GPIO_PR1_KBCOUT09       0x000F0404
#define GPIO_PR1_M0PWM1         0x000F0406
#define GPIO_PR1_LCDFP          0x000F040F

#define GPIO_PR2_I2C2SCL        0x000F0802
#define GPIO_PR2_KBCOUT10       0x000F0804
#define GPIO_PR2_M0PWM2         0x000F0806
#define GPIO_PR2_LCDLP          0x000F080F

#define GPIO_PR3_I2C2SDA        0x000F0C02
#define GPIO_PR3_KBCOUT11       0x000F0C04
#define GPIO_PR3_M0PWM3         0x000F0C06
#define GPIO_PR3_LCDDATA03      0x000F0C0F

#define GPIO_PR4_I2C3SCL        0x000F1002
#define GPIO_PR4_T0CCP0         0x000F1003
#define GPIO_PR4_KBCOUT12       0x000F1004
#define GPIO_PR4_M0PWM4         0x000F1006
#define GPIO_PR4_LCDDATA00      0x000F100F

#define GPIO_PR5_U1RX           0x000F1401
#define GPIO_PR5_I2C3SDA        0x000F1402
#define GPIO_PR5_T0CCP1         0x000F1403
#define GPIO_PR5_KBCOUT13       0x000F1404
#define GPIO_PR5_LPC0COMYRX     0x000F1405
#define GPIO_PR5_M0PWM5         0x000F1406
#define GPIO_PR5_LCDDATA01      0x000F140F

#define GPIO_PR6_U1TX           0x000F1801
#define GPIO_PR6_I2C4SCL        0x000F1802
#define GPIO_PR6_T1CCP0         0x000F1803
#define GPIO_PR6_KBCOUT14       0x000F1804
#define GPIO_PR6_LPC0COMYTX     0x000F1805
#define GPIO_PR6_M0PWM6         0x000F1806
#define GPIO_PR6_LCDDATA04      0x000F180F

#define GPIO_PR7_I2C4SDA        0x000F1C02
#define GPIO_PR7_T1CCP1         0x000F1C03
#define GPIO_PR7_KBCOUT15       0x000F1C04
#define GPIO_PR7_M0PWM7         0x000F1C06
#define GPIO_PR7_EN0TXEN        0x000F1C0E
#define GPIO_PR7_LCDDATA05      0x000F1C0F

#define GPIO_PS0_T2CCP0         0x00100003
#define GPIO_PS0_KBCOUT16       0x00100004
#define GPIO_PS0_M0FAULT0       0x00100006
#define GPIO_PS0_LPC0A20        0x0010000D
#define GPIO_PS0_LCDDATA20      0x0010000F

#define GPIO_PS1_T2CCP1         0x00100403
#define GPIO_PS1_KBCOUT17       0x00100404
#define GPIO_PS1_M0FAULT1       0x00100406
#define GPIO_PS1_LPC0RESET_N    0x0010040D
#define GPIO_PS1_LCDDATA21      0x0010040F

#define GPIO_PS2_U1DSR          0x00100801
#define GPIO_PS2_T3CCP0         0x00100803
#define GPIO_PS2_KBCOUT18       0x00100804
#define GPIO_PS2_M0FAULT2       0x00100806
#define GPIO_PS2_LCDDATA22      0x0010080F

#define GPIO_PS3_T3CCP1         0x00100C03
#define GPIO_PS3_KBCOUT19       0x00100C04
#define GPIO_PS3_M0FAULT3       0x00100C06
#define GPIO_PS3_LCDDATA23      0x00100C0F

#define GPIO_PS4_T4CCP0         0x00101003
#define GPIO_PS4_KBCIN07        0x00101004
#define GPIO_PS4_PHA0           0x00101006
#define GPIO_PS4_EN0TXD0        0x0010100E
#define GPIO_PS4_LCDDATA06      0x0010100F

#define GPIO_PS5_T4CCP1         0x00101403
#define GPIO_PS5_KBCIN06        0x00101404
#define GPIO_PS5_PHB0           0x00101406
#define GPIO_PS5_EN0TXD1        0x0010140E
#define GPIO_PS5_LCDDATA07      0x0010140F

#define GPIO_PS6_T5CCP0         0x00101803
#define GPIO_PS6_KBCIN05        0x00101804
#define GPIO_PS6_IDX0           0x00101806
#define GPIO_PS6_EN0RXER        0x0010180E
#define GPIO_PS6_LCDDATA08      0x0010180F

#define GPIO_PS7_T5CCP1         0x00101C03
#define GPIO_PS7_KBCIN04        0x00101C04
#define GPIO_PS7_EN0RXDV        0x00101C0E
#define GPIO_PS7_LCDDATA09      0x00101C0F

#define GPIO_PT0_T6CCP0         0x00110003
#define GPIO_PT0_KBCIN03        0x00110004
#define GPIO_PT0_CAN0RX         0x00110007
#define GPIO_PT0_EN0RXD0        0x0011000E
#define GPIO_PT0_LCDDATA10      0x0011000F

#define GPIO_PT1_T6CCP1         0x00110403
#define GPIO_PT1_KBCIN02        0x00110404
#define GPIO_PT1_CAN0TX         0x00110407
#define GPIO_PT1_EN0RXD1        0x0011040E
#define GPIO_PT1_LCDDATA11      0x0011040F

#define GPIO_PT2_T7CCP0         0x00110803
#define GPIO_PT2_KBCIN01        0x00110804
#define GPIO_PT2_CAN1RX         0x00110807
#define GPIO_PT2_LCDDATA18      0x0011080F

#define GPIO_PT3_T7CCP1         0x00110C03
#define GPIO_PT3_KBCIN00        0x00110C04
#define GPIO_PT3_CAN1TX         0x00110C07
#define GPIO_PT3_LCDDATA19      0x00110C0F

#endif // PART_TM4C129XNCZAD

#endif // __DRIVERLIB_PIN_MAP_H__
