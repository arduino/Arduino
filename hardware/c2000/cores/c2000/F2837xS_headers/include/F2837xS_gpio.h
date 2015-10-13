//###########################################################################
//
// FILE:    F2837xS_gpio.h
//
// TITLE:   F2837xS Device GPIO Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_GPIO_H__
#define __F2837xS_GPIO_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// GPIO Individual Register Bit Definitions:

struct GPACTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO0 to GPIO7
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO8 to GPIO15
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO16 to GPIO23
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO24 to GPIO31
};

union GPACTRL_REG {
    Uint32  all;
    struct  GPACTRL_BITS  bit;
};

struct GPAQSEL1_BITS {                  // bits description
    Uint16 GPIO0:2;                     // 1:0 Select input qualification type for GPIO0
    Uint16 GPIO1:2;                     // 3:2 Select input qualification type for GPIO1
    Uint16 GPIO2:2;                     // 5:4 Select input qualification type for GPIO2
    Uint16 GPIO3:2;                     // 7:6 Select input qualification type for GPIO3
    Uint16 GPIO4:2;                     // 9:8 Select input qualification type for GPIO4
    Uint16 GPIO5:2;                     // 11:10 Select input qualification type for GPIO5
    Uint16 GPIO6:2;                     // 13:12 Select input qualification type for GPIO6
    Uint16 GPIO7:2;                     // 15:14 Select input qualification type for GPIO7
    Uint16 GPIO8:2;                     // 17:16 Select input qualification type for GPIO8
    Uint16 GPIO9:2;                     // 19:18 Select input qualification type for GPIO9
    Uint16 GPIO10:2;                    // 21:20 Select input qualification type for GPIO10
    Uint16 GPIO11:2;                    // 23:22 Select input qualification type for GPIO11
    Uint16 GPIO12:2;                    // 25:24 Select input qualification type for GPIO12
    Uint16 GPIO13:2;                    // 27:26 Select input qualification type for GPIO13
    Uint16 GPIO14:2;                    // 29:28 Select input qualification type for GPIO14
    Uint16 GPIO15:2;                    // 31:30 Select input qualification type for GPIO15
};

union GPAQSEL1_REG {
    Uint32  all;
    struct  GPAQSEL1_BITS  bit;
};

struct GPAQSEL2_BITS {                  // bits description
    Uint16 GPIO16:2;                    // 1:0 Select input qualification type for GPIO16
    Uint16 GPIO17:2;                    // 3:2 Select input qualification type for GPIO17
    Uint16 GPIO18:2;                    // 5:4 Select input qualification type for GPIO18
    Uint16 GPIO19:2;                    // 7:6 Select input qualification type for GPIO19
    Uint16 GPIO20:2;                    // 9:8 Select input qualification type for GPIO20
    Uint16 GPIO21:2;                    // 11:10 Select input qualification type for GPIO21
    Uint16 GPIO22:2;                    // 13:12 Select input qualification type for GPIO22
    Uint16 GPIO23:2;                    // 15:14 Select input qualification type for GPIO23
    Uint16 GPIO24:2;                    // 17:16 Select input qualification type for GPIO24
    Uint16 GPIO25:2;                    // 19:18 Select input qualification type for GPIO25
    Uint16 GPIO26:2;                    // 21:20 Select input qualification type for GPIO26
    Uint16 GPIO27:2;                    // 23:22 Select input qualification type for GPIO27
    Uint16 GPIO28:2;                    // 25:24 Select input qualification type for GPIO28
    Uint16 GPIO29:2;                    // 27:26 Select input qualification type for GPIO29
    Uint16 GPIO30:2;                    // 29:28 Select input qualification type for GPIO30
    Uint16 GPIO31:2;                    // 31:30 Select input qualification type for GPIO31
};

union GPAQSEL2_REG {
    Uint32  all;
    struct  GPAQSEL2_BITS  bit;
};

struct GPAMUX1_BITS {                   // bits description
    Uint16 GPIO0:2;                     // 1:0 Defines pin-muxing selection for GPIO0
    Uint16 GPIO1:2;                     // 3:2 Defines pin-muxing selection for GPIO1
    Uint16 GPIO2:2;                     // 5:4 Defines pin-muxing selection for GPIO2
    Uint16 GPIO3:2;                     // 7:6 Defines pin-muxing selection for GPIO3
    Uint16 GPIO4:2;                     // 9:8 Defines pin-muxing selection for GPIO4
    Uint16 GPIO5:2;                     // 11:10 Defines pin-muxing selection for GPIO5
    Uint16 GPIO6:2;                     // 13:12 Defines pin-muxing selection for GPIO6
    Uint16 GPIO7:2;                     // 15:14 Defines pin-muxing selection for GPIO7
    Uint16 GPIO8:2;                     // 17:16 Defines pin-muxing selection for GPIO8
    Uint16 GPIO9:2;                     // 19:18 Defines pin-muxing selection for GPIO9
    Uint16 GPIO10:2;                    // 21:20 Defines pin-muxing selection for GPIO10
    Uint16 GPIO11:2;                    // 23:22 Defines pin-muxing selection for GPIO11
    Uint16 GPIO12:2;                    // 25:24 Defines pin-muxing selection for GPIO12
    Uint16 GPIO13:2;                    // 27:26 Defines pin-muxing selection for GPIO13
    Uint16 GPIO14:2;                    // 29:28 Defines pin-muxing selection for GPIO14
    Uint16 GPIO15:2;                    // 31:30 Defines pin-muxing selection for GPIO15
};

union GPAMUX1_REG {
    Uint32  all;
    struct  GPAMUX1_BITS  bit;
};

struct GPAMUX2_BITS {                   // bits description
    Uint16 GPIO16:2;                    // 1:0 Defines pin-muxing selection for GPIO16
    Uint16 GPIO17:2;                    // 3:2 Defines pin-muxing selection for GPIO17
    Uint16 GPIO18:2;                    // 5:4 Defines pin-muxing selection for GPIO18
    Uint16 GPIO19:2;                    // 7:6 Defines pin-muxing selection for GPIO19
    Uint16 GPIO20:2;                    // 9:8 Defines pin-muxing selection for GPIO20
    Uint16 GPIO21:2;                    // 11:10 Defines pin-muxing selection for GPIO21
    Uint16 GPIO22:2;                    // 13:12 Defines pin-muxing selection for GPIO22
    Uint16 GPIO23:2;                    // 15:14 Defines pin-muxing selection for GPIO23
    Uint16 GPIO24:2;                    // 17:16 Defines pin-muxing selection for GPIO24
    Uint16 GPIO25:2;                    // 19:18 Defines pin-muxing selection for GPIO25
    Uint16 GPIO26:2;                    // 21:20 Defines pin-muxing selection for GPIO26
    Uint16 GPIO27:2;                    // 23:22 Defines pin-muxing selection for GPIO27
    Uint16 GPIO28:2;                    // 25:24 Defines pin-muxing selection for GPIO28
    Uint16 GPIO29:2;                    // 27:26 Defines pin-muxing selection for GPIO29
    Uint16 GPIO30:2;                    // 29:28 Defines pin-muxing selection for GPIO30
    Uint16 GPIO31:2;                    // 31:30 Defines pin-muxing selection for GPIO31
};

union GPAMUX2_REG {
    Uint32  all;
    struct  GPAMUX2_BITS  bit;
};

struct GPADIR_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO1:1;                     // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO2:1;                     // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO3:1;                     // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO4:1;                     // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO5:1;                     // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO6:1;                     // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO7:1;                     // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO8:1;                     // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO9:1;                     // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO10:1;                    // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO11:1;                    // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO12:1;                    // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO13:1;                    // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO14:1;                    // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO15:1;                    // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO16:1;                    // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO17:1;                    // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO18:1;                    // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO19:1;                    // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO20:1;                    // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO21:1;                    // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO22:1;                    // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO23:1;                    // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO24:1;                    // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO25:1;                    // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO26:1;                    // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO27:1;                    // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO28:1;                    // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO29:1;                    // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO30:1;                    // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO31:1;                    // 31 Defines direction for this pin in GPIO mode
};

union GPADIR_REG {
    Uint32  all;
    struct  GPADIR_BITS  bit;
};

struct GPAPUD_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Pull-Up Disable control for this pin
    Uint16 GPIO1:1;                     // 1 Pull-Up Disable control for this pin
    Uint16 GPIO2:1;                     // 2 Pull-Up Disable control for this pin
    Uint16 GPIO3:1;                     // 3 Pull-Up Disable control for this pin
    Uint16 GPIO4:1;                     // 4 Pull-Up Disable control for this pin
    Uint16 GPIO5:1;                     // 5 Pull-Up Disable control for this pin
    Uint16 GPIO6:1;                     // 6 Pull-Up Disable control for this pin
    Uint16 GPIO7:1;                     // 7 Pull-Up Disable control for this pin
    Uint16 GPIO8:1;                     // 8 Pull-Up Disable control for this pin
    Uint16 GPIO9:1;                     // 9 Pull-Up Disable control for this pin
    Uint16 GPIO10:1;                    // 10 Pull-Up Disable control for this pin
    Uint16 GPIO11:1;                    // 11 Pull-Up Disable control for this pin
    Uint16 GPIO12:1;                    // 12 Pull-Up Disable control for this pin
    Uint16 GPIO13:1;                    // 13 Pull-Up Disable control for this pin
    Uint16 GPIO14:1;                    // 14 Pull-Up Disable control for this pin
    Uint16 GPIO15:1;                    // 15 Pull-Up Disable control for this pin
    Uint16 GPIO16:1;                    // 16 Pull-Up Disable control for this pin
    Uint16 GPIO17:1;                    // 17 Pull-Up Disable control for this pin
    Uint16 GPIO18:1;                    // 18 Pull-Up Disable control for this pin
    Uint16 GPIO19:1;                    // 19 Pull-Up Disable control for this pin
    Uint16 GPIO20:1;                    // 20 Pull-Up Disable control for this pin
    Uint16 GPIO21:1;                    // 21 Pull-Up Disable control for this pin
    Uint16 GPIO22:1;                    // 22 Pull-Up Disable control for this pin
    Uint16 GPIO23:1;                    // 23 Pull-Up Disable control for this pin
    Uint16 GPIO24:1;                    // 24 Pull-Up Disable control for this pin
    Uint16 GPIO25:1;                    // 25 Pull-Up Disable control for this pin
    Uint16 GPIO26:1;                    // 26 Pull-Up Disable control for this pin
    Uint16 GPIO27:1;                    // 27 Pull-Up Disable control for this pin
    Uint16 GPIO28:1;                    // 28 Pull-Up Disable control for this pin
    Uint16 GPIO29:1;                    // 29 Pull-Up Disable control for this pin
    Uint16 GPIO30:1;                    // 30 Pull-Up Disable control for this pin
    Uint16 GPIO31:1;                    // 31 Pull-Up Disable control for this pin
};

union GPAPUD_REG {
    Uint32  all;
    struct  GPAPUD_BITS  bit;
};

struct GPAINV_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Input inversion control for this pin
    Uint16 GPIO1:1;                     // 1 Input inversion control for this pin
    Uint16 GPIO2:1;                     // 2 Input inversion control for this pin
    Uint16 GPIO3:1;                     // 3 Input inversion control for this pin
    Uint16 GPIO4:1;                     // 4 Input inversion control for this pin
    Uint16 GPIO5:1;                     // 5 Input inversion control for this pin
    Uint16 GPIO6:1;                     // 6 Input inversion control for this pin
    Uint16 GPIO7:1;                     // 7 Input inversion control for this pin
    Uint16 GPIO8:1;                     // 8 Input inversion control for this pin
    Uint16 GPIO9:1;                     // 9 Input inversion control for this pin
    Uint16 GPIO10:1;                    // 10 Input inversion control for this pin
    Uint16 GPIO11:1;                    // 11 Input inversion control for this pin
    Uint16 GPIO12:1;                    // 12 Input inversion control for this pin
    Uint16 GPIO13:1;                    // 13 Input inversion control for this pin
    Uint16 GPIO14:1;                    // 14 Input inversion control for this pin
    Uint16 GPIO15:1;                    // 15 Input inversion control for this pin
    Uint16 GPIO16:1;                    // 16 Input inversion control for this pin
    Uint16 GPIO17:1;                    // 17 Input inversion control for this pin
    Uint16 GPIO18:1;                    // 18 Input inversion control for this pin
    Uint16 GPIO19:1;                    // 19 Input inversion control for this pin
    Uint16 GPIO20:1;                    // 20 Input inversion control for this pin
    Uint16 GPIO21:1;                    // 21 Input inversion control for this pin
    Uint16 GPIO22:1;                    // 22 Input inversion control for this pin
    Uint16 GPIO23:1;                    // 23 Input inversion control for this pin
    Uint16 GPIO24:1;                    // 24 Input inversion control for this pin
    Uint16 GPIO25:1;                    // 25 Input inversion control for this pin
    Uint16 GPIO26:1;                    // 26 Input inversion control for this pin
    Uint16 GPIO27:1;                    // 27 Input inversion control for this pin
    Uint16 GPIO28:1;                    // 28 Input inversion control for this pin
    Uint16 GPIO29:1;                    // 29 Input inversion control for this pin
    Uint16 GPIO30:1;                    // 30 Input inversion control for this pin
    Uint16 GPIO31:1;                    // 31 Input inversion control for this pin
};

union GPAINV_REG {
    Uint32  all;
    struct  GPAINV_BITS  bit;
};

struct GPAODR_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO1:1;                     // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO2:1;                     // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO3:1;                     // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO4:1;                     // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO5:1;                     // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO6:1;                     // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO7:1;                     // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO8:1;                     // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO9:1;                     // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO10:1;                    // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO11:1;                    // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO12:1;                    // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO13:1;                    // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO14:1;                    // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO15:1;                    // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO16:1;                    // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO17:1;                    // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO18:1;                    // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO19:1;                    // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO20:1;                    // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO21:1;                    // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO22:1;                    // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO23:1;                    // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO24:1;                    // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO25:1;                    // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO26:1;                    // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO27:1;                    // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO28:1;                    // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO29:1;                    // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO30:1;                    // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO31:1;                    // 31 Outpout Open-Drain control for this pin
};

union GPAODR_REG {
    Uint32  all;
    struct  GPAODR_BITS  bit;
};

struct GPAGMUX1_BITS {                  // bits description
    Uint16 GPIO0:2;                     // 1:0 Defines pin-muxing selection for GPIO0
    Uint16 GPIO1:2;                     // 3:2 Defines pin-muxing selection for GPIO1
    Uint16 GPIO2:2;                     // 5:4 Defines pin-muxing selection for GPIO2
    Uint16 GPIO3:2;                     // 7:6 Defines pin-muxing selection for GPIO3
    Uint16 GPIO4:2;                     // 9:8 Defines pin-muxing selection for GPIO4
    Uint16 GPIO5:2;                     // 11:10 Defines pin-muxing selection for GPIO5
    Uint16 GPIO6:2;                     // 13:12 Defines pin-muxing selection for GPIO6
    Uint16 GPIO7:2;                     // 15:14 Defines pin-muxing selection for GPIO7
    Uint16 GPIO8:2;                     // 17:16 Defines pin-muxing selection for GPIO8
    Uint16 GPIO9:2;                     // 19:18 Defines pin-muxing selection for GPIO9
    Uint16 GPIO10:2;                    // 21:20 Defines pin-muxing selection for GPIO10
    Uint16 GPIO11:2;                    // 23:22 Defines pin-muxing selection for GPIO11
    Uint16 GPIO12:2;                    // 25:24 Defines pin-muxing selection for GPIO12
    Uint16 GPIO13:2;                    // 27:26 Defines pin-muxing selection for GPIO13
    Uint16 GPIO14:2;                    // 29:28 Defines pin-muxing selection for GPIO14
    Uint16 GPIO15:2;                    // 31:30 Defines pin-muxing selection for GPIO15
};

union GPAGMUX1_REG {
    Uint32  all;
    struct  GPAGMUX1_BITS  bit;
};

struct GPAGMUX2_BITS {                  // bits description
    Uint16 GPIO16:2;                    // 1:0 Defines pin-muxing selection for GPIO16
    Uint16 GPIO17:2;                    // 3:2 Defines pin-muxing selection for GPIO17
    Uint16 GPIO18:2;                    // 5:4 Defines pin-muxing selection for GPIO18
    Uint16 GPIO19:2;                    // 7:6 Defines pin-muxing selection for GPIO19
    Uint16 GPIO20:2;                    // 9:8 Defines pin-muxing selection for GPIO20
    Uint16 GPIO21:2;                    // 11:10 Defines pin-muxing selection for GPIO21
    Uint16 GPIO22:2;                    // 13:12 Defines pin-muxing selection for GPIO22
    Uint16 GPIO23:2;                    // 15:14 Defines pin-muxing selection for GPIO23
    Uint16 GPIO24:2;                    // 17:16 Defines pin-muxing selection for GPIO24
    Uint16 GPIO25:2;                    // 19:18 Defines pin-muxing selection for GPIO25
    Uint16 GPIO26:2;                    // 21:20 Defines pin-muxing selection for GPIO26
    Uint16 GPIO27:2;                    // 23:22 Defines pin-muxing selection for GPIO27
    Uint16 GPIO28:2;                    // 25:24 Defines pin-muxing selection for GPIO28
    Uint16 GPIO29:2;                    // 27:26 Defines pin-muxing selection for GPIO29
    Uint16 GPIO30:2;                    // 29:28 Defines pin-muxing selection for GPIO30
    Uint16 GPIO31:2;                    // 31:30 Defines pin-muxing selection for GPIO31
};

union GPAGMUX2_REG {
    Uint32  all;
    struct  GPAGMUX2_BITS  bit;
};

struct GPACSEL1_BITS {                  // bits description
    Uint16 GPIO0:4;                     // 3:0 GPIO0 Master CPU Select
    Uint16 GPIO1:4;                     // 7:4 GPIO1 Master CPU Select
    Uint16 GPIO2:4;                     // 11:8 GPIO2 Master CPU Select
    Uint16 GPIO3:4;                     // 15:12 GPIO3 Master CPU Select
    Uint16 GPIO4:4;                     // 19:16 GPIO4 Master CPU Select
    Uint16 GPIO5:4;                     // 23:20 GPIO5 Master CPU Select
    Uint16 GPIO6:4;                     // 27:24 GPIO6 Master CPU Select
    Uint16 GPIO7:4;                     // 31:28 GPIO7 Master CPU Select
};

union GPACSEL1_REG {
    Uint32  all;
    struct  GPACSEL1_BITS  bit;
};

struct GPACSEL2_BITS {                  // bits description
    Uint16 GPIO8:4;                     // 3:0 GPIO8 Master CPU Select
    Uint16 GPIO9:4;                     // 7:4 GPIO9 Master CPU Select
    Uint16 GPIO10:4;                    // 11:8 GPIO10 Master CPU Select
    Uint16 GPIO11:4;                    // 15:12 GPIO11 Master CPU Select
    Uint16 GPIO12:4;                    // 19:16 GPIO12 Master CPU Select
    Uint16 GPIO13:4;                    // 23:20 GPIO13 Master CPU Select
    Uint16 GPIO14:4;                    // 27:24 GPIO14 Master CPU Select
    Uint16 GPIO15:4;                    // 31:28 GPIO15 Master CPU Select
};

union GPACSEL2_REG {
    Uint32  all;
    struct  GPACSEL2_BITS  bit;
};

struct GPACSEL3_BITS {                  // bits description
    Uint16 GPIO16:4;                    // 3:0 GPIO16 Master CPU Select
    Uint16 GPIO17:4;                    // 7:4 GPIO17 Master CPU Select
    Uint16 GPIO18:4;                    // 11:8 GPIO18 Master CPU Select
    Uint16 GPIO19:4;                    // 15:12 GPIO19 Master CPU Select
    Uint16 GPIO20:4;                    // 19:16 GPIO20 Master CPU Select
    Uint16 GPIO21:4;                    // 23:20 GPIO21 Master CPU Select
    Uint16 GPIO22:4;                    // 27:24 GPIO22 Master CPU Select
    Uint16 GPIO23:4;                    // 31:28 GPIO23 Master CPU Select
};

union GPACSEL3_REG {
    Uint32  all;
    struct  GPACSEL3_BITS  bit;
};

struct GPACSEL4_BITS {                  // bits description
    Uint16 GPIO24:4;                    // 3:0 GPIO24 Master CPU Select
    Uint16 GPIO25:4;                    // 7:4 GPIO25 Master CPU Select
    Uint16 GPIO26:4;                    // 11:8 GPIO26 Master CPU Select
    Uint16 GPIO27:4;                    // 15:12 GPIO27 Master CPU Select
    Uint16 GPIO28:4;                    // 19:16 GPIO28 Master CPU Select
    Uint16 GPIO29:4;                    // 23:20 GPIO29 Master CPU Select
    Uint16 GPIO30:4;                    // 27:24 GPIO30 Master CPU Select
    Uint16 GPIO31:4;                    // 31:28 GPIO31 Master CPU Select
};

union GPACSEL4_REG {
    Uint32  all;
    struct  GPACSEL4_BITS  bit;
};

struct GPALOCK_BITS {                   // bits description
    Uint16 GPIO0:1;                     // 0 Configuration Lock bit for this pin
    Uint16 GPIO1:1;                     // 1 Configuration Lock bit for this pin
    Uint16 GPIO2:1;                     // 2 Configuration Lock bit for this pin
    Uint16 GPIO3:1;                     // 3 Configuration Lock bit for this pin
    Uint16 GPIO4:1;                     // 4 Configuration Lock bit for this pin
    Uint16 GPIO5:1;                     // 5 Configuration Lock bit for this pin
    Uint16 GPIO6:1;                     // 6 Configuration Lock bit for this pin
    Uint16 GPIO7:1;                     // 7 Configuration Lock bit for this pin
    Uint16 GPIO8:1;                     // 8 Configuration Lock bit for this pin
    Uint16 GPIO9:1;                     // 9 Configuration Lock bit for this pin
    Uint16 GPIO10:1;                    // 10 Configuration Lock bit for this pin
    Uint16 GPIO11:1;                    // 11 Configuration Lock bit for this pin
    Uint16 GPIO12:1;                    // 12 Configuration Lock bit for this pin
    Uint16 GPIO13:1;                    // 13 Configuration Lock bit for this pin
    Uint16 GPIO14:1;                    // 14 Configuration Lock bit for this pin
    Uint16 GPIO15:1;                    // 15 Configuration Lock bit for this pin
    Uint16 GPIO16:1;                    // 16 Configuration Lock bit for this pin
    Uint16 GPIO17:1;                    // 17 Configuration Lock bit for this pin
    Uint16 GPIO18:1;                    // 18 Configuration Lock bit for this pin
    Uint16 GPIO19:1;                    // 19 Configuration Lock bit for this pin
    Uint16 GPIO20:1;                    // 20 Configuration Lock bit for this pin
    Uint16 GPIO21:1;                    // 21 Configuration Lock bit for this pin
    Uint16 GPIO22:1;                    // 22 Configuration Lock bit for this pin
    Uint16 GPIO23:1;                    // 23 Configuration Lock bit for this pin
    Uint16 GPIO24:1;                    // 24 Configuration Lock bit for this pin
    Uint16 GPIO25:1;                    // 25 Configuration Lock bit for this pin
    Uint16 GPIO26:1;                    // 26 Configuration Lock bit for this pin
    Uint16 GPIO27:1;                    // 27 Configuration Lock bit for this pin
    Uint16 GPIO28:1;                    // 28 Configuration Lock bit for this pin
    Uint16 GPIO29:1;                    // 29 Configuration Lock bit for this pin
    Uint16 GPIO30:1;                    // 30 Configuration Lock bit for this pin
    Uint16 GPIO31:1;                    // 31 Configuration Lock bit for this pin
};

union GPALOCK_REG {
    Uint32  all;
    struct  GPALOCK_BITS  bit;
};

struct GPACR_BITS {                     // bits description
    Uint16 GPIO0:1;                     // 0 Configuration lock commit bit for this pin
    Uint16 GPIO1:1;                     // 1 Configuration lock commit bit for this pin
    Uint16 GPIO2:1;                     // 2 Configuration lock commit bit for this pin
    Uint16 GPIO3:1;                     // 3 Configuration lock commit bit for this pin
    Uint16 GPIO4:1;                     // 4 Configuration lock commit bit for this pin
    Uint16 GPIO5:1;                     // 5 Configuration lock commit bit for this pin
    Uint16 GPIO6:1;                     // 6 Configuration lock commit bit for this pin
    Uint16 GPIO7:1;                     // 7 Configuration lock commit bit for this pin
    Uint16 GPIO8:1;                     // 8 Configuration lock commit bit for this pin
    Uint16 GPIO9:1;                     // 9 Configuration lock commit bit for this pin
    Uint16 GPIO10:1;                    // 10 Configuration lock commit bit for this pin
    Uint16 GPIO11:1;                    // 11 Configuration lock commit bit for this pin
    Uint16 GPIO12:1;                    // 12 Configuration lock commit bit for this pin
    Uint16 GPIO13:1;                    // 13 Configuration lock commit bit for this pin
    Uint16 GPIO14:1;                    // 14 Configuration lock commit bit for this pin
    Uint16 GPIO15:1;                    // 15 Configuration lock commit bit for this pin
    Uint16 GPIO16:1;                    // 16 Configuration lock commit bit for this pin
    Uint16 GPIO17:1;                    // 17 Configuration lock commit bit for this pin
    Uint16 GPIO18:1;                    // 18 Configuration lock commit bit for this pin
    Uint16 GPIO19:1;                    // 19 Configuration lock commit bit for this pin
    Uint16 GPIO20:1;                    // 20 Configuration lock commit bit for this pin
    Uint16 GPIO21:1;                    // 21 Configuration lock commit bit for this pin
    Uint16 GPIO22:1;                    // 22 Configuration lock commit bit for this pin
    Uint16 GPIO23:1;                    // 23 Configuration lock commit bit for this pin
    Uint16 GPIO24:1;                    // 24 Configuration lock commit bit for this pin
    Uint16 GPIO25:1;                    // 25 Configuration lock commit bit for this pin
    Uint16 GPIO26:1;                    // 26 Configuration lock commit bit for this pin
    Uint16 GPIO27:1;                    // 27 Configuration lock commit bit for this pin
    Uint16 GPIO28:1;                    // 28 Configuration lock commit bit for this pin
    Uint16 GPIO29:1;                    // 29 Configuration lock commit bit for this pin
    Uint16 GPIO30:1;                    // 30 Configuration lock commit bit for this pin
    Uint16 GPIO31:1;                    // 31 Configuration lock commit bit for this pin
};

union GPACR_REG {
    Uint32  all;
    struct  GPACR_BITS  bit;
};

struct GPBCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO32 to GPIO39
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO40 to GPIO47
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO48 to GPIO55
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO56 to GPIO63
};

