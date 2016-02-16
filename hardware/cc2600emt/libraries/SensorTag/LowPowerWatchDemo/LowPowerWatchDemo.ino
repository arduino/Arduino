// Include application, user and local libraries
#include "Wire.h"
#include "SPI.h"
#include "OneMsTaskTimer.h"
#include "LCD_SharpBoosterPack_SPI.h"
#include "Adafruit_TMP007.h"
#include <ti/sysbios/knl/Clock.h>

#include <ti/sysbios/hal/Seconds.h>
#include <time.h>

/* TMP007 driver */
Adafruit_TMP007 tmp007;

/* LCD driver */
LCD_SharpBoosterPack_SPI myScreen(7, 20, 10, false);

int32_t secondsOffset = 0;

Semaphore_Handle mySem;

void myClkFunc(UArg arg)
{
    Semaphore_post(mySem);
}

void button1Interrupt()
{
    Semaphore_post(mySem);
}

void button2Interrupt()
{
    Semaphore_post(mySem);
}

void lcdSetup() {
    Semaphore_Params mySemParams;
    Clock_Params myClkParams;

    /* Use pull up on button inputs to save power */  
    pinMode(PUSH1, INPUT_PULLUP);
    pinMode(PUSH2, INPUT_PULLUP);

    /* Both buttons post the semaphore */
    attachInterrupt(PUSH1, button1Interrupt, FALLING);
    attachInterrupt(PUSH2, button2Interrupt, FALLING);

    /* set LCD's EXTMODE low (sadly this is the UART Rx pin too) */
    digitalWrite(12, 0);

    /* turn off MPU power */
    digitalWrite(22, 0);

    /* put flash into power down mode */
    SPI.begin();
    SPI.transfer((uint8_t)32, 0xb9);
    SPI.end();

    /* power down the tmp007 */
    Wire.begin();
    tmp007.begin(TMP007_CFG_1SAMPLE);
    tmp007.write16(TMP007_CONFIG, TMP007_CFG_ALERTEN | TMP007_CFG_TRANSC | TMP007_CFG_1SAMPLE);
    Wire.end();
  
    Semaphore_Params_init(&mySemParams);

    mySem = Semaphore_create(0, &mySemParams, NULL);
  
    Clock_Params_init(&myClkParams);

    myClkParams.period = 100000; /* one second */
    myClkParams.startFlag = true;

    /* comment out for steady state power testing */
    Clock_create(myClkFunc, 0, &myClkParams, NULL); 
  
    myScreen.begin(); /* also calls SPI.begin() */

    myScreen.setFont(1);
    myScreen.text(10, 10, "Hello!");
    myScreen.flush(); 

    SPI.end(); /* to save power */

    /* Say Hello for 1 second */
    delay(1000);

    SPI.begin();
    myScreen.clear();
    SPI.end(); /* to save Power */
}

void printTime()
{
    String buf;
    uint32_t curSeconds;
    int days, hours, minutes, seconds;

    SPI.begin();

    myScreen.clearBuffer();

    myScreen.text(5, 10, "Energia");

    curSeconds = Seconds_get();
    seconds = (int) curSeconds % 60;
    minutes = (int) ((curSeconds / 60) % 60);
    hours   = (int) ((curSeconds / (60*60)) % 24);
    days    = (int) (curSeconds / (60*60*24));

    if (hours < 10) {
        buf += "0";
    }
    buf += hours;
    buf += ":";
    if (minutes < 10) {
        buf += "0";
    }
    buf += minutes;
    buf += ":";
    if (seconds < 10) {
        buf += "0";
    }
    buf += seconds;
    myScreen.text(1, 50, buf);
    myScreen.text(25, 70, "Time");
    buf = "";
    if (days < 100) buf += "0";
    if (days < 10) buf += "0";
    buf += days;
    buf += ":";
    myScreen.text(1, 30, buf);
    myScreen.flush();

    SPI.end(); /* to save Power */
}

void lcdLoop() {

    Semaphore_pend(mySem, BIOS_WAIT_FOREVER);

    /* Advance quickly */
    while(digitalRead(PUSH2) == 0) {
        secondsOffset += 100;
        Seconds_set(secondsOffset);
        printTime();
    }

    /* reverse more slowly */
    while(digitalRead(PUSH1) == 0) {
        secondsOffset -= 10;
        Seconds_set(secondsOffset);
        printTime();
    }

    printTime();
}
