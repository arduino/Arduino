//*****************************************************************************
//
// hw_ethernet.h - Macros used when accessing the Ethernet hardware.
//
// Copyright (c) 2006-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_ETHERNET_H__
#define __HW_ETHERNET_H__

//*****************************************************************************
//
// The following are defines for the Ethernet MAC register offsets.
//
//*****************************************************************************
#define MAC_O_RIS               0x00000000  // Ethernet MAC Raw Interrupt
                                            // Status/Acknowledge
#define MAC_O_IACK              0x00000000  // Ethernet MAC Raw Interrupt
                                            // Status/Acknowledge
#define MAC_O_IM                0x00000004  // Ethernet MAC Interrupt Mask
#define MAC_O_RCTL              0x00000008  // Ethernet MAC Receive Control
#define MAC_O_TCTL              0x0000000C  // Ethernet MAC Transmit Control
#define MAC_O_DATA              0x00000010  // Ethernet MAC Data
#define MAC_O_IA0               0x00000014  // Ethernet MAC Individual Address
                                            // 0
#define MAC_O_IA1               0x00000018  // Ethernet MAC Individual Address
                                            // 1
#define MAC_O_THR               0x0000001C  // Ethernet MAC Threshold
#define MAC_O_MCTL              0x00000020  // Ethernet MAC Management Control
#define MAC_O_MDV               0x00000024  // Ethernet MAC Management Divider
#define MAC_O_MADD              0x00000028  // Ethernet MAC Management Address
#define MAC_O_MTXD              0x0000002C  // Ethernet MAC Management Transmit
                                            // Data
#define MAC_O_MRXD              0x00000030  // Ethernet MAC Management Receive
                                            // Data
#define MAC_O_NP                0x00000034  // Ethernet MAC Number of Packets
#define MAC_O_TR                0x00000038  // Ethernet MAC Transmission
                                            // Request
