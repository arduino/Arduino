/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       Camera.h
 *
 *  @brief      Camera driver interface
 *
 *  The Camera header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/Camera.h>
 *  @endcode
 *
 *  # Operation #
 *  The Camera driver is used to retrieve the data being transferred by the
 *  Camera sensor.
 *  This driver provides API for capturing the image from the Camera sensor.
 *  The camera sensor control and implementation is the responsibility of the
 *  application using the interface.
 *
 *  The application initializes the Camera driver by calling Camera_init()
 *  and is then ready to open a Camera by calling Camera_open() and passing
 *  in a Camera parameters data structure.
 *
 *  The APIs in this driver serve as an interface to a typical TI-RTOS
 *  application. The specific peripheral implementations are responsible to
 *  create all the OSAL specific primitives to allow for thread-safe
 *  operation.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  Camera_Handle      handle;
 *  Camera_Params      params;
 *
 *  Camera_Params_init(&params);
 *  params.captureMode       =  Camera_MODE_BLOCKING;
 *  < Change any other params as required >
 *
 *  handle = Camera_open(someCamera_configIndexValue, &params);
 *  if (!handle) {
 *      System_printf("Camera did not open");
 *  }
 *  @endcode
 *
 *  ## Capturing image #
 *
 *  @code
 *  unsigned char captureBuffer[1920];
 *
 *  ret = Camera_capture(handle,&captureBuffer, sizeof(captureBuffer));
 *  @endcode
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  Camera_FxnTable.
 *
 *  The Camera driver interface module is joined (at link time) to a
 *  NULL-terminated array of Camera_Config data structures named *Camera_config*.
 *  *Camera_config* is implemented in the application with each entry being an
 *  instance of a Camera peripheral. Each entry in *Camera_config* contains a:
 *  - (Camera_FxnTable *) to a set of functions that implement a Camera peripheral
 *  - (void *) data object that is associated with the Camera_FxnTable
 *  - (void *) hardware attributes that are associated to the Camera_FxnTable
 *
 *  Currently the following Camera peripheral implementations are supported:
 *  - @ref CameraCC3200DMA.h
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_Camera__include
#define ti_drivers_Camera__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/*!
 * Common Camera_control command code reservation offset.
 * Camera driver implementations should offset command codes with CAMERA_CMD_RESERVED
 * growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define CAMERAXYZ_COMMAND0       CAMERA_CMD_RESERVED + 0
 * #define CAMERAXYZ_COMMAND1       CAMERA_CMD_RESERVED + 1
 * @endcode
 */
#define CAMERA_CMD_RESERVED          32

/*!
 * Common Camera_control status code reservation offset.
 * Camera driver implementations should offset status codes with
 * CAMERA_STATUS_RESERVED growing negatively.
 *
 * Example implementation specific status codes:
 * @code
 * #define CAMERAXYZ_STATUS_ERROR0  CAMERA_STATUS_RESERVED - 0
 * #define CAMERAXYZ_STATUS_ERROR1  CAMERA_STATUS_RESERVED - 1
 * #define CAMERAXYZ_STATUS_ERROR2  CAMERA_STATUS_RESERVED - 2
 * @endcode
 */
#define CAMERA_STATUS_RESERVED      -32

/*!
 * \brief   Successful status code returned by Camera_control().
 *
 * Camera_control() returns CAMERA_STATUS_SUCCESS if the control code was
 * executed successfully.
 */
#define CAMERA_STATUS_SUCCESS       0

/*!
 * \brief   Generic error status code returned by Camera_control().
 *
 * Camera_control() returns CAMERA_STATUS_ERROR if the control code was not
 * executed successfully.
 */
#define CAMERA_STATUS_ERROR        -1

/*!
 * \brief   An error status code returned by Camera_control() for undefined
 * command codes.
 *
 * Camera_control() returns CAMERA_STATUS_UNDEFINEDCMD if the control code is
 * not recognized by the driver implementation.
 */
#define CAMERA_STATUS_UNDEFINEDCMD -2

/*!
 *  @brief    Wait forever define
 */
#define Camera_WAIT_FOREVER ~(0)

/*!
 *  @brief      A handle that is returned from a Camera_open() call.
 */
typedef struct Camera_Config      *Camera_Handle;

/*!
 *  @brief      The definition of a callback function used by the Camera driver
 *              when used in ::Camera_MODE_CALLBACK
 *
 *  @param      Camera_Handle             Camera_Handle
 *
 *  @param      buf                       Pointer to capture buffer
 *
 *  @param      bufferLength              length of frame
 *
 */
typedef void        (*Camera_Callback)    (Camera_Handle, void *buf,
                                           size_t bufferLength);

/*!
 *  @brief      Camera capture mode settings
 *
 *  This enum defines the capture mode for the
 *  configured Camera.
 */
