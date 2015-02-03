/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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
 *  @file   WiFiMSP430CC3000.h
 *
 *  @brief  WiFi driver implementation for a MSP430 device using the CC3000.
 *
 *  The WiFi header file should be included in the application as follows:
 *  @code
 *  #include <ti/drivers/WiFi.h>
 *  #include <ti/drivers/wifi/WiFiMSP430CC3000.h>
 *  @endcode
 *
 *  This WiFi driver implementation is designed to operate on a MSP430
 *  device using the SimpleLink Wi-Fi CC3000. One of the device's USCI
 *  peripherals will be utilized by the driver in SPI mode as well as two DMA
 *  channels. This means that in addition to a *WiFi_config* array, a
 *  *SPI_config* array with a SPIUSCIADMA or SPIUSCIBDMA entry must be
 *  provided. See @ref SPI.h for more details.
 *
 *  This WiFi driver implementation not only provides the SPI transport layer
 *  required by the CC3000 Host Driver but also provides many of the necessary
 *  callbacks. In the case of unsolicited events that require the application to
 *  make a decision (such as an unsolicited disconnect from an AP), a callback
 *  pointer should be provided through the WiFi_open() arguments. This callback
 *  function will be called in an interrupt context and should be designed
 *  accordingly. An example is shown below:
 *
 *  @code
 *  void callbackFxn(long eventType, char *data, unsigned char length)
 *  {
 *      switch(eventType){
 *          case HCI_EVNT_WLAN_UNSOL_CONNECT:
 *              // CC3000 connected to an AP
 *              deviceConnected = true;
 *              break;
 *
 *          case HCI_EVNT_WLAN_UNSOL_DISCONNECT:
 *              // CC3000 disconnected from an AP
 *              deviceConnected = false;
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
 *      handle = WiFi_open(WiFi_configIndex, SPI_configIndex, callbackFxn,
 *                         &params);
 *      if (!handle) {
 *          System_abort("WiFi did not open");
 *      }
 *
 *      // Wi-Fi device's host driver APIs (such as socket()) may now be used
 *  }
 *  @endcode
 *
 *  For a list of all events and details on what data they may provide, see
 *  *wlan_init()* in the <a href="http://processors.wiki.ti.com/index.php/CC3000
 *  _Wi-Fi_Downloads#CC3000_Host_Driver">CC3000 Host Driver Doxygen API
 *  reference guide</a>. The possible event macros are defined in the host
 *  driver's *cc3000_common.h*.
 *
 *  Because of the WiFi driver's control over the various callbacks used by the
 *  CC3000 Host Driver, the SimpleLink API *wlan_init()* is encapsulated in the
 *  WiFi_open() function and should <b>not</b> be called by the application. The
 *  SimpleLink APIs *wlan_start()* and *wlan_stop()* are also called within
 *  WiFi_open() and WiFi_close() respectively. However, unlike *wlan_init()*,
 *  the user application may call *wlan_stop()* and *wlan_start()* to restart
 *  the CC3000 without having to close and reopen the WiFi driver instance.
 *
 *  ## Interrupts #
 *  The SPI transport layer used by the CC3000 uses an IRQ line to signal the
 *  host MCU to perform an action. The pin and port for this IRQ pin are
 *  configured in the WiFiMSP430CC3000_HWAttrs structure. The interrupt for this
 *  GPIO port is used by the driver and a Hwi should be created with the Hwi
 *  function set to WiFiMSP430CC3000_hwiIntFxn().
 *
 *  The MSP430 DMA controller uses a single interrupt vector to handle all DMA
 *  related interrupts. Because of the "shared" nature, of the DMA's ISR, the
 *  SPI driver provides a function SPI_serviceISR() which needs to be called
 *  from within the DMA's ISR as shown below.
 *
 *  @code
 *  // As this DMA controller uses a single interrupt vector for all DMA
 *  // channels (regardless of the triggering source), it's left up to the user
 *  // to call SPI_serviceISR() to service its associated DMA channels.
 *  void myDMAISR(UArg arg)
 *  {
 *      // Services and clears the DMA channel interrupts associated with the
 *      // SPI peripheral used by WiFi
 *      SPI_serviceISR(spiHandle);
 *
 *      // other DMA code shared in this ISR
 *  }
 *  @endcode
 *
 *  ## Note about CC3000 Host Driver #
 *  It is important to note that at this time the version of the CC3000 Host
 *  Driver that TI-RTOS provides is <b>NOT</b> thread safe. That means that
 *  WiFi APIs and CC3000 Host Driver APIs are only to be called within a single
 *  task. They may not be called from Hwi or Swi context either.
 *
 *  The CC3000 Host Driver is provided by TI-RTOS in the following directory in
 *  the TI-RTOS installation:
 *      * /packages/ti/drivers/wifi/cc3000
 *
 *  For more on the SimpleLink APIs and to download the Doxygen guide see the
 *  <a href="http://processors.wiki.ti.com/index.php/CC3000">SimpleLink Wi-Fi
 *  CC3000 Wiki</a>.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_wifi_WiFiMSP430CC3000__include
#define ti_drivers_wifi_WiFiMSP430CC3000__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ti/sysbios/knl/Semaphore.h>

#include <ti/drivers/SPI.h>
#include <ti/drivers/WiFi.h>
#include <ti/drivers/wifi/cc3000/spi.h>

/* Return codes for WiFi_control() */
#define WiFiMSP430CC3000_CMD_UNDEFINED  -1

/*! @brief  WiFi function table for MSP430 devices with the CC3000 */
extern const WiFi_FxnTable WiFiMSP430CC3000_fxnTable;

/*! @brief  WiFi ISR function to be called by the IRQ's GPIO port ISR */
extern void WiFiMSP430CC3000_hwiIntFxn(UArg arg);

/*!
 *  @brief  States used by SPI state machine. Not needed by user application.
 */
typedef enum WiFiMSP430CC3000_State {
    STATE_POWERUP,
    STATE_INITIALIZED,
    STATE_IDLE,
    STATE_WRITE_EOT,
    STATE_READ_IRQ,
    STATE_READ_EOT
} WiFiMSP430CC3000_State;

/*!
 *  @brief  WiFiMSP430CC3000 Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware, these definitions are found in:
 *      - gpio.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const WiFiMSP430CC3000_HWAttrs wiFiMSP430CC3000HWAttrs[] = {
 *      {
 *          GPIO_PORT_P2,
 *          GPIO_PIN4,
 *
 *          GPIO_PORT_P2,
 *          GPIO_PIN6,
 *
 *          GPIO_PORT_P2,
 *          GPIO_PIN3
 *      }
 *  };
 *  @endcode
 */
typedef struct WiFiMSP430CC3000_HWAttrs {
    uint32_t    irqPort;       /*!< IRQ port */
    uint32_t    irqPin;        /*!< IRQ pin */

    uint32_t    csPort;        /*!< CS port */
    uint32_t    csPin;         /*!< CS pin */

    uint32_t    enPort;        /*!< WLAN EN port */
    uint32_t    enPin;         /*!< WLAN EN pin */
} WiFiMSP430CC3000_HWAttrs;

/*!
 *  @brief  WiFiMSP430CC3000 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct WiFiMSP430CC3000_Object {
    Semaphore_Struct       writeComplete;   /* Indicates a write has finished */
    SPI_Handle             spiHandle;       /* Handle for SPI module */
    RxHandlerFxn           spiRxHandler;    /* Host Driver's receive handler */
    WiFiMSP430CC3000_State volatile spiState; /* State of transfer layer */
    SPI_Transaction        transaction;     /* Transaction for SPI_transfer */
    bool                   isOpen;          /* Flag to indicate module is open */
} WiFiMSP430CC3000_Object;

#ifdef  __cplusplus
}
#endif

#endif /* ti_drivers_wifi_WiFiMSP430CC3000__include */
