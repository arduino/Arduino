// TI File $Revision: /main/2 $
// Checkin $Date: September 19, 2008   14:25:33 $
//###########################################################################
//
// FILE:   F2802x_Comp.h
//
// TITLE:  F2802x Device Comparator Register Definitions
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_COMP_H
#define F2802x_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

//===========================================================================
//  Comparator Register Bit Definitions
//

struct COMPCTL_BITS {            // bit       description
    uint16_t   COMPDACEN:1;        // 0         Comparator/DAC  Enable
    uint16_t   COMPSOURCE:1;       // 1         Source select for comparator inverting input
    uint16_t   CMPINV:1;           // 2         Invert select for Comparator
    uint16_t   QUALSEL:5;          // 7:03      Qualification Period for synchronized output of the comparator
    uint16_t   SYNCSEL:1;          // 8         Synchronization select for output of the comparator
    uint16_t   rsvd1:7;            // 15:09     reserved
};

union COMPCTL_REG  {
    uint16_t                         all;
    struct COMPCTL_BITS            bit;
};

struct COMPSTS_BITS {            // bit       description
    uint16_t   COMPSTS:1;          // 0         Logical latched value of the comparator
    uint16_t   rsvd1:15;           // 15:01     reserved
};

union COMPSTS_REG  {
    uint16_t                         all;
    struct COMPSTS_BITS            bit;
};


struct DACVAL_BITS {             // bit       description
    uint16_t   DACVAL:10;          // 9:00      DAC Value bit
    uint16_t   rsvd1:6;            // 15:10     reserved
};

union DACVAL_REG  {
    uint16_t                         all;
    struct DACVAL_BITS             bit;
};

//===========================================================================
//  Comparator Register Definitions
//

struct COMP_REGS {
    union  COMPCTL_REG         COMPCTL;
    uint16_t                     rsvd1;
    union  COMPSTS_REG         COMPSTS;
    uint16_t                     rsvd2[3];
    union  DACVAL_REG          DACVAL;
    uint16_t                     rsvd4[10];
};

//===========================================================================
//  Comparator External References and Function Declarations
//

extern volatile struct COMP_REGS Comp1Regs;
extern volatile struct COMP_REGS Comp2Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_COMP_H definition

//===========================================================================
// End of file
//===========================================================================