#define MAC_O_TS                0x0000003C  // Ethernet MAC Timer Support
#define MAC_O_LED               0x00000040  // Ethernet MAC LED Encoding
#define MAC_O_MDIX              0x00000044  // Ethernet PHY MDIX

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_RIS register.
//
//*****************************************************************************
#define MAC_RIS_PHYINT          0x00000040  // PHY Interrupt
#define MAC_RIS_MDINT           0x00000020  // MII Transaction Complete
#define MAC_RIS_RXER            0x00000010  // Receive Error
#define MAC_RIS_FOV             0x00000008  // FIFO Overrun
#define MAC_RIS_TXEMP           0x00000004  // Transmit FIFO Empty
#define MAC_RIS_TXER            0x00000002  // Transmit Error
#define MAC_RIS_RXINT           0x00000001  // Packet Received

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IACK register.
//
//*****************************************************************************
#define MAC_IACK_PHYINT         0x00000040  // Clear PHY Interrupt
#define MAC_IACK_MDINT          0x00000020  // Clear MII Transaction Complete
#define MAC_IACK_RXER           0x00000010  // Clear Receive Error
#define MAC_IACK_FOV            0x00000008  // Clear FIFO Overrun
#define MAC_IACK_TXEMP          0x00000004  // Clear Transmit FIFO Empty
#define MAC_IACK_TXER           0x00000002  // Clear Transmit Error
#define MAC_IACK_RXINT          0x00000001  // Clear Packet Received

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IM register.
//
//*****************************************************************************
#define MAC_IM_PHYINTM          0x00000040  // Mask PHY Interrupt
#define MAC_IM_MDINTM           0x00000020  // Mask MII Transaction Complete
#define MAC_IM_RXERM            0x00000010  // Mask Receive Error
#define MAC_IM_FOVM             0x00000008  // Mask FIFO Overrun
#define MAC_IM_TXEMPM           0x00000004  // Mask Transmit FIFO Empty
#define MAC_IM_TXERM            0x00000002  // Mask Transmit Error
#define MAC_IM_RXINTM           0x00000001  // Mask Packet Received

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_RCTL register.
//
//*****************************************************************************
#define MAC_RCTL_RSTFIFO        0x00000010  // Clear Receive FIFO
#define MAC_RCTL_BADCRC         0x00000008  // Enable Reject Bad CRC
#define MAC_RCTL_PRMS           0x00000004  // Enable Promiscuous Mode
#define MAC_RCTL_AMUL           0x00000002  // Enable Multicast Frames
#define MAC_RCTL_RXEN           0x00000001  // Enable Receiver

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_TCTL register.
//
//*****************************************************************************
#define MAC_TCTL_DUPLEX         0x00000010  // Enable Duplex Mode
#define MAC_TCTL_CRC            0x00000004  // Enable CRC Generation
#define MAC_TCTL_PADEN          0x00000002  // Enable Packet Padding
#define MAC_TCTL_TXEN           0x00000001  // Enable Transmitter

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_DATA register.
//
//*****************************************************************************
#define MAC_DATA_TXDATA_M       0xFFFFFFFF  // Transmit FIFO Data
#define MAC_DATA_RXDATA_M       0xFFFFFFFF  // Receive FIFO Data
#define MAC_DATA_RXDATA_S       0
#define MAC_DATA_TXDATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IA0 register.
//
//*****************************************************************************
#define MAC_IA0_MACOCT4_M       0xFF000000  // MAC Address Octet 4
#define MAC_IA0_MACOCT3_M       0x00FF0000  // MAC Address Octet 3
#define MAC_IA0_MACOCT2_M       0x0000FF00  // MAC Address Octet 2
#define MAC_IA0_MACOCT1_M       0x000000FF  // MAC Address Octet 1
#define MAC_IA0_MACOCT4_S       24
#define MAC_IA0_MACOCT3_S       16
#define MAC_IA0_MACOCT2_S       8
#define MAC_IA0_MACOCT1_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IA1 register.
//
//*****************************************************************************
#define MAC_IA1_MACOCT6_M       0x0000FF00  // MAC Address Octet 6
#define MAC_IA1_MACOCT5_M       0x000000FF  // MAC Address Octet 5
#define MAC_IA1_MACOCT6_S       8
#define MAC_IA1_MACOCT5_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_THR register.
//
//*****************************************************************************
#define MAC_THR_THRESH_M        0x0000003F  // Threshold Value
#define MAC_THR_THRESH_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MCTL register.
//
//*****************************************************************************
#define MAC_MCTL_REGADR_M       0x000000F8  // MII Register Address
#define MAC_MCTL_WRITE          0x00000002  // MII Register Transaction Type
#define MAC_MCTL_START          0x00000001  // MII Register Transaction Enable
#define MAC_MCTL_REGADR_S       3

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MDV register.
//
//*****************************************************************************
#define MAC_MDV_DIV_M           0x000000FF  // Clock Divider
#define MAC_MDV_DIV_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MADD register.
//
//*****************************************************************************
#define MAC_MADD_PHYADR_M       0x0000001F  // PHY Address
#define MAC_MADD_PHYADR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MTXD register.
//
//*****************************************************************************
#define MAC_MTXD_MDTX_M         0x0000FFFF  // MII Register Transmit Data
#define MAC_MTXD_MDTX_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MRXD register.
//
//*****************************************************************************
#define MAC_MRXD_MDRX_M         0x0000FFFF  // MII Register Receive Data
#define MAC_MRXD_MDRX_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_NP register.
//
//*****************************************************************************
#define MAC_NP_NPR_M            0x0000003F  // Number of Packets in Receive
                                            // FIFO
