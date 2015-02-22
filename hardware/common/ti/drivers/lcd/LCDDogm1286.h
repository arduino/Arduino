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
 *  @file       LCDDogm1286.h
 *
 *  @brief      LCD driver implementation for a DOGM128W-6 LCD display.
 *
 * # Driver include #
 *  The LCD header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/lcd/LCDDogm1286.h>
 *  @endcode
 *
 * # Overview #
 *  This LCD driver implementation is designed to operate on a DOGM128W-6 LCD display.
 *  This display is the one used on the SmartRF06 EB (Evaluation Board). The LCD display
 *  can be written to by first writing the data to display to an internal buffer, and then
 *  sending the buffer content to the LCD display. The LCD driver will make use of the
 *  SPI driver for updating the display. The driver contains different functions for
 *  both modifying the internal buffer and for updating the display with the buffer content.
 *
 *  The DOGM128W-6 LCD display contains 128 pixel columns and 64 pixel rows.
 *  The (x,y) coordinate system is as described below:
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
 *  This LCD driver uses a 5x7 font, thus each character takes up 5 pixels width
 *  and 7 pixels height. Each line of text will take up one page of the display.
 *  The difference between the defined variables ::LCD_CHAR_WIDTH
 *  and ::LCD_FONT_WIDTH equals the character spacing on the LCD display.
 *
 *
 * # General Behavior #
 * Before using LCD:
 *   - In order to use the DOGM128W-6 LCD display on the SmartRF06 EB,
 *     the application needs to first drive the Board_3V3_EN pin high to enable the 3.3V
 *     domain on the board.
 *   - The LCD display is configured by calling ::LCD_open(). This function will in turn
 *     open the SPI driver and allocate the 2 additional control signals (through the PIN driver)
 *      required to operate the LCD.
 *
 * In total the following pins are required to operate the LCD on the SmartRF06EB:
 *  \verbatim
 *  Board_SPI0_MOSI     (Serial peripheral interface, Master-Out-Slave-In, controlled by LCD driver)
 *  Board_SPI0_MISO     (Serial peripheral interface, Master-In-Slave-Out, controlled by LCD driver)
 *  Board_SPI0_CLK      (Serial peripheral interface, Clock, controlled by LCD driver)
 *  Board_LCD_CSN       (Serial peripheral interface, Chip select, controlled by LCD driver)
 *  Board_LCD_RST       (LCD reset signal, active low, controlled by LCD driver)
 *  Board_LCD_MODE      (LCD mode signal, controlled by LCD driver)
 *  Board_3V3_EN        (Enable the 3.3V domain. NOTE: Must be set by application, NOT controlled by LCD driver)
 *  \endverbatim
 *
 * The following SPI parameters will be fixed by the LCD driver:
 *   - transferMode    = ::SPI_MODE_BLOCKING
 *   - transferTimeout = BIOS_WAIT_FOREVER
 *   - mode            = ::SPI_MASTER
 *   - dataSize        = 8
 *
 * The APIs in this driver serve as an interface to a typical TI-RTOS
 * application. The specific peripheral implementations are responsible to
 * create all the SYS/BIOS specific primitives to allow for thread-safe
 * operation.
 *
 * After LCD operation has ended:
 * - Release system dependencies for LCD by calling ::LCD_close().
 *
 * # Error handling #
 * Please refer to the SPI driver documentation for information about error handling
 * during a SPI transaction.
 *
 * If an error occurs when modifying the internal buffers, the functions are return
 * without completing the buffer modification.
 *
 * # Power Management #
 * The TI-RTOS power management framework will try to put the device into the most
 * power efficient mode whenever possible. Please see the technical reference
 * manual for further details on each power mode.
 *
 * The LCD driver makes use of the SPICC26XXDMA driver, which is setting a power constraint during
 * transfers to keep the device out of standby. I.e. device will enter idle mode when no tasks
 * are active. When the transfer has finished, the power constraint is released.
 *
 * # LCD Details #
 * ## Allocating space to internal buffers ##
 *  The LCD driver joined (at link time) to an array of ::LCD_Buffer structures
 *  named *lcdBuffers*.
 *  *lcdBuffers* is implemented in the application with each entry being an
 *  instance of a ::LCD_Buffer. The number of buffers availible must be
 *  passed as an argument to ::LCD_open(). Each entry in *lcdBuffers* contains a:
 *  - (Char *)            which points to a buffer with data to be printed on the LCD
 *  - (unsigned int)      which is the size of the buffer
 *  - (Semaphore_Struct)  which is a semaphore to be associated with the buffer.
 *  The Semaphores will be constructed by the LCD driver when it is being opened,
 *  and is being used to block task execution while the associated buffer is in use.
 *
 * ## Modifying internal buffers and updating LCD display ##
 *  Before the LCD screen can be filled, the data to display must be written to the
 *  internal buffers. All functions called LCD_bufferxxxx are only modifying the
 *  internal buffers. To send the buffer content to the LCD display, one must use the
 *  functions ::LCD_update() or ::LCD_updatePart().
 *  The only exception from this is the function ::LCD_writeLine(), which both modifies a
 *  buffer and send the content to the LCD display.
 *
 * # Supported Functions #
 *  | API function                   | Description                                              |
 *  |------------------------------- |----------------------------------------------------------|
 *  | LCD_open()                     | Initialize LCD display and configure SPI driver          |
 *  | LCD_close()                    | Disable LCD operation                                    |
 *  | LCD_writeLine()                | Write a string and a number to a page on the LCD display |
 *  | LCD_update()                   | Write the content of a LCD buffer to the display         |
 *  | LCD_updatePart()               | Write part of a LCD buffer to the display                |
 *  | LCD_bufferClear()              | Empty an entire LCD buffer                               |
 *  | LCD_bufferClearPage()          | Empty an entire page in a LCD buffer                     |
 *  | LCD_bufferClearPart()          | Empty part of a LCD buffer                               |
 *  | LCD_bufferInvert()             | Invert the pixels of a part of a LCD buffer              |
 *  | LCD_bufferInvertPage()         | Invert the pixels of a page in a LCD buffer              |
 *  | LCD_bufferPrintString()        | Write a string to a LCD buffer                           |
 *  | LCD_bufferPrintStringAligned() | Write an aligned string to a LCD buffer                  |
 *  | LCD_bufferPrintInt()           | Write an integer to a LCD buffer                         |
 *  | LCD_bufferPrintIntAligned()    | Write an aligned integer to a LCD buffer                 |
 *  | LCD_bufferPrintFloat()         | Write a floating point number to a LCD buffer            |
 *  | LCD_bufferPrintFloatAligned()  | Write an aligned floating point number to a LCD buffer   |
 *  | LCD_bufferSetLine()            | Draw a line to a LCD buffer                              |
 *  | LCD_bufferClearLine()          | Clear a line from a LCD buffer                           |
 *  | LCD_bufferSetHLine()           | Draw a horizontal line to a LCD buffer                   |
 *  | LCD_bufferClearHLine()         | Clear a horizontal line from a LCD buffer                |
 *  | LCD_bufferSetVLine()           | Draw a vertical line to a LCD buffer                     |
 *  | LCD_bufferClearVLine()         | Clear a vertical line from a LCD buffer                  |
 *  | LCD_bufferHArrow()             | Draw a horizontal arrow to a LCD buffer                  |
 *  | LCD_bufferVArrow()             | Draw a vertical arrow to a LCD buffer                    |
 *  | LCD_bufferSetPx()              | Set a pixel in a LCD buffer                              |
 *  | LCD_bufferClearPx()            | Clear a pixel in a LCD buffer                            |
 *  | LCD_bufferCopy()               | Copy content of one LCD buffer into another              |
 *  | LCD_setContrast()              | Set the contrast of the LCD display                      |
 *
 * ## Use Cases \anchor USE_CASES_LCD ##
 *  The most basic use cases discribed are described below. A complete LCD example
 *  can also be found in the TI-RTOS simplelink distribution.
 *
 * ### Configuring the LCD display ###
 *
 *  @code
 *  LCD_Handle lcdHandle;
 *  LCD_Params lcdParams;
 *  PIN_State  pinState;
 *  PIN_Handle hPins;
 *
 *  // This application supports two LCD buffers
 *  Char lcdBuffer0[LCD_BYTES] = {0};
 *  Char lcdBuffer1[LCD_BYTES] = {0};
 *
 *  // Populate LCD_Buffer structure with buffer pointers and buffer sizes.
 *  // The Semaphore structure will be constructed when opening the LCD.
 *  LCD_Buffer lcdBuffers[] = {
 *      {lcdBuffer0, LCD_BYTES, NULL},
 *      {lcdBuffer1, LCD_BYTES, NULL},
 *  };
 *
 *  // Application pin table.
 *  // Drive Board_3V3_EN high to enble 3.3V domain on SRF06EB
 *  PIN_Config pinList[] = {
 *       Board_3V3_EN     | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH  | PIN_PUSHPULL,
 *       PIN_TERMINATE
 *  };
 *
 *  // Open PIN driver
 *  hPins = PIN_open(&pinState, pinList);
 *
 *  // Initialize LCD parameters
 *  LCD_Params_init(&lcdParams);
 *
 *  // Optionally override default bit rate
 *  lcdParams.spiBitRate = someNewSpiBitRate;
 *
 *  // Open LCD driver, using 2 buffers
 *  lcdHandle = LCD_open(&lcdBuffers[0], 2, &lcdParams);
 *
 *  // Make sure it was successful
 *  if (!lcdHandle)
 *  {
 *      System_abort("Error initializing LCD\n");
 *  }
 *
 *
 *  @endcode
 *
 * ### Writing to the internal buffer ###
 *
 *  @code
 *  // Clear and write to buffer 0
 *  LCD_bufferClear(lcdHandle, 0);
 *  LCD_bufferPrintString(lcdHandle, 0, "Writing to Buffer 0", 24, LCD_PAGE0);
 *  LCD_bufferSetHLine(lcdHandle, 0, LCD_X_FIRST, LCD_X_LAST, 20);
 *  @endcode
 *
 * ### Updating LCD display with buffer content ###
 *
 *  @code
 *  // Update display with content of buffer 0
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
 *  ============================================================================
 */

