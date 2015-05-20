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

/*!*****************************************************************************
 *  @file       PINCC26XX.h
 *  @brief      Device-specific pin & GPIO driver for CC26xx family [def]
 *
 *  # Overview #
 *  This is the device-specific implementation of the generic PIN driver for the
 *  CC26xx family of devices.
 *
 *******************************************************************************
 */

#ifndef ti_drivers_PINCC26XX__include
#define ti_drivers_PINCC26XX__include
#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/PIN.h>
#include <driverlib/ioc.h>
#include <driverlib/gpio.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>

#include <stdint.h>
#include <stddef.h>



//------------------------------------------------------------------------------
// Internal function used to find the index of the rightmost set bit in
// efficient way
#if defined(__IAR_SYSTEMS_ICC__) || defined(DOXYGEN)
    #include <intrinsics.h>
#endif

__STATIC_INLINE uint32_t PIN_ctz(uint32_t x) {
#if defined(codered) || defined(gcc) || defined(sourcerygxx)
    return __builtin_ctz(x);
#elif defined(__IAR_SYSTEMS_ICC__) || defined(DOXYGEN)
    return __CLZ(__RBIT(x));
#elif defined(rvmdk) || defined(__ARMCC_VERSION)
    return __clz(__rbit(x));
#elif defined(__TI_COMPILER_VERSION__)
    return __clz(__rbit(x));
#else
    #error "Unsupported compiler used"
#endif
}

//------------------------------------------------------------------------------

// Constant that can be used to remove run-time checks for improved efficiency
// Activate through preprocessor define PIN_DISABLE_RUNTIME_CHECKS
#ifdef PIN_DISABLE_RUNTIME_CHECKS
    #define PIN_CHKEN 0
#else
    #define PIN_CHKEN 1
#endif

/** \anchor PINCC26XX_FLAGS
 *  \name Device-specific PIN_Config flags/fields for CC26xx family
 * \{
 * CC26XX-specific I/O configuration fields/flags for use in #PIN_Config
 * entries. These fields flags/for the most part map directly to the values
 * used in the \c IOCFG hardware registers for efficiency. May not be mixed
 * with \ref PIN_GENERIC_FLAGS "device-independent I/O options".
 */
#define PINCC26XX_INPUT_EN          (1<<29)         ///< Enable input buffer
#define PINCC26XX_HYSTERESIS        (1<<30)         ///< Enable input buffer hysteresis
#define PINCC26XX_NOPULL            (0x3<<13)       ///< No pull-up or pull-down resistor
#define PINCC26XX_PULLUP            (0x2<<13)       ///< ~20k pull-up resistor enabled
#define PINCC26XX_PULLDOWN          (0x1<<13)       ///< ~20k pull-down resistor enabled
#define PINCC26XX_BM_INPUT_EN       (0x01<<29)      ///< Bitmask for input enable option
#define PINCC26XX_BM_HYSTERESIS     (0x01<<30)      ///< Bitmask for all input mode options
#define PINCC26XX_BM_PULLING        (0x03<<13)      ///< Bitmask for pull-up/pull-down options
/// Bitmask for all input mode options
#define PINCC26XX_BM_INPUT_MODE     (PINCC26XX_BM_INPUT_EN|PINCC26XX_BM_HYSTERESIS| \
                                     PINCC26XX_BM_PULLING)