#define MAC_NP_NPR_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_TR register.
//
//*****************************************************************************
#define MAC_TR_NEWTX            0x00000001  // New Transmission

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_TS register.
//
//*****************************************************************************
#define MAC_TS_TSEN             0x00000001  // Time Stamp Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_LED register.
//
//*****************************************************************************
#define MAC_LED_LED1_M          0x00000F00  // LED1 Source
#define MAC_LED_LED1_LINK       0x00000000  // Link OK
#define MAC_LED_LED1_RXTX       0x00000100  // RX or TX Activity (Default LED1)
#define MAC_LED_LED1_100        0x00000500  // 100BASE-TX mode
#define MAC_LED_LED1_10         0x00000600  // 10BASE-T mode
#define MAC_LED_LED1_DUPLEX     0x00000700  // Full-Duplex
#define MAC_LED_LED1_LINKACT    0x00000800  // Link OK & Blink=RX or TX
                                            // Activity
#define MAC_LED_LED0_M          0x0000000F  // LED0 Source
#define MAC_LED_LED0_LINK       0x00000000  // Link OK (Default LED0)
#define MAC_LED_LED0_RXTX       0x00000001  // RX or TX Activity
#define MAC_LED_LED0_100        0x00000005  // 100BASE-TX mode
#define MAC_LED_LED0_10         0x00000006  // 10BASE-T mode
#define MAC_LED_LED0_DUPLEX     0x00000007  // Full-Duplex
#define MAC_LED_LED0_LINKACT    0x00000008  // Link OK & Blink=RX or TX
                                            // Activity

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MDIX register.
//
//*****************************************************************************
#define MAC_MDIX_EN             0x00000001  // MDI/MDI-X Enable

//*****************************************************************************
//
// The following are defines for the Ethernet Controller PHY registers.
//
//*****************************************************************************
#define PHY_MR0                 0x00000000  // Ethernet PHY Management Register
                                            // 0 - Control
#define PHY_MR1                 0x00000001  // Ethernet PHY Management Register
                                            // 1 - Status
#define PHY_MR2                 0x00000002  // Ethernet PHY Management Register
                                            // 2 - PHY Identifier 1
#define PHY_MR3                 0x00000003  // Ethernet PHY Management Register
                                            // 3 - PHY Identifier 2
#define PHY_MR4                 0x00000004  // Ethernet PHY Management Register
                                            // 4 - Auto-Negotiation
                                            // Advertisement
#define PHY_MR5                 0x00000005  // Ethernet PHY Management Register
                                            // 5 - Auto-Negotiation Link
                                            // Partner Base Page Ability
#define PHY_MR6                 0x00000006  // Ethernet PHY Management Register
                                            // 6 - Auto-Negotiation Expansion
#define PHY_MR16                0x00000010  // Ethernet PHY Management Register
                                            // 16 - Vendor-Specific
#define PHY_MR17                0x00000011  // Ethernet PHY Management Register
                                            // 17 - Mode Control/Status
#define PHY_MR18                0x00000012  // Ethernet PHY Management Register
                                            // 18 - Diagnostic
#define PHY_MR19                0x00000013  // Ethernet PHY Management Register
                                            // 19 - Transceiver Control
#define PHY_MR23                0x00000017  // Ethernet PHY Management Register
                                            // 23 - LED Configuration
#define PHY_MR24                0x00000018  // Ethernet PHY Management Register
                                            // 24 -MDI/MDIX Control
#define PHY_MR27                0x0000001B  // Ethernet PHY Management Register
                                            // 27 - Special Control/Status
#define PHY_MR29                0x0000001D  // Ethernet PHY Management Register
                                            // 29 - Interrupt Status
#define PHY_MR30                0x0000001E  // Ethernet PHY Management Register
                                            // 30 - Interrupt Mask
#define PHY_MR31                0x0000001F  // Ethernet PHY Management Register
                                            // 31 - PHY Special Control/Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR0 register.