#ifndef ti_drivers_lcd_LCDDogm1286__include
#define ti_drivers_lcd_LCDDogm1286__include

#ifdef __cplusplus
extern "C" {
#endif

#include <xdc/std.h>
#include <ti/drivers/SPI.h>

#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>

/*! \internal Number of pixels in LCD display */
#define LCD_PIXELS          8192
/*! Number of bytes needed in LCD buffer */
#define LCD_BYTES           1024
/*! Number of pixel columns */
#define LCD_COLS            128
/*! First pixel on LCD x-axis */
#define LCD_X_MIN           0
/*! Last pixel on LCD x-axis */
#define LCD_X_MAX           (LCD_COLS-1)
/*! Number of pixel rows */
#define LCD_ROWS            64
/*! First pixel on LCD y-axis */
#define LCD_Y_MIN           0
/*! Last pixel on LCD y-axis */
#define LCD_Y_MAX           (LCD_ROWS-1)
/*! \internal Number of pages */
#define LCD_PAGES           8
/*! Number of pixel rows per LCD page */
#define LCD_PAGE_ROWS       8
/*! Space used for each character */
#define LCD_CHAR_WIDTH      6
/*! Actual font character width */
#define LCD_FONT_WIDTH      5


/*!
*  @brief      A handle that is returned from a LCD_open() call.
*/
typedef struct LCD_Config   *LCD_Handle;

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
 *  It is used for y argument in LCD_bufferxxx functions
 *
 */
typedef enum LCD_Y_Limit
{
    LCD_Y_FIRST = 0,
    LCD_Y_LAST = (LCD_ROWS-1)
} LCD_Y_Limit;

/*!
 *  @brief
 *  LCD Parameters are used to with the LCD_open() call. Default values for
 *  these parameters are set using LCD_Params_init().
 *
 *  @sa     SPI_Params_init
 */
typedef struct LCD_Params
{
     unsigned int       lcdWriteTimeout;    /*!< Timeout for write semaphore */

     /* SPI parameters */
     unsigned int       spiBitRate;         /*!< SPI bit rate in Hz */
     SPI_FrameFormat    spiFrameFormat;     /*!< SPI frame format */
} LCD_Params;

/*!
 *  @brief Format of LCD commands used by the LCD controller.
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
 *  @brief  LCD_Buffer used to store data to be printed on the LCD display.
 *
 *  A sample structure is shown below:
 *  @code
 *  LCD_Buffer lcdBuffers[] = {
 *      {lcdBuffer0, LCD_BYTES, NULL},
 *      {lcdBuffer1, LCD_BYTES, NULL},
 *  };
 *  @endcode
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
    LCD_Buffer           *lcdBuffers;       /* Pointer to the array
                                               with lcd buffers */
    uint8_t              nBuffers;          /* number of buffers availible */
} LCD_Object;

