//*****************************************************************************
// spi_drv.h - API and other data constructs to operate SPI Driver.
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************


#ifndef __SPI_DRV_H__
#define __SPI_DRV_H__

#include "cc_pm.h"
#include "osi.h"
#include "spi_hal.h"

/*
*   OS port APIs
*/
#define RTOS_SEM_CREATE(x)      osi_SyncObjCreate(x)
#define RTOS_SEM_WAIT(x)        osi_SyncObjWait(x, OSI_WAIT_FOREVER)
#define RTOS_SEM_SIGNAL(x)      osi_SyncObjSignalFromISR(x)
#define RTOS_SEM_DELETE(x)      osi_SyncObjDelete(x)

#define RTOS_MUTEX_CREATE(x)        osi_LockObjCreate(x)
#define RTOS_MUTEX_ACQUIRE(x)       osi_LockObjLock(x, OSI_WAIT_FOREVER)
#define RTOS_MUTEX_ACQUIRE_IMM(x)   osi_LockObjLock(x, OSI_NO_WAIT)
#define RTOS_MUTEX_RELEASE(x)       osi_LockObjUnlock(x)
#define RTOS_MUTEX_DELETE(x)        osi_LockObjDelete(x)

/*!
*
*  \brief The function checks if the request state transition can be supported
*   and also initiates the corresponding action with the HAL.
*
*  \param  mod_drv is the pointer to module driver structure
*  \param  pm_state is the requested next state of the module
*
*  \return 0: on success, -1: cannot transition to specified state
*
*/
i32 spi_handle_pm_cmd(struct module_drv *mod_drv, const enum mod_pm pm_state);

/*! 
*   \brief This function should be called from centralized & RTOS specific 
*   initialization sequence. 
*
*   Goal of this function is to extend information about SOC module to SW driver 
*   enable it to initialize hardware through HAL. Driver could use private field 
*   called 'hw_detail', if provisioned, to configure hardware. 
*
*   Driver instance must enroll / register itself with PM / platfrom framework.
*
*   \param spi_module mainly has the platform specific details as well as the 
*          module initial configuration information.
*
*   \return 0: on success, < 0: on error
*
*/
i32 spi_driver_load(struct soc_module *spi_module);

/*!
*   \brief Open the SPI module.
*   This function returns the driver context of the specified module. The API
*   has to be invoked only after the driver has been loaded.
*   
*   \param module_id is the module identifier for the platform.
*    This field should match the identifier specified while loading the driver.
*
*   \return on success a handle specific indicated instance of HW, otherwise
*           NULL on error.
*/
cc_hndl spi_open(u32 module_id);

/*!
*   \brief Close the SPI module.
*   Invocation of this function signifies that the services of the module will
*   no longer be required by the subscriber who invoked the spi_open.
*   
*   \param spi_drv_hndl is the handle to the SPI driver.
*
*   \return 0: on success, < 0: on error.
*/
i32 spi_close(cc_hndl spi_drv_hndl);

/*!
*   \brief Half duplex Write data over SPI.
*   The API enables transmitting the specified buffer contents over SPI.
*   The values read during the SPI transactions are discarded.
*   
*   \param spi_drv_hndl is the handle to the SPI driver.
*   \param wr_data is the pointer to the data to be transmitted.
*   \param size is the length of data to be transmitted.
*
*   \return number of bytes pending: on success/partial success, < 0: on error.
*/
i32 spi_write(cc_hndl spi_drv_hndl, const i8 *wr_data, i32 size);

/*!
*   \brief Half duplex Read data over SPI.
*   The API enables reception of the specified length into the specified 
*   buffer over SPI. The dummy bytes (DUMMY_SPI_WORD (0xFF)) are written 
*   during the SPI transactions.
*   
*   \param spi_drv_hndl is the handle to the SPI driver.
*   \param rd_data is the pointer to the buffer to be filled.
*   \param size is the length of data to be received.
*
*   \return number of bytes pending: on success/partial success, < 0: on error.
*/
i32 spi_read(cc_hndl spi_drv_hndl, i8 *rd_data, i32 size);

/*!
*   \brief Full duplex Write-Read over SPI.
*   The API enables transmission-reception of the specified length from-into
*   the specified buffers over SPI. Both the buffer must be able to accomodate
*   the specified transaction size.
*   
*   \param spi_drv_hndl is the handle to the SPI driver.
*   \param wr_data is the pointer to the data to be transmitted.
*   \param rd_data is the pointer to the buffer to be filled.
*   \param size is the transaction size.
*
*   \return number of bytes pending: on success/partial success, < 0: on error.
*/
i32 spi_write_read(cc_hndl spi_drv_hndl, const i8 *wr_data, 
                   i8 *rd_data, i32 size);

#endif // __SPI_DRV_H__
