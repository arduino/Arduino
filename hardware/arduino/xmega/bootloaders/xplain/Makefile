DEPTH := $(DEPTH).x

MAKEFILE_STACK_$(DEPTH)        := $(MAKEFILE)
MAKEFILE_FOLDER_STACK_$(DEPTH) := $(MAKEFILE_FOLDER)

MAKEFILE        := $(lastword $(MAKEFILE_LIST))
MAKEFILE        := $(abspath $(MAKEFILE))
MAKEFILE_FOLDER := $(dir $(MAKEFILE))

TOP := $(abspath $(MAKEFILE_FOLDER)/../../..)

ifndef SOURCE
SOURCE := $(TOP)/arduino/bootloaders/atmega/src
endif

BUILD_FOLDER := $(abspath build)
HEX_FOLDER   := $(abspath .)

include $(SOURCE)/Definitions.mk

.PHONY: all
all: xplain

######################

TARGET     := xplain
MCU_TARGET := atxmega128a1
CFLAGS_LOCAL := -I$(MAKEFILE_FOLDER)
CFLAGS_LOCAL += -DNUM_LED_FLASHES=3
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
