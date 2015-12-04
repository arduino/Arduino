#
#             LUFA Library
#     Copyright (C) Dean Camera, 2015.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

MCU          = atmega8u2
ARCH         = AVR8
BOARD        = USER
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = Arduino-usbserial
SRC          = $(TARGET).c Descriptors.c $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS)
LUFA_PATH    = ../../LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/
LD_FLAGS     =

# Specify the Arduino model using the assigned PID.  This is used by Descriptors.c
#   to set PID and product descriptor string
# Arduino UNO:
#ARDUINO_MODEL_PID = 0x0001
# Arduino Mega 2560:
#ARDUINO_MODEL_PID = 0x0010
# Arduino USB-Serial:
#ARDUINO_MODEL_PID = 0x003B
# Arduino Mega ADK:
#ARDUINO_MODEL_PID = 0x003F
# Arduino Mega 2560 R3:
#ARDUINO_MODEL_PID = 0x0042
# Arduino UNO R3:
ARDUINO_MODEL_PID = 0x0043
# Arduino Mega ADK R3:
#ARDUINO_MODEL_PID = 0x0044

CC_FLAGS += -DARDUINO_MODEL_PID=$(ARDUINO_MODEL_PID)
CC_FLAGS += -DAVR_RESET_LINE_PORT="PORTD"
CC_FLAGS += -DAVR_RESET_LINE_DDR="DDRD"
CC_FLAGS += -DAVR_RESET_LINE_MASK="(1 << 7)"
CC_FLAGS += -DTX_RX_LED_PULSE_MS=3

# Default target
all:

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk
