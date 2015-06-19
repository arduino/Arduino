/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_BIOS__INTERNAL__
#define ti_sysbios_BIOS__INTERNAL__

#ifndef ti_sysbios_BIOS__internalaccess
#define ti_sysbios_BIOS__internalaccess
#endif

#include <ti/sysbios/BIOS.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* start */
#undef ti_sysbios_BIOS_start
#define ti_sysbios_BIOS_start ti_sysbios_BIOS_start__E

/* exit */
#undef ti_sysbios_BIOS_exit
#define ti_sysbios_BIOS_exit ti_sysbios_BIOS_exit__E

/* getThreadType */
#undef ti_sysbios_BIOS_getThreadType
#define ti_sysbios_BIOS_getThreadType ti_sysbios_BIOS_getThreadType__E

/* setThreadType */
#undef ti_sysbios_BIOS_setThreadType
#define ti_sysbios_BIOS_setThreadType ti_sysbios_BIOS_setThreadType__E

/* setCpuFreq */
#undef ti_sysbios_BIOS_setCpuFreq
#define ti_sysbios_BIOS_setCpuFreq ti_sysbios_BIOS_setCpuFreq__E

/* getCpuFreq */
#undef ti_sysbios_BIOS_getCpuFreq
#define ti_sysbios_BIOS_getCpuFreq ti_sysbios_BIOS_getCpuFreq__E

/* errorRaiseHook */
#define BIOS_errorRaiseHook ti_sysbios_BIOS_errorRaiseHook__I

/* startFunc */
#define BIOS_startFunc ti_sysbios_BIOS_startFunc__I

/* atExitFunc */
#define BIOS_atExitFunc ti_sysbios_BIOS_atExitFunc__I

/* exitFunc */
#define BIOS_exitFunc ti_sysbios_BIOS_exitFunc__I

/* registerRTSLock */
#define BIOS_registerRTSLock ti_sysbios_BIOS_registerRTSLock__I

/* removeRTSLock */
#define BIOS_removeRTSLock ti_sysbios_BIOS_removeRTSLock__I

/* rtsLock */
#define BIOS_rtsLock ti_sysbios_BIOS_rtsLock__I

/* rtsUnlock */
#define BIOS_rtsUnlock ti_sysbios_BIOS_rtsUnlock__I

/* nullFunc */
#define BIOS_nullFunc ti_sysbios_BIOS_nullFunc__I

/* Module_startup */
#undef ti_sysbios_BIOS_Module_startup
#define ti_sysbios_BIOS_Module_startup ti_sysbios_BIOS_Module_startup__E

/* Instance_init */
#undef ti_sysbios_BIOS_Instance_init
#define ti_sysbios_BIOS_Instance_init ti_sysbios_BIOS_Instance_init__E

/* Instance_finalize */
#undef ti_sysbios_BIOS_Instance_finalize
#define ti_sysbios_BIOS_Instance_finalize ti_sysbios_BIOS_Instance_finalize__E

/* module */
#define BIOS_module ((ti_sysbios_BIOS_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_BIOS_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_sysbios_BIOS__cplusplus)
#define module ((ti_sysbios_BIOS_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_BIOS_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_BIOS_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_BIOS_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_BIOS_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_BIOS_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_BIOS_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_BIOS_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_BIOS_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_BIOS_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_BIOS_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_BIOS_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_BIOS_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_BIOS_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_BIOS_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_BIOS_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_BIOS_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_BIOS_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_BIOS_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_BIOS_Module_GateProxy_query


#endif /* ti_sysbios_BIOS__INTERNAL____ */