union GPBCTRL_REG {
    Uint32  all;
    struct  GPBCTRL_BITS  bit;
};

struct GPBQSEL1_BITS {                  // bits description
    Uint16 GPIO32:2;                    // 1:0 Select input qualification type for GPIO32
    Uint16 GPIO33:2;                    // 3:2 Select input qualification type for GPIO33
    Uint16 GPIO34:2;                    // 5:4 Select input qualification type for GPIO34
    Uint16 GPIO35:2;                    // 7:6 Select input qualification type for GPIO35
    Uint16 GPIO36:2;                    // 9:8 Select input qualification type for GPIO36
    Uint16 GPIO37:2;                    // 11:10 Select input qualification type for GPIO37
    Uint16 GPIO38:2;                    // 13:12 Select input qualification type for GPIO38
    Uint16 GPIO39:2;                    // 15:14 Select input qualification type for GPIO39
    Uint16 GPIO40:2;                    // 17:16 Select input qualification type for GPIO40
    Uint16 GPIO41:2;                    // 19:18 Select input qualification type for GPIO41
    Uint16 GPIO42:2;                    // 21:20 Select input qualification type for GPIO42
    Uint16 GPIO43:2;                    // 23:22 Select input qualification type for GPIO43
    Uint16 GPIO44:2;                    // 25:24 Select input qualification type for GPIO44
    Uint16 GPIO45:2;                    // 27:26 Select input qualification type for GPIO45
    Uint16 GPIO46:2;                    // 29:28 Select input qualification type for GPIO46
    Uint16 GPIO47:2;                    // 31:30 Select input qualification type for GPIO47
};

union GPBQSEL1_REG {
    Uint32  all;
    struct  GPBQSEL1_BITS  bit;
};

struct GPBQSEL2_BITS {                  // bits description
    Uint16 GPIO48:2;                    // 1:0 Select input qualification type for GPIO48
    Uint16 GPIO49:2;                    // 3:2 Select input qualification type for GPIO49
    Uint16 GPIO50:2;                    // 5:4 Select input qualification type for GPIO50
    Uint16 GPIO51:2;                    // 7:6 Select input qualification type for GPIO51
    Uint16 GPIO52:2;                    // 9:8 Select input qualification type for GPIO52
    Uint16 GPIO53:2;                    // 11:10 Select input qualification type for GPIO53
    Uint16 GPIO54:2;                    // 13:12 Select input qualification type for GPIO54
    Uint16 GPIO55:2;                    // 15:14 Select input qualification type for GPIO55
    Uint16 GPIO56:2;                    // 17:16 Select input qualification type for GPIO56
    Uint16 GPIO57:2;                    // 19:18 Select input qualification type for GPIO57
    Uint16 GPIO58:2;                    // 21:20 Select input qualification type for GPIO58
    Uint16 GPIO59:2;                    // 23:22 Select input qualification type for GPIO59
    Uint16 GPIO60:2;                    // 25:24 Select input qualification type for GPIO60
    Uint16 GPIO61:2;                    // 27:26 Select input qualification type for GPIO61
    Uint16 GPIO62:2;                    // 29:28 Select input qualification type for GPIO62
    Uint16 GPIO63:2;                    // 31:30 Select input qualification type for GPIO63
};

union GPBQSEL2_REG {
    Uint32  all;
    struct  GPBQSEL2_BITS  bit;
};

struct GPBMUX1_BITS {                   // bits description
    Uint16 GPIO32:2;                    // 1:0 Defines pin-muxing selection for GPIO32
    Uint16 GPIO33:2;                    // 3:2 Defines pin-muxing selection for GPIO33
    Uint16 GPIO34:2;                    // 5:4 Defines pin-muxing selection for GPIO34
    Uint16 GPIO35:2;                    // 7:6 Defines pin-muxing selection for GPIO35
    Uint16 GPIO36:2;                    // 9:8 Defines pin-muxing selection for GPIO36
    Uint16 GPIO37:2;                    // 11:10 Defines pin-muxing selection for GPIO37
    Uint16 GPIO38:2;                    // 13:12 Defines pin-muxing selection for GPIO38
    Uint16 GPIO39:2;                    // 15:14 Defines pin-muxing selection for GPIO39
    Uint16 GPIO40:2;                    // 17:16 Defines pin-muxing selection for GPIO40
    Uint16 GPIO41:2;                    // 19:18 Defines pin-muxing selection for GPIO41
    Uint16 GPIO42:2;                    // 21:20 Defines pin-muxing selection for GPIO42
    Uint16 GPIO43:2;                    // 23:22 Defines pin-muxing selection for GPIO43
    Uint16 GPIO44:2;                    // 25:24 Defines pin-muxing selection for GPIO44
    Uint16 GPIO45:2;                    // 27:26 Defines pin-muxing selection for GPIO45
    Uint16 GPIO46:2;                    // 29:28 Defines pin-muxing selection for GPIO46
    Uint16 GPIO47:2;                    // 31:30 Defines pin-muxing selection for GPIO47
};

union GPBMUX1_REG {
    Uint32  all;
    struct  GPBMUX1_BITS  bit;
};

struct GPBMUX2_BITS {                   // bits description
    Uint16 GPIO48:2;                    // 1:0 Defines pin-muxing selection for GPIO48
    Uint16 GPIO49:2;                    // 3:2 Defines pin-muxing selection for GPIO49
    Uint16 GPIO50:2;                    // 5:4 Defines pin-muxing selection for GPIO50
    Uint16 GPIO51:2;                    // 7:6 Defines pin-muxing selection for GPIO51
    Uint16 GPIO52:2;                    // 9:8 Defines pin-muxing selection for GPIO52
    Uint16 GPIO53:2;                    // 11:10 Defines pin-muxing selection for GPIO53
    Uint16 GPIO54:2;                    // 13:12 Defines pin-muxing selection for GPIO54
    Uint16 GPIO55:2;                    // 15:14 Defines pin-muxing selection for GPIO55
    Uint16 GPIO56:2;                    // 17:16 Defines pin-muxing selection for GPIO56
    Uint16 GPIO57:2;                    // 19:18 Defines pin-muxing selection for GPIO57
    Uint16 GPIO58:2;                    // 21:20 Defines pin-muxing selection for GPIO58
    Uint16 GPIO59:2;                    // 23:22 Defines pin-muxing selection for GPIO59
    Uint16 GPIO60:2;                    // 25:24 Defines pin-muxing selection for GPIO60
    Uint16 GPIO61:2;                    // 27:26 Defines pin-muxing selection for GPIO61
    Uint16 GPIO62:2;                    // 29:28 Defines pin-muxing selection for GPIO62
    Uint16 GPIO63:2;                    // 31:30 Defines pin-muxing selection for GPIO63
};

union GPBMUX2_REG {
    Uint32  all;
    struct  GPBMUX2_BITS  bit;
};

struct GPBDIR_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO33:1;                    // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO34:1;                    // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO35:1;                    // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO36:1;                    // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO37:1;                    // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO38:1;                    // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO39:1;                    // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO40:1;                    // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO41:1;                    // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO42:1;                    // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO43:1;                    // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO44:1;                    // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO45:1;                    // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO46:1;                    // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO47:1;                    // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO48:1;                    // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO49:1;                    // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO50:1;                    // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO51:1;                    // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO52:1;                    // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO53:1;                    // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO54:1;                    // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO55:1;                    // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO56:1;                    // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO57:1;                    // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO58:1;                    // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO59:1;                    // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO60:1;                    // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO61:1;                    // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO62:1;                    // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO63:1;                    // 31 Defines direction for this pin in GPIO mode
};

union GPBDIR_REG {
    Uint32  all;
    struct  GPBDIR_BITS  bit;
};

struct GPBPUD_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Pull-Up Disable control for this pin
    Uint16 GPIO33:1;                    // 1 Pull-Up Disable control for this pin
    Uint16 GPIO34:1;                    // 2 Pull-Up Disable control for this pin
    Uint16 GPIO35:1;                    // 3 Pull-Up Disable control for this pin
    Uint16 GPIO36:1;                    // 4 Pull-Up Disable control for this pin
    Uint16 GPIO37:1;                    // 5 Pull-Up Disable control for this pin
    Uint16 GPIO38:1;                    // 6 Pull-Up Disable control for this pin
    Uint16 GPIO39:1;                    // 7 Pull-Up Disable control for this pin
    Uint16 GPIO40:1;                    // 8 Pull-Up Disable control for this pin
    Uint16 GPIO41:1;                    // 9 Pull-Up Disable control for this pin
    Uint16 GPIO42:1;                    // 10 Pull-Up Disable control for this pin
    Uint16 GPIO43:1;                    // 11 Pull-Up Disable control for this pin
    Uint16 GPIO44:1;                    // 12 Pull-Up Disable control for this pin
    Uint16 GPIO45:1;                    // 13 Pull-Up Disable control for this pin
    Uint16 GPIO46:1;                    // 14 Pull-Up Disable control for this pin
    Uint16 GPIO47:1;                    // 15 Pull-Up Disable control for this pin
    Uint16 GPIO48:1;                    // 16 Pull-Up Disable control for this pin
    Uint16 GPIO49:1;                    // 17 Pull-Up Disable control for this pin
    Uint16 GPIO50:1;                    // 18 Pull-Up Disable control for this pin
    Uint16 GPIO51:1;                    // 19 Pull-Up Disable control for this pin
    Uint16 GPIO52:1;                    // 20 Pull-Up Disable control for this pin
    Uint16 GPIO53:1;                    // 21 Pull-Up Disable control for this pin
    Uint16 GPIO54:1;                    // 22 Pull-Up Disable control for this pin
    Uint16 GPIO55:1;                    // 23 Pull-Up Disable control for this pin
    Uint16 GPIO56:1;                    // 24 Pull-Up Disable control for this pin
    Uint16 GPIO57:1;                    // 25 Pull-Up Disable control for this pin
    Uint16 GPIO58:1;                    // 26 Pull-Up Disable control for this pin
    Uint16 GPIO59:1;                    // 27 Pull-Up Disable control for this pin
    Uint16 GPIO60:1;                    // 28 Pull-Up Disable control for this pin
    Uint16 GPIO61:1;                    // 29 Pull-Up Disable control for this pin
    Uint16 GPIO62:1;                    // 30 Pull-Up Disable control for this pin
    Uint16 GPIO63:1;                    // 31 Pull-Up Disable control for this pin
};

union GPBPUD_REG {
    Uint32  all;
    struct  GPBPUD_BITS  bit;
};

struct GPBINV_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Input inversion control for this pin
    Uint16 GPIO33:1;                    // 1 Input inversion control for this pin
    Uint16 GPIO34:1;                    // 2 Input inversion control for this pin
    Uint16 GPIO35:1;                    // 3 Input inversion control for this pin
    Uint16 GPIO36:1;                    // 4 Input inversion control for this pin
    Uint16 GPIO37:1;                    // 5 Input inversion control for this pin
    Uint16 GPIO38:1;                    // 6 Input inversion control for this pin
    Uint16 GPIO39:1;                    // 7 Input inversion control for this pin
    Uint16 GPIO40:1;                    // 8 Input inversion control for this pin
    Uint16 GPIO41:1;                    // 9 Input inversion control for this pin
    Uint16 GPIO42:1;                    // 10 Input inversion control for this pin
    Uint16 GPIO43:1;                    // 11 Input inversion control for this pin
    Uint16 GPIO44:1;                    // 12 Input inversion control for this pin
    Uint16 GPIO45:1;                    // 13 Input inversion control for this pin
    Uint16 GPIO46:1;                    // 14 Input inversion control for this pin
    Uint16 GPIO47:1;                    // 15 Input inversion control for this pin
    Uint16 GPIO48:1;                    // 16 Input inversion control for this pin
    Uint16 GPIO49:1;                    // 17 Input inversion control for this pin
    Uint16 GPIO50:1;                    // 18 Input inversion control for this pin
    Uint16 GPIO51:1;                    // 19 Input inversion control for this pin
    Uint16 GPIO52:1;                    // 20 Input inversion control for this pin
    Uint16 GPIO53:1;                    // 21 Input inversion control for this pin
    Uint16 GPIO54:1;                    // 22 Input inversion control for this pin
    Uint16 GPIO55:1;                    // 23 Input inversion control for this pin
    Uint16 GPIO56:1;                    // 24 Input inversion control for this pin
    Uint16 GPIO57:1;                    // 25 Input inversion control for this pin
    Uint16 GPIO58:1;                    // 26 Input inversion control for this pin
    Uint16 GPIO59:1;                    // 27 Input inversion control for this pin
    Uint16 GPIO60:1;                    // 28 Input inversion control for this pin
    Uint16 GPIO61:1;                    // 29 Input inversion control for this pin
    Uint16 GPIO62:1;                    // 30 Input inversion control for this pin
    Uint16 GPIO63:1;                    // 31 Input inversion control for this pin
};

union GPBINV_REG {
    Uint32  all;
    struct  GPBINV_BITS  bit;
};

struct GPBODR_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO33:1;                    // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO34:1;                    // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO35:1;                    // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO36:1;                    // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO37:1;                    // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO38:1;                    // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO39:1;                    // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO40:1;                    // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO41:1;                    // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO42:1;                    // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO43:1;                    // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO44:1;                    // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO45:1;                    // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO46:1;                    // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO47:1;                    // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO48:1;                    // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO49:1;                    // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO50:1;                    // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO51:1;                    // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO52:1;                    // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO53:1;                    // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO54:1;                    // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO55:1;                    // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO56:1;                    // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO57:1;                    // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO58:1;                    // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO59:1;                    // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO60:1;                    // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO61:1;                    // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO62:1;                    // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO63:1;                    // 31 Outpout Open-Drain control for this pin
};

union GPBODR_REG {
    Uint32  all;
    struct  GPBODR_BITS  bit;
};

struct GPBAMSEL_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:1;                     // 4 Reserved
    Uint16 rsvd6:1;                     // 5 Reserved
    Uint16 rsvd7:1;                     // 6 Reserved
    Uint16 rsvd8:1;                     // 7 Reserved
    Uint16 rsvd9:1;                     // 8 Reserved
    Uint16 rsvd10:1;                    // 9 Reserved
    Uint16 GPIO42:1;                    // 10 Analog Mode select for this pin
    Uint16 GPIO43:1;                    // 11 Analog Mode select for this pin
    Uint16 rsvd11:1;                    // 12 Reserved
    Uint16 rsvd12:1;                    // 13 Reserved
    Uint16 rsvd13:1;                    // 14 Reserved
    Uint16 rsvd14:1;                    // 15 Reserved
    Uint16 rsvd15:1;                    // 16 Reserved
    Uint16 rsvd16:1;                    // 17 Reserved
    Uint16 rsvd17:1;                    // 18 Reserved
    Uint16 rsvd18:1;                    // 19 Reserved
    Uint16 rsvd19:1;                    // 20 Reserved
    Uint16 rsvd20:1;                    // 21 Reserved
    Uint16 rsvd21:1;                    // 22 Reserved
    Uint16 rsvd22:1;                    // 23 Reserved
    Uint16 rsvd23:1;                    // 24 Reserved
    Uint16 rsvd24:1;                    // 25 Reserved
    Uint16 rsvd25:1;                    // 26 Reserved
    Uint16 rsvd26:1;                    // 27 Reserved
    Uint16 rsvd27:1;                    // 28 Reserved
    Uint16 rsvd28:1;                    // 29 Reserved
    Uint16 rsvd29:1;                    // 30 Reserved
    Uint16 rsvd30:1;                    // 31 Reserved
};

union GPBAMSEL_REG {
    Uint32  all;
    struct  GPBAMSEL_BITS  bit;
};

struct GPBGMUX1_BITS {                  // bits description
    Uint16 GPIO32:2;                    // 1:0 Defines pin-muxing selection for GPIO32
    Uint16 GPIO33:2;                    // 3:2 Defines pin-muxing selection for GPIO33
    Uint16 GPIO34:2;                    // 5:4 Defines pin-muxing selection for GPIO34
    Uint16 GPIO35:2;                    // 7:6 Defines pin-muxing selection for GPIO35
    Uint16 GPIO36:2;                    // 9:8 Defines pin-muxing selection for GPIO36
    Uint16 GPIO37:2;                    // 11:10 Defines pin-muxing selection for GPIO37
    Uint16 GPIO38:2;                    // 13:12 Defines pin-muxing selection for GPIO38
    Uint16 GPIO39:2;                    // 15:14 Defines pin-muxing selection for GPIO39
    Uint16 GPIO40:2;                    // 17:16 Defines pin-muxing selection for GPIO40
    Uint16 GPIO41:2;                    // 19:18 Defines pin-muxing selection for GPIO41
    Uint16 GPIO42:2;                    // 21:20 Defines pin-muxing selection for GPIO42
    Uint16 GPIO43:2;                    // 23:22 Defines pin-muxing selection for GPIO43
    Uint16 GPIO44:2;                    // 25:24 Defines pin-muxing selection for GPIO44
    Uint16 GPIO45:2;                    // 27:26 Defines pin-muxing selection for GPIO45
    Uint16 GPIO46:2;                    // 29:28 Defines pin-muxing selection for GPIO46
    Uint16 GPIO47:2;                    // 31:30 Defines pin-muxing selection for GPIO47
};

union GPBGMUX1_REG {
    Uint32  all;
    struct  GPBGMUX1_BITS  bit;
};

struct GPBGMUX2_BITS {                  // bits description
    Uint16 GPIO48:2;                    // 1:0 Defines pin-muxing selection for GPIO48
    Uint16 GPIO49:2;                    // 3:2 Defines pin-muxing selection for GPIO49
    Uint16 GPIO50:2;                    // 5:4 Defines pin-muxing selection for GPIO50
    Uint16 GPIO51:2;                    // 7:6 Defines pin-muxing selection for GPIO51
    Uint16 GPIO52:2;                    // 9:8 Defines pin-muxing selection for GPIO52
    Uint16 GPIO53:2;                    // 11:10 Defines pin-muxing selection for GPIO53
    Uint16 GPIO54:2;                    // 13:12 Defines pin-muxing selection for GPIO54
    Uint16 GPIO55:2;                    // 15:14 Defines pin-muxing selection for GPIO55
    Uint16 GPIO56:2;                    // 17:16 Defines pin-muxing selection for GPIO56
    Uint16 GPIO57:2;                    // 19:18 Defines pin-muxing selection for GPIO57
    Uint16 GPIO58:2;                    // 21:20 Defines pin-muxing selection for GPIO58
    Uint16 GPIO59:2;                    // 23:22 Defines pin-muxing selection for GPIO59
    Uint16 GPIO60:2;                    // 25:24 Defines pin-muxing selection for GPIO60
    Uint16 GPIO61:2;                    // 27:26 Defines pin-muxing selection for GPIO61
    Uint16 GPIO62:2;                    // 29:28 Defines pin-muxing selection for GPIO62
    Uint16 GPIO63:2;                    // 31:30 Defines pin-muxing selection for GPIO63
};

union GPBGMUX2_REG {
    Uint32  all;
    struct  GPBGMUX2_BITS  bit;
};

struct GPBCSEL1_BITS {                  // bits description
    Uint16 GPIO32:4;                    // 3:0 GPIO32 Master CPU Select
    Uint16 GPIO33:4;                    // 7:4 GPIO33 Master CPU Select
    Uint16 GPIO34:4;                    // 11:8 GPIO34 Master CPU Select
    Uint16 GPIO35:4;                    // 15:12 GPIO35 Master CPU Select
    Uint16 GPIO36:4;                    // 19:16 GPIO36 Master CPU Select
    Uint16 GPIO37:4;                    // 23:20 GPIO37 Master CPU Select
    Uint16 GPIO38:4;                    // 27:24 GPIO38 Master CPU Select
    Uint16 GPIO39:4;                    // 31:28 GPIO39 Master CPU Select
};

union GPBCSEL1_REG {
    Uint32  all;
    struct  GPBCSEL1_BITS  bit;
};

struct GPBCSEL2_BITS {                  // bits description
    Uint16 GPIO40:4;                    // 3:0 GPIO40 Master CPU Select
    Uint16 GPIO41:4;                    // 7:4 GPIO41 Master CPU Select
    Uint16 GPIO42:4;                    // 11:8 GPIO42 Master CPU Select
    Uint16 GPIO43:4;                    // 15:12 GPIO43 Master CPU Select
    Uint16 GPIO44:4;                    // 19:16 GPIO44 Master CPU Select
    Uint16 GPIO45:4;                    // 23:20 GPIO45 Master CPU Select
    Uint16 GPIO46:4;                    // 27:24 GPIO46 Master CPU Select
    Uint16 GPIO47:4;                    // 31:28 GPIO47 Master CPU Select
};

union GPBCSEL2_REG {
    Uint32  all;
    struct  GPBCSEL2_BITS  bit;
};

struct GPBCSEL3_BITS {                  // bits description
    Uint16 GPIO48:4;                    // 3:0 GPIO48 Master CPU Select
    Uint16 GPIO49:4;                    // 7:4 GPIO49 Master CPU Select
    Uint16 GPIO50:4;                    // 11:8 GPIO50 Master CPU Select
    Uint16 GPIO51:4;                    // 15:12 GPIO51 Master CPU Select
    Uint16 GPIO52:4;                    // 19:16 GPIO52 Master CPU Select
    Uint16 GPIO53:4;                    // 23:20 GPIO53 Master CPU Select
    Uint16 GPIO54:4;                    // 27:24 GPIO54 Master CPU Select
    Uint16 GPIO55:4;                    // 31:28 GPIO55 Master CPU Select
};

union GPBCSEL3_REG {
    Uint32  all;
    struct  GPBCSEL3_BITS  bit;
};

struct GPBCSEL4_BITS {                  // bits description
    Uint16 GPIO56:4;                    // 3:0 GPIO56 Master CPU Select
    Uint16 GPIO57:4;                    // 7:4 GPIO57 Master CPU Select
    Uint16 GPIO58:4;                    // 11:8 GPIO58 Master CPU Select
    Uint16 GPIO59:4;                    // 15:12 GPIO59 Master CPU Select
    Uint16 GPIO60:4;                    // 19:16 GPIO60 Master CPU Select
    Uint16 GPIO61:4;                    // 23:20 GPIO61 Master CPU Select
    Uint16 GPIO62:4;                    // 27:24 GPIO62 Master CPU Select
    Uint16 GPIO63:4;                    // 31:28 GPIO63 Master CPU Select
};

union GPBCSEL4_REG {
    Uint32  all;
    struct  GPBCSEL4_BITS  bit;
};

struct GPBLOCK_BITS {                   // bits description
    Uint16 GPIO32:1;                    // 0 Configuration Lock bit for this pin
    Uint16 GPIO33:1;                    // 1 Configuration Lock bit for this pin
    Uint16 GPIO34:1;                    // 2 Configuration Lock bit for this pin
    Uint16 GPIO35:1;                    // 3 Configuration Lock bit for this pin
    Uint16 GPIO36:1;                    // 4 Configuration Lock bit for this pin
    Uint16 GPIO37:1;                    // 5 Configuration Lock bit for this pin
    Uint16 GPIO38:1;                    // 6 Configuration Lock bit for this pin
    Uint16 GPIO39:1;                    // 7 Configuration Lock bit for this pin
    Uint16 GPIO40:1;                    // 8 Configuration Lock bit for this pin
    Uint16 GPIO41:1;                    // 9 Configuration Lock bit for this pin
    Uint16 GPIO42:1;                    // 10 Configuration Lock bit for this pin
    Uint16 GPIO43:1;                    // 11 Configuration Lock bit for this pin
    Uint16 GPIO44:1;                    // 12 Configuration Lock bit for this pin
    Uint16 GPIO45:1;                    // 13 Configuration Lock bit for this pin
    Uint16 GPIO46:1;                    // 14 Configuration Lock bit for this pin
    Uint16 GPIO47:1;                    // 15 Configuration Lock bit for this pin
    Uint16 GPIO48:1;                    // 16 Configuration Lock bit for this pin
    Uint16 GPIO49:1;                    // 17 Configuration Lock bit for this pin
    Uint16 GPIO50:1;                    // 18 Configuration Lock bit for this pin
    Uint16 GPIO51:1;                    // 19 Configuration Lock bit for this pin
    Uint16 GPIO52:1;                    // 20 Configuration Lock bit for this pin
    Uint16 GPIO53:1;                    // 21 Configuration Lock bit for this pin
    Uint16 GPIO54:1;                    // 22 Configuration Lock bit for this pin
    Uint16 GPIO55:1;                    // 23 Configuration Lock bit for this pin
    Uint16 GPIO56:1;                    // 24 Configuration Lock bit for this pin
    Uint16 GPIO57:1;                    // 25 Configuration Lock bit for this pin
    Uint16 GPIO58:1;                    // 26 Configuration Lock bit for this pin
    Uint16 GPIO59:1;                    // 27 Configuration Lock bit for this pin
    Uint16 GPIO60:1;                    // 28 Configuration Lock bit for this pin
    Uint16 GPIO61:1;                    // 29 Configuration Lock bit for this pin
    Uint16 GPIO62:1;                    // 30 Configuration Lock bit for this pin
    Uint16 GPIO63:1;                    // 31 Configuration Lock bit for this pin
};

union GPBLOCK_REG {
    Uint32  all;
    struct  GPBLOCK_BITS  bit;
};

struct GPBCR_BITS {                     // bits description
    Uint16 GPIO32:1;                    // 0 Configuration lock commit bit for this pin
    Uint16 GPIO33:1;                    // 1 Configuration lock commit bit for this pin
    Uint16 GPIO34:1;                    // 2 Configuration lock commit bit for this pin
    Uint16 GPIO35:1;                    // 3 Configuration lock commit bit for this pin
    Uint16 GPIO36:1;                    // 4 Configuration lock commit bit for this pin
    Uint16 GPIO37:1;                    // 5 Configuration lock commit bit for this pin
    Uint16 GPIO38:1;                    // 6 Configuration lock commit bit for this pin
    Uint16 GPIO39:1;                    // 7 Configuration lock commit bit for this pin
    Uint16 GPIO40:1;                    // 8 Configuration lock commit bit for this pin
    Uint16 GPIO41:1;                    // 9 Configuration lock commit bit for this pin
    Uint16 GPIO42:1;                    // 10 Configuration lock commit bit for this pin
    Uint16 GPIO43:1;                    // 11 Configuration lock commit bit for this pin
    Uint16 GPIO44:1;                    // 12 Configuration lock commit bit for this pin
    Uint16 GPIO45:1;                    // 13 Configuration lock commit bit for this pin
    Uint16 GPIO46:1;                    // 14 Configuration lock commit bit for this pin
    Uint16 GPIO47:1;                    // 15 Configuration lock commit bit for this pin
    Uint16 GPIO48:1;                    // 16 Configuration lock commit bit for this pin
    Uint16 GPIO49:1;                    // 17 Configuration lock commit bit for this pin
    Uint16 GPIO50:1;                    // 18 Configuration lock commit bit for this pin
    Uint16 GPIO51:1;                    // 19 Configuration lock commit bit for this pin
    Uint16 GPIO52:1;                    // 20 Configuration lock commit bit for this pin
    Uint16 GPIO53:1;                    // 21 Configuration lock commit bit for this pin
    Uint16 GPIO54:1;                    // 22 Configuration lock commit bit for this pin
    Uint16 GPIO55:1;                    // 23 Configuration lock commit bit for this pin
    Uint16 GPIO56:1;                    // 24 Configuration lock commit bit for this pin
    Uint16 GPIO57:1;                    // 25 Configuration lock commit bit for this pin
    Uint16 GPIO58:1;                    // 26 Configuration lock commit bit for this pin
    Uint16 GPIO59:1;                    // 27 Configuration lock commit bit for this pin
    Uint16 GPIO60:1;                    // 28 Configuration lock commit bit for this pin
    Uint16 GPIO61:1;                    // 29 Configuration lock commit bit for this pin
    Uint16 GPIO62:1;                    // 30 Configuration lock commit bit for this pin
    Uint16 GPIO63:1;                    // 31 Configuration lock commit bit for this pin
};

