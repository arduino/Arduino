/*
 * user.h - CC31xx/CC32xx Host Driver Implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


#ifndef __USER_H__
#define __USER_H__

typedef void (*SL_P_EVENT_HANDLER)(void* pValue);


#ifdef  __cplusplus
extern "C" {
#endif


/*!
 ******************************************************************************

    \defgroup       porting_user_include        Porting - User Include Files

    This section IS NOT REQUIRED in case user provided primitives are handled
    in makefiles or project configurations (IDE)

    PORTING ACTION:
        - Include all required header files for the definition of:
            -# Transport layer library API (e.g. SPI, UART)
            -# OS primitives definitions (e.g. Task spawn, Semaphores)
            -# Memory management primitives (e.g. alloc, free)

 ******************************************************************************
 */

#include <string.h>
#include "SimpleLinkForEnergia.h"


#ifndef SL_IF_TYPE_UART
//#include "spiWrapper.h"
//already included with SimpleLinkForEnergia file
#else
#include "uart.h" //!!uart won't function! not abstracted to Energia layer
#endif


/*!
    \def        MAX_CONCURRENT_ACTIONS

    \brief      Defines the maximum number of concurrent action in the system
                Min:1 , Max: 32

                Actions which has async events as return, can be

    \sa

    \note       In case there are not enough resources for the actions needed in the system,
                error is received: POOL_IS_EMPTY
                one option is to increase MAX_CONCURRENT_ACTIONS
                (improves performance but results in memory consumption)
                Other option is to call the API later (decrease performance)

    \warning    In case of setting to one, recommend to use non-blocking recv\recvfrom to allow
                multiple socket recv
*/
#define MAX_CONCURRENT_ACTIONS 10

/*!
 ******************************************************************************

    \defgroup       porting_capabilities        Porting - Capabilities Set

    This section IS NOT REQUIRED in case one of the following pre defined
    capabilities set is in use:
    - SL_TINY
    - SL_SMALL
    - SL_FULL

    PORTING ACTION:
        - Define one of the pre-defined capabilities set or uncomment the
          relevant definitions below to select the required capabilities

    @{

 *******************************************************************************
 */

/*!
    \def        SL_INC_ARG_CHECK

    \brief      Defines whether the SimpleLink driver perform argument check
                or not

                When defined, the SimpleLink driver perform argument check on
                function call. Removing this define could reduce some code
                size and improve slightly the performances but may impact in
                unpredictable behavior in case of invalid arguments

    \sa

    \note       belongs to \ref porting_sec

    \warning    Removing argument check may cause unpredictable behavior in
                case of invalid arguments.
                In this case the user is responsible to argument validity
                (for example all handlers must not be NULL)
*/
#define SL_INC_ARG_CHECK


/*!
    \def        SL_INC_STD_BSD_API_NAMING

    \brief      Defines whether SimpleLink driver should expose standard BSD
                APIs or not

                When defined, the SimpleLink driver in addtion to its alternative
                BSD APIs expose also standard BSD APIs.
                Stadrad BSD API includs the following functions:
                socket , close , accept , bind , listen , connect , select ,
                setsockopt  , getsockopt , recv , recvfrom , write , send , sendto ,
                gethostbyname

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/

//#define SL_INC_STD_BSD_API_NAMING


/*!
    \brief      Defines whether to include extended API in SimpleLink driver
                or not

                When defined, the SimpleLink driver will include also all
                exteded API of the included packages

    \sa         ext_api

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_EXT_API

/*!
    \brief      Defines whether to include WLAN package in SimpleLink driver
                or not

                When defined, the SimpleLink driver will include also
                the WLAN package

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_WLAN_PKG

/*!
    \brief      Defines whether to include SOCKET package in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also
                the SOCKET package

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_SOCKET_PKG

/*!
    \brief      Defines whether to include NET_APP package in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also the
                NET_APP package

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_NET_APP_PKG

/*!
    \brief      Defines whether to include NET_CFG package in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also
                the NET_CFG package

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_NET_CFG_PKG

/*!
    \brief      Defines whether to include NVMEM package in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also the
                NVMEM package

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_NVMEM_PKG

/*!
    \brief      Defines whether to include socket server side APIs
                in SimpleLink driver or not

                When defined, the SimpleLink driver will include also socket
                server side APIs

    \sa         server_side

    \note

    \warning
*/
#define SL_INC_SOCK_SERVER_SIDE_API

/*!
    \brief      Defines whether to include socket client side APIs in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also socket
                client side APIs

    \sa         client_side

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_SOCK_CLIENT_SIDE_API

/*!
    \brief      Defines whether to include socket receive APIs in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also socket
                receive side APIs

    \sa         recv_api

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_SOCK_RECV_API

/*!
    \brief      Defines whether to include socket send APIs in SimpleLink
                driver or not

                When defined, the SimpleLink driver will include also socket
                send side APIs

    \sa         send_api

    \note       belongs to \ref porting_sec

    \warning
*/
#define SL_INC_SOCK_SEND_API

