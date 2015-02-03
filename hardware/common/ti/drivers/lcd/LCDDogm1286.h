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
 *  @file       LCDDogm1286.h
 *
 *  @brief      LCD driver implementation for a DOGM128W-6 LCD display.
 *
 *  The LCD header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/lcd/LCDDogm1286.h>
 *  @endcode
 *
 *  This LCD driver implementation is designed to operate on a DOGM128W-6 LCD display.
 *  The (x,y) coordinate system used in this device driver is as described below:
 *  \verbatim
 *
 *       X ----->
 *   Y   +---------------------------------------------+
 *   |   |(0,0)              PAGE 0             (127,0)|
 *   |   |                   PAGE 1                    |
 *   v   |                   PAGE 2                    |
 *       |                   PAGE 3                    |
 *       |                   PAGE 4                    |
 *       |                   PAGE 5                    |
 *       |                   PAGE 6                    |
 *       |(0,63)             PAGE 7            (127,63)|
 *       +---------------------------------------------+
 *  \endverbatim
 *
 *  # Operation #
 *  The LCD driver simplifies writing to a DOGM128W-6 LCD display on the board.
 *  Note: In order to use this LCD on the SmartRF06 EB (evaluation board), the
 *  application needs to first drive the Board_3V3_EN pin high to enable the 3.3V
 *  domain on the board.
 *  The application should then open the LCD by calling LCD_open() and passing
 *  in a LCD parameters data structure.
 *  is passed as an argument, so the application can use the same handle for SPI
 *  operations that is not LCD-related. The following SPI parameters will be fixed
 *  by the LCD driver:
 *  params.mode           = SPI_MASTER;
 *  params.dataSize       = 8;
 *
 *  The LCD driver will in turn open the SPI driver and allocate the 2 additional
 *  control signals (through the PIN driver) required to operate the LCD.
 *  The Board_3V3_EN signal must be enabled and controlled by the application.
 *  In total the following pins are required to operate the LCD on the SmartRF06EB:
 *  \verbatim
 *
 *  Board_SPI0_MOSI     (Serial peripheral interface, Master-Out-Slave-In, controlled by LCD driver)
 *  Board_SPI0_MISO     (Serial peripheral interface, Master-In-Slave-Out, controlled by LCD driver)
 *  Board_SPI0_CLK      (Serial peripheral interface, Clock, controlled by LCD driver)
 *  Board_LCD_CSN       (Serial peripheral interface, Chip select, controlled by LCD driver)
 *  Board_LCD_RST       (LCD reset signal, active low, controlled by LCD driver)
 *  Board_LCD_MODE      (LCD mode signal, controlled by LCD driver)
 *  Board_3V3_EN        (Enable the 3.3V domain. NOTE: Must be set by application, NOT controlled by LCD driver)
 *  \endverbatim
 *
 *  The APIs in this driver serve as an interface to a typical TI-RTOS
 *  application. The specific peripheral implementations are responsible to
 *  create all the SYS/BIOS specific primitives to allow for thread-safe
 *  operation.
 *
 *  ## Allocating space to internal buffers #
 *
 *  The LCD driver joined (at link time) to a
 *  NULL-terminated array of LCD_Buffer structures named *lcdBuffers*.
 *  *lcdBuffers* is implemented in the application with each entry being an
 *  instance of a LCD_Buffer. Each entry in *lcdBuffers* contains a:
 *  - (Char *)            to a buffer with data to be printed on the LCD
 *  - (unsigned int)              which is the size of the buffer
 *  - (Semaphore_Struct)  which is a semaphore to be associated with the buffer.
 *  The Semaphores will be constructed by the LCD driver when it is being opened,
 *  and is being used to block task execution while the associated buffer is in use.
 *
 *  @code
 *  Char lcdBuffer0[LCD_BYTES] = {0};
 *  Char lcdBuffer1[LCD_BYTES] = {0};
 *
 *  LCD_Buffer lcdBuffers[] = {
 *      {lcdBuffer0, LCD_BYTES, NULL},
 *      {lcdBuffer1, LCD_BYTES, NULL},
 *      {NULL, NULL, NULL},
 *  };
 *  @endcode
 *
 *  ## Opening the driver #
 *
 *  @code
 *  // Locals
 *  LCD_Handle      lcdHandle;
 *  LCD_Params      lcdParams;
 *  PIN_State       pinState;
 *
 *  // Drive Board_3V3_EN high to enble 3.3V domain on SRF06EB
 *  PIN_Config pinList[] = {
 *       PIN_GPIO_OUTPUT_EN | PIN_PUSHPULL | PIN_GPIO_HIGH | Board_3V3_EN,
 *       PIN_TERMINATE
 *  };
 *  hPin = PIN_open(&pinState, pinList);
 *
 *  // Initialize LCD parameters
 *  LCD_Params_init(&lcdParams);
 *  // Optionally override default bit rate
 *  lcdParams.spiBitRate = someNewSpiBitRate;
 *  // Open LCD driver (opens SPI driver and allocates the 2 additional
 *  // control signals required to operate LCD (Board_LCD_MODE and Board_LCD_RST)
 *  lcdHandle = LCD_open(&lcdParams);
 *  // Make sure it was successful
 *  if (!lcdHandle)
 *  {
 *      System_printf("LCD did not open");
 *  }
 *
 *  @endcode
 *
 *  ## Writing to the internal buffer #
 *
 *  @code
 *  LCD_bufferClear(lcdHandle, 0);
 *  LCD_bufferPrintString(lcdHandle, 0, "Writing to Buffer 0", 24, LCD_PAGE0);
 *  LCD_bufferSetHLine(lcdHandle, 0, LCD_X_FIRST, LCD_X_LAST, 20);
 *  @endcode
 *
 *  ## Updating LCD with buffer content #
 *
 *  @code
 *  LCD_update(lcdHandle, 0);
 *  @endcode
 *
 *  # Instrumentation #
 *  The LCD driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_lcd_LCDDogm1286__include