union GPBCR_REG {
    Uint32  all;
    struct  GPBCR_BITS  bit;
};

struct GPCCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO64 to GPIO71
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO72 to GPIO79
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO80 to GPIO87
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO88 to GPIO95
};

union GPCCTRL_REG {
    Uint32  all;
    struct  GPCCTRL_BITS  bit;
};

struct GPCQSEL1_BITS {                  // bits description
    Uint16 GPIO64:2;                    // 1:0 Select input qualification type for GPIO64
    Uint16 GPIO65:2;                    // 3:2 Select input qualification type for GPIO65
    Uint16 GPIO66:2;                    // 5:4 Select input qualification type for GPIO66
    Uint16 GPIO67:2;                    // 7:6 Select input qualification type for GPIO67
    Uint16 GPIO68:2;                    // 9:8 Select input qualification type for GPIO68
    Uint16 GPIO69:2;                    // 11:10 Select input qualification type for GPIO69
    Uint16 GPIO70:2;                    // 13:12 Select input qualification type for GPIO70
    Uint16 GPIO71:2;                    // 15:14 Select input qualification type for GPIO71
    Uint16 GPIO72:2;                    // 17:16 Select input qualification type for GPIO72
    Uint16 GPIO73:2;                    // 19:18 Select input qualification type for GPIO73
    Uint16 GPIO74:2;                    // 21:20 Select input qualification type for GPIO74
    Uint16 GPIO75:2;                    // 23:22 Select input qualification type for GPIO75
    Uint16 GPIO76:2;                    // 25:24 Select input qualification type for GPIO76
    Uint16 GPIO77:2;                    // 27:26 Select input qualification type for GPIO77
    Uint16 GPIO78:2;                    // 29:28 Select input qualification type for GPIO78
    Uint16 GPIO79:2;                    // 31:30 Select input qualification type for GPIO79
};

union GPCQSEL1_REG {
    Uint32  all;
    struct  GPCQSEL1_BITS  bit;
};

struct GPCQSEL2_BITS {                  // bits description
    Uint16 GPIO80:2;                    // 1:0 Select input qualification type for GPIO80
    Uint16 GPIO81:2;                    // 3:2 Select input qualification type for GPIO81
    Uint16 GPIO82:2;                    // 5:4 Select input qualification type for GPIO82
    Uint16 GPIO83:2;                    // 7:6 Select input qualification type for GPIO83
    Uint16 GPIO84:2;                    // 9:8 Select input qualification type for GPIO84
    Uint16 GPIO85:2;                    // 11:10 Select input qualification type for GPIO85
    Uint16 GPIO86:2;                    // 13:12 Select input qualification type for GPIO86
    Uint16 GPIO87:2;                    // 15:14 Select input qualification type for GPIO87
    Uint16 GPIO88:2;                    // 17:16 Select input qualification type for GPIO88
    Uint16 GPIO89:2;                    // 19:18 Select input qualification type for GPIO89
    Uint16 GPIO90:2;                    // 21:20 Select input qualification type for GPIO90
    Uint16 GPIO91:2;                    // 23:22 Select input qualification type for GPIO91
    Uint16 GPIO92:2;                    // 25:24 Select input qualification type for GPIO92
    Uint16 GPIO93:2;                    // 27:26 Select input qualification type for GPIO93
    Uint16 GPIO94:2;                    // 29:28 Select input qualification type for GPIO94
    Uint16 GPIO95:2;                    // 31:30 Select input qualification type for GPIO95
};

union GPCQSEL2_REG {
    Uint32  all;
    struct  GPCQSEL2_BITS  bit;
};

struct GPCMUX1_BITS {                   // bits description
    Uint16 GPIO64:2;                    // 1:0 Defines pin-muxing selection for GPIO64
    Uint16 GPIO65:2;                    // 3:2 Defines pin-muxing selection for GPIO65
    Uint16 GPIO66:2;                    // 5:4 Defines pin-muxing selection for GPIO66
    Uint16 GPIO67:2;                    // 7:6 Defines pin-muxing selection for GPIO67
    Uint16 GPIO68:2;                    // 9:8 Defines pin-muxing selection for GPIO68
    Uint16 GPIO69:2;                    // 11:10 Defines pin-muxing selection for GPIO69
    Uint16 GPIO70:2;                    // 13:12 Defines pin-muxing selection for GPIO70
    Uint16 GPIO71:2;                    // 15:14 Defines pin-muxing selection for GPIO71
    Uint16 GPIO72:2;                    // 17:16 Defines pin-muxing selection for GPIO72
    Uint16 GPIO73:2;                    // 19:18 Defines pin-muxing selection for GPIO73
    Uint16 GPIO74:2;                    // 21:20 Defines pin-muxing selection for GPIO74
    Uint16 GPIO75:2;                    // 23:22 Defines pin-muxing selection for GPIO75
    Uint16 GPIO76:2;                    // 25:24 Defines pin-muxing selection for GPIO76
    Uint16 GPIO77:2;                    // 27:26 Defines pin-muxing selection for GPIO77
    Uint16 GPIO78:2;                    // 29:28 Defines pin-muxing selection for GPIO78
    Uint16 GPIO79:2;                    // 31:30 Defines pin-muxing selection for GPIO79
};

union GPCMUX1_REG {
    Uint32  all;
    struct  GPCMUX1_BITS  bit;
};

struct GPCMUX2_BITS {                   // bits description
    Uint16 GPIO80:2;                    // 1:0 Defines pin-muxing selection for GPIO80
    Uint16 GPIO81:2;                    // 3:2 Defines pin-muxing selection for GPIO81
    Uint16 GPIO82:2;                    // 5:4 Defines pin-muxing selection for GPIO82
    Uint16 GPIO83:2;                    // 7:6 Defines pin-muxing selection for GPIO83
    Uint16 GPIO84:2;                    // 9:8 Defines pin-muxing selection for GPIO84
    Uint16 GPIO85:2;                    // 11:10 Defines pin-muxing selection for GPIO85
    Uint16 GPIO86:2;                    // 13:12 Defines pin-muxing selection for GPIO86
    Uint16 GPIO87:2;                    // 15:14 Defines pin-muxing selection for GPIO87
    Uint16 GPIO88:2;                    // 17:16 Defines pin-muxing selection for GPIO88
    Uint16 GPIO89:2;                    // 19:18 Defines pin-muxing selection for GPIO89
    Uint16 GPIO90:2;                    // 21:20 Defines pin-muxing selection for GPIO90
    Uint16 GPIO91:2;                    // 23:22 Defines pin-muxing selection for GPIO91
    Uint16 GPIO92:2;                    // 25:24 Defines pin-muxing selection for GPIO92
    Uint16 GPIO93:2;                    // 27:26 Defines pin-muxing selection for GPIO93
    Uint16 GPIO94:2;                    // 29:28 Defines pin-muxing selection for GPIO94
    Uint16 GPIO95:2;                    // 31:30 Defines pin-muxing selection for GPIO95
};

union GPCMUX2_REG {
    Uint32  all;
    struct  GPCMUX2_BITS  bit;
};

struct GPCDIR_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO65:1;                    // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO66:1;                    // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO67:1;                    // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO68:1;                    // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO69:1;                    // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO70:1;                    // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO71:1;                    // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO72:1;                    // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO73:1;                    // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO74:1;                    // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO75:1;                    // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO76:1;                    // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO77:1;                    // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO78:1;                    // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO79:1;                    // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO80:1;                    // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO81:1;                    // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO82:1;                    // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO83:1;                    // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO84:1;                    // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO85:1;                    // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO86:1;                    // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO87:1;                    // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO88:1;                    // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO89:1;                    // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO90:1;                    // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO91:1;                    // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO92:1;                    // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO93:1;                    // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO94:1;                    // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO95:1;                    // 31 Defines direction for this pin in GPIO mode
};

union GPCDIR_REG {
    Uint32  all;
    struct  GPCDIR_BITS  bit;
};

struct GPCPUD_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Pull-Up Disable control for this pin
    Uint16 GPIO65:1;                    // 1 Pull-Up Disable control for this pin
    Uint16 GPIO66:1;                    // 2 Pull-Up Disable control for this pin
    Uint16 GPIO67:1;                    // 3 Pull-Up Disable control for this pin
    Uint16 GPIO68:1;                    // 4 Pull-Up Disable control for this pin
    Uint16 GPIO69:1;                    // 5 Pull-Up Disable control for this pin
    Uint16 GPIO70:1;                    // 6 Pull-Up Disable control for this pin
    Uint16 GPIO71:1;                    // 7 Pull-Up Disable control for this pin
    Uint16 GPIO72:1;                    // 8 Pull-Up Disable control for this pin
    Uint16 GPIO73:1;                    // 9 Pull-Up Disable control for this pin
    Uint16 GPIO74:1;                    // 10 Pull-Up Disable control for this pin
    Uint16 GPIO75:1;                    // 11 Pull-Up Disable control for this pin
    Uint16 GPIO76:1;                    // 12 Pull-Up Disable control for this pin
    Uint16 GPIO77:1;                    // 13 Pull-Up Disable control for this pin
    Uint16 GPIO78:1;                    // 14 Pull-Up Disable control for this pin
    Uint16 GPIO79:1;                    // 15 Pull-Up Disable control for this pin
    Uint16 GPIO80:1;                    // 16 Pull-Up Disable control for this pin
    Uint16 GPIO81:1;                    // 17 Pull-Up Disable control for this pin
    Uint16 GPIO82:1;                    // 18 Pull-Up Disable control for this pin
    Uint16 GPIO83:1;                    // 19 Pull-Up Disable control for this pin
    Uint16 GPIO84:1;                    // 20 Pull-Up Disable control for this pin
    Uint16 GPIO85:1;                    // 21 Pull-Up Disable control for this pin
    Uint16 GPIO86:1;                    // 22 Pull-Up Disable control for this pin
    Uint16 GPIO87:1;                    // 23 Pull-Up Disable control for this pin
    Uint16 GPIO88:1;                    // 24 Pull-Up Disable control for this pin
    Uint16 GPIO89:1;                    // 25 Pull-Up Disable control for this pin
    Uint16 GPIO90:1;                    // 26 Pull-Up Disable control for this pin
    Uint16 GPIO91:1;                    // 27 Pull-Up Disable control for this pin
    Uint16 GPIO92:1;                    // 28 Pull-Up Disable control for this pin
    Uint16 GPIO93:1;                    // 29 Pull-Up Disable control for this pin
    Uint16 GPIO94:1;                    // 30 Pull-Up Disable control for this pin
    Uint16 GPIO95:1;                    // 31 Pull-Up Disable control for this pin
};

union GPCPUD_REG {
    Uint32  all;
    struct  GPCPUD_BITS  bit;
};

struct GPCINV_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Input inversion control for this pin
    Uint16 GPIO65:1;                    // 1 Input inversion control for this pin
    Uint16 GPIO66:1;                    // 2 Input inversion control for this pin
    Uint16 GPIO67:1;                    // 3 Input inversion control for this pin
    Uint16 GPIO68:1;                    // 4 Input inversion control for this pin
    Uint16 GPIO69:1;                    // 5 Input inversion control for this pin
    Uint16 GPIO70:1;                    // 6 Input inversion control for this pin
    Uint16 GPIO71:1;                    // 7 Input inversion control for this pin
    Uint16 GPIO72:1;                    // 8 Input inversion control for this pin
    Uint16 GPIO73:1;                    // 9 Input inversion control for this pin
    Uint16 GPIO74:1;                    // 10 Input inversion control for this pin
    Uint16 GPIO75:1;                    // 11 Input inversion control for this pin
    Uint16 GPIO76:1;                    // 12 Input inversion control for this pin
    Uint16 GPIO77:1;                    // 13 Input inversion control for this pin
    Uint16 GPIO78:1;                    // 14 Input inversion control for this pin
    Uint16 GPIO79:1;                    // 15 Input inversion control for this pin
    Uint16 GPIO80:1;                    // 16 Input inversion control for this pin
    Uint16 GPIO81:1;                    // 17 Input inversion control for this pin
    Uint16 GPIO82:1;                    // 18 Input inversion control for this pin
    Uint16 GPIO83:1;                    // 19 Input inversion control for this pin
    Uint16 GPIO84:1;                    // 20 Input inversion control for this pin
    Uint16 GPIO85:1;                    // 21 Input inversion control for this pin
    Uint16 GPIO86:1;                    // 22 Input inversion control for this pin
    Uint16 GPIO87:1;                    // 23 Input inversion control for this pin
    Uint16 GPIO88:1;                    // 24 Input inversion control for this pin
    Uint16 GPIO89:1;                    // 25 Input inversion control for this pin
    Uint16 GPIO90:1;                    // 26 Input inversion control for this pin
    Uint16 GPIO91:1;                    // 27 Input inversion control for this pin
    Uint16 GPIO92:1;                    // 28 Input inversion control for this pin
    Uint16 GPIO93:1;                    // 29 Input inversion control for this pin
    Uint16 GPIO94:1;                    // 30 Input inversion control for this pin
    Uint16 GPIO95:1;                    // 31 Input inversion control for this pin
};

union GPCINV_REG {
    Uint32  all;
    struct  GPCINV_BITS  bit;
};

struct GPCODR_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO65:1;                    // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO66:1;                    // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO67:1;                    // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO68:1;                    // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO69:1;                    // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO70:1;                    // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO71:1;                    // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO72:1;                    // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO73:1;                    // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO74:1;                    // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO75:1;                    // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO76:1;                    // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO77:1;                    // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO78:1;                    // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO79:1;                    // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO80:1;                    // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO81:1;                    // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO82:1;                    // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO83:1;                    // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO84:1;                    // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO85:1;                    // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO86:1;                    // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO87:1;                    // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO88:1;                    // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO89:1;                    // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO90:1;                    // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO91:1;                    // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO92:1;                    // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO93:1;                    // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO94:1;                    // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO95:1;                    // 31 Outpout Open-Drain control for this pin
};

union GPCODR_REG {
    Uint32  all;
    struct  GPCODR_BITS  bit;
};

struct GPCGMUX1_BITS {                  // bits description
    Uint16 GPIO64:2;                    // 1:0 Defines pin-muxing selection for GPIO64
    Uint16 GPIO65:2;                    // 3:2 Defines pin-muxing selection for GPIO65
    Uint16 GPIO66:2;                    // 5:4 Defines pin-muxing selection for GPIO66
    Uint16 GPIO67:2;                    // 7:6 Defines pin-muxing selection for GPIO67
    Uint16 GPIO68:2;                    // 9:8 Defines pin-muxing selection for GPIO68
    Uint16 GPIO69:2;                    // 11:10 Defines pin-muxing selection for GPIO69
    Uint16 GPIO70:2;                    // 13:12 Defines pin-muxing selection for GPIO70
    Uint16 GPIO71:2;                    // 15:14 Defines pin-muxing selection for GPIO71
    Uint16 GPIO72:2;                    // 17:16 Defines pin-muxing selection for GPIO72
    Uint16 GPIO73:2;                    // 19:18 Defines pin-muxing selection for GPIO73
    Uint16 GPIO74:2;                    // 21:20 Defines pin-muxing selection for GPIO74
    Uint16 GPIO75:2;                    // 23:22 Defines pin-muxing selection for GPIO75
    Uint16 GPIO76:2;                    // 25:24 Defines pin-muxing selection for GPIO76
    Uint16 GPIO77:2;                    // 27:26 Defines pin-muxing selection for GPIO77
    Uint16 GPIO78:2;                    // 29:28 Defines pin-muxing selection for GPIO78
    Uint16 GPIO79:2;                    // 31:30 Defines pin-muxing selection for GPIO79
};

union GPCGMUX1_REG {
    Uint32  all;
    struct  GPCGMUX1_BITS  bit;
};

struct GPCGMUX2_BITS {                  // bits description
    Uint16 GPIO80:2;                    // 1:0 Defines pin-muxing selection for GPIO80
    Uint16 GPIO81:2;                    // 3:2 Defines pin-muxing selection for GPIO81
    Uint16 GPIO82:2;                    // 5:4 Defines pin-muxing selection for GPIO82
    Uint16 GPIO83:2;                    // 7:6 Defines pin-muxing selection for GPIO83
    Uint16 GPIO84:2;                    // 9:8 Defines pin-muxing selection for GPIO84
    Uint16 GPIO85:2;                    // 11:10 Defines pin-muxing selection for GPIO85
    Uint16 GPIO86:2;                    // 13:12 Defines pin-muxing selection for GPIO86
    Uint16 GPIO87:2;                    // 15:14 Defines pin-muxing selection for GPIO87
    Uint16 GPIO88:2;                    // 17:16 Defines pin-muxing selection for GPIO88
    Uint16 GPIO89:2;                    // 19:18 Defines pin-muxing selection for GPIO89
    Uint16 GPIO90:2;                    // 21:20 Defines pin-muxing selection for GPIO90
    Uint16 GPIO91:2;                    // 23:22 Defines pin-muxing selection for GPIO91
    Uint16 GPIO92:2;                    // 25:24 Defines pin-muxing selection for GPIO92
    Uint16 GPIO93:2;                    // 27:26 Defines pin-muxing selection for GPIO93
    Uint16 GPIO94:2;                    // 29:28 Defines pin-muxing selection for GPIO94
    Uint16 GPIO95:2;                    // 31:30 Defines pin-muxing selection for GPIO95
};

union GPCGMUX2_REG {
    Uint32  all;
    struct  GPCGMUX2_BITS  bit;
};

struct GPCCSEL1_BITS {                  // bits description
    Uint16 GPIO64:4;                    // 3:0 GPIO64 Master CPU Select
    Uint16 GPIO65:4;                    // 7:4 GPIO65 Master CPU Select
    Uint16 GPIO66:4;                    // 11:8 GPIO66 Master CPU Select
    Uint16 GPIO67:4;                    // 15:12 GPIO67 Master CPU Select
    Uint16 GPIO68:4;                    // 19:16 GPIO68 Master CPU Select
    Uint16 GPIO69:4;                    // 23:20 GPIO69 Master CPU Select
    Uint16 GPIO70:4;                    // 27:24 GPIO70 Master CPU Select
    Uint16 GPIO71:4;                    // 31:28 GPIO71 Master CPU Select
};

union GPCCSEL1_REG {
    Uint32  all;
    struct  GPCCSEL1_BITS  bit;
};

struct GPCCSEL2_BITS {                  // bits description
    Uint16 GPIO72:4;                    // 3:0 GPIO72 Master CPU Select
    Uint16 GPIO73:4;                    // 7:4 GPIO73 Master CPU Select
    Uint16 GPIO74:4;                    // 11:8 GPIO74 Master CPU Select
    Uint16 GPIO75:4;                    // 15:12 GPIO75 Master CPU Select
    Uint16 GPIO76:4;                    // 19:16 GPIO76 Master CPU Select
    Uint16 GPIO77:4;                    // 23:20 GPIO77 Master CPU Select
    Uint16 GPIO78:4;                    // 27:24 GPIO78 Master CPU Select
    Uint16 GPIO79:4;                    // 31:28 GPIO79 Master CPU Select
};

union GPCCSEL2_REG {
    Uint32  all;
    struct  GPCCSEL2_BITS  bit;
};

struct GPCCSEL3_BITS {                  // bits description
    Uint16 GPIO80:4;                    // 3:0 GPIO80 Master CPU Select
    Uint16 GPIO81:4;                    // 7:4 GPIO81 Master CPU Select
    Uint16 GPIO82:4;                    // 11:8 GPIO82 Master CPU Select
    Uint16 GPIO83:4;                    // 15:12 GPIO83 Master CPU Select
    Uint16 GPIO84:4;                    // 19:16 GPIO84 Master CPU Select
    Uint16 GPIO85:4;                    // 23:20 GPIO85 Master CPU Select
    Uint16 GPIO86:4;                    // 27:24 GPIO86 Master CPU Select
    Uint16 GPIO87:4;                    // 31:28 GPIO87 Master CPU Select
};

union GPCCSEL3_REG {
    Uint32  all;
    struct  GPCCSEL3_BITS  bit;
};

struct GPCCSEL4_BITS {                  // bits description
    Uint16 GPIO88:4;                    // 3:0 GPIO88 Master CPU Select
    Uint16 GPIO89:4;                    // 7:4 GPIO89 Master CPU Select
    Uint16 GPIO90:4;                    // 11:8 GPIO90 Master CPU Select
    Uint16 GPIO91:4;                    // 15:12 GPIO91 Master CPU Select
    Uint16 GPIO92:4;                    // 19:16 GPIO92 Master CPU Select
    Uint16 GPIO93:4;                    // 23:20 GPIO93 Master CPU Select
    Uint16 GPIO94:4;                    // 27:24 GPIO94 Master CPU Select
    Uint16 GPIO95:4;                    // 31:28 GPIO95 Master CPU Select
};

union GPCCSEL4_REG {
    Uint32  all;
    struct  GPCCSEL4_BITS  bit;
};

struct GPCLOCK_BITS {                   // bits description
    Uint16 GPIO64:1;                    // 0 Configuration Lock bit for this pin
    Uint16 GPIO65:1;                    // 1 Configuration Lock bit for this pin
    Uint16 GPIO66:1;                    // 2 Configuration Lock bit for this pin
    Uint16 GPIO67:1;                    // 3 Configuration Lock bit for this pin
    Uint16 GPIO68:1;                    // 4 Configuration Lock bit for this pin
    Uint16 GPIO69:1;                    // 5 Configuration Lock bit for this pin
    Uint16 GPIO70:1;                    // 6 Configuration Lock bit for this pin
    Uint16 GPIO71:1;                    // 7 Configuration Lock bit for this pin
    Uint16 GPIO72:1;                    // 8 Configuration Lock bit for this pin
    Uint16 GPIO73:1;                    // 9 Configuration Lock bit for this pin
    Uint16 GPIO74:1;                    // 10 Configuration Lock bit for this pin
    Uint16 GPIO75:1;                    // 11 Configuration Lock bit for this pin
    Uint16 GPIO76:1;                    // 12 Configuration Lock bit for this pin
    Uint16 GPIO77:1;                    // 13 Configuration Lock bit for this pin
    Uint16 GPIO78:1;                    // 14 Configuration Lock bit for this pin
    Uint16 GPIO79:1;                    // 15 Configuration Lock bit for this pin
    Uint16 GPIO80:1;                    // 16 Configuration Lock bit for this pin
    Uint16 GPIO81:1;                    // 17 Configuration Lock bit for this pin
    Uint16 GPIO82:1;                    // 18 Configuration Lock bit for this pin
    Uint16 GPIO83:1;                    // 19 Configuration Lock bit for this pin
    Uint16 GPIO84:1;                    // 20 Configuration Lock bit for this pin
    Uint16 GPIO85:1;                    // 21 Configuration Lock bit for this pin
    Uint16 GPIO86:1;                    // 22 Configuration Lock bit for this pin
    Uint16 GPIO87:1;                    // 23 Configuration Lock bit for this pin
    Uint16 GPIO88:1;                    // 24 Configuration Lock bit for this pin
    Uint16 GPIO89:1;                    // 25 Configuration Lock bit for this pin
    Uint16 GPIO90:1;                    // 26 Configuration Lock bit for this pin
    Uint16 GPIO91:1;                    // 27 Configuration Lock bit for this pin
    Uint16 GPIO92:1;                    // 28 Configuration Lock bit for this pin
    Uint16 GPIO93:1;                    // 29 Configuration Lock bit for this pin
    Uint16 GPIO94:1;                    // 30 Configuration Lock bit for this pin
    Uint16 GPIO95:1;                    // 31 Configuration Lock bit for this pin
};

union GPCLOCK_REG {
    Uint32  all;
    struct  GPCLOCK_BITS  bit;
};

struct GPCCR_BITS {                     // bits description
    Uint16 GPIO64:1;                    // 0 Configuration lock commit bit for this pin
    Uint16 GPIO65:1;                    // 1 Configuration lock commit bit for this pin
    Uint16 GPIO66:1;                    // 2 Configuration lock commit bit for this pin
    Uint16 GPIO67:1;                    // 3 Configuration lock commit bit for this pin
    Uint16 GPIO68:1;                    // 4 Configuration lock commit bit for this pin
    Uint16 GPIO69:1;                    // 5 Configuration lock commit bit for this pin
    Uint16 GPIO70:1;                    // 6 Configuration lock commit bit for this pin
    Uint16 GPIO71:1;                    // 7 Configuration lock commit bit for this pin
    Uint16 GPIO72:1;                    // 8 Configuration lock commit bit for this pin
    Uint16 GPIO73:1;                    // 9 Configuration lock commit bit for this pin
    Uint16 GPIO74:1;                    // 10 Configuration lock commit bit for this pin
    Uint16 GPIO75:1;                    // 11 Configuration lock commit bit for this pin
    Uint16 GPIO76:1;                    // 12 Configuration lock commit bit for this pin
    Uint16 GPIO77:1;                    // 13 Configuration lock commit bit for this pin
    Uint16 GPIO78:1;                    // 14 Configuration lock commit bit for this pin
    Uint16 GPIO79:1;                    // 15 Configuration lock commit bit for this pin
    Uint16 GPIO80:1;                    // 16 Configuration lock commit bit for this pin
    Uint16 GPIO81:1;                    // 17 Configuration lock commit bit for this pin
    Uint16 GPIO82:1;                    // 18 Configuration lock commit bit for this pin
    Uint16 GPIO83:1;                    // 19 Configuration lock commit bit for this pin
    Uint16 GPIO84:1;                    // 20 Configuration lock commit bit for this pin
    Uint16 GPIO85:1;                    // 21 Configuration lock commit bit for this pin
    Uint16 GPIO86:1;                    // 22 Configuration lock commit bit for this pin
    Uint16 GPIO87:1;                    // 23 Configuration lock commit bit for this pin
    Uint16 GPIO88:1;                    // 24 Configuration lock commit bit for this pin
    Uint16 GPIO89:1;                    // 25 Configuration lock commit bit for this pin
    Uint16 GPIO90:1;                    // 26 Configuration lock commit bit for this pin
    Uint16 GPIO91:1;                    // 27 Configuration lock commit bit for this pin
    Uint16 GPIO92:1;                    // 28 Configuration lock commit bit for this pin
    Uint16 GPIO93:1;                    // 29 Configuration lock commit bit for this pin
    Uint16 GPIO94:1;                    // 30 Configuration lock commit bit for this pin
    Uint16 GPIO95:1;                    // 31 Configuration lock commit bit for this pin
};

