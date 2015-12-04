This folder contains revision 002 of the firmware for the ATmega16u2 or 8u2
USB-Serial interface chip used on various Arduino/Genuino development boards and
the Arduino USB to Serial adapters. The main improvement over version 001 is that
it fixes a bug that caused data corruption at 250000 baud.

If you simply want to upgrade the firmware on an existing board, download the
appropriate .hex file for your device and follow these instructions to install it:
https://www.arduino.cc/en/Hacking/DFUProgramming8U2

To re-compile the firmware, you will need avr-gcc in your path, and LUFA version
151115 from here:
http://www.fourwalledcubicle.com/LUFA.php
(Newer versions may work but haven't been tested.)
Unpack LUFA and place this folder inside the LUFA Projects folder.
Edit the makefile and uncomment the ARDUINO_MODEL_PID line that matches your device.
Run make. It should compile the firmware and generate Arduino-usbserial.hex
