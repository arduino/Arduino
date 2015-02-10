DEPTH := $(DEPTH).x

MAKEFILE_STACK_$(DEPTH)        := $(MAKEFILE)
MAKEFILE_FOLDER_STACK_$(DEPTH) := $(MAKEFILE_FOLDER)

MAKEFILE        := $(lastword $(MAKEFILE_LIST))
MAKEFILE        := $(abspath $(MAKEFILE))
MAKEFILE_FOLDER := $(dir $(MAKEFILE))

ifndef ARDUINO_BOOTLOADER_FOLDER
ARDUINO_BOOTLOADER_FOLDER:=$(MAKEFILE_FOLDER)/../../../arduino/bootloaders
endif

ifndef SOURCE
SOURCE:=$(ARDUINO_BOOTLOADER_FOLDER)/atmega/src
SOURCE:=$(abspath $(SOURCE))
endif

BUILD_FOLDER := $(abspath build)
HEX_FOLDER   := $(abspath .)

include $(SOURCE)/Definitions.mk


.PHONY: all
all: sfe_xmega100

######################

TARGET       := sfe_xmega100
MCU_TARGET   := atxmega128a1
CFLAGS_LOCAL := 
CFLAGS_LOCAL += -I $(MAKEFILE_FOLDER).
CFLAGS_LOCAL += -I $(SOURCE)/board
CFLAGS_LOCAL += -DNUM_LED_FLASHES=3
CFLAGS_LOCAL += -DBAUD_RATE=57600
AVR_FREQ     := 32000000L
BOOT_ADDR    := 0x20000

include $(SOURCE)/TargetRules.mk

$(TARGET): $(BIN)

$(ISP): FUSE0 = 
$(ISP): FUSE1 = 
$(ISP): FUSE2 = 
$(ISP): FUSE4 = 
$(ISP): FUSE5 = 

######################

include $(SOURCE)/Rules.mk