union GPCCR_REG {
    Uint32  all;
    struct  GPCCR_BITS  bit;
};

struct GPDCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO96 to GPIO103
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO104 to GPIO111
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO112 to GPIO119
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO120 to GPIO127
};

union GPDCTRL_REG {
    Uint32  all;
    struct  GPDCTRL_BITS  bit;
};

struct GPDQSEL1_BITS {                  // bits description
    Uint16 GPIO96:2;                    // 1:0 Select input qualification type for GPIO96
    Uint16 GPIO97:2;                    // 3:2 Select input qualification type for GPIO97
    Uint16 GPIO98:2;                    // 5:4 Select input qualification type for GPIO98
    Uint16 GPIO99:2;                    // 7:6 Select input qualification type for GPIO99
    Uint16 GPIO100:2;                   // 9:8 Select input qualification type for GPIO100
    Uint16 GPIO101:2;                   // 11:10 Select input qualification type for GPIO101
    Uint16 GPIO102:2;                   // 13:12 Select input qualification type for GPIO102
    Uint16 GPIO103:2;                   // 15:14 Select input qualification type for GPIO103
    Uint16 GPIO104:2;                   // 17:16 Select input qualification type for GPIO104
    Uint16 GPIO105:2;                   // 19:18 Select input qualification type for GPIO105
    Uint16 GPIO106:2;                   // 21:20 Select input qualification type for GPIO106
    Uint16 GPIO107:2;                   // 23:22 Select input qualification type for GPIO107
    Uint16 GPIO108:2;                   // 25:24 Select input qualification type for GPIO108
    Uint16 GPIO109:2;                   // 27:26 Select input qualification type for GPIO109
    Uint16 GPIO110:2;                   // 29:28 Select input qualification type for GPIO110
    Uint16 GPIO111:2;                   // 31:30 Select input qualification type for GPIO111
};

union GPDQSEL1_REG {
    Uint32  all;
    struct  GPDQSEL1_BITS  bit;
};

struct GPDQSEL2_BITS {                  // bits description
    Uint16 GPIO112:2;                   // 1:0 Select input qualification type for GPIO112
    Uint16 GPIO113:2;                   // 3:2 Select input qualification type for GPIO113
    Uint16 GPIO114:2;                   // 5:4 Select input qualification type for GPIO114
    Uint16 GPIO115:2;                   // 7:6 Select input qualification type for GPIO115
    Uint16 GPIO116:2;                   // 9:8 Select input qualification type for GPIO116
    Uint16 GPIO117:2;                   // 11:10 Select input qualification type for GPIO117
    Uint16 GPIO118:2;                   // 13:12 Select input qualification type for GPIO118
    Uint16 GPIO119:2;                   // 15:14 Select input qualification type for GPIO119
    Uint16 GPIO120:2;                   // 17:16 Select input qualification type for GPIO120
    Uint16 GPIO121:2;                   // 19:18 Select input qualification type for GPIO121
    Uint16 GPIO122:2;                   // 21:20 Select input qualification type for GPIO122
    Uint16 GPIO123:2;                   // 23:22 Select input qualification type for GPIO123
    Uint16 GPIO124:2;                   // 25:24 Select input qualification type for GPIO124
    Uint16 GPIO125:2;                   // 27:26 Select input qualification type for GPIO125
    Uint16 GPIO126:2;                   // 29:28 Select input qualification type for GPIO126
    Uint16 GPIO127:2;                   // 31:30 Select input qualification type for GPIO127
};

union GPDQSEL2_REG {
    Uint32  all;
    struct  GPDQSEL2_BITS  bit;
};

struct GPDMUX1_BITS {                   // bits description
    Uint16 GPIO96:2;                    // 1:0 Defines pin-muxing selection for GPIO96
    Uint16 GPIO97:2;                    // 3:2 Defines pin-muxing selection for GPIO97
    Uint16 GPIO98:2;                    // 5:4 Defines pin-muxing selection for GPIO98
    Uint16 GPIO99:2;                    // 7:6 Defines pin-muxing selection for GPIO99
    Uint16 GPIO100:2;                   // 9:8 Defines pin-muxing selection for GPIO100
    Uint16 GPIO101:2;                   // 11:10 Defines pin-muxing selection for GPIO101
    Uint16 GPIO102:2;                   // 13:12 Defines pin-muxing selection for GPIO102
    Uint16 GPIO103:2;                   // 15:14 Defines pin-muxing selection for GPIO103
    Uint16 GPIO104:2;                   // 17:16 Defines pin-muxing selection for GPIO104
    Uint16 GPIO105:2;                   // 19:18 Defines pin-muxing selection for GPIO105
    Uint16 GPIO106:2;                   // 21:20 Defines pin-muxing selection for GPIO106
    Uint16 GPIO107:2;                   // 23:22 Defines pin-muxing selection for GPIO107
    Uint16 GPIO108:2;                   // 25:24 Defines pin-muxing selection for GPIO108
    Uint16 GPIO109:2;                   // 27:26 Defines pin-muxing selection for GPIO109
    Uint16 GPIO110:2;                   // 29:28 Defines pin-muxing selection for GPIO110
    Uint16 GPIO111:2;                   // 31:30 Defines pin-muxing selection for GPIO111
};

union GPDMUX1_REG {
    Uint32  all;
    struct  GPDMUX1_BITS  bit;
};

struct GPDMUX2_BITS {                   // bits description
    Uint16 GPIO112:2;                   // 1:0 Defines pin-muxing selection for GPIO112
    Uint16 GPIO113:2;                   // 3:2 Defines pin-muxing selection for GPIO113
    Uint16 GPIO114:2;                   // 5:4 Defines pin-muxing selection for GPIO114
    Uint16 GPIO115:2;                   // 7:6 Defines pin-muxing selection for GPIO115
    Uint16 GPIO116:2;                   // 9:8 Defines pin-muxing selection for GPIO116
    Uint16 GPIO117:2;                   // 11:10 Defines pin-muxing selection for GPIO117
    Uint16 GPIO118:2;                   // 13:12 Defines pin-muxing selection for GPIO118
    Uint16 GPIO119:2;                   // 15:14 Defines pin-muxing selection for GPIO119
    Uint16 GPIO120:2;                   // 17:16 Defines pin-muxing selection for GPIO120
    Uint16 GPIO121:2;                   // 19:18 Defines pin-muxing selection for GPIO121
    Uint16 GPIO122:2;                   // 21:20 Defines pin-muxing selection for GPIO122
    Uint16 GPIO123:2;                   // 23:22 Defines pin-muxing selection for GPIO123
    Uint16 GPIO124:2;                   // 25:24 Defines pin-muxing selection for GPIO124
    Uint16 GPIO125:2;                   // 27:26 Defines pin-muxing selection for GPIO125
    Uint16 GPIO126:2;                   // 29:28 Defines pin-muxing selection for GPIO126
    Uint16 GPIO127:2;                   // 31:30 Defines pin-muxing selection for GPIO127
};

union GPDMUX2_REG {
    Uint32  all;
    struct  GPDMUX2_BITS  bit;
};

struct GPDDIR_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO97:1;                    // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO98:1;                    // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO99:1;                    // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO100:1;                   // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO101:1;                   // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO102:1;                   // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO103:1;                   // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO104:1;                   // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO105:1;                   // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO106:1;                   // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO107:1;                   // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO108:1;                   // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO109:1;                   // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO110:1;                   // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO111:1;                   // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO112:1;                   // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO113:1;                   // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO114:1;                   // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO115:1;                   // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO116:1;                   // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO117:1;                   // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO118:1;                   // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO119:1;                   // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO120:1;                   // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO121:1;                   // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO122:1;                   // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO123:1;                   // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO124:1;                   // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO125:1;                   // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO126:1;                   // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO127:1;                   // 31 Defines direction for this pin in GPIO mode
};

union GPDDIR_REG {
    Uint32  all;
    struct  GPDDIR_BITS  bit;
};

struct GPDPUD_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Pull-Up Disable control for this pin
    Uint16 GPIO97:1;                    // 1 Pull-Up Disable control for this pin
    Uint16 GPIO98:1;                    // 2 Pull-Up Disable control for this pin
    Uint16 GPIO99:1;                    // 3 Pull-Up Disable control for this pin
    Uint16 GPIO100:1;                   // 4 Pull-Up Disable control for this pin
    Uint16 GPIO101:1;                   // 5 Pull-Up Disable control for this pin
    Uint16 GPIO102:1;                   // 6 Pull-Up Disable control for this pin
    Uint16 GPIO103:1;                   // 7 Pull-Up Disable control for this pin
    Uint16 GPIO104:1;                   // 8 Pull-Up Disable control for this pin
    Uint16 GPIO105:1;                   // 9 Pull-Up Disable control for this pin
    Uint16 GPIO106:1;                   // 10 Pull-Up Disable control for this pin
    Uint16 GPIO107:1;                   // 11 Pull-Up Disable control for this pin
    Uint16 GPIO108:1;                   // 12 Pull-Up Disable control for this pin
    Uint16 GPIO109:1;                   // 13 Pull-Up Disable control for this pin
    Uint16 GPIO110:1;                   // 14 Pull-Up Disable control for this pin
    Uint16 GPIO111:1;                   // 15 Pull-Up Disable control for this pin
    Uint16 GPIO112:1;                   // 16 Pull-Up Disable control for this pin
    Uint16 GPIO113:1;                   // 17 Pull-Up Disable control for this pin
    Uint16 GPIO114:1;                   // 18 Pull-Up Disable control for this pin
    Uint16 GPIO115:1;                   // 19 Pull-Up Disable control for this pin
    Uint16 GPIO116:1;                   // 20 Pull-Up Disable control for this pin
    Uint16 GPIO117:1;                   // 21 Pull-Up Disable control for this pin
    Uint16 GPIO118:1;                   // 22 Pull-Up Disable control for this pin
    Uint16 GPIO119:1;                   // 23 Pull-Up Disable control for this pin
    Uint16 GPIO120:1;                   // 24 Pull-Up Disable control for this pin
    Uint16 GPIO121:1;                   // 25 Pull-Up Disable control for this pin
    Uint16 GPIO122:1;                   // 26 Pull-Up Disable control for this pin
    Uint16 GPIO123:1;                   // 27 Pull-Up Disable control for this pin
    Uint16 GPIO124:1;                   // 28 Pull-Up Disable control for this pin
    Uint16 GPIO125:1;                   // 29 Pull-Up Disable control for this pin
    Uint16 GPIO126:1;                   // 30 Pull-Up Disable control for this pin
    Uint16 GPIO127:1;                   // 31 Pull-Up Disable control for this pin
};

union GPDPUD_REG {
    Uint32  all;
    struct  GPDPUD_BITS  bit;
};

struct GPDINV_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Input inversion control for this pin
    Uint16 GPIO97:1;                    // 1 Input inversion control for this pin
    Uint16 GPIO98:1;                    // 2 Input inversion control for this pin
    Uint16 GPIO99:1;                    // 3 Input inversion control for this pin
    Uint16 GPIO100:1;                   // 4 Input inversion control for this pin
    Uint16 GPIO101:1;                   // 5 Input inversion control for this pin
    Uint16 GPIO102:1;                   // 6 Input inversion control for this pin
    Uint16 GPIO103:1;                   // 7 Input inversion control for this pin
    Uint16 GPIO104:1;                   // 8 Input inversion control for this pin
    Uint16 GPIO105:1;                   // 9 Input inversion control for this pin
    Uint16 GPIO106:1;                   // 10 Input inversion control for this pin
    Uint16 GPIO107:1;                   // 11 Input inversion control for this pin
    Uint16 GPIO108:1;                   // 12 Input inversion control for this pin
    Uint16 GPIO109:1;                   // 13 Input inversion control for this pin
    Uint16 GPIO110:1;                   // 14 Input inversion control for this pin
    Uint16 GPIO111:1;                   // 15 Input inversion control for this pin
    Uint16 GPIO112:1;                   // 16 Input inversion control for this pin
    Uint16 GPIO113:1;                   // 17 Input inversion control for this pin
    Uint16 GPIO114:1;                   // 18 Input inversion control for this pin
    Uint16 GPIO115:1;                   // 19 Input inversion control for this pin
    Uint16 GPIO116:1;                   // 20 Input inversion control for this pin
    Uint16 GPIO117:1;                   // 21 Input inversion control for this pin
    Uint16 GPIO118:1;                   // 22 Input inversion control for this pin
    Uint16 GPIO119:1;                   // 23 Input inversion control for this pin
    Uint16 GPIO120:1;                   // 24 Input inversion control for this pin
    Uint16 GPIO121:1;                   // 25 Input inversion control for this pin
    Uint16 GPIO122:1;                   // 26 Input inversion control for this pin
    Uint16 GPIO123:1;                   // 27 Input inversion control for this pin
    Uint16 GPIO124:1;                   // 28 Input inversion control for this pin
    Uint16 GPIO125:1;                   // 29 Input inversion control for this pin
    Uint16 GPIO126:1;                   // 30 Input inversion control for this pin
    Uint16 GPIO127:1;                   // 31 Input inversion control for this pin
};

union GPDINV_REG {
    Uint32  all;
    struct  GPDINV_BITS  bit;
};

struct GPDODR_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO97:1;                    // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO98:1;                    // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO99:1;                    // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO100:1;                   // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO101:1;                   // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO102:1;                   // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO103:1;                   // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO104:1;                   // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO105:1;                   // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO106:1;                   // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO107:1;                   // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO108:1;                   // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO109:1;                   // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO110:1;                   // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO111:1;                   // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO112:1;                   // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO113:1;                   // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO114:1;                   // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO115:1;                   // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO116:1;                   // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO117:1;                   // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO118:1;                   // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO119:1;                   // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO120:1;                   // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO121:1;                   // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO122:1;                   // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO123:1;                   // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO124:1;                   // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO125:1;                   // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO126:1;                   // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO127:1;                   // 31 Outpout Open-Drain control for this pin
};

union GPDODR_REG {
    Uint32  all;
    struct  GPDODR_BITS  bit;
};

struct GPDGMUX1_BITS {                  // bits description
    Uint16 GPIO96:2;                    // 1:0 Defines pin-muxing selection for GPIO96
    Uint16 GPIO97:2;                    // 3:2 Defines pin-muxing selection for GPIO97
    Uint16 GPIO98:2;                    // 5:4 Defines pin-muxing selection for GPIO98
    Uint16 GPIO99:2;                    // 7:6 Defines pin-muxing selection for GPIO99
    Uint16 GPIO100:2;                   // 9:8 Defines pin-muxing selection for GPIO100
    Uint16 GPIO101:2;                   // 11:10 Defines pin-muxing selection for GPIO101
    Uint16 GPIO102:2;                   // 13:12 Defines pin-muxing selection for GPIO102
    Uint16 GPIO103:2;                   // 15:14 Defines pin-muxing selection for GPIO103
    Uint16 GPIO104:2;                   // 17:16 Defines pin-muxing selection for GPIO104
    Uint16 GPIO105:2;                   // 19:18 Defines pin-muxing selection for GPIO105
    Uint16 GPIO106:2;                   // 21:20 Defines pin-muxing selection for GPIO106
    Uint16 GPIO107:2;                   // 23:22 Defines pin-muxing selection for GPIO107
    Uint16 GPIO108:2;                   // 25:24 Defines pin-muxing selection for GPIO108
    Uint16 GPIO109:2;                   // 27:26 Defines pin-muxing selection for GPIO109
    Uint16 GPIO110:2;                   // 29:28 Defines pin-muxing selection for GPIO110
    Uint16 GPIO111:2;                   // 31:30 Defines pin-muxing selection for GPIO111
};

union GPDGMUX1_REG {
    Uint32  all;
    struct  GPDGMUX1_BITS  bit;
};

struct GPDGMUX2_BITS {                  // bits description
    Uint16 GPIO112:2;                   // 1:0 Defines pin-muxing selection for GPIO112
    Uint16 GPIO113:2;                   // 3:2 Defines pin-muxing selection for GPIO113
    Uint16 GPIO114:2;                   // 5:4 Defines pin-muxing selection for GPIO114
    Uint16 GPIO115:2;                   // 7:6 Defines pin-muxing selection for GPIO115
    Uint16 GPIO116:2;                   // 9:8 Defines pin-muxing selection for GPIO116
    Uint16 GPIO117:2;                   // 11:10 Defines pin-muxing selection for GPIO117
    Uint16 GPIO118:2;                   // 13:12 Defines pin-muxing selection for GPIO118
    Uint16 GPIO119:2;                   // 15:14 Defines pin-muxing selection for GPIO119
    Uint16 GPIO120:2;                   // 17:16 Defines pin-muxing selection for GPIO120
    Uint16 GPIO121:2;                   // 19:18 Defines pin-muxing selection for GPIO121
    Uint16 GPIO122:2;                   // 21:20 Defines pin-muxing selection for GPIO122
    Uint16 GPIO123:2;                   // 23:22 Defines pin-muxing selection for GPIO123
    Uint16 GPIO124:2;                   // 25:24 Defines pin-muxing selection for GPIO124
    Uint16 GPIO125:2;                   // 27:26 Defines pin-muxing selection for GPIO125
    Uint16 GPIO126:2;                   // 29:28 Defines pin-muxing selection for GPIO126
    Uint16 GPIO127:2;                   // 31:30 Defines pin-muxing selection for GPIO127
};

union GPDGMUX2_REG {
    Uint32  all;
    struct  GPDGMUX2_BITS  bit;
};

struct GPDCSEL1_BITS {                  // bits description
    Uint16 GPIO96:4;                    // 3:0 GPIO96 Master CPU Select
    Uint16 GPIO97:4;                    // 7:4 GPIO97 Master CPU Select
    Uint16 GPIO98:4;                    // 11:8 GPIO98 Master CPU Select
    Uint16 GPIO99:4;                    // 15:12 GPIO99 Master CPU Select
    Uint16 GPIO100:4;                   // 19:16 GPIO100 Master CPU Select
    Uint16 GPIO101:4;                   // 23:20 GPIO101 Master CPU Select
    Uint16 GPIO102:4;                   // 27:24 GPIO102 Master CPU Select
    Uint16 GPIO103:4;                   // 31:28 GPIO103 Master CPU Select
};

union GPDCSEL1_REG {
    Uint32  all;
    struct  GPDCSEL1_BITS  bit;
};

struct GPDCSEL2_BITS {                  // bits description
    Uint16 GPIO104:4;                   // 3:0 GPIO104 Master CPU Select
    Uint16 GPIO105:4;                   // 7:4 GPIO105 Master CPU Select
    Uint16 GPIO106:4;                   // 11:8 GPIO106 Master CPU Select
    Uint16 GPIO107:4;                   // 15:12 GPIO107 Master CPU Select
    Uint16 GPIO108:4;                   // 19:16 GPIO108 Master CPU Select
    Uint16 GPIO109:4;                   // 23:20 GPIO109 Master CPU Select
    Uint16 GPIO110:4;                   // 27:24 GPIO110 Master CPU Select
    Uint16 GPIO111:4;                   // 31:28 GPIO111 Master CPU Select
};

union GPDCSEL2_REG {
    Uint32  all;
    struct  GPDCSEL2_BITS  bit;
};

struct GPDCSEL3_BITS {                  // bits description
    Uint16 GPIO112:4;                   // 3:0 GPIO112 Master CPU Select
    Uint16 GPIO113:4;                   // 7:4 GPIO113 Master CPU Select
    Uint16 GPIO114:4;                   // 11:8 GPIO114 Master CPU Select
    Uint16 GPIO115:4;                   // 15:12 GPIO115 Master CPU Select
    Uint16 GPIO116:4;                   // 19:16 GPIO116 Master CPU Select
    Uint16 GPIO117:4;                   // 23:20 GPIO117 Master CPU Select
    Uint16 GPIO118:4;                   // 27:24 GPIO118 Master CPU Select
    Uint16 GPIO119:4;                   // 31:28 GPIO119 Master CPU Select
};

union GPDCSEL3_REG {
    Uint32  all;
    struct  GPDCSEL3_BITS  bit;
};

struct GPDCSEL4_BITS {                  // bits description
    Uint16 GPIO120:4;                   // 3:0 GPIO120 Master CPU Select
    Uint16 GPIO121:4;                   // 7:4 GPIO121 Master CPU Select
    Uint16 GPIO122:4;                   // 11:8 GPIO122 Master CPU Select
    Uint16 GPIO123:4;                   // 15:12 GPIO123 Master CPU Select
    Uint16 GPIO124:4;                   // 19:16 GPIO124 Master CPU Select
    Uint16 GPIO125:4;                   // 23:20 GPIO125 Master CPU Select
    Uint16 GPIO126:4;                   // 27:24 GPIO126 Master CPU Select
    Uint16 GPIO127:4;                   // 31:28 GPIO127 Master CPU Select
};

union GPDCSEL4_REG {
    Uint32  all;
    struct  GPDCSEL4_BITS  bit;
};

struct GPDLOCK_BITS {                   // bits description
    Uint16 GPIO96:1;                    // 0 Configuration Lock bit for this pin
    Uint16 GPIO97:1;                    // 1 Configuration Lock bit for this pin
    Uint16 GPIO98:1;                    // 2 Configuration Lock bit for this pin
    Uint16 GPIO99:1;                    // 3 Configuration Lock bit for this pin
    Uint16 GPIO100:1;                   // 4 Configuration Lock bit for this pin
    Uint16 GPIO101:1;                   // 5 Configuration Lock bit for this pin
    Uint16 GPIO102:1;                   // 6 Configuration Lock bit for this pin
    Uint16 GPIO103:1;                   // 7 Configuration Lock bit for this pin
    Uint16 GPIO104:1;                   // 8 Configuration Lock bit for this pin
    Uint16 GPIO105:1;                   // 9 Configuration Lock bit for this pin
    Uint16 GPIO106:1;                   // 10 Configuration Lock bit for this pin
    Uint16 GPIO107:1;                   // 11 Configuration Lock bit for this pin
    Uint16 GPIO108:1;                   // 12 Configuration Lock bit for this pin
    Uint16 GPIO109:1;                   // 13 Configuration Lock bit for this pin
    Uint16 GPIO110:1;                   // 14 Configuration Lock bit for this pin
    Uint16 GPIO111:1;                   // 15 Configuration Lock bit for this pin
    Uint16 GPIO112:1;                   // 16 Configuration Lock bit for this pin
    Uint16 GPIO113:1;                   // 17 Configuration Lock bit for this pin
    Uint16 GPIO114:1;                   // 18 Configuration Lock bit for this pin
    Uint16 GPIO115:1;                   // 19 Configuration Lock bit for this pin
    Uint16 GPIO116:1;                   // 20 Configuration Lock bit for this pin
    Uint16 GPIO117:1;                   // 21 Configuration Lock bit for this pin
    Uint16 GPIO118:1;                   // 22 Configuration Lock bit for this pin
    Uint16 GPIO119:1;                   // 23 Configuration Lock bit for this pin
    Uint16 GPIO120:1;                   // 24 Configuration Lock bit for this pin
    Uint16 GPIO121:1;                   // 25 Configuration Lock bit for this pin
    Uint16 GPIO122:1;                   // 26 Configuration Lock bit for this pin
    Uint16 GPIO123:1;                   // 27 Configuration Lock bit for this pin
    Uint16 GPIO124:1;                   // 28 Configuration Lock bit for this pin
    Uint16 GPIO125:1;                   // 29 Configuration Lock bit for this pin
    Uint16 GPIO126:1;                   // 30 Configuration Lock bit for this pin
    Uint16 GPIO127:1;                   // 31 Configuration Lock bit for this pin
};

union GPDLOCK_REG {
    Uint32  all;
    struct  GPDLOCK_BITS  bit;
};

struct GPDCR_BITS {                     // bits description
    Uint16 GPIO96:1;                    // 0 Configuration lock commit bit for this pin
    Uint16 GPIO97:1;                    // 1 Configuration lock commit bit for this pin
    Uint16 GPIO98:1;                    // 2 Configuration lock commit bit for this pin
    Uint16 GPIO99:1;                    // 3 Configuration lock commit bit for this pin
    Uint16 GPIO100:1;                   // 4 Configuration lock commit bit for this pin
    Uint16 GPIO101:1;                   // 5 Configuration lock commit bit for this pin
    Uint16 GPIO102:1;                   // 6 Configuration lock commit bit for this pin
    Uint16 GPIO103:1;                   // 7 Configuration lock commit bit for this pin
    Uint16 GPIO104:1;                   // 8 Configuration lock commit bit for this pin
    Uint16 GPIO105:1;                   // 9 Configuration lock commit bit for this pin
    Uint16 GPIO106:1;                   // 10 Configuration lock commit bit for this pin
    Uint16 GPIO107:1;                   // 11 Configuration lock commit bit for this pin
    Uint16 GPIO108:1;                   // 12 Configuration lock commit bit for this pin
    Uint16 GPIO109:1;                   // 13 Configuration lock commit bit for this pin
    Uint16 GPIO110:1;                   // 14 Configuration lock commit bit for this pin
    Uint16 GPIO111:1;                   // 15 Configuration lock commit bit for this pin
    Uint16 GPIO112:1;                   // 16 Configuration lock commit bit for this pin
    Uint16 GPIO113:1;                   // 17 Configuration lock commit bit for this pin
    Uint16 GPIO114:1;                   // 18 Configuration lock commit bit for this pin
    Uint16 GPIO115:1;                   // 19 Configuration lock commit bit for this pin
    Uint16 GPIO116:1;                   // 20 Configuration lock commit bit for this pin
    Uint16 GPIO117:1;                   // 21 Configuration lock commit bit for this pin
    Uint16 GPIO118:1;                   // 22 Configuration lock commit bit for this pin
    Uint16 GPIO119:1;                   // 23 Configuration lock commit bit for this pin
    Uint16 GPIO120:1;                   // 24 Configuration lock commit bit for this pin
    Uint16 GPIO121:1;                   // 25 Configuration lock commit bit for this pin
    Uint16 GPIO122:1;                   // 26 Configuration lock commit bit for this pin
    Uint16 GPIO123:1;                   // 27 Configuration lock commit bit for this pin
    Uint16 GPIO124:1;                   // 28 Configuration lock commit bit for this pin
    Uint16 GPIO125:1;                   // 29 Configuration lock commit bit for this pin
    Uint16 GPIO126:1;                   // 30 Configuration lock commit bit for this pin
    Uint16 GPIO127:1;                   // 31 Configuration lock commit bit for this pin
};

