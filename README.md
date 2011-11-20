XmegaDuino
===========

Port of the Arduino IDE, core, libraries and bootloader to support the Atmel XMEGA family of chips.

Currently supported boards:

* AVR xplain board
* Akafuino X board
* Sparkfun xmega100 breakout board

The following boards should work with a little tweaking:

* Magnetovore
* Megavore
* Boston Android

This project has replaced the xmegaduino project on Google Code (http://code.google.com/p/xmegaduino/)
and has been active since September 2011. It supersedes the earlier xplainduino.

Installation
============

Download from [here](https://github.com/akafugu/Xmegaduino/downloads).

* Windows
* OS X
* Linux

Requirements
============

* AVR xplain board

The LUFA project provides a replacement USB firmware that can act as a PDI programmer.
You can also use a PDI programmer such as the AVR Dragon.

* Sparkfun xmega100

Requires a PDI programmer, such as the AVR Dragon in order to upload sketches and burn bootloaders.

* Akafuino X

Comes with a bootloader pre-installed and can be used directly from the Xmegaduino IDE.

Status
======

The Xmegaduino project is beta quality, and not all the features of the Arduino IDE are supported yet.

Working features:

* digitalRead and digitalWrite
* millis and delay
* micros and delayMicroseconds
* Serial on USB (USARTC0), Serial1 on pins D2/D3 (USARTD0) and Serial2 on D6/D7 (USARTD1).
* analogRead
* analogWrite
* attachInterrupt, detachInterrupt, interrupts, noInterrupts
* Upload using bootloader over usb port, D2/3, or D6/7.
* Burn bootloader from arduino IDE
* DAC (using xmDAC library)
* Wire
* shiftOut, pulseIn (not tested)

Todo:

* analogReference
* tone
* Spi library
* Ethernet library
* Servo library
* Stepper library