typedef enum Camera_CaptureMode {
    /*!
      *  Uses a semaphore to block while data is being sent.  Context of
      *  the call must be a Task.
      */
    Camera_MODE_BLOCKING,

    /*!
      *  Non-blocking and will return immediately.  When the capture
      *  by the interrupt is finished the configured callback function
      *  is called.
      */
    Camera_MODE_CALLBACK
} Camera_CaptureMode;

/*!
 *  @brief  Camera HSync polarity
 *
 *  This enum defines the polarity of the HSync signal.
 */
typedef enum Camera_HSyncPolarity {
    Camera_HSYNC_POLARITY_HIGH = 0,
    Camera_HSYNC_POLARITY_LOW
} Camera_HSyncPolarity;

/*!
 *  @brief  Camera VSync polarity
 *
 *  This enum defines the polarity of the VSync signal.
 */
typedef enum Camera_VSyncPolarity {
    Camera_VSYNC_POLARITY_HIGH = 0,
    Camera_VSYNC_POLARITY_LOW
} Camera_VSyncPolarity;

/*!
 *  @brief  Camera pixel clock configuration
 *
 *  This enum defines the pixel clock configuration.
 */
typedef enum Camera_PixelClkConfig {
    Camera_PCLK_CONFIG_RISING_EDGE = 0,
    Camera_PCLK_CONFIG_FALLING_EDGE
} Camera_PixelClkConfig;

/*!
 *  @brief  Camera byte order
 *
 *  This enum defines the byte order of camera capture.
 *
 *  In normal mode, the byte order is:
 *  | byte3 | byte2 | byte1 | byte0 |
 *
 *  In swap mode, the bytes are ordered as:
 *  | byte2 | byte3 | byte0 | byte1 |
 */
typedef enum Camera_ByteOrder {
    Camera_BYTE_ORDER_NORMAL = 0,
    Camera_BYTE_ORDER_SWAP
} Camera_ByteOrder;

/*!
 *  @brief  Camera interface synchoronisation
 *
 *  This enum defines the sensor to camera inteface synchoronisation
 *  configuration.
 */
typedef enum Camera_IfSynchoronisation {
    Camera_INTERFACE_SYNC_OFF = 0,
    Camera_INTERFACE_SYNC_ON
} Camera_IfSynchoronisation;

/*!
 *  @brief  Camera stop capture configuration
 *
 *  This enum defines the stop capture configuration.
 */
typedef enum Camera_StopCaptureConfig {
    Camera_STOP_CAPTURE_IMMEDIATE = 0,
    Camera_STOP_CAPTURE_FRAME_END
} Camera_StopCaptureConfig;

/*!
 *  @brief  Camera start capture configuration
 *
 *  This enum defines the start capture configuration.
 */
typedef enum Camera_StartCaptureConfig {
    Camera_START_CAPTURE_IMMEDIATE = 0,
    Camera_START_CAPTURE_FRAME_START
} Camera_StartCaptureConfig;

/*!
 *  @brief  Camera Parameters
 *
 *  Camera parameters are used to with the Camera_open() call.
 *  Default values for these parameters are set using Camera_Params_init().
 *
 *  If Camera_CaptureMode is set to Camera_MODE_BLOCKING then Camera_capture
 *  function calls will block thread execution until the capture has completed.
 *
 *  If Camera_CaptureMode is set to Camera_MODE_CALLBACK then Camera_capture
 *  will not block thread execution and it will call the function specified by
 *  captureCallbackFxn.
 *
 *  @sa     Camera_Params_init()
 */
typedef struct Camera_Params {
    /*!< Mode for camera capture */
    Camera_CaptureMode         captureMode;

    /*!< Output clock to set divider */
    uint32_t                    outputClock;

    /*!< Polarity of Hsync  */
    Camera_HSyncPolarity       hsyncPolarity;

    /*!< Polarity of VSync */
    Camera_VSyncPolarity       vsyncPolarity;

    /*!< Pixcel clock configuration */
    Camera_PixelClkConfig      pixelClkConfig;

    /*!< camera capture byte order */
    Camera_ByteOrder           byteOrder;

    /*!< Camera-Sensor synchoronisation */
    Camera_IfSynchoronisation  interfaceSync;

     /*!< Camera stop configuration */
    Camera_StopCaptureConfig   stopConfig;

    /*!< Camera start configuration */
    Camera_StartCaptureConfig  startConfig;

    /*!< Timeout for capture semaphore */
    uint32_t                   captureTimeout;

    /*!< Pointer to capture callback */
    Camera_Callback            captureCallback;

    /*!< Custom argument used by driver implementation */
    void                       *custom;
} Camera_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              Camera_close().
 */