#define ti_drivers_lcd_LCDDogm1286__include

#ifdef __cplusplus
extern "C" {
#endif

#include <xdc/std.h>
#include <ti/drivers/SPI.h>

/*
 * The following allows this header file to be included in an application file
 * which also includes ti/sysbios/hal/Hwi.h.
 */
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>

/* LCD definitions */
#define LCD_PIXELS          8192
#define LCD_BYTES           1024
#define LCD_COLS            128
#define LCD_X_MIN           0
#define LCD_X_MAX           (LCD_COLS-1)
#define LCD_ROWS            64
#define LCD_Y_MIN           0
#define LCD_Y_MAX           (LCD_ROWS-1)
#define LCD_PAGES           8
#define LCD_PAGE_ROWS       8
/*  The difference between LCD_CHAR_WIDTH and LCD_FONT_WIDTH
    equals the character spacing on the LCD display. */
#define LCD_CHAR_WIDTH      6 /* Space used for each character */
#define LCD_FONT_WIDTH      5 /* The actual font character width */




/*!
*  @brief      A handle that is returned from a LCD_open() call.
*/
typedef struct LCD_Config      *LCD_Handle;

/*!
 *  @brief      LCD alignment enum
 *
 *  This enumeration defines the text alignment.
 *  It is used by LCD_bufferPrintxxxAligned functions.
 *
 */
typedef enum LCD_Align
{
    LCD_ALIGN_LEFT,     /*!< Text is aligned to the left */
    LCD_ALIGN_CENTER,   /*!< Text is aligned in the center */
    LCD_ALIGN_RIGHT     /*!< Text is aligned to the right */
} LCD_Align;

/*!
 *  @brief      LCD page enum
 *
 *  This enumeration defines the LCD pages.
 *  It is used by LCD_bufferxxx functions
 *
 */
typedef enum LCD_Page
{
    LCD_PAGE0 = 0,
    LCD_PAGE1,
    LCD_PAGE2,
    LCD_PAGE3,
    LCD_PAGE4,
    LCD_PAGE5,
    LCD_PAGE6,
    LCD_PAGE7,
    LCD_PAGE_COUNT
} LCD_Page;

/*!
 *  @brief      LCD x-axis enum
 *
 *  This enumeration defines x axis limit
 *  It is used for x argument in LCD_bufferxxx functions
 *
 */
typedef enum LCD_X_Limit
{
    LCD_X_FIRST = 0,
    LCD_X_LAST = (LCD_COLS-1)
} LCD_X_Limit;

/*!
 *  @brief      LCD y-axis enum
 *
 *  This enumeration defines y axis limit
 *  It is used for xy argument in LCD_bufferxxx functions
 *
 */
typedef enum LCD_Y_Limit
{
    LCD_Y_FIRST = 0,
    LCD_Y_LAST = (LCD_ROWS-1)
} LCD_Y_Limit;

/*!
 *  @brief    Basic LCD Parameters
 *
 */
typedef struct LCD_Params
{
     unsigned int       lcdWriteTimeout;    /*!< Timeout for write semaphore */

     /* SPI parameters */
     unsigned int       spiBitRate;         /*!< SPI bit rate in Hz */
     SPI_FrameFormat    spiFrameFormat;     /*!< SPI frame format */
} LCD_Params;

/*!
 *  @brief LCD Command structure
 *
 */
typedef struct LCD_Command
{
    char  displayStartLine;
    char  adcSet;
    char  outputMode;
    char  displayType;
    char  lcdBias;
    char  powerControl;
    char  boosterRadio0;
    char  boosterRadio1;
    char  contrastSet0;
    char  contrastSet1;
    char  contrastSet2;
    char  staticIndicator0;
    char  staticIndicator1;
    char  displayEn;
    char  setPage;
    char  columnHi;
    char  columnLo;
} LCD_Command;

/*!
 *  @brief  LCD_Buffer structure.
 *
 */
typedef struct LCD_Buffer
{
    char                *pcBuffer;  /*!< Ptr to a buffer with data to be transmitted */
    unsigned int        bufSize;    /*!< Size of the buffer */
    Semaphore_Struct    bufMutex;   /*!< Semaphore associated with the buffer */
} LCD_Buffer;

/*!
 *  @brief      LCD Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct LCD_Object
{
    /* LCD control variables */
    Bool                 isOpen;            /* Has the obj been opened? */
    SPI_Handle           spiHandle;         /* SPI handle used by the LCD */
    unsigned int         lcdWriteTimeout;   /* Timeout for write semaphore */
    Semaphore_Struct     lcdMutex;          /* Semaphore associated with the lcd */

    /* LCD pin mapping */
    unsigned int         lcdCsn;            /* Chip select for LCD  */
} LCD_Object;

