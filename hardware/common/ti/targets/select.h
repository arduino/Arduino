/*
 *  Copyright 2015 by Texas Instruments Incorporated.
 *
 */

/*
 *  ======== select.h ========
 *  This header selects an appropriate target name based on TI compiler
 *  predefined macros and includes the appropriate target-specific std.h.
 *
 *  This header is entirely optional: the user can directly select any
 *  existing target by adding definition of the following two symbols to
 *  the compile line:
 *    xdc_target_name__     the short name of the target; e.g., C64P
 *    xdc_target_types__    a package path relative path to the types header
 *                          for the target; e.g., ti/targets/std.h
 *
 *  For more information about these symbols see:
 *  http://rtsc.eclipse.org/docs-tip/Integrating_RTSC_Modules
 */

/*
 *  ======== MSP430 ========
 */
#if defined(__MSP430__)
#  if defined(__MSP430X__)
     /* --silicon_version=mspx is specified */
#    if defined(__LARGE_CODE_MODEL__)
       /* --code_model=large is specified */
#      define xdc_target_name__ MSP430X
#    else
#      define xdc_target_name__ MSP430X_small
#    endif
#  else
#    define xdc_target_name__ MSP430
#  endif
#  if __TI_EABI__ == 1
#    define xdc_target_types__ ti/targets/msp430/elf/std.h
#  else
#    define xdc_target_types__ ti/targets/msp430/std.h
#  endif

/*
 *  ======== TMS320C6X ========
 */
#elif defined(_TMS320C6X)
#  if __TI_EABI__ == 1
     /* set to 1 if compiling for EABI (ELF) and is set to 0 otherwise. */
#    define xdc_target_types__ ti/targets/elf/std.h
#  else
#    define xdc_target_types__ ti/targets/std.h
#  endif

#  if defined(_BIG_ENDIAN)
#    if defined(_TMS320C6600)
#      define xdc_target_name__ C66_big_endian
#    elif defined(_TI_C6X_TESLA)
#      define xdc_target_name__ C64T_big_endian
#    elif defined(_TMS320C6740)
#      define xdc_target_name__ C674_big_endian
#    elif defined(_TMS320C6400_PLUS)
#      define xdc_target_name__ C64P_big_endian
#    endif
#  else
#    if defined(_TMS320C6600)
#      define xdc_target_name__ C66
#    elif defined(_TI_C6X_TESLA)
#      define xdc_target_name__ C64T
#    elif defined(_TMS320C6740)
#      define xdc_target_name__ C674
#    elif defined(_TMS320C6400_PLUS)
#      define xdc_target_name__ C64P
#    elif defined(_TMS320C6700_PLUS)
#      define xdc_target_name__ C67P
#    endif
#  endif
/*
 *  ======== ARP32 ========
 *  ARP32 (EVE) devices
 */
#elif defined (__ARP32__)
#  define xdc_target_types__ ti/targets/arp32/elf/std.h
#  define xdc_target_name__ ARP32

/*
 *  ======== TMS470 ========
 *  Arm devices
 */
#elif defined (__TMS470__)
#  if defined(__TI_EABI_SUPPORT__)
     /* Defined to 1 if the --abi=eabi option is used */
#    define xdc_target_types__ ti/targets/arm/elf/std.h
#  else
#    define xdc_target_types__ ti/targets/arm/std.h
#  endif

#  if defined (__TI_TMS470_V4__)
     /* Defined to 1 if the ARM7 is targeted (the -mv4 option is used); */
#    if defined(__big_endian__)
#      define xdc_target_name__ Arm7_big_endian
#    else
#      define xdc_target_name__ Arm7
#    endif

#  elif defined(__TI_TMS470_V5__)
     /* Defined to 1 if the ARM9E is targeted (the -mv5e option is used); */
#    if defined(__16bis__)
#      define xdc_target_name__ Arm9t
#    else
#      define xdc_target_name__ Arm9
#    endif
#  elif defined(__TI_TMS470_V7A8__)
     /* Defined to 1 if the Cortex-A8 is targeted ( -mv7A8 option is used) */