typedef void        (*Camera_CloseFxn)    (Camera_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              Camera_control().
 */
typedef int         (*Camera_ControlFxn)  (Camera_Handle handle,
                                           unsigned int cmd,
                                           void *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              Camera_init().
 */
typedef void        (*Camera_InitFxn)     (Camera_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              Camera_open().
 */
typedef Camera_Handle  (*Camera_OpenFxn)   (Camera_Handle handle,
                                            Camera_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              Camera_capture().
 */
typedef int        (*Camera_CaptureFxn) (Camera_Handle handle,
                                          void *buffer, size_t bufferlen);

/*!
 *  @brief      The definition of a Camera function table that contains the
 *              required set of functions to control a specific Camera driver
 *              implementation.
 */
typedef struct Camera_FxnTable {
    /*! Function to close the specified peripheral */
    Camera_CloseFxn        closeFxn;

    /*! Function to implementation specific control function */
    Camera_ControlFxn      controlFxn;

    /*! Function to initialize the given data object */
    Camera_InitFxn         initFxn;

    /*! Function to open the specified peripheral */
    Camera_OpenFxn         openFxn;

    /*! Function to initiate a Camera capture */
    Camera_CaptureFxn     captureFxn;
} Camera_FxnTable;

/*!
 *  @brief  Camera Global configuration
 *
 *  The Camera_Config structure contains a set of pointers used to characterize
 *  the Camera driver implementation.
 *
 *  This structure needs to be defined before calling Camera_init() and it must
 *  not be changed thereafter.
 *
*  @sa     Camera_init()
 */
typedef struct Camera_Config {
    /*! Pointer to a table of driver-specific implementations of Camera APIs */
    Camera_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                  *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void            const *hwAttrs;
} Camera_Config;

/*!
 *  @brief  Function to close a Camera peripheral specified by the Camera handle
 *
 *  @pre    Camera_open() had to be called first.
 *
 *  @param  handle  A Camera_Handle returned from Camera_open
 *
 *  @sa     Camera_open()
 */
extern void Camera_close(Camera_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          Camera_Handle.
 *
 *  @pre    Camera_open() has to be called first.
 *
 *  @param  handle      A Camera handle returned from Camera_open()
 *
 *  @param  cmd         A command value defined by the driver specific
 *                      implementation
 *
 *  @param  arg         An optional R/W (read/write) argument that is
 *                      accompanied with cmd
 *
 *  @return Implementation specific return codes. Negative values indicate
 *          unsuccessful operations.
 *
 *  @sa     Camera_open()
 */
extern int Camera_control(Camera_Handle handle, uint32_t cmd, void *arg);

/*!
 *  @brief  Function to initializes the Camera module
 *
 *  @pre    The Camera_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other Camera driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern void Camera_init(void);

/*!
 *  @brief  Function to initialize a given Camera peripheral specified by the
 *          particular index value. The parameter specifies which mode the
 *          Camera will operate.
 *
 *  @pre    Camera controller has been initialized
 *
 *  @param  index         Logical peripheral number for the Camera indexed into
 *                        the Camera_config table
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *
 *  @return A Camera_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     Camera_init()
 *  @sa     Camera_close()
 */
extern Camera_Handle Camera_open(uint32_t index, Camera_Params *params);

/*!
 *  @brief  Function to initialize the Camera_Params structure to its defaults
 *
 *  @param  params      An pointer to Camera_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      captureMode       =  Camera_MODE_BLOCKING;
 *      outputClock       =  24000000;
 *      hsyncPolarity     =  Camera_HSYNC_POLARITY_HIGH;
 *      vsyncPolarity     =  Camera_VSYNC_POLARITY_HIGH;
 *      pixelClkConfig    =  Camera_PCLK_CONFIG_RISING_EDGE;
 *      byteOrder         =  Camera_BYTE_ORDER_NORMAL;
 *      interfaceSync     =  Camera_INTERFACE_SYNC_ON;
 *      stopConfig        =  Camera_STOP_CAPTURE_FRAME_END;
 *      startConfig       =  Camera_START_CAPTURE_FRAME_START;
 *      captureTimeout    =  Camera_WAIT_FOREVER;
 *      captureCallback   =  NULL;
 */
extern void Camera_Params_init(Camera_Params *params);

/*!
 *  @brief  Function that handles the Camera capture of a frame.
 *
 *  In Camera_MODE_BLOCKING, Camera_capture will block task execution until
 *  the capture is complete.
 *
 *  In Camera_MODE_CALLBACK, Camera_capture does not block task execution
 *  and calls a callback function specified by captureCallbackFxn.
 *  The Camera buffer must stay persistent until the Camera_capture
 *  function has completed!
 *
 *  @param  handle      A Camera_Handle
 *
 *  @param  buffer      A pointer to a WO (write-only) buffer into which the
 *                      captured frame is placed
 *
 *  @param  bufferlen   Length (in bytes) of the capture buffer
 *
 *  @return Number of bytes captured.
 *
 *  @sa     Camera_open
 */
extern int Camera_capture(Camera_Handle handle, void *buffer, size_t bufferlen);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_Camera__include */
