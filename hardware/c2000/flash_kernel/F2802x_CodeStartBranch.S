;// TI File $Revision: /main/1 $
;// Checkin $Date: August 14, 2008   16:58:01 $
;//###########################################################################
;//
;// FILE:  DSP2802x_CodeStartBranch.asm    
;//
;// TITLE: Branch for redirecting code execution after boot. 
;//
;// For these examples, code_start is the first code that is executed after
;// exiting the boot ROM code. 
;//
;// The codestart section in the linker cmd file is used to physically place
;// this code at the correct memory location.  This section should be placed 
;// at the location the BOOT ROM will re-direct the code to.  For example, 
;// for boot to FLASH this code will be located at 0x3f7ff6. 
;//
;// In addition, the example DSP2802x projects are setup such that the codegen
;// entry point is also set to the code_start label.  This is done by linker 
;// option -e in the project build options.  When the debugger loads the code,
;// it will automatically set the PC to the "entry point" address indicated by
;// the -e linker option.  In this case the debugger is simply assigning the PC, 
;// it is not the same as a full reset of the device. 
;// 
;// The compiler may warn that the entry point for the project is other then
;//  _c_init00.  _c_init00 is the C environment setup and is run before 
;// main() is entered. The code_start code will re-direct the execution 
;// to _c_init00 and thus there is no worry and this warning can be ignored. 
;// 
;//###########################################################################
;// $TI Release: f2802x Support Library v210 $
;// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
;//###########################################################################

***********************************************************************

WD_DISABLE    .set    1        ;set to 1 to disable WD, else set to 0

    .ref _InitBoot
    .global code_start

***********************************************************************
* Function: codestart section
*
* Description: Branch to code starting point
***********************************************************************

    .sect "codestart"

code_start:
    .if WD_DISABLE == 1
        LB wd_disable       ;Branch to watchdog disable code
    .else
        LB _InitBoot         ;Branch to start of boot.asm in RTS library
    .endif

;end codestart section

***********************************************************************
* Function: wd_disable
*
* Description: Disables the watchdog timer
***********************************************************************
    .if WD_DISABLE == 1

    .text
wd_disable:
    SETC OBJMODE        ;Set OBJMODE for 28x object code
    EALLOW              ;Enable EALLOW protected register access
    MOVZ DP, #7029h>>6  ;Set data page for WDCR register
    MOV @7029h, #0068h  ;Set WDDIS bit in WDCR to disable WD
    EDIS                ;Disable EALLOW protected register access
    LB _InitBoot         ;Branch to start of boot.asm in RTS library

    .endif

;end wd_disable

    .end
    
;//===========================================================================
;// End of file.
;//===========================================================================