//
//*****************************************************************************
#define PHY_MR0_RESET           0x00008000  // Reset Registers
#define PHY_MR0_LOOPBK          0x00004000  // Loopback Mode
#define PHY_MR0_SPEEDSL         0x00002000  // Speed Select
#define PHY_MR0_ANEGEN          0x00001000  // Auto-Negotiation Enable
#define PHY_MR0_PWRDN           0x00000800  // Power Down
#define PHY_MR0_ISO             0x00000400  // Isolate
#define PHY_MR0_RANEG           0x00000200  // Restart Auto-Negotiation
#define PHY_MR0_DUPLEX          0x00000100  // Set Duplex Mode
#define PHY_MR0_COLT            0x00000080  // Collision Test

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR1 register.
//
//*****************************************************************************
#define PHY_MR1_100X_F          0x00004000  // 100BASE-TX Full-Duplex Mode
#define PHY_MR1_100X_H          0x00002000  // 100BASE-TX Half-Duplex Mode
#define PHY_MR1_10T_F           0x00001000  // 10BASE-T Full-Duplex Mode
#define PHY_MR1_10T_H           0x00000800  // 10BASE-T Half-Duplex Mode
#define PHY_MR1_MFPS            0x00000040  // Management Frames with Preamble
                                            // Suppressed
#define PHY_MR1_ANEGC           0x00000020  // Auto-Negotiation Complete
#define PHY_MR1_RFAULT          0x00000010  // Remote Fault
#define PHY_MR1_ANEGA           0x00000008  // Auto-Negotiation
#define PHY_MR1_LINK            0x00000004  // Link Made
#define PHY_MR1_JAB             0x00000002  // Jabber Condition
#define PHY_MR1_EXTD            0x00000001  // Extended Capabilities

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR2 register.
//
//*****************************************************************************
#define PHY_MR2_OUI_M           0x0000FFFF  // Organizationally Unique
                                            // Identifier[21:6]
#define PHY_MR2_OUI_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR3 register.
//
//*****************************************************************************
#define PHY_MR3_OUI_M           0x0000FC00  // Organizationally Unique
                                            // Identifier[5:0]
#define PHY_MR3_MN_M            0x000003F0  // Model Number
#define PHY_MR3_RN_M            0x0000000F  // Revision Number
#define PHY_MR3_OUI_S           10
#define PHY_MR3_MN_S            4
#define PHY_MR3_RN_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR4 register.
//
//*****************************************************************************
#define PHY_MR4_NP              0x00008000  // Next Page
#define PHY_MR4_RF              0x00002000  // Remote Fault
#define PHY_MR4_A3              0x00000100  // Technology Ability Field [3]
#define PHY_MR4_A2              0x00000080  // Technology Ability Field [2]
#define PHY_MR4_A1              0x00000040  // Technology Ability Field [1]
#define PHY_MR4_A0              0x00000020  // Technology Ability Field [0]
#define PHY_MR4_S_M             0x0000001F  // Selector Field
#define PHY_MR4_S_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR5 register.
//
//*****************************************************************************
#define PHY_MR5_NP              0x00008000  // Next Page
#define PHY_MR5_ACK             0x00004000  // Acknowledge
#define PHY_MR5_RF              0x00002000  // Remote Fault
#define PHY_MR5_A_M             0x00001FE0  // Technology Ability Field
#define PHY_MR5_S_M             0x0000001F  // Selector Field
#define PHY_MR5_S_8023          0x00000001  // IEEE Std 802.3
#define PHY_MR5_S_8029          0x00000002  // IEEE Std 802.9 ISLAN-16T
#define PHY_MR5_S_8025          0x00000003  // IEEE Std 802.5
#define PHY_MR5_S_1394          0x00000004  // IEEE Std 1394
#define PHY_MR5_A_S             5

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR6 register.
//
//*****************************************************************************
#define PHY_MR6_PDF             0x00000010  // Parallel Detection Fault
#define PHY_MR6_LPNPA           0x00000008  // Link Partner is Next Page Able
#define PHY_MR6_PRX             0x00000002  // New Page Received
#define PHY_MR6_LPANEGA         0x00000001  // Link Partner is Auto-Negotiation
                                            // Able

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR16 register.
//
//*****************************************************************************
#define PHY_MR16_RPTR           0x00008000  // Repeater Mode
#define PHY_MR16_INPOL          0x00004000  // Interrupt Polarity
#define PHY_MR16_TXHIM          0x00001000  // Transmit High Impedance Mode
#define PHY_MR16_SQEI           0x00000800  // SQE Inhibit Testing
#define PHY_MR16_NL10           0x00000400  // Natural Loopback Mode
#define PHY_MR16_SR_M           0x000003C0  // Silicon Revision Identifier
#define PHY_MR16_APOL           0x00000020  // Auto-Polarity Disable
#define PHY_MR16_RVSPOL         0x00000010  // Receive Data Polarity
#define PHY_MR16_PCSBP          0x00000002  // PCS Bypass
#define PHY_MR16_RXCC           0x00000001  // Receive Clock Control
#define PHY_MR16_SR_S           6

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR17 register.
//
//*****************************************************************************
#define PHY_MR17_JABBER_IE      0x00008000  // Jabber Interrupt Enable
#define PHY_MR17_FASTRIP        0x00004000  // 10-BASE-T Fast Mode Enable
#define PHY_MR17_RXER_IE        0x00004000  // Receive Error Interrupt Enable
#define PHY_MR17_EDPD           0x00002000  // Enable Energy Detect Power Down
#define PHY_MR17_PRX_IE         0x00002000  // Page Received Interrupt Enable
#define PHY_MR17_PDF_IE         0x00001000  // Parallel Detection Fault
                                            // Interrupt Enable