/*!
 *  @brief      LCD Hardware attributes
 *
 */
typedef struct LCD_HWAttrs
{
    /*! LCD initialization command */
    LCD_Command const *LCD_initCmd;
    /* LCD mode pin */
    uint8_t           lcdModePin;
    /* LCD reset pin */
    uint8_t           lcdResetPin;
    /* LCD CSn pin */
    uint8_t           lcdCsnPin;
    /* Logical peripheral number indexed
       into the SPI_config table */
    uint8_t           spiIndex;

} LCD_HWAttrs;

/*!
 * @brief LCD Global configuration
 *
 */
typedef struct LCD_Config
{
  /*! Pointer to a driver specific data object */
  LCD_Object            *object;
  /*! Pointer to a driver specific hardware attributes structure */
  LCD_HWAttrs   const   *hwAttrs;
  /*! Pointer to the LCD buffers */
  LCD_Buffer            *buffers;
} LCD_Config;




/*!
 *  @brief  Function to close a given LCD peripheral specified by the
 *          LCD handle.
 *
 *  @pre    LCD_open() has to be called first.
 *
 *  @param  handle A LCD handle returned from LCD_open()
 *
 *  @sa     LCD_open()
 */
extern void LCD_close(LCD_Handle handle);

/*!
 *  @brief  This function initializes the LCD driver module.
 *
 *  @pre    The LCD_config structure must exist and be persistent before
 *          this function can be called.
 *          This function must also be called before any other LCD driver APIs.
 */
extern void LCD_init(void);

/*!
 *  @brief   This function opens a given LCD peripheral.
 *
 *  @pre     LCD controller has been initialized using LCD_init()
 *
 *  @param   params      Pointer to an parameter block, if NULL it will use
 *                       default values
 *
 *  @return  A pointer to a LCD_Handle on success or a NULL it was already
 *           opened
 *
 *  @sa      LCD_close()
 *  @sa      LCD_init()
 */