union GPDCR_REG {
    Uint32  all;
    struct  GPDCR_BITS  bit;
};

struct GPECTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO128 to GPIO135
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO136 to GPIO143
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO144 to GPIO151
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO152 to GPIO159
};

union GPECTRL_REG {
    Uint32  all;
    struct  GPECTRL_BITS  bit;
};

struct GPEQSEL1_BITS {                  // bits description
    Uint16 GPIO128:2;                   // 1:0 Select input qualification type for GPIO128
    Uint16 GPIO129:2;                   // 3:2 Select input qualification type for GPIO129
    Uint16 GPIO130:2;                   // 5:4 Select input qualification type for GPIO130
    Uint16 GPIO131:2;                   // 7:6 Select input qualification type for GPIO131
    Uint16 GPIO132:2;                   // 9:8 Select input qualification type for GPIO132
    Uint16 GPIO133:2;                   // 11:10 Select input qualification type for GPIO133
    Uint16 GPIO134:2;                   // 13:12 Select input qualification type for GPIO134
    Uint16 GPIO135:2;                   // 15:14 Select input qualification type for GPIO135
    Uint16 GPIO136:2;                   // 17:16 Select input qualification type for GPIO136
    Uint16 GPIO137:2;                   // 19:18 Select input qualification type for GPIO137
    Uint16 GPIO138:2;                   // 21:20 Select input qualification type for GPIO138
    Uint16 GPIO139:2;                   // 23:22 Select input qualification type for GPIO139
    Uint16 GPIO140:2;                   // 25:24 Select input qualification type for GPIO140
    Uint16 GPIO141:2;                   // 27:26 Select input qualification type for GPIO141
    Uint16 GPIO142:2;                   // 29:28 Select input qualification type for GPIO142
    Uint16 GPIO143:2;                   // 31:30 Select input qualification type for GPIO143
};

union GPEQSEL1_REG {
    Uint32  all;
    struct  GPEQSEL1_BITS  bit;
};

struct GPEQSEL2_BITS {                  // bits description
    Uint16 GPIO144:2;                   // 1:0 Select input qualification type for GPIO144
    Uint16 GPIO145:2;                   // 3:2 Select input qualification type for GPIO145
    Uint16 GPIO146:2;                   // 5:4 Select input qualification type for GPIO146
    Uint16 GPIO147:2;                   // 7:6 Select input qualification type for GPIO147
    Uint16 GPIO148:2;                   // 9:8 Select input qualification type for GPIO148
    Uint16 GPIO149:2;                   // 11:10 Select input qualification type for GPIO149
    Uint16 GPIO150:2;                   // 13:12 Select input qualification type for GPIO150
    Uint16 GPIO151:2;                   // 15:14 Select input qualification type for GPIO151
    Uint16 GPIO152:2;                   // 17:16 Select input qualification type for GPIO152
    Uint16 GPIO153:2;                   // 19:18 Select input qualification type for GPIO153
    Uint16 GPIO154:2;                   // 21:20 Select input qualification type for GPIO154
    Uint16 GPIO155:2;                   // 23:22 Select input qualification type for GPIO155
    Uint16 GPIO156:2;                   // 25:24 Select input qualification type for GPIO156
    Uint16 GPIO157:2;                   // 27:26 Select input qualification type for GPIO157
    Uint16 GPIO158:2;                   // 29:28 Select input qualification type for GPIO158
    Uint16 GPIO159:2;                   // 31:30 Select input qualification type for GPIO159
};

union GPEQSEL2_REG {
    Uint32  all;
    struct  GPEQSEL2_BITS  bit;
};

struct GPEMUX1_BITS {                   // bits description
    Uint16 GPIO128:2;                   // 1:0 Defines pin-muxing selection for GPIO128
    Uint16 GPIO129:2;                   // 3:2 Defines pin-muxing selection for GPIO129
    Uint16 GPIO130:2;                   // 5:4 Defines pin-muxing selection for GPIO130
    Uint16 GPIO131:2;                   // 7:6 Defines pin-muxing selection for GPIO131
    Uint16 GPIO132:2;                   // 9:8 Defines pin-muxing selection for GPIO132
    Uint16 GPIO133:2;                   // 11:10 Defines pin-muxing selection for GPIO133
    Uint16 GPIO134:2;                   // 13:12 Defines pin-muxing selection for GPIO134
    Uint16 GPIO135:2;                   // 15:14 Defines pin-muxing selection for GPIO135
    Uint16 GPIO136:2;                   // 17:16 Defines pin-muxing selection for GPIO136
    Uint16 GPIO137:2;                   // 19:18 Defines pin-muxing selection for GPIO137
    Uint16 GPIO138:2;                   // 21:20 Defines pin-muxing selection for GPIO138
    Uint16 GPIO139:2;                   // 23:22 Defines pin-muxing selection for GPIO139
    Uint16 GPIO140:2;                   // 25:24 Defines pin-muxing selection for GPIO140
    Uint16 GPIO141:2;                   // 27:26 Defines pin-muxing selection for GPIO141
    Uint16 GPIO142:2;                   // 29:28 Defines pin-muxing selection for GPIO142
    Uint16 GPIO143:2;                   // 31:30 Defines pin-muxing selection for GPIO143
};

union GPEMUX1_REG {
    Uint32  all;
    struct  GPEMUX1_BITS  bit;
};

struct GPEMUX2_BITS {                   // bits description
    Uint16 GPIO144:2;                   // 1:0 Defines pin-muxing selection for GPIO144
    Uint16 GPIO145:2;                   // 3:2 Defines pin-muxing selection for GPIO145
    Uint16 GPIO146:2;                   // 5:4 Defines pin-muxing selection for GPIO146
    Uint16 GPIO147:2;                   // 7:6 Defines pin-muxing selection for GPIO147
    Uint16 GPIO148:2;                   // 9:8 Defines pin-muxing selection for GPIO148
    Uint16 GPIO149:2;                   // 11:10 Defines pin-muxing selection for GPIO149
    Uint16 GPIO150:2;                   // 13:12 Defines pin-muxing selection for GPIO150
    Uint16 GPIO151:2;                   // 15:14 Defines pin-muxing selection for GPIO151
    Uint16 GPIO152:2;                   // 17:16 Defines pin-muxing selection for GPIO152
    Uint16 GPIO153:2;                   // 19:18 Defines pin-muxing selection for GPIO153
    Uint16 GPIO154:2;                   // 21:20 Defines pin-muxing selection for GPIO154
    Uint16 GPIO155:2;                   // 23:22 Defines pin-muxing selection for GPIO155
    Uint16 GPIO156:2;                   // 25:24 Defines pin-muxing selection for GPIO156
    Uint16 GPIO157:2;                   // 27:26 Defines pin-muxing selection for GPIO157
    Uint16 GPIO158:2;                   // 29:28 Defines pin-muxing selection for GPIO158
    Uint16 GPIO159:2;                   // 31:30 Defines pin-muxing selection for GPIO159
};

union GPEMUX2_REG {
    Uint32  all;
    struct  GPEMUX2_BITS  bit;
};

struct GPEDIR_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO129:1;                   // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO130:1;                   // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO131:1;                   // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO132:1;                   // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO133:1;                   // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO134:1;                   // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO135:1;                   // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO136:1;                   // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO137:1;                   // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO138:1;                   // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO139:1;                   // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO140:1;                   // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO141:1;                   // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO142:1;                   // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO143:1;                   // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO144:1;                   // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO145:1;                   // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO146:1;                   // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO147:1;                   // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO148:1;                   // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO149:1;                   // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO150:1;                   // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO151:1;                   // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO152:1;                   // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO153:1;                   // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO154:1;                   // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO155:1;                   // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO156:1;                   // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO157:1;                   // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO158:1;                   // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO159:1;                   // 31 Defines direction for this pin in GPIO mode
};

union GPEDIR_REG {
    Uint32  all;
    struct  GPEDIR_BITS  bit;
};

struct GPEPUD_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Pull-Up Disable control for this pin
    Uint16 GPIO129:1;                   // 1 Pull-Up Disable control for this pin
    Uint16 GPIO130:1;                   // 2 Pull-Up Disable control for this pin
    Uint16 GPIO131:1;                   // 3 Pull-Up Disable control for this pin
    Uint16 GPIO132:1;                   // 4 Pull-Up Disable control for this pin
    Uint16 GPIO133:1;                   // 5 Pull-Up Disable control for this pin
    Uint16 GPIO134:1;                   // 6 Pull-Up Disable control for this pin
    Uint16 GPIO135:1;                   // 7 Pull-Up Disable control for this pin
    Uint16 GPIO136:1;                   // 8 Pull-Up Disable control for this pin
    Uint16 GPIO137:1;                   // 9 Pull-Up Disable control for this pin
    Uint16 GPIO138:1;                   // 10 Pull-Up Disable control for this pin
    Uint16 GPIO139:1;                   // 11 Pull-Up Disable control for this pin
    Uint16 GPIO140:1;                   // 12 Pull-Up Disable control for this pin
    Uint16 GPIO141:1;                   // 13 Pull-Up Disable control for this pin
    Uint16 GPIO142:1;                   // 14 Pull-Up Disable control for this pin
    Uint16 GPIO143:1;                   // 15 Pull-Up Disable control for this pin
    Uint16 GPIO144:1;                   // 16 Pull-Up Disable control for this pin
    Uint16 GPIO145:1;                   // 17 Pull-Up Disable control for this pin
    Uint16 GPIO146:1;                   // 18 Pull-Up Disable control for this pin
    Uint16 GPIO147:1;                   // 19 Pull-Up Disable control for this pin
    Uint16 GPIO148:1;                   // 20 Pull-Up Disable control for this pin
    Uint16 GPIO149:1;                   // 21 Pull-Up Disable control for this pin
    Uint16 GPIO150:1;                   // 22 Pull-Up Disable control for this pin
    Uint16 GPIO151:1;                   // 23 Pull-Up Disable control for this pin
    Uint16 GPIO152:1;                   // 24 Pull-Up Disable control for this pin
    Uint16 GPIO153:1;                   // 25 Pull-Up Disable control for this pin
    Uint16 GPIO154:1;                   // 26 Pull-Up Disable control for this pin
    Uint16 GPIO155:1;                   // 27 Pull-Up Disable control for this pin
    Uint16 GPIO156:1;                   // 28 Pull-Up Disable control for this pin
    Uint16 GPIO157:1;                   // 29 Pull-Up Disable control for this pin
    Uint16 GPIO158:1;                   // 30 Pull-Up Disable control for this pin
    Uint16 GPIO159:1;                   // 31 Pull-Up Disable control for this pin
};

union GPEPUD_REG {
    Uint32  all;
    struct  GPEPUD_BITS  bit;
};

struct GPEINV_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Input inversion control for this pin
    Uint16 GPIO129:1;                   // 1 Input inversion control for this pin
    Uint16 GPIO130:1;                   // 2 Input inversion control for this pin
    Uint16 GPIO131:1;                   // 3 Input inversion control for this pin
    Uint16 GPIO132:1;                   // 4 Input inversion control for this pin
    Uint16 GPIO133:1;                   // 5 Input inversion control for this pin
    Uint16 GPIO134:1;                   // 6 Input inversion control for this pin
    Uint16 GPIO135:1;                   // 7 Input inversion control for this pin
    Uint16 GPIO136:1;                   // 8 Input inversion control for this pin
    Uint16 GPIO137:1;                   // 9 Input inversion control for this pin
    Uint16 GPIO138:1;                   // 10 Input inversion control for this pin
    Uint16 GPIO139:1;                   // 11 Input inversion control for this pin
    Uint16 GPIO140:1;                   // 12 Input inversion control for this pin
    Uint16 GPIO141:1;                   // 13 Input inversion control for this pin
    Uint16 GPIO142:1;                   // 14 Input inversion control for this pin
    Uint16 GPIO143:1;                   // 15 Input inversion control for this pin
    Uint16 GPIO144:1;                   // 16 Input inversion control for this pin
    Uint16 GPIO145:1;                   // 17 Input inversion control for this pin
    Uint16 GPIO146:1;                   // 18 Input inversion control for this pin
    Uint16 GPIO147:1;                   // 19 Input inversion control for this pin
    Uint16 GPIO148:1;                   // 20 Input inversion control for this pin
    Uint16 GPIO149:1;                   // 21 Input inversion control for this pin
    Uint16 GPIO150:1;                   // 22 Input inversion control for this pin
    Uint16 GPIO151:1;                   // 23 Input inversion control for this pin
    Uint16 GPIO152:1;                   // 24 Input inversion control for this pin
    Uint16 GPIO153:1;                   // 25 Input inversion control for this pin
    Uint16 GPIO154:1;                   // 26 Input inversion control for this pin
    Uint16 GPIO155:1;                   // 27 Input inversion control for this pin
    Uint16 GPIO156:1;                   // 28 Input inversion control for this pin
    Uint16 GPIO157:1;                   // 29 Input inversion control for this pin
    Uint16 GPIO158:1;                   // 30 Input inversion control for this pin
    Uint16 GPIO159:1;                   // 31 Input inversion control for this pin
};

union GPEINV_REG {
    Uint32  all;
    struct  GPEINV_BITS  bit;
};

struct GPEODR_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO129:1;                   // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO130:1;                   // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO131:1;                   // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO132:1;                   // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO133:1;                   // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO134:1;                   // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO135:1;                   // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO136:1;                   // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO137:1;                   // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO138:1;                   // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO139:1;                   // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO140:1;                   // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO141:1;                   // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO142:1;                   // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO143:1;                   // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO144:1;                   // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO145:1;                   // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO146:1;                   // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO147:1;                   // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO148:1;                   // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO149:1;                   // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO150:1;                   // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO151:1;                   // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO152:1;                   // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO153:1;                   // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO154:1;                   // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO155:1;                   // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO156:1;                   // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO157:1;                   // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO158:1;                   // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO159:1;                   // 31 Outpout Open-Drain control for this pin
};

union GPEODR_REG {
    Uint32  all;
    struct  GPEODR_BITS  bit;
};

struct GPEGMUX1_BITS {                  // bits description
    Uint16 GPIO128:2;                   // 1:0 Defines pin-muxing selection for GPIO128
    Uint16 GPIO129:2;                   // 3:2 Defines pin-muxing selection for GPIO129
    Uint16 GPIO130:2;                   // 5:4 Defines pin-muxing selection for GPIO130
    Uint16 GPIO131:2;                   // 7:6 Defines pin-muxing selection for GPIO131
    Uint16 GPIO132:2;                   // 9:8 Defines pin-muxing selection for GPIO132
    Uint16 GPIO133:2;                   // 11:10 Defines pin-muxing selection for GPIO133
    Uint16 GPIO134:2;                   // 13:12 Defines pin-muxing selection for GPIO134
    Uint16 GPIO135:2;                   // 15:14 Defines pin-muxing selection for GPIO135
    Uint16 GPIO136:2;                   // 17:16 Defines pin-muxing selection for GPIO136
    Uint16 GPIO137:2;                   // 19:18 Defines pin-muxing selection for GPIO137
    Uint16 GPIO138:2;                   // 21:20 Defines pin-muxing selection for GPIO138
    Uint16 GPIO139:2;                   // 23:22 Defines pin-muxing selection for GPIO139
    Uint16 GPIO140:2;                   // 25:24 Defines pin-muxing selection for GPIO140
    Uint16 GPIO141:2;                   // 27:26 Defines pin-muxing selection for GPIO141
    Uint16 GPIO142:2;                   // 29:28 Defines pin-muxing selection for GPIO142
    Uint16 GPIO143:2;                   // 31:30 Defines pin-muxing selection for GPIO143
};

union GPEGMUX1_REG {
    Uint32  all;
    struct  GPEGMUX1_BITS  bit;
};

struct GPEGMUX2_BITS {                  // bits description
    Uint16 GPIO144:2;                   // 1:0 Defines pin-muxing selection for GPIO144
    Uint16 GPIO145:2;                   // 3:2 Defines pin-muxing selection for GPIO145
    Uint16 GPIO146:2;                   // 5:4 Defines pin-muxing selection for GPIO146
    Uint16 GPIO147:2;                   // 7:6 Defines pin-muxing selection for GPIO147
    Uint16 GPIO148:2;                   // 9:8 Defines pin-muxing selection for GPIO148
    Uint16 GPIO149:2;                   // 11:10 Defines pin-muxing selection for GPIO149
    Uint16 GPIO150:2;                   // 13:12 Defines pin-muxing selection for GPIO150
    Uint16 GPIO151:2;                   // 15:14 Defines pin-muxing selection for GPIO151
    Uint16 GPIO152:2;                   // 17:16 Defines pin-muxing selection for GPIO152
    Uint16 GPIO153:2;                   // 19:18 Defines pin-muxing selection for GPIO153
    Uint16 GPIO154:2;                   // 21:20 Defines pin-muxing selection for GPIO154
    Uint16 GPIO155:2;                   // 23:22 Defines pin-muxing selection for GPIO155
    Uint16 GPIO156:2;                   // 25:24 Defines pin-muxing selection for GPIO156
    Uint16 GPIO157:2;                   // 27:26 Defines pin-muxing selection for GPIO157
    Uint16 GPIO158:2;                   // 29:28 Defines pin-muxing selection for GPIO158
    Uint16 GPIO159:2;                   // 31:30 Defines pin-muxing selection for GPIO159
};

union GPEGMUX2_REG {
    Uint32  all;
    struct  GPEGMUX2_BITS  bit;
};

struct GPECSEL1_BITS {                  // bits description
    Uint16 GPIO128:4;                   // 3:0 GPIO128 Master CPU Select
    Uint16 GPIO129:4;                   // 7:4 GPIO129 Master CPU Select
    Uint16 GPIO130:4;                   // 11:8 GPIO130 Master CPU Select
    Uint16 GPIO131:4;                   // 15:12 GPIO131 Master CPU Select
    Uint16 GPIO132:4;                   // 19:16 GPIO132 Master CPU Select
    Uint16 GPIO133:4;                   // 23:20 GPIO133 Master CPU Select
    Uint16 GPIO134:4;                   // 27:24 GPIO134 Master CPU Select
    Uint16 GPIO135:4;                   // 31:28 GPIO135 Master CPU Select
};

union GPECSEL1_REG {
    Uint32  all;
    struct  GPECSEL1_BITS  bit;
};

struct GPECSEL2_BITS {                  // bits description
    Uint16 GPIO136:4;                   // 3:0 GPIO136 Master CPU Select
    Uint16 GPIO137:4;                   // 7:4 GPIO137 Master CPU Select
    Uint16 GPIO138:4;                   // 11:8 GPIO138 Master CPU Select
    Uint16 GPIO139:4;                   // 15:12 GPIO139 Master CPU Select
    Uint16 GPIO140:4;                   // 19:16 GPIO140 Master CPU Select
    Uint16 GPIO141:4;                   // 23:20 GPIO141 Master CPU Select
    Uint16 GPIO142:4;                   // 27:24 GPIO142 Master CPU Select
    Uint16 GPIO143:4;                   // 31:28 GPIO143 Master CPU Select
};

union GPECSEL2_REG {
    Uint32  all;
    struct  GPECSEL2_BITS  bit;
};

struct GPECSEL3_BITS {                  // bits description
    Uint16 GPIO144:4;                   // 3:0 GPIO144 Master CPU Select
    Uint16 GPIO145:4;                   // 7:4 GPIO145 Master CPU Select
    Uint16 GPIO146:4;                   // 11:8 GPIO146 Master CPU Select
    Uint16 GPIO147:4;                   // 15:12 GPIO147 Master CPU Select
    Uint16 GPIO148:4;                   // 19:16 GPIO148 Master CPU Select
    Uint16 GPIO149:4;                   // 23:20 GPIO149 Master CPU Select
    Uint16 GPIO150:4;                   // 27:24 GPIO150 Master CPU Select
    Uint16 GPIO151:4;                   // 31:28 GPIO151 Master CPU Select
};

union GPECSEL3_REG {
    Uint32  all;
    struct  GPECSEL3_BITS  bit;
};

struct GPECSEL4_BITS {                  // bits description
    Uint16 GPIO152:4;                   // 3:0 GPIO152 Master CPU Select
    Uint16 GPIO153:4;                   // 7:4 GPIO153 Master CPU Select
    Uint16 GPIO154:4;                   // 11:8 GPIO154 Master CPU Select
    Uint16 GPIO155:4;                   // 15:12 GPIO155 Master CPU Select
    Uint16 GPIO156:4;                   // 19:16 GPIO156 Master CPU Select
    Uint16 GPIO157:4;                   // 23:20 GPIO157 Master CPU Select
    Uint16 GPIO158:4;                   // 27:24 GPIO158 Master CPU Select
    Uint16 GPIO159:4;                   // 31:28 GPIO159 Master CPU Select
};

union GPECSEL4_REG {
    Uint32  all;
    struct  GPECSEL4_BITS  bit;
};

struct GPELOCK_BITS {                   // bits description
    Uint16 GPIO128:1;                   // 0 Configuration Lock bit for this pin
    Uint16 GPIO129:1;                   // 1 Configuration Lock bit for this pin
    Uint16 GPIO130:1;                   // 2 Configuration Lock bit for this pin
    Uint16 GPIO131:1;                   // 3 Configuration Lock bit for this pin
    Uint16 GPIO132:1;                   // 4 Configuration Lock bit for this pin
    Uint16 GPIO133:1;                   // 5 Configuration Lock bit for this pin
    Uint16 GPIO134:1;                   // 6 Configuration Lock bit for this pin
    Uint16 GPIO135:1;                   // 7 Configuration Lock bit for this pin
    Uint16 GPIO136:1;                   // 8 Configuration Lock bit for this pin
    Uint16 GPIO137:1;                   // 9 Configuration Lock bit for this pin
    Uint16 GPIO138:1;                   // 10 Configuration Lock bit for this pin
    Uint16 GPIO139:1;                   // 11 Configuration Lock bit for this pin
    Uint16 GPIO140:1;                   // 12 Configuration Lock bit for this pin
    Uint16 GPIO141:1;                   // 13 Configuration Lock bit for this pin
    Uint16 GPIO142:1;                   // 14 Configuration Lock bit for this pin
    Uint16 GPIO143:1;                   // 15 Configuration Lock bit for this pin
    Uint16 GPIO144:1;                   // 16 Configuration Lock bit for this pin
    Uint16 GPIO145:1;                   // 17 Configuration Lock bit for this pin
    Uint16 GPIO146:1;                   // 18 Configuration Lock bit for this pin
    Uint16 GPIO147:1;                   // 19 Configuration Lock bit for this pin
    Uint16 GPIO148:1;                   // 20 Configuration Lock bit for this pin
    Uint16 GPIO149:1;                   // 21 Configuration Lock bit for this pin
    Uint16 GPIO150:1;                   // 22 Configuration Lock bit for this pin
    Uint16 GPIO151:1;                   // 23 Configuration Lock bit for this pin
    Uint16 GPIO152:1;                   // 24 Configuration Lock bit for this pin
    Uint16 GPIO153:1;                   // 25 Configuration Lock bit for this pin
    Uint16 GPIO154:1;                   // 26 Configuration Lock bit for this pin
    Uint16 GPIO155:1;                   // 27 Configuration Lock bit for this pin
    Uint16 GPIO156:1;                   // 28 Configuration Lock bit for this pin
    Uint16 GPIO157:1;                   // 29 Configuration Lock bit for this pin
    Uint16 GPIO158:1;                   // 30 Configuration Lock bit for this pin
    Uint16 GPIO159:1;                   // 31 Configuration Lock bit for this pin
};

union GPELOCK_REG {
    Uint32  all;
    struct  GPELOCK_BITS  bit;
};

struct GPECR_BITS {                     // bits description
    Uint16 GPIO128:1;                   // 0 Configuration lock commit bit for this pin
    Uint16 GPIO129:1;                   // 1 Configuration lock commit bit for this pin
    Uint16 GPIO130:1;                   // 2 Configuration lock commit bit for this pin
    Uint16 GPIO131:1;                   // 3 Configuration lock commit bit for this pin
    Uint16 GPIO132:1;                   // 4 Configuration lock commit bit for this pin
    Uint16 GPIO133:1;                   // 5 Configuration lock commit bit for this pin
    Uint16 GPIO134:1;                   // 6 Configuration lock commit bit for this pin
    Uint16 GPIO135:1;                   // 7 Configuration lock commit bit for this pin
    Uint16 GPIO136:1;                   // 8 Configuration lock commit bit for this pin
    Uint16 GPIO137:1;                   // 9 Configuration lock commit bit for this pin
    Uint16 GPIO138:1;                   // 10 Configuration lock commit bit for this pin
    Uint16 GPIO139:1;                   // 11 Configuration lock commit bit for this pin
    Uint16 GPIO140:1;                   // 12 Configuration lock commit bit for this pin
    Uint16 GPIO141:1;                   // 13 Configuration lock commit bit for this pin
    Uint16 GPIO142:1;                   // 14 Configuration lock commit bit for this pin
    Uint16 GPIO143:1;                   // 15 Configuration lock commit bit for this pin
    Uint16 GPIO144:1;                   // 16 Configuration lock commit bit for this pin
    Uint16 GPIO145:1;                   // 17 Configuration lock commit bit for this pin
    Uint16 GPIO146:1;                   // 18 Configuration lock commit bit for this pin
    Uint16 GPIO147:1;                   // 19 Configuration lock commit bit for this pin
    Uint16 GPIO148:1;                   // 20 Configuration lock commit bit for this pin
    Uint16 GPIO149:1;                   // 21 Configuration lock commit bit for this pin
    Uint16 GPIO150:1;                   // 22 Configuration lock commit bit for this pin
    Uint16 GPIO151:1;                   // 23 Configuration lock commit bit for this pin
    Uint16 GPIO152:1;                   // 24 Configuration lock commit bit for this pin
    Uint16 GPIO153:1;                   // 25 Configuration lock commit bit for this pin
    Uint16 GPIO154:1;                   // 26 Configuration lock commit bit for this pin
    Uint16 GPIO155:1;                   // 27 Configuration lock commit bit for this pin
    Uint16 GPIO156:1;                   // 28 Configuration lock commit bit for this pin
    Uint16 GPIO157:1;                   // 29 Configuration lock commit bit for this pin
    Uint16 GPIO158:1;                   // 30 Configuration lock commit bit for this pin
    Uint16 GPIO159:1;                   // 31 Configuration lock commit bit for this pin
};

union GPECR_REG {
    Uint32  all;
    struct  GPECR_BITS  bit;
};

struct GPFCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO160 to GPIO167
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO168
    Uint16 rsvd1:8;                     // 23:16 Reserved
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union GPFCTRL_REG {
    Uint32  all;
    struct  GPFCTRL_BITS  bit;
};