#define PHY_MR17_LSQE           0x00000800  // Low Squelch Enable
#define PHY_MR17_LPACK_IE       0x00000800  // LP Acknowledge Interrupt Enable
#define PHY_MR17_LSCHG_IE       0x00000400  // Link Status Change Interrupt
                                            // Enable
#define PHY_MR17_RFAULT_IE      0x00000200  // Remote Fault Interrupt Enable
#define PHY_MR17_ANEGCOMP_IE    0x00000100  // Auto-Negotiation Complete
                                            // Interrupt Enable
#define PHY_MR17_FASTEST        0x00000100  // Auto-Negotiation Test Mode
#define PHY_MR17_JABBER_INT     0x00000080  // Jabber Event Interrupt
#define PHY_MR17_RXER_INT       0x00000040  // Receive Error Interrupt
#define PHY_MR17_PRX_INT        0x00000020  // Page Receive Interrupt
#define PHY_MR17_PDF_INT        0x00000010  // Parallel Detection Fault
                                            // Interrupt
#define PHY_MR17_LPACK_INT      0x00000008  // LP Acknowledge Interrupt
#define PHY_MR17_LSCHG_INT      0x00000004  // Link Status Change Interrupt
#define PHY_MR17_FGLS           0x00000004  // Force Good Link Status
#define PHY_MR17_RFAULT_INT     0x00000002  // Remote Fault Interrupt
#define PHY_MR17_ENON           0x00000002  // Energy On
#define PHY_MR17_ANEGCOMP_INT   0x00000001  // Auto-Negotiation Complete
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR18 register.
//
//*****************************************************************************
#define PHY_MR18_ANEGF          0x00001000  // Auto-Negotiation Failure
#define PHY_MR18_DPLX           0x00000800  // Duplex Mode
#define PHY_MR18_RATE           0x00000400  // Rate
#define PHY_MR18_RXSD           0x00000200  // Receive Detection
#define PHY_MR18_RX_LOCK        0x00000100  // Receive PLL Lock

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR19 register.
//
//*****************************************************************************
#define PHY_MR19_TXO_M          0x0000C000  // Transmit Amplitude Selection
#define PHY_MR19_TXO_00DB       0x00000000  // Gain set for 0.0dB of insertion
                                            // loss
#define PHY_MR19_TXO_04DB       0x00004000  // Gain set for 0.4dB of insertion
                                            // loss
#define PHY_MR19_TXO_08DB       0x00008000  // Gain set for 0.8dB of insertion
                                            // loss
