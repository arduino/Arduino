/* 
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * */

/*
 *  ======== Registry__epilogue.h ========
 */

/* short name alias to make command lines and makefiles easier */
#ifdef Registry_CURDESC
#define xdc_runtime_Registry_CURDESC Registry_CURDESC
#endif

#ifdef xdc_runtime_Registry_CURDESC

__extern xdc_runtime_Registry_Desc xdc_runtime_Registry_CURDESC;

/*
 *  ======== Module__MID ========
 *  Redefine the module id to reference the module ID assigned when
 *  xdc_runtime_Registry_CURDESC was initialized by registry_addModule().
 */
#undef Module__MID
#define Module__MID xdc_runtime_Registry_CURDESC.id

/*
 *  ======== Module__DGSMASK ========
 *  Redefine the module diags mask to reference the mask that is part of 
 *  xdc_runtime_Registry_CURDESC (which is initialized at runtime).
 */
#undef Module__DGSMASK
#define Module__DGSMASK &xdc_runtime_Registry_CURDESC.mask

/*
 *  ======== Module__DGSINCL ========
 *  DGSINCL is the mask of all bits which were not configured as ALWAYS_OFF.
 *  In other words, it is the mask of all bits which could *possibly* be on.
 */
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Registry_Module__diagsIncluded__C

/*
 *  ======== Module__DGSENAB ========
 *  DGSENAB is the mask of all bits which were configured as ALWAYS_ON.
 *  If a bit is on in this mask, then the DGSMASK is not checked.
 */
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Registry_Module__diagsEnabled__C

/*
 *  ======== Module__LOGOBJ ========
 *  The handle to the module's logger instance.
 */
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Registry_Module__loggerObj__C

/*
 *  ======== Module__LOGDEF ========
 *  Whether a logger has been configured for this module.
 */
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Registry_Module__loggerDefined__C

/*
 *  ======== Module__LOGFXN ========
 *  The ILogger functions to call when logging.
 */
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Registry_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Registry_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Registry_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Registry_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Registry_Module__loggerFxn8__C

#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:13; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