struct GPFQSEL1_BITS {                  // bits description
    Uint16 GPIO160:2;                   // 1:0 Select input qualification type for GPIO160
    Uint16 GPIO161:2;                   // 3:2 Select input qualification type for GPIO161
    Uint16 GPIO162:2;                   // 5:4 Select input qualification type for GPIO162
    Uint16 GPIO163:2;                   // 7:6 Select input qualification type for GPIO163
    Uint16 GPIO164:2;                   // 9:8 Select input qualification type for GPIO164
    Uint16 GPIO165:2;                   // 11:10 Select input qualification type for GPIO165
    Uint16 GPIO166:2;                   // 13:12 Select input qualification type for GPIO166
    Uint16 GPIO167:2;                   // 15:14 Select input qualification type for GPIO167
    Uint16 GPIO168:2;                   // 17:16 Select input qualification type for GPIO168
    Uint16 rsvd1:2;                     // 19:18 Reserved
    Uint16 rsvd2:2;                     // 21:20 Reserved
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:2;                     // 27:26 Reserved
    Uint16 rsvd6:2;                     // 29:28 Reserved
    Uint16 rsvd7:2;                     // 31:30 Reserved
};

union GPFQSEL1_REG {
    Uint32  all;
    struct  GPFQSEL1_BITS  bit;
};

struct GPFMUX1_BITS {                   // bits description
    Uint16 GPIO160:2;                   // 1:0 Defines pin-muxing selection for GPIO160
    Uint16 GPIO161:2;                   // 3:2 Defines pin-muxing selection for GPIO161
    Uint16 GPIO162:2;                   // 5:4 Defines pin-muxing selection for GPIO162
    Uint16 GPIO163:2;                   // 7:6 Defines pin-muxing selection for GPIO163
    Uint16 GPIO164:2;                   // 9:8 Defines pin-muxing selection for GPIO164
    Uint16 GPIO165:2;                   // 11:10 Defines pin-muxing selection for GPIO165
    Uint16 GPIO166:2;                   // 13:12 Defines pin-muxing selection for GPIO166
    Uint16 GPIO167:2;                   // 15:14 Defines pin-muxing selection for GPIO167
    Uint16 GPIO168:2;                   // 17:16 Defines pin-muxing selection for GPIO168
    Uint16 rsvd1:2;                     // 19:18 Reserved
    Uint16 rsvd2:2;                     // 21:20 Reserved
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:2;                     // 27:26 Reserved
    Uint16 rsvd6:2;                     // 29:28 Reserved
    Uint16 rsvd7:2;                     // 31:30 Reserved
};

union GPFMUX1_REG {
    Uint32  all;
    struct  GPFMUX1_BITS  bit;
};

struct GPFDIR_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO161:1;                   // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO162:1;                   // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO163:1;                   // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO164:1;                   // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO165:1;                   // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO166:1;                   // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO167:1;                   // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO168:1;                   // 8 Defines direction for this pin in GPIO mode
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFDIR_REG {
    Uint32  all;
    struct  GPFDIR_BITS  bit;
};

struct GPFPUD_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Pull-Up Disable control for this pin
    Uint16 GPIO161:1;                   // 1 Pull-Up Disable control for this pin
    Uint16 GPIO162:1;                   // 2 Pull-Up Disable control for this pin
    Uint16 GPIO163:1;                   // 3 Pull-Up Disable control for this pin
    Uint16 GPIO164:1;                   // 4 Pull-Up Disable control for this pin
    Uint16 GPIO165:1;                   // 5 Pull-Up Disable control for this pin
    Uint16 GPIO166:1;                   // 6 Pull-Up Disable control for this pin
    Uint16 GPIO167:1;                   // 7 Pull-Up Disable control for this pin
    Uint16 GPIO168:1;                   // 8 Pull-Up Disable control for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFPUD_REG {
    Uint32  all;
    struct  GPFPUD_BITS  bit;
};

struct GPFINV_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Input inversion control for this pin
    Uint16 GPIO161:1;                   // 1 Input inversion control for this pin
    Uint16 GPIO162:1;                   // 2 Input inversion control for this pin
    Uint16 GPIO163:1;                   // 3 Input inversion control for this pin
    Uint16 GPIO164:1;                   // 4 Input inversion control for this pin
    Uint16 GPIO165:1;                   // 5 Input inversion control for this pin
    Uint16 GPIO166:1;                   // 6 Input inversion control for this pin
    Uint16 GPIO167:1;                   // 7 Input inversion control for this pin
    Uint16 GPIO168:1;                   // 8 Input inversion control for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFINV_REG {
    Uint32  all;
    struct  GPFINV_BITS  bit;
};

struct GPFODR_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO161:1;                   // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO162:1;                   // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO163:1;                   // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO164:1;                   // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO165:1;                   // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO166:1;                   // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO167:1;                   // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO168:1;                   // 8 Outpout Open-Drain control for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFODR_REG {
    Uint32  all;
    struct  GPFODR_BITS  bit;
};

struct GPFGMUX1_BITS {                  // bits description
    Uint16 GPIO160:2;                   // 1:0 Defines pin-muxing selection for GPIO160
    Uint16 GPIO161:2;                   // 3:2 Defines pin-muxing selection for GPIO161
    Uint16 GPIO162:2;                   // 5:4 Defines pin-muxing selection for GPIO162
    Uint16 GPIO163:2;                   // 7:6 Defines pin-muxing selection for GPIO163
    Uint16 GPIO164:2;                   // 9:8 Defines pin-muxing selection for GPIO164
    Uint16 GPIO165:2;                   // 11:10 Defines pin-muxing selection for GPIO165
    Uint16 GPIO166:2;                   // 13:12 Defines pin-muxing selection for GPIO166
    Uint16 GPIO167:2;                   // 15:14 Defines pin-muxing selection for GPIO167
    Uint16 GPIO168:2;                   // 17:16 Defines pin-muxing selection for GPIO168
    Uint16 rsvd1:2;                     // 19:18 Reserved
    Uint16 rsvd2:2;                     // 21:20 Reserved
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:2;                     // 27:26 Reserved
    Uint16 rsvd6:2;                     // 29:28 Reserved
    Uint16 rsvd7:2;                     // 31:30 Reserved
};

union GPFGMUX1_REG {
    Uint32  all;
    struct  GPFGMUX1_BITS  bit;
};

struct GPFCSEL1_BITS {                  // bits description
    Uint16 GPIO160:4;                   // 3:0 GPIO160 Master CPU Select
    Uint16 GPIO161:4;                   // 7:4 GPIO161 Master CPU Select
    Uint16 GPIO162:4;                   // 11:8 GPIO162 Master CPU Select
    Uint16 GPIO163:4;                   // 15:12 GPIO163 Master CPU Select
    Uint16 GPIO164:4;                   // 19:16 GPIO164 Master CPU Select
    Uint16 GPIO165:4;                   // 23:20 GPIO165 Master CPU Select
    Uint16 GPIO166:4;                   // 27:24 GPIO166 Master CPU Select
    Uint16 GPIO167:4;                   // 31:28 GPIO167 Master CPU Select
};

union GPFCSEL1_REG {
    Uint32  all;
    struct  GPFCSEL1_BITS  bit;
};

struct GPFCSEL2_BITS {                  // bits description
    Uint16 GPIO168:4;                   // 3:0 GPIO168 Master CPU Select
    Uint16 rsvd1:4;                     // 7:4 Reserved
    Uint16 rsvd2:4;                     // 11:8 Reserved
    Uint16 rsvd3:4;                     // 15:12 Reserved
    Uint16 rsvd4:4;                     // 19:16 Reserved
    Uint16 rsvd5:4;                     // 23:20 Reserved
    Uint16 rsvd6:4;                     // 27:24 Reserved
    Uint16 rsvd7:4;                     // 31:28 Reserved
};

union GPFCSEL2_REG {
    Uint32  all;
    struct  GPFCSEL2_BITS  bit;
};

struct GPFLOCK_BITS {                   // bits description
    Uint16 GPIO160:1;                   // 0 Configuration Lock bit for this pin
    Uint16 GPIO161:1;                   // 1 Configuration Lock bit for this pin
    Uint16 GPIO162:1;                   // 2 Configuration Lock bit for this pin
    Uint16 GPIO163:1;                   // 3 Configuration Lock bit for this pin
    Uint16 GPIO164:1;                   // 4 Configuration Lock bit for this pin
    Uint16 GPIO165:1;                   // 5 Configuration Lock bit for this pin
    Uint16 GPIO166:1;                   // 6 Configuration Lock bit for this pin
    Uint16 GPIO167:1;                   // 7 Configuration Lock bit for this pin
    Uint16 GPIO168:1;                   // 8 Configuration Lock bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFLOCK_REG {
    Uint32  all;
    struct  GPFLOCK_BITS  bit;
};

struct GPFCR_BITS {                     // bits description
    Uint16 GPIO160:1;                   // 0 Configuration lock commit bit for this pin
    Uint16 GPIO161:1;                   // 1 Configuration lock commit bit for this pin
    Uint16 GPIO162:1;                   // 2 Configuration lock commit bit for this pin
    Uint16 GPIO163:1;                   // 3 Configuration lock commit bit for this pin
    Uint16 GPIO164:1;                   // 4 Configuration lock commit bit for this pin
    Uint16 GPIO165:1;                   // 5 Configuration lock commit bit for this pin
    Uint16 GPIO166:1;                   // 6 Configuration lock commit bit for this pin
    Uint16 GPIO167:1;                   // 7 Configuration lock commit bit for this pin
    Uint16 GPIO168:1;                   // 8 Configuration lock commit bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFCR_REG {
    Uint32  all;
    struct  GPFCR_BITS  bit;
};

struct GPIO_CTRL_REGS {
    union   GPACTRL_REG                      GPACTRL;                      // GPIO A Qualification Sampling Period Control (GPIO0 to 31)
    union   GPAQSEL1_REG                     GPAQSEL1;                     // GPIO A Qualifier Select 1 Register (GPIO0 to 15)
    union   GPAQSEL2_REG                     GPAQSEL2;                     // GPIO A Qualifier Select 2 Register (GPIO16 to 31)
    union   GPAMUX1_REG                      GPAMUX1;                      // GPIO A Mux 1 Register (GPIO0 to 15)
    union   GPAMUX2_REG                      GPAMUX2;                      // GPIO A Mux 2 Register (GPIO16 to 31)
    union   GPADIR_REG                       GPADIR;                       // GPIO A Direction Register (GPIO0 to 31)
    union   GPAPUD_REG                       GPAPUD;                       // GPIO A Pull Up Disable Register (GPIO0 to 31) 
    Uint16                                   rsvd1[2];                     // Reserved
    union   GPAINV_REG                       GPAINV;                       // GPIO A Input Polarity Invert Registers (GPIO0 to 31)
    union   GPAODR_REG                       GPAODR;                       // GPIO A Open Drain Output Register (GPIO0 to GPIO31)
    Uint16                                   rsvd2[12];                    // Reserved
    union   GPAGMUX1_REG                     GPAGMUX1;                     // GPIO A Peripheral Group Mux (GPIO0 to 15)
    union   GPAGMUX2_REG                     GPAGMUX2;                     // GPIO A Peripheral Group Mux (GPIO16 to 31)
    Uint16                                   rsvd3[4];                     // Reserved
    union   GPACSEL1_REG                     GPACSEL1;                     // GPIO A Core Select Register (GPIO0 to 7)
    union   GPACSEL2_REG                     GPACSEL2;                     // GPIO A Core Select Register (GPIO8 to 15)
    union   GPACSEL3_REG                     GPACSEL3;                     // GPIO A Core Select Register (GPIO16 to 23)
    union   GPACSEL4_REG                     GPACSEL4;                     // GPIO A Core Select Register (GPIO24 to 31)
    Uint16                                   rsvd4[12];                    // Reserved
    union   GPALOCK_REG                      GPALOCK;                      // GPIO A Lock Configuration Register (GPIO0 to 31)
    union   GPACR_REG                        GPACR;                        // GPIO A Lock Commit Register (GPIO0 to 31)
    union   GPBCTRL_REG                      GPBCTRL;                      // GPIO B Qualification Sampling Period Control (GPIO32 to 63)
    union   GPBQSEL1_REG                     GPBQSEL1;                     // GPIO B Qualifier Select 1 Register (GPIO32 to 47)
    union   GPBQSEL2_REG                     GPBQSEL2;                     // GPIO B Qualifier Select 2 Register (GPIO48 to 63)
    union   GPBMUX1_REG                      GPBMUX1;                      // GPIO B Mux 1 Register (GPIO32 to 47)
    union   GPBMUX2_REG                      GPBMUX2;                      // GPIO B Mux 2 Register (GPIO48 to 63)
    union   GPBDIR_REG                       GPBDIR;                       // GPIO B Direction Register (GPIO32 to 63)
    union   GPBPUD_REG                       GPBPUD;                       // GPIO B Pull Up Disable Register (GPIO32 to 63) 
    Uint16                                   rsvd5[2];                     // Reserved
    union   GPBINV_REG                       GPBINV;                       // GPIO B Input Polarity Invert Registers (GPIO32 to 63)
    union   GPBODR_REG                       GPBODR;                       // GPIO B Open Drain Output Register (GPIO32 to GPIO63)
    union   GPBAMSEL_REG                     GPBAMSEL;                     // GPIO B Analog Mode Select register (GPIO32 to GPIO63)
    Uint16                                   rsvd6[10];                    // Reserved
    union   GPBGMUX1_REG                     GPBGMUX1;                     // GPIO B Peripheral Group Mux (GPIO32 to 47)
    union   GPBGMUX2_REG                     GPBGMUX2;                     // GPIO B Peripheral Group Mux (GPIO48 to 63)
    Uint16                                   rsvd7[4];                     // Reserved
    union   GPBCSEL1_REG                     GPBCSEL1;                     // GPIO B Core Select Register (GPIO32 to 39)
    union   GPBCSEL2_REG                     GPBCSEL2;                     // GPIO B Core Select Register (GPIO40 to 47)
    union   GPBCSEL3_REG                     GPBCSEL3;                     // GPIO B Core Select Register (GPIO48 to 55)
    union   GPBCSEL4_REG                     GPBCSEL4;                     // GPIO B Core Select Register (GPIO56 to 63)
    Uint16                                   rsvd8[12];                    // Reserved
    union   GPBLOCK_REG                      GPBLOCK;                      // GPIO B Lock Configuration Register (GPIO32 to 63)
    union   GPBCR_REG                        GPBCR;                        // GPIO B Lock Commit Register (GPIO32 to 63)
    union   GPCCTRL_REG                      GPCCTRL;                      // GPIO C Qualification Sampling Period Control (GPIO64 to 95)
    union   GPCQSEL1_REG                     GPCQSEL1;                     // GPIO C Qualifier Select 1 Register (GPIO64 to 79)
    union   GPCQSEL2_REG                     GPCQSEL2;                     // GPIO C Qualifier Select 2 Register (GPIO80  to 95)
    union   GPCMUX1_REG                      GPCMUX1;                      // GPIO C Mux 1 Register (GPIO64 to 79)
    union   GPCMUX2_REG                      GPCMUX2;                      // GPIO C Mux 2 Register (GPIO80  to 95)
    union   GPCDIR_REG                       GPCDIR;                       // GPIO C Direction Register (GPIO64 to 95)
    union   GPCPUD_REG                       GPCPUD;                       // GPIO C Pull Up Disable Register (GPIO64 to 95) 
    Uint16                                   rsvd9[2];                     // Reserved
    union   GPCINV_REG                       GPCINV;                       // GPIO C Input Polarity Invert Registers (GPIO64 to 95)
    union   GPCODR_REG                       GPCODR;                       // GPIO C Open Drain Output Register (GPIO64 to GPIO95)
    Uint16                                   rsvd10[12];                   // Reserved
    union   GPCGMUX1_REG                     GPCGMUX1;                     // GPIO C Peripheral Group Mux (GPIO64 to 79)
    union   GPCGMUX2_REG                     GPCGMUX2;                     // GPIO C Peripheral Group Mux (GPIO80  to 95)
    Uint16                                   rsvd11[4];                    // Reserved
    union   GPCCSEL1_REG                     GPCCSEL1;                     // GPIO C Core Select Register (GPIO64 to 71)
    union   GPCCSEL2_REG                     GPCCSEL2;                     // GPIO C Core Select Register (GPIO72 to 79)
    union   GPCCSEL3_REG                     GPCCSEL3;                     // GPIO C Core Select Register (GPIO80  to 87)
    union   GPCCSEL4_REG                     GPCCSEL4;                     // GPIO C Core Select Register (GPIO88 to 95)
    Uint16                                   rsvd12[12];                   // Reserved
    union   GPCLOCK_REG                      GPCLOCK;                      // GPIO C Lock Configuration Register (GPIO64 to 95)
    union   GPCCR_REG                        GPCCR;                        // GPIO C Lock Commit Register (GPIO64 to 95)
    union   GPDCTRL_REG                      GPDCTRL;                      // GPIO D Qualification Sampling Period Control (GPIO96 to 127)
    union   GPDQSEL1_REG                     GPDQSEL1;                     // GPIO D Qualifier Select 1 Register (GPIO96 to 111)
    union   GPDQSEL2_REG                     GPDQSEL2;                     // GPIO D Qualifier Select 2 Register (GPIO112 to 127)
    union   GPDMUX1_REG                      GPDMUX1;                      // GPIO D Mux 1 Register (GPIO96 to 111)
    union   GPDMUX2_REG                      GPDMUX2;                      // GPIO D Mux 2 Register (GPIO112 to 127)
    union   GPDDIR_REG                       GPDDIR;                       // GPIO D Direction Register (GPIO96 to 127)
    union   GPDPUD_REG                       GPDPUD;                       // GPIO D Pull Up Disable Register (GPIO96 to 127) 
    Uint16                                   rsvd13[2];                    // Reserved
    union   GPDINV_REG                       GPDINV;                       // GPIO D Input Polarity Invert Registers (GPIO96 to 127)
    union   GPDODR_REG                       GPDODR;                       // GPIO D Open Drain Output Register (GPIO96 to GPIO127)
    Uint16                                   rsvd14[12];                   // Reserved
    union   GPDGMUX1_REG                     GPDGMUX1;                     // GPIO D Peripheral Group Mux (GPIO96 to 111)
    union   GPDGMUX2_REG                     GPDGMUX2;                     // GPIO D Peripheral Group Mux (GPIO112 to 127)
    Uint16                                   rsvd15[4];                    // Reserved
    union   GPDCSEL1_REG                     GPDCSEL1;                     // GPIO D Core Select Register (GPIO96 to 103)
    union   GPDCSEL2_REG                     GPDCSEL2;                     // GPIO D Core Select Register (GPIO104 to 111)
    union   GPDCSEL3_REG                     GPDCSEL3;                     // GPIO D Core Select Register (GPIO112 to 119)
    union   GPDCSEL4_REG                     GPDCSEL4;                     // GPIO D Core Select Register (GPIO120 to 127)
    Uint16                                   rsvd16[12];                   // Reserved
    union   GPDLOCK_REG                      GPDLOCK;                      // GPIO D Lock Configuration Register (GPIO96 to 127)
    union   GPDCR_REG                        GPDCR;                        // GPIO D Lock Commit Register (GPIO96 to 127)
    union   GPECTRL_REG                      GPECTRL;                      // GPIO E Qualification Sampling Period Control (GPIO128 to 159)
    union   GPEQSEL1_REG                     GPEQSEL1;                     // GPIO E Qualifier Select 1 Register (GPIO128 to 143)
    union   GPEQSEL2_REG                     GPEQSEL2;                     // GPIO E Qualifier Select 2 Register (GPIO144  to 159)
    union   GPEMUX1_REG                      GPEMUX1;                      // GPIO E Mux 1 Register (GPIO128 to 143)
    union   GPEMUX2_REG                      GPEMUX2;                      // GPIO E Mux 2 Register (GPIO144  to 159)
    union   GPEDIR_REG                       GPEDIR;                       // GPIO E Direction Register (GPIO128 to 159)
    union   GPEPUD_REG                       GPEPUD;                       // GPIO E Pull Up Disable Register (GPIO128 to 159) 
    Uint16                                   rsvd17[2];                    // Reserved
    union   GPEINV_REG                       GPEINV;                       // GPIO E Input Polarity Invert Registers (GPIO128 to 159)
    union   GPEODR_REG                       GPEODR;                       // GPIO E Open Drain Output Register (GPIO128 to GPIO159)
    Uint16                                   rsvd18[12];                   // Reserved
    union   GPEGMUX1_REG                     GPEGMUX1;                     // GPIO E Peripheral Group Mux (GPIO128 to 143)
    union   GPEGMUX2_REG                     GPEGMUX2;                     // GPIO E Peripheral Group Mux (GPIO144  to 159)
    Uint16                                   rsvd19[4];                    // Reserved
    union   GPECSEL1_REG                     GPECSEL1;                     // GPIO E Core Select Register (GPIO128 to 135)
    union   GPECSEL2_REG                     GPECSEL2;                     // GPIO E Core Select Register (GPIO136 to 143)
    union   GPECSEL3_REG                     GPECSEL3;                     // GPIO E Core Select Register (GPIO144  to 151)
    union   GPECSEL4_REG                     GPECSEL4;                     // GPIO E Core Select Register (GPIO152 to 159)
    Uint16                                   rsvd20[12];                   // Reserved
    union   GPELOCK_REG                      GPELOCK;                      // GPIO E Lock Configuration Register (GPIO128 to 159)
    union   GPECR_REG                        GPECR;                        // GPIO E Lock Commit Register (GPIO128 to 159)
    union   GPFCTRL_REG                      GPFCTRL;                      // GPIO F Qualification Sampling Period Control (GPIO160 to 168)
    union   GPFQSEL1_REG                     GPFQSEL1;                     // GPIO F Qualifier Select 1 Register (GPIO160 to 168)
    Uint16                                   rsvd21[2];                    // Reserved
    union   GPFMUX1_REG                      GPFMUX1;                      // GPIO F Mux 1 Register (GPIO160 to 168)
    Uint16                                   rsvd22[2];                    // Reserved
    union   GPFDIR_REG                       GPFDIR;                       // GPIO F Direction Register (GPIO160 to 168)
    union   GPFPUD_REG                       GPFPUD;                       // GPIO F Pull Up Disable Register (GPIO160 to 168) 
    Uint16                                   rsvd23[2];                    // Reserved
    union   GPFINV_REG                       GPFINV;                       // GPIO F Input Polarity Invert Registers (GPIO160 to 168)
    union   GPFODR_REG                       GPFODR;                       // GPIO F Open Drain Output Register (GPIO160 to GPIO168)
    Uint16                                   rsvd24[12];                   // Reserved
    union   GPFGMUX1_REG                     GPFGMUX1;                     // GPIO F Peripheral Group Mux (GPIO160 to 168)
    Uint16                                   rsvd25[6];                    // Reserved
    union   GPFCSEL1_REG                     GPFCSEL1;                     // GPIO F Core Select Register (GPIO160 to 167)
    union   GPFCSEL2_REG                     GPFCSEL2;                     // GPIO F Core Select Register (GPIO168)
    Uint16                                   rsvd26[16];                   // Reserved
    union   GPFLOCK_REG                      GPFLOCK;                      // GPIO F Lock Configuration Register (GPIO160 to 168)
    union   GPFCR_REG                        GPFCR;                        // GPIO F Lock Commit Register (GPIO160 to 168)
};

struct GPADAT_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Data Register for this pin
    Uint16 GPIO1:1;                     // 1 Data Register for this pin
    Uint16 GPIO2:1;                     // 2 Data Register for this pin
    Uint16 GPIO3:1;                     // 3 Data Register for this pin
    Uint16 GPIO4:1;                     // 4 Data Register for this pin
    Uint16 GPIO5:1;                     // 5 Data Register for this pin
    Uint16 GPIO6:1;                     // 6 Data Register for this pin
    Uint16 GPIO7:1;                     // 7 Data Register for this pin
    Uint16 GPIO8:1;                     // 8 Data Register for this pin
    Uint16 GPIO9:1;                     // 9 Data Register for this pin
    Uint16 GPIO10:1;                    // 10 Data Register for this pin
    Uint16 GPIO11:1;                    // 11 Data Register for this pin
    Uint16 GPIO12:1;                    // 12 Data Register for this pin
    Uint16 GPIO13:1;                    // 13 Data Register for this pin
    Uint16 GPIO14:1;                    // 14 Data Register for this pin
    Uint16 GPIO15:1;                    // 15 Data Register for this pin
    Uint16 GPIO16:1;                    // 16 Data Register for this pin
    Uint16 GPIO17:1;                    // 17 Data Register for this pin
    Uint16 GPIO18:1;                    // 18 Data Register for this pin
    Uint16 GPIO19:1;                    // 19 Data Register for this pin
    Uint16 GPIO20:1;                    // 20 Data Register for this pin
    Uint16 GPIO21:1;                    // 21 Data Register for this pin
    Uint16 GPIO22:1;                    // 22 Data Register for this pin
    Uint16 GPIO23:1;                    // 23 Data Register for this pin
    Uint16 GPIO24:1;                    // 24 Data Register for this pin
    Uint16 GPIO25:1;                    // 25 Data Register for this pin
    Uint16 GPIO26:1;                    // 26 Data Register for this pin
    Uint16 GPIO27:1;                    // 27 Data Register for this pin
    Uint16 GPIO28:1;                    // 28 Data Register for this pin
    Uint16 GPIO29:1;                    // 29 Data Register for this pin
    Uint16 GPIO30:1;                    // 30 Data Register for this pin
    Uint16 GPIO31:1;                    // 31 Data Register for this pin
};

union GPADAT_REG {
    Uint32  all;
    struct  GPADAT_BITS  bit;
};