#define PINCC26XX_GPIO_OUTPUT_EN    (1<<23)     ///< Enable output buffer when GPIO
#define PINCC26XX_GPIO_LOW          (0<<22)     ///< Output buffer drives to VSS when GPIO
#define PINCC26XX_GPIO_HIGH         (1<<22)     ///< Output buffer drives to VDD when GPIO
#define PINCC26XX_PUSHPULL          (0x0<<25)   ///< Output buffer mode: push/pull
#define PINCC26XX_OPENDRAIN         (0x2<<25)   ///< Output buffer mode: open drain
#define PINCC26XX_OPENSOURCE        (0x3<<25)   ///< Output buffer mode: open source
#define PINCC26XX_SLEWCTRL          (1<<12)     ///< Enable output buffer slew control
#define PINCC26XX_DRVSTR_MIN        (0x0<<8)    ///< Drive strength is 2/2 mA
#define PINCC26XX_DRVSTR_MED        (0x4<<8)    ///< Drive strength is 4/4 mA
#define PINCC26XX_DRVSTR_MAX        (0x8<<8)    ///< Drive strength is 4/8 mA
#define PINCC26XX_BM_GPIO_OUTPUT_EN (1<<23)     ///< Bitmask for output enable option
#define PINCC26XX_BM_GPIO_OUTPUT_VAL (1<<22)    ///< Bitmask for output value option
#define PINCC26XX_BM_OUTPUT_BUF     (3<<25)     ///< Bitmask for output buffer options
#define PINCC26XX_BM_SLEWCTRL       (1<<12)     ///< Bitmask for slew control options
#define PINCC26XX_BM_DRVSTR         (0xF<<8)    ///< Bitmask for drive strength options
/// Bitmask for all GPIO output mode options
#define PINCC26XX_BM_GPIO_OUTPUT_MODE (PINCC26XX_BM_GPIO_OUTPUT_EN|PINCC26XX_BM_GPIO_OUTPUT_VAL)
/// Bitmask for all output mode options
#define PINCC26XX_BM_OUTPUT_MODE    (PINCC26XX_BM_GPIO_OUTPUT_MODE|PINCC26XX_BM_OUTPUT_BUF| \
                                     PINCC26XX_BM_SLEWCTRL|PINCC26XX_BM_DRVSTR)

#define PINCC26XX_INV_INOUT         (1<<24)     ///< Logically invert input and output
#define PINCC26XX_IRQ_DIS           (0x0<<16)   ///< Enable IRQ on pin
#define PINCC26XX_IRQ_NEGEDGE       (0x5<<16)   ///< IRQ on negative edge
#define PINCC26XX_IRQ_POSEDGE       (0x6<<16)   ///< IRQ on positive edge
#define PINCC26XX_IRQ_BOTHEDGES     (0x7<<16)   ///< IRQ on both edges
#define PINCC26XX_BM_INV_INOUT      (1<<24)     ///< Bitmask for input/output inversion option
#define PINCC26XX_BM_IRQ            (0x7<<16)   ///< Bitmask for pin interrupt option

#define PINCC26XX_NO_WAKEUP         (0<<27)     ///< No wakeup from shutdown for this pin
#define PINCC26XX_WAKEUP_POSEDGE    (3<<27)     ///< Wakeup from shutdown on positive edge
#define PINCC26XX_WAKEUP_NEGEDGE    (2<<27)     ///< Wakeup from shutdown on negative edge
#define PINCC26XX_BM_WAKEUP         (3<<27)     ///< Bitmask for pin wakeup from shutdown option

/// Bitmask for all pin options in IOCFG register
#define PINCC26XX_BM_IOCFG          (PINCC26XX_BM_INPUT_MODE|PINCC26XX_BM_OUTPUT_BUF| \
                                     PINCC26XX_BM_SLEWCTRL|PINCC26XX_BM_DRVSTR| \
                                     PINCC26XX_BM_INV_INOUT|PINCC26XX_BM_IRQ|PINCC26XX_BM_WAKEUP)
/// Bitmask for all pin options
#define PINCC26XX_BM_ALL            (PINCC26XX_BM_IOCFG|PINCC26XX_BM_GPIO_OUTPUT_MODE)

/** \} (PINCC26XX_FLAGS)
 */

/** \anchor PINCC26XX_IONAMES
 *  \name PIN names for the CC26xx family
 *  \{
 *  The digital I/O pins in the CC26xx family are named DIOx, where x is from
 *  0 to IO_MAX. Numeric IO indexes for x can be used directly, i.e. 5 or
 *  PIN_ID(5). For convenience and readability aliases are defined below for
 *  all DIOs.
 */
