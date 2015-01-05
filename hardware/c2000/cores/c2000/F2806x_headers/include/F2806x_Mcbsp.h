//###########################################################################
//
// FILE:   F2806x_Mcbsp.h
//
// TITLE:  F2806x Device McBSP Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_McBSP_H
#define F2806x_McBSP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// McBSP Individual Register Bit Definitions:

struct DRR2_BITS {     // bits description
	Uint16	HWLB:8;			// 7:0	High word low byte
	Uint16	HWHB:8;			// 15:8	High word high byte
};

union DRR2_REG {
	Uint16 all;
	struct DRR2_BITS	bit;
};

struct DRR1_BITS {     // bits description
	Uint16	LWLB:8;			// 7:0	Low word low byte
	Uint16	LWHB:8;			// 15:8	Low word high byte
};

union DRR1_REG {
	Uint16 all;
	struct DRR1_BITS	bit;
};

struct DXR2_BITS {     // bits description
	Uint16	HWLB:8;			// 7:0	High word low byte
	Uint16	HWHB:8;			// 15:8	High word high byte
};

union DXR2_REG {
	Uint16 all;
	struct DXR2_BITS	bit;
};

struct DXR1_BITS {     // bits description
	Uint16	LWLB:8;			// 7:0	Low word low byte
	Uint16	LWHB:8;			// 15:8	Low word high byte
};

union DXR1_REG {
	Uint16 all;
	struct DXR1_BITS	bit;
};

struct SPCR2_BITS {     // bits description
	Uint16	XRST:1;			// 0	Transmitter reset
	Uint16	XRDY:1;			// 1	Transmitter ready
	Uint16	XEMPTY:1;		// 2	Transmitter empty
	Uint16	XSYNCERR:1;		// 3	Transmit sync error INT flag
	Uint16	XINTM:2;		// 5:4	Transmit Interupt mode bits
	Uint16	GRST:1;			// 6	Sample rate generator reset
	Uint16	FRST:1;			// 7	Frame sync logic reset
	Uint16	SOFT:1;			// 8	SOFT bit
	Uint16	FREE:1;			// 9	FREE bit
	Uint16	rsvd1:6;		// 15:10	Reserved
};

union SPCR2_REG {
	Uint16 all;
	struct SPCR2_BITS	bit;
};

struct SPCR1_BITS {     // bits description
	Uint16	RRST:1;			// 0	Receiver reset
	Uint16	RRDY:1;			// 1	Receiver ready
	Uint16	RFULL:1;		// 2	Receiver full
	Uint16	RSYNCERR:1;		// 3	Receive sync error INT flag
	Uint16	RINTM:2;		// 5:4	Receive Interupt mode bits
	Uint16	rsvd1:1;		// 6	Reserved
	Uint16	DXENA:1;		// 7	DX delay enable
	Uint16	rsvd2:3;		// 10:8	Reserved
	Uint16	CLKSTP:2;		// 12:11	Clock stop mode
	Uint16	RJUST:2;		// 14:13	Rx sign extension and justification mode
	Uint16	DLB:1;			// 15	Digital loopback
};

union SPCR1_REG {
	Uint16 all;
	struct SPCR1_BITS	bit;
};

struct RCR2_BITS {     // bits description
	Uint16	RDATDLY:2;			// 1:0  	Receive data delay
	Uint16	RFIG:1;				// 2	Receive frame sync ignore
	Uint16	RCOMPAND:2;			// 4:3	Receive Companding Mode selects
	Uint16	RWDLEN2:3;			// 7:5	Receive word length 2
	Uint16	RFRLEN2:7;			// 14:8	Receive Frame length 2
	Uint16	RPHASE:1;			// 15	Receive Phase
};

union RCR2_REG {
	Uint16 all;
	struct RCR2_BITS	bit;
};

struct RCR1_BITS {     // bits description
	Uint16	rsvd1:5;			// 4:0  	Reserved
	Uint16	RWDLEN1:3;			// 7:5	Receive word length 1
	Uint16	RFRLEN1:7;			// 14:8 	Receive Frame length 1
	Uint16	rsvd2:1;			// 15	Reserved
};

union RCR1_REG {
	Uint16 all;
	struct RCR1_BITS	bit;
};

