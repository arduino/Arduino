// TI File $Revision: /main/5 $
// Checkin $Date: July 6, 2009   15:27:56 $
//###########################################################################
//
// FILE:   F2802x_Gpio.h
//
// TITLE:  F2802x General Purpose I/O Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_GPIO_H
#define F2802x_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// GPIO A control register bit definitions */
struct GPACTRL_BITS {        // bits   description
   uint16_t QUALPRD0:8;        // 7:0    Qual period
   uint16_t QUALPRD1:8;        // 15:8   Qual period
   uint16_t QUALPRD2:8;        // 23:16  Qual period
   uint16_t QUALPRD3:8;        // 31:24  Qual period
};

union GPACTRL_REG {
   uint32_t              all;
   struct GPACTRL_BITS bit;
};

//----------------------------------------------------
// GPIO B control register bit definitions */
struct GPBCTRL_BITS {        // bits   description
   uint16_t QUALPRD0:8;        // 7:0    Qual period
   uint16_t rsvd1:8;           // 15:8   reserved
   uint16_t rsvd2:16;          // 31:16  reserved
};

union GPBCTRL_REG {
   uint32_t              all;
   struct GPBCTRL_BITS bit;
};

//----------------------------------------------------
// GPIO Qual/MUX select register bit definitions */
struct GPA1_BITS {            // bits   description
   uint16_t GPIO0:2;            // 1:0    GPIO0
   uint16_t GPIO1:2;            // 3:2    GPIO1
   uint16_t GPIO2:2;            // 5:4    GPIO2
   uint16_t GPIO3:2;            // 7:6    GPIO3
   uint16_t GPIO4:2;            // 9:8    GPIO4
   uint16_t GPIO5:2;            // 11:10  GPIO5
   uint16_t GPIO6:2;            // 13:12  GPIO6
   uint16_t GPIO7:2;            // 15:14  GPIO7
   uint16_t GPIO8:2;            // 17:16  GPIO8
   uint16_t GPIO9:2;            // 19:18  GPIO9
   uint16_t GPIO10:2;           // 21:20  GPIO10
   uint16_t GPIO11:2;           // 23:22  GPIO11
   uint16_t GPIO12:2;           // 25:24  GPIO12
   uint16_t GPIO13:2;           // 27:26  GPIO13
   uint16_t GPIO14:2;           // 29:28  GPIO14
   uint16_t GPIO15:2;           // 31:30  GPIO15
};

struct GPA2_BITS {            // bits   description
   uint16_t GPIO16:2;           // 1:0    GPIO16
   uint16_t GPIO17:2;           // 3:2    GPIO17
   uint16_t GPIO18:2;           // 5:4    GPIO18
   uint16_t GPIO19:2;           // 7:6    GPIO19
   uint16_t GPIO20:2;           // 9:8    GPIO20
   uint16_t GPIO21:2;           // 11:10  GPIO21
   uint16_t GPIO22:2;           // 13:12  GPIO22
   uint16_t GPIO23:2;           // 15:14  GPIO23
   uint16_t GPIO24:2;           // 17:16  GPIO24
   uint16_t GPIO25:2;           // 19:18  GPIO25
   uint16_t GPIO26:2;           // 21:20  GPIO26
   uint16_t GPIO27:2;           // 23:22  GPIO27
   uint16_t GPIO28:2;           // 25:24  GPIO28
   uint16_t GPIO29:2;           // 27:26  GPIO29
   uint16_t GPIO30:2;           // 29:28  GPIO30
   uint16_t GPIO31:2;           // 31:30  GPIO31
};

struct GPB1_BITS {            // bits   description
   uint16_t GPIO32:2;           // 1:0    GPIO32
   uint16_t GPIO33:2;           // 3:2    GPIO33
   uint16_t GPIO34:2;           // 5:4    GPIO34
   uint16_t GPIO35:2;           // 7:6    GPIO35
   uint16_t GPIO36:2;           // 9:8    GPIO36
   uint16_t GPIO37:2;           // 11:10  GPIO37
   uint16_t GPIO38:2;           // 13:12  GPIO38
   uint16_t rsvd1:2;            // 15:14  reserved
   uint16_t rsvd2:16;           // 31:16  reserved
};

struct AIO_BITS {            // bits   description
   uint16_t rsvd1:2;           // 1:0    GPIO0
   uint16_t rsvd2:2;           // 3:2    GPIO1
   uint16_t AIO2:2;            // 5:4    GPIO2
   uint16_t rsvd3:2;           // 7:6    GPIO3
   uint16_t AIO4:2;            // 9:8    GPIO4
   uint16_t rsvd4:2;           // 11:10  GPIO5
   uint16_t AIO6:2;            // 13:12  GPIO6
   uint16_t rsvd5:2;           // 15:14  GPIO7
   uint16_t rsvd6:2;           // 17:16  GPIO8
   uint16_t rsvd7:2;           // 19:18  GPIO9
   uint16_t AIO10:2;           // 21:20  GPIO10
   uint16_t rsvd8:2;           // 23:22  GPIO11
   uint16_t AIO12:2;           // 25:24  GPIO12
   uint16_t rsvd9:2;           // 27:26  GPIO13
   uint16_t AIO14:2;           // 29:28  GPIO14
   uint16_t rsvd10:2;          // 31:30  GPIO15
};