/*!
 *  @brief      LCD Hardware attributes
 *
 *  A sample structure is shown below:
 *  @code
 *  const LCD_HWAttrs lcdHWAttrs = {
 *      .LCD_initCmd = &LCD_initCmd,
 *      .lcdResetPin = Board_LCD_RST,
 *      .lcdModePin = Board_LCD_MODE,
 *      .lcdCsnPin = Board_LCD_CSN,
 *      .spiIndex = Board_SPI0
 *  };
 *  @endcode
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
 *  @brief
 *  The LCD_Config structure contains a set of pointers used to characterize
 *  the LCD driver implementation.
 */
typedef struct LCD_Config
{
  /*! Pointer to a driver specific data object */
  LCD_Object            *object;
  /*! Pointer to a driver specific hardware attributes structure */
  LCD_HWAttrs   const   *hwAttrs;
} LCD_Config;

/*! \internal
 *
 *  @brief   LCD initialization command sequence used to initialize
 *           The LCD display. The format of the command in defined in
 *           the LCD_Command structure
 *
 *  @sa      LCD_Command
 */
static const LCD_Command LCD_initCmd =
{
    0x40, /*Display start line 0                    */
    0xA1, /*ADC reverse, 6 oclock viewing direction */
    0xC0, /*Normal COM0...COM63                     */
    0xA6, /*Display normal, not mirrored            */
    0xA2, /*Set Bias 1/9 (Duty 1/65)                */
    0x2F, /*Booster, Regulator and Follower On      */
    0xF8, /*Set internal Booster to 4x              */
    0x00, /*                                        */
    0x27, /*Contrast set                            */
    0x81, /*                                        */
    0x16, /* <- use value from LCD-MODULE .doc guide*/
          /*    for better contrast (not 0x10)      */
    0xAC, /*No indicator                            */
    0x00, /*                                        */
    0xAF, /*Display on                              */
    0xB0, /*Set Page 0                              */
    0x10, /*High-Nibble of column address           */
    0x00  /*Low-Nibble of column address            */
};

