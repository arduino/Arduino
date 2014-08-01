// TI File $Revision: /main/2 $
// Checkin $Date: October 29, 2008   14:53:46 $
//###########################################################################
//
// FILE:    F2802x_BootVars.h
//          
// TITLE:   F2802x Boot Variable Definitions.
//
// NOTES:
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_BOOT_VARS_H
#define F2802x_BOOT_VARS_H

#ifdef __cplusplus
extern "C" {
#endif



//---------------------------------------------------------------------------
// External Boot ROM variable definitions:
//
extern uint16_t EmuKey;
extern uint16_t EmuBMode;
extern uint32_t Flash_CPUScaleFactor;
extern void (*Flash_CallbackPtr) (void);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_BOOT_VARS_H definition

//===========================================================================
// End of file.
//===========================================================================