#define PHY_MR19_TXO_12DB       0x0000C000  // Gain set for 1.2dB of insertion
                                            // loss

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR23 register.
//
//*****************************************************************************
#define PHY_MR23_LED1_M         0x000000F0  // LED1 Source
#define PHY_MR23_LED1_LINK      0x00000000  // Link OK
#define PHY_MR23_LED1_RXTX      0x00000010  // RX or TX Activity (Default LED1)
#define PHY_MR23_LED1_100       0x00000050  // 100BASE-TX mode
#define PHY_MR23_LED1_10        0x00000060  // 10BASE-T mode
#define PHY_MR23_LED1_DUPLEX    0x00000070  // Full-Duplex
#define PHY_MR23_LED1_LINKACT   0x00000080  // Link OK & Blink=RX or TX
                                            // Activity
#define PHY_MR23_LED0_M         0x0000000F  // LED0 Source
#define PHY_MR23_LED0_LINK      0x00000000  // Link OK (Default LED0)
#define PHY_MR23_LED0_RXTX      0x00000001  // RX or TX Activity
#define PHY_MR23_LED0_100       0x00000005  // 100BASE-TX mode
#define PHY_MR23_LED0_10        0x00000006  // 10BASE-T mode
#define PHY_MR23_LED0_DUPLEX    0x00000007  // Full-Duplex
#define PHY_MR23_LED0_LINKACT   0x00000008  // Link OK & Blink=RX or TX
                                            // Activity

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR24 register.
//
//*****************************************************************************
#define PHY_MR24_PD_MODE        0x00000080  // Parallel Detection Mode
#define PHY_MR24_AUTO_SW        0x00000040  // Auto-Switching Enable
#define PHY_MR24_MDIX           0x00000020  // Auto-Switching Configuration
#define PHY_MR24_MDIX_CM        0x00000010  // Auto-Switching Complete
#define PHY_MR24_MDIX_SD_M      0x0000000F  // Auto-Switching Seed
#define PHY_MR24_MDIX_SD_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR27 register.
//
//*****************************************************************************
#define PHY_MR27_XPOL           0x00000010  // Polarity State of 10 BASE-T

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR29 register.
//
//*****************************************************************************
#define PHY_MR29_EONIS          0x00000080  // ENERGYON Interrupt
#define PHY_MR29_ANCOMPIS       0x00000040  // Auto-Negotiation Complete
                                            // Interrupt
#define PHY_MR29_RFLTIS         0x00000020  // Remote Fault Interrupt
#define PHY_MR29_LDIS           0x00000010  // Link Down Interrupt
#define PHY_MR29_LPACKIS        0x00000008  // Auto-Negotiation LP Acknowledge
#define PHY_MR29_PDFIS          0x00000004  // Parallel Detection Fault
#define PHY_MR29_PRXIS          0x00000002  // Auto Negotiation Page Received

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR30 register.
//
//*****************************************************************************
#define PHY_MR30_EONIM          0x00000080  // ENERGYON Interrupt Enabled
#define PHY_MR30_ANCOMPIM       0x00000040  // Auto-Negotiation Complete
                                            // Interrupt Enabled
#define PHY_MR30_RFLTIM         0x00000020  // Remote Fault Interrupt Enabled
#define PHY_MR30_LDIM           0x00000010  // Link Down Interrupt Enabled
#define PHY_MR30_LPACKIM        0x00000008  // Auto-Negotiation LP Acknowledge
                                            // Enabled
