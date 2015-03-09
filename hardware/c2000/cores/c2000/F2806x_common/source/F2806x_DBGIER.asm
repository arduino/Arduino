;// TI File $Revision: /main/2 $ 
;// Checkin $Date: January 4, 2011   10:10:11 $ 
;//###########################################################################
;//
;// FILE:  F2806x_DBGIER.asm
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
;// $TI Release: 2806x C/C++ Header Files V1.10 $ 
;// $Release Date: April 7, 2011 $ 
;//###########################################################################	
		.global _SetDBGIER
		.text
		
_SetDBGIER:
		MOV 	*SP++,AL
		POP 	DBGIER
		LRETR
		