struct XCR2_BITS {     // bits description
	Uint16	XDATDLY:2;			// 1:0  	Transmit data delay
	Uint16	XFIG:1;				// 2	Transmit frame sync ignore
	Uint16	XCOMPAND:2;			// 4:3	Transmit Companding Mode selects
	Uint16	XWDLEN2:3;			// 7:5	Transmit word length 2
	Uint16	XFRLEN2:7;			// 14:8	Transmit Frame length 2
	Uint16	XPHASE:1;			// 15	Transmit Phase
};

union XCR2_REG {
	Uint16 all;
	struct XCR2_BITS	bit;
};

struct XCR1_BITS {     // bits description
	Uint16	rsvd1:5;			// 4:0  	Reserved
	Uint16	XWDLEN1:3;			// 7:5	Transmit word length 1
	Uint16	XFRLEN1:7;			// 14:8 	Transmit Frame length 1
	Uint16	rsvd2:1;			// 15	Reserved
};

union XCR1_REG {
	Uint16 all;
	struct XCR1_BITS	bit;
};

struct SRGR2_BITS {     // bits description
	Uint16	FPER:12;			// 11:0  	Frame-sync period
	Uint16	FSGM:1;				// 12	Frame sync generator mode
	Uint16	CLKSM:1;			// 13	Sample rate generator mode
	Uint16	rsvd1:1;			// 14	Reserved
	Uint16	GSYNC:1;			// 15	CLKG sync
};

union SRGR2_REG {
	Uint16 all;
	struct SRGR2_BITS	bit;
};

struct SRGR1_BITS {     // bits description
	Uint16	CLKGDV:8;		// 7:0	CLKG divider
	Uint16	FWID:8;			// 15:8	Frame width
};

union SRGR1_REG {
	Uint16 all;
	struct SRGR1_BITS	bit;
};

struct MCR2_BITS {     // bits description
	Uint16	XMCM:2;				// 1:0	Transmit multichannel mode
	Uint16	XCBLK:3;			// 4:2	Transmit current block
	Uint16	XPABLK:2;			// 6:5	Transmit partition A Block
	Uint16	XPBBLK:2;			// 8:7	Transmit partition B Block
	Uint16	XMCME:1;			// 9	Transmit multi-channel enhance mode
	Uint16	rsvd1:6;			// 15:10	Reserved
};

union MCR2_REG {
	Uint16 all;
	struct MCR2_BITS	bit;
};

struct MCR1_BITS {     // bits description
	Uint16	RMCM:1;				// 0	Receive multichannel mode
	Uint16	rsvd1:1;			// 1	Reserved
	Uint16	RCBLK:3;			// 4:2	Receive current block
	Uint16	RPABLK:2;			// 6:5	Receive partition A Block
	Uint16	RPBBLK:2;			// 8:7	Receive partition B Block
	Uint16	RMCME:1;			// 9	Receive multi-channel enhance mode
	Uint16	rsvd2:6;			// 15:10	Reserved
};

union MCR1_REG {
	Uint16 all;
	struct MCR1_BITS	bit;
};

struct RCERA_BITS {     // bits description
	Uint16	RCEA0:1;			// 0	Receive Channel enable bit
	Uint16	RCEA1:1;			// 1	Receive Channel enable bit
	Uint16	RCEA2:1;			// 2	Receive Channel enable bit
	Uint16	RCEA3:1;			// 3	Receive Channel enable bit
	Uint16	RCEA4:1;			// 4	Receive Channel enable bit
	Uint16	RCEA5:1;			// 5	Receive Channel enable bit
	Uint16	RCEA6:1;			// 6	Receive Channel enable bit
	Uint16	RCEA7:1;			// 7	Receive Channel enable bit
	Uint16	RCEA8:1;			// 8	Receive Channel enable bit
	Uint16	RCEA9:1;			// 9	Receive Channel enable bit
	Uint16	RCEA10:1;			// 10	Receive Channel enable bit
	Uint16	RCEA11:1;			// 11	Receive Channel enable bit
	Uint16	RCEA12:1;			// 12	Receive Channel enable bit
	Uint16	RCEA13:1;			// 13	Receive Channel enable bit
	Uint16	RCEA14:1;			// 14	Receive Channel enable bit
	Uint16	RCEA15:1;			// 15	Receive Channel enable bit
};

union RCERA_REG {
	Uint16 all;
	struct RCERA_BITS	bit;
};