/*!

 Close the Doxygen group.
 @}

 */


/*!
 ******************************************************************************

    \defgroup   porting_enable_device       Porting - Device Enable/Disable

    The enable/disable API provide mechanism to enable/disable the network processor


    PORTING ACTION:
        - None
    @{

 ******************************************************************************
 */

/*!
    \brief      Enable the Network Processor

    \sa         sl_DeviceDisable

    \note       belongs to \ref porting_sec

*/
#define sl_DeviceEnable       CC3100_enable

/*!
    \brief      Disable the Network Processor

    \sa         sl_DeviceEnable

    \note       belongs to \ref porting_sec
*/
#define sl_DeviceDisable      CC3100_disable

/*!

 Close the Doxygen group.
 @}

 */

/*!
 ******************************************************************************

    \defgroup   porting_interface         Porting - Communication Interface

    The simple link device can work with different communication
    channels (e.g. spi/uart). Texas Instruments provides single driver
    that can work with all these types. This section bind between the
    physical communication interface channel and the SimpleLink driver


    \note       Correct and efficient implementation of this driver is critical
                for the performances of the SimpleLink device on this platform.


    PORTING ACTION:
        - None

    @{

 ******************************************************************************
 */

#define _SlFd_t                    int

/*!
    \brief      Opens an interface communication port to be used for communicating
                with a SimpleLink device

                Given an interface name and option flags, this function opens
                the communication port and creates a file descriptor.
                This file descriptor is used afterwards to read and write
                data from and to this specific communication channel.
                The speed, clock polarity, clock phase, chip select and all other
                specific attributes of the channel are all should be set to hardcoded
                in this function.

    \param      ifName  -   points to the interface name/path. The interface name is an
                            optional attributes that the simple link driver receives
                            on opening the driver (sl_Start).
                            In systems that the spi channel is not implemented as
                            part of the os device drivers, this parameter could be NULL.

    \param      flags   -   optional flags parameters for future use

    \return     upon successful completion, the function shall open the channel
                and return a non-negative integer representing the file descriptor.
                Otherwise, -1 shall be returned

    \sa         sl_IfClose , sl_IfRead , sl_IfWrite

    \note       The prototype of the function is as follow:
                    Fd_t xxx_IfOpen(char* pIfName , unsigned long flags);

    \note       belongs to \ref porting_sec

    \warning
*/
#ifndef SL_IF_TYPE_UART
#define sl_IfOpen                           spi_Open
#else
#define sl_IfOpen                           uart_Open
#endif
/*!
    \brief      Closes an opened interface communication port

    \param      fd  -   file descriptor of opened communication channel

    \return     upon successful completion, the function shall return 0.
                Otherwise, -1 shall be returned

    \sa         sl_IfOpen , sl_IfRead , sl_IfWrite

    \note       The prototype of the function is as follow:
                    int xxx_IfClose(Fd_t Fd);

    \note       belongs to \ref porting_sec

    \warning
*/
#ifndef SL_IF_TYPE_UART
#define sl_IfClose                          spi_Close
#else
#define sl_IfClose                          uart_Close
#endif

/*!
    \brief      Attempts to read up to len bytes from an opened communication channel
                into a buffer starting at pBuff.

    \param      fd      -   file descriptor of an opened communication channel

    \param      pBuff   -   pointer to the first location of a buffer that contains enough
                            space for all expected data

    \param      len     -   number of bytes to read from the communication channel

    \return     upon successful completion, the function shall return the number of read bytes.
                Otherwise, 0 shall be returned

    \sa         sl_IfClose , sl_IfOpen , sl_IfWrite


    \note       The prototype of the function is as follow:
                    int xxx_IfRead(Fd_t Fd , char* pBuff , int Len);

    \note       belongs to \ref porting_sec

    \warning
*/
#ifndef SL_IF_TYPE_UART
#define sl_IfRead                           spi_Read
#else
#define sl_IfRead                           uart_Read
#endif


/*!
    \brief attempts to write up to len bytes to the SPI channel

    \param      fd      -   file descriptor of an opened communication channel

    \param      pBuff   -   pointer to the first location of a buffer that contains
                            the data to send over the communication channel

    \param      len     -   number of bytes to write to the communication channel

    \return     upon successful completion, the function shall return the number of sent bytes.
                therwise, 0 shall be returned

    \sa         sl_IfClose , sl_IfOpen , sl_IfRead

    \note       This function could be implemented as zero copy and return only upon successful completion
                of writing the whole buffer, but in cases that memory allocation is not too tight, the
                function could copy the data to internal buffer, return back and complete the write in
                parallel to other activities as long as the other SPI activities would be blocked until
                the entire buffer write would be completed

               The prototype of the function is as follow:
                    int xxx_IfWrite(Fd_t Fd , char* pBuff , int Len);

    \note       belongs to \ref porting_sec

    \warning
*/
#ifndef SL_IF_TYPE_UART
#define sl_IfWrite                          spi_Write
#else
#define sl_IfWrite                          uart_Write
#endif