struct GPASET_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Output Set bit for this pin
    Uint16 GPIO1:1;                     // 1 Output Set bit for this pin
    Uint16 GPIO2:1;                     // 2 Output Set bit for this pin
    Uint16 GPIO3:1;                     // 3 Output Set bit for this pin
    Uint16 GPIO4:1;                     // 4 Output Set bit for this pin
    Uint16 GPIO5:1;                     // 5 Output Set bit for this pin
    Uint16 GPIO6:1;                     // 6 Output Set bit for this pin
    Uint16 GPIO7:1;                     // 7 Output Set bit for this pin
    Uint16 GPIO8:1;                     // 8 Output Set bit for this pin
    Uint16 GPIO9:1;                     // 9 Output Set bit for this pin
    Uint16 GPIO10:1;                    // 10 Output Set bit for this pin
    Uint16 GPIO11:1;                    // 11 Output Set bit for this pin
    Uint16 GPIO12:1;                    // 12 Output Set bit for this pin
    Uint16 GPIO13:1;                    // 13 Output Set bit for this pin
    Uint16 GPIO14:1;                    // 14 Output Set bit for this pin
    Uint16 GPIO15:1;                    // 15 Output Set bit for this pin
    Uint16 GPIO16:1;                    // 16 Output Set bit for this pin
    Uint16 GPIO17:1;                    // 17 Output Set bit for this pin
    Uint16 GPIO18:1;                    // 18 Output Set bit for this pin
    Uint16 GPIO19:1;                    // 19 Output Set bit for this pin
    Uint16 GPIO20:1;                    // 20 Output Set bit for this pin
    Uint16 GPIO21:1;                    // 21 Output Set bit for this pin
    Uint16 GPIO22:1;                    // 22 Output Set bit for this pin
    Uint16 GPIO23:1;                    // 23 Output Set bit for this pin
    Uint16 GPIO24:1;                    // 24 Output Set bit for this pin
    Uint16 GPIO25:1;                    // 25 Output Set bit for this pin
    Uint16 GPIO26:1;                    // 26 Output Set bit for this pin
    Uint16 GPIO27:1;                    // 27 Output Set bit for this pin
    Uint16 GPIO28:1;                    // 28 Output Set bit for this pin
    Uint16 GPIO29:1;                    // 29 Output Set bit for this pin
    Uint16 GPIO30:1;                    // 30 Output Set bit for this pin
    Uint16 GPIO31:1;                    // 31 Output Set bit for this pin
};

union GPASET_REG {
    Uint32  all;
    struct  GPASET_BITS  bit;
};

struct GPACLEAR_BITS {                  // bits description
    Uint16 GPIO0:1;                     // 0 Output Clear bit for this pin
    Uint16 GPIO1:1;                     // 1 Output Clear bit for this pin
    Uint16 GPIO2:1;                     // 2 Output Clear bit for this pin
    Uint16 GPIO3:1;                     // 3 Output Clear bit for this pin
    Uint16 GPIO4:1;                     // 4 Output Clear bit for this pin
    Uint16 GPIO5:1;                     // 5 Output Clear bit for this pin
    Uint16 GPIO6:1;                     // 6 Output Clear bit for this pin
    Uint16 GPIO7:1;                     // 7 Output Clear bit for this pin
    Uint16 GPIO8:1;                     // 8 Output Clear bit for this pin
    Uint16 GPIO9:1;                     // 9 Output Clear bit for this pin
    Uint16 GPIO10:1;                    // 10 Output Clear bit for this pin
    Uint16 GPIO11:1;                    // 11 Output Clear bit for this pin
    Uint16 GPIO12:1;                    // 12 Output Clear bit for this pin
    Uint16 GPIO13:1;                    // 13 Output Clear bit for this pin
    Uint16 GPIO14:1;                    // 14 Output Clear bit for this pin
    Uint16 GPIO15:1;                    // 15 Output Clear bit for this pin
    Uint16 GPIO16:1;                    // 16 Output Clear bit for this pin
    Uint16 GPIO17:1;                    // 17 Output Clear bit for this pin
    Uint16 GPIO18:1;                    // 18 Output Clear bit for this pin
    Uint16 GPIO19:1;                    // 19 Output Clear bit for this pin
    Uint16 GPIO20:1;                    // 20 Output Clear bit for this pin
    Uint16 GPIO21:1;                    // 21 Output Clear bit for this pin
    Uint16 GPIO22:1;                    // 22 Output Clear bit for this pin
    Uint16 GPIO23:1;                    // 23 Output Clear bit for this pin
    Uint16 GPIO24:1;                    // 24 Output Clear bit for this pin
    Uint16 GPIO25:1;                    // 25 Output Clear bit for this pin
    Uint16 GPIO26:1;                    // 26 Output Clear bit for this pin
    Uint16 GPIO27:1;                    // 27 Output Clear bit for this pin
    Uint16 GPIO28:1;                    // 28 Output Clear bit for this pin
    Uint16 GPIO29:1;                    // 29 Output Clear bit for this pin
    Uint16 GPIO30:1;                    // 30 Output Clear bit for this pin
    Uint16 GPIO31:1;                    // 31 Output Clear bit for this pin
};

union GPACLEAR_REG {
    Uint32  all;
    struct  GPACLEAR_BITS  bit;
};

struct GPATOGGLE_BITS {                 // bits description
    Uint16 GPIO0:1;                     // 0 Output Toggle bit for this pin
    Uint16 GPIO1:1;                     // 1 Output Toggle bit for this pin
    Uint16 GPIO2:1;                     // 2 Output Toggle bit for this pin
    Uint16 GPIO3:1;                     // 3 Output Toggle bit for this pin
    Uint16 GPIO4:1;                     // 4 Output Toggle bit for this pin
    Uint16 GPIO5:1;                     // 5 Output Toggle bit for this pin
    Uint16 GPIO6:1;                     // 6 Output Toggle bit for this pin
    Uint16 GPIO7:1;                     // 7 Output Toggle bit for this pin
    Uint16 GPIO8:1;                     // 8 Output Toggle bit for this pin
    Uint16 GPIO9:1;                     // 9 Output Toggle bit for this pin
    Uint16 GPIO10:1;                    // 10 Output Toggle bit for this pin
    Uint16 GPIO11:1;                    // 11 Output Toggle bit for this pin
    Uint16 GPIO12:1;                    // 12 Output Toggle bit for this pin
    Uint16 GPIO13:1;                    // 13 Output Toggle bit for this pin
    Uint16 GPIO14:1;                    // 14 Output Toggle bit for this pin
    Uint16 GPIO15:1;                    // 15 Output Toggle bit for this pin
    Uint16 GPIO16:1;                    // 16 Output Toggle bit for this pin
    Uint16 GPIO17:1;                    // 17 Output Toggle bit for this pin
    Uint16 GPIO18:1;                    // 18 Output Toggle bit for this pin
    Uint16 GPIO19:1;                    // 19 Output Toggle bit for this pin
    Uint16 GPIO20:1;                    // 20 Output Toggle bit for this pin
    Uint16 GPIO21:1;                    // 21 Output Toggle bit for this pin
    Uint16 GPIO22:1;                    // 22 Output Toggle bit for this pin
    Uint16 GPIO23:1;                    // 23 Output Toggle bit for this pin
    Uint16 GPIO24:1;                    // 24 Output Toggle bit for this pin
    Uint16 GPIO25:1;                    // 25 Output Toggle bit for this pin
    Uint16 GPIO26:1;                    // 26 Output Toggle bit for this pin
    Uint16 GPIO27:1;                    // 27 Output Toggle bit for this pin
    Uint16 GPIO28:1;                    // 28 Output Toggle bit for this pin
    Uint16 GPIO29:1;                    // 29 Output Toggle bit for this pin
    Uint16 GPIO30:1;                    // 30 Output Toggle bit for this pin
    Uint16 GPIO31:1;                    // 31 Output Toggle bit for this pin
};

union GPATOGGLE_REG {
    Uint32  all;
    struct  GPATOGGLE_BITS  bit;
};

struct GPBDAT_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Data Register for this pin
    Uint16 GPIO33:1;                    // 1 Data Register for this pin
    Uint16 GPIO34:1;                    // 2 Data Register for this pin
    Uint16 GPIO35:1;                    // 3 Data Register for this pin
    Uint16 GPIO36:1;                    // 4 Data Register for this pin
    Uint16 GPIO37:1;                    // 5 Data Register for this pin
    Uint16 GPIO38:1;                    // 6 Data Register for this pin
    Uint16 GPIO39:1;                    // 7 Data Register for this pin
    Uint16 GPIO40:1;                    // 8 Data Register for this pin
    Uint16 GPIO41:1;                    // 9 Data Register for this pin
    Uint16 GPIO42:1;                    // 10 Data Register for this pin
    Uint16 GPIO43:1;                    // 11 Data Register for this pin
    Uint16 GPIO44:1;                    // 12 Data Register for this pin
    Uint16 GPIO45:1;                    // 13 Data Register for this pin
    Uint16 GPIO46:1;                    // 14 Data Register for this pin
    Uint16 GPIO47:1;                    // 15 Data Register for this pin
    Uint16 GPIO48:1;                    // 16 Data Register for this pin
    Uint16 GPIO49:1;                    // 17 Data Register for this pin
    Uint16 GPIO50:1;                    // 18 Data Register for this pin
    Uint16 GPIO51:1;                    // 19 Data Register for this pin
    Uint16 GPIO52:1;                    // 20 Data Register for this pin
    Uint16 GPIO53:1;                    // 21 Data Register for this pin
    Uint16 GPIO54:1;                    // 22 Data Register for this pin
    Uint16 GPIO55:1;                    // 23 Data Register for this pin
    Uint16 GPIO56:1;                    // 24 Data Register for this pin
    Uint16 GPIO57:1;                    // 25 Data Register for this pin
    Uint16 GPIO58:1;                    // 26 Data Register for this pin
    Uint16 GPIO59:1;                    // 27 Data Register for this pin
    Uint16 GPIO60:1;                    // 28 Data Register for this pin
    Uint16 GPIO61:1;                    // 29 Data Register for this pin
    Uint16 GPIO62:1;                    // 30 Data Register for this pin
    Uint16 GPIO63:1;                    // 31 Data Register for this pin
};

union GPBDAT_REG {
    Uint32  all;
    struct  GPBDAT_BITS  bit;
};

struct GPBSET_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Output Set bit for this pin
    Uint16 GPIO33:1;                    // 1 Output Set bit for this pin
    Uint16 GPIO34:1;                    // 2 Output Set bit for this pin
    Uint16 GPIO35:1;                    // 3 Output Set bit for this pin
    Uint16 GPIO36:1;                    // 4 Output Set bit for this pin
    Uint16 GPIO37:1;                    // 5 Output Set bit for this pin
    Uint16 GPIO38:1;                    // 6 Output Set bit for this pin
    Uint16 GPIO39:1;                    // 7 Output Set bit for this pin
    Uint16 GPIO40:1;                    // 8 Output Set bit for this pin
    Uint16 GPIO41:1;                    // 9 Output Set bit for this pin
    Uint16 GPIO42:1;                    // 10 Output Set bit for this pin
    Uint16 GPIO43:1;                    // 11 Output Set bit for this pin
    Uint16 GPIO44:1;                    // 12 Output Set bit for this pin
    Uint16 GPIO45:1;                    // 13 Output Set bit for this pin
    Uint16 GPIO46:1;                    // 14 Output Set bit for this pin
    Uint16 GPIO47:1;                    // 15 Output Set bit for this pin
    Uint16 GPIO48:1;                    // 16 Output Set bit for this pin
    Uint16 GPIO49:1;                    // 17 Output Set bit for this pin
    Uint16 GPIO50:1;                    // 18 Output Set bit for this pin
    Uint16 GPIO51:1;                    // 19 Output Set bit for this pin
    Uint16 GPIO52:1;                    // 20 Output Set bit for this pin
    Uint16 GPIO53:1;                    // 21 Output Set bit for this pin
    Uint16 GPIO54:1;                    // 22 Output Set bit for this pin
    Uint16 GPIO55:1;                    // 23 Output Set bit for this pin
    Uint16 GPIO56:1;                    // 24 Output Set bit for this pin
    Uint16 GPIO57:1;                    // 25 Output Set bit for this pin
    Uint16 GPIO58:1;                    // 26 Output Set bit for this pin
    Uint16 GPIO59:1;                    // 27 Output Set bit for this pin
    Uint16 GPIO60:1;                    // 28 Output Set bit for this pin
    Uint16 GPIO61:1;                    // 29 Output Set bit for this pin
    Uint16 GPIO62:1;                    // 30 Output Set bit for this pin
    Uint16 GPIO63:1;                    // 31 Output Set bit for this pin
};

union GPBSET_REG {
    Uint32  all;
    struct  GPBSET_BITS  bit;
};

struct GPBCLEAR_BITS {                  // bits description
    Uint16 GPIO32:1;                    // 0 Output Clear bit for this pin
    Uint16 GPIO33:1;                    // 1 Output Clear bit for this pin
    Uint16 GPIO34:1;                    // 2 Output Clear bit for this pin
    Uint16 GPIO35:1;                    // 3 Output Clear bit for this pin
    Uint16 GPIO36:1;                    // 4 Output Clear bit for this pin
    Uint16 GPIO37:1;                    // 5 Output Clear bit for this pin
    Uint16 GPIO38:1;                    // 6 Output Clear bit for this pin
    Uint16 GPIO39:1;                    // 7 Output Clear bit for this pin
    Uint16 GPIO40:1;                    // 8 Output Clear bit for this pin
    Uint16 GPIO41:1;                    // 9 Output Clear bit for this pin
    Uint16 GPIO42:1;                    // 10 Output Clear bit for this pin
    Uint16 GPIO43:1;                    // 11 Output Clear bit for this pin
    Uint16 GPIO44:1;                    // 12 Output Clear bit for this pin
    Uint16 GPIO45:1;                    // 13 Output Clear bit for this pin
    Uint16 GPIO46:1;                    // 14 Output Clear bit for this pin
    Uint16 GPIO47:1;                    // 15 Output Clear bit for this pin
    Uint16 GPIO48:1;                    // 16 Output Clear bit for this pin
    Uint16 GPIO49:1;                    // 17 Output Clear bit for this pin
    Uint16 GPIO50:1;                    // 18 Output Clear bit for this pin
    Uint16 GPIO51:1;                    // 19 Output Clear bit for this pin
    Uint16 GPIO52:1;                    // 20 Output Clear bit for this pin
    Uint16 GPIO53:1;                    // 21 Output Clear bit for this pin
    Uint16 GPIO54:1;                    // 22 Output Clear bit for this pin
    Uint16 GPIO55:1;                    // 23 Output Clear bit for this pin
    Uint16 GPIO56:1;                    // 24 Output Clear bit for this pin
    Uint16 GPIO57:1;                    // 25 Output Clear bit for this pin
    Uint16 GPIO58:1;                    // 26 Output Clear bit for this pin
    Uint16 GPIO59:1;                    // 27 Output Clear bit for this pin
    Uint16 GPIO60:1;                    // 28 Output Clear bit for this pin
    Uint16 GPIO61:1;                    // 29 Output Clear bit for this pin
    Uint16 GPIO62:1;                    // 30 Output Clear bit for this pin
    Uint16 GPIO63:1;                    // 31 Output Clear bit for this pin
};

union GPBCLEAR_REG {
    Uint32  all;
    struct  GPBCLEAR_BITS  bit;
};

struct GPBTOGGLE_BITS {                 // bits description
    Uint16 GPIO32:1;                    // 0 Output Toggle bit for this pin
    Uint16 GPIO33:1;                    // 1 Output Toggle bit for this pin
    Uint16 GPIO34:1;                    // 2 Output Toggle bit for this pin
    Uint16 GPIO35:1;                    // 3 Output Toggle bit for this pin
    Uint16 GPIO36:1;                    // 4 Output Toggle bit for this pin
    Uint16 GPIO37:1;                    // 5 Output Toggle bit for this pin
    Uint16 GPIO38:1;                    // 6 Output Toggle bit for this pin
    Uint16 GPIO39:1;                    // 7 Output Toggle bit for this pin
    Uint16 GPIO40:1;                    // 8 Output Toggle bit for this pin
    Uint16 GPIO41:1;                    // 9 Output Toggle bit for this pin
    Uint16 GPIO42:1;                    // 10 Output Toggle bit for this pin
    Uint16 GPIO43:1;                    // 11 Output Toggle bit for this pin
    Uint16 GPIO44:1;                    // 12 Output Toggle bit for this pin
    Uint16 GPIO45:1;                    // 13 Output Toggle bit for this pin
    Uint16 GPIO46:1;                    // 14 Output Toggle bit for this pin
    Uint16 GPIO47:1;                    // 15 Output Toggle bit for this pin
    Uint16 GPIO48:1;                    // 16 Output Toggle bit for this pin
    Uint16 GPIO49:1;                    // 17 Output Toggle bit for this pin
    Uint16 GPIO50:1;                    // 18 Output Toggle bit for this pin
    Uint16 GPIO51:1;                    // 19 Output Toggle bit for this pin
    Uint16 GPIO52:1;                    // 20 Output Toggle bit for this pin
    Uint16 GPIO53:1;                    // 21 Output Toggle bit for this pin
    Uint16 GPIO54:1;                    // 22 Output Toggle bit for this pin
    Uint16 GPIO55:1;                    // 23 Output Toggle bit for this pin
    Uint16 GPIO56:1;                    // 24 Output Toggle bit for this pin
    Uint16 GPIO57:1;                    // 25 Output Toggle bit for this pin
    Uint16 GPIO58:1;                    // 26 Output Toggle bit for this pin
    Uint16 GPIO59:1;                    // 27 Output Toggle bit for this pin
    Uint16 GPIO60:1;                    // 28 Output Toggle bit for this pin
    Uint16 GPIO61:1;                    // 29 Output Toggle bit for this pin
    Uint16 GPIO62:1;                    // 30 Output Toggle bit for this pin
    Uint16 GPIO63:1;                    // 31 Output Toggle bit for this pin
};

union GPBTOGGLE_REG {
    Uint32  all;
    struct  GPBTOGGLE_BITS  bit;
};

struct GPCDAT_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Data Register for this pin
    Uint16 GPIO65:1;                    // 1 Data Register for this pin
    Uint16 GPIO66:1;                    // 2 Data Register for this pin
    Uint16 GPIO67:1;                    // 3 Data Register for this pin
    Uint16 GPIO68:1;                    // 4 Data Register for this pin
    Uint16 GPIO69:1;                    // 5 Data Register for this pin
    Uint16 GPIO70:1;                    // 6 Data Register for this pin
    Uint16 GPIO71:1;                    // 7 Data Register for this pin
    Uint16 GPIO72:1;                    // 8 Data Register for this pin
    Uint16 GPIO73:1;                    // 9 Data Register for this pin
    Uint16 GPIO74:1;                    // 10 Data Register for this pin
    Uint16 GPIO75:1;                    // 11 Data Register for this pin
    Uint16 GPIO76:1;                    // 12 Data Register for this pin
    Uint16 GPIO77:1;                    // 13 Data Register for this pin
    Uint16 GPIO78:1;                    // 14 Data Register for this pin
    Uint16 GPIO79:1;                    // 15 Data Register for this pin
    Uint16 GPIO80:1;                    // 16 Data Register for this pin
    Uint16 GPIO81:1;                    // 17 Data Register for this pin
    Uint16 GPIO82:1;                    // 18 Data Register for this pin
    Uint16 GPIO83:1;                    // 19 Data Register for this pin
    Uint16 GPIO84:1;                    // 20 Data Register for this pin
    Uint16 GPIO85:1;                    // 21 Data Register for this pin
    Uint16 GPIO86:1;                    // 22 Data Register for this pin
    Uint16 GPIO87:1;                    // 23 Data Register for this pin
    Uint16 GPIO88:1;                    // 24 Data Register for this pin
    Uint16 GPIO89:1;                    // 25 Data Register for this pin
    Uint16 GPIO90:1;                    // 26 Data Register for this pin
    Uint16 GPIO91:1;                    // 27 Data Register for this pin
    Uint16 GPIO92:1;                    // 28 Data Register for this pin
    Uint16 GPIO93:1;                    // 29 Data Register for this pin
    Uint16 GPIO94:1;                    // 30 Data Register for this pin
    Uint16 GPIO95:1;                    // 31 Data Register for this pin
};

union GPCDAT_REG {
    Uint32  all;
    struct  GPCDAT_BITS  bit;
};

struct GPCSET_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Output Set bit for this pin
    Uint16 GPIO65:1;                    // 1 Output Set bit for this pin
    Uint16 GPIO66:1;                    // 2 Output Set bit for this pin
    Uint16 GPIO67:1;                    // 3 Output Set bit for this pin
    Uint16 GPIO68:1;                    // 4 Output Set bit for this pin
    Uint16 GPIO69:1;                    // 5 Output Set bit for this pin
    Uint16 GPIO70:1;                    // 6 Output Set bit for this pin
    Uint16 GPIO71:1;                    // 7 Output Set bit for this pin
    Uint16 GPIO72:1;                    // 8 Output Set bit for this pin
    Uint16 GPIO73:1;                    // 9 Output Set bit for this pin
    Uint16 GPIO74:1;                    // 10 Output Set bit for this pin
    Uint16 GPIO75:1;                    // 11 Output Set bit for this pin
    Uint16 GPIO76:1;                    // 12 Output Set bit for this pin
    Uint16 GPIO77:1;                    // 13 Output Set bit for this pin
    Uint16 GPIO78:1;                    // 14 Output Set bit for this pin
    Uint16 GPIO79:1;                    // 15 Output Set bit for this pin
    Uint16 GPIO80:1;                    // 16 Output Set bit for this pin
    Uint16 GPIO81:1;                    // 17 Output Set bit for this pin
    Uint16 GPIO82:1;                    // 18 Output Set bit for this pin
    Uint16 GPIO83:1;                    // 19 Output Set bit for this pin
    Uint16 GPIO84:1;                    // 20 Output Set bit for this pin
    Uint16 GPIO85:1;                    // 21 Output Set bit for this pin
    Uint16 GPIO86:1;                    // 22 Output Set bit for this pin
    Uint16 GPIO87:1;                    // 23 Output Set bit for this pin
    Uint16 GPIO88:1;                    // 24 Output Set bit for this pin
    Uint16 GPIO89:1;                    // 25 Output Set bit for this pin
    Uint16 GPIO90:1;                    // 26 Output Set bit for this pin
    Uint16 GPIO91:1;                    // 27 Output Set bit for this pin
    Uint16 GPIO92:1;                    // 28 Output Set bit for this pin
    Uint16 GPIO93:1;                    // 29 Output Set bit for this pin
    Uint16 GPIO94:1;                    // 30 Output Set bit for this pin
    Uint16 GPIO95:1;                    // 31 Output Set bit for this pin
};

union GPCSET_REG {
    Uint32  all;
    struct  GPCSET_BITS  bit;
};

struct GPCCLEAR_BITS {                  // bits description
    Uint16 GPIO64:1;                    // 0 Output Clear bit for this pin
    Uint16 GPIO65:1;                    // 1 Output Clear bit for this pin
    Uint16 GPIO66:1;                    // 2 Output Clear bit for this pin
    Uint16 GPIO67:1;                    // 3 Output Clear bit for this pin
    Uint16 GPIO68:1;                    // 4 Output Clear bit for this pin
    Uint16 GPIO69:1;                    // 5 Output Clear bit for this pin
    Uint16 GPIO70:1;                    // 6 Output Clear bit for this pin
    Uint16 GPIO71:1;                    // 7 Output Clear bit for this pin
    Uint16 GPIO72:1;                    // 8 Output Clear bit for this pin
    Uint16 GPIO73:1;                    // 9 Output Clear bit for this pin
    Uint16 GPIO74:1;                    // 10 Output Clear bit for this pin
    Uint16 GPIO75:1;                    // 11 Output Clear bit for this pin
    Uint16 GPIO76:1;                    // 12 Output Clear bit for this pin
    Uint16 GPIO77:1;                    // 13 Output Clear bit for this pin
    Uint16 GPIO78:1;                    // 14 Output Clear bit for this pin
    Uint16 GPIO79:1;                    // 15 Output Clear bit for this pin
    Uint16 GPIO80:1;                    // 16 Output Clear bit for this pin
    Uint16 GPIO81:1;                    // 17 Output Clear bit for this pin
    Uint16 GPIO82:1;                    // 18 Output Clear bit for this pin
    Uint16 GPIO83:1;                    // 19 Output Clear bit for this pin
    Uint16 GPIO84:1;                    // 20 Output Clear bit for this pin
    Uint16 GPIO85:1;                    // 21 Output Clear bit for this pin
    Uint16 GPIO86:1;                    // 22 Output Clear bit for this pin
    Uint16 GPIO87:1;                    // 23 Output Clear bit for this pin
    Uint16 GPIO88:1;                    // 24 Output Clear bit for this pin
    Uint16 GPIO89:1;                    // 25 Output Clear bit for this pin
    Uint16 GPIO90:1;                    // 26 Output Clear bit for this pin
    Uint16 GPIO91:1;                    // 27 Output Clear bit for this pin
    Uint16 GPIO92:1;                    // 28 Output Clear bit for this pin
    Uint16 GPIO93:1;                    // 29 Output Clear bit for this pin
    Uint16 GPIO94:1;                    // 30 Output Clear bit for this pin
    Uint16 GPIO95:1;                    // 31 Output Clear bit for this pin
};

union GPCCLEAR_REG {
    Uint32  all;
    struct  GPCCLEAR_BITS  bit;
};

struct GPCTOGGLE_BITS {                 // bits description
    Uint16 GPIO64:1;                    // 0 Output Toggle bit for this pin
    Uint16 GPIO65:1;                    // 1 Output Toggle bit for this pin
    Uint16 GPIO66:1;                    // 2 Output Toggle bit for this pin
    Uint16 GPIO67:1;                    // 3 Output Toggle bit for this pin
    Uint16 GPIO68:1;                    // 4 Output Toggle bit for this pin
    Uint16 GPIO69:1;                    // 5 Output Toggle bit for this pin
    Uint16 GPIO70:1;                    // 6 Output Toggle bit for this pin
    Uint16 GPIO71:1;                    // 7 Output Toggle bit for this pin
    Uint16 GPIO72:1;                    // 8 Output Toggle bit for this pin
    Uint16 GPIO73:1;                    // 9 Output Toggle bit for this pin
    Uint16 GPIO74:1;                    // 10 Output Toggle bit for this pin
    Uint16 GPIO75:1;                    // 11 Output Toggle bit for this pin
    Uint16 GPIO76:1;                    // 12 Output Toggle bit for this pin
    Uint16 GPIO77:1;                    // 13 Output Toggle bit for this pin
    Uint16 GPIO78:1;                    // 14 Output Toggle bit for this pin
    Uint16 GPIO79:1;                    // 15 Output Toggle bit for this pin
    Uint16 GPIO80:1;                    // 16 Output Toggle bit for this pin
    Uint16 GPIO81:1;                    // 17 Output Toggle bit for this pin
    Uint16 GPIO82:1;                    // 18 Output Toggle bit for this pin
    Uint16 GPIO83:1;                    // 19 Output Toggle bit for this pin
    Uint16 GPIO84:1;                    // 20 Output Toggle bit for this pin
    Uint16 GPIO85:1;                    // 21 Output Toggle bit for this pin
    Uint16 GPIO86:1;                    // 22 Output Toggle bit for this pin
    Uint16 GPIO87:1;                    // 23 Output Toggle bit for this pin
    Uint16 GPIO88:1;                    // 24 Output Toggle bit for this pin
    Uint16 GPIO89:1;                    // 25 Output Toggle bit for this pin
    Uint16 GPIO90:1;                    // 26 Output Toggle bit for this pin
    Uint16 GPIO91:1;                    // 27 Output Toggle bit for this pin
    Uint16 GPIO92:1;                    // 28 Output Toggle bit for this pin
    Uint16 GPIO93:1;                    // 29 Output Toggle bit for this pin
    Uint16 GPIO94:1;                    // 30 Output Toggle bit for this pin
    Uint16 GPIO95:1;                    // 31 Output Toggle bit for this pin
};