struct RCERB_BITS {     // bits description
	Uint16	RCEB0:1;			// 0	Receive Channel enable bit
	Uint16	RCEB1:1;			// 1	Receive Channel enable bit
	Uint16	RCEB2:1;			// 2	Receive Channel enable bit
	Uint16	RCEB3:1;			// 3	Receive Channel enable bit
	Uint16	RCEB4:1;			// 4	Receive Channel enable bit
	Uint16	RCEB5:1;			// 5	Receive Channel enable bit
	Uint16	RCEB6:1;			// 6	Receive Channel enable bit
	Uint16	RCEB7:1;			// 7	Receive Channel enable bit
	Uint16	RCEB8:1;			// 8	Receive Channel enable bit
	Uint16	RCEB9:1;			// 9	Receive Channel enable bit
	Uint16	RCEB10:1;			// 10	Receive Channel enable bit
	Uint16	RCEB11:1;			// 11	Receive Channel enable bit
	Uint16	RCEB12:1;			// 12	Receive Channel enable bit
	Uint16	RCEB13:1;			// 13	Receive Channel enable bit
	Uint16	RCEB14:1;			// 14	Receive Channel enable bit
	Uint16	RCEB15:1;			// 15	Receive Channel enable bit
};

union RCERB_REG {
	Uint16 all;
	struct RCERB_BITS	bit;
};

struct XCERA_BITS {     // bits description
	Uint16	XCERA0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERA1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERA2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERA3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERA4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERA5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERA6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERA7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERA8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERA9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERA10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERA11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERA12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERA13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERA14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERA15:1;			// 15	Transmit Channel enable bit
};

union XCERA_REG {
	Uint16 all;
	struct XCERA_BITS	bit;
};

struct XCERB_BITS {     // bits description
	Uint16	XCERB0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERB1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERB2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERB3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERB4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERB5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERB6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERB7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERB8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERB9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERB10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERB11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERB12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERB13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERB14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERB15:1;			// 15	Transmit Channel enable bit
};

union XCERB_REG {
	Uint16 all;
	struct XCERB_BITS	bit;
};

struct PCR_BITS {     // bits description
	Uint16	CLKRP:1;			// 0	Receive Clock polarity
	Uint16	CLKXP:1;			// 1	Transmit clock polarity
	Uint16	FSRP:1;				// 2	Receive Frame synchronization polarity
	Uint16	FSXP:1;				// 3	Transmit Frame synchronization polarity
	Uint16	rsvd1:1;			// 4	Reserved
	Uint16	rsvd2:1;			// 5	Reserved
	Uint16	rsvd3:1;			// 6	Reserved
	Uint16	SCLKME:1;			// 7	Sample clock mode selection
	Uint16	CLKRM:1;			// 8	Receiver Clock Mode
	Uint16	CLKXM:1;			// 9	Transmit Clock Mode.
	Uint16	FSRM:1;				// 10	Receive Frame Synchronization Mode
	Uint16	FSXM:1;				// 11	Transmit Frame Synchronization Mode
	Uint16	rsvd4:4;			// 15:12	Reserved
};

union PCR_REG {
	Uint16 all;
	struct PCR_BITS	bit;
};

struct RCERC_BITS {     // bits description
	Uint16	RCEC0:1;			// 0	Receive Channel enable bit
	Uint16	RCEC1:1;			// 1	Receive Channel enable bit
	Uint16	RCEC2:1;			// 2	Receive Channel enable bit
	Uint16	RCEC3:1;			// 3	Receive Channel enable bit
	Uint16	RCEC4:1;			// 4	Receive Channel enable bit
	Uint16	RCEC5:1;			// 5	Receive Channel enable bit
	Uint16	RCEC6:1;			// 6	Receive Channel enable bit
	Uint16	RCEC7:1;			// 7	Receive Channel enable bit
	Uint16	RCEC8:1;			// 8	Receive Channel enable bit
	Uint16	RCEC9:1;			// 9	Receive Channel enable bit
	Uint16	RCEC10:1;			// 10	Receive Channel enable bit
	Uint16	RCEC11:1;			// 11	Receive Channel enable bit
	Uint16	RCEC12:1;			// 12	Receive Channel enable bit
	Uint16	RCEC13:1;			// 13	Receive Channel enable bit
	Uint16	RCEC14:1;			// 14	Receive Channel enable bit
	Uint16	RCEC15:1;			// 15	Receive Channel enable bit
};

union RCERC_REG {
	Uint16 all;
	struct RCERC_BITS	bit;
};