extern LCD_Handle LCD_open(LCD_Params *params);

/*!
 *  @brief  Function to initialize the LCD_Params structure to its defaults
 *
 *  @param  params  Parameter structure to initialize
 */
extern void LCD_Params_init(LCD_Params *params);

/*!
 *  @brief  Function that writes the specified string and value to a
 *          buffer and sends it to the LCD display. The written page is being
 *          cleared before it is written to.
 *
 *          LCD_write will block task execution until all
 *          the data in buffer has been written to the LCD.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  str        A pointer to the string to print.
 *
 *  @param  uiValue    Value to print
 *
 *  @param  ucFormat   Base of the value to print – 2,8,16 etc.
 *                     ucFormat must be between 2 and 36, where 10 means decimal base,
 *                     16 hexadecimal, 8 octal, and 2 binary.
 *                     If ucFormat is zero, only the string will get printed.
 *
 *  @param  ucLine     The page to write. Must be a value from 0-7.
 *
 */
extern void LCD_writeLine(LCD_Handle handle, unsigned int bufIndex, char *str, unsigned int uiValue, unsigned char ucFormat, unsigned char ucLine);

/*!
 *  @brief  Function that writes the specified buffer to the LCD display
 *
 *          LCD_update will block task execution until all
 *          the data in buffer has been written to the LCD.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *
 */
extern void LCD_update(LCD_Handle handle, unsigned int bufIndex);

/*!
 *  @brief  Function that sends the specified part of the given buffer
 *          to the corresponding part on the LCD.
 *          This function assumes \e ucXFrom <= \e ucXTo and \e iPageFrom <= \e iPageTo.
 *          The resolution is given in columns [0--127] and pages [0--7].
 *
 *          LCD_updatePart will block task execution until all
 *          the data has been written to the LCD.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom     The lowest x-position (column) to write [0--127].
 *
 *  @param  ucXTo       The highest x-position to write [ucXFrom--127].
 *
 *  @param  iPageFrom   The first page to write. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 *  @param  iPageTo     The last page to write [iPageFrom--LCD_PAGE7].
 *
 *  @return None
 *
 */
extern void LCD_updatePart(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucXTo,
                  LCD_Page iPageFrom, LCD_Page iPageTo);

/*!
 *  @brief  Function that empties the specified LCD buffer
 *
 *          LCD_bufferClear will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 */
extern void LCD_bufferClear(LCD_Handle handle, unsigned int bufIndex);

/*!
 *  @brief  This function clears the page specified by \e iPage in the given buffer
 *
 *          LCD_bufferClearPage will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  iPage       The page to clear. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 * @return   None
 *
 */
extern void LCD_bufferClearPage(LCD_Handle handle, unsigned int bufIndex, LCD_Page iPage);

/*!
 *  @brief  This function clears the pixels in a given piece of a page.
 *          Resolution is given in coulmns [0--127] and pages [0--7]. The
 *          function assumes \e ucXFrom <= \e ucXTo and
 *          \e iPageFrom <= \e iPageTo.
 *
 *          LCD_bufferClearPart will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom    The lowest x-position (column) to be cleared [0--127].
 *
 *  @param  ucXTo      The highest x-position to be cleared [ucXFrom--127].
 *
 *  @param  iPageFrom  The first page cleared. Must be one of the
 *                     following enumerated values:
 *                     \li \b LCD_PAGE0
 *                     \li \b LCD_PAGE1
 *                     \li \b LCD_PAGE2
 *                     \li \b LCD_PAGE3
 *                     \li \b LCD_PAGE4
 *                     \li \b LCD_PAGE5
 *                     \li \b LCD_PAGE6
 *                     \li \b LCD_PAGE7
 *
 * @param    iPageTo   The last page cleared [iPageFrom--LCD_PAGE7].
 *
 * @return   None
 *
 */
extern void LCD_bufferClearPart(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucXTo,
                   LCD_Page iPageFrom, LCD_Page iPageTo);