/*!
 *  @brief  Function to close the LCD instance specified by the
 *          LCD handle.
 *
 *  @pre    LCD_open() has to be called first. Function assumes that the handle is not NULL.
 *          Calling context: Task.
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
 *          this function can be called. This function must be called before any
 *          other LCD driver APIs.
 *          Calling context: Hwi, Swi, Task, Main.
 */
extern void LCD_init(void);

/*!
 *  @brief   Function to set up the DOGM128W-6 LCD display
 *
 *  @pre     LCD controller has been initialized using LCD_init().
 *           Calling context: Task.
 *
 *  @param   buffers     Pointer to a buffer block.
 *
 *  @param   nBuffers    Number of buffers in the buffer block.
 *
 *  @param   params      Pointer to a parameter block, if NULL it will use
 *                       default values
 *
 *  @return  A pointer to a LCD_Handle on success or a NULL it was already
 *           opened
 *
 *  @sa      LCD_close()
 *  @sa      LCD_init()
 */
extern LCD_Handle LCD_open(LCD_Buffer *buffers, uint8_t nBuffers, LCD_Params *params);

/*!
 *  @brief  Function to initialize the LCD_Params struct to its defaults
 *
 *  Defaults values are:
 *  @code
 *  lcdWriteTimeout = BIOS_WAIT_FOREVER;
 *  spiBitRate      = 1000000;
 *  spiFrameFormat  = SPI_POL0_PHA0;
 *  @endcode
 *
 *  @pre    Calling context: Task.
 *
 *  @param  params  Parameter structure to initialize
 */
extern void LCD_Params_init(LCD_Params *params);

/*!
 *  @brief  Function that writes a string and value to a
 *          buffer and sends it to the LCD display. The written page is being
 *          cleared before it is written to.
 *
 *          LCD_write will block task execution until all
 *          the data in buffer has been written to the LCD.
 *
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
 *
 *  @param  handle      A LCD_Handle
 *
 *  @param  bufIndex    The buffer to use, specified by its index in the LCD_Buffer structure.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @return   None
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
 *
 *  @param  handle     A LCD_Handle
 *
 *  @param  bufIndex   The buffer to use, specified by its index in the LCD_Buffer structure.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @return  None
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffer is not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle and buffers are not NULL.
 *          Calling context: Task.
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
 *  @pre    Function assumes that the handle is not NULL.
 *          Calling context: Task.
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
