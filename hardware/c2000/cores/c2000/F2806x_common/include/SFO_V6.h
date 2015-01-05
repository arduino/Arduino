
//###########################################################################
//
// FILE:   SFO_V6.H
//
// TITLE:  Scale Factor Optimizer Library V6 Interface Header
//
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.03| 11 Aug 2008 | TI   | New version (V6) with calibration logic separate
//                           | from each ePWM channel.
//  0.04| 03 Aug 2009 | TI   | Minor update to set MEP_ScaleFactor limit to 255
//                           | instead of 254.
//                           | Now updates HRMSTEP register for
//                           | auto-conversion only of MEP_ScaleFactor is <= 255
//                           |
//###########################################################################


//============================================================================
// Description:     This header provides the function call interface
//                  for the scale factor optimizer
//============================================================================


//============================================================================
// Multiple include Guard
//============================================================================
#ifndef _SFO_V6_H
#define _SFO_V6_H

//============================================================================
// C++ namespace
//============================================================================
#ifdef __cplusplus
extern "C" {
#endif

//============================================================================
// USER MUST UPDATE THIS CONSTANT FOR NUMBER OF HRPWM CHANNELS USED
//============================================================================
#define PWM_CH  5   // Equal # of HRPWM channels PLUS 1
                    // i.e. PWM_CH is 9 for 8 channels, 7 for 6 channels, etc.
//============================================================================
// Function prototypes for MEP SFO
//============================================================================

int SFO(void);             // SFO V6  Calibration Function
//============================================================================
// Useful Defines when Using SFO Functions
//============================================================================
#define SFO_INCOMPLETE      0
#define SFO_COMPLETE        1
#define SFO_ERROR           2

//============================================================================
// Multiple include Guard
//============================================================================
#endif // End: Multiple include Guard

//============================================================================
// C++ namespace
//============================================================================
#ifdef __cplusplus
}
#endif /* extern "C" */
