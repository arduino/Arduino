;// TI File $Revision: /main/1 $
;// Checkin $Date: August 14, 2008   16:58:21 $
;//###########################################################################
;//
;// FILE:  DSP2802x_DisInt.asm    
;//
;// TITLE: Disable and Restore INTM and DBGM
;// 
;// Function Prototypes:
;//
;//      Uint16 DSP28x_DisableInt();
;// and  void DSP28x_RestoreInt(Uint16 Stat0);
;//
;// Usage:
;//
;//      DSP28x_DisableInt() sets both the INTM and DBGM
;//      bits to disable maskable interrupts.  Before doing
;//      this, the current value of ST1 is stored on the stack
;//      so that the values can be restored later.  The value
;//      of ST1 before the masks are set is returned to the
;//      user in AL.  This is then used to restore their state
;//      via the DSP28x_RestoreInt(Uint16 ST1) function.
;//
;// Example
;//
;//   Uint16 StatusReg1    
;//   StatusReg1 = DSP28x_DisableInt();
;//
;//   ... May also want to disable INTM here
;// 
;//   ... code here
;//
;//   DSP28x_RestoreInt(StatusReg1);
;//
;//   ... Restore INTM enable
;//
;//###########################################################################
;// $TI Release: f2802x Support Library v210 $
;// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
;//###########################################################################

   .def _DSP28x_DisableInt
   .def _DSP28x_RestoreInt

_DSP28x_DisableInt:
    PUSH  ST1
    SETC  INTM,DBGM
    MOV   AL, *--SP
    LRETR

_DSP28x_RestoreInt:
    MOV   *SP++, AL
    POP   ST1
    LRETR

;//===========================================================================
;// End of file.
;//===========================================================================

   
