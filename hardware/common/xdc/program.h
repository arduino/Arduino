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
 *  ======== program.h ========
 */

#if defined(__TI_COMPILER_VERSION__)
#warn deprecated: use xdc/cfg/global.h instead of this header
#elif defined(__GNUC__)
#warning deprecated: use xdc/cfg/global.h instead of this header
#else
static int DEPRECATED__use_the_global_h_header_in_the_xdc_cfg_package = 0;
#endif

#ifdef xdc_cfg__header__
#define xdc_cfg__xheader__ <xdc_cfg__header__>
#endif
#ifdef xdc_cfg__xheader__
#include xdc_cfg__xheader__
#endif
/*
 *  @(#) xdc; 1, 1, 1,0; 4-24-2015 12:33:46; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