/*!
 *  @brief  This function inverts the pixels (bits) in a given region of the
 *          specified buffer.
 *
 *          LCD_bufferInvert will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom    The first x-position (column) to invert [0--127].
 *
 *  @param  ucYFrom    is the first y-position (row) to invert [0--63].
 *
 *  @param  ucXTo      The last x-position (column) to invert [0--127].
 *
 *  @param  ucYTo      The last y-position (row) to invert [0--63].
 *
 *  @return None
 *
 */
extern void LCD_bufferInvert(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucYFrom,
                    unsigned char ucXTo, unsigned char ucYTo);

/*!
 *  @brief  This function inverts a range of columns in the display buffer on a
 *          specified page (for example, \b LCD_PAGE0). This function assumes
 *          \e ucXFrom <= \e ucXTo.
 *
 *          LCD_bufferInvertPage will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom    The first x-position (column) to invert [0--127].
 *
 *  @param  ucXTo      The last x-position (column) to invert [ucXFrom--127].
 *
 *  @param  iPage      The page on which to invert. Must be one of the
 *                     following enumerated values:
 *                     \li \b LCD_PAGE0
 *                     \li \b LCD_PAGE1
 *                     \li \b LCD_PAGE2
 *                     \li \b LCD_PAGE3
 *                     \li \b LCD_PAGE4
 *                     \li \b LCD_PAGE5
 *                     \li \b LCD_PAGE6
 *                     \li \b LCD_PAGE7
 *
 *  @return   None
 */
extern void LCD_bufferInvertPage(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucXTo,
                    LCD_Page iPage);

/*!
 *  @brief  Function that writes a string to the specified buffer
 *
 *          LCD_bufferPrintString will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  pcStr       A pointer to the string to print.
 *
 *  @param  ucX         The x-position (column) to begin printing [0--127].
 *
 *  @param  iPage       The page on which to print. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 *
 */
extern void LCD_bufferPrintString(LCD_Handle handle, unsigned int bufIndex, const char *pcStr, unsigned char ucX,
                                  LCD_Page iPage);

/*!
 *  @brief  This function writes a string to the given buffer
 *          specified by the \e iAlignment argument.
 *
 *          LCD_bufferPrintStringAligned will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  pcStr       A pointer to the string to print.
 *
 *  @param  iAlignment  The text alignment. Must be one of the following
 *                      enumerated values:
 *                      \li \b LCD_ALIGN_LEFT
 *                      \li \b LCD_ALIGN_CENTER
 *                      \li \b LCD_ALIGN_RIGHT
 *
 *  @param  iPage       The page on which to print. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 *  @return   None
 *
 */
extern void LCD_bufferPrintStringAligned(LCD_Handle handle, unsigned int bufIndex, const char *pcStr,
                            LCD_Align iAlignment, LCD_Page iPage);

/*!
 *  @brief  Function that writes an integer to the specified buffer
 *
 *          LCD_bufferPrintInt will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  i32Number   The number to print.
 *
 *  @param  ucX         The x-position (column) to begin printing [0--127].
 *
 *  @param  iPage       The page on which to print. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 */
extern void LCD_bufferPrintInt(LCD_Handle handle, unsigned int bufIndex, int i32Number, unsigned char ucX,
                               LCD_Page iPage);

/*!
 *  @brief  This function writes an integer to the given buffer as
 *          specified by the \e iAlignment argument.
 *
 *          LCD_bufferPrintIntAligned will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  i32Number   The number to be printed.
 *
 *  @param  iAlignment  The text alignment. Must be one of the following
 *                      enumerated values:
 *                      \li \b LCD_ALIGN_LEFT
 *                      \li \b LCD_ALIGN_CENTER
 *                      \li \b LCD_ALIGN_RIGHT
 *
 *  @param  iPage       The page on which to print. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 *  @return   None
 */
extern void LCD_bufferPrintIntAligned(LCD_Handle handle, unsigned int bufIndex, int i32Number,
                         LCD_Align iAlignment, LCD_Page iPage);