union GPA1_REG {
   uint32_t              all;
   struct GPA1_BITS    bit;
};

union GPA2_REG {
   uint32_t              all;
   struct GPA2_BITS    bit;
};

union GPB1_REG {
   uint32_t              all;
   struct GPB1_BITS    bit;
};

union AIO_REG {
   uint32_t              all;
   struct AIO_BITS     bit;
};

//----------------------------------------------------
// GPIO DIR/TOGGLE/SET/CLEAR register bit definitions */
struct GPADAT_BITS {          // bits   description
   uint16_t GPIO0:1;            // 0      GPIO0
   uint16_t GPIO1:1;            // 1      GPIO1
   uint16_t GPIO2:1;            // 2      GPIO2
   uint16_t GPIO3:1;            // 3      GPIO3
   uint16_t GPIO4:1;            // 4      GPIO4
   uint16_t GPIO5:1;            // 5      GPIO5
   uint16_t GPIO6:1;            // 6      GPIO6
   uint16_t GPIO7:1;            // 7      GPIO7
   uint16_t GPIO8:1;            // 8      GPIO8
   uint16_t GPIO9:1;            // 9      GPIO9
   uint16_t GPIO10:1;           // 10     GPIO10
   uint16_t GPIO11:1;           // 11     GPIO11
   uint16_t GPIO12:1;           // 12     GPIO12
   uint16_t GPIO13:1;           // 13     GPIO13
   uint16_t GPIO14:1;           // 14     GPIO14
   uint16_t GPIO15:1;           // 15     GPIO15
   uint16_t GPIO16:1;           // 16     GPIO16
   uint16_t GPIO17:1;           // 17     GPIO17
   uint16_t GPIO18:1;           // 18     GPIO18
   uint16_t GPIO19:1;           // 19     GPIO19
   uint16_t GPIO20:1;           // 20     GPIO20
   uint16_t GPIO21:1;           // 21     GPIO21
   uint16_t GPIO22:1;           // 22     GPIO22
   uint16_t GPIO23:1;           // 23     GPIO23
   uint16_t GPIO24:1;           // 24     GPIO24
   uint16_t GPIO25:1;           // 25     GPIO25
   uint16_t GPIO26:1;           // 26     GPIO26
   uint16_t GPIO27:1;           // 27     GPIO27
   uint16_t GPIO28:1;           // 28     GPIO28
   uint16_t GPIO29:1;           // 29     GPIO29
   uint16_t GPIO30:1;           // 30     GPIO30
   uint16_t GPIO31:1;           // 31     GPIO31
};

struct GPBDAT_BITS {          // bits   description
   uint16_t GPIO32:1;           // 0      GPIO32
   uint16_t GPIO33:1;           // 1      GPIO33
   uint16_t GPIO34:1;           // 2      GPIO34
   uint16_t GPIO35:1;           // 3      GPIO35
   uint16_t GPIO36:1;           // 4      GPIO36
   uint16_t GPIO37:1;           // 5      GPIO37
   uint16_t GPIO38:1;           // 6      GPIO38
   uint16_t rsvd1:9;            // 15:7   reserved
   uint16_t rsvd2:16;           // 31:16  reserved
};

struct AIODAT_BITS {         // bits   description
   uint16_t rsvd1:1;           // 0      reserved
   uint16_t rsvd2:1;           // 1      reserved
   uint16_t AIO2:1;            // 2      AIO2
   uint16_t rsvd3:1;           // 3      reserved
   uint16_t AIO4:1;            // 4      AIO4
   uint16_t rsvd4:1;           // 5      reserved
   uint16_t AIO6:1;            // 6      AIO6
   uint16_t rsvd5:1;           // 7      reserved
   uint16_t rsvd6:1;           // 8      reserved
   uint16_t rsvd7:1;           // 9      reserved
   uint16_t AIO10:1;           // 10     AIO10
   uint16_t rsvd8:1;           // 11     reserved
   uint16_t AIO12:1;           // 12     AIO12
   uint16_t rsvd9:1;           // 13     reserved
   uint16_t AIO14:1;           // 14     AIO14
   uint16_t rsvd10:1;          // 15     reserved
};

union GPADAT_REG {
   uint32_t              all;
   struct GPADAT_BITS  bit;
};