#    if defined(__16bis__)
#      define xdc_target_name__ A8Ft
#    else
#      if defined(__TI_VFP_SUPPORT__)
#        if defined(__TI_NEON_SUPPORT__)
#          define xdc_target_name__ A8Fnv
#        else
#          define xdc_target_name__ A8Fv
#        endif
#      else
#        if defined(__TI_NEON_SUPPORT__)
#          define xdc_target_name__ A8F
#        else
#          define xdc_target_name__ A8
#        endif
#      endif
#    endif

#  elif defined(__TI_TMS470_V7M3__)
     /* Defined to 1 if Cortex-M3 is targeted (the -mv7M3 option is used); */
#    if defined(__big_endian__)
#      define xdc_target_name__ M3_big_endian
#    else
#      define xdc_target_name__ M3
#    endif

#  elif defined(__TI_TMS470_V7M4__)
     /* Defined to 1 if Cortex-M4 is targeted (the -mv7M4 option is used); */
#    if defined(__TI_VFP_SUPPORT__)
#      define xdc_target_name__ M4F
#    else
#      define xdc_target_name__ M4
#    endif

#  elif defined(__TI_TMS470_V7R4__)
     /* Defined to 1 if Cortex-R4 is targeted (the -mv7R4 option is used); */
#    if defined(__big_endian__)
#      if defined(__16bis__)
#        if defined(__TI_VFP_SUPPORT__)
#          define xdc_target_name__ R4Ft_big_endian
#        else
#          define xdc_target_name__ R4t_big_endian
#        endif
#      else
#        if defined(__TI_VFP_SUPPORT__)
#          define xdc_target_name__ R4F_big_endian
#        else
#          define xdc_target_name__ R4_big_endian
#        endif
#      endif
#    else
#      if defined(__16bis__)
#        if defined(__TI_VFP_SUPPORT__)
#          define xdc_target_name__ R4Ft
#        else
#          define xdc_target_name__ R4t
#        endif
#      else
#        if defined(__TI_VFP_SUPPORT__)
#          define xdc_target_name__ R4F
#        else
#          define xdc_target_name__ R4
#        endif
#      endif
#    endif
#  endif

/*
 *  ======== TMS320C28XX ========
 */
#elif defined(__TMS320C28XX__)
#  if defined(__LARGE_MODEL__)
     /* large-model code is selected (the -ml option is used) */
#    if defined(__TMS320C28XX_FPU32__)
       /* 32-bit hardware floating-point support (--float_support=fpu32) */
#      define xdc_target_name__ C28_float
#    elif defined(__TMS320C28XX_FPU64__)
       /* 64-bit hardware floating-point support (--float_support=fpu64) */
#      error 64-bit floating point target does not exist (yet)
#    else
#      define xdc_target_name__ C28_large
#    endif
#  else
     /* small-model */
#    define xdc_target_name__ C28
#  endif
#  define xdc_target_types__ ti/targets/std.h

#else
#  warn can't determine an appropriate setting for xdc_target_types__; unknown ISA
#endif

#if defined(xdc_target_name__) && defined(xdc_target_types__)
/*
 *  ======== include the selected type header ========
 */
#define xdc_target__ <xdc_target_types__>
#include xdc_target__

#else
  /* if we get here, this header was unable to select an appropriate set of
   * types.  If the target exists, you can avoid the warnings below by
   * explicitly defining the symbols xdc_target_name__ and
   * xdc_target_types__ on the compile line.
   */
#  ifndef xdc_target_name__
#    warn can't determine an appropriate setting for xdc_target_name__
#  endif
#  ifndef xdc_target_types__
#    warn can't determine an appropriate setting for xdc_target_types__
#  endif
#endif
/*
 *  @(#) ti.targets; 1, 0, 3,5; 2-27-2015 12:11:33; /db/ztree/library/trees/xdctargets/xdctargets-i02/src/ xlibrary

 */