/*!
 *  @brief  This function writes a number of data type float to the given buffer
 *          at a specified column and page. Use this function instead of
 *          performing a float to c-string conversion and then using
 *          LCD_bufferPrintString().
 *
 *          LCD_bufferPrintFloat will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  fNumber     The number to print.
 *
 *  @param  ucDecimals  The number of decimals to print, MAX = 10.
 *
 *  @param  ucX         The x-position (column) to begin printing [0--127].
 *
 *  @param  iPage       The page on which to print. Must be one of the
 *                      following enumerated values:
 *                      \li \b LCD_PAGE0
 *                      \li \b LCD_PAGE1
 *                      \li \b LCD_PAGE2
 *                      \li \b LCD_PAGE3
 *                      \li \b LCD_PAGE4
 *                      \li \b LCD_PAGE5
 *                      \li \b LCD_PAGE6
 *                      \li \b LCD_PAGE7
 *
 *  @return None
 *
 */
extern void LCD_bufferPrintFloat(LCD_Handle handle, unsigned int bufIndex, float fNumber, unsigned char ucDecimals,
                    unsigned char ucX, LCD_Page iPage);

/*!
 *  @brief  This function writes a float number to the given buffer as
 *          specified by the \e iAlignment argument.
 *
 *          LCD_bufferPrintFloatAligned will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  fNumber     The number to be printed.
 *
 *  @param  ucDecimals  The number of decimals to be printed, MAX = 10.
 *
 *  @param  iAlignment  The text alignment. Can be one of the following
 *                      enumerated values:
 *                      \li \b LCD_ALIGN_LEFT
 *                      \li \b LCD_ALIGN_CENTER
 *                      \li \b LCD_ALIGN_RIGHT
 *
 *  @param  iPage      The page on which to print. Must be one of the
 *                     following enumerated values:
 *                     \li \b LCD_PAGE0
 *                     \li \b LCD_PAGE1
 *                     \li \b LCD_PAGE2
 *                     \li \b LCD_PAGE3
 *                     \li \b LCD_PAGE4
 *                     \li \b LCD_PAGE5
 *                     \li \b LCD_PAGE6
 *                     \li \b LCD_PAGE7
 *
 *  @return None
 *
 */
extern void LCD_bufferPrintFloatAligned(LCD_Handle handle, unsigned int bufIndex, float fNumber, unsigned char ucDecimals,
                           LCD_Align iAlignment, LCD_Page iPage);

/*!
 *  @brief  This function draws a line in the specified buffer from
 *          (\e ucXFrom,\e ucYFrom) to (\e ucXTo,\e ucYTo). The function
 *          uses Bresenham's line algorithm.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom    The start column [0--127].
 *
 *  @param  ucXTo      The end column [0--127].
 *
 *  @param  ucYFrom    The start row [0--63].
 *
 *  @param  ucYTo      The end row [0--63].
 *
 *  @return None
 *
 */
extern void LCD_bufferSetLine(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucYFrom,
                 unsigned char ucXTo, unsigned char ucYTo);

/*!
 *  @brief  This function clears a line in the specified buffer from
 *          (\e ucXFrom,\e ucYFrom) to (\e ucXTo,\e ucYTo). The function
 *          uses Bresenham's line algorithm.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom    The start column [0--127].
 *
 *  @param  ucXTo      The end column [0--127].
 *
 *  @param  ucYFrom    The start row [0--63].
 *
 *  @param  ucYTo      The end row [0--63].
 *
 *  @return None
 *
 */
extern void LCD_bufferClearLine(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucYFrom,
                   unsigned char ucXTo, unsigned char ucYTo);

/*!
 *  @brief   This function draws a horizontal line from (\e ucXFrom,\e ucY) to
 *           (\e ucXTo,\e ucY) into the specified buffer.
 *
 *           This function will block task execution until all
 *           the buffer modification has finished.
 *
 *  @param   handle     A LCD_Handle
 *
 *  @param   bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param   ucXFrom    The start column [0--127].
 *
 *  @param   ucXTo      The end column [0--127].
 *
 *  @param   ucY        The row [0--63].
 *
 *  @return  None
 *
 */
extern void LCD_bufferSetHLine(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucXTo,
                  unsigned char ucY);

/*!
 *  @brief  This function clears a horizontal line from (\e ucXFrom,\e ucY) to
 *          (\e ucXTo,\e ucY) from the specified buffer.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom     The start column [0--127].
 *
 *  @param  ucXTo       The end column [0--127].
 *
 *  @param  ucY         The row [0--63].
 *
 *  @return None
 *
 */
extern void LCD_bufferClearHLine(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom,
                    unsigned char ucXTo, unsigned char ucY);