#define PHY_MR30_PDFIM          0x00000004  // Parallel Detection Fault Enabled
#define PHY_MR30_PRXIM          0x00000002  // Auto Negotiation Page Received
                                            // Enabled

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR31 register.
//
//*****************************************************************************
#define PHY_MR31_AUTODONE       0x00001000  // Auto Negotiation Done
#define PHY_MR31_SPEED_M        0x0000001C  // HCD Speed Value
#define PHY_MR31_SPEED_10HD     0x00000004  // 10BASE-T half duplex
#define PHY_MR31_SPEED_100HD    0x00000008  // 100BASE-T half duplex
#define PHY_MR31_SPEED_10FD     0x00000014  // 10BASE-T full duplex
#define PHY_MR31_SPEED_100FD    0x00000018  // 100BASE-T full duplex
#define PHY_MR31_SCRDIS         0x00000001  // Scramble Disable

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the Ethernet MAC register offsets.
//
//*****************************************************************************
#define MAC_O_IS                0x00000000  // Interrupt Status Register

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_IS
// register.
//
//*****************************************************************************
#define MAC_IS_PHYINT           0x00000040  // PHY Interrupt
#define MAC_IS_MDINT            0x00000020  // MDI Transaction Complete
#define MAC_IS_RXER             0x00000010  // RX Error
#define MAC_IS_FOV              0x00000008  // RX FIFO Overrun
#define MAC_IS_TXEMP            0x00000004  // TX FIFO Empy
#define MAC_IS_TXER             0x00000002  // TX Error
#define MAC_IS_RXINT            0x00000001  // RX Packet Available

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_IA0
// register.
//
//*****************************************************************************
#define MAC_IA0_MACOCT4         0xFF000000  // 4th Octet of MAC address
#define MAC_IA0_MACOCT3         0x00FF0000  // 3rd Octet of MAC address
#define MAC_IA0_MACOCT2         0x0000FF00  // 2nd Octet of MAC address
#define MAC_IA0_MACOCT1         0x000000FF  // 1st Octet of MAC address

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_IA1
// register.
//
//*****************************************************************************
#define MAC_IA1_MACOCT6         0x0000FF00  // 6th Octet of MAC address
#define MAC_IA1_MACOCT5         0x000000FF  // 5th Octet of MAC address

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_THR
// register.
//
//*****************************************************************************
#define MAC_THR_THRESH          0x0000003F  // Transmit Threshold Value

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_MCTL
// register.
//
//*****************************************************************************
#define MAC_MCTL_REGADR         0x000000F8  // Address for Next MII Transaction

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_MDV
// register.
//
//*****************************************************************************
#define MAC_MDV_DIV             0x000000FF  // Clock Divider for MDC for TX

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_MTXD
// register.
//
//*****************************************************************************
#define MAC_MTXD_MDTX           0x0000FFFF  // Data for Next MII Transaction

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_MRXD
// register.
//
//*****************************************************************************
#define MAC_MRXD_MDRX           0x0000FFFF  // Data Read from Last MII Trans

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the MAC_O_NP
// register.
//
//*****************************************************************************
#define MAC_NP_NPR              0x0000003F  // Number of RX Frames in FIFO

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the PHY_MR23
// register.
//
//*****************************************************************************
#define PHY_MR23_LED1_TX        0x00000020  // TX Activity
#define PHY_MR23_LED1_RX        0x00000030  // RX Activity
#define PHY_MR23_LED1_COL       0x00000040  // Collision
#define PHY_MR23_LED0_TX        0x00000002  // TX Activity
#define PHY_MR23_LED0_RX        0x00000003  // RX Activity
#define PHY_MR23_LED0_COL       0x00000004  // Collision

//*****************************************************************************
//
// The following are deprecated defines for the reset values of the MAC
// registers.
//
//*****************************************************************************
#define MAC_RV_MDV              0x00000080
#define MAC_RV_IM               0x0000007F
#define MAC_RV_THR              0x0000003F
#define MAC_RV_RCTL             0x00000008
#define MAC_RV_IA0              0x00000000
#define MAC_RV_TCTL             0x00000000
#define MAC_RV_DATA             0x00000000
#define MAC_RV_MRXD             0x00000000
#define MAC_RV_TR               0x00000000
#define MAC_RV_IS               0x00000000
#define MAC_RV_NP               0x00000000
#define MAC_RV_MCTL             0x00000000
#define MAC_RV_MTXD             0x00000000
#define MAC_RV_IA1              0x00000000
#define MAC_RV_IACK             0x00000000
#define MAC_RV_MADD             0x00000000

#endif

#endif // __HW_ETHERNET_H__
