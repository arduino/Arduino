/* 
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 * 
 * */
/*
 *  ======== global.h ========
 *  This header is used by C/C++ sources that want to "portably" include a
 *  configuration-specific generated header (which contains extern
 *  declarations of configuration specified global variables).
 *
 *  To use this header you must define the symbol xdc_cfg__header__ to be
 *  the package-qualified name of the configuration header.
 *
 *  For example, to compile sources that reference config values
 *  for a TI C6x target with a generated
 *  configuration header named "package/cfg/mycfg_p62.h" in a package
 *  named "local.examples" the following command line is sufficient:
 *
 *      cl6x -Dxdc_cfg__header__=local/examples/package/cfg/mycfg_p62.h ...
 */

#ifndef xdc_cfg_global__include
#define xdc_cfg_global__include

/* support old compiler option for naming config include file */
#ifdef xdc_cfg__header__
#define xdc_cfg__xheader__ <xdc_cfg__header__>
#endif

/* if specified, include configuration generated header */
#ifdef xdc_cfg__xheader__
#include xdc_cfg__xheader__
#endif

#endif
/*
 *  @(#) xdc.cfg; 1, 0, 2,0; 4-24-2015 12:33:56; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