struct RCERD_BITS {     // bits description
	Uint16	RCED0:1;			// 0	Receive Channel enable bit
	Uint16	RCED1:1;			// 1	Receive Channel enable bit
	Uint16	RCED2:1;			// 2	Receive Channel enable bit
	Uint16	RCED3:1;			// 3	Receive Channel enable bit
	Uint16	RCED4:1;			// 4	Receive Channel enable bit
	Uint16	RCED5:1;			// 5	Receive Channel enable bit
	Uint16	RCED6:1;			// 6	Receive Channel enable bit
	Uint16	RCED7:1;			// 7	Receive Channel enable bit
	Uint16	RCED8:1;			// 8	Receive Channel enable bit
	Uint16	RCED9:1;			// 9	Receive Channel enable bit
	Uint16	RCED10:1;			// 10	Receive Channel enable bit
	Uint16	RCED11:1;			// 11	Receive Channel enable bit
	Uint16	RCED12:1;			// 12	Receive Channel enable bit
	Uint16	RCED13:1;			// 13	Receive Channel enable bit
	Uint16	RCED14:1;			// 14	Receive Channel enable bit
	Uint16	RCED15:1;			// 15	Receive Channel enable bit
};

union RCERD_REG {
	Uint16 all;
	struct RCERD_BITS	bit;
};

struct XCERC_BITS {     // bits description
	Uint16	XCERC0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERC1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERC2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERC3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERC4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERC5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERC6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERC7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERC8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERC9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERC10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERC11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERC12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERC13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERC14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERC15:1;			// 15	Transmit Channel enable bit
};

union XCERC_REG {
	Uint16 all;
	struct XCERC_BITS	bit;
};

struct XCERD_BITS {     // bits description
	Uint16	XCERD0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERD1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERD2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERD3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERD4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERD5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERD6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERD7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERD8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERD9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERD10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERD11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERD12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERD13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERD14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERD15:1;			// 15	Transmit Channel enable bit
};

union XCERD_REG {
	Uint16 all;
	struct XCERD_BITS	bit;
};

struct RCERE_BITS {     // bits description
	Uint16	RCEE0:1;			// 0	Receive Channel enable bit
	Uint16	RCEE1:1;			// 1	Receive Channel enable bit
	Uint16	RCEE2:1;			// 2	Receive Channel enable bit
	Uint16	RCEE3:1;			// 3	Receive Channel enable bit
	Uint16	RCEE4:1;			// 4	Receive Channel enable bit
	Uint16	RCEE5:1;			// 5	Receive Channel enable bit
	Uint16	RCEE6:1;			// 6	Receive Channel enable bit
	Uint16	RCEE7:1;			// 7	Receive Channel enable bit
	Uint16	RCEE8:1;			// 8	Receive Channel enable bit
	Uint16	RCEE9:1;			// 9	Receive Channel enable bit
	Uint16	RCEE10:1;			// 10	Receive Channel enable bit
	Uint16	RCEE11:1;			// 11	Receive Channel enable bit
	Uint16	RCEE12:1;			// 12	Receive Channel enable bit
	Uint16	RCEE13:1;			// 13	Receive Channel enable bit
	Uint16	RCEE14:1;			// 14	Receive Channel enable bit
	Uint16	RCEE15:1;			// 15	Receive Channel enable bit
};

union RCERE_REG {
	Uint16 all;
	struct RCERE_BITS	bit;
};

struct RCERF_BITS {     // bits description
	Uint16	RCEF0:1;			// 0	Receive Channel enable bit
	Uint16	RCEF1:1;			// 1	Receive Channel enable bit
	Uint16	RCEF2:1;			// 2	Receive Channel enable bit
	Uint16	RCEF3:1;			// 3	Receive Channel enable bit
	Uint16	RCEF4:1;			// 4	Receive Channel enable bit
	Uint16	RCEF5:1;			// 5	Receive Channel enable bit
	Uint16	RCEF6:1;			// 6	Receive Channel enable bit
	Uint16	RCEF7:1;			// 7	Receive Channel enable bit
	Uint16	RCEF8:1;			// 8	Receive Channel enable bit
	Uint16	RCEF9:1;			// 9	Receive Channel enable bit
	Uint16	RCEF10:1;			// 10	Receive Channel enable bit
	Uint16	RCEF11:1;			// 11	Receive Channel enable bit
	Uint16	RCEF12:1;			// 12	Receive Channel enable bit
	Uint16	RCEF13:1;			// 13	Receive Channel enable bit
	Uint16	RCEF14:1;			// 14	Receive Channel enable bit
	Uint16	RCEF15:1;			// 15	Receive Channel enable bit
};