#define PINCC26XX_DIO0    0
#define PINCC26XX_DIO1    1
#define PINCC26XX_DIO2    2
#define PINCC26XX_DIO3    3
#define PINCC26XX_DIO4    4
#define PINCC26XX_DIO5    5
#define PINCC26XX_DIO6    6
#define PINCC26XX_DIO7    7
#define PINCC26XX_DIO8    8
#define PINCC26XX_DIO9    9
#define PINCC26XX_DIO10   10
#define PINCC26XX_DIO11   11
#define PINCC26XX_DIO12   12
#define PINCC26XX_DIO13   13
#define PINCC26XX_DIO14   14
#define PINCC26XX_DIO15   15
#define PINCC26XX_DIO16   16
#define PINCC26XX_DIO17   17
#define PINCC26XX_DIO18   18
#define PINCC26XX_DIO19   19
#define PINCC26XX_DIO20   20
#define PINCC26XX_DIO21   21
#define PINCC26XX_DIO22   22
#define PINCC26XX_DIO23   23
#define PINCC26XX_DIO24   24
#define PINCC26XX_DIO25   25
#define PINCC26XX_DIO26   26
#define PINCC26XX_DIO27   27
#define PINCC26XX_DIO28   28
#define PINCC26XX_DIO29   29
#define PINCC26XX_DIO30   30
#define PINCC26XX_DIO31   31
/** \} (PINCC26XX_IONAMES)
 */


// Array of handles, one per pin (pin id is index)
extern PIN_Handle PIN_HandleTable[];

// Number of pins available on device
extern uint_t PIN_NumPins;


/// \brief Fast/efficient version of #PIN_getInputValue()
__STATIC_INLINE uint_t PINCC26XX_getInputValue(PIN_Id pinId) {
    return (HWREG(GPIO_BASE+GPIO_O_DIN31_0)>>pinId)&1;
}


/* \brief Fast/efficient version of #PIN_setOutputEnable()
 * \note  Does not include any checks on handle for efficiency reasons,
 *        use #PIN_setOutputEnable() for checked version
 */
__STATIC_INLINE void PINCC26XX_setOutputEnable(PIN_Id pinId, bool bOutEn) {
    uint32_t key = Hwi_disable();
        HWREG(GPIO_BASE+GPIO_O_DOE31_0) =
            ((HWREG(GPIO_BASE+GPIO_O_DOE31_0) & ~(1<<pinId)) | (bOutEn<<pinId));
    Hwi_restore(key);
}


/* \brief Fast/efficient version of #PIN_setOutputValue()
 * \note  Does not include any checks on handle for efficiency reasons,
 *        use #PIN_setOutputValue() for checked version
 */
__STATIC_INLINE void PINCC26XX_setOutputValue(PIN_Id pinId, uint_t val) {
    HWREGB(GPIO_BASE+GPIO_O_DOUT3_0+pinId) = (val) ? 1 : 0;
}


/// \brief Fast/efficient version of #PIN_getOutputValue()
__STATIC_INLINE uint_t PINCC26XX_getOutputValue(PIN_Id pinId) {
    return (HWREG(GPIO_BASE+GPIO_O_DOUT31_0)>>pinId)&1;
}


__STATIC_INLINE void PINCC26XX_clrPendInterrupt(PIN_Id pinId) {
    HWREG(GPIO_NONBUF_BASE+GPIO_O_EVFLAGS31_0) = (1<<pinId);
}


/// \brief Fast/efficient version of #PIN_getPortInputValue()
__STATIC_INLINE uint_t PINCC26XX_getPortInputValue(PIN_Handle handle) {
    // Only a single port on CC26xx
    return HWREG(GPIO_BASE+GPIO_O_DIN31_0);
}


/// \brief Fast/efficient version of #PIN_getPortOutputValue()
__STATIC_INLINE uint_t PINCC26XX_getPortOutputValue(PIN_Handle handle) {
    // Only a single port on CC26xx
    return HWREG(GPIO_BASE+GPIO_O_DOUT31_0);
}


/* \brief Fast/efficient version of #PIN_setPortOutputValue()
 * \note  Does not include any checks on handle for efficiency reasons,
 *        use #PIN_setPortOutputValue() for checked version
 */