union GPCTOGGLE_REG {
    Uint32  all;
    struct  GPCTOGGLE_BITS  bit;
};

struct GPDDAT_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Data Register for this pin
    Uint16 GPIO97:1;                    // 1 Data Register for this pin
    Uint16 GPIO98:1;                    // 2 Data Register for this pin
    Uint16 GPIO99:1;                    // 3 Data Register for this pin
    Uint16 GPIO100:1;                   // 4 Data Register for this pin
    Uint16 GPIO101:1;                   // 5 Data Register for this pin
    Uint16 GPIO102:1;                   // 6 Data Register for this pin
    Uint16 GPIO103:1;                   // 7 Data Register for this pin
    Uint16 GPIO104:1;                   // 8 Data Register for this pin
    Uint16 GPIO105:1;                   // 9 Data Register for this pin
    Uint16 GPIO106:1;                   // 10 Data Register for this pin
    Uint16 GPIO107:1;                   // 11 Data Register for this pin
    Uint16 GPIO108:1;                   // 12 Data Register for this pin
    Uint16 GPIO109:1;                   // 13 Data Register for this pin
    Uint16 GPIO110:1;                   // 14 Data Register for this pin
    Uint16 GPIO111:1;                   // 15 Data Register for this pin
    Uint16 GPIO112:1;                   // 16 Data Register for this pin
    Uint16 GPIO113:1;                   // 17 Data Register for this pin
    Uint16 GPIO114:1;                   // 18 Data Register for this pin
    Uint16 GPIO115:1;                   // 19 Data Register for this pin
    Uint16 GPIO116:1;                   // 20 Data Register for this pin
    Uint16 GPIO117:1;                   // 21 Data Register for this pin
    Uint16 GPIO118:1;                   // 22 Data Register for this pin
    Uint16 GPIO119:1;                   // 23 Data Register for this pin
    Uint16 GPIO120:1;                   // 24 Data Register for this pin
    Uint16 GPIO121:1;                   // 25 Data Register for this pin
    Uint16 GPIO122:1;                   // 26 Data Register for this pin
    Uint16 GPIO123:1;                   // 27 Data Register for this pin
    Uint16 GPIO124:1;                   // 28 Data Register for this pin
    Uint16 GPIO125:1;                   // 29 Data Register for this pin
    Uint16 GPIO126:1;                   // 30 Data Register for this pin
    Uint16 GPIO127:1;                   // 31 Data Register for this pin
};

union GPDDAT_REG {
    Uint32  all;
    struct  GPDDAT_BITS  bit;
};

struct GPDSET_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Output Set bit for this pin
    Uint16 GPIO97:1;                    // 1 Output Set bit for this pin
    Uint16 GPIO98:1;                    // 2 Output Set bit for this pin
    Uint16 GPIO99:1;                    // 3 Output Set bit for this pin
    Uint16 GPIO100:1;                   // 4 Output Set bit for this pin
    Uint16 GPIO101:1;                   // 5 Output Set bit for this pin
    Uint16 GPIO102:1;                   // 6 Output Set bit for this pin
    Uint16 GPIO103:1;                   // 7 Output Set bit for this pin
    Uint16 GPIO104:1;                   // 8 Output Set bit for this pin
    Uint16 GPIO105:1;                   // 9 Output Set bit for this pin
    Uint16 GPIO106:1;                   // 10 Output Set bit for this pin
    Uint16 GPIO107:1;                   // 11 Output Set bit for this pin
    Uint16 GPIO108:1;                   // 12 Output Set bit for this pin
    Uint16 GPIO109:1;                   // 13 Output Set bit for this pin
    Uint16 GPIO110:1;                   // 14 Output Set bit for this pin
    Uint16 GPIO111:1;                   // 15 Output Set bit for this pin
    Uint16 GPIO112:1;                   // 16 Output Set bit for this pin
    Uint16 GPIO113:1;                   // 17 Output Set bit for this pin
    Uint16 GPIO114:1;                   // 18 Output Set bit for this pin
    Uint16 GPIO115:1;                   // 19 Output Set bit for this pin
    Uint16 GPIO116:1;                   // 20 Output Set bit for this pin
    Uint16 GPIO117:1;                   // 21 Output Set bit for this pin
    Uint16 GPIO118:1;                   // 22 Output Set bit for this pin
    Uint16 GPIO119:1;                   // 23 Output Set bit for this pin
    Uint16 GPIO120:1;                   // 24 Output Set bit for this pin
    Uint16 GPIO121:1;                   // 25 Output Set bit for this pin
    Uint16 GPIO122:1;                   // 26 Output Set bit for this pin
    Uint16 GPIO123:1;                   // 27 Output Set bit for this pin
    Uint16 GPIO124:1;                   // 28 Output Set bit for this pin
    Uint16 GPIO125:1;                   // 29 Output Set bit for this pin
    Uint16 GPIO126:1;                   // 30 Output Set bit for this pin
    Uint16 GPIO127:1;                   // 31 Output Set bit for this pin
};

union GPDSET_REG {
    Uint32  all;
    struct  GPDSET_BITS  bit;
};

struct GPDCLEAR_BITS {                  // bits description
    Uint16 GPIO96:1;                    // 0 Output Clear bit for this pin
    Uint16 GPIO97:1;                    // 1 Output Clear bit for this pin
    Uint16 GPIO98:1;                    // 2 Output Clear bit for this pin
    Uint16 GPIO99:1;                    // 3 Output Clear bit for this pin
    Uint16 GPIO100:1;                   // 4 Output Clear bit for this pin
    Uint16 GPIO101:1;                   // 5 Output Clear bit for this pin
    Uint16 GPIO102:1;                   // 6 Output Clear bit for this pin
    Uint16 GPIO103:1;                   // 7 Output Clear bit for this pin
    Uint16 GPIO104:1;                   // 8 Output Clear bit for this pin
    Uint16 GPIO105:1;                   // 9 Output Clear bit for this pin
    Uint16 GPIO106:1;                   // 10 Output Clear bit for this pin
    Uint16 GPIO107:1;                   // 11 Output Clear bit for this pin
    Uint16 GPIO108:1;                   // 12 Output Clear bit for this pin
    Uint16 GPIO109:1;                   // 13 Output Clear bit for this pin
    Uint16 GPIO110:1;                   // 14 Output Clear bit for this pin
    Uint16 GPIO111:1;                   // 15 Output Clear bit for this pin
    Uint16 GPIO112:1;                   // 16 Output Clear bit for this pin
    Uint16 GPIO113:1;                   // 17 Output Clear bit for this pin
    Uint16 GPIO114:1;                   // 18 Output Clear bit for this pin
    Uint16 GPIO115:1;                   // 19 Output Clear bit for this pin
    Uint16 GPIO116:1;                   // 20 Output Clear bit for this pin
    Uint16 GPIO117:1;                   // 21 Output Clear bit for this pin
    Uint16 GPIO118:1;                   // 22 Output Clear bit for this pin
    Uint16 GPIO119:1;                   // 23 Output Clear bit for this pin
    Uint16 GPIO120:1;                   // 24 Output Clear bit for this pin
    Uint16 GPIO121:1;                   // 25 Output Clear bit for this pin
    Uint16 GPIO122:1;                   // 26 Output Clear bit for this pin
    Uint16 GPIO123:1;                   // 27 Output Clear bit for this pin
    Uint16 GPIO124:1;                   // 28 Output Clear bit for this pin
    Uint16 GPIO125:1;                   // 29 Output Clear bit for this pin
    Uint16 GPIO126:1;                   // 30 Output Clear bit for this pin
    Uint16 GPIO127:1;                   // 31 Output Clear bit for this pin
};

union GPDCLEAR_REG {
    Uint32  all;
    struct  GPDCLEAR_BITS  bit;
};

struct GPDTOGGLE_BITS {                 // bits description
    Uint16 GPIO96:1;                    // 0 Output Toggle bit for this pin
    Uint16 GPIO97:1;                    // 1 Output Toggle bit for this pin
    Uint16 GPIO98:1;                    // 2 Output Toggle bit for this pin
    Uint16 GPIO99:1;                    // 3 Output Toggle bit for this pin
    Uint16 GPIO100:1;                   // 4 Output Toggle bit for this pin
    Uint16 GPIO101:1;                   // 5 Output Toggle bit for this pin
    Uint16 GPIO102:1;                   // 6 Output Toggle bit for this pin
    Uint16 GPIO103:1;                   // 7 Output Toggle bit for this pin
    Uint16 GPIO104:1;                   // 8 Output Toggle bit for this pin
    Uint16 GPIO105:1;                   // 9 Output Toggle bit for this pin
    Uint16 GPIO106:1;                   // 10 Output Toggle bit for this pin
    Uint16 GPIO107:1;                   // 11 Output Toggle bit for this pin
    Uint16 GPIO108:1;                   // 12 Output Toggle bit for this pin
    Uint16 GPIO109:1;                   // 13 Output Toggle bit for this pin
    Uint16 GPIO110:1;                   // 14 Output Toggle bit for this pin
    Uint16 GPIO111:1;                   // 15 Output Toggle bit for this pin
    Uint16 GPIO112:1;                   // 16 Output Toggle bit for this pin
    Uint16 GPIO113:1;                   // 17 Output Toggle bit for this pin
    Uint16 GPIO114:1;                   // 18 Output Toggle bit for this pin
    Uint16 GPIO115:1;                   // 19 Output Toggle bit for this pin
    Uint16 GPIO116:1;                   // 20 Output Toggle bit for this pin
    Uint16 GPIO117:1;                   // 21 Output Toggle bit for this pin
    Uint16 GPIO118:1;                   // 22 Output Toggle bit for this pin
    Uint16 GPIO119:1;                   // 23 Output Toggle bit for this pin
    Uint16 GPIO120:1;                   // 24 Output Toggle bit for this pin
    Uint16 GPIO121:1;                   // 25 Output Toggle bit for this pin
    Uint16 GPIO122:1;                   // 26 Output Toggle bit for this pin
    Uint16 GPIO123:1;                   // 27 Output Toggle bit for this pin
    Uint16 GPIO124:1;                   // 28 Output Toggle bit for this pin
    Uint16 GPIO125:1;                   // 29 Output Toggle bit for this pin
    Uint16 GPIO126:1;                   // 30 Output Toggle bit for this pin
    Uint16 GPIO127:1;                   // 31 Output Toggle bit for this pin
};

union GPDTOGGLE_REG {
    Uint32  all;
    struct  GPDTOGGLE_BITS  bit;
};

struct GPEDAT_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Data Register for this pin
    Uint16 GPIO129:1;                   // 1 Data Register for this pin
    Uint16 GPIO130:1;                   // 2 Data Register for this pin
    Uint16 GPIO131:1;                   // 3 Data Register for this pin
    Uint16 GPIO132:1;                   // 4 Data Register for this pin
    Uint16 GPIO133:1;                   // 5 Data Register for this pin
    Uint16 GPIO134:1;                   // 6 Data Register for this pin
    Uint16 GPIO135:1;                   // 7 Data Register for this pin
    Uint16 GPIO136:1;                   // 8 Data Register for this pin
    Uint16 GPIO137:1;                   // 9 Data Register for this pin
    Uint16 GPIO138:1;                   // 10 Data Register for this pin
    Uint16 GPIO139:1;                   // 11 Data Register for this pin
    Uint16 GPIO140:1;                   // 12 Data Register for this pin
    Uint16 GPIO141:1;                   // 13 Data Register for this pin
    Uint16 GPIO142:1;                   // 14 Data Register for this pin
    Uint16 GPIO143:1;                   // 15 Data Register for this pin
    Uint16 GPIO144:1;                   // 16 Data Register for this pin
    Uint16 GPIO145:1;                   // 17 Data Register for this pin
    Uint16 GPIO146:1;                   // 18 Data Register for this pin
    Uint16 GPIO147:1;                   // 19 Data Register for this pin
    Uint16 GPIO148:1;                   // 20 Data Register for this pin
    Uint16 GPIO149:1;                   // 21 Data Register for this pin
    Uint16 GPIO150:1;                   // 22 Data Register for this pin
    Uint16 GPIO151:1;                   // 23 Data Register for this pin
    Uint16 GPIO152:1;                   // 24 Data Register for this pin
    Uint16 GPIO153:1;                   // 25 Data Register for this pin
    Uint16 GPIO154:1;                   // 26 Data Register for this pin
    Uint16 GPIO155:1;                   // 27 Data Register for this pin
    Uint16 GPIO156:1;                   // 28 Data Register for this pin
    Uint16 GPIO157:1;                   // 29 Data Register for this pin
    Uint16 GPIO158:1;                   // 30 Data Register for this pin
    Uint16 GPIO159:1;                   // 31 Data Register for this pin
};

union GPEDAT_REG {
    Uint32  all;
    struct  GPEDAT_BITS  bit;
};

struct GPESET_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Output Set bit for this pin
    Uint16 GPIO129:1;                   // 1 Output Set bit for this pin
    Uint16 GPIO130:1;                   // 2 Output Set bit for this pin
    Uint16 GPIO131:1;                   // 3 Output Set bit for this pin
    Uint16 GPIO132:1;                   // 4 Output Set bit for this pin
    Uint16 GPIO133:1;                   // 5 Output Set bit for this pin
    Uint16 GPIO134:1;                   // 6 Output Set bit for this pin
    Uint16 GPIO135:1;                   // 7 Output Set bit for this pin
    Uint16 GPIO136:1;                   // 8 Output Set bit for this pin
    Uint16 GPIO137:1;                   // 9 Output Set bit for this pin
    Uint16 GPIO138:1;                   // 10 Output Set bit for this pin
    Uint16 GPIO139:1;                   // 11 Output Set bit for this pin
    Uint16 GPIO140:1;                   // 12 Output Set bit for this pin
    Uint16 GPIO141:1;                   // 13 Output Set bit for this pin
    Uint16 GPIO142:1;                   // 14 Output Set bit for this pin
    Uint16 GPIO143:1;                   // 15 Output Set bit for this pin
    Uint16 GPIO144:1;                   // 16 Output Set bit for this pin
    Uint16 GPIO145:1;                   // 17 Output Set bit for this pin
    Uint16 GPIO146:1;                   // 18 Output Set bit for this pin
    Uint16 GPIO147:1;                   // 19 Output Set bit for this pin
    Uint16 GPIO148:1;                   // 20 Output Set bit for this pin
    Uint16 GPIO149:1;                   // 21 Output Set bit for this pin
    Uint16 GPIO150:1;                   // 22 Output Set bit for this pin
    Uint16 GPIO151:1;                   // 23 Output Set bit for this pin
    Uint16 GPIO152:1;                   // 24 Output Set bit for this pin
    Uint16 GPIO153:1;                   // 25 Output Set bit for this pin
    Uint16 GPIO154:1;                   // 26 Output Set bit for this pin
    Uint16 GPIO155:1;                   // 27 Output Set bit for this pin
    Uint16 GPIO156:1;                   // 28 Output Set bit for this pin
    Uint16 GPIO157:1;                   // 29 Output Set bit for this pin
    Uint16 GPIO158:1;                   // 30 Output Set bit for this pin
    Uint16 GPIO159:1;                   // 31 Output Set bit for this pin
};

union GPESET_REG {
    Uint32  all;
    struct  GPESET_BITS  bit;
};

struct GPECLEAR_BITS {                  // bits description
    Uint16 GPIO128:1;                   // 0 Output Clear bit for this pin
    Uint16 GPIO129:1;                   // 1 Output Clear bit for this pin
    Uint16 GPIO130:1;                   // 2 Output Clear bit for this pin
    Uint16 GPIO131:1;                   // 3 Output Clear bit for this pin
    Uint16 GPIO132:1;                   // 4 Output Clear bit for this pin
    Uint16 GPIO133:1;                   // 5 Output Clear bit for this pin
    Uint16 GPIO134:1;                   // 6 Output Clear bit for this pin
    Uint16 GPIO135:1;                   // 7 Output Clear bit for this pin
    Uint16 GPIO136:1;                   // 8 Output Clear bit for this pin
    Uint16 GPIO137:1;                   // 9 Output Clear bit for this pin
    Uint16 GPIO138:1;                   // 10 Output Clear bit for this pin
    Uint16 GPIO139:1;                   // 11 Output Clear bit for this pin
    Uint16 GPIO140:1;                   // 12 Output Clear bit for this pin
    Uint16 GPIO141:1;                   // 13 Output Clear bit for this pin
    Uint16 GPIO142:1;                   // 14 Output Clear bit for this pin
    Uint16 GPIO143:1;                   // 15 Output Clear bit for this pin
    Uint16 GPIO144:1;                   // 16 Output Clear bit for this pin
    Uint16 GPIO145:1;                   // 17 Output Clear bit for this pin
    Uint16 GPIO146:1;                   // 18 Output Clear bit for this pin
    Uint16 GPIO147:1;                   // 19 Output Clear bit for this pin
    Uint16 GPIO148:1;                   // 20 Output Clear bit for this pin
    Uint16 GPIO149:1;                   // 21 Output Clear bit for this pin
    Uint16 GPIO150:1;                   // 22 Output Clear bit for this pin
    Uint16 GPIO151:1;                   // 23 Output Clear bit for this pin
    Uint16 GPIO152:1;                   // 24 Output Clear bit for this pin
    Uint16 GPIO153:1;                   // 25 Output Clear bit for this pin
    Uint16 GPIO154:1;                   // 26 Output Clear bit for this pin
    Uint16 GPIO155:1;                   // 27 Output Clear bit for this pin
    Uint16 GPIO156:1;                   // 28 Output Clear bit for this pin
    Uint16 GPIO157:1;                   // 29 Output Clear bit for this pin
    Uint16 GPIO158:1;                   // 30 Output Clear bit for this pin
    Uint16 GPIO159:1;                   // 31 Output Clear bit for this pin
};

union GPECLEAR_REG {
    Uint32  all;
    struct  GPECLEAR_BITS  bit;
};

struct GPETOGGLE_BITS {                 // bits description
    Uint16 GPIO128:1;                   // 0 Output Toggle bit for this pin
    Uint16 GPIO129:1;                   // 1 Output Toggle bit for this pin
    Uint16 GPIO130:1;                   // 2 Output Toggle bit for this pin
    Uint16 GPIO131:1;                   // 3 Output Toggle bit for this pin
    Uint16 GPIO132:1;                   // 4 Output Toggle bit for this pin
    Uint16 GPIO133:1;                   // 5 Output Toggle bit for this pin
    Uint16 GPIO134:1;                   // 6 Output Toggle bit for this pin
    Uint16 GPIO135:1;                   // 7 Output Toggle bit for this pin
    Uint16 GPIO136:1;                   // 8 Output Toggle bit for this pin
    Uint16 GPIO137:1;                   // 9 Output Toggle bit for this pin
    Uint16 GPIO138:1;                   // 10 Output Toggle bit for this pin
    Uint16 GPIO139:1;                   // 11 Output Toggle bit for this pin
    Uint16 GPIO140:1;                   // 12 Output Toggle bit for this pin
    Uint16 GPIO141:1;                   // 13 Output Toggle bit for this pin
    Uint16 GPIO142:1;                   // 14 Output Toggle bit for this pin
    Uint16 GPIO143:1;                   // 15 Output Toggle bit for this pin
    Uint16 GPIO144:1;                   // 16 Output Toggle bit for this pin
    Uint16 GPIO145:1;                   // 17 Output Toggle bit for this pin
    Uint16 GPIO146:1;                   // 18 Output Toggle bit for this pin
    Uint16 GPIO147:1;                   // 19 Output Toggle bit for this pin
    Uint16 GPIO148:1;                   // 20 Output Toggle bit for this pin
    Uint16 GPIO149:1;                   // 21 Output Toggle bit for this pin
    Uint16 GPIO150:1;                   // 22 Output Toggle bit for this pin
    Uint16 GPIO151:1;                   // 23 Output Toggle bit for this pin
    Uint16 GPIO152:1;                   // 24 Output Toggle bit for this pin
    Uint16 GPIO153:1;                   // 25 Output Toggle bit for this pin
    Uint16 GPIO154:1;                   // 26 Output Toggle bit for this pin
    Uint16 GPIO155:1;                   // 27 Output Toggle bit for this pin
    Uint16 GPIO156:1;                   // 28 Output Toggle bit for this pin
    Uint16 GPIO157:1;                   // 29 Output Toggle bit for this pin
    Uint16 GPIO158:1;                   // 30 Output Toggle bit for this pin
    Uint16 GPIO159:1;                   // 31 Output Toggle bit for this pin
};

union GPETOGGLE_REG {
    Uint32  all;
    struct  GPETOGGLE_BITS  bit;
};

struct GPFDAT_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Data Register for this pin
    Uint16 GPIO161:1;                   // 1 Data Register for this pin
    Uint16 GPIO162:1;                   // 2 Data Register for this pin
    Uint16 GPIO163:1;                   // 3 Data Register for this pin
    Uint16 GPIO164:1;                   // 4 Data Register for this pin
    Uint16 GPIO165:1;                   // 5 Data Register for this pin
    Uint16 GPIO166:1;                   // 6 Data Register for this pin
    Uint16 GPIO167:1;                   // 7 Data Register for this pin
    Uint16 GPIO168:1;                   // 8 Data Register for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFDAT_REG {
    Uint32  all;
    struct  GPFDAT_BITS  bit;
};

struct GPFSET_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Output Set bit for this pin
    Uint16 GPIO161:1;                   // 1 Output Set bit for this pin
    Uint16 GPIO162:1;                   // 2 Output Set bit for this pin
    Uint16 GPIO163:1;                   // 3 Output Set bit for this pin
    Uint16 GPIO164:1;                   // 4 Output Set bit for this pin
    Uint16 GPIO165:1;                   // 5 Output Set bit for this pin
    Uint16 GPIO166:1;                   // 6 Output Set bit for this pin
    Uint16 GPIO167:1;                   // 7 Output Set bit for this pin
    Uint16 GPIO168:1;                   // 8 Output Set bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFSET_REG {
    Uint32  all;
    struct  GPFSET_BITS  bit;
};

struct GPFCLEAR_BITS {                  // bits description
    Uint16 GPIO160:1;                   // 0 Output Clear bit for this pin
    Uint16 GPIO161:1;                   // 1 Output Clear bit for this pin
    Uint16 GPIO162:1;                   // 2 Output Clear bit for this pin
    Uint16 GPIO163:1;                   // 3 Output Clear bit for this pin
    Uint16 GPIO164:1;                   // 4 Output Clear bit for this pin
    Uint16 GPIO165:1;                   // 5 Output Clear bit for this pin
    Uint16 GPIO166:1;                   // 6 Output Clear bit for this pin
    Uint16 GPIO167:1;                   // 7 Output Clear bit for this pin
    Uint16 GPIO168:1;                   // 8 Output Clear bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFCLEAR_REG {
    Uint32  all;
    struct  GPFCLEAR_BITS  bit;
};

struct GPFTOGGLE_BITS {                 // bits description
    Uint16 GPIO160:1;                   // 0 Output Toggle bit for this pin
    Uint16 GPIO161:1;                   // 1 Output Toggle bit for this pin
    Uint16 GPIO162:1;                   // 2 Output Toggle bit for this pin
    Uint16 GPIO163:1;                   // 3 Output Toggle bit for this pin
    Uint16 GPIO164:1;                   // 4 Output Toggle bit for this pin
    Uint16 GPIO165:1;                   // 5 Output Toggle bit for this pin
    Uint16 GPIO166:1;                   // 6 Output Toggle bit for this pin
    Uint16 GPIO167:1;                   // 7 Output Toggle bit for this pin
    Uint16 GPIO168:1;                   // 8 Output Toggle bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFTOGGLE_REG {
    Uint32  all;
    struct  GPFTOGGLE_BITS  bit;
};

struct GPIO_DATA_REGS {
    union   GPADAT_REG                       GPADAT;                       // GPIO A Data Register (GPIO0 to 31)
    union   GPASET_REG                       GPASET;                       // GPIO A Data Set Register (GPIO0 to 31)
    union   GPACLEAR_REG                     GPACLEAR;                     // GPIO A Data Clear Register (GPIO0 to 31)
    union   GPATOGGLE_REG                    GPATOGGLE;                    // GPIO A Data Toggle Register (GPIO0 to 31) 
    union   GPBDAT_REG                       GPBDAT;                       // GPIO B Data Register (GPIO32 to 63)
    union   GPBSET_REG                       GPBSET;                       // GPIO B Data Set Register (GPIO32 to 63)
    union   GPBCLEAR_REG                     GPBCLEAR;                     // GPIO B Data Clear Register (GPIO32 to 63)
    union   GPBTOGGLE_REG                    GPBTOGGLE;                    // GPIO B Data Toggle Register (GPIO32 to 63) 
    union   GPCDAT_REG                       GPCDAT;                       // GPIO C Data Register (GPIO64 to 95)
    union   GPCSET_REG                       GPCSET;                       // GPIO C Data Set Register (GPIO64 to 95)
    union   GPCCLEAR_REG                     GPCCLEAR;                     // GPIO C Data Clear Register (GPIO64 to 95)
    union   GPCTOGGLE_REG                    GPCTOGGLE;                    // GPIO C Data Toggle Register (GPIO64 to 95) 
    union   GPDDAT_REG                       GPDDAT;                       // GPIO D Data Register (GPIO96 to 127)
    union   GPDSET_REG                       GPDSET;                       // GPIO D Data Set Register (GPIO96 to 127)
    union   GPDCLEAR_REG                     GPDCLEAR;                     // GPIO D Data Clear Register (GPIO96 to 127)
    union   GPDTOGGLE_REG                    GPDTOGGLE;                    // GPIO D Data Toggle Register (GPIO96 to 127) 
    union   GPEDAT_REG                       GPEDAT;                       // GPIO E Data Register (GPIO128 to 159)
    union   GPESET_REG                       GPESET;                       // GPIO E Data Set Register (GPIO128 to 159)
    union   GPECLEAR_REG                     GPECLEAR;                     // GPIO E Data Clear Register (GPIO128 to 159)
    union   GPETOGGLE_REG                    GPETOGGLE;                    // GPIO E Data Toggle Register (GPIO128 to 159) 
    union   GPFDAT_REG                       GPFDAT;                       // GPIO F Data Register (GPIO160 to 168)
    union   GPFSET_REG                       GPFSET;                       // GPIO F Data Set Register (GPIO160 to 168)
    union   GPFCLEAR_REG                     GPFCLEAR;                     // GPIO F Data Clear Register (GPIO160 to 168)
    union   GPFTOGGLE_REG                    GPFTOGGLE;                    // GPIO F Data Toggle Register (GPIO160 to 168) 
};

//---------------------------------------------------------------------------
// GPIO External References & Function Declarations:
//
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