/*!
    \brief      register an interrupt handler routine for the host IRQ

    \param      InterruptHdl    -   pointer to interrupt handler routine

    \param      pValue          -   pointer to a memory structure that is passed
                                    to the interrupt handler.

    \return     upon successful registration, the function shall return 0.
                Otherwise, -1 shall be returned

    \sa

    \note       If there is already registered interrupt handler, the function
                should overwrite the old handler with the new one

    \note       If the handler is a null pointer, the function should un-register the
                interrupt handler, and the interrupts can be disabled.

    \note       belongs to \ref porting_sec

    \warning
*/
#define sl_IfRegIntHdlr(InterruptHdl , pValue) \
                                registerInterruptHandler(InterruptHdl , pValue)
/*!
    \brief      Masks the Host IRQ

    \sa     sl_IfUnMaskIntHdlr



    \note       belongs to \ref porting_sec

    \warning
*/
#ifndef SL_IF_TYPE_UART
#define sl_IfMaskIntHdlr()
#else
#define sl_IfMaskIntHdlr        MaskIntHdlr
#endif

/*!
    \brief      Unmasks the Host IRQ

    \sa     sl_IfMaskIntHdlr



    \note       belongs to \ref porting_sec

    \warning
*/
#ifndef SL_IF_TYPE_UART
#define sl_IfUnMaskIntHdlr()
#else
#define sl_IfUnMaskIntHdlr     UnMaskIntHdlr
#endif

/*!

 Close the Doxygen group.
 @}

 */

/*!
 ******************************************************************************

    \defgroup   porting_mem_mgm             Porting - Memory Management

    This section declare in which memory management model the SimpleLink driver
    will run:
        -# Static
        -# Dynamic

    This section IS NOT REQUIRED in case Static model is selected.

    The default memory model is Static

    PORTING ACTION:
        - If dynamic model is selected, define the alloc and free functions.

    @{

 *****************************************************************************
 */

/*!
    \brief      Defines whether the SimpleLink driver is working in dynamic
                memory model or not

                When defined, the SimpleLink driver use dynamic allocations
                if dynamic allocation is selected malloc and free functions
                must be retrieved

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/

#define SL_MEMORY_MGMT_DYNAMIC


#ifdef SL_MEMORY_MGMT_DYNAMIC

/*!
    \brief

    \sa

    \note           belongs to \ref porting_sec

    \warning
*/
#define sl_Malloc(Size)         malloc(size)

/*!
    \brief

    \sa

    \note           belongs to \ref porting_sec

    \warning
*/
#define sl_Free(pMem)           free(pMem)

#endif

/*!

 Close the Doxygen group.
 @}

 */

/*!
 ******************************************************************************

    \defgroup       porting_events      Porting - Event Handlers

    This section includes the asynchronous event handlers routines

    PORTING ACTION:
        -Uncomment the required handler and define your routine as the value
        of this handler

    @{

 ******************************************************************************
 */

/*!
    \brief

    \sa

    \note       belongs to \ref porting_sec

    \warning
*/

#define sl_GeneralEvtHdlr   SimpleLinkGeneralEventHandler


/*!
    \brief          An event handler for WLAN connection or disconnection indication
                    This event handles async WLAN events.
                    Possible events are:
                    SL_WLAN_CONNECT_EVENT - indicates WLAN is connected
                    SL_WLAN_DISCONNECT_EVENT - indicates WLAN is disconnected
    \sa

    \note           belongs to \ref porting_sec

    \warning
*/
#define sl_WlanEvtHdlr      SimpleLinkWlanEventHandler

/*!
    \brief          An event handler for IP address asynchronous event. Usually accepted after new WLAN connection.
                    This event handles networking events.
                    Possible events are:
                    SL_NETAPP_IPV4_ACQUIRED - IP address was acquired (DHCP or Static)

    \sa

    \note           belongs to \ref porting_sec

    \warning
*/

#define sl_NetAppEvtHdlr        SimpleLinkNetAppEventHandler

/*!
    \brief          A callback for HTTP server events.
                    Possible events are:
                    SL_NETAPP_HTTPGETTOKENVALUE - NWP requests to get the value of a specific token
                    SL_NETAPP_HTTPPOSTTOKENVALUE - NWP post to the host a new value for a specific token

    \param          pServerEvent - Contains the relevant event information (SL_NETAPP_HTTPGETTOKENVALUE or SL_NETAPP_HTTPPOSTTOKENVALUE)

    \param          pServerResponse - Should be filled by the user with the relevant response information (i.e SL_NETAPP_HTTPSETTOKENVALUE as a response to SL_NETAPP_HTTPGETTOKENVALUE event)

    \sa

    \note           belongs to \ref porting_sec

    \warning
*/

#define sl_HttpServerCallback   SimpleLinkHttpServerCallback

/*!
    \brief

    \sa

    \note           belongs to \ref porting_sec

    \warning
*/
#define sl_SockEvtHdlr          SimpleLinkSockEventHandler

/*!

 Close the Doxygen group.
 @}

 */


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __USER_H__ */