union RCERF_REG {
	Uint16 all;
	struct RCERF_BITS	bit;
};

struct XCERE_BITS {     // bits description
	Uint16	XCERE0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERE1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERE2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERE3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERE4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERE5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERE6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERE7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERE8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERE9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERE10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERE11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERE12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERE13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERE14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERE15:1;			// 15	Transmit Channel enable bit
};

union XCERE_REG {
	Uint16 all;
	struct XCERE_BITS	bit;
};

struct XCERF_BITS {     // bits description
	Uint16	XCERF0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERF1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERF2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERF3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERF4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERF5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERF6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERF7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERF8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERF9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERF10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERF11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERF12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERF13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERF14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERF15:1;			// 15	Transmit Channel enable bit
};

union XCERF_REG {
	Uint16 all;
	struct XCERF_BITS	bit;
};

struct RCERG_BITS {     // bits description
	Uint16	RCEG0:1;			// 0	Receive Channel enable bit
	Uint16	RCEG1:1;			// 1	Receive Channel enable bit
	Uint16	RCEG2:1;			// 2	Receive Channel enable bit
	Uint16	RCEG3:1;			// 3	Receive Channel enable bit
	Uint16	RCEG4:1;			// 4	Receive Channel enable bit
	Uint16	RCEG5:1;			// 5	Receive Channel enable bit
	Uint16	RCEG6:1;			// 6	Receive Channel enable bit
	Uint16	RCEG7:1;			// 7	Receive Channel enable bit
	Uint16	RCEG8:1;			// 8	Receive Channel enable bit
	Uint16	RCEG9:1;			// 9	Receive Channel enable bit
	Uint16	RCEG10:1;			// 10	Receive Channel enable bit
	Uint16	RCEG11:1;			// 11	Receive Channel enable bit
	Uint16	RCEG12:1;			// 12	Receive Channel enable bit
	Uint16	RCEG13:1;			// 13	Receive Channel enable bit
	Uint16	RCEG14:1;			// 14	Receive Channel enable bit
	Uint16	RCEG15:1;			// 15	Receive Channel enable bit
};

union RCERG_REG {
	Uint16 all;
	struct RCERG_BITS	bit;
};

struct RCERH_BITS {     // bits description
	Uint16	RCEH0:1;			// 0	Receive Channel enable bit
	Uint16	RCEH1:1;			// 1	Receive Channel enable bit
	Uint16	RCEH2:1;			// 2	Receive Channel enable bit
	Uint16	RCEH3:1;			// 3	Receive Channel enable bit
	Uint16	RCEH4:1;			// 4	Receive Channel enable bit
	Uint16	RCEH5:1;			// 5	Receive Channel enable bit
	Uint16	RCEH6:1;			// 6	Receive Channel enable bit
	Uint16	RCEH7:1;			// 7	Receive Channel enable bit
	Uint16	RCEH8:1;			// 8	Receive Channel enable bit
	Uint16	RCEH9:1;			// 9	Receive Channel enable bit
	Uint16	RCEH10:1;			// 10	Receive Channel enable bit
	Uint16	RCEH11:1;			// 11	Receive Channel enable bit
	Uint16	RCEH12:1;			// 12	Receive Channel enable bit
	Uint16	RCEH13:1;			// 13	Receive Channel enable bit
	Uint16	RCEH14:1;			// 14	Receive Channel enable bit
	Uint16	RCEH15:1;			// 15	Receive Channel enable bit
};

union RCERH_REG {
	Uint16 all;
	struct RCERH_BITS	bit;
};

struct XCERG_BITS {     // bits description
	Uint16	XCERG0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERG1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERG2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERG3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERG4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERG5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERG6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERG7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERG8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERG9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERG10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERG11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERG12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERG13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERG14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERG15:1;			// 15	Transmit Channel enable bit
};

union XCERG_REG {
	Uint16 all;
	struct XCERG_BITS	bit;
};