__STATIC_INLINE void PINCC26XX_setPortOutputValue(PIN_Handle handle, uint_t bmOutVal) {
    // Only a single port on CC26xx
    HWREG(GPIO_BASE+GPIO_O_DOUTTGL31_0) =
         (HWREG(GPIO_BASE+GPIO_O_DOUT31_0) ^ bmOutVal) & handle->bmPort;
}


/* \brief Fast/efficient version of #PIN_setPortOutputEnable()
 * \note  Does not include any checks on handle for efficiency reasons,
 *        use #PIN_setPortOutputEnable() for checked version
 */
__STATIC_INLINE void PINCC26XX_setPortOutputEnable(PIN_Handle handle, uint_t bmOutEn) {
    // Only a single port on CC26xx
    uint32_t key = Hwi_disable();
        HWREG(GPIO_BASE+GPIO_O_DOE31_0) =
            (HWREG(GPIO_BASE+GPIO_O_DOE31_0) & (~handle->bmPort)) | (bmOutEn  & handle->bmPort);
    Hwi_restore(key);
}


/** \brief Returns CC26xx device-specific pin configuration
 *
 *  \param pinId    Pin ID
 *  \return  Current pin configuration as a #PIN_Config value
 *  \note    The pin ID is embedded in return value.
 *  \note    Return value uses \ref PINCC26XX_FLAGS "CC26xx specific I/O options"
 */
extern PIN_Config PINCC26XX_getConfig(PIN_Id pinId);


/** \brief Configure wakeup (from shutdown) on pins
 *
 *  \param aPinCfg #PIN_Config list identifying pin ID and relevant pin
 *                 configuration as one of:
 *                 - #PINCC26XX_NO_WAKEUP      (default)
 *                 - #PINCC26XX_WAKEUP_POSEDGE
 *                 - #PINCC26XX_WAKEUP_NEGEDGE
 *  \return #PIN_SUCCESS if successful, else error code
 *  \todo   Define properly
 *  \par Usage
 *       \code
 *       PIN_setWakeup(NULL, PIN_ID(9)|PIN_WAKEUP_NEGEDGE);
 *       Power_enterShutdown();
 *       \endcode
 */
extern PIN_Status PINCC26XX_setWakeup(const PIN_Config aPinCfg[]);


/** \brief Get device-specific pin mapping to GPIO, HW peripheral or HW signal
 *
 *  \param pinId    Pin ID
 *  \return Device-specific pin mapping index for connection to hardware
 *          peripheral or hardware signal, -1 if pin is used for GPIO
 *  \note  Mostly used by driver code
 *  \par Usage
 *       \code
 *       if (PINCC26XX_getMux(PIN_ID(16)) < 0) {
 *          // Pin is GPIO
 *       }
 *       \endcode
 */
extern int_t PINCC26XX_getMux(PIN_Id pinId);


/** \brief Connect pin to HW peripheral, signal or to GPIO
 *
 *  \param handle  Handle provided by previous call to PIN_open()
 *  \param pinId   Pin ID
 *  \param nMux    Device-specific index of peripheral port or hardware signal.
 *                 A value of -1 reverts the pin to GPIO mapping
 *  \return #PIN_SUCCESS if successful, else error code
 *  \note  Mostly used by driver code or for diagnostics
 *  \par Usage
 *       \code
 *       PIN_setMux(hPins, PIN_ID(16), PINCC26XX_UART_TX);
 *       \endcode
 */
extern PIN_Status PINCC26XX_setMux(PIN_Handle handle, PIN_Id pinId, int32_t nMux);



/** \anchor PINCC26XX_MUX_VALS
 *  \name Device-specific pin mux values for CC26xx family
 *  \ deprecated Use IOC_PORT_* defines from driverlib/ioc.h directly instead
 *  \{
 *  CC26XX-specific mux vakues used in conjunction with #PINCC26XX_setMux() to
 *  map hardware peripheral ports, GPIO or observation signals to pins.
 */
