;// TI File $Revision: /main/1 $
;// Checkin $Date: August 14, 2008   16:58:15 $
;//###########################################################################
;//
;// FILE:  DSP2802x_DBGIER.asm
;//
;// TITLE: Set the DBGIER register
;//
;// DESCRIPTION:
;//  
;//  Function to set the DBGIER register (for realtime emulation).
;//  Function Prototype: void SetDBGIER(Uint16)
;//  Useage: SetDBGIER(value);
;//  Input Parameters: Uint16 value = value to put in DBGIER register. 
;//  Return Value: none          
;//
;//###########################################################################
;// $TI Release: f2802x Support Library v210 $
;// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
;//###########################################################################    
        .global _SetDBGIER
        .text
        
_SetDBGIER:
        MOV     *SP++,AL
        POP     DBGIER
        LRETR
        