union GPBDAT_REG {
   uint32_t              all;
   struct GPBDAT_BITS  bit;
};

union AIODAT_REG {
   uint16_t               all;
   struct AIODAT_BITS  bit;
};

//----------------------------------------------------------------
// GPIO XINT1/XINT2/XNMI/XCLKIN select register bit definitions */
struct GPIOXINT_BITS {        // bits   description
    uint16_t GPIOSEL:5;         // 4:0    Select GPIO interrupt input source
    uint16_t rsvd1:11;          // 15:5   reserved
};

union GPIOXINT_REG {
   uint16_t                all;
   struct GPIOXINT_BITS  bit;
};

struct GPIO_CTRL_REGS {
   union  GPACTRL_REG  GPACTRL;   // GPIO A Control Register (GPIO0 to 31)
   union  GPA1_REG     GPAQSEL1;  // GPIO A Qualifier Select 1 Register (GPIO0 to 15)
   union  GPA2_REG     GPAQSEL2;  // GPIO A Qualifier Select 2 Register (GPIO16 to 31)
   union  GPA1_REG     GPAMUX1;   // GPIO A Mux 1 Register (GPIO0 to 15)
   union  GPA2_REG     GPAMUX2;   // GPIO A Mux 2 Register (GPIO16 to 31)
   union  GPADAT_REG   GPADIR;    // GPIO A Direction Register (GPIO0 to 31)
   union  GPADAT_REG   GPAPUD;    // GPIO A Pull Up Disable Register (GPIO0 to 31)
   uint32_t              rsvd1;     // reserved
   union  GPBCTRL_REG  GPBCTRL;   // GPIO B Control Register (GPIO32 to 38)
   union  GPB1_REG     GPBQSEL1;  // GPIO B Qualifier Select 1 Register (GPIO32 to 38)
   uint32_t              rsvd2;     // reserved
   union  GPB1_REG     GPBMUX1;   // GPIO B Mux 1 Register (GPIO32 to 38)
   uint32_t              rsvd3;     // reserved
   union  GPBDAT_REG   GPBDIR;    // GPIO B Direction Register (GPIO32 to 38)
   union  GPBDAT_REG   GPBPUD;    // GPIO B Pull Up Disable Register (GPIO32 to 38)
   uint16_t              rsvd4[24]; // reserved
   union  AIO_REG      AIOMUX1;   // Analog IO Mux 1 Register (AIO0 to 15)
   uint32_t              rsvd5;     // reserved
   union  AIODAT_REG   AIODIR;    // Analog IO Direction Register (AIO0 to 15)
   uint16_t              rsvd6[5];  // reserved
};

struct GPIO_DATA_REGS {
   union  GPADAT_REG       GPADAT;       // GPIO Data Register (GPIO0 to 31)
   union  GPADAT_REG       GPASET;       // GPIO Data Set Register (GPIO0 to 31)
   union  GPADAT_REG       GPACLEAR;     // GPIO Data Clear Register (GPIO0 to 31)
   union  GPADAT_REG       GPATOGGLE;    // GPIO Data Toggle Register (GPIO0 to 31)
   union  GPBDAT_REG       GPBDAT;       // GPIO Data Register (GPIO32 to 38)
   union  GPBDAT_REG       GPBSET;       // GPIO Data Set Register (GPIO32 to 38)
   union  GPBDAT_REG       GPBCLEAR;     // GPIO Data Clear Register (GPIO32 to 38)
   union  GPBDAT_REG       GPBTOGGLE;    // GPIO Data Toggle Register (GPIO32 to 38)
   uint16_t                  rsvd1[8];     // reserved
   union  AIODAT_REG       AIODAT;       // Analog IO Data Register (AIO0-15)
   uint16_t                   rsvd2;
   union  AIODAT_REG       AIOSET;       // Analog IO Data Set Register (AIO0-15)
   uint16_t                   rsvd3;
   union  AIODAT_REG       AIOCLEAR;     // Analog IO Data Clear Register (AIO0-15)
   uint16_t                   rsvd4;
   union  AIODAT_REG       AIOTOGGLE;    // Analog IO Data Toggle Register (AIO0-15)
   uint16_t                   rsvd5;
};

struct GPIO_INT_REGS {
   union  GPIOXINT_REG     GPIOXINT1SEL; // XINT1 GPIO Input Selection
   union  GPIOXINT_REG     GPIOXINT2SEL; // XINT2 GPIO Input Selection
   union  GPIOXINT_REG     GPIOXINT3SEL; // XINT3 GPIO Input Selection
   uint16_t                  rsvd1[5];
   union  GPADAT_REG       GPIOLPMSEL;   // Low power modes GPIO input select
};

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS GpioIntRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_GPIO_H definition

//===========================================================================
// End of file.
//===========================================================================
