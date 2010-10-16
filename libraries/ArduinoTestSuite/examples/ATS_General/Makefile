#BOARD			?=	mega1280stk500v2
BOARD			?=	mega2560stk500v2
#BOARD			?=	arduino_butterfly
#BOARD			?=	arduino_wiring1281
#BOARD			=	arduino_amber128
#BOARD			=	arduino_duino644
#BOARD			=	arduino_illuminato
#BOARD			=	arduino_penguino
#BOARD			=	arduino_cerebot_plus
#BOARD			=	arduino_android2561
#BOARD			=	arduino_android2561_16
#BOARD			=	atmega8
#BOARD			=	atmega88
#BOARD			=	arduino_atmega16
#BOARD			=	atmega328
#BOARD			=	arduino_attiny45
#BOARD			=	arduino_attiny2313
#BOARD			=	dragonrider328
#BOARD			=	arduino_atmega8535
#BOARD			=	dragonrider8535
#BOARD			=	arduino_1284p
#BOARD			=	arduino_atmega8515
#BOARD			=	arduino_at90usbkey

PORT			?=	/dev/tty.usbserial-A900cbro
#PORT			=	/dev/tty.usbserial-A800eGS5
#PORT			=	/dev/tty.usbserial-FTF4BHEE
#PORT			=	/dev/tty.usbserial-RCTBW0HY


#	mega1280 stk500 v2
ifeq ($(BOARD),mega1280stk500v2)
PORT			=	/dev/tty.usbserial-A600bySf
endif


#atmega8
ifeq ($(BOARD),atmega8)
PORT			=	/dev/tty.usbserial-A700dARA
endif

#1281
ifeq ($(BOARD),arduino_wiring1281)
PORT			=	/dev/tty.usbserial-A700e5Bx
endif

#	Illuminato
ifeq ($(BOARD),arduino_illuminato)
PORT			=	/dev/tty.usbserial-A80098Dl
endif

#	mega2560
ifeq ($(BOARD),mega2560stk500v2)
PORT			=	/dev/tty.usbmodem1a21
endif

#	arduino_amber128
ifeq ($(BOARD),arduino_amber128)
PORT			=	/dev/tty.usbserial-FTF4BHEE
endif

#	arduino_penguino
ifeq ($(BOARD),arduino_penguino)
PORT			=	/dev/cu.penguino-uart 115200
endif

#	arduino_penguino
ifeq ($(BOARD),arduino_cerebot_plus)
PORT			=	/dev/tty.usbserial-FTF4BHEE 
endif

#	arduino_android2561
ifeq ($(BOARD),arduino_android2561)
PORT			=	/dev/tty.usbserial-A800cAoo
endif

#	arduino_android2561_16
ifeq ($(BOARD),arduino_android2561_16)
PORT			=	/dev/tty.usbserial-A800cAoo
endif


# atmega328
ifeq ($(BOARD),atmega328)
PORT			=	/dev/tty.usbserial-A700dB60
endif


# dragonrider328
ifeq ($(BOARD),dragonrider328)
PORT			=	usb
endif

# dragonrider8535
ifeq ($(BOARD),dragonrider8535)
PORT			=	usb
endif


#arduino_butterfly
ifeq ($(BOARD),arduino_butterfly)
PORT			=	/dev/tty.usbserial-FTF4BHEE
endif

#arduino_atmega16
ifeq ($(BOARD),arduino_atmega16)
PORT			=	/dev/tty.usbserial-FTF4BHEE
endif




#LIB_DIRS		=	../libraries/WiseClock2
LIB_DIRS		=	../libraries/UnivGraphicsLib /Applications/Arduino.app/Contents/Resources/Java/libraries/EEPROM /Applications/Arduino.app/Contents/Resources/Java/libraries/Wire /Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility
LIB_DIRS		+=	/Applications/Arduino.app/Contents/Resources/Java/libraries/LiquidCrystal
LIB_DIRS		+=	../libraries/Digilent_lib
ARD_HOME		=	/Applications/Arduino.app/Contents/Resources/Java
#ARD_BIN		=	/usr/local/test/avr1/bin
#AVRDUDE_HOME	=	/usr/local/CrossPack-AVR
AVRDUDE_HOME	=	/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr
#ARD_BIN		=	/usr/local/test/avr1/bin


include ../Makefile.master