/*!
 *  @brief  This function draws a vertical line from (ucX,ucYFrom) to
 *          (ucX,ucYTo) into the specified buffer.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucX        The x-position (column) of the line [0--127].
 *
 *  @param  ucYFrom    The start row [0--63].
 *
 *  @param  ucYTo      The end row [0--63].
 *
 *  @return None
 *
 */
extern void LCD_bufferSetVLine(LCD_Handle handle, unsigned int bufIndex, unsigned char ucX, unsigned char ucYFrom,
                  unsigned char ucYTo);

/*!
 *  @brief  This function clears a vertical line from (\e ucX,\e ucYFrom) to
 *          (\e ucX,\e ucYTo) from the buffer specified.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucX        The x-position (column) of the line [0--127].
 *
 *  @param  ucYFrom    The start row [0--63].
 *
 *  @param  ucYTo      The end row [0--63].
 *
 *  @return   None
 *
 */
extern void LCD_bufferClearVLine(LCD_Handle handle, unsigned int bufIndex, unsigned char ucX, unsigned char ucYFrom,
                    unsigned char ucYTo);

/*!
 *  @brief  This function draws a horizontal arrow from (\e ucXFrom,\e ucY) to
 *          (\e ucXTo,\e ucY) to buffer specified. The function
 *          assumes \e ucY to be in the range [2--61] in order for arrowhead to
 *          fit on the LCD.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucXFrom    The start column [0--127].
 *
 *  @param  ucXTo      The end column [0--127].
 *
 *  @param  ucY        The the y-position (row) of the arrow [2--61].
 *
 *  @return None
 *
 */
extern void LCD_bufferHArrow(LCD_Handle handle, unsigned int bufIndex, unsigned char ucXFrom, unsigned char ucXTo, unsigned char ucY);

/*!
 *  @brief  This function draws a vertical arrow from (\e ucX,\e ucYFrom) to
 *          (\e ucX,\e ucYTo) to the buffer specified.
 *          The function assumes that \e ucX is in the range [2--125] for the
 *          arrowhead to fit on the LCD.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucX        The the x-position (column) of the arrow [2--125].
 *
 *  @param  ucYFrom    The start row [0--63].
 *
 *  @param  ucYTo      The end row [0--63].
 *
 *
 *  @return   None
 */
extern void LCD_bufferVArrow(LCD_Handle handle, unsigned int bufIndex, unsigned char ucX, unsigned char ucYFrom, unsigned char ucYTo);

/*!
 *  @brief  This function sets a pixel on (\e ucX,\e ucY).
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucX        The pixel x-position (column) [0--127].
 *
 *  @param  ucY        The pixel y-position (row) [0--63].
 *
 *  @return None
 *
 */
extern void LCD_bufferSetPx(LCD_Handle handle, unsigned int bufIndex, unsigned char ucX, unsigned char ucY);

/*!
 *  @brief  This function clears the pixel at (\e ucX,\e ucY).
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
 *
 *  @param  ucX         The pixel x-position (column) [0--127].
 *
 *  @param  ucY         The pixel y-position (row) [0--63].
 *
 *  @return None
 */
extern void LCD_bufferClearPx(LCD_Handle handle, unsigned int bufIndex, unsigned char ucX, unsigned char ucY);

/*!
 *  @brief  This function copies the content of \e fromBufIndex to
 *          \e toBufIndex.
 *
 *          This function will block task execution until all
 *          the buffer modification has finished.
 *
 *  @param  handle        A LCD_Handle
 *
 *  @param  fromBufIndex  A pointer to the destination buffer.
 *
 *  @param  toBufIndex    A pointer to the target buffer.
 *
 *  @return None
 *
 */
extern void LCD_bufferCopy(LCD_Handle handle, unsigned int fromBufIndex, unsigned int toBufIndex);

/*!
 *
 *  @brief   This Function sets the LCD contrast.
 *
 *  @param   handle      A LCD_Handle
 *
 *  @param   ucContrast  The contrast value [0--63].
 *
 *  @return  None
 *
 */
extern void LCD_setContrast(LCD_Handle handle, unsigned char ucContrast);

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_lcd_LCDDogm1286__include */
