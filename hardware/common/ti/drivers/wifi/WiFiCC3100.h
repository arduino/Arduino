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
 /** ===========================================================================
 *  @file   WiFiCC3100.h
 *
 *  @brief  WiFi driver implementation for the SimpleLink Wi-Fi CC3100 device.
 *
 *  The WiFi header file should be included in the application as follows:
 *  @code
 *  #include <ti/drivers/WiFi.h>
 *  #include <ti/drivers/wifi/WiFiCC3100.h>
 *  @endcode
 *
 *  This WiFi driver implementation is designed for the SimpleLink Wi-Fi CC3100
 *  device on a host processor. One of the host device's SPI (SSI) peripherals
 *  will be utilized by the driver as well as its corresponding DMA channels.
 *  This means that in addition to a *WiFi_config* array, a *SPI_config* array
 *  with a host device-specific SPI entry must be provided.
 *  See @ref SPI.h, @ref SPIEUSCIADMA.h, @ref SPIEUSCIBDMA.h,
 *  @ref SPIUSCIADMA.h, @ref SPIUSCIBDMA.h, @ref SPIMSP432DMA.h and
 *  @ref SPITivaDMA.h for more details.
 *
 *  The SPI transport layer used by the CC3100 uses an IRQ line to signal the
 *  host processor to perform an action. The pin, port, and interrupt number
 *  for the IRQ pin are configured in the WiFiCC3100_HWAttrs structure. Note
 *  that no other pins on this GPIO port will be able to use GPIO interrupts
 *  while the WiFi driver is in use.
 *
 *  This WiFi driver implementation not only provides the SPI transport layer
 *  required by the SimpleLink Host Driver but also provides many of the
 *  necessary callbacks. In the case of unsolicited events that require the
 *  application to make a decision (such as an unsolicited disconnect from
 *  an AP), the SimpleLink Host Driver specifies callbacks which must be
 *  modified to fit application requirements.  Contrary to other WiFi driver
 *  implementations, callback function pointers are not provided to WiFi_open()
 *  as arguments.  An example of how to modify the SimpleLink Host Driver
 *  callbacks is shown below:
 *
 *  @code
 *  void SimpleLinkWlanEventHandler(SlWlanEvent_t *pArgs)
 *  {
 *      switch(pArgs->Event){
 *          case SL_WLAN_CONNECT_EVENT:
 *              // CC3100 connected to an AP
 *              deviceConnected = true;
 *              break;
 *
 *          case SL_WLAN_DISCONNECT_EVENT:
 *              // CC3100 disconnected from an AP
 *              deviceConnected = false;
 *              break;
 *          case SL_WLAN_SMART_CONFIG_START_EVENT:
 *              break;
 *
 *          case SL_WLAN_SMART_CONFIG_STOP_EVENT:
 *              break;
 *      }
 *  }
 *
 *  void function0()
 *  {
 *      WiFi_Handle      handle;
 *      WiFi_Params      params;
 *
 *      WiFi_Params_init(&params);
 *      handle = WiFi_open(WiFi_configIndex, SPI_configIndex, NULL, &params);
 *      if (!handle) {
 *          System_abort("WiFi did not open");
 *      }
 *
 *      // Wi-Fi device's host driver APIs (such as socket()) may now be used
 *  }
 *  @endcode
 *
 *  For a list of all events and details on what data they may provide, see
 *  the Porting - Event Handlers section of the SimpleLink Host Driver API
 *  reference guide on <a href="http://processors.wiki.ti.com/index.php/CC3100">
 *  SimpleLink Wi-Fi CC3100 Wiki</a>.
 *
 *  The SimpleLink Host Driver APIs *sl_Start()* must be called by the user
 *  application to start the network processor.  Additionally, *sl_Start()* and
 *  *sl_Stop() can be called by the application to restart the CC3100 without
 *  having to close and reopen the WiFi Driver instance.
 *
 *  The SimpleLink Host Driver for the CC3100 device is provided by TI-RTOS in
 *  the following directory in the TI-RTOS installation:
 *      * /packages/ti/drivers/wifi/cc3100
 *
 *  For more on the SimpleLink Host Driver APIs, the CC3100 SDK and to download
 *  Doxygen APIs see <a href="http://processors.wiki.ti.com/index.php/CC3100">
 *  SimpleLink Wi-Fi CC3100 Wiki</a>.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_wifi_WiFiCC3100__include
#define ti_drivers_wifi_WiFiCC3100__include

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MSP430WARE)
#include <ti/sysbios/hal/Hwi.h>
#else
#include <ti/sysbios/family/arm/m3/Hwi.h>
#endif

#include <ti/sysbios/knl/Semaphore.h>

#include <ti/drivers/SPI.h>
#include <ti/drivers/WiFi.h>

/*! @brief  WiFi function table for CC3100 devices */
extern const WiFi_FxnTable WiFiCC3100_fxnTable;

/*!
 *  @brief  SPI state machine. Not needed by user application.
 */
typedef enum WiFiCC3100_SPI_State {
    WiFiCC3100_SPI_UNINITIALIZED = 0,
    WiFiCC3100_SPI_IDLE,
    WiFiCC3100_SPI_READ_EOT,
    WiFiCC3100_SPI_READ_MSG,
    WiFiCC3100_SPI_WRITE_EOT,
    WiFiCC3100_SPI_WRITE_MSG
} WiFiCC3100_SPI_State;

/*!
 *  @brief  WiFiCC3100 Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. These definitions are found in:
 *    For TivaWare:
 *      - inc/hw_memap.h
 *      - inc/hw_ints.h
 *      - driverlib/gpio.h
 *
 *    For MSP430Ware:
 *      - gpio.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const WiFiCC3100_HWAttrs wiFiCC3100HWAttrs[] = {
 *      // TivaWare example
 *      {
 *          GPIO_PORTM_BASE,
 *          GPIO_PIN_3,
 *          INT_GPIOM,
 *
 *          GPIO_PORTH_BASE,
 *          GPIO_PIN_2,
 *
 *          GPIO_PORTC_BASE,
 *          GPIO_PIN_6
 *      }
 *      // MSP430Ware example
 *      {
 *          GPIO_PORT_P1,
 *          GPIO_PIN2,
 *          39,
 *
 *          GPIO_PORT_P3,
 *          GPIO_PIN0,
 *
 *          GPIO_PORT_P4,
 *          GPIO_PIN3
 *      }
 *  };
 *  @endcode
 */
typedef struct WiFiCC3100_HWAttrs {
    uint32_t    irqPort;       /*!< IRQ port */
    uint32_t    irqPin;        /*!< IRQ pin */
    uint32_t    irqIntNum;     /*!< IRQ port interrupt vector */

    uint32_t    csPort;        /*!< CS port */
    uint32_t    csPin;         /*!< CS pin */

    uint32_t    enPort;        /*!< WLAN EN port */
    uint32_t    enPin;         /*!< WLAN EN pin */
} WiFiCC3100_HWAttrs;

/*!
 *  @brief  WiFiCC3100 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct WiFiCC3100_Object {
    Hwi_Struct       wifiHwi;
    SPI_Handle       spiHandle;

    uint32_t         bitRate;
    unsigned int     spiIndex;

    void           (*wifiIntFxn)();

    Semaphore_Struct readSemaphore;
    Semaphore_Struct writeSemaphore;

    volatile WiFiCC3100_SPI_State spiState;

    bool             isOpen;
} WiFiCC3100_Object;

#ifdef  __cplusplus
}
#endif

#endif /* ti_drivers_wifi_WiFiCC3100__include */