struct XCERH_BITS {     // bits description
	Uint16	XCERH0:1;			// 0	Transmit Channel enable bit
	Uint16	XCERH1:1;			// 1	Transmit Channel enable bit
	Uint16	XCERH2:1;			// 2	Transmit Channel enable bit
	Uint16	XCERH3:1;			// 3	Transmit Channel enable bit
	Uint16	XCERH4:1;			// 4	Transmit Channel enable bit
	Uint16	XCERH5:1;			// 5	Transmit Channel enable bit
	Uint16	XCERH6:1;			// 6	Transmit Channel enable bit
	Uint16	XCERH7:1;			// 7	Transmit Channel enable bit
	Uint16	XCERH8:1;			// 8	Transmit Channel enable bit
	Uint16	XCERH9:1;			// 9	Transmit Channel enable bit
	Uint16	XCERH10:1;			// 10	Transmit Channel enable bit
	Uint16	XCERH11:1;			// 11	Transmit Channel enable bit
	Uint16	XCERH12:1;			// 12	Transmit Channel enable bit
	Uint16	XCERH13:1;			// 13	Transmit Channel enable bit
	Uint16	XCERH14:1;			// 14	Transmit Channel enable bit
	Uint16	XCERH15:1;			// 15	Transmit Channel enable bit
};

union XCERH_REG {
	Uint16 all;
	struct XCERH_BITS	bit;
};

struct MFFINT_BITS {     // bits description
	Uint16	XINT:1;			// 0	XINT  interrupt enable
	Uint16	rsvd1:1;		// 1	Reserved
	Uint16	RINT:1;			// 2	RINT  interrupt enable
	Uint16	rsvd2:13;		// 15:3	Reserved
};

union MFFINT_REG {
	Uint16 all;
	struct MFFINT_BITS	bit;
};

struct McBSP_REGS {
	union	DRR2_REG	DRR2;		// Data receive register bits 31-16
	union	DRR1_REG	DRR1;		// Data receive register bits 15-0
	union	DXR2_REG	DXR2;		// Data transmit register bits 31-16
	union	DXR1_REG	DXR1;		// Data transmit register bits 15-0
	union	SPCR2_REG	SPCR2;		// Control register 2
	union	SPCR1_REG	SPCR1;		// Control register 1
	union	RCR2_REG	RCR2;		// Receive Control register 2
	union	RCR1_REG	RCR1;		// Receive Control register 1
	union	XCR2_REG	XCR2;		// Transmit Control register 2
	union	XCR1_REG	XCR1;		// Transmit Control register 1
	union	SRGR2_REG	SRGR2;		// Sample rate generator register 2
	union	SRGR1_REG	SRGR1;		// Sample rate generator register 1
	union	MCR2_REG	MCR2;		// Multi-channel register 2
	union	MCR1_REG	MCR1;		// Multi-channel register 1
	union	RCERA_REG	RCERA;		// Receive channel enable partition A
	union	RCERB_REG	RCERB;		// Receive channel enable partition B
	union	XCERA_REG	XCERA;		// Transmit channel enable partition A
	union	XCERB_REG	XCERB;		// Transmit channel enable partition B
	union	PCR_REG		PCR;		// Pin Control register
	union	RCERC_REG	RCERC;		// Receive channel enable partition C
	union	RCERD_REG	RCERD;		// Receive channel enable partition D
	union	XCERC_REG	XCERC;		// Transmit channel enable partition C
	union	XCERD_REG	XCERD;		// Transmit channel enable partition D
	union	RCERE_REG	RCERE;		// Receive channel enable partition E
	union	RCERF_REG	RCERF;		// Receive channel enable partition F
	union	XCERE_REG	XCERE;		// Transmit channel enable partition E
	union	XCERF_REG	XCERF;		// Transmit channel enable partition F
	union	RCERG_REG	RCERG;		// Receive channel enable partition G
	union	RCERH_REG	RCERH;		// Receive channel enable partition H
	union	XCERG_REG	XCERG;		// Transmit channel enable partition G
	union	XCERH_REG	XCERH;		// Transmit channel enable partition H
	Uint16				rsvd1[4];	// Reserved
	union	MFFINT_REG	MFFINT;		// Interrupt enable
};

//---------------------------------------------------------------------------
// Mcbsp External References & Function Declarations:
//
extern volatile struct McBSP_REGS McbspaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_McBSP_H definition
//===========================================================================
// End of file.
//===========================================================================