#define PINCC26XX_MUX_GPIO           IOC_PORT_GPIO            // Default general purpose IO usage
#define PINCC26XX_MUX_AON_SCS        IOC_PORT_AON_SCS         // AON SPI-S SCS Pin
#define PINCC26XX_MUX_AON_SCK        IOC_PORT_AON_SCK         // AON SPI-S SCK Pin
#define PINCC26XX_MUX_AON_SDI        IOC_PORT_AON_SDI         // AON SPI-S SDI Pin
#define PINCC26XX_MUX_AON_SDO        IOC_PORT_AON_SDO         // AON SPI-S SDO Pin
#define PINCC26XX_MUX_AON_TDI        IOC_PORT_AON_TDI         // AON JTAG TDI Pin
#define PINCC26XX_MUX_AON_TDO        IOC_PORT_AON_TDO         // AON JTAG TDO Pin
#define PINCC26XX_MUX_AON_CLK32K     IOC_PORT_AON_CLK32K      // AON External 32kHz clock
#define PINCC26XX_MUX_AUX_IO         IOC_PORT_AUX_IO          // AUX IO Pin
#define PINCC26XX_MUX_MCU_SSI0_RX    IOC_PORT_MCU_SSI0_RX     // MCU SSI0 Receive Pin
#define PINCC26XX_MUX_MCU_SSI0_TX    IOC_PORT_MCU_SSI0_TX     // MCU SSI0 Transmit Pin
#define PINCC26XX_MUX_MCU_SSI0_FSS   IOC_PORT_MCU_SSI0_FSS    // MCU SSI0 FSS Pin
#define PINCC26XX_MUX_MCU_SSI0_CLK   IOC_PORT_MCU_SSI0_CLK    // MCU SSI0 Clock Pin
#define PINCC26XX_MUX_MCU_I2C_MSSDA  IOC_PORT_MCU_I2C_MSSDA   // MCU I2C Data Pin
#define PINCC26XX_MUX_MCU_I2C_MSSCL  IOC_PORT_MCU_I2C_MSSCL   // MCU I2C Clock Pin
#define PINCC26XX_MUX_MCU_UART0_RX   IOC_PORT_MCU_UART0_RX    // MCU UART0 Receive Pin
#define PINCC26XX_MUX_MCU_UART0_TX   IOC_PORT_MCU_UART0_TX    // MCU UART0 Transmit Pin
#define PINCC26XX_MUX_MCU_UART0_CTS  IOC_PORT_MCU_UART0_CTS   // MCU UART0 Clear To Send Pin
#define PINCC26XX_MUX_MCU_UART0_RTS  IOC_PORT_MCU_UART0_RTS   // MCU UART0 Request To Send Pin
#define PINCC26XX_MUX_MCU_UART1_RX   IOC_PORT_MCU_UART1_RX    // MCU UART1 Receive Pin
#define PINCC26XX_MUX_MCU_UART1_TX   IOC_PORT_MCU_UART1_TX    // MCU UART1 Transmit Pin
#define PINCC26XX_MUX_MCU_UART1_CTS  IOC_PORT_MCU_UART1_CTS   // MCU UART1 Clear To Send  Pin
#define PINCC26XX_MUX_MCU_UART1_RTS  IOC_PORT_MCU_UART1_RTS   // MCU UART1 Request To Send  Pin
#define PINCC26XX_MUX_MCU_TIMER0     IOC_PORT_MCU_TIMER0      // MCU GPT Pin 0
#define PINCC26XX_MUX_MCU_TIMER1     IOC_PORT_MCU_TIMER1      // MCU GPT Pin 1
#define PINCC26XX_MUX_MCU_TIMER2     IOC_PORT_MCU_TIMER2      // MCU GPT Pin 2
#define PINCC26XX_MUX_MCU_TIMER3     IOC_PORT_MCU_TIMER3      // MCU GPT Pin 3
#define PINCC26XX_MUX_MCU_TIMER4     IOC_PORT_MCU_TIMER4      // MCU GPT Pin 4
#define PINCC26XX_MUX_MCU_TIMER5     IOC_PORT_MCU_TIMER5      // MCU GPT Pin 5
#define PINCC26XX_MUX_MCU_TIMER6     IOC_PORT_MCU_TIMER6      // MCU GPT Pin 6
#define PINCC26XX_MUX_MCU_TIMER7     IOC_PORT_MCU_TIMER7      // MCU GPT Pin 7
#define PINCC26XX_MUX_RESERVED0      IOC_PORT_RESERVED0       // Reserved0
#define PINCC26XX_MUX_RESERVED1      IOC_PORT_RESERVED1       // Reserved1
#define PINCC26XX_MUX_MCU_SSI1_RX    IOC_PORT_MCU_SSI1_RX     // MCU SSI1 Receive Pin
#define PINCC26XX_MUX_MCU_SSI1_TX    IOC_PORT_MCU_SSI1_TX     // MCU SSI1 Transmit Pin
#define PINCC26XX_MUX_MCU_SSI1_FSS   IOC_PORT_MCU_SSI1_FSS    // MCU SSI1 FSS Pin
#define PINCC26XX_MUX_MCU_SSI1_CLK   IOC_PORT_MCU_SSI1_CLK    // MCU SSI1 Clock Pin
#define PINCC26XX_MUX_MCU_I2S_AD0    IOC_PORT_MCU_I2S_AD0     // MCU I2S Data Pin 0
#define PINCC26XX_MUX_MCU_I2S_AD1    IOC_PORT_MCU_I2S_AD1     // MCU I2S Data Pin 1
#define PINCC26XX_MUX_MCU_I2S_WCLK   IOC_PORT_MCU_I2S_WCLK    // MCU I2S Frame/Word Clock
#define PINCC26XX_MUX_MCU_I2S_BCLK   IOC_PORT_MCU_I2S_BCLK    // MCU I2S Bit Clock
#define PINCC26XX_MUX_MCU_I2S_MCLK   IOC_PORT_MCU_I2S_MCLK    // MCU I2S Master clock 2
#define PINCC26XX_MUX_MCU_IOC_OBS0   IOC_PORT_MCU_IOC_OBS0    // MCU Port 0 for observation
#define PINCC26XX_MUX_MCU_IOC_OBS1   IOC_PORT_MCU_IOC_OBS1    // MCU Port 1 for observation
#define PINCC26XX_MUX_MCU_IOC_OBS2   IOC_PORT_MCU_IOC_OBS2    // MCU Port 2 for observation
#define PINCC26XX_MUX_MCU_IOC_OBS3   IOC_PORT_MCU_IOC_OBS3    // MCU Port 3 for observation
#define PINCC26XX_MUX_RFC_TRC        IOC_PORT_RFC_TRC         // RF Core Tracer
#define PINCC26XX_MUX_RFC_GPO0       IOC_PORT_RFC_GPO0        // RC Core Data Out Pin 0
#define PINCC26XX_MUX_RFC_GPO1       IOC_PORT_RFC_GPO1        // RC Core Data Out Pin 1
#define PINCC26XX_MUX_RFC_GPO2       IOC_PORT_RFC_GPO2        // RC Core Data Out Pin 2
#define PINCC26XX_MUX_RFC_GPO3       IOC_PORT_RFC_GPO3        // RC Core Data Out Pin 3
#define PINCC26XX_MUX_RFC_GPI0       IOC_PORT_RFC_GPI0        // RC Core Data In Pin 0
#define PINCC26XX_MUX_RFC_GPI1       IOC_PORT_RFC_GPI1        // RC Core Data In Pin 1
#define PINCC26XX_MUX_RFC_SMI_DL_OUT IOC_PORT_RFC_SMI_DL_OUT  // RF Core SMI Data Link Out
#define PINCC26XX_MUX_RFC_SMI_DL_IN  IOC_PORT_RFC_SMI_DL_IN   // RF Core SMI Data Link in
#define PINCC26XX_MUX_RFC_SMI_CL_OUT IOC_PORT_RFC_SMI_CL_OUT  // RF Core SMI Command Link Out
#define PINCC26XX_MUX_RFC_SMI_CL_IN  IOC_PORT_RFC_SMI_CL_IN   // RF Core SMI Command Link In
/** \} (PINCC26XX_MUX_VALS)
 */


#ifdef __cplusplus
}
#endif
#endif /* ti_drivers_PINCC26XX__include */
